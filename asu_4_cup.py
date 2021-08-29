histogram = []

def subset_sum(numbers, target, partial=[]):
    s = sum(partial)

    # check if the partial sum is equals to target
    if s == target: 
        histogram.append( partial )
        if(len(histogram) != 2):
            pass    
        else:
            print histogram[histogram.index(min(histogram, key=len))]
    if s >= target:
        return  # if we reach the number why bother to continue

    for i in range(len(numbers)):
        n = numbers[i]
        remaining = numbers[i+1:]
       
        subset_sum(remaining, target, partial + [n]) 

n = int(raw_input())
target = int(raw_input())
arr = [0 for x in range(n) ]

for i in range(n):
    arr[i] = int(raw_input())

subset_sum( arr,target )