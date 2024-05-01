"use strict";
/***********************************************************************
 * File: game.ts
 * Author: nakumi
 * Create Date: 2024/5/1
 * Editor: nakumi, Gravity cat
 * Update Date: 2024/5/1
 * Description: make the element work on the page
***********************************************************************/
//create a random number within the range
function RandomNumber(min, max) {
    return Math.floor(Math.random() * (max - min) + min);
}
//start game with randon board
function RandomStart() {
    const rows = RandomNumber(5, 15);
    const columns = RandomNumber(5, 15);
    StartGame(rows, columns);
}
//change to the page that you can input the row and column
function CustomMenu() {
    const setupSpace = document.getElementById("setup-space");
    const customSize = document.getElementById("custom-size");
    if (!setupSpace || !customSize) {
        return;
    }
    setupSpace.style.display = "none";
    customSize.style.display = "flex";
}
//start game with the board you set
function CustomStart() {
    const rowInput = document.getElementById("Row-input");
    const columnInput = document.getElementById("Column-input");
    if (!rowInput || !columnInput) {
        return;
    }
    if (!rowInput.value || !columnInput.value) {
        return;
    }
    const rows = parseInt(rowInput.value);
    const columns = parseInt(columnInput.value);
    //set a range of row and column
    if (rows < 5 || rows > 30 || columns < 5 || columns > 30) {
        return;
    }
    StartGame(rows, columns);
}
//print the board on the page
function DisplayBoard() {
    const rows = GetRows();
    const columns = GetColumns();
    const board = document.getElementById('board');
    if (!board) {
        return;
    }
    //Use grid to arrange each img
    const imageSize = (rows < 15 && columns < 15) ? 50 : 25;
    board.style.gridTemplateRows = `repeat(${rows}, ${imageSize}px)`;
    board.style.gridTemplateColumns = `repeat(${columns}, ${imageSize}px)`;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < columns; c++) {
            let image = document.createElement("img");
            image.id = `${r}_${c}`;
            const info = GetPipeInfo(r, c);
            const shape = info[0];
            const rotation = parseInt(info[1]);
            const water = parseInt(info[2]) == 1;
            const startOrEnd = IsStart(r, c) || IsEnd(r, c);
            let suffix = "";
            if (startOrEnd) {
                suffix = "s";
            }
            else if (water) {
                suffix = "w";
            }
            image.src = `./image/${shape}${suffix}.png`;
            image.style.transform = `rotate(${rotation * 90}deg)`;
            image.onclick = () => {
                Click(r, c);
            };
            board.appendChild(image);
        }
    }
}
//clean the board
function ClearBoard() {
    const board = document.getElementById('board');
    if (!board) {
        return;
    }
    board.innerHTML = "";
}
//start game
function StartGame(rows, columns) {
    const homePage = document.getElementById("home-page");
    const gamePage = document.getElementById("game-page");
    if (!homePage || !gamePage) {
        return;
    }
    homePage.style.display = "none";
    gamePage.style.display = "flex";
    ApiStartGame(rows, columns);
    DisplayBoard();
    ApiPlayBGM();
}
let clickCount = 0;
//Action on click
function Click(row, column) {
    ClearBoard();
    // Count display
    clickCount++;
    const countDisplay = document.getElementById('count');
    if (countDisplay) {
        countDisplay.textContent = `click: ${clickCount}`;
    }
    // API
    ApiClick(row, column);
    ApiPlayWater();
    DisplayBoard();
    // Check if game is over
    if (IsOver()) {
        GameOver();
    }
}
//back to homepage
function GoHome() {
    ClearBoard();
    clickCount = 0;
    const homePage = document.getElementById("home-page");
    const setupSpace = document.getElementById("setup-space");
    const customSize = document.getElementById("custom-size");
    const gamePage = document.getElementById("game-page");
    const winPage = document.getElementById("win-page");
    if (!homePage || !setupSpace || !customSize || !gamePage || !winPage) {
        return;
    }
    homePage.style.display = "flex";
    setupSpace.style.display = "flex";
    customSize.style.display = "none";
    gamePage.style.display = "none";
    winPage.style.display = "none";
    ApiStopBGM();
}
//close the bgm
function ShutUp() {
    ApiStopBGM();
}
//action on gameover
function GameOver() {
    const gamePage = document.getElementById("game-page");
    const winPage = document.getElementById("win-page");
    if (!winPage || !gamePage)
        return;
    gamePage.style.display = "none";
    winPage.style.display = "flex";
}
//start game with the board on the file
function FileStart() {
    ApiReadFile();
    const homePage = document.getElementById("home-page");
    const gamePage = document.getElementById("game-page");
    if (!homePage || !gamePage) {
        return;
    }
    homePage.style.display = "none";
    gamePage.style.display = "flex";
    DisplayBoard();
    ApiPlayBGM();
}
//get row
function GetRows() {
    return parseInt(ApiGetRows());
}
//get column
function GetColumns() {
    return parseInt(ApiGetColumns());
}
//get any information of each pipe
function GetPipeInfo(row, column) {
    return ApiGetPipeInfo(row, column);
}
//find the fisrt pipe
function IsStart(row, column) {
    return ApiIsStart(row, column) == "1";
}
//find the last pipe
function IsEnd(row, column) {
    return ApiIsEnd(row, column) == "1";
}
function IsOver() {
    return ApiIsOver() == "1";
}
