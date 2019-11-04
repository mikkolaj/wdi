def pow(a, n):
    c=1
    for i in range(1,n+1):
        c*=a
    return c
tab = [1, 2, 3, 4]
for i in tab:
    print(pow(i, 2))
