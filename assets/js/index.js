"use strict";
let boardCol = 1;
let boardRow = 1;
let water = false;
const pipeType = ["cross", "straight", "Tpose", "Lpose"];
const gBoard = document.getElementById('board');
const homePage = document.getElementById('home-page');
const gamePage = document.getElementById('game-page');
const buttonPart = document.getElementById('setup-space');
const inputPart = document.getElementById('custom-size');
const countDisplay = document.getElementById('count');
const buttonHome = document.getElementById('iconHome');
const buttonMute = document.getElementById('iconMute');
const buttonRandom = document.getElementById('Random-button');
const buttonCustom = document.getElementById('Custom-button');
const startButton = document.getElementById('enter-button');
buttonRandom === null || buttonRandom === void 0 ? void 0 : buttonRandom.addEventListener('click', startRandom);
buttonCustom === null || buttonCustom === void 0 ? void 0 : buttonCustom.addEventListener('click', startCustom);
startButton === null || startButton === void 0 ? void 0 : startButton.addEventListener('click', function () {
    if (boardCol > 3 && boardRow > 3)
        GameStart(boardRow, boardCol);
    generateBoard();
});
buttonHome === null || buttonHome === void 0 ? void 0 : buttonHome.addEventListener('click', function () {
    if (gBoard)
        gBoard.innerHTML = '';
    if (homePage && gamePage && inputPart && buttonPart) {
        if (countDisplay)
            countDisplay.textContent = `click: 0`;
        buttonPart.style.display = 'flex';
        inputPart.style.display = 'none';
        homePage.style.display = 'flex';
        gamePage.style.display = 'none';
    }
});
//the random mode on the game
function startRandom() {
    boardCol = getRandom(12, 3);
    boardRow = getRandom(12, 3);
    generateBoard();
}
//the custom mode on the game
function startCustom() {
    const inputRow = document.getElementById('Row-input');
    const inputCol = document.getElementById('Column-input');
    if (homePage && gamePage && inputPart && buttonPart) {
        buttonPart.style.display = 'none';
        inputPart.style.display = 'flex';
        inputRow === null || inputRow === void 0 ? void 0 : inputRow.addEventListener('input', function () {
            boardRow = parseInt(inputRow.value);
        });
        inputCol === null || inputCol === void 0 ? void 0 : inputCol.addEventListener('input', function () {
            boardCol = parseInt(inputCol.value);
        });
    }
    if (boardCol > 3 && boardRow > 3)
        GameStart(boardRow, boardCol);
}
//set random
function getRandom(max, min) {
    return Math.floor(Math.random() * (max - min) + min);
}
//click and play audio
function clickSound() {
    const audio = document.createElement('audio');
    audio.src = './audio/rotate_sound.mp3';
    audio.play();
}
//click rotate image
function clickPipe(img, angle) {
    clickSound();
    const currentRotation = angle * 90;
    img.style.transform = `rotate(${currentRotation}deg)`;
}
//setup broad
function generateBoard() {
    let countClick = 0;
    if (homePage && gamePage) {
        homePage.style.display = 'none';
        gamePage.style.display = 'flex';
    }
    if (gBoard) {
        gBoard.style.display = 'grid';
        let imgSize = 50;
        if (boardCol > 15 || boardRow > 15)
            imgSize = 25;
        gBoard.style.gridTemplateColumns = `repeat(${boardCol}, ${imgSize}px)`;
        gBoard.style.gridTemplateRows = `repeat(${boardRow}, ${imgSize}px)`;
        for (let i = 0; i < boardCol; i++) {
            for (let j = 0; j < boardRow; j++) {
                const img = document.createElement('img');
                img.id = `${i}_${j}`;
                let info = "100";
                if (info[2])
                    img.src = `./image/water_${pipeType[parseInt(info[0])]}.png`;
                else
                    img.src = `./image/${pipeType[parseInt(info[0])]}.png`;
                img.onclick = () => {
                    countClick++;
                    if (countDisplay)
                        countDisplay.textContent = `click: ${countClick}`;
                    clickPipe(img, parseInt(info[1]));
                };
                gBoard.appendChild(img);
            }
        }
    }
}
function GameStart(row, column) {
    ApiStartGame(row, column);
}
function GetPipeInfo(row, column) {
    // It will consists of 3 char: Shape, rotation, water
    // Shape:    0, 1, 2, 3
    // Rotation: 0, 1, 2, 3
    // Water:    0, 1
    return ApiGetPipeInfo(row, column);
}
function Click(row, column) {
    ApiClick(row, column);
}
function GameOver() {
    return ApiGameOver();
}
