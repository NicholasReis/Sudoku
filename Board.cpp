#include <iostream>

void displayBoard(int[9][9]);

int main()
{
    int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 4, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 6, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 0, 0, 0, 0, 0, 0}};

    displayBoard(board);

    return 0;
}

void displayBoard(int board[9][9])
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            //Been a little while may be [x][y] or [y][x]
            std::cout << board[x][y];
            if ((y+1) % 3 == 0 && y!= 8)
            {
                std::cout << " || ";
            }else if(y != 8){
                std::cout << " | ";
            }
        }
        if((x+1)%3 ==0 && x != 8){
            std::cout << std::endl <<  "___________________________________";
        }
        std::cout<< std::endl;
    }
}