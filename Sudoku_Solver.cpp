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

    //Initialized here because of it's static size
    std::vector< std::vector<int> > tempBoard;
    
    std::vector<int> removalQueue;
    //While there are more numbers to remove
    while(removalQuota > 0){
        //Sets to original state
        board = preservedBoard;
        removalQuota = preservedQuota;
        removalQueue = loadQueue(removalQuota);
        
        for(int index : removalQueue){
            if(removalQuota > 0){
                int x = index/9;
                int y = index%9;
            
                //Assigns a temporary board as to not mess with the working one
                 tempBoard = board;
            
                tempBoard[x][y] = 0;
                //Solves the board with the new missing piece (ensures only 1 possible solution)
                if(solve(tempBoard)){
                    //Removes the piece if it's a proper sudoku
                    board[x][y] = 0;
                    std::cout<<"Removed: " << "[" << x << "][" << y << "]" << "(" << index << ")" << std::endl;
                    removalQuota--;
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
    for(int count = 0; count < 81; count++){
        int tempVal = rand()%validNumbers.size();
        std::cout << validNumbers[tempVal] << std::endl;

        queue.push_back(validNumbers[tempVal]);

        dropValue(validNumbers, validNumbers[tempVal]);

    }

    return queue;
}