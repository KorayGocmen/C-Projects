#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void printBoard(char board[21][21], int n) {
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
            if (j == n - 1)
            	printf("%c\n", board[i][j]);
            else
            	printf("%c", board[i][j]);
    	}
    }
}

int findLongest(char board[21][21], int n, int row, int col) {
    bool found = true;
    int longest1 = 0, longest2 = 0, longest3 = 0, longest4 = 0;
    int longest5 = 0, longest6 = 0, longest7 = 0, longest8 = 0;
    
    //left-up
    for (int i = 1; i <= row && i <= col && found; i++) {
    	if (board[row][col] == board[row - i][col - i]) {
            longest1++;
            found = true;
    	} else
            found = false;
    }
    found = true;
    //up
    for (int i = 1; i <= row && found; i++) {
    	if (board[row][col] == board[row - i][col]) {
            longest2++;
            found = true;
    	} else
            found = false;
    }
    found = true;
    //right-up
    for (int i = 1; i <= row && i <= n - col-1 && found; i++) {
    	if (board[row][col] == board[row - i][col + i]) {
            longest3++;
            found = true;
    	} else
            found = false;
    }
    found = true;
    //right
    for (int i = 1; i <= n - col-1 && found; i++) {
    	if (board[row][col] == board[row][col + i]) {
            longest4++;
            found = true;
    	} else
            found = false;
    }
    found = true;
    //right-down
    for (int i = 1; i <= n - row-1 && i <= n - col-1 && found; i++) {
    	if (board[row][col] == board[row + i][col + i]) {
            longest5++;
            found = true;
    	} else
            found = false;
    }
    found = true;
    //down
    for (int i = 1; i <= n - row-1 && found; i++) {
    	if (board[row][col] == board[row + i][col]) {
            longest6++;
            found = true;
    	} else
            found = false;
    }
    found = true;
    //left-down
    for (int i = 1; i <= n - row-1 && i <= col && found; i++) {
    	if (board[row][col] == board[row + i][col - i]) {
            longest7++;
            found = true;
    	} else
            found = false;
    }
    found = true;
    //left
    for (int i = 1; i <= col && found; i++) {
    	if (board[row][col] == board[row][col - i]) {
            longest8++;
            found = true;
    	} else
            found = false;
    }
    
    int leftUpToRightDown = longest1 + longest5 + 1;
    int upToDown = longest2 + longest6 + 1;
    int rightUpToLeftDown = longest3 + longest7 + 1;
    int rightToLeft = longest4 + longest8 + 1;
    
    int maxLongest = fmax(fmax(leftUpToRightDown, upToDown), fmax(rightUpToLeftDown, rightToLeft));
    
    return maxLongest;
}

int main(void) {
    
    int dimensions, row, col;
    
    printf("Enter board dimensions (n), n>=6 and n<=21: ");
    scanf("%d", &dimensions);
    int n = dimensions;
    
    char board[21][21];
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
            board[i][j] = 'U';
    	}
    }
    
    int positionCounter[21][21];
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
            positionCounter[i][j] = 0;
    	}
    }
    
    printBoard(board, n);
    
    do {
    	printf("Enter position (ROW COL) of blocked square; (-1 -1) to finish: ");
    	scanf("%d %d", &row, &col);
    	if (row > n || col > n)
            printf("Out of range row or column\n");
    	else {
            if (col >= 0 && row >= 0) {
            	if (board[row][col] != (char) 'U')
                    printf("Position already occupied, try again\n");
            	else {
                    board[row][col] = (char) 'R';
                    printBoard(board, n);
            	}
            }
    	}
    } while (row >= 0 && col >= 0);
    
    int start = 1;
    
    do {
        
    	if (start % 2 == 1) {
            bool found = true;
            do {
            	printf("Enter Black Move (ROW COL); (-1 -1) to finish: ");
            	scanf("%d %d", &row, &col);
            	if (row < 0 || col < 0)
                    break;
            	if (row > n - 1 || col > n - 1) {
                    printf("Out of range row or column\n");
                    found = true;
            	} else {
                    if (board[row][col] != (char) 'U') {
                    	printf("That square is already occupied or blocked\n");
                    	found = true;
                    } else {
                    	board[row][col] = (char) 'B';
                    	printBoard(board, n);
                    	found = false;
                    	for (int i = 0; i < n; i++) {
                            for (int j = 0; j < n; j++) {
                            	if (positionCounter[i][j] != 0)
                                    positionCounter[i][j]++;
                            }
                    	}
                    	positionCounter[row][col]++;
                    }
            	}
                
            } while (found);
    	} else {
            bool found = true;
            
            do {
            	printf("Enter White Move (ROW COL); (-1 -1) to finish: ");
            	scanf("%d %d", &row, &col);
            	if (row < 0 || col < 0)
                    break;
            	if (row > n - 1 || col > n - 1) {
                    printf("Out of range row or column\n");
                    found = true;
            	} else {
                    if (board[row][col] != (char) 'U') {
                    	printf("That square is already occupied or blocked\n");
                    	found = true;
                    } else {
                    	board[row][col] = (char) 'W';
                    	printBoard(board, n);
                    	found = false;
                    	for (int i = 0; i < n; i++) {
                            for (int j = 0; j < n; j++) {
                            	if (positionCounter[i][j] != 0)
                                    positionCounter[i][j]++;
                            }
                    	}
                    	positionCounter[row][col]++;
                    }
            	}
                
            } while (found);
    	}
    	start++;
    } while (row >= 0 && col >= 0);
    
    int theBiggest = 0;
    int maxLongest;
    int maxRow, maxCol;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
            if (board[i][j] == 'W' || board[i][j] == 'B') {
            	maxLongest = findLongest(board, n, i, j);
            	if (maxLongest > theBiggest) {
                    theBiggest = maxLongest;
                    maxRow = i;
                    maxCol = j;
            	}
            }
    	}
    }
    
    if (theBiggest >= 6 && board[maxRow][maxCol] == 'W')
    	printf("\nWhite wins\n");
    
    else if (theBiggest >= 6 && board[maxRow][maxCol] == 'B')
    	printf("\nBlack wins\n");
    
    else
    	printf("\nNo winner so far\n");
    
    do {
    	printf("Enter position (ROW COL) of square to measure; (-1 -1) to finish: ");
    	scanf("%d %d", &row, &col);
    	if (row > n - 1 || col > n - 1)
            printf("Out of range row or column\n");
    	else {
            if (row >= 0 && col >= 0) {
            	if (board[row][col] != 'B' && board[row][col] != 'W')
                    printf("That square is neither white nor black\n");
            	else{
                    int positioner=findLongest(board, n, row, col);
                    printf("Longest Run of %c at position (%d,%d) is %d\n", board[row][col], row, col, positioner);
            	}
            }
    	}
    } while (row >= 0 && col >= 0);
    
    printf("Goodbye");
    
    return (0);
}
