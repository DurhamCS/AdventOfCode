#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void questionOne(ifstream* file){
    string line;
    int curr, count = 0;
    int prev = 10000;

    while(getline(*file, line)){
        curr = stoi(line);
        if(curr > prev) count++;
        prev = curr;
    }
    cout << count << '\n'; 
}

int getint(ifstream* file){
    string line;
    getline(*file, line);
    return stoi(line);
}

void questionTwo(ifstream* file){
    string line;

    int left,middle, right, count, prevSum, currSum = 0;
    left = getint(file);
    middle = getint(file);
    right = getint(file);
    prevSum = currSum = left+middle+right;

    while(getline(*file, line)){
        currSum -= left;
        left = middle;
        middle = right;
        right = stoi(line);
        currSum += right;
        
        if(currSum > prevSum) count++;
        prevSum = currSum;
    }
    cout << count << '\n'; 
}

int main() {
    ifstream day1input("day1input.txt");
    questionOne(&day1input);
    day1input.clear();
    day1input.seekg(0, ios::beg);
    questionTwo(&day1input);
    day1input.close();
}
