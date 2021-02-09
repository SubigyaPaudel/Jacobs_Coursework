def min_word_len(A):
    min = len(A[0])
    for i in range(1, len(A)):
        if(len(A[i]) < min):
            min = len(A[i])
    return min

def word_radix_sort(A):
    count = {}
    k = min_word_len(A)
    for s in range(k-1, -1, -1):
        B = []
        for i in range(0, len(A)):
            B.append(' ')
        for i in range(0, 26):
            count[chr(65 + i)] = 0
            count[chr(97 + i)] = 0
        for i in range(0,len(A)):
            count[A[i][s]] += 1
        #in lines 21, 22 and 23 calculating the cummulative frequency of words having a give letter at position s
        for i in range(1, 26):
            count[chr(65 + i)] = count[chr(65 + i)] + count[chr(64 + i)]
        count['a'] = count['a'] + count['Z']                                
        for i in range(1, 26):
            count[chr(97 + i)] = count[chr(97 + i)] + count[chr(96 + i)]
        for i in range(0, 26):
            count[chr(65 + i)] -= 1 #decrementing the cummulative frequency to match the index of the array where the elements are to be inserted
            count[chr(97 + i)] -= 1
        for j in range(len(A) - 1, -1, -1):
            B[count[A[j][s]]] = A[j]
            count[A[j][s]] -= 1 
        A = B
    return A

def print_list(A):
    for i in range(0, len(A)):
        print(f"{A[i]}", end= ' ')
    print('\n')


A = ['word', 'category', 'cat', 'new', 'news', 'world', 'bear', 'at', 'work', 'asleep' ,'time']
A = word_radix_sort(A)
print_list(A)