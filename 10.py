def signal_check(cycle, score, increment, code):
    if code == 'n':
        if (cycle - 20) % 40 == 39:
            return score * (cycle + 1) 
        else:
            return 0
    else:
        if (cycle - 20) % 40 == 39: 
            return score * (cycle + 1)
        if (cycle - 20) % 40 == 38:
            return (score + increment) * (cycle + 2)
        else: 
            return 0

def print_screen(screen):
    for row in screen:
        print("".join(row))

def part1():
    with open("10.txt", 'r') as f:
        cycle = 1
        score = 1
        sum_signal = 0
        for line in f.readlines():
            if line[0] == 'n':
                sum_signal += signal_check(cycle, score, 0, 'n')
                cycle += 1
            if line[0] == 'a':
                increment = int(line[5:])
                sum_signal += signal_check(cycle, score, increment, 'a')
                s = signal_check(cycle, score, increment, 'a')
                cycle += 2
                score += increment
                
                
        print(sum_signal)

def part2():
    with open("10.txt", 'r') as f:
        cycle = 1
        score = 1
        screen = [['.'] * 40 for _ in range(6)]
        x = 0
        y = 0
        for line in f.readlines():
            if line[0] == 'n':
                if abs(x - score) <= 1:
                    screen[y][x] = '#'
                cycle += 1
                if x == 39: 
                    x = 0
                    y += 1
                else:
                    x += 1
            if line[0] == 'a':
                if abs(x - score) <= 1:
                    screen[y][x] = '#'
                if x == 39: 
                    x = 0
                    y += 1
                else:
                    x += 1
                cycle += 1
                if abs(x - score) <= 1:
                    screen[y][x] = '#'
                if x == 39: 
                    x = 0
                    y += 1
                else:
                    x += 1
                cycle += 1
                score += int(line[5:])
        print_screen(screen)

if __name__ == "__main__":
    part1()
    part2() #RKPJBPLA