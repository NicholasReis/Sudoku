#include <iostream>

void displayBoard(int[9][9]);

int main()
{
    int board[9][9] = {{0, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 3, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 7, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 5, 0, 0, 0, 0, 0, 0}};

    displayBoard(board);

    return 0;
}


//Displays the board when given the array
void displayBoard(int board[9][9])
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            //Formats the board with a single line dividing cells
            //And a double to divide quadrants (or whatever they are called)
            std::cout << board[x][y];
            if ((y+1) % 3 == 0 && y!= 8)
            {
                std::cout << " || ";
            }else if(y != 8){
                std::cout << " | ";
            }
        }//Adds a second line to divide quadrants
        if((x+1) % 3 ==0){
            std::cout << std::endl <<  "----------||-----------||----------";
            std::cout << std::endl <<  "----------||-----------||----------";
        }else if(x != 8){
        }
        
        std::cout<< std::endl;
    }
}