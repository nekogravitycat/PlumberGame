let boardCol: number = 1;
let boardRow: number = 1;
let water: boolean = false; 
const homePage = document.getElementById('home-page');
const gamePage = document.getElementById('game-page');
const buttonRandom = document.getElementById('Random-button');
const buttonCustom = document.getElementById('Custom-button');
const startButton = document.getElementById('enter-button');
const gBoard = document.getElementById('board');

buttonRandom?.addEventListener('click', startRandom);

buttonCustom?.addEventListener('click', startCustom);

startButton?.addEventListener('click', generateBoard);

//the random mode on the game
function startRandom() {  
    boardCol = getRandom(12, 3);
    boardRow = getRandom(12, 3);
    generateBoard();
    
}

//the custom mode on the game
function startCustom() {
    const buttonPart = document.getElementById('setup-space');
    const inputPart = document.getElementById('custom-size');
    const inputRow = document.getElementById('Row-input') as HTMLInputElement;
    const inputCol = document.getElementById('Column-input') as HTMLInputElement;
    if (homePage && gamePage && inputPart && buttonPart)
    {
        buttonPart.style.display = 'none';
        inputPart.style.display = 'flex';
        inputRow?.addEventListener('input', function () {
            boardRow = parseInt(inputRow.value);
        })
        inputCol?.addEventListener('input', function () {
            boardCol = parseInt(inputCol.value);
        })
    }
    
}

//set random
function getRandom(max: number, min:number) {
    return Math.floor(Math.random() * (max - min) + min);
}

//click and play audio
function clickSound() {
    const audio = document.createElement('audio');
    audio.src = './audio/rotate_sound.mp3';
    audio.play();
}

function clickPipe(img: HTMLImageElement) {
    clickSound();
    const currentRotation = parseFloat(img.style.transform.replace('rotate(', '').replace('deg)', '')) || 0;
    img.style.transform = `rotate(${currentRotation + 90}deg)`;
}

//setup broad
function generateBoard() {
    let count:number = 0;
    if (homePage && gamePage)
        {
            homePage.style.display = 'none';
            gamePage.style.display = 'flex';
        }
    if (gBoard) {
        gBoard.style.display = 'grid';
        let imgSize = 50;
        if (boardCol > 15 || boardRow > 15) imgSize = 25;
        gBoard.style.gridTemplateColumns = `repeat(${boardCol}, ${imgSize}px)`;
        gBoard.style.gridTemplateRows = `repeat(${boardRow}, ${imgSize}px)`;
    
        for (let i = 0; i < boardCol; i++) {
            for (let j = 0; j < boardRow; j++) {
                const img = document.createElement('img');
    
                if (getRandom(0, 1)) img.src = './image/cross.png';
                else img.src = './image/straight.png';
                img.onclick = () => {
                    
                    clickPipe(img);
                }
                gBoard.appendChild(img);
            }
        }
    }
}

