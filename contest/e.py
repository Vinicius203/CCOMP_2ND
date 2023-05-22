while True:
    try:
        n = int(input())
        if n % 2 == 0:
            print('0')
        else:
            print('1')
    except EOFError:
        break