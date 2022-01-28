#include <iostream>
#include <vector>
#include <time.h>

#include "Value_Generator.cpp"
#include "Sudoku_Solver.cpp"


void displayBoard(std::vector< std::vector<int> >);

int main()
{
    //Retrieves the random (valid) values and puts them into a 2d vector
    std::vector< std::vector<int> > board = getRandomValues();
    displayBoard(board);
    //Removes the pieces to create the puzzle
    board = removeValues(board, 30);

    //Displays the board
    displayBoard(board);
    
    return 0;
}




//Displays the board when given the array
void displayBoard(std::vector< std::vector<int> > board)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            //Formats the board with a single line dividing cells
            //And a double to divide quadrants (or whatever they are called)
            if(board[x][y] != 0){
                std::cout << board[x][y];
            }else{
                std::cout << " ";
            }
            if ((y+1) % 3 == 0 && y!= 8)
            {
                std::cout << " || ";
            }else if(y != 8){
                std::cout << " | ";
            }
        }//Adds a second line to divide quadrants
        if((x+1) % 3 ==0 && x != 8){
            std::cout << std::endl <<  "----------||-----------||----------";
            std::cout << std::endl <<  "----------||-----------||----------";
        }
        
        std::cout<< std::endl;
    }
}
