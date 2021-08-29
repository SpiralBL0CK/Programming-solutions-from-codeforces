t = int(raw_input())

mod = 1e9 + 7
dp = [None for x in range(1000000)]
for k in range(t):
    n = int(raw_input())
    m = int(raw_input())
    for k in range(n):
        for j in range(m):
            tmp = raw_input()
            if(tmp <= j):
                dp[j] = (dp[j] + dp[j-tmp]) % mod
