#include <vector>
#include <time.h>


//Function Declarations
bool solve(std::vector< std::vector<int> >);
int bruteForceAnswers(std::vector< std::vector< std::vector<int> > >, std::vector< std::vector<int> >, int);
std::vector<int> removeFirstElement(std::vector<int>);
std::vector<int> possibilitiesToVectorInt(std::vector<int>);

//This function will take the current board and number of values to remove before returning
//the board.
std::vector< std::vector<int> > removeValues(std::vector< std::vector<int> > board, int removalQuota){
    //Initializes the random timer
    srand(time(0));
    std::vector< std::vector<int> > preservedBoard = board;
    int preservedQuota = removalQuota;
    int failure = 0;

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
                failure = 0;
                removalQuota--;
                std::cout << "Quota Left: " << removalQuota << std::endl;
            }else{
                failure++;
                if(failure > 100){ //I can make a board to test which values have been pulled out and didnt work to get this number exact
                    board = preservedBoard;
                    removalQuota = preservedQuota;
                    failure = 0;
                    std::cout << "Board Reset-----------------------------------------------------" << std::endl;
                }
            }
        }
    }

    return board;
}

//Checks if the game is solveable
bool solve(std::vector< std::vector<int> > board){
    //Creates an array to hold possible values for each cell
    std::vector< std::vector< std::vector<int> > > possibilities(9);
    for(int x = 0; x < 9; x++){
        //Stores the values of each Y value to put into the possibility cells
        std::vector< std::vector<int> > yValues(9);
        for(int y = 0; y < 9; y++){
            //Create a temporary array for the possible cell values
            std::vector<int> cellPossibilities = {};
            //If the cell is blank
            if(board[x][y] == 0){
                //For each value 1-9 (tests each possible number in the cell)
                for(int index = 1; index < 10; index++){
                    //Checks if the test number is valid
                    if(verticalTest(x, y, index, board) && horizontalTest(x, y, index, board) && boxTest(x, y, index, board)){
                        //If valid, puts it into the temporary array
                        cellPossibilities.push_back(index);
                        //std::cout << "Assigned [" << x << "][" << y << "]: " << index << std::endl;
                    }
                }
            }
                //std::cout << "YValues Checkpoint" << std::endl;
                yValues[y] = cellPossibilities;
                //std::cout << "Y: " << yValues.size() << std::endl;
        }
        //std::cout << "XValues Checkpoint" << std::endl;
        possibilities[x] = yValues;
        //std::cout << "X: " << possibilities.size() << std::endl;
    }

    /*
    std::cout << "Done implementation..." << std::endl;

    for(int x = 0; x < possibilities.size(); x++){
        for(int y = 0; y < possibilities[x].size(); y++){
            if(!possibilities[x][y].empty()){
                for(int index = 0; index < possibilities[x][y].size(); index++){
                    std::cout << "[" << x << "][" << y << "]: " << possibilities[x][y][index];
                }
            }
        }
    }
    std::cout << "Done Display" << std::endl;
    */

    //If the puzzle has exactly 1 answer
    int answers = bruteForceAnswers(possibilities, board, 0);
    if(answers == 1){
        //Returns true signalling a proper sudoku
        return true;
    }else{
        //std::cout << "Board had: " << answers << std::endl;
    }

    //Too many or not enough solutions (should only ever be too many since it's a valid puzzle)
    return false;
}


int bruteForceAnswers(std::vector< std::vector< std::vector<int> > > possibilities, std::vector< std::vector<int> > board, int answers){
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            //If this cell is blank apply the possible values
            if(board[x][y] == 0){
                //std::cout << "Options for [" << x << "][" << y << "]: ";
                for(int index = 0; index < possibilities[x][y].size(); index++){
                    board[x][y] = possibilities[x][y][index];
                    answers += bruteForceAnswers(possibilities, board, answers);
                }
                return answers;
            }
        }
    }
    answers++;
    return answers;
}

std::vector<int> removeFirstElement(std::vector<int> possibilities){
    std::cout << "Dropping";
    
    std::vector<int> tempPossibilities;
    if(static_cast<int>(possibilities.size()) > 0){
    std::cout << "..." << std::endl;
    
        for(int index =1; index < static_cast<int>(possibilities.size()); index++){
            tempPossibilities.push_back(possibilities[index]);
        }
    std::cout << "Dropped: " << possibilities[0] << std::endl;
    }
    return tempPossibilities;
}

std::vector<int> possibilitiesToVectorInt(std::vector<int>possibilities){
    std::vector<int> tempArray;
    std::cout << "This";
    for(int index = 0; index < static_cast<int>(possibilities.size()); index++){
        tempArray.push_back(possibilities[index]);
    }
    return tempArray;
}