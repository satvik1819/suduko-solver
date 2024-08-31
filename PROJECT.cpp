#include <iostream>
using namespace std;

const int SIZE = 9;
bool rowCheck[SIZE][SIZE] = {false};
bool colCheck[SIZE][SIZE] = {false};
bool subgridCheck[SIZE][SIZE] = {false};

bool isValid(int grid[SIZE][SIZE], int row, int col, int num)
{
    return !rowCheck[row][num - 1] &&
           !colCheck[col][num - 1] &&
           !subgridCheck[row / 3 * 3 + col / 3][num - 1];
}

bool solveSudoku(int grid[SIZE][SIZE])
{
    int row = -1, col = -1;
    bool isEmpty = false;
    for (int i = 0; i < SIZE && !isEmpty; i++)
    {
        for (int j = 0; j < SIZE && !isEmpty; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = true;
            }
        }
    }

    if (!isEmpty)
        return true;

    for (int num = 1; num <= SIZE; num++)
    {
        if (isValid(grid, row, col, num))
        {
            grid[row][col] = num;
            rowCheck[row][num - 1] = true;
            colCheck[col][num - 1] = true;
            subgridCheck[row / 3 * 3 + col / 3][num - 1] = true;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;
            rowCheck[row][num - 1] = false;
            colCheck[col][num - 1] = false;
            subgridCheck[row / 3 * 3 + col / 3][num - 1] = false;
        }
    }

    return false;
}

void printGrid(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] != 0)
            {
                int num = grid[i][j];
                rowCheck[i][num - 1] = true;
                colCheck[j][num - 1] = true;
                subgridCheck[i / 3 * 3 + j / 3][num - 1] = true;
            }
        }
    }

    if (solveSudoku(grid))
    {
        cout << "Solved Sudoku:" << endl;
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}
