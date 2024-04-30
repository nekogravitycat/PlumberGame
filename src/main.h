/***********************************************************************
 * File: main.h
 * Author: Gravity cat
 * Create Date: 2024/5/1
 * Editor: Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for main
***********************************************************************/
#pragma once

#include <AppCore/CAPI.h>
#include <JavaScriptCore/JavaScript.h>
#include "Game.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>

// Intent: Initializes the application.
// Pre: None.
// Post: Application is initialized.
void Init();

// Intent: This is called continuously from the app's main run loop. Updates app logic inside this callback.
// Pre: The user_data parameter must point to valid data.
// Post: App logic is updated.
void OnUpdate(void* user_data);

// Intent: This is called when the window is closed.
// Pre: The user_data parameter must point to valid data. The window parameter must be a valid window object.
// Post: Window is closed.
void OnClose(void* user_data, ULWindow window);

// Intent: This is called whenever the window resizes. 
// Pre: The user_data parameter must point to valid data. The window parameter must be a valid window object.
// Post: Window is resized.
void OnResize(void* user_data, ULWindow window, unsigned int width, unsigned int height);

// Intent: Called when the DOM is ready for JavaScript execution.
// Pre: The user_data parameter must point to valid data. The caller parameter must be a valid view object.
// Post: DOM is ready.
void OnDOMReady(void* user_data, ULView caller, unsigned long long frame_id, bool is_main_frame, ULString url);

// Intent: Starts the game.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Game is started.
JSValueRef ApiStartGame(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Handles click events.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Click event is handled.
JSValueRef ApiClick(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Gets the number of rows.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Number of rows is returned.
JSValueRef ApiGetRows(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Gets the number of columns.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Number of columns is returned.
JSValueRef ApiGetColumns(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Checks if the game has started.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Returns whether the game has started.
JSValueRef ApiIsStart(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Checks if the game has ended.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Returns whether the game has ended.
JSValueRef ApiIsEnd(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Gets information about a pipe.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Pipe information is returned.
JSValueRef ApiGetPipeInfo(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Checks if the game is over.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Returns whether the game is over.
JSValueRef ApiIsOver(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Plays background music.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Background music is played.
JSValueRef ApiPlayBGM(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Stops background music.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: Background music is stopped.
JSValueRef ApiStopBGM(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Reads a file.
// Pre: The ctx parameter must be a valid JavaScript context. The function and thisObject parameters must be valid JavaScript objects.
// Post: File is read.
JSValueRef ApiReadFile(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

// Intent: Shuts down the application.
// Pre: None.
// Post: Application is shut down.
void Shutdown();

// Intent: Entry point of the program.
// Pre: None.
// Post: Program execution begins.
int main();