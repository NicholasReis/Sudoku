#include <iostream>
#include <vector>
#include <time.h>

//Function Declarations


//This function will take the current board and number of values to remove before returning
//the board.
std::vector<std::vector<int>> removeValues(std::vector<std::vector<int>> board, int removalQuota){
    //Initializes the random timer
    srand(time(0));
    
    //While there are more numbers to remove
    while(removalQuota > 0){

        removalQuota--;
    }

    return board;
}
