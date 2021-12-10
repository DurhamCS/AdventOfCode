#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::unordered_map<char, char> brackets {
    {'{', '}'},
    {'(', ')'},
    {'[', ']'},
    {'<', '>'}
};

enum backBr {curly = '}', square = ']', roun = ')', angled = '>'};

int Corrupted(const char &c)
{
    if (c == curly)
        return 1197;
    if (c == square)
        return 57;
    if (c == roun)
        return 3;
    return 25137;
}

int Incomplete(const char &c) {
    if (c == curly)
        return 3;
    if (c == square)
        return 2;
    if (c == roun)
        return 1;
    return 4;
}

int main() {
    std::string line;
    std::ifstream fd("input.txt");
    unsigned int ans1 = 0;
    long long int ans2 = 0;
    std::vector<long long int> scores;
    while(getline(fd, line))
    {
        bool corrupted = false;
        std::string stack = "";
        int n = line.size();
        for (int i = 0; i < n; i++) 
        {
            if (line[i] == '{' || line[i] == '(' || line[i] == '[' || line[i] == '<')
            {
                stack.push_back(brackets[line[i]]);
            }
            else 
            {
                if (stack.back() != line[i])
                {
                    ans1 += Corrupted(line[i]);
                    corrupted = true;
                    break;
                }
                else 
                {
                    stack.pop_back();
                }
            }
        }
        if (!corrupted)
        {
            long long int score = 0;
            while (stack != "") 
            {
                score = score * 5 + Incomplete(stack.back());
                stack.pop_back();
            }
            scores.push_back(score);
        }
    }
    sort(scores.begin(), scores.end());
    ans2 = scores[scores.size()/2];
    std::cout <<"Star 1: " <<ans1 <<std::endl
              <<"Star 1: " <<ans2 <<std::endl;
}