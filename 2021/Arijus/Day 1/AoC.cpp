#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> depths, newDepths;
    int temp, ans1 = 0, ans2 = 0;
    ifstream fd("input.txt");
    while (fd >> temp) depths.push_back(temp);

    int n = depths.size();

    for (int i = 1; i < n; i++) {
        if (depths[i] > depths[i-1]) ans1++;
    }

    for (int i = 0; i < n-2; i++) {
        newDepths.push_back(depths[i]+depths[i+1]+depths[i+2]);
    }

    for (int i = 1; i < newDepths.size(); i++) {
        if (newDepths[i] > newDepths[i-1]) ans2++;
    }

    cout <<"Star 1: "<<ans1 <<endl
         <<"Star 2: "<<ans2 <<endl;
    return 0;
}