from math import log10, floor

def max(A):
    largest = A[0]
    for i in A:
        if(i > largest):
            largest = i
    return largest

def extract_digit(A,pos):
    return floor((A / 10 ** pos)) % 10

def hollerithsort(A,k):
    if(len(A) < 2 or k < 0):
        return A
    else:
        C = [0] * 10
        arrays, S = [], []
        for i in A:
            C[extract_digit(i,k)] += 1
            arrays.append([])       #CREATE NEW ARRAYS TO DIFFERENTIATE NUMBERS WHOSE ORDER OF MAGNITUDE ARE DIFFERENT
        for i in range(1,len(C)):
            C[i] += C[i-1]
        for i in range(0,len(C)):
            C[i] -= 1
        for i in range(0,len(A)):
            arrays[C[extract_digit(A[i],k)]] += [A[i]]
            print(arrays)
        for i in range(0,len(arrays)):
            result = hollerithsort(arrays[i],k-1)
            S += result
        return S
    
A = [23,110,329, 457, 657, 839, 436, 720, 355, 1000,4000, 4800, 5000, 6070]
A = hollerithsort(A,floor(log10(max(A))))
print(A)