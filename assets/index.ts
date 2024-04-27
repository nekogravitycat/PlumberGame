let boardCol: number = 1;
let boardRow: number = 1;
const homePage = document.getElementById('home-page');
const gamePage = document.getElementById('game-page');
const buttonRandom = document.getElementById('Random-button');
const customRandom = document.getElementById('Custom-button');
const gBoard = document.getElementById('board');

//the random mode on the game
function startRandom() {
    if (homePage && gamePage)
    {
        homePage.style.display = 'none';
        gamePage.style.display = 'flex';
        boardCol = getRandom(12, 3);
        boardRow = getRandom(12, 3);
        generateBoard();
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

buttonRandom?.addEventListener('click', startRandom);

//setup broad
function generateBoard() {
    if (gBoard) {
        gBoard.style.display = 'grid';
        gBoard.style.gridTemplateColumns = `repeat(${boardCol}, 50px)`;
        gBoard.style.gridTemplateRows = `repeat(${boardRow}, 50px)`;
    
        for (let i = 0; i < boardCol; i++) {
            for (let j = 0; j < boardRow; j++) {
                const img = document.createElement('img');
    
                if (getRandom(0, 1)) img.src = './image/cross.png';
                else img.src = './image/straight.png';
    
                img.addEventListener('click', function() {
                    clickSound();
                    const currentRotation = parseFloat(img.style.transform.replace('rotate(', '').replace('deg)', '')) || 0;
                    img.style.transform = `rotate(${currentRotation + 90}deg)`;
                });
                gBoard.appendChild(img);
            }
        }
    }
}

