with open("1.txt", 'r') as f:
    lines = f.readlines()
    
    tot = 0
    cur = 0
    m = 0
    m_tot = [0, 0, 0]

    for line in lines[:-1]:
        if line == '\n':
            #if cur > m:
            #    m = max(cur, m)
            #    m_tot = tot
            #cur = 0
            #tot = 0

            if tot > m_tot[2]:
                m_tot[2] = tot
                m_tot.sort(reverse=True)
            tot = 0
            cur = 0
        
        else:
            n = int(line[:-1])
            tot += n
            cur = max(n, tot)

    tot += int(lines[-1])
    if tot > m_tot[2]:
        m_tot[2] = tot
    
    print(sum(m_tot))