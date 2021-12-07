#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<algorithm>

using namespace std;
typedef unsigned long long ull;

ull f(vector<int> fishes, int days){
    ull counts[9] = {0};
    ull counts_temp[9];
    for(const auto &fish: fishes) counts[fish] += 1;

    for(int d = 0; d<days; d++){
        copy(begin(counts),end(counts), begin(counts_temp));
        for(int t = 0; t<9; t++){
            ull v = counts[t];
            counts_temp[t] -= v;
            if(t==0){
                counts_temp[6] += v;
                counts_temp[8] += v;
            }else counts_temp[t - 1] += v;
        }
        copy(begin(counts_temp),end(counts_temp), begin(counts));
    }
    ull sum = 0;
    for(const auto &t: counts) sum += t;
    return sum;

}

int main(){
    ifstream input("day6input.txt");
    string t;
    vector<int> fishes;
    while (getline(input, t, ',')) fishes.push_back(stoi(t));

    cout << f(fishes, 80) << '\n';
    cout << f(fishes, 256) << '\n';
}   
