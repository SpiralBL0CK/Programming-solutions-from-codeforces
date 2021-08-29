import math

x = int(raw_input())
s = 0
while(x):
    a = int(raw_input()) + int(raw_input())
    b = int(raw_input()) - int(raw_input())
    s = 1 + gcd(a,b)
    x = x -1