from math import floor

def counting_sort(A, max):
    C = []
    B = []
    for i in range(0, max+1):
        C.append(0)
    for i in range(0, len(A)):
        C[A[i]] = C[A[i]] + 1
        B.append(0)
    for i in range(1,len(C)):
        C[i] = C[i] + C[i-1]
    for i in range(0,len(C)):
        C[i] -=1
    for i in range(len(A)-1, -1, -1):
        B[C[A[i]]] = A[i]
        C[A[i]] -= 1
    return B

def insertion_sort(A):
    for i in range(1,len(A)):
        key = A[i]
        j = i - 1
        while(A[j] > key and j >= 0):
            print_list(A)
            A[j+1] = A[j]
            j = j - 1
            print(f"Value of j = {j}")
        A[j+1] = key
        print_list(A)

def bucket_sort(A):
    B = []
    concated_list = []
    for i in range(0,len(A)):
        B.append([])
    for i in range(0, len(A)):
        B[floor(len(B)*A[i])].append(A[i])
    for i in range(0, len(B)):
        insertion_sort(B[i])
    for i in range(0,len(B)):
        if(len(B[i]) != 0):
            for j in range(0,len(B[i])):
                concated_list.append(B[i][j])
    return concated_list
    

def print_list(A):
    for i in range(0, len(A)):
        print(f"{A[i]}", end= ' ')
    print('\n')

A = [9,1,6,7,6,2,1]
A = counting_sort(A,9)
C = [0.9,0.1,0.6,0.7,0.6,0.3,0.1]
C = bucket_sort(C)
print_list(A) 
print_list(C)