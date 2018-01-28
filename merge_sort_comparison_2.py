# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 16:00:36 2018

@author: sarah
"""
#from math import floor 
from multiprocessing import Process, Array, active_children, cpu_count, \
    current_process
import time
import numpy as np
import matplotlib.pyplot as plt

#implement merging-------------------------------------------------------------
def Merge(left, right):
    arr = list()
    left_itr, right_itr = 0, 0
    while left_itr < len(left) and right_itr < len(right):
        print left_itr, right_itr,left,right
        if left[left_itr] <= right[right_itr]:
            arr.append(right[right_itr])
            left_itr += 1
        else:
            arr.append(right[right_itr])
            right_itr += 1
    if left_itr == len(left):
        arr.extend(right[right_itr:])
    elif right_itr == len(right):
        arr.extend(left[left_itr:])
    print arr
    return arr

#implement sequential merge sort-----------------------------------------------
def Merge_Sort(A):
    if len(A) == 1:
        return A
    mid = len(A)//2    #find the median of the array
    #recursively divide the array and using merging to sort the array
    #using slicing divide the array A into half
    return Merge(Merge_Sort(A[:mid]), Merge_Sort(A[mid:]))

#implement multithread merge sort without parallel merging
def Merge_Sort_Parallelsort(A):
    if len(A) == 1:
        return A
    mid = len(A)//2        #find the median of the array
    #using multithreads to implement recursive merge sort
    child_processls = active_children()
    if len(child_processls) <= cpu_count():
        current_process().join()
    else:
        t1 = Process(target = Merge_Sort_Parallelsort, args = (A[:mid],))
        t1.start()
        t2 = Process(target = Merge_Sort_Parallelsort, args = (A[mid:],))
        t2.start()
        #print 'MSP:', t1.pid, t2.pid
        #sync the multithread process
        t1.join()
        t2.join()
        #using the same merging as the squential merge sort
        return Merge(Merge_Sort(A[:mid]), Merge_Sort(A[mid:]))

#implemnt merge sort with multithreads-----------------------------------------
def P_Merge_Sort(A, p, r, B, s):
    n = r - p + 1   #compute the length of the array
    #print p, r, s,B, A,
    if n == 1:    #base case when the length is 1
        B[s] = A[p]
    else: 
        T = Array('i', [0] * n)
        #B = A[s:(s + r - p)]
        q = (p + r)//2
        q1 = q - p + 1    #compute the elements in the first array
        t1 = Process(target = P_Merge_Sort, args = (A, p, q, T, 0))
        t1.start()
        t2 = Process(target = P_Merge_Sort, args = (A, q + 1, r, T, q1))
        t2.start()
        #print 'P_M_S:', t1.pid, t2.pid
        t1.join()
        t2.join()
        P_Merge(T, 0, q1 - 1, q1, n - 1, B, s)

#using binary search to find the location p2-----------------------------------
def Binary_Search(x, T, p, r):
    low = p
    high = max(p, r + 1)
    while low < high:
        mid = (low + high)//2
        if x <= T[mid]:
            high = mid
        else:
            low = mid + 1
    return high

#implement multithread merging-------------------------------------------------
def P_Merge(T, p1, r1, p2, r2, A, p3):
    n1 = r1 - p1 + 1    #compute the length of T[p1..r1]
    n2 = r2 - p2 + 1   #compute the length of T[p2..r2]
    if n1 < n2:    #assume n1 >= n2, then the base case is n1 = 0
        #using tuple swap two values
        p1, p2 = p2, p1
        r1, r2 = r2, r1
        n1, n2 = n2, n1
    if n1 == 0:   #base case, n1 and n2 are empty
        return
    else:
        q1 = (p1 + r1)//2       #compute the median in T[p1..r1]
        #using binary search to find the location p2 
        #satisfies T[p2-1] < T[p1] < T[p2]
        q2 = Binary_Search(T[q1], T, p2, r2)
        #find the location of T[p1] in A[p3]
        q3 = p3 + (q1 -p1) + (q2 - p2)
        A[q3] = T[q1]   #assign the pivot value in the original array
        #using multithreads to implemnt the recursive parallel merging
        t1 = Process(target = P_Merge, 
                         args = (T, p1, q1 - 1, p2, q2 - 1, A, p3))
        t1.start()
        t2 = Process(target = P_Merge, 
                         args = (T, q1 + 1 , r1, q2, r2 , A, q3 + 1))
        t2.start()
        #print 'P_M:', t1.pid, t2.pid
        #sync the multithread implementations
        t1.join()
        t2.join()

if __name__ == "__main__":
    arr = list()    #build a list storing the input arrays
    idx_n = list()      #build a list storing the size of the arrays
    idx_n = [10* 2 ** n for n in xrange(1)]
    aver_t1, aver_t2, aver_t3 = list(), list(), list()
    for counter,idx in enumerate(idx_n):
        arr = list(np.random.randint(0, 101, idx))
        #print "input array:", arr
        timelist1 = list()
        timelist2 = list()
        timelist3 = list()
        for n in xrange(1):
            arr1 = arr[:]
            start1 = time.time()
            arr1 = Merge_Sort(arr)
            #print "Merge_Sort:", arr1[:]
            end1 = time.time()
            arr2 = arr[:]
            start2 = time.time()
            arr2 = Merge_Sort_Parallelsort(arr)
            #print "Merge_Sort_Parallel:", arr2[:]
            end2 = time.time()
            arr3 = Array('i', arr)
            start3 = time.time()
            #P_Merge_Sort(arr, 0, len(arr) - 1, arr3, 0)
            #print "Merge_Sort_Parallel:", arr3[:]
            end3 = time.time()
            timelist1.append(end1 - start1)
            timelist2.append(end2 - start2)
            timelist3.append(end3 - start3)
        aver_t1.append(np.average(timelist1))
        aver_t2.append(np.average(timelist2))
        aver_t3.append(np.average(timelist3))
        print "size %d accomplish" % idx
    print aver_t1, aver_t2, aver_t3, idx_n
    print arr, arr1, arr2
    plt.figure(1)
    plt.plot(aver_t1, idx_n)
    plt.hold("on")
    plt.xlabel("size")
    plt.ylabel("time")
    plt.title("merge sorts time efficiency camparison")
    plt.plot(aver_t2, idx_n)
    plt.plot(aver_t3, idx_n)
    plt.legend("squential merge sort", "merge sort with parallel sort", 
                   "parallel merge sort")
    plt.show()