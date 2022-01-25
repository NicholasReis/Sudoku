#include <iostream>
#include <vector>
#include <time.h>

//Function Declarations
bool dropValue(std::vector<std::vector<int>>, int, int);

//This function will take the current board and number of values to remove before returning
//the board.
std::vector<std::vector<int>> removeValues(std::vector<std::vector<int>> board, int removalQuota){
    //Initializes the random timer
    srand(time(0));

    //While there are more numbers to remove
    while(removalQuota > 0){
        int xRemove = (rand()%9);
        int yRemove = (rand()%9);
        if(dropValue(board, xRemove, yRemove)){
            board[xRemove][yRemove] = 0;
            removalQuota--;
        }
    }

    return board;
}

bool dropValue(std::vector<std::vector<int>> board, int x, int y){
    //Creating a new board to test on
    if(board[x][y] != 0){
        board[x][y] = 0;
        return true;
    }else{
        return false;
    }
}