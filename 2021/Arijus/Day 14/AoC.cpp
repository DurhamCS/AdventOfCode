#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

int main() 
{
    std::unordered_map<std::string,std::string> formula;
    std::unordered_map<std::string,long long int> count, ans;
    std::string poly, temp, key, value;
    std::ifstream fd("input.txt");
    getline(fd, poly);
    getline(fd, temp);
    while(getline(fd, temp))
    {
        std::stringstream ss(temp);
        int counter = 0;
        while(getline(ss, temp, ' '))
        {
            if (counter % 3 == 0) {
                key = temp;
            }
            else if (counter % 3 == 2) {
                value = temp;
            }
            counter++;
        }
        formula[key] = value;
        count[key] = 0;
        ans[value] = 0;
    }
    
    int n = poly.size();
    for (int i = 0; i < n-1; i++) 
        count[poly.substr(i,2)]++;
    
    for (int i = 0; i < n; i++)
    {
        temp = "";
        temp.push_back(poly[i]);
        ans[temp]++;
    }
        
    int iterations = 10;
    for (int i = 0; i < iterations; i++)
    {
        std::unordered_map<std::string, long long int> copyCount = count;
        for (std::unordered_map<std::string, long long int>::iterator it = count.begin(); it != count.end(); it++)
        {
            std::string current = it->first;
            std::string left = current.substr(0,1) + formula[current];
            std::string right = formula[current] + current.substr(1,1);
            ans[formula[current]] += it->second;
            copyCount[left] += it->second;
            copyCount[right] += it->second;
            copyCount[current] -= it->second;
        }
        count = copyCount;
    }

    long long int mini = std::pow(2, 63)-1, maxi = 0;
    for (std::unordered_map<std::string, long long int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        mini = std::min(mini, it->second);
        maxi = std::max(maxi, it->second);
    }

    std::cout <<"Star 1: " <<maxi - mini <<std::endl;

    iterations = 30;
    for (int i = 0; i < iterations; i++)
    {
        std::unordered_map<std::string, long long int> copyCount = count;
        for (std::unordered_map<std::string, long long int>::iterator it = count.begin(); it != count.end(); it++)
        {
            std::string current = it->first;
            std::string left = current.substr(0,1) + formula[current];
            std::string right = formula[current] + current.substr(1,1);
            ans[formula[current]] += it->second;
            copyCount[left] += it->second;
            copyCount[right] += it->second;
            copyCount[current] -= it->second;
        }
        count = copyCount;
    }

    mini = std::pow(2, 63)-1, maxi = 0;
    for (std::unordered_map<std::string, long long int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        mini = std::min(mini, it->second);
        maxi = std::max(maxi, it->second);
    }

    std::cout <<"Star 2: " <<maxi - mini <<std::endl;
    return 0;     
}