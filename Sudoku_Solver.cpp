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
    //Creates an array to hold possible values for each cell
    std::vector<std::vector<std::vector<int>>> possibilities;
    
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            //Stores the values of each Y value to put into the possibility cells
            std::vector<std::vector<int>> yValues;
            //If the cell is blank
            if(board[x][y] == 0){
                //Create a temporary array for the possible cell values
                std::vector<int> cellPossibilities;
                std::cout << "[" << x << "][" << y << "]: ";
                //For each value 1-9 (tests each possible number in the cell)
                for(int index = 1; index < 10; index++){
                    //Checks if the test number is valid
                    if(verticalTest(x, y, index, board) && horizontalTest(x, y, index, board) && boxTest(x, y, index, board)){
                        //If valid, puts it into the temporary array
                        cellPossibilities.push_back(index);
                        std::cout << index << ", ";
                    }
                }
                std::cout << std::endl;
                //Puts the temporary array into the y value array
                yValues.push_back(cellPossibilities);
            }
            //Puts the y value array into the permanent array
            possibilities.push_back(yValues);
        }
    }

    //Returns true until I can get the logic to check in
    return true;
}

std::vector<std::vector<int>> dropValue(std::vector<std::vector<int>> board, int x, int y){
    //Creating a new board to test on
    if(board[x][y] != 0){
        board[x][y] = 0;
    }
    return board;
}