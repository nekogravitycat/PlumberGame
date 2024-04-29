"use strict";
let boardCol = 1;
let boardRow = 1;
let water = false;
const homePage = document.getElementById('home-page');
const gamePage = document.getElementById('game-page');
const buttonRandom = document.getElementById('Random-button');
const buttonCustom = document.getElementById('Custom-button');
const gBoard = document.getElementById('board');
buttonRandom === null || buttonRandom === void 0 ? void 0 : buttonRandom.addEventListener('click', startRandom);
buttonCustom === null || buttonCustom === void 0 ? void 0 : buttonCustom.addEventListener('click', startCustom);
//the random mode on the game
function startRandom() {
    if (homePage && gamePage) {
        homePage.style.display = 'none';
        gamePage.style.display = 'flex';
        boardCol = getRandom(12, 3);
        boardRow = getRandom(12, 3);
        generateBoard();
    }
}
//the custom mode on the game
function startCustom() {
    const buttonPart = document.getElementById('setup-space');
    const inputPart = document.getElementById('custom-size');
    if (homePage && gamePage && inputPart && buttonPart) {
        buttonPart.style.display = 'none';
        inputPart.style.display = 'flex';
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
function clickPipe(img) {
    clickSound();
    const currentRotation = parseFloat(img.style.transform.replace('rotate(', '').replace('deg)', '')) || 0;
    img.style.transform = `rotate(${currentRotation + 90}deg)`;
}
//setup broad
function generateBoard() {
    if (gBoard) {
        gBoard.style.display = 'grid';
        gBoard.style.gridTemplateColumns = `repeat(${boardCol}, 75px)`;
        gBoard.style.gridTemplateRows = `repeat(${boardRow}, 75px)`;
        for (let i = 0; i < boardCol; i++) {
            for (let j = 0; j < boardRow; j++) {
                const img = document.createElement('img');
                if (getRandom(0, 1))
                    img.src = './image/cross.png';
                else
                    img.src = './image/straight.png';
                img.onclick = () => {
                    clickPipe(img);
                };
                gBoard.appendChild(img);
            }
        }
    }
}
