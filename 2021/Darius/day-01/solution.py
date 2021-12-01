def part_one(n, arr):
    return sum(arr[i] < arr[i+1] for i in range(n-1))


# If you cared about efficiency, do this manually :x
def part_two(n, arr):
    return sum(sum(arr[i:i+3]) < sum(arr[i+1:i+4]) for i in range(n-3))


if __name__ == '__main__':
    with open("input.txt") as f:
        inp = [int(val) for val in f.readlines()]
        length = len(inp)

    print(part_one(length, inp))
    print(part_two(length, inp))
