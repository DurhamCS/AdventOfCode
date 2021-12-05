#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <sstream>
#include <unordered_set>
using namespace std;

#define SIZE 5
typedef unordered_map<int, pair<int, int>> board;
typedef vector<board> boards;

// class Board {
//     public:
//     boardmap board;
//     int rowCount[SIZE];
//     int colCount[SIZE];
//     Board(boardmap board)
// }

vector<int> split(string s, char delim)
{
    stringstream ss(s);
    vector<int> result;
    string substr;
    while (1)
    {
        getline(ss, substr, delim);
        if(substr == "") continue;
        result.push_back(stoi(substr));
        if(!ss.good()) return result;
    }
}

boards get_boards(ifstream* input)
{
    boards boards;
    string line;
    while(getline(*input, line))
    {
        board board;
        for (int i = 0; i < SIZE; i++)
        {
            getline(*input, line);
            vector<int> row = split(line, ' ');
            for (int j = 0; j < SIZE; j++)
                board[row[j]] = make_pair(i, j);
        }
        boards.push_back(board);
    }
    return boards;
}

int main()
{
    ifstream input("day4input.txt");
    string line;
    getline(input, line);
    vector<int> numbers = split(line, ',');

    boards boards = get_boards(&input);
    int num_boards = boards.size();
    int rowCount[num_boards][SIZE];
    int colCount[num_boards][SIZE];

    for(int i=0; i<num_boards; i++){
        for(int j=0; j<SIZE; j++){
            rowCount[i][j] = SIZE;
            colCount[i][j] = SIZE;
        }
    }
    unordered_set<int> removed; // indexes of removed items
    for (const auto &num : numbers)
    {
        for (int i = 0;i<boards.size(); i++)
        {
            if (removed.count(i) || !boards[i].count(num))
                continue;    
            pair<int, int> pos  = boards[i][num];
            boards[i][num] = make_pair(-1, -1);
            int r = --rowCount[i][pos.first];
            int c = --colCount[i][pos.second];
            if (r == 0 || c == 0)
            {
                int unmarked_sum = 0;
                for (auto kv : boards[i])
                    if (kv.second != make_pair(-1, -1)) 
                        unmarked_sum += kv.first;
                removed.insert(i);
                cout << unmarked_sum * num << '\n';
                if(removed.size() == boards.size()) return 0;
            }
        }
    }
    return 0;
}
