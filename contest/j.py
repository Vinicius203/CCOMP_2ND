import math as m

while True:
    try:
        n = int(input())
        max = int(m.sqrt(n))
        flag = False
        for i in range(max + 1, 0, -1):
            for j in range(max + 1):
                #print("==", (i ** 2) + (j ** 2), "==")
                if flag:
                    break
                elif ((i ** 2) + (j ** 2)) == n:
                    #print("==(", i,j,")==", (i ** 2) + (j ** 2), "==")
                    print(1)
                    flag = True
                    break
        if not flag:
            print(0)
    except EOFError:
        break
