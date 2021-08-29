x = int(raw_input())
y = int(raw_input())

students = [None for i in range(x)]
groups = {}

for i in range(x):
    students[i] = raw_input()

for i in range(x):
    x = raw_input().split()
    choice = x[0]
    if(choice == '1'):
        if x[1] in groups:
            pass
        else:
            groups[x[1]] = x[2]
    else:
        if groups[x[1]]:
            print"yes"
        else:
            print "no"
