#include <vector>
#include <time.h>


//Function Declarations
bool solve(std::vector< std::vector<int> >);
int bruteForceAnswers(std::vector< std::vector< std::vector<int> > >, std::vector< std::vector<int> >, int);
std::vector< std::vector<int> > dropValue(std::vector< std::vector<int> >, int, int);

//This function will take the current board and number of values to remove before returning
//the board.
std::vector< std::vector<int> > removeValues(std::vector< std::vector<int> > board, int removalQuota){
    //Initializes the random timer
    srand(time(0));

    //While there are more numbers to remove
    while(removalQuota > 0){
        //Randomly grabs an X and Y coordinate
        int x = (rand()%9);
        int y = (rand()%9);

        //Creates a temporary board as to not mess with the working one
        std::vector< std::vector<int> > tempBoard = board;
        //Makes sure it's not a repeated cell
        if(tempBoard[x][y] != 0){
            tempBoard[x][y] = 0;
            //Solves the board with the new missing piece (ensures only 1 possible solution)
            if(solve(tempBoard)){
                //Removes the piece if it's a proper sudoku
                board[x][y] = 0;
                //Decrements the quota
                removalQuota--;
            }
        }
    }
    
    return board;
}

//Checks if the game is solveable
bool solve(std::vector< std::vector<int> > board){
    //Creates an array to hold possible values for each cell
    std::vector< std::vector< std::vector<int> > > possibilities;
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            //Stores the values of each Y value to put into the possibility cells
            std::vector< std::vector<int> > yValues;
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
                    }else{
                    }
                }
                yValues.push_back(cellPossibilities);
            }
            possibilities.push_back(yValues);
        }
    }

    //If the puzzle has exactly 1 answer
    if(bruteForceAnswers(possibilities, board, 0) == 1){
        //Returns true signalling a proper sudoku
        return true;
    }

    //Too many or not enough solutions (should only ever be too many since it's a valid puzzle)
    return false;
}


int bruteForceAnswers(std::vector< std::vector< std::vector<int> > > possibilities, std::vector< std::vector<int> > board, int answers){
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            //If this cell is blank apply the possible values
            if(board[x][y] == 0){
                //For each possibility it will apply the answer to the board, remove the value from possibilities and pass it back to this function
                for(int index = 0; index < possibilities[x].size(); index++){
                    //Checks if the test number is valid
                    if(verticalTest(x, y, index, board) && horizontalTest(x, y, index, board) && boxTest(x, y, index, board)){
                        //Assigns the board a possible value
                        board[x][y] = index;
                        //Removes the applied possible value
                        possibilities[x].erase(possibilities[x].begin()); //<-- Suspect Broke here when possibilities[x][y]. Both seem to work generally the same? Will look into more theory
                        if(!possibilities[x].empty()){
                            //Sends the updated board and new possibilities (will not trigger Y values because this cell is now occupied on the board)
                            answers += bruteForceAnswers(possibilities, board, answers); //Assigns answer to be accumulated in order to make the recursion work
                        }
                    }
                }
                
            }
        }
    }

    //Increments answer 
    answers++;

    return answers;
}