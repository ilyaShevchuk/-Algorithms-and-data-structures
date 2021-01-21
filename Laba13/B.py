def prefix_fun(s):
    pref = [0 for i in range(len(s))]
    for i in range(1, len(s)):
        k = pref[i - 1]
        while k > 0 and s[i] != s[k]:
            k = pref[k - 1]
        if s[i] == s[k]:
            k += 1
        pref[i] = k
    return pref


def kmp(p, t):
    result = []
    pi = prefix_fun(p + '#' + t)
    for i in range(len(t)):
        if pi[len(p) + i + 1] == len(p):
            result.append(i-len(p)+2)
    return result


fin = open("search2.in")
fout = open("search2.out", "w")
p1 = fin.readline().strip()
t1 = fin.readline().strip()
lst = kmp(p1, t1)
fout.write(str(len(lst)) + '\n')
for index in lst:
    fout.write(str(index) + ' ')
fout.close()
fin.close()
