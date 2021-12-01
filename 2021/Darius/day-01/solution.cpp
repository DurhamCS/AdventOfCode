#include <iostream>
#include <fstream>
#include <vector>


auto parse_input(std::string s) {
    int number;
    std::vector<uint32_t> input = {};
    std::ifstream File;
    File.open(s);
    while (File >> number)
        input.push_back(number);

    return input;
}

int part_one(int n, std::vector<uint32_t> input) {
    int total = 0;
    for (int i=1; i < n; i++)
        if (input[i-1] < input[i]) total++;

    return total;
}

int part_two(int n, std::vector<uint32_t> input) {
    int total = 0;
    int prev_sum = input[0] + input[1] + input[2];
    int cur_sum;
    for (int i=3; i < n; i++) {
        cur_sum = prev_sum - input[i - 3] + input[i];
        if (prev_sum < cur_sum) total++;
        prev_sum = cur_sum;
    }

    return total;
}

int main() {
    auto input = parse_input("input.txt");
    int input_size = input.size();
    std::cout << part_one(input_size, input) << std::endl;
    std::cout << part_two(input_size, input) << std::endl;
    return 0;
}
