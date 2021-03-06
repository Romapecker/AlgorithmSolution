#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<bool> > visited1(8, vector<bool>(8, false));
vector<vector<bool> > visited2(8, vector<bool>(8, false));

void flood(int i, int j, vector<vector<bool> > &visited)
{
    visited[i][j] = true;
    if (i + 2 < 8 && j + 2 < 8 &&
        i + 2 >= 0 && j + 2 >= 0 &&
        !visited[i + 2][j + 2])
    {
        flood(i + 2, j + 2, visited);
    }

    if (i + 2 < 8 && j - 2 < 8 &&
        i + 2 >= 0 && j - 2 >= 0 &&
        !visited[i + 2][j - 2])
    {
        flood(i + 2, j - 2, visited);
    }

    if (i - 2 < 8 && j + 2 < 8 &&
        i - 2 >= 0 && j + 2 >= 0 &&
        !visited[i - 2][j + 2])
    {
        flood(i - 2, j + 2, visited);
    }

    if (i - 2 < 8 && j - 2 < 8 &&
        i - 2 >= 0 && j - 2 >= 0 &&
        !visited[i - 2][j - 2])
    {
        flood(i - 2, j - 2, visited);
    }
}

bool canTwoKingMeet(const vector<string>& v)
{
    int cntK = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (v[i][j] == 'K' && cntK == 0)
            {
                flood(i, j, visited1);
                cntK++;
            }
            else if (v[i][j] == 'K' && cntK == 1)
            {
                flood(i, j ,visited2);
		cntK++;
            }
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (visited1[i][j] == true && visited2[i][j] == true &&
                v[i][j] != '#')
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n = 0;
    cin >> n;
    vector<string> v(8);
    for (int i = 0; i < n; ++i)
    {
        for (int row = 0; row < 8; ++row)
        {
            cin >> v[row];
        }

        for (int ii = 0; ii < 8; ++ii)
        {
            for (int jj = 0; jj < 8; ++jj)
            {
                visited1[ii][jj] = false;
            }
        }

        for (int ii = 0; ii < 8; ++ii)
        {
            for (int jj = 0; jj < 8; ++jj)
            {
                visited2[ii][jj] = false;
            }
        }


        if (canTwoKingMeet(v))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
