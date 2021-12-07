#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<algorithm>
#include <numeric>

using namespace std;
typedef unsigned long long ull;

ull f(vector<int> fishes, int days){
    ull counts[9] = {0};
    for(const auto &fish: fishes) counts[fish] += 1;
    for(int d = 0; d<days; d++){
        ull temp = counts[0];
        for(int t = 0; t<8; t++) counts[t] = counts[t+1];
        counts[6] += temp;
        counts[8] = temp;
    }
    return accumulate(counts, counts + 9, 0LL, plus<ull>());
}

int main(){
    ifstream input("day6input.txt");
    string t;
    vector<int> fishes;
    while (getline(input, t, ',')) fishes.push_back(stoi(t));
    cout << f(fishes, 80) << '\n';
    cout << f(fishes, 256) << '\n';
}
