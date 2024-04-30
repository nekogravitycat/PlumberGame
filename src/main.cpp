#include <AppCore/CAPI.h>
#include <JavaScriptCore/JavaScript.h>
#include "Game.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")

using namespace std;

// Various globals
Game game(10, 10);
ULApp app = 0;
ULWindow window = 0;
ULOverlay overlay = 0;
ULView view = 0;

// Forward declaration of our OnUpdate callback.
void OnUpdate(void* user_data);
// Forward declaration of our OnClose callback.
void OnClose(void* user_data, ULWindow window);
// Forward declaration of our OnResize callback.
void OnResize(void* user_data, ULWindow window, unsigned int width, unsigned int height);
// Forward declaration of our OnDOMReady callback.
void OnDOMReady(void* user_data, ULView caller, unsigned long long frame_id, bool is_main_frame, ULString url);

void Init() {
  ULSettings settings = ulCreateSettings();
  ulSettingsSetForceCPURenderer(settings, true);
  ULConfig config = ulCreateConfig();
  app = ulCreateApp(settings, config);
  // Register a callback to handle app update logic.
  ulAppSetUpdateCallback(app, OnUpdate, 0);
  // Done using settings/config, make sure to destroy anything we create
  ulDestroySettings(settings);
  ulDestroyConfig(config);
  // Create our window, make it 500x500 with a titlebar and resize handles.
  window = ulCreateWindow(ulAppGetMainMonitor(app), 1600, 900, false, kWindowFlags_Titled | kWindowFlags_Resizable | kWindowFlags_Maximizable);
  // Set our window title.
  ulWindowSetTitle(window, "Plumber Game");
  // Register a callback to handle window close.
  ulWindowSetCloseCallback(window, OnClose, 0);
  // Register a callback to handle window resize.
  ulWindowSetResizeCallback(window, OnResize, 0);
  overlay = ulCreateOverlay(window, ulWindowGetWidth(window), ulWindowGetHeight(window), 0, 0);
  view = ulOverlayGetView(overlay);
  ulViewSetDOMReadyCallback(view, OnDOMReady, 0);
  ULString url = ulCreateString("file:///app.html");
  ulViewLoadURL(view, url);
  ulDestroyString(url);
}

// This is called continuously from the app's main run loop. You should update any app logic inside this callback.
void OnUpdate(void* user_data) {
  // Place holder
}

// This is called when the window is closed.
void OnClose(void* user_data, ULWindow window) {
  ulAppQuit(app);
}

// This is called whenever the window resizes. Width and height are in DPI-independent logical coordinates (not pixels).
void OnResize(void* user_data, ULWindow window, unsigned int width, unsigned int height) {
  ulOverlayResize(overlay, width, height);
}

JSValueRef ApiStartGame(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  int row = JSValueToNumber(ctx, arguments[0], exception);
  int column = JSValueToNumber(ctx, arguments[1], exception);
  game = Game(row, column);
  game.startGameCore(row, column);
  return JSValueMakeNull(ctx);
}

JSValueRef ApiClick(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  int row = JSValueToNumber(ctx, arguments[0], exception);
  int column = JSValueToNumber(ctx, arguments[1], exception);
  game.Click(row, column);
  return JSValueMakeNull(ctx);
}

JSValueRef ApiGetRows(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  string info = to_string(game.GetRows());
  JSStringRef str = JSStringCreateWithUTF8CString(info.c_str());
  JSValueRef value = JSValueMakeString(ctx, str);
  JSStringRelease(str);
  return value;
}

JSValueRef ApiGetColumns(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  string info = to_string(game.GetColumns());
  JSStringRef str = JSStringCreateWithUTF8CString(info.c_str());
  JSValueRef value = JSValueMakeString(ctx, str);
  JSStringRelease(str);
  return value;
}

JSValueRef ApiIsStart(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  int row = JSValueToNumber(ctx, arguments[0], exception);
  int column = JSValueToNumber(ctx, arguments[1], exception);
  string info = game.IsStart(row, column) ? "1" : "0";
  JSStringRef str = JSStringCreateWithUTF8CString(info.c_str());
  JSValueRef value = JSValueMakeString(ctx, str);
  JSStringRelease(str);
  return value;
}

JSValueRef ApiIsEnd(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  int row = JSValueToNumber(ctx, arguments[0], exception);
  int column = JSValueToNumber(ctx, arguments[1], exception);
  string info = game.IsEnd(row, column) ? "1" : "0";
  JSStringRef str = JSStringCreateWithUTF8CString(info.c_str());
  JSValueRef value = JSValueMakeString(ctx, str);
  JSStringRelease(str);
  return value;
}
 
JSValueRef ApiGetPipeInfo(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  int row = JSValueToNumber(ctx, arguments[0], exception);
  int column = JSValueToNumber(ctx, arguments[1], exception);
  string info = to_string(game.GetPipeInfo(row, column));
  while (info.length() < 3) {
    info = "0" + info;
  }
  JSStringRef str = JSStringCreateWithUTF8CString(info.c_str());
  JSValueRef value = JSValueMakeString(ctx, str);
  JSStringRelease(str);
  return value;
}

JSValueRef ApiIsOver(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  string info = game.isItGameOver() ? "1" : "0";
  JSStringRef str = JSStringCreateWithUTF8CString(info.c_str());
  JSValueRef value = JSValueMakeString(ctx, str);
  JSStringRelease(str);
  if (game.isItGameOver()) {
    PlaySound(0, 0, 0);
  }
  return value;
}

JSValueRef ApiPlayBGM(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  PlaySound(TEXT("./assets/sound/bgm.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
  return JSValueMakeNull(ctx);
}

JSValueRef ApiStopBGM(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  PlaySound(0, 0, 0);
  return JSValueMakeNull(ctx);
}

JSValueRef ApiReadFile(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
  game = Game();
  game.fileStartGameCore();
  return JSValueMakeNull(ctx);
}


// This is called when the page has finished parsing the document and is ready to execute scripts.
// We will use this event to set up our JavaScript <-> C callback.
void OnDOMReady(void* user_data, ULView caller, unsigned long long frame_id,
  bool is_main_frame, ULString url) {
  // Acquire the page's JavaScript execution context.
  JSContextRef ctx = ulViewLockJSContext(view);
  // Click
  JSStringRef name = JSStringCreateWithUTF8CString("ApiClick");
  JSObjectRef func = JSObjectMakeFunctionWithCallback(ctx, name, ApiClick);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // StartGame
  name = JSStringCreateWithUTF8CString("ApiStartGame");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiStartGame);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // GetRows
  name = JSStringCreateWithUTF8CString("ApiGetRows");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiGetRows);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // GetColumns
  name = JSStringCreateWithUTF8CString("ApiGetColumns");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiGetColumns);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // IsStart
  name = JSStringCreateWithUTF8CString("ApiIsStart");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiIsStart);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // IsEnd
  name = JSStringCreateWithUTF8CString("ApiIsEnd");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiIsEnd);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // IsOver
  name = JSStringCreateWithUTF8CString("ApiIsOver");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiIsOver);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // GetPipeInfo
  name = JSStringCreateWithUTF8CString("ApiGetPipeInfo");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiGetPipeInfo);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // PlayBGM
  name = JSStringCreateWithUTF8CString("ApiPlayBGM");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiPlayBGM);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // StopBGM
  name = JSStringCreateWithUTF8CString("ApiStopBGM");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiStopBGM);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // ReadFile
  name = JSStringCreateWithUTF8CString("ApiReadFile");
  func = JSObjectMakeFunctionWithCallback(ctx, name, ApiReadFile);
  JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), name, func, 0, 0);
  JSStringRelease(name);
  // Unlock the JS context so other threads can modify JavaScript state.
  ulViewUnlockJSContext(view);
}

void Shutdown() {
  ulDestroyOverlay(overlay);
  ulDestroyWindow(window);
  ulDestroyApp(app);
}

int main() {
  Init();
  ulAppRun(app);
  Shutdown();
  return 0;
}

/*
#include"Game.h"

using namespace std;

int main(void) {
    Game mainGame(7, 6);
    //mainGame.startGame();
    mainGame.startGameCore(7, 6);
    int r, c;
    while (cin >> r >> c) {
        mainGame.Click(r, c);
        if (mainGame.isItGameOver()) {
            return 0;
        }
    }
}
*/
