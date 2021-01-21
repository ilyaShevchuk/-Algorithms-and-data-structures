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


fin = open("prefix.in")
out = open("prefix.out", "w")
p = fin.readline().strip()
lst = prefix_fun(p)
for index in lst:
    out.write(str(index) + ' ')
out.close()
fin.close()
