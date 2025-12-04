#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
vector<pair<int, int>> toRemove;
int n;
int m;

int countNeighbors(int i, int j)
{
    int adjacent = 0;
    int dx[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int dy[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
    for (int k = 0; k < 8; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
        {
            if (grid[ni][nj] == '@')
            {
                adjacent++;
            }
            else
            {
                continue;
            }
        }
    }
    return adjacent;
}

int main()
{
    ifstream in ("U4.txt");
    string input;
    int accessible = 0, removed = 0;
    while (in >> input)
    {
        grid.push_back(input);
    }
    n = grid.size();
    m = grid[0].size();
    while (1 > 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '@')
                {
                    int neighbors = countNeighbors(i, j);
                    if (neighbors < 4)
                    {
                        accessible++;
                        toRemove.push_back(make_pair(i, j));
                    }
                }
            }
        }
        if (toRemove.empty())
        {
            break;
        }
        else
        {
            for (int k = 0; k < toRemove.size(); k++){
                int remi = toRemove[k].first;
                int remj = toRemove[k].second;
                grid[remi][remj] = '.';
            }
            removed += toRemove.size();
            toRemove.clear();
        }
    }
    cout << removed;
    return 0;
}
