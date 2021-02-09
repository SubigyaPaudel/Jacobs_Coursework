def n_fibonacci(n, Table):
    if(n >= len(Table)):
        if n == 1 or n == 0:
            Table.append(1)
            return 1
        else:
            Table.append(n_fibonacci(n-2, Table) + n_fibonacci(n-1, Table))
            return Table[-1]
    else:
        return Table[n]

i = int(input("Enter a number"))
Table = list()
print(f"The {i} th fibonacci number is {n_fibonacci(i,Table)}")

