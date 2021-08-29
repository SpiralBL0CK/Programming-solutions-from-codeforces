n = int(raw_input())
k = int(raw_input())
ans_2 = 0
ans_1 = 0 
arr_1 = [0 for x in range(n)]
arr_2 = [0 for x in range(n)]

for i in range(n):
    arr_1[i] = int(raw_input())
    if(arr_1[i] > k):
        continue
    else:
        ans = ans +1


for i in range(n):
    arr_2[i] = int(raw_input())
    if(arr_1[i] > k):
        continue
    else:
        ans_2 = ans_2 +1

if(ans1>ans2): print "Mahmoud"
	if(ans1==ans2): print "Draw"