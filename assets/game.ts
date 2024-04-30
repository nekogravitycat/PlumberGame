function RandomNumber(min: number, max: number) {
  return Math.floor(Math.random() * (max - min) + min);
}

function RandomStart() {
  const rows = RandomNumber(5, 15);
  const columns = RandomNumber(5, 15);
  StartGame(rows, columns);
}

function CustomMenu() {
  const setupSpace = document.getElementById("setup-space");
  const customSize = document.getElementById("custom-size");
  if (!setupSpace || !customSize) {
    return;
  }
  setupSpace.style.display = "none";
  customSize.style.display = "flex";
}

function CustomStart() {
  const rowInput = document.getElementById("Row-input") as HTMLInputElement;
  const columnInput = document.getElementById("Column-input") as HTMLInputElement;
  if (!rowInput || !columnInput) {
    return;
  }
  if (!rowInput.value || !columnInput.value) {
    return;
  }
  const rows: number = parseInt(rowInput.value);
  const columns: number = parseInt(columnInput.value);
  if (rows < 5 || rows > 30 || columns < 5 || columns > 30) {
    return;
  }
  StartGame(rows, columns);
}

function DisplayBoard() {
  const rows: number = GetRows();
  const columns: number = GetColumns();
  const board = document.getElementById('board');
  if (!board) {
    return;
  }
  const imageSize: number = (rows < 15 && columns < 15) ? 50 : 25;
  board.style.gridTemplateRows = `repeat(${rows}, ${imageSize}px)`;
  board.style.gridTemplateColumns = `repeat(${columns}, ${imageSize}px)`;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < columns; c++) {
      let image = document.createElement("img");
      image.id = `${r}_${c}`;
      const info: string = GetPipeInfo(r, c);
      const shape: string = info[0];
      const rotation: number = parseInt(info[1]);
      const water: boolean = parseInt(info[2]) == 1;
      const startOrEnd: boolean = IsStart(r, c) || IsEnd(r, c);
      let suffix: string = "";
      if (startOrEnd) {
        suffix = "s";
      }
      else if (water) {
        suffix = "w";
      }
      image.src = `./image/${shape}${suffix}.png`
      image.style.transform = `rotate(${rotation*90}deg)`;
      image.onclick = () => {
        Click(r, c);
      }
      board.appendChild(image);
    }
  }
}

function Mute() {
  const audioElement = document.getElementById('background_music') as HTMLMediaElement;
  audioElement.muted = (audioElement.muted)? false : true;
}

function ClearBoard() {
  const board = document.getElementById('board');
  if (!board) {
    return;
  }
  board.innerHTML = "";
}

function StartGame(rows: number, columns: number) {
  const homePage = document.getElementById("home-page");
  const gamePage = document.getElementById("game-page");
  if (!homePage || !gamePage) {
    return;
  }
  homePage.style.display = "none";
  gamePage.style.display = "flex";
  ApiStartGame(rows, columns);
  DisplayBoard();
}

let clickCount: number = 0;

function Click(row: number, column: number) {
  ClearBoard();
  // Count display
  clickCount++;
  const countDisplay = document.getElementById('count');
  if (countDisplay) {
    countDisplay.textContent = `click: ${clickCount}`;
  }
  // API
  ApiClick(row, column);
  DisplayBoard();
}

function GoHome() {
  
}

function GetRows(): number {
  return parseInt(ApiGetRows());
}

function GetColumns(): number {
  return parseInt(ApiGetColumns());
}

function GetPipeInfo(row: number, column: number): string {
  return ApiGetPipeInfo(row, column);
}

function IsStart(row: number, column: number): boolean {
  return ApiIsStart(row, column) == "1";
}

function IsEnd(row: number, column: number): boolean {
  return ApiIsEnd(row, column) == "1";
}