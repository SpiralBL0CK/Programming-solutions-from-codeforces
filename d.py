"""

a = 2 *nr student -> spart in a = a/2[0]
b = a/2[1]

The ith numbered student in the first line can be partnered with the jth numbered student in the second line if |i−j|≤e

.

However, there are k pairs of students that cannot be paired together to avoid trouble in the classroom

"""

import z3


s = Solver()

n = input()
e = input()
k = input()

code = IntVector("x", n)
code2 = IntVector("x", n)

if k == 0:
    print(max(n,e))
else:
    u = input()
    v = input()
for k in range(n):
    for z in range(n):
        for i in range(u):
            for j in range(v):
                s.add((code[i] - code[j]) > e)
        
if solver.check() == z3.sat:
        print("".join(chr(solver.model()[c].as_long()) for c in name).encode("latin-1")) 
                                    
