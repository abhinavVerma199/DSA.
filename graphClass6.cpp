#include <bits/stdc++.h>
using namespace std;
// No of Provinces LC-547
class Solution
{
public:
    void dfs(int src, unordered_map<int, bool> &visited, int n, vector<vector<int>> &isConnected)
    {
        visited[src] = 1;
        int col = n;
        int row = src;
        for (int nbr = 0; nbr < col; nbr++)
        {
            int nb = nbr;
            if (src != nb && isConnected[row][nbr] == 1)
            {
                if (!visited[nb])
                {
                    dfs(nb, visited, n, isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_map<int, bool> visited;
        int n = isConnected.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, n, isConnected);
                count++;
            }
        }
        return count;
    }
};

// No of Islands LC-200
class Solution
{
public:
    bool isSafe(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1' && !vis[{i, j}])
            return true;
        return false;
    }

    void bfs(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[{i, j}] = true;
        while (!q.empty())
        {
            auto frontNode = q.front();
            q.pop();
            int tempX = frontNode.first;
            int tempY = frontNode.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++)
            {
                int newX = tempX + dx[k];
                int newY = tempY + dy[k];
                if (isSafe(newX, newY, grid, vis))
                {
                    q.push({newX, newY});
                    vis[{newX, newY}] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        map<pair<int, int>, bool> vis;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[{i, j}] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};

// Flood Fill LC-733
class Solution
{
public:
    bool isSafe(int i, int j, int oldColor, vector<vector<int>> &image, vector<vector<int>> &ans, map<pair<int, int>, bool> &vis)
    {
        if (i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && ans[i][j] == oldColor && !vis[{i, j}])
            return 1;
        return 0;
    }
    void dfs(int oldColor, int newColor, map<pair<int, int>, bool> &vis, vector<vector<int>> &ans,
             vector<vector<int>> &image, int sr, int sc)
    {
        vis[{sr, sc}] = 1;
        ans[sr][sc] = newColor;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            if (isSafe(newX, newY, oldColor, image, ans, vis))
            {
                dfs(oldColor, newColor, vis, ans, image, newX, newY);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        int newColor = color;
        if (oldColor == color)
        {
            return image;
        }
        map<pair<int, int>, bool> vis;
        dfs(oldColor, newColor, vis, ans, image, sr, sc);
        return ans;
    }
};

// Rootten Oranges LC-994
class Solution
{
public:
    bool isSafe(int x, int y, int n, int m)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<vector<int>> temp = grid;
        queue<pair<pair<int, int>, int>> q;
        int minTime = 0;
        int n = grid.size();
        int m = grid[0].size();

        // Find all rotten oranges and put them in the queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        // BFS logic
        while (!q.empty())
        {
            auto frontNode = q.front();
            q.pop();
            int tempX = frontNode.first.first;
            int tempY = frontNode.first.second;
            int frontTime = frontNode.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if (isSafe(newX, newY, n, m) && temp[newX][newY] == 1)
                {
                    q.push({{newX, newY}, frontTime + 1});
                    // Mark this orange as rotten
                    temp[newX][newY] = 2;
                    minTime = max(minTime, frontTime + 1);
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == 1)
                    return -1;
            }
        }

        return minTime;
    }
};

int main()
{

    return 0;
}