let boardCol: number = 1;
let boardRow: number = 1;
let water: boolean = false; 
const pipeType: string[] = ["cross", "straight", "Tpose", "Lpose"]; 
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

buttonRandom?.addEventListener('click', startRandom);
buttonCustom?.addEventListener('click', startCustom);
startButton?.addEventListener('click', function () {
    if (boardCol > 3 && boardRow > 3) GameStart(boardRow, boardCol);
    generateBoard();
});
buttonHome?.addEventListener('click', function () {
    if (gBoard) gBoard.innerHTML = '';
    if (homePage && gamePage && inputPart && buttonPart)
    {
        if (countDisplay) countDisplay.textContent = `click: 0`
        buttonPart.style.display = 'flex';
        inputPart.style.display = 'none';
        homePage.style.display = 'flex';
        gamePage.style.display = 'none';
    }
})

//the random mode on the game
function startRandom() {  
    boardCol = getRandom(12, 3);
    boardRow = getRandom(12, 3);
    if (boardCol > 3 && boardRow > 3) GameStart(boardRow, boardCol);
    generateBoard();
}

//the custom mode on the game
function startCustom() {
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

//click rotate image
function clickPipe(img: HTMLImageElement, angle: number) {
    clickSound();
    img.style.transform = `rotate(${angle * 90}deg)`;
}

//setup broad
function generateBoard() {
    let countClick:number = 0;
    if (homePage && gamePage)
    {
        homePage.style.display = 'none';
        gamePage.style.display = 'flex';
    }
    if (gBoard) 
    {
        gBoard.style.display = 'grid';
        let imgSize = 50;

        if (boardCol > 15 || boardRow > 15) imgSize = 25;

        gBoard.style.gridTemplateRows = `repeat(${boardRow}, ${imgSize}px)`;
        gBoard.style.gridTemplateColumns = `repeat(${boardCol}, ${imgSize}px)`;
    
        for (let i = 0; i < boardCol; i++) {
            for (let j = 0; j < boardRow; j++) {
                const img = document.createElement('img');
                img.id = `${i}_${j}`;
                let info: string  = GetPipeInfo(j, i);
                if (parseInt(info[2])) img.src = `./image/water_${pipeType[parseInt(info[0])]}.png`;
                else img.src = `./image/${pipeType[parseInt(info[0])]}.png`;
                img.style.transform = `rotate(${parseInt(info[1]) * 90}deg)`;
                img.onclick = () => {
                    countClick++;
                    if (countDisplay) countDisplay.textContent = `click: ${countClick}`;
                    clickPipe(img, parseInt(info[1]));
                    Click(j, i);
                }
                gBoard.appendChild(img);
            }
        }
    }
}

function GameStart(row: number, column: number) {
    ApiStartGame(row, column)
}

function GetPipeInfo(row: number, column: number): string {
    // It will consists of 3 char: Shape, rotation, water
    // Shape:    0, 1, 2, 3
    // Rotation: 0, 1, 2, 3
    // Water:    0, 1
    return ApiGetPipeInfo(row, column);
}

function Click(row: number, column: number) {
    ApiClick(row, column);
}

function GameOver(): bool {
    return ApiGameOver();
}

