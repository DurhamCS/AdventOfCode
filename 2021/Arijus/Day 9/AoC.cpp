#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

int BasinSearch(std::vector<std::string> &map, int i, int j) {
    int ans = 1;
    map[i][j] = 'x';
    if (map[i][j-1] != '9' && map[i][j-1] != 'x') {
        ans += BasinSearch(map, i, j-1);
    }        
    if (map[i-1][j] != '9' && map[i-1][j] != 'x') {
        ans += BasinSearch(map, i-1, j);
    }
        
    if (map[i][j+1] != '9' && map[i][j+1] != 'x') {
        ans += BasinSearch(map, i, j+1);
    }
        
    if (map[i+1][j] != '9' && map[i+1][j] != 'x') {
        ans += BasinSearch(map, i+1, j);
    }
        
    return ans;
}

int main() {
    std::vector<std::string> heatmap;
    std::vector<int> basins;
    int ans1 = 0;
    std::string str;
    std::ifstream fd("input.txt");
    while (getline(fd, str)) {
        str.push_back('9');
        str.insert(str.begin(),'9');
        heatmap.push_back(str);
    }
    int m = heatmap[0].size();
    str.clear();
    for (int i = 0; i < m; i++)
        str.push_back('9');
    heatmap.insert(heatmap.begin(), str);
    heatmap.push_back(str);
    int n = heatmap.size();
    
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            if (heatmap[i-1][j] > heatmap[i][j] && heatmap[i][j-1] > heatmap[i][j] && heatmap[i+1][j] > heatmap[i][j] && heatmap[i][j+1] > heatmap[i][j]) {
                ans1 += (heatmap[i][j]+1-'0');
                std::vector<std::string> copy = heatmap;
                basins.push_back(BasinSearch(copy, i, j));
            }
        }
    }
    std::make_heap(basins.begin(), basins.end());
    int ans2 = basins.front();
    std::pop_heap(basins.begin(), basins.end());
    basins.pop_back();
    ans2 *= basins.front();
    std::pop_heap(basins.begin(), basins.end());
    basins.pop_back();
    ans2 *= basins.front();
    std::cout <<"Star 1: " <<ans1 <<std::endl
              <<"Star 2: " <<ans2 <<std::endl;

}