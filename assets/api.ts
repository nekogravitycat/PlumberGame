function GameStart(row: number, column: number) {
  ApiStartGame(row, column)
}

function GetPipeInfo(): string {
  // It will consists of 3 char: Shape, rotation, water
  // Shape:    0, 1, 2, 3
  // Rotation: 0, 1, 2, 3
  // Water:    0, 1
  return ApiGetPipeInfo();
}

function Click(row: number, column: number) {
  ApiClick(row, column);
}
