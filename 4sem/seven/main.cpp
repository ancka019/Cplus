#include <iostream>

using namespace std;


int getRow(int board[5][3],int rows, int col){
    int row = - 1;
    for( int i= 0; i < rows; i++){
        if(board[i][col] != 0){
            row = i;
            break;
        }
    }
    return row;
}

void exit(int board[5][3],int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == 0){
                cout << " \t";
            }
            else {
                cout << board[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << "\n\n";
}

// перемещение диска
void move(char kernel1, char kernel2, int board[5][3],int rows, int cols){
    cout << "из стержня " << kernel1 << " в " << kernel2 << "\n";
    int col1 = (int)kernel1 - (int)'A';
    int col2 =(int)kernel2 - (int)'A';
    int row1 = getRow(board, rows, col1);
    int row2 = getRow(board,rows,col2);
    if(row2 == -1) {
        row2 = rows - 1;
    }
    else{
        row2--;
    }
    int value = board[row1][col1];
    board[row1][col1] = 0;
    board[row2][col2] = value;
    exit(board, rows, cols);
}

bool isEmpty(int board[5][3],int rows, int cols){
    int LastRowIndex = rows - 1;
    for( int j = 0; j < cols; j++){
        if(board[LastRowIndex][j] !=0){
            return false;
        }
    }
    return true;
}

void init(int countDisk, int board[5][3], int rows, int col){
    int LastRowIndex = rows -1;
    for( int i = LastRowIndex; countDisk > 0 ; i--){
        board[i][col] = countDisk;
        countDisk--;
    }
}

// пробегает всю башню
void tower( int amount, char kernel1, char kernel2, char temp,int board[5][3],int rows, int cols){
    if( amount == 0){
        return;
    }

    if(isEmpty(board,rows,cols)){
        init(amount, board, rows, 0);
        cout << "start";
        exit(board, rows,cols);
    }
    tower(amount -1, kernel1, temp, kernel2,board, rows, cols);
    move(kernel1, kernel2, board, rows, cols);
    tower(amount -1, temp, kernel2, kernel1,board, rows, cols);
}

int main() {
    const int rows = 5;
    const int cols = 3;
    int board[rows][cols] = {0};
    tower(3, 'A', 'B', 'C', board, rows, cols);
    return 0;
}
