#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::string temp;
    std::vector<std::pair<std::string,int>> instruction;
    std::vector<std::vector<bool>> grid;
    std::vector<std::pair<int,int>> xy;
    std::ifstream fd("input.txt");
    int maxx = 0, maxy = 0;
    while(true) 
    {
        getline(fd, temp);
        if(temp == "")
            break;
        std::stringstream ss(temp);
        int counter = 0;
        int x,y;
        while (getline(ss, temp, ','))
        {
            if (counter%2 == 0)
                x = stoi(temp);
            else
                y = stoi(temp);
            counter++;
        }
        xy.push_back(std::make_pair(x, y));
        maxx = std::max(maxx, x);
        maxy = std::max(maxy, y);
    }
    maxx++;
    maxy++;
    for (int i = 0; i < maxx; i++) {
        std::vector<bool> row;
        for (int j = 0; j < maxy; j++) {
            row.push_back(0);
        }
        grid.push_back(row);
    }

    for (auto coord : xy) {
        grid[coord.first][coord.second] = true;
    }

    while(getline(fd, temp)) 
    {
        std::stringstream ss(temp);
        int counter = 0;
        std::string instr;
        while (getline(ss, temp, ' '))
        {
            counter++;
            if (counter%3 == 0) 
            {
                std::stringstream ss2(temp);
                std::string c, temp2;
                int number;
                int counter2 = 0;
                while (getline(ss2, temp2, '='))
                {
                    if (counter2%2 == 0)
                        c = temp2;
                    else
                        number = stoi(temp2);
                    counter2++; 
                }
                instruction.push_back(std::make_pair(c, number));
            }
        }
    }

    int n = instruction.size();

    for (int i = 0; i < n; i++)
    {
        int line = instruction[i].second;
        if (instruction[i].first == "x")
        {
            for (int j = 0; j < maxy; j++) {
                for (int k = line; k < maxx; k++) {
                    if (grid[k][j] && k-line >= 0) {
                        grid[line-(k-line)][j] = true;
                        grid[k][j] = false;
                    }
                }
            }
            maxx = line;
        }
        else
        {
            for (int j = line; j < maxy; j++) {
                for (int k = 0; k < maxx; k++) {
                    if (grid[k][j] && j-line >= 0) {
                        grid[k][line-(j-line)] = true;
                        grid[k][j] = false;
                    }
                }
            }
            maxy = line;
        }
        int counter = 0;
        for (int j = 0; j < maxy; j++) {
            for (int k = 0; k < maxx; k++) {
                if (grid[k][j])
                    counter++;
            }
        }
        if (i == 0)
            std::cout <<"Star 1: " <<counter <<std::endl;
    }

    std::cout <<"Star 2: " <<std::endl;
    for (int j = 0; j < maxy; j++) {
        for (int k = 0; k < maxx; k++) {
            if (grid[k][j])
                std::cout <<'#';
            else
                std::cout <<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}