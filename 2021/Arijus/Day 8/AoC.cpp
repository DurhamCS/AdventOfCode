#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

char operator-(std::string &a, std::string &b) {
    int a_size = a.size(), b_size = b.size();
    bool exists = false;
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < b_size; j++) {
            if (b[j] == a[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) return a[i];
        exists = false;
    }
    return 0;
}

std::string subtract(std::string &a, std::string &b) {
    std::string ans = "";
    int a_size = a.size(), b_size = b.size();
    bool exists = false;
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < b_size; j++) {
            if (b[j] == a[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) ans.push_back(a[i]);
        exists = false;
    }
    return ans;
}

char operator-(std::string &a, char &b) {
    int a_size = a.size();
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b) return a[i];
    }
    return 0;
}

bool check(char letter, std::string &word) {
    int n = word.size();
    for (int i = 0; i < n; i++) {
        if (letter == word[i]) return true;
    }
    return false;
}

int convert(std::string number) {
    if (number == "012345") return 0;
    if (number == "12") return 1;
    if (number == "01346") return 2;
    if (number == "01236") return 3;
    if (number == "1256") return 4;
    if (number == "02356") return 5;
    if (number == "023456") return 6;
    if (number == "012") return 7;
    if (number == "0123456") return 8;
    if (number == "012356") return 9;
    return -1;
}

int decode(char segments[], std::vector<std::string> display) {
    std::unordered_map<char, char> decode;
    std::string number = "";
    int digit[4];
    for (int i = 0; i < 7; i++) {
        decode[segments[i]] = i+'0';
    }

    for (int i = 0; i < 4; i++) {
        int n = display[i].size();
        for (int j = 0; j < n; j++) {
            number.push_back(decode[display[i][j]]);
        }
        std::sort(number.begin(), number.end());
        digit[i] = convert(number);
        number.clear();
    }
    return digit[0] * 1000 + digit[1] * 100 + digit[2] * 10 + digit[3];
}

int main() {
    std::string str;
    std::vector<std::string> digits;
    std::vector<std::string> display;
    std::ifstream fd("input.txt");
    int counter = 0, ans1 = 0, ans2 = 0;
    while(getline(fd, str)) {
        std::stringstream ss(str);
        while(getline(ss, str, ' ')) {
            if (counter < 10) digits.push_back(str);
            if (counter > 10) {
                if (str.size() == 7 || str.size() == 2 || str.size() == 3 || str.size() == 4) ans1++;
                display.push_back(str);
            }
            counter++;
        }
        counter = 0;

        std::sort(digits.begin(), digits.end(), [] (std::string a, std::string b) {return a.length() < b.length(); });
        char position[8];
        int numbers[10];

        for (int i = 0; i < 10; i++) numbers[i] = -1;

        /*
        7 segment positions: 
            0 - 0 and 1 and 2 and 3 and 4 and 5;
            1 - 1 and 2;
            2 - 0 and 1 and 3 and 4 and 6;
            3 - 0 and 1 and 2 abd 3 and 6;
            4 - 1 and 2 and 5 and 6;
            5 - 0 and 2 and 3 and 5 and 6;
            6 - 0 and 2 and 3 and 4 and 5 and 6;
            7 - 0 and 1 and 2;
            8 - 0 and 1 and 2 and 3 and 4 and 5 and 6;
            9 - 0 and 1 and 2 and 3 and 5 and 6; 

            7 - 1 = 0th position
            8 - 6 = 1th position (check against 7)
            8 - 0 = 6
            8 - 9 = 4
            8 - 6 = 1
            => 2th position (from 1)
            8 - 0 = 6th position (check against 4)
            => 5th position (from 4)
            => 3rd position (from 9)
            => 4th position (from 0)
        */

        position[0] = digits[1] - digits[0];

        if (check(digits[9] - digits[8], digits[1])) {
            position[1] = digits[9] - digits[8];
            numbers[8] = 6;
        }
        else if (check(digits[9] - digits[7], digits[1])) {
            position[1] = digits[9] - digits[7];
            numbers[7] = 6;
        }
        else {
            position[1] = digits[9] - digits[6];
            numbers[6] = 6;
        }

        position[2] = digits[0] - position[1];

        std::string mod_4 = "";
        mod_4.push_back(position[1]);
        mod_4 = subtract(digits[2], mod_4);
        if (check(digits[9] - digits[8], mod_4)) {
            position[6] = digits[9] - digits[8];
            numbers[8] = 0;
        }
        else if (check(digits[9] - digits[7], mod_4)) {
            position[6] = digits[9] - digits[7];
            numbers[7] = 0;
        }
        else {
            position[6] = digits[9] - digits[6];
            numbers[6] = 0;
        }

        if (numbers[6] == -1) numbers[6] = 9;
        if (numbers[7] == -1) numbers[7] = 9;
        if (numbers[8] == -1) numbers[8] = 9;

        std::string inter = subtract(digits[2], digits[0]);
        position[5] = inter - position[6];

        std::string temp = "";
        temp.push_back(position[5]);
        temp.push_back(position[6]);
        if (numbers[6] == 9) {
            std::string inter = subtract(digits[6], digits[1]);
            position[3] = inter - temp;
        }
        if (numbers[7] == 9) {
            std::string inter = subtract(digits[7], digits[1]);
            position[3] = inter - temp;
        }
        if (numbers[8] == 9) {
            std::string inter = subtract(digits[8], digits[1]);
            position[3] = inter - temp;
        }

        if (numbers[6] == 9) {
            position[4] = digits[9] - digits[6];
        }
        if (numbers[7] == 9) {
            position[4] = digits[9] - digits[7];
        }
        if (numbers[8] == 9) {
            position[4] = digits[9] - digits[8];
        }
        
        ans2 += decode(position, display);

        digits.clear();
        display.clear();
    }
    std::cout <<"Star 1: " <<ans1 <<std::endl
              <<"Star 2: " <<ans2 <<std::endl;
}