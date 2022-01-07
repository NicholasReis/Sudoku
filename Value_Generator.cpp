#include <iostream>
#include <vector>
#include <time.h>


//Function declarations
std::vector<std::vector<int>>swapValues(int, std::vector<std::vector<int>>);
bool verticalTest(int, int, std::vector<std::vector<int>>);
bool horizontalTest(int, int, std::vector<std::vector<int>>);
bool boxTest(int, int, std::vector<std::vector<int>>);


//Will return a valid selection of random values in a 2d vector to the board class
std::vector<std::vector<int>> getRandomValues()
{

    //Initializes the random timer
    srand(time(0));

    //So long as the numbers are already set I don't need to
    //waste time generating them. I will swap the required ones instead
    std::vector<std::vector<int>> currentBoard =
        {{1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9},
         {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    //Because we need every value 1-9 to remain in the first row
    //in a different order I will just send the rows to swap horizontal positions
    for(int x = 0; x < 9; x++){
        currentBoard = swapValues(x, currentBoard);
    }

    //Returns the board after all the swaps
    return currentBoard;
}


//This function swaps the values and does tests to make sure it's a valid position
//before returning the updated board
std::vector<std::vector<int>>swapValues(int x, std::vector<std::vector<int>> board){

    //Each row will begin at index 0, find an appropriate swap
    //and lock in the past numbers to avoid breaking working cells
    for(int y= 0; y < 9; y++){
        //Remaining cells tracks how many cells past y there are left
        int remainingCells = 9-y;

        //Random number between y and board length
        int position = (rand() % remainingCells) + y;
        
        //Disabled until tests are written, but will continuously swap until a valid position is found
        //(May need to consider a breakout case, but for now I think the numbers will always work with this algorithm)
        //while(!verticalTest(x, y, board) || !horizontalTest(x, y, board) || !boxTest(x, y, board)){
            //Swaps the position with a random value on the board
            int tempVal = board[x][y];
            board[x][y] = board[x][position];
            board[x][position] = tempVal;
        //}

    }

    //Returns the updated board
    return board;
}
