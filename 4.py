with open("4.txt", 'r') as f:
    part1 = 0
    part2 = 0

    for line in f.readlines():
        a, b = line.split(',')
        a1, a2 = map(int, a.split('-'))
        b1, b2 = map(int, b.split('-'))
        # part 1
        if (a1 <= b1 and a2 >= b2) or (b1 <= a1 and b2 >= a2):
            part1 += 1
        # part 2
        if ((a1 <= b1 and a2 >= b1) or (b1 <= a1 and b2 >= a1)):
            part2 += 1

    print(part1)
    print(part2)
