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