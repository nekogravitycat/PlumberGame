"use strict";
const boardSize = 8;
const gBoard = document.getElementById('board');
//setup broad
if (gBoard) {
    gBoard.style.display = 'grid';
    gBoard.style.gridTemplateColumns = `repeat(${boardSize}, 100px)`;
    gBoard.style.gridTemplateRows = `repeat(${boardSize}, 100px)`;
    for (let i = 0; i < boardSize; i++) {
        for (let j = 0; j < boardSize; j++) {
            const square = document.createElement('div');
            const img = document.createElement('img');
            img.src = `./image/straight.png`;
            square.appendChild(img);
            img.addEventListener('click', function () {
                const currentRotation = parseFloat(img.style.transform.replace('rotate(', '').replace('deg)', ''));
                img.style.transform = `rotate(${currentRotation + 90}deg)`;
            });
            gBoard.appendChild(square);
        }
    }
}
