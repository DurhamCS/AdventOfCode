#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}

long double count_fish(int days, std::pair<int, int> fish, std::unordered_map<size_t, long double> &memo) {
    //count children
    //count children's children
    long double ans = 0;
    int m = days-fish.first-fish.second;
    if (m < 0) return 0;
    ans += m/7+1;
    for (int i = 0; i < m/7; i++) {
        if ( memo.find(key(9, fish.first+fish.second+i*7)) == memo.end() ) {
            ans += count_fish(days, std::make_pair(9, fish.first+fish.second+i*7), memo);
        } else {
            ans += memo[key(9, fish.first+fish.second+i*7)];
        }
    }
    memo[key(fish.first, fish.second)] = ans;
    return ans;
}

int main() {
    std::vector<std::pair<int,int>> fish;
    std::ifstream fd("input.txt");
    std::unordered_map<size_t, long double> memo;
    std::string str;
    getline(fd, str);
    std::stringstream ss(str);
    while (getline(ss, str, ',')) fish.push_back(std::make_pair(stoi(str)+1,0));
    int n = fish.size();
    long double ans1 = n, ans2 = n;
    int number_of_days1 = 80, number_of_days2 = 256;
    for (int i = 0; i < n; i++) {
        ans1 += count_fish(number_of_days1, fish[i], memo);
    }
    memo.clear();
    for (int i = 0; i < n; i++) {
        ans2 += count_fish(number_of_days2, fish[i], memo);
    }
    std::cout << std::fixed <<std::setprecision(0) 
              <<"Star 1: " <<ans1 <<std::endl
              <<"Star 2: " <<ans2 <<std::endl;
    fd.close();
    return 0;
}