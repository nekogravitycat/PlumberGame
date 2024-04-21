const boardSize: number = 8;
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
            img.addEventListener('click', function() {
                // 當點擊圖片時，將其旋轉90度
                const currentRotation = parseFloat(img.style.transform.replace('rotate(', '').replace('deg)', '')) || 0;
                img.style.transform = `rotate(${currentRotation + 90}deg)`;
            });
            gBoard.appendChild(square);
        }
    }
}

