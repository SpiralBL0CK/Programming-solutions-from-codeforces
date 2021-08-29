x = int(raw_input())
y = int(raw_input())
command = raw_input()

for i in command:
    if i == 'U':
        y = y + 1
    if i == 'D':
        y = y -1
    if i == 'L':
        x = x-1
    if i == 'R':
        x = x+1

print(x,y)
