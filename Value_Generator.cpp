#include <iostream>
#include <vector>
#include <time.h>

//Function declarations
std::vector<std::vector<int>> addValueToBoard(int, int, int, std::vector<std::vector<int>>);
bool verticalTest(int, int, int, std::vector<std::vector<int>>);
bool boxTest(int, int, int, std::vector<std::vector<int>>);
std::vector<int> dropValue(std::vector<int>, int);


//Will return a valid selection of random values in a 2d vector to the board class
std::vector<std::vector<int>> getRandomValues()
{

    //Initializes the random timer
    srand(time(0));

    //Empty board so there are no conflicts as we go.
    std::vector<std::vector<int>> currentBoard =
        {{0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    

    //Because we need every value 1-9 to remain in the first row
    //in a different order I will just send the rows to swap horizontal positions
    for (int x = 0; x < 9; x++)
    {
        //For every X we will reset the array of numbers we can use
        std::vector<int> validNumbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (int y = 0; y < 9; y++)
        {
            bool passed = false;
            int resetCounter = 0;
            while (!passed && resetCounter < 20)
            {
                int testValue = validNumbers[(rand() % validNumbers.size())];
                if (verticalTest(x, y, testValue, currentBoard)) // && boxTest(x, y, currentBoard)
                {
                    currentBoard = addValueToBoard(x, y, testValue, currentBoard);
                    passed = true;
                    validNumbers = dropValue(validNumbers, testValue);

                }else{
                    resetCounter++;
                }
            }
            if(resetCounter >= 19){
                x--;
                break;
            }
        }
    }

    //Returns the board after all the swaps
    return currentBoard;
}

//This function swaps the values and does tests to make sure it's a valid position
//before returning the updated board
std::vector<std::vector<int>> addValueToBoard(int x, int y, int value, std::vector<std::vector<int>> board)
{
    //Swaps the position with a random value on the board
    board[x][y] = value;

    //Returns the updated board
    return board;
}

bool verticalTest(int x, int y, int value, std::vector<std::vector<int>> board)
{
    std::vector<std::vector<int>> tempBoard = board;
    tempBoard = addValueToBoard(x, y, value, tempBoard);
    for (int tempX = 0; tempX < 9; tempX++)
    {
        if (tempBoard[x][y] == tempBoard[tempX][y] && x != tempX)
        {
            return false;
        }
    }
    return true;
}

//bool boxTest(int x, int y, std::vector<std::vector<int>> board){

//}

std::vector<int> dropValue(std::vector<int> numArray, int value){
    bool removed = false;
    std::vector<int> tempArr = {};
    for(int position : numArray){
        if(position != value){
            tempArr.push_back(position);
        }
    }
    return tempArr;
}