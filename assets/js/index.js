"use strict";
let boardCol = 1;
let boardRow = 1;
let water = false;
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
startButton === null || startButton === void 0 ? void 0 : startButton.addEventListener('click', generateBoard);
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
function clickPipe(img) {
    clickSound();
    const currentRotation = parseFloat(img.style.transform.replace('rotate(', '').replace('deg)', '')) || 0;
    img.style.transform = `rotate(${currentRotation + 90}deg)`;
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
                if (getRandom(0, 1))
                    img.src = './image/cross.png';
                else
                    img.src = './image/straight.png';
                img.onclick = () => {
                    countClick++;
                    if (countDisplay)
                        countDisplay.textContent = `click: ${countClick}`;
                    clickPipe(img);
                };
                gBoard.appendChild(img);
            }
        }
    }
}
