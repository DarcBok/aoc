import cmath
import math


rope = [0] * 10
seen = [set([x]) for x in rope]
direction = {'L':-1, 'R':1, 'D':-1j, 'U':1j}
move_sign = lambda x : complex((x.real > 0) - (x.real < 0), (x.imag > 0) - (x.imag < 0))

with open("9.txt") as f:
    for line in f.readlines():
        di = line[0]
        moves = int(line[2:])

        for _ in range(moves):
            rope[0] += direction[line[0]]
            for i in range(1,10):
                if abs(rope[i] - rope[i-1]) >= 2:
                    rope[i] += move_sign(rope[i-1] - rope[i])
                    seen[i].add(rope[i])

    print(len(seen[1]))
    print(len(seen[9]))