#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cmath>

int unmarked(std::vector<long long int> square) {
    int ans = 0;
    for (int i = 0; i < 25; i++) {
        if (square[i] != -1) ans += square[i];
    }
    return ans;
}

void mark_square(int rc, std::vector<long long int> &square, std::unordered_map<int, int> &primer, int key) {
    if (rc > 4) {
        for (int i = 0; i < 5; i++) {
            if (primer[square[5*i+rc-5]] == key) {
                square[5*i+rc-5] = -1;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            if (primer[square[5*rc+i]] == key) {
                square[5*rc+i] = -1;
                break;
            }
        }
    }
}

std::vector<int> find_primes_till_max(int max) {
    std::vector<int> ans;
    if (max == 1) ans.push_back(2);
    if (max == 2) {ans.push_back(2); ans.push_back(3); }
    if (max == 3) {ans.push_back(2); ans.push_back(3); ans.push_back(5);}
    if (max == 4) {ans.push_back(2); ans.push_back(3); ans.push_back(5); ans.push_back(7);}
    if (max == 5) {ans.push_back(2); ans.push_back(3); ans.push_back(5); ans.push_back(7); ans.push_back(11);}
    if (max >= 6) {
        int p = std::ceil(max*std::log(max)+max*std::log(std::log(max)));
        std::vector<int>nums;
        for (int i = 2; i < p; i++) {
            nums.push_back(i);
        }
        int n = nums.size();
        for (int i = 0; i < max; i++) {
            ans.push_back(nums[i]);
            for (int j = i+1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    nums.erase(nums.begin()+j);
                    j--;
                    n--;
                }
            }
        }
    }
    return ans;
}

void primeriser(std::unordered_map<int, int> &ans, std::vector<int> bingo, int max) {
    std::vector<int> primes = find_primes_till_max(max);
    for (int i = 0; i < max; i++) {
        ans[bingo[i]] = primes[i];
    }
}

int main() {
    int maxi = 0;
    std::vector<int> bingo_guesses;
    std::vector<std::vector<long long int>> translated_bingo_squares, untranslated_bingo_squares;
    std::unordered_map<int, int> primer;
    std::ifstream fr("input.txt");
    std::string temp, str;
    getline(fr, str);
    std::stringstream ss(str);
    while(getline(ss,temp, ',')) {
        std::stringstream stream(temp);
        bingo_guesses.push_back(stoi(temp));

        maxi = maxi < stoi(temp) ? stoi(temp) : maxi;
    };
    int n = bingo_guesses.size();
    maxi++;
    primeriser(primer, bingo_guesses, maxi);
    
    int bingo;
    while (fr >> bingo) {
        std::vector<long long int> bingo_square = {1,1,1,1,1,1,1,1,1,1}, untranslated;
        untranslated.push_back(bingo);
        bingo_square[0] *= primer[bingo];
        bingo_square[5] *= primer[bingo];
        for (int i = 1; i < 25; i++) {
            fr >> bingo;
            bingo_square[std::floor(i/5)] *= primer[bingo];
            bingo_square[i%5+5] *= primer[bingo];
            untranslated.push_back(bingo);
        }
        translated_bingo_squares.push_back(bingo_square);
        untranslated_bingo_squares.push_back(untranslated);
    }

    bool q1 = true;
    int m = translated_bingo_squares.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 10; k++) {
                if (translated_bingo_squares[j][k] % primer[bingo_guesses[i]] == 0) {
                    translated_bingo_squares[j][k] /= primer[bingo_guesses[i]];
                    mark_square(k, untranslated_bingo_squares[j], primer, primer[bingo_guesses[i]]);
                    if (translated_bingo_squares[j][k] == 1) {
                        if (q1) { std::cout <<"Star 1: " <<unmarked(untranslated_bingo_squares[j])*bingo_guesses[i] <<std::endl; q1 = false; }
                        if (m == 1) {
                            std::cout <<"Star 2: "<<unmarked(untranslated_bingo_squares[0])*bingo_guesses[i] <<std::endl;
                            return 0;
                        }
                        translated_bingo_squares.erase(translated_bingo_squares.begin()+j);
                        untranslated_bingo_squares.erase(untranslated_bingo_squares.begin()+j);
                        j--;
                        m--;
                        break;
                    }
                }
            }
        }
    }

}