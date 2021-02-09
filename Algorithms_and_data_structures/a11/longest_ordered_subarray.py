def one_count(A):
    count = 0
    for i in A:
        if i == 1:
            count += 1
    return count

def max_pos(A):
    max = 0
    for i in range(0,len(A)):
        if(A[i]>A[max]):
            max = i
    return max

def generate_table(A):
    Table = []
    for i in range(0,len(A)):
        Table.append(list([0]*len(A)))
    for i in range(0, len(A)):
        elligible = []
        for j in range(i-1, -1, -1):
            if A[j] < A[i]:
                elligible.append(Table[j])
        counts = []
        for j in elligible:
            counts.append(one_count(j))
        if(elligible != []):
            max = max_pos(counts)
            Table[i] = list(elligible[max])
        Table[i][i] = 1
    return Table

A = input("Enter a series of numbers")
inputlist = []
number = 0
for i in range(0, len(A)):
        if str.isdigit(A[i]):
            number += int(A[i]) 
            if i != len(A)-1:
                if ord(A[i+1]) == 32:
                    inputlist.append(number)
                    number = 0
                elif(str.isdigit(A[i+1])):
                    number *= 10
                else:
                    pass
            else:
                if(str.isdigit(A[i])):
                    inputlist.append(number)
table = generate_table(inputlist)
count = []
for i in table:
    count.append(one_count(i))
max = max_pos(count)
target_list = table[max]
print("A maximum ordered subarray is", end= '\n')
pos = 0
for i in target_list:
    if i == 1:
        print(inputlist[pos], end= ' ')
    pos += 1

