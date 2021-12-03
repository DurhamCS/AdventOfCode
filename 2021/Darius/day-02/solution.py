def part_one(arr):
    depth = position = 0
    for instruction, amount in arr:
        if instruction == "forward":
            position += int(amount)
        elif instruction == "up":
            depth -= int(amount)
        elif instruction == "down":
            depth += int(amount)

    return depth * position


def part_two(arr):
    depth = position = aim = 0
    for instruction, amount in arr:
        if instruction == "forward":
            position += int(amount)
            depth += aim * int(amount)
        elif instruction == "up":
            aim -= int(amount)
        elif instruction == "down":
            aim += int(amount)

    return depth * position


if __name__ == '__main__':
    with open("input.txt") as f:
        inp = [line.split() for line in f.readlines()]

    print(part_one(inp))
    print(part_two(inp))
