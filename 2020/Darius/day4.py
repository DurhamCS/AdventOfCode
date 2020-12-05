with open('inputs/day4.txt') as f:
    data = [{fields.split(':')[0]: fields.split(':')[1] for fields in line.split()}
            for line in f.read().split('\n\n')]


required = {'byr': lambda v: '1920' <= v <= '2002',
            'iyr': lambda v: '2010' <= v <= '2020',
            'eyr': lambda v: '2020' <= v <= '2030',
            'hgt': lambda v: '150' <= v[:-2] <= '193' if v[-2:] == 'cm' else '59' <= v[:-2] <= '76',
            'hcl': lambda v: len(v) == 7 and v[0] == '#' and all(char in '0123456789abcdef' for char in v[1:]),
            'ecl': lambda v: v in ('amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'),
            'pid': lambda v: len(v) == 9 and v.isdigit()}


def is_valid(passport, checks=True):
    if required.keys() != passport.keys() & required.keys():
        return False
    elif not checks:
        return True

    for field, value in passport.items():
        if field == 'cid':
            continue
        elif not required.get(field)(value):
            return False
    return True


print(sum(is_valid(passport, checks=False) for passport in data))
print(sum(is_valid(passport) for passport in data))
