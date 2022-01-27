#include <iostream>
#include <vector>
#include <time.h>


//Function Declarations
bool solve(std::vector<std::vector<int>>);

std::vector<std::vector<int>> dropValue(std::vector<std::vector<int>>, int, int);

//This function will take the current board and number of values to remove before returning
//the board.
std::vector<std::vector<int>> removeValues(std::vector<std::vector<int>> board, int removalQuota){
    //Initializes the random timer
    srand(time(0));

    //While there are more numbers to remove
    while(removalQuota > 0){
        int x = (rand()%9);
        int y = (rand()%9);
        std::vector<std::vector<int>> tempBoard = dropValue(board, x, y);
        
        if(solve(tempBoard)){
            board[x][y] = 0;
            removalQuota--;
        }
    }

    return board;
}

//Global variables
int timesSolved = 0;

//Checks if the game is solveable
bool solve(std::vector<std::vector<int>> board){
    std::vector<std::vector<std::vector<int>>> possibilities;
    
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            std::vector<std::vector<int>> yValues;
            if(board[x][y] = 0){ //Never triggers
                std::vector<int> cellPossibilities;
                std::cout << "[" << x << "][" << y << "]: ";
                for(int index = 1; index < 10; index++){
                    if(verticalTest(x, y, index, board) && horizontalTest(x, y, index, board) && boxTest(x, y, index, board)){
                        cellPossibilities.push_back(index);
                        std::cout << index << ", ";
                    }
                }
                std::cout << std::endl;
                yValues.push_back(cellPossibilities);
            }
            possibilities.push_back(yValues);
        }
    }
    return true;
}

std::vector<std::vector<int>> dropValue(std::vector<std::vector<int>> board, int x, int y){
    //Creating a new board to test on
    if(board[x][y] != 0){
        board[x][y] = 0;
    }
    return board;
}