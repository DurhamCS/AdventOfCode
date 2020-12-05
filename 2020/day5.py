with open('inputs/day5.txt') as f:
    data = f.read().split('\n')

seating = {'B': lambda rc: [(1 + sum(rc[0]) // 2, rc[0][1]), rc[1]],
           'F': lambda rc: [(rc[0][0], sum(rc[0]) // 2), rc[1]],
           'R': lambda rc: [rc[0], (1 + sum(rc[1]) // 2, rc[1][1])],
           'L': lambda rc: [rc[0], (rc[1][0], sum(rc[1]) // 2)]}


def find_seat_id(boarding):
    row_col_range = [(0, 127), (0, 7)]
    for char in boarding:
        row_col_range = seating[char](row_col_range)
    return 8 * row_col_range[0][0] + row_col_range[1][0]


seats = sorted(find_seat_id(seat) for seat in data)
print(max(seats))

for seat_id in range(seats[1], seats[-1]):
    if seat_id not in seats:
        print(seat_id)
        break
