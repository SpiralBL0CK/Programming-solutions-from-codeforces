import math
def main():
    PI =  math.pi
    total_num = int(raw_input())
    length = int(raw_input())
    radious = length / (2 * math.sin(PI / total_num));    
    area = PI * radious * radious;
    print(area)

main()
