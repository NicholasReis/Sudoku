#include <iostream>
#include <vector>


//Function Declarations


//Global variables
int timesSolved = 0;

//Checks if the game is solveable
bool solveable(std::vector<std::vector<int>> board){
    std::vector<std::vector<std::vector<int>>> possibilities;
    for(int x = 0; x < 9; x++){
        std::vector<std::vector<int>> yValues;
        for(int y = 0; y < 9; y++){
            std::vector<int> optionsForCell;
            if(board[x][y] == 0){
                //std::cout << "[" << x << "][" << y << "]: ";
                for(int index = 1; index < 10; index++){
                    if(verticalTest(x, y, index, board) && horizontalTest(x, y, index, board) && boxTest(x, y, index, board)){
                        //std::cout << index << ", ";
                        optionsForCell.push_back(index);
                    }
                }
                //std::cout<< std::endl;
            }
            
            yValues.push_back(optionsForCell);
        }
        possibilities.push_back(yValues);
    }
    return false;
}


//Checks if the game can be solved in exactly one way
bool properSudoku(){
    if(timesSolved == 1){
        return true;
    }else{
        return false;
    }
}



