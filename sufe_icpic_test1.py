import math
import string 
digs = string.digits + string.ascii_letters
base = (1+math.sqrt(5))/2
eps = 1e-8

def int2base(n,base):
    b = 1.0
    s = ''
    tag = True
    while (b * base <= n):
        b *= base
    while (n > 0):
        if (tag and b + eps < 1.0):
            s += '.'
            tag = False
        if ((n > b) or math.fabs(n - b) <= eps):
            s += ('1')
            n = n -base
        else:
            s += ('0')
        b = b / base
    return s

print(int2base(100000,base))