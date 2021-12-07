#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iomanip>

long double count_fish(int days, int fish, std::unordered_map<int, long double> &memo) {
    //count children
    //count children's children
    long double ans = 0;
    int m = days-fish;
    if (m < 0) return 0;
    ans += m/7+1;
    for (int i = 0; i < m/7; i++) {
        if ( memo.find(fish+i*7+9) == memo.end() ) {
            ans += count_fish(days, fish+i*7+9, memo);
        } else {
            ans += memo[fish+i*7+9];
        }
    }
    memo[fish] = ans;
    return ans;
}

int main() {
    std::vector<int> fish;
    std::ifstream fd("input.txt");
    std::unordered_map<int, long double> memo;
    std::string str;
    getline(fd, str);
    std::stringstream ss(str);
    while (getline(ss, str, ',')) fish.push_back(stoi(str)+1);
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