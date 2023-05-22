while True:
    try:
        n, m = input().split()
        lista = []
        n_int = int(n)
        m_int = int(m)

        for i in range(n_int, m_int):
            string = str(i)
            reverse = string[::-1]
            if string == reverse:
                lista.append(i)

        if lista:
            print(lista[0], lista[len(lista)-1])
        else:
            print('-1')
    except EOFError:
        break
