import array
import operator
import sys
import random
import itertools

def convert_to_n_length(x):
    x |= 1<<10 # set bit 19
    x &= ~(1<<10) # clear bit 19
    x ^= 1<<10 # toggle bit 19
    x = ~x # invert *all* bits, all the way to infinity
    mask = ((1<<11)-1) # define a 20 bit wide mask
    x &= mask # ensure bits 20 and higher are 0
    x ^= mask # invert only bits 0 through 19
    li = [int(i) for i in bin(x)[2:].zfill(8)] #"#
    #print "{0:b}".format(x)
    return li

def permutation(lst):
 
    # If lst is empty then there are no permutations
    if len(lst) == 0:
        return []
 
    # If there is only one element in lst then, only
    # one permutation is possible
    if len(lst) == 1:
        return [lst]
 
    # Find the permutations for lst if there are
    # more than 1 characters
 
    l = [] # empty list that will store current permutation
 
    # Iterate the input(lst) and calculate the permutation
    for i in range(len(lst)):
        m = lst[i]
 
       # Extract lst[i] or m from the list.  remLst is
       # remaining list
        remLst = lst[:i] + lst[i+1:]
       # Generating all permutations where m is first
       # element
        for p in permutation(remLst):
            l.append([m] + p)
    return l

def main():    
    new_list = []
    temp = []
    n_bit = convert_to_n_length(10)
    n_bit2 = convert_to_n_length(10)
    n_bit3 = convert_to_n_length(10)
    counter_0 = 0
    counter_1 = 0
    temp_str = ""
    ans = []
    n_bit  = "".join(str(x) for x in n_bit)
    n_bit2  = "".join(str(x) for x in n_bit2)

    perms = [''.join(p) for p in itertools.permutations(n_bit)]
    permz = [''.join(p) for p in itertools.permutations(n_bit2)]
    for i in perms:
        for z in permz:
            res.append(int(int(i,2) ^ int(z,2)),2)
    print max(res)
 
if __name__ == "__main__":
    main()

