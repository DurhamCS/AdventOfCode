#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <tuple>
#include <algorithm>


class Bingo {
public:
    int board[5][5];
    void markDrawn(int number);
    int getScore();
    bool hasWon();

private:
    int lastDrawn;
};
bool Bingo::hasWon() {
    int count;
    for (int i = 0; i < 5; i++) {
        count = 0;
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != -1)
                break;
            count++;
        }
        if (count == 5)
            return true;
    }
    for (int i = 0; i < 5; i++) {
        count = 0;
        for (int j = 0; j < 5; j++) {
            if (board[j][i] != -1)
                break;
            count++;
        }
        if (count == 5)
            return true;
    }
    return false;
}
int Bingo::getScore() {
    int sum = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (board[i][j] != -1)
                sum += board[i][j];

    return sum * lastDrawn;
}
void Bingo::markDrawn(int number) {
    lastDrawn = number;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (board[i][j] == number)
                board[i][j] = -1;
}


auto parse_input(std::string s) {
    std::vector<int> random_numbers;
    std::string random_nums_str, temp;
    std::ifstream File(s);
    File >> random_nums_str;
    std::stringstream ss(random_nums_str);
    while (std::getline(ss, temp, ','))
        random_numbers.push_back(std::stoi(temp));

    std::vector<Bingo> bingo_boards;
    while (File) {
        Bingo bingo_board;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                File >> bingo_board.board[i][j];
        bingo_boards.push_back(bingo_board);
    }

    std::reverse(random_numbers.begin(), random_numbers.end());
    return std::make_pair(bingo_boards, random_numbers);
}

int part_one() {
    std::vector<int> random_numbers;
    std::vector<Bingo> bingo_boards;
    std::tie(bingo_boards, random_numbers) = parse_input("input.txt");

    int n = random_numbers.size();
    int m = bingo_boards.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bingo_boards[j].markDrawn(random_numbers.back());
            if (i < 4)
                continue;

            if (bingo_boards[j].hasWon())
                return bingo_boards[j].getScore();
        }
        random_numbers.pop_back();
    }
    return -1;
}

int part_two() {
    std::vector<int> random_numbers;
    std::vector<Bingo> bingo_boards;
    std::tie(bingo_boards, random_numbers) = parse_input("input.txt");

    int n = random_numbers.size();
    int m = bingo_boards.size();
    for (int i = 0; (i < n) && (1 < m); i++) {
        m = bingo_boards.size();
        for (int j = m-1; 0 <= j; j--) {
            bingo_boards[j].markDrawn(random_numbers.back());
            if (i < 4)
                continue;

            if (bingo_boards[j].hasWon())
                bingo_boards.erase(bingo_boards.begin() + j);
        }
        random_numbers.pop_back();
    }
    while (!bingo_boards[0].hasWon()) {
        bingo_boards[0].markDrawn(random_numbers.back());
        random_numbers.pop_back();
    }
    return bingo_boards[0].getScore();
}

int main() {
    std::cout << part_one() << std::endl
              << part_two() << std::endl;
    return 0;
}
