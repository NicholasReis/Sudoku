#include <vector>
#include <time.h>


//Function Declarations
bool solve(std::vector< std::vector<int> >);
int bruteForceAnswers(std::vector< std::vector< std::vector<int> > >, std::vector< std::vector<int> >, int);
std::vector<int> loadQueue(int);

//This function will take the current board and number of values to remove before returning
//the board.
std::vector< std::vector<int> > removeValues(std::vector< std::vector<int> > board, int removalQuota){
    //Initializes the random timer
    srand(time(0));
    std::vector< std::vector<int> > preservedBoard = board;
    int preservedQuota = removalQuota;
    

    std::vector<int> removalQueue;

    //While there are more numbers to remove
    while(removalQuota > 0){
        bool failed = false;
        board = preservedBoard;
        removalQuota = preservedQuota;
        removalQueue = loadQueue(removalQuota);

        int counter = 0;
        while(counter < removalQueue.size() && !failed){

            int x = removalQueue[counter]/9;
            int y = removalQueue[counter]%9;
            
            //Creates a temporary board as to not mess with the working one
            std::vector< std::vector<int> > tempBoard = board;
            
            tempBoard[x][y] = 0;
            //Solves the board with the new missing piece (ensures only 1 possible solution)
            if(solve(tempBoard)){
                //Removes the piece if it's a proper sudoku
                board[x][y] = 0;

                //Decrements the quota
                removalQuota--;
                std::cout << "Quota Left: " << removalQuota << std::endl;
            }else{
                board = preservedBoard;
                removalQuota = preservedQuota;
                failed = true;
                removalQueue = loadQueue(removalQuota);
                std::cout << "Board Reset-----------------------------------------------------" << std::endl;
                
            }
            counter++;
        
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
                    }
                }
            }
                yValues[y] = cellPossibilities;
        }
        possibilities[x] = yValues;
    }

    //If the puzzle has exactly 1 answer
    int answers = bruteForceAnswers(possibilities, board, 0);
    if(answers == 1){
        //Returns true signalling a proper sudoku
        return true;
    }else{
        std::cout << "Board had: " << answers << std::endl;
    }

    //Too many or not enough solutions (should only ever be too many since it's a valid puzzle)
    return false;
}


int bruteForceAnswers(std::vector< std::vector< std::vector<int> > > possibilities, std::vector< std::vector<int> > board, int answers){
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            //If this cell is blank apply the possible values
            if(board[x][y] == 0){
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

std::vector<int> loadQueue(int quota){
    std::vector<int> queue;
    std::vector<int> validNumbers;
    for(int val = 0; val < 81; val++){
        validNumbers.push_back(val);
    }
    for(int count = 0; count < quota; count++){
        int tempVal = rand()%validNumbers.size();

        queue.push_back(tempVal);

        dropValue(validNumbers, tempVal);

    }

    return queue;
}