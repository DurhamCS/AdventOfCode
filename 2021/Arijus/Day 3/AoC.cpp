#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>

int count(int n, std::vector<std::string> &str, int bit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i][bit] == '1') count++;
        else count--;
    }
    return count;
}

int main (){
    std::string number;
    std::ifstream fd("input.txt");
    
    std::vector<std::string> oxy, co;

    while (fd >> number) {
        oxy.push_back(number);
        co.push_back(number);
    }

    int n = number.size();
    int m = oxy.size();

    int gamma = 0, epsilon = 0;
    for (int i = 0; i < n; i++) {
        if (count(m, oxy, i) > 0) gamma += pow(2, n-1-i);
        else epsilon += pow(2, n-1-i);
    }

    for (int i = 0; i < n; i++) {
        int m = oxy.size();
        int currCount = count(m, oxy, i);

        for (int j = 0; j < m; j++) {
            if (oxy.size() == 1) {
                i = n;
                break;
            }
            if (currCount >= 0){
                if (oxy[j][i] == '0') {
                    oxy.erase(oxy.begin()+j);
                    j--;
                    m--;
                }
            }
            else {
                if (oxy[j][i] == '1') {
                    oxy.erase(oxy.begin()+j);
                    j--;
                    m--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int m = co.size();
        int currCount = count(m, co, i);

        for (int j = 0; j < m; j++) {
            if (co.size() == 1) {
                i = n;
                break;
            }

            if (currCount < 0){
                if (co[j][i] == '0') {
                    co.erase(co.begin()+j);
                    j--;
                    m--;
                }
            }
            else {
                if (co[j][i] == '1') {
                    co.erase(co.begin()+j);
                    j--;
                    m--;
                }
            }
        }
    }

    int oxygen = 0, co2 = 0;
    for (int i = 0; i < n; i++) {
        if (oxy[0][i] == '1') oxygen += pow(2, n-1-i);
        if (co[0][i] == '1') co2 += pow(2, n-1-i);
    }
    

    std::cout <<"Star 1: " <<gamma * epsilon <<std::endl
              <<"Star 2: " <<oxygen * co2<<std::endl;
}