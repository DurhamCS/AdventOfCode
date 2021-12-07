#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

int main () {
    std::vector<int> pos;
    std::string str;
    std::ifstream fd("input.txt");
    getline(fd, str);
    std::stringstream ss(str);
    while (getline(ss, str, ',')) pos.push_back(stoi(str));

    std::sort(pos.begin(), pos.end());
    int n = pos.size();
    int med = pos[n/2];
    int ans1 = 0;
    long long int ans2 = 0;
    double e = 0;

    for (int i = 0; i < n; i++) {
        ans1 += abs(pos[i]-med);
        e += pos[i];
    }
    e = std::trunc(e/n);

    for (int i = 0; i < n; i++) {
        ans2 += (abs(e-pos[i])+1)*abs(e-pos[i])/2;
        // std::cout <<ans2 <<std::endl;
    }

    std::cout <<"Star 1: "<<ans1 <<std::endl
              <<"Star 2: "<<ans2 <<std::endl;
}