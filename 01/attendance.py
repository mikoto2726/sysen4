def sum_between(x, y):
    num = 0
    for i in  range(x,y+1):
        num += i
    print(num)
    return num


sum_between(10, 20)