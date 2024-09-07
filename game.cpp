#include <iostream>
#include <vector>
#include <cmath>

int size;  // global variables for size and subgrid check
int temp;

// This function is used to find an empty cell in Sudoku and modify the value in row and col and return 1 if it exists
// otherwise, it returns 0 to show that no empty block is now present in Sudoku
int findEmptyCell(std::vector<std::vector<int>>& arr, int* row, int* col) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 0) {  // found empty cell and update row and col pass by address and return 1
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;  // no empty cell present, return 0
}

// If subgrids are possible, this function checks the subgrid and returns 1 if
// the value is present, else returns 0
int presentInSubgrid(int row, int col, int number, const std::vector<std::vector<int>>& arr) {
    if (temp * temp != size)  // if subgrid not possible, return 0
        return 0;

    int startRow = (row / temp) * temp;
    int startCol = (col / temp) * temp;

    for (int i = 0; i < temp; i++) {  // check for number present in that grid
        for (int j = 0; j < temp; j++) {
            if (arr[startRow + i][startCol + j] == number)
                return 1;  // if present, return 1
        }
    }
    return 0;  // if not found, return 0
}

// It accepts our Sudoku to solve with row and column backtracking arrays
int sudokuSolver(std::vector<std::vector<int>>& arr, std::vector<std::vector<int>>& rowBacktracking, std::vector<std::vector<int>>& colBacktracking) {
    int row, col;
    int flag = 0;
    int temp = findEmptyCell(arr, &row, &col);  // calling findEmptyCell function to find empty cell
    if (temp == 0)  // if no empty cell is present, then our Sudoku is solved and return 1
        return 1;

    for (int i = 1; i <= size; i++) {
        // check if value i is present in that particular row, column, or subgrid
        if (rowBacktracking[row][i - 1] || colBacktracking[col][i - 1] || presentInSubgrid(row, col, i, arr))
            continue;

        arr[row][col] = i;  // assign value i to the particular empty block
        rowBacktracking[row][i - 1] = 1;  // update row backtracking
        colBacktracking[col][i - 1] = 1;  // update col backtracking

        // call recursively for arr again with now new one cell filled
        flag = sudokuSolver(arr, rowBacktracking, colBacktracking);

        if (flag == 1)
            return 1;  // if the function returns 1, it means the value works, so return 1

        // if the function returns 0, it means we chose the wrong value
        // so make arr[row][col] = 0 again and try for another value of i
        arr[row][col] = 0;
        rowBacktracking[row][i - 1] = 0;
        colBacktracking[col][i - 1] = 0;
    }
    // if no value of i works, return 0
    return 0;
}

// This function initializes required arrays for backtracking
// and calls sudokuSolver to solve the Sudoku recursively with backtracking
int LetsSolveSudoku(std::vector<std::vector<int>>& arr) {
    // allocating memory for backtracking
    std::vector<std::vector<int>> rowBacktracking(size, std::vector<int>(size, 0));
    std::vector<std::vector<int>> colBacktracking(size, std::vector<int>(size, 0));

    // storing value in column and row backtracking arrays
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] > size)
                return -1;
            if (arr[i][j] != 0) {
                if (rowBacktracking[i][arr[i][j] - 1] == 0)
                    rowBacktracking[i][arr[i][j] - 1] = 1;
                else
                    return 0;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] > size)
                return -1;
            if (arr[i][j] != 0) {
                if (colBacktracking[j][arr[i][j] - 1] == 0)
                    colBacktracking[j][arr[i][j] - 1] = 1;
                else
                    return 0;
            }
        }
    }
    // calling the sudokuSolver function with row and col backtracking
    return sudokuSolver(arr, rowBacktracking, colBacktracking);
}

int lenOfInt(int a) {
    int count = 0;
    while (a != 0) {
        a /= 10;
        count++;
    }
    return count;
}

void accuratePrint(int a) {
    int len = lenOfInt(a);
    int lenOfSize = lenOfInt(size);
    for (int i = 0; i < lenOfSize - len; i++) {
        std::cout << " ";
    }
    std::cout << " " << a << " ";
}

int main() {
    std::cout << "\n!!!Welcome to Sudoku Solver Program!!!\n";
    while (true) {
        std::cout << "\nEnter the size of Sudoku in integer format (enter -1 to exit)\n";
        std::cin >> size;
        if (size == -1)
            break;
        else if (size <= 0) {
            std::cout << "Enter correct size\n";
            continue;
        }
        temp = std::sqrt(size);
        std::vector<std::vector<int>> grid(size, std::vector<int>(size));
        std::cout << "Enter Sudoku Grid\n";  // taking grid input from user
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cin >> grid[i][j];
            }
        }
        int ans = LetsSolveSudoku(grid);  // calling function to solve Sudoku

        if (ans == 1) {
            std::cout << "\nBingo!!! The answer is\n\n";  // if answer exists, print the grid
            int var = (lenOfInt(size) + 2) * size + static_cast<int>(std::ceil(std::sqrt(size))) + 1;
            for (int i = 0; i < size; i++) {
                if (i == 0 || i % static_cast<int>(std::ceil(std::sqrt(size))) == 0) {
                    for (int k = 0; k < var; k++)
                        std::cout << "-";
                    std::cout << "\n";
                }
                for (int j = 0; j < size; j++) {
                    if (j == 0 || j % static_cast<int>(std::ceil(std::sqrt(size))) == 0)
                        std::cout << "|";
                    accuratePrint(grid[i][j]);
                }
                std::cout << "|\n";
            }
            for (int k = 0; k < var; k++)
                std::cout << "-";
            std::cout << "\n";
        } else if (ans == -1)
            std::cout << "\nEnter correct values in Sudoku.\n";  // error in values
        else
            std::cout << "Sorry, no solution exists for the given Sudoku.\n";  // else, print no solution exists

        char c;
        std::cout << "\nWant to continue? Press y for yes, n for no\n";
        std::cin >> c;
        if (c == 'n')
            break;
    }

    return 0;
}
