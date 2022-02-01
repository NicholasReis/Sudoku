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
    //Check for puzzles of this size and if one already exists
    //If not create a new puzzle
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
    std::fstream genFile("SudokuPuzzles");

    //Search for "Size: xx" for puzzle size
    //Then append a new line to fill here

    std::vector< std::vector<int> > board = getRandomValues();
    board = removeValues(board, size);
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            genFile << board[x][y];
        }
    }
    genFile.close();
}