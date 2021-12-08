#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream fd("input.txt");
    std::string temp, str, temp2;
    std::vector<int> x1,y1,x2,y2;
    int maxx = 0, maxy = 0;
    while(getline(fd, str)) {
        std::stringstream ss(str);
        int counter = 0;
        while(getline(ss,temp, ',')) {
            std::stringstream stream(temp);
            if (counter == 0) {
                x1.push_back(std::stoi(temp));
                if (maxx < std::stoi(temp)) maxx = std::stoi(temp);
            }
            if (counter == 2) {
                y2.push_back(std::stoi(temp));
                if (maxy < std::stoi(temp)) maxy = std::stoi(temp);
            }
            if (counter == 1) {
                getline(stream,temp2, ' ');
                std::stringstream sss(temp2);
                y1.push_back(std::stoi(temp2));
                if (maxy < std::stoi(temp2)) maxy = std::stoi(temp2);
                getline(stream,temp2, ' ');
                getline(stream,temp2, ' ');
                x2.push_back(std::stoi(temp2));
                if (maxx < std::stoi(temp2)) maxx = std::stoi(temp2);
            }
            
            counter++;
        };
    }
    maxx++;
    maxy++;
    int n = x1.size();
    
    std::vector<std::vector<int>> grid;
    for (int x = 0; x < maxx; x++) {
        std::vector<int> row;
        for (int y = 0; y < maxy; y++) {
            row.push_back(0);
        }
        grid.push_back(row);
    }
    for (int i = 0; i < n; i++) {
        if (x1[i] == x2[i] || y1[i] == y2[i]) {
            if (x1[i] == x2[i] && y1[i] <= y2[i]) {
                for (int y = y1[i]; y <= y2[i]; y++) {
                    grid[x1[i]][y]++;
                }
            }
            else if (x1[i] >= x2[i] && y1[i] == y2[i]) {
                for (int x = x2[i]; x <= x1[i]; x++) {
                    grid[x][y1[i]]++;
                }
            }
            else if (x1[i] == x2[i] && y1[i] >= y2[i]) {
                for (int y = y2[i]; y <= y1[i]; y++) {
                    grid[x1[i]][y]++;
                }
            }
            else {
                for (int x = x1[i]; x <= x2[i]; x++) {
                    grid[x][y1[i]]++;
                }
            }
        }
    }
    int ans1 = 0;
    for (int x = 0; x < maxx; x++) {
        for (int y = 0; y < maxy; y++) {
            if (grid[x][y] > 1) ans1++;
        }
    }
    std::cout <<"Star 1: " <<ans1 <<std::endl;

    grid.clear();
    for (int x = 0; x < maxx; x++) {
        std::vector<int> row;
        for (int y = 0; y < maxy; y++) {
            row.push_back(0);
        }
        grid.push_back(row);
    }
    for (int i = 0; i < n; i++) {
        if (x1[i] == x2[i] || y1[i] == y2[i] || std::abs(x1[i] - x2[i]) == std::abs(y1[i]-y2[i])) {
            if (x1[i] == x2[i] && y1[i] <= y2[i]) {
                for (int y = y1[i]; y <= y2[i]; y++) {
                    grid[x1[i]][y]++;
                }
            }
            else if (x1[i] >= x2[i] && y1[i] == y2[i]) {
                for (int x = x2[i]; x <= x1[i]; x++) {
                    grid[x][y1[i]]++;
                }
            }
            else if (x1[i] == x2[i] && y1[i] >= y2[i]) {
                for (int y = y2[i]; y <= y1[i]; y++) {
                    grid[x1[i]][y]++;
                }
            }
            else if (x1[i] <= x2[i] && y1[i] == y2[i]) {
                for (int x = x1[i]; x <= x2[i]; x++) {
                    grid[x][y1[i]]++;
                }
            }
            else {
                int x = x1[i], y = y1[i];
                if (x1[i] >= x2[i] && y1[i] >= y2[i]) {
                    while(x2[i] != x) {
                        grid[x][y]++;
                        x--;
                        y--;
                    }
                }
                if (x1[i] >= x2[i] && y1[i] <= y2[i]) {
                    while(x2[i] != x) {
                        grid[x][y]++;
                        x--;
                        y++;
                    }
                }
                if (x1[i] <= x2[i] && y1[i] <= y2[i]) {
                    while(x2[i] != x) {
                        grid[x][y]++;
                        x++;
                        y++;
                    }
                }
                else {
                    while(x2[i] != x) {
                        grid[x][y]++;
                        x++;
                        y--;
                    }
                }
                grid[x][y]++;
            }
        }
    }
    int ans2 = 0;
    for (int x = 0; x < maxy; x++) {
        for (int y = 0; y < maxx; y++) {
            if (grid[x][y] > 1) ans2++;
        }
    }
    std::cout <<"Star 2: " <<ans2 <<std::endl;
}
