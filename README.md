## Description
Sudoku creates CLI sudoku puzzles. This project was just created for fun. I have heard people in various discord servers and forums about using a sudoku solver as a benchmark for their skills and decided to take it a step further. This program builds sudoku puzzles by solving them, effectively being both a puzzle generator and puzzle solver.

## How It Works (Functional)
Just run the code. No input required. You can change the "cellsToSolve" variable to adjust the blank spaces on the board. There will be an exponential increase in time the more open spaces there are; this is because a "proper sudoku" has only one solution, if there are more spaces open, there are more available solutions.

## How It Works (Techincal)
The program begins by creating 9 lists of numbers 1-9 and randomly assigns them from top to bottom, left to right. After each number is placed it checks it is a legal move (not repeated vertically, nor in the neighbouring cells) and removes it from the list. Because it is a unique list of numbers 1-9 it is impossible for it to fail the horizontal test and therefor is not checked. Once the board is populated with a legal puzzle it incrementally removes a random number up to "cellsToSolve". Once a cell is removed it will be solved by recursively creating every possible board outcome. If more than one solution is possible it will be marked as an illegal game and a new cell will be marked for removal. If there is are too many tries the board will be considered impossible and restart the process with a new board.

## What's Next
- There are a lot of ways I could reduce the variability of results. For instance there is probably a way to flag a board with the cells I have attempted to remove so there are no repeated processes.
- Allowing the "cellsToSolve" to be set via command line would make it a little bit easier to use.
- Saving boards on games with "cellsToSolve" > 46 would increase speed, however I would also need to implement a way to ask for a unique or old puzzle.

## Warning
The fewest possible clues you can have is 17. With the board being 9x9 (81) and subtracting 17 from that, 64 is the absolute highest value "cellsToSolve" can be. This program currently struggles above 46, but a first grader could do faster arithmetic than my CPU so you may have better results than me.

Read More Here:
https://www.technologyreview.com/2012/01/06/188520/mathematicians-solve-minimum-sudoku-problem/
