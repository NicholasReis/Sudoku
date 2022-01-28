#include <iostream>
#include <vector>
#include <time.h>


//Function Declarations
bool solve(std::vector<std::vector<int>>);
int bruteForceAnswers(std::vector<std::vector<std::vector<int>>>, std::vector<std::vector<int>>, int);
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
                //For each value 1-9 (tests each possible number in the cell)
                for(int index = 1; index < 10; index++){
                    //Checks if the test number is valid
                    if(verticalTest(x, y, index, board) && horizontalTest(x, y, index, board) && boxTest(x, y, index, board)){
                        //If valid, puts it into the temporary array
                        cellPossibilities.push_back(index);
                    }
                }
                //Puts the temporary array into the y value array
                yValues.push_back(cellPossibilities);
            }
            //Puts the y value array into the permanent array
            possibilities.push_back(yValues);
        }
    }
    
    if(bruteForceAnswers(possibilities, board, 0) == 1){
        return true;
    }
    return false;
}

int bruteForceAnswers(std::vector< std::vector< std::vector<int> > > possibilities, std::vector< std::vector<int> > board, int answers){
    
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            //If this cell is blank apply the possible values
            if(board[x][y] == 0){
                //For each possibility it will apply the answer to the board, remove the value from possibilities and pass it back to this function
                for(int index : possibilities[x][y]){ //<--- Breaks here
                    //Checks if the test number is valid
                    if(verticalTest(x, y, index, board) && horizontalTest(x, y, index, board) && boxTest(x, y, index, board)){
                        //Assigns the board a possible value
                        board[x][y] = index;
                        //Removes the applied possible value
                        possibilities[x][y].erase(possibilities[x][y].begin());
                        //Sends the updated board and new possibilities (will not trigger Y values because this cell is now occupied on the board)
                        bruteForceAnswers(possibilities, board, answers);
                    }
                }
            }
        }
    }
    
    std::cout << answers << std::endl;//Debug info. Is not reached.
    return answers;
}

std::vector<std::vector<int>> dropValue(std::vector<std::vector<int>> board, int x, int y){
    //Creating a new board to test on
    if(board[x][y] != 0){
        board[x][y] = 0;
    }
    return board;
}