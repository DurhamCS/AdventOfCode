#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main(){
    ifstream input("day7input.txt");
    string h;
    vector<int> pos;
    while (getline(input, h, ',')) pos.push_back(stoi(h));
    sort(pos.begin(), pos.end());
    int med = (pos[pos.size()/2]+pos[pos.size()/2-1])/2;
    int mean = accumulate(pos.begin(), pos.end(), 0)/pos.size();
    cout << accumulate(pos.begin(), pos.end(),0, [med](int x, int y){return x + abs(y-med);}) <<'\n';
    cout << accumulate(pos.begin(), pos.end(),0, [mean](double x, float y){ return x + abs(y-mean)/2*(1+abs(y-mean));});
}
