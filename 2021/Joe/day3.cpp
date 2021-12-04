#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ifstream input("day3input.txt");
    vector<string> lines;
    string line;
    while (getline(input, line))
        lines.push_back(line);

    // Question One
    int count[12] = {0};
    int g = 0;

    for (const auto &line : lines) for (int i = 0; i < 12; i++) count[i] += line[i] == '1' ? 1 : -1;
    for (int i = 0; i < 12; i++) g = (g << 1) + (count[i] > 0);
    cout << g * (g ^ 4095) << '\n';

    // Question Two
    int rating = 1;
    string last = "";
    unordered_set<int> removed; // indexes of removed items
    for (int type = 0; type < 2; type++)
    {
        for (int i = 0; i < 12; i++)
        {
            // set filter to most common bit if type = 0, or least common bit if type = 1
            int count = 0;
            for (int j = 0; j<lines.size(); j++) if(!removed.count(j)) count += lines[j][i] == '1' ? 1 : -1; 

            //remove elements if they don't match filter
            int filter = (type ? count < 0 : count >= 0) ? '1' : '0';
            for (int j = 0; j<lines.size(); j++){
                if(removed.count(j)) continue;
                if (lines[j][i] != filter) removed.insert(j); else last=lines[j];
            }
            if (removed.size() == lines.size() -1) break;
        }
        rating *= stoi(last, nullptr, 2);
        removed.clear();
    }
    cout << rating << '\n';
    return 0;
}
