#include <bits/stdc++.h>


int convert (std::string s) {
    int k;
    std::stringstream ss(s);
    ss >> k;
    return k;
}

int main() {
    std::ifstream fr("input.txt");

    std::string str, val;
    std::string temp;
    std::vector<std::string> directon;
    std::vector<int> value;
    int counter = 0;
    
    while (getline(fr, str)) {
        std::stringstream ss(str);
        counter = 0;
        while(getline(ss,temp, ' '))
        {
            std::stringstream stream(temp);
            if (counter % 2 == 0) directon.push_back(temp);
            else value.push_back(convert(temp));
            counter++;
        }
    }

    int n = directon.size();
    int depth1 = 0, depth2 = 0, horrizontal1 = 0, horrizontal2 = 0, aim = 0;


    for (int i = 0; i < n; i++) {
        if (directon[i] == "up") depth1 -= value[i];
        else if (directon[i] == "down") depth1 += value[i];
        else horrizontal1 += value[i];
    }

    for (int i = 0; i < n; i++) {
        if (directon[i] == "up") aim -= value[i];
        else if (directon[i] == "down") aim += value[i];
        else {
            horrizontal2 += value[i];
            depth2 += aim * value[i];
        }
    }

    std::cout <<"Star 1: " <<depth1*horrizontal1 <<std::endl
              <<"Star 2: " <<depth2*horrizontal2 <<std::endl;
}
