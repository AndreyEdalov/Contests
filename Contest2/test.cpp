#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(const vector<vector<int>>& matrix)
{
    for (int i = 0 ; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == -1) {
                cout << "* ";
            } else {
                cout << matrix[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

void Cells(vector<vector<int>>& matrix, int x, int y)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int newX = x + i;
            int newY = y + j;
            if
                    (
                    newX >= 0 && newX < matrix.size() &&
                    newY >= 0 && newY < matrix[0].size() &&
                    matrix[newX][newY] != -1
                    )
            {
                matrix[newX][newY]++;
            }
        }
    }
}

vector<vector<int>> mineMatrix(vector<int> xBombs, vector<int> yBombs, int n, int m)
{
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < xBombs.size(); i++)
    {
        matrix[xBombs[i]][yBombs[i]] = -1;
    }
    for (int i = 0; i < xBombs.size(); i++)
    {
        Cells(matrix, xBombs[i], yBombs[i]);
    }
    return matrix;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> xBombs(k), yBombs(k);

    while (k != 0)
    {
        cin >> xBombs[xBombs.size() - k] >> yBombs[yBombs.size() - k];
        xBombs[xBombs.size() - k] -= 1;
        yBombs[yBombs.size() - k] -= 1;
        k--;
    }

    auto matrix = mineMatrix(xBombs, yBombs, n, m);

    print(matrix);

    return 0;
}