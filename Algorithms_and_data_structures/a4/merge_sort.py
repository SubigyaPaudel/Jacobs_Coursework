import time
from random import randrange

def merge_sort(A, initial, final, k):
    initial = int(initial)
    final = int(final)
    if final - initial + 1 > k:
        middle = (initial + final) // 2
        merge_sort(A,initial,middle,k)
        merge_sort(A,middle + 1,final,k)
        merge(A, initial, middle, final)
    else:
        insertion_sort(A, initial, final)
  
    
def merge(A, initial, middle, final):
    L = A[initial:middle+1]
    R = A[middle+1:(final+1)]
    L.append(float('inf'))
    R.append(float('inf'))
    l = r = i = 0
    while(i < (final - initial + 1)):
        if L[l] < R[r]:
            A[initial+i] = L[l]
            l += 1
        else:
            A[initial+i] = R[r]
            r += 1
        i += 1
        
def insertion_sort(A, initial, final):
    for i in range(initial+1, final +1):
        key = A[i]
        k = i-1
        while (k >= initial and A[k] > key):
            A[k+1] = A[k]
            k -= 1
        A[k+1] = key

file1 = open("Best_case_data.txt",'w')
file1.seek(0)
file2 = open("Best_case_timings_only.txt", 'w')
file2.seek(0)
file3 = open("Average_case_data.txt", 'w')
file3.seek(0)
file4 = open("Average_case_timings_only.txt",'w')
file4.seek(0)
file5 = open("Worst_case_data.txt", 'w')
file5.seek(0)
file6 = open("Worst_case_timings_only.txt", 'w')
file6.seek(0)

#working on the best case
print("Working on the best case...")
A = list(range(1,10000+1))
for k in range(100, 10100, 100):
    B = A
    start = time.perf_counter_ns()
    merge_sort(B, 0, len(B) - 1, k)
    stop = time.perf_counter_ns()
    duration = stop - start
    file1.write(f"k:{k} and t:{duration}\n")
    file2.write(f"{duration},\n")
print("Test for best case completed, data is written on the files")
#working on the average case
A = []
print("Working on the average case")
for i in range(1,10000+1):
    A.append(randrange(1,10001))
for k in range(100,10100,100):
    B = A
    start = time.perf_counter_ns()
    merge_sort(B,0,len(A)-1,k)
    stop = time.perf_counter_ns()
    duration = stop - start
    file3.write(f"k:{k} and t: {duration}\n")
    file4.write(f"{duration},\n")
print("Test for average case completed, data is written on the files")
#working on the worst case
print("Working on the worst case")
A = list(range(10000, 0, -1))
for k in range(100, 10100, 100):
    B = A
    start = time.perf_counter_ns()
    merge_sort(B, 0, len(B) - 1, k)
    stop = time.perf_counter_ns()
    duration = stop - start
    file5.write(f"k:{k} and t: {duration}\n")
    file6.write(f"{duration},\n")
print("Test for worst case completed, data is written on the files")
file1.close()
file2.close()
file3.close()
file4.close()
file5.close()
file6.close()


