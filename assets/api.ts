enum PShape { CROSS, STRA, TEE, ELBOW };

interface Pipe {
  shape: PShape;
  rotation: number;
}

interface Board {
  rowCount: number;
  colCount: number;
  elements: Pipe[];
}

function webStartGame() {

}

function webUpdate() {

}

function coreBoardStatus(board: number[]) {

}

function coreClick(row: number, col: number) {

}

function coreGameStatus(): string {
  return "status"
}