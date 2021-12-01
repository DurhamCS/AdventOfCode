#include <iostream>
#include <fstream>
#include <vector>


auto parse_input(std::string s) {
    int number;
    std::vector<int> input = {};
    std::ifstream File;
    File.open(s);
    while (File >> number)
        input.push_back(number);

    return input;
}

int part_one(int n, void *input) {
    return -1;
}

int part_two(int n, void *input) {
    return -1;
}

int main() {
    auto input = parse_input("input.txt");
    int input_size = input.size();
    std::cout << part_one(input_size, &input) << std::endl
              << part_two(input_size, &input) << std::endl;
    return 0;
}
