### Project Name:
# DSA-Project-SudokuSolver-using-Backtracking-Algorithm

### Hello guys, Welcome to our Sudoku-Solver Programme.


// This program helps you find a solution for any size of Sudoku, not limited by the size of the grid.
// Time complexity is O(n^m), where 'n' is the number of possible values in a single block and 'm' is the number of empty blocks to fill.
// Despite its time complexity, the solution is fast due to the use of backtracking.


// Key Features:
    1. User can input any grid size.
    2. Utilizes the Backtracking Algorithm, ensuring fast solutions.
    3. Easy-to-read output format.
    4. Entire code written in **C++**.
    5. For standard Sudoku grids like 9x9 or 16x16 (perfect squares), it ensures a unique value in the subgrid.
    
// Libraries Used:
  - <cmath> for arithmetic operations.
  - <cstdlib> for dynamic memory allocation used in backtracking.
  - <iostream> and <vector> for input/output operations and dynamic data structures.
  
// How It Works:
  1) First, it finds the empty location to be filled.
  2) Then, it tries all possible values iteratively for that location.
  3) If a value satisfies the grid conditions, the algorithm recursively calls for the next empty cell.
  4) It continues this process until a solution is found.
  5) If a solution is found, it returns true and prints the solution.
  6) If no solution is possible, it returns false.
  7) If there is an error in input, it handles it gracefully.


### Working Application 

##### 4X4 Sudoku:

<img src="4X4.png" width="750" height="380"/>

##### 9X9 Sudoku:

<img src="9X9.png" width="750" height="380"/>

##### 12X12 Sudoku:

<img src="12X12.png" width="750" height="380"/>


