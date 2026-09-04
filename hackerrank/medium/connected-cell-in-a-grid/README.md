# Connected Cells in a Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Consider a matrix where each cell contains either a $0$ or a $1$.  Any cell containing a $1$ is called a *filled* cell. Two cells are said to be *connected* if they are adjacent to each other horizontally, vertically, or diagonally.  In the following grid, all cells marked `X` are connected to the cell marked `Y`.

    XXX
    XYX  
    XXX    

If one or more filled cells are also connected, they form a *region*. Note that each cell in a region is connected to zero or more cells in the region but is not necessarily directly connected to all the other cells in the region.

Given an $n \times m$ matrix, find and print the number of cells in the largest *region* in the matrix. Note that there may be more than one region in the matrix.

For example, there are two regions in the following $3 \times 3$ matrix.  The larger region at the top left contains $3$ cells.  The smaller one at the bottom right contains $1$.  

    110
    100
    001


**Function Description**  

Complete the *connectedCell* function in the editor below.  

connectedCell has the following parameter(s):  
- *int matrix[n][m]*: $matrix[i]$ represents the $i^{th}$ row of the matrix  

**Returns**   
- *int:* the area of the largest region  

**Input Format**

The first line contains an integer $n$, the number of rows in the matrix.		
The second line contains an integer $m$, the number of columns in the matrix.		
Each of the next $n$ lines contains $m$ space-separated integers $matrix[i][j]$.

**Constraints**

- $0 \lt n, m \lt 10$

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-04T03:25:21.356Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int getRegionSize(vector<vector<int>>& matrix, int row, int col) {
    
    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] == 0) {
        return 0;
    }

  
    matrix[row][col] = 0;
    int size = 1; 

    
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            size += getRegionSize(matrix, r, c);
        }
    }

    return size;
}

int connectedCell(vector<vector<int>> matrix) {
    int maxRegion = 0;

    
    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[0].size(); c++) {
    
            if (matrix[r][c] == 1) {
                int currentRegionSize = getRegionSize(matrix, r, c);
    
                maxRegion = max(maxRegion, currentRegionSize);
            }
        }
    }

    return maxRegion;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem)