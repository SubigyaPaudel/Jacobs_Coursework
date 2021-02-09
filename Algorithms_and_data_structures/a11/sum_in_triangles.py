from sys import exit

def string_to_numbers(A):
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
    return inputlist

def make_tree(lines):
    tree = []
    for i in range(1, lines+1):
        newrow = []
        for j in range(0,i):
            newrow.append(0)
        tree.append(newrow)
    return tree

def max_pos(A):
    max = 0
    for i in range(0,len(A)):
        if(A[i]>A[max]):
            max = i
    return max

linecopy = lines = int(input("How many lines?"))
valuetree = make_tree(lines)
sumtree = make_tree(lines)
for i in range(1, lines+1):
    enter = input("Enter the numbers")
    numbers = string_to_numbers(enter)
    if(len(numbers) > i):
        print("Invalid input")
        exit()
    valuetree[i-1] = numbers
sumtree[0][0] = valuetree[0][0]
for i in range(1, lines):
    for j in range(0,i+1):
        if (j == 0):
            sumtree[i][j] = sumtree[i-1][j] + valuetree[i][j]
        elif (j == i):
            sumtree[i][j] = sumtree[i-1][j-1] + valuetree[i][j]
        else:
            if(sumtree[i-1][j-1] > sumtree[i-1][j]):
                sumtree[i][j] = sumtree[i-1][j-1] + valuetree[i][j]
            else:
                sumtree[i][j] = sumtree[i-1][j] + valuetree[i][j]
print(valuetree, end='\n')
print(sumtree, end='\n')
max = max_pos(sumtree[lines-1])
target = [0]*lines
for i in range(lines-1, -1, -1):
    target[i] = valuetree[i][max]
    print(target[i], end= '\n')
    if(sumtree[i][max] == sumtree[i-1][max-1] + valuetree[i][max]):
        max -= 1
print(target)
        
    
