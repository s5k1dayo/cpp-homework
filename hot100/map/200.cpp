#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //,先暴力找一个1,再深度优先遍历（函数递归，其实没有归，一直递出去把所有相邻1变为0）,找上下左右所有相邻的1（边界检验）,再全抹除;
    void find(int x, int y, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> que;
        que.push({x, y});
        pair<int, int> cur;
        while (!que.empty())
        {
            cur = que.front();
            que.pop();
            char curnum = grid[cur.first][cur.second];

            
            if (cur.first + 1 < grid.size() && grid[cur.first + 1][cur.second]=='1')
            {
                que.push({cur.first + 1, cur.second});
                grid[cur.first + 1][cur.second]='0';
            }
            if (cur.second + 1 < grid[0].size() && grid[cur.first][cur.second+1]=='1')
            {
                que.push({cur.first, cur.second + 1});
                grid[cur.first][cur.second+1]='0';
            }
            if (cur.first - 1 >= 0 && grid[cur.first - 1][cur.second]=='1')
            {
                que.push({cur.first - 1, cur.second});
                grid[cur.first - 1][cur.second]='0';
            }
            if (cur.second - 1 >= 0 && grid[cur.first][cur.second-1]=='1')
            {
                que.push({cur.first, cur.second - 1});
                grid[cur.first][cur.second-1]='0';
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    find(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
};
