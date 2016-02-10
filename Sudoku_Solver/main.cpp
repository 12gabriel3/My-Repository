#include <stdio.h>

int isValid(int puzzle[][9], int row, int column, int num){
    int row1 = row/3;
    int column1 = column/3;

    for(int i = 0; i < 9; i++){
        if(puzzle[row][i] == num) return 0;
        if(puzzle[i][column] == num) return 0;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(puzzle[row1*3 + i][column1*3 + j] == num) return 0;
        }
    }

    return 1;
}



int solveSudoku(int puzzle[][9], int row, int column){
    if(row == 9) return 1;

    if(puzzle[row][column]){
        if(column == 8){
            if(solveSudoku(puzzle, row + 1, 0)) return 1;
        } else {
            if(solveSudoku(puzzle, row, column + 1)) return 1;
        }
        return 0;
    }

    for (int num = 1; num < 10; num++) {
        if (isValid(puzzle, row, column, num)) {
            puzzle[row][column] = num;
            if (column == 8) {
                if (solveSudoku(puzzle, row + 1, 0)) return 1;
            } else {
                if (solveSudoku(puzzle, row, column + 1)) return 1;
            }
        }
    }
    puzzle[row][column] = 0;
    return  0;
}

int displaySudoku(int puzzle[][9], int row, int column){
    if(row == 9) return 0;

    if(column == 8){
        printf("%d\n", puzzle[row][column]);
        displaySudoku(puzzle, row + 1, 0);
    } else {
        printf("%d ", puzzle[row][column]);
        displaySudoku(puzzle, row, column +1);
    }
}

int main() {
    int puzzle[][9] = {
            0, 6, 5, 8, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 8, 4,
            0, 0, 9, 0, 6, 3, 0, 0, 0,
            5, 0, 0, 0, 0, 0, 9, 0, 0,
            9, 3, 0, 5, 0, 2, 0, 1, 7,
            0, 0, 7, 0, 0, 0, 0, 0, 3,
            0, 0, 0, 3, 2, 0, 5, 0, 0,
            6, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 2, 6, 0
    };
    displaySudoku(puzzle, 0, 0);
    solveSudoku(puzzle, 0, 0);
    printf("\n");
    displaySudoku(puzzle, 0, 0);

    return 0;
}
