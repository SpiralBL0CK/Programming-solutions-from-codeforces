hashmap = {}
n = int(raw_input())
arr = [0 for x in range(n)]
for i in range(n):
    arr[i] = int(raw_input())

ip = iter(arr)
s = set(next(ip))
s.intersection(*ip)
