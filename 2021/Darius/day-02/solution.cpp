#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>


typedef std::vector<std::tuple<char, int> > input_tuple;
auto parse_input(std::string s) {
    std::string instruction;
    int number;
    input_tuple input;
    std::ifstream File(s);
    while (File >> instruction >> number)
        input.push_back(std::make_tuple(instruction[0], number));

    return input;
}

int part_one(int n, input_tuple input) {
    int depth = 0;
    int position = 0;
    int value;
    for (int i=0; i < n; i++) {
        value = std::get<1>(input[i]);
        switch (std::get<0>(input[i])) {
            case 'f':
                position += value;
                break;
            case 'd':
                depth += value;
                break;
            case 'u':
                depth -= value;
                break;
        }
    }
    return depth * position;
}

int part_two(int n, input_tuple input) {
    int aim = 0;
    int depth = 0;
    int position = 0;
    int value;
    for (int i=0; i < n; i++) {
        value = std::get<1>(input[i]);
        switch (std::get<0>(input[i])) {
            case 'f':
                position += value;
                depth += aim * value;
                break;
            case 'd':
                aim += value;
                break;
            case 'u':
                aim -= value;
                break;
        }
    }
    return depth * position;
}

int main() {
    auto input = parse_input("input.txt");
    int input_size = input.size();
    std::cout << part_one(input_size, input) << std::endl
              << part_two(input_size, input) << std::endl;
    return 0;
}
