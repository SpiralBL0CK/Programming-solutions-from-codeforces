a = int(raw_input())
b = int(raw_input())

arr = [None for x in range(a)]

for i in range(a):
    arr[i] = int(raw_input())

sol = {}
for i in range(1,a):
    slow = i-1
    diff = arr[i]-arr[slow]
    if(diff < 0):
        sol[str(arr[i])] = arr[slow]
    else:
        if ( (str(arr[i]) in sol )):
            pass
        else:      
            sol[str(arr[i])] = str(arr[slow])
    
counter = 0
for key in sol:
    print key
    counter += 1
    if(counter % b == 0):
        break
    

