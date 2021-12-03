#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


typedef std::vector<std::string> input_vector;
auto parse_input(std::string s) {
    std::string bit_seq;
    input_vector input = {};
    std::ifstream File;
    File.open(s);
    while (File >> bit_seq)
        input.push_back(bit_seq);

    return input;
}

int get_freq(input_vector input, int bit) {
    int n = input.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (input[i][bit] == '1')
            count++;
        else
            count--;
    }
    return count;
}

int part_one(int n, input_vector input) {
    int gamma = 0;
    int epsilon = 0;
    int count;
    for (int i = 0; i < n; i++) {
        count = get_freq(input, i);
        if (count > 0)
            gamma += pow(2, n-i-1);
        else
            epsilon += pow(2, n-i-1);
    }
    return (gamma * epsilon);
}

int part_two(int n, input_vector input) {
    int count;
    input_vector oxygen_vector(input);
    input_vector co2_vector(input);

    int m = oxygen_vector.size();
    for (int i = 0; (i < n) && (1 < m); i++) {
        count = get_freq(oxygen_vector, i);
        for (int j = m-1; 0 <= j; j--) {
            if ((count >= 0) && (oxygen_vector[j][i] == '0'))
                oxygen_vector.erase(oxygen_vector.begin() + j);
            else if ((count < 0) && (oxygen_vector[j][i] == '1'))
                oxygen_vector.erase(oxygen_vector.begin() + j);
        }
        m = oxygen_vector.size();
    }

    m = co2_vector.size();
    for (int i = 0; (i < n) && (1 < m); i++) {
        count = get_freq(co2_vector, i);
        for (int j = m-1; 0 <= j; j--) {
            if ((count >= 0) && (co2_vector[j][i] == '1'))
                co2_vector.erase(co2_vector.begin() + j);
            else if ((count < 0) && (co2_vector[j][i] == '0'))
                co2_vector.erase(co2_vector.begin() + j);
        }
        m = co2_vector.size();
    }

    int oxygen = 0;
    int co2 = 0;
    for (int i = 0; i < n; i++) {
        if (oxygen_vector[0][i] == '1')
            oxygen += pow(2, n-i-1);
        if (co2_vector[0][i] == '1')
            co2 += pow(2, n-i-1);
    }
    return (oxygen * co2);
}

int main() {
    auto input = parse_input("input.txt");
    int input_size = input[0].size();
    std::cout << part_one(input_size, input) << std::endl
              << part_two(input_size, input) << std::endl;
    return 0;
}
