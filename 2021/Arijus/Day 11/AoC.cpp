#include <iostream>
#include <fstream>
#include <vector>

int ans1 = 0;

void Blink(std::vector<std::string> &grid, int i, int j, int &count) {
    int directions[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    count++;
    ans1++;
    grid[i][j] = '0';
    for (int k = 0; k < 8; k++) 
    {
        if (grid[i+directions[k][0]][j+directions[k][1]] != 'x' && grid[i+directions[k][0]][j+directions[k][1]] != '0' && grid[i+directions[k][0]][j+directions[k][1]]-'0' != 10)
        {
            grid[i+directions[k][0]][j+directions[k][1]]++;
            if (grid[i+directions[k][0]][j+directions[k][1]]-'0' == 10) {
                Blink(grid, i+directions[k][0], j+directions[k][1], count);
            }
        }
    }
}

int main() {
    std::vector<std::string> grid;
    std::ifstream fd("input.txt");
    std::string padding = "xxxxxxxxxxxx";
    grid.push_back(padding);
    for (int i = 0; i < 10; i++)
    {
        std::string temp;
        fd >> temp;
        temp.push_back('x');
        temp.insert(0, 1, 'x');
        grid.push_back(temp);
    }
    grid.push_back(padding);
    int ans2 = 0;
    std::vector<std::string> newGrid;
    newGrid = grid;
    int days = 100;
    for (int i = 0; i < days; i++) 
    {        
        for (int j = 1; j < 11; j++) 
        {
            for (int k = 1; k < 11; k++)
            {
                grid[j][k]++;
            }
        }
        int count = 0;
        for (int j = 1; j < 11; j++) 
        {
            for (int k = 1; k < 11; k++)
            {
                if (grid[j][k]-'0' == 10)
                {
                    Blink(grid, j, k, count);
                }
            }
        }
    }
    std::cout <<ans1 <<std::endl;
    while(true)
    {
        ans2++;
        for (int j = 1; j < 11; j++) 
        {
            for (int k = 1; k < 11; k++)
            {
                newGrid[j][k]++;
            }
        }
        int count = 0;
        for (int j = 1; j < 11; j++) 
        {
            for (int k = 1; k < 11; k++)
            {
                if (newGrid[j][k]-'0' == 10)
                {
                    Blink(newGrid, j, k, count);
                }
            }
        }
        if (count == 100)
            break;
    }
    
    std::cout <<ans2 <<std::endl;
}