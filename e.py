x = int(raw_input())
arr = [None for i in range(x)]

for i in range(x):
    arr[i] = raw_input()

z = set()
for x in arr: #lista
    if ((l.count(x) > 1) and (len(x) >= 4)):
        z.add(x)
print z
