#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

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
    long long int ans2 = 922337203685477580;

    for (int i = 0; i < n; i++) {
        ans1 += abs(pos[i]-med);
    }

    for (int i = 0; i < pos[n-1]; i++) {
        long long int mini = 0;
        for (int j = 0; j < n; j++) {
            med = abs(pos[j]-i);
            mini += ((med+1)*med)/2;
        }
        if (ans2 > mini) {
            ans2 = mini;
        }
    }


    std::cout <<"Star 1: "<<ans1 <<std::endl
              <<"Star 2: "<<ans2 <<std::endl;
}