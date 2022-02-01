#include <iostream>
#include <fstream>

//Function Declaration
void createPuzzle(int);

std::vector< std::vector<int> > loadPuzzle(int size){
    
    std::vector< std::vector<int> > tempBoard = 
        {{0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    createPuzzle(5);
    std::ifstream genFile("SudokuPuzzles");
    std::string game;
    getline(genFile, game);

    int count = 0;
    while(count < game.length()){
        for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
                tempBoard[x][y] = game[count] - '0';
                count++;
            }
        }
    }
    return tempBoard;
}

void createPuzzle(int size){
    std::ofstream genFile("SudokuPuzzles");
    std::vector< std::vector<int> > board = getRandomValues();
    board = removeValues(board, size);
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            genFile << board[x][y];
        }
    }
    genFile.close();
}