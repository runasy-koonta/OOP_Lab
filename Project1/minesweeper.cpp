#include "minesweeper.h"

void minesweeper( string input, string output ) {
	ifstream fin(input);
	ofstream fout(output);
	
	char c, board[SIZE][SIZE];
	bool touchedBoard[SIZE][SIZE], gameOver = false;
	string command, target;
	int status = 0, touchCount = 0;
	while (fin.get(c)) {
		if (c == '\r') {
			continue;
		} else if (c == ' ') {
			if (status == 0) {
				status = 1;
			} else {
				target.append(1, c);
			}
		} else if (c == '\n') {
			fout << "Command: " << command << " " << target << endl;
			
			if (command == "load") {
				initBoard(board, target);
				initTouched(touchedBoard);
			} else if (command == "display") {
				displayBoard(fout, board, touchedBoard, gameOver);
			} else if (command == "touch") {
				touchBoard(touchedBoard, target[0] - '0', target[2] - '0');
				touchCount++;
				
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						if (board[i][j] == '*' && touchedBoard[i][j] == true) {
							gameOver = true;
							break;
						}
					}
					if (gameOver) break;
				}
				if (gameOver) {
					displayBoard(fout, board, touchedBoard, true);
					break;
				}
			}
			
			command = "";
			target = "";
			status = 0;
		} else {
			if (status == 0) {
				command.append(1, c);
			} else {
				target.append(1, c);
			}
		}
	}
	if (!gameOver) {
		displayBoard(fout, board, touchedBoard, true);
	}
}

void initBoard( char board[][SIZE], string file ) {
	ifstream boardFile(file);
	char c;
	
	int col = 0, row = 0;
	while (boardFile.get(c)) {
		if (c == '\r') {
			continue;			   
		} else if (c == '\n') {
			col = 0;
			row++;
		} else {
			board[row][col++] = c;
		}
	}
}

void displayBoard( ostream& out, char board[][SIZE], bool touchedBoard[][SIZE], bool gameOver ) {
	if (gameOver) {
		out << "Game Over" << endl << "~~~~~~~~~" << endl << "Final Board" << endl;
	}
	int touchedCount = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (touchedBoard[i][j] == false) {
				if (gameOver) {
					if (board[i][j] == '.') {
						out << '.';
					} else if (board[i][j] == '*') {
						out << '@';
					}
				} else {
					out << '.';
				}
			} else {
				touchedCount++;
				if (gameOver) {
					if (board[i][j] == '.') {
						int bombs = 0;

						int x = i - 1, y = j - 1, c = 0;
						int moves[8][2] = { { 1, 0 }, { 1, 0 }, { 0, 1 }, { 0, 1 }, { -1, 0 }, { -1, 0 }, { 0, -1 }, { 0, -1 } };
						do {
							x += moves[c][0];
							y += moves[c][1];
							c++;
							if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) {
								continue;
							}
							if (board[x][y] == '*') {
								bombs++;
							}
						} while (x != i - 1 || y != j - 1);
						out << bombs;
					} else if (board[i][j] == '*') {
						out << '*';
					}
				} else {
					if (board[i][j] == '*') {
						out << '@'; 
					} else {
						out << '.';
					}
				}
			}
		}
		out << endl;
	}
	if (gameOver) {
		out << endl << "Spaces touched: " << touchedCount << endl;	
	} else {
		out << endl;
	}
}

void initTouched( bool touchedBoard[][SIZE] ) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			touchedBoard[i][j] = false;
		}
	}
}

void touchBoard( bool board[][SIZE], int x, int y ){
	board[x - 1][y - 1] = true;
}

int main(){
    minesweeper("test4commands.txt", "output.txt");
	
	return 0;
}