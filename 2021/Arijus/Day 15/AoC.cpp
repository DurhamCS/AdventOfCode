#include <iostream>
#include <fstream>
#include <vector>

#define dirx i+directions[k][0]
#define diry j+directions[k][1]

void Dijkstra(std::vector<std::string> &grid, std::vector<std::vector<int>> &dist, int i, int j, int n)
{
    int directions[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    int mini = 2147483647;
    
    if (grid[i][j] != '0')
        mini = dist[i][j];

    for (int k = 1; k < n-1;  k++)
    {
        for (int p = 1; p < n-1; p++)
        {
            if (grid[k][p] != '0' && dist[k][p] < mini)
            {
                mini = dist[k][p];
                i = k;
                j = p;
            }
        }
    }
    grid[i][j] = '0';
    for (int k = 0; k < 4; k++)
    {
        if (dist[dirx][diry] != -1 && grid[dirx][diry] != '0')
        {
            int alt = mini + grid[dirx][diry]-'0';
            if (alt < dist[dirx][diry])
                dist[dirx][diry] = alt;
        }
    }
}

std::string Enlargen(std::string &line)
{
    std::string ans = line + line + line + line + line;
    int n = ans.size(), m = n/5;
    for (int i = m; i < n; i++)
    {
        ans[i] = ans[i-m]+1;
        if (ans[i] - '0' > 9)
        {
            ans[i] = '1';
        }
    }
    return ans;
}

void GridEnlargen(std::vector<std::string> &grid, std::vector<std::vector<int>> &dist)
{
    int n = grid[0].size();
    int m = grid.size();

    std::string temp;
    std::vector<int> unvi;

    for (int i = m; i < n-2; i++)
    {
        grid.push_back(grid[i-m]);
        dist.push_back(dist[0]);
        for (int j = 1; j < n-1; j++)
        {
            grid[i][j]++;
            if (grid[i][j] - '0' > 9)
            {
               grid[i][j] = '1';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        temp.push_back('9');
        unvi.push_back(-1);
    }
    grid.insert(grid.begin(),temp);
    grid.push_back(temp);
    dist.insert(dist.begin(),unvi);
    dist.push_back(unvi);
}

int main()
{
    std::vector<std::string> grid, bigGrid;
    std::vector<std::vector<int>> dist, bigDist;
    std::string temp, temp2;
    std::vector<int> unvi;
    std::ifstream fd("input.txt");
    int n;
    while(getline(fd, temp))
    {
        temp2 = Enlargen(temp);
        temp.insert(0,1,'9');
        temp.push_back('9');
        temp2.insert(0,1,'9');
        temp2.push_back('9');
        grid.push_back(temp);
        bigGrid.push_back(temp2);

        n = temp.size();
        unvi.clear();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n-1)
                unvi.push_back(-1);
            else
                unvi.push_back(2147483647);
        }
        dist.push_back(unvi);

        n = temp2.size();
        unvi.clear();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n-1)
                unvi.push_back(-1);
            else
                unvi.push_back(2147483647);
        }
        bigDist.push_back(unvi);
    }
    GridEnlargen(bigGrid, bigDist);

    temp = "";
    unvi.clear();
    for (int i = 0; i < n; i++)
    {
        temp.push_back('9');
        unvi.push_back(-1);
    }
    grid.insert(grid.begin(),temp);
    grid.push_back(temp);
    dist.insert(dist.begin(),unvi);
    dist.push_back(unvi);

    n = grid.size();
    dist[1][1] = 0;
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < n-1; j++)
        {
            Dijkstra(grid, dist, i, j, n);
        }
    }
    std::cout <<"Star 1: " <<dist[n-2][n-2] <<std::endl;

    n = bigGrid.size();

    bigDist[1][1] = 0;
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < n-1; j++)
        {
            Dijkstra(bigGrid, bigDist, i, j, n);
        }
    }
    std::cout <<"Star 2: " <<bigDist[n-2][n-2] <<std::endl;
}