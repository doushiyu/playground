# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 16:00:36 2018

@author: sarah
"""
#from math import floor 
import os
from multiprocessing import Process, Manager
from random import randint, shuffle

#implement merging-------------------------------------------------------------
def Merge(A, p, q, r):
    n1 = q - p + 1   #comput the lenth of the first subarray
    n2 = r - q      #comput the lenth of the second subarray
    left_arr = list()     #initialize a list for left array
    right_arr = list()    #initialize a list for left array
    #build up left and right arrays using the element from the first array and 
    #second array, respectively
    for i in xrange(n1):
        left_arr.append(A[p + i])
    for j in xrange(n2):
        right_arr.append(A[q + j + 1])
    #assign a sentinel for the left and right array
    left_arr.append("infinity")
    right_arr.append("infinity")
    i, j  = 0, 0    #initialize the interator i and j
    #compare the first elements from left and right array, merge the less one
    #to the original array
    for k in xrange(p, r + 1):
        if left_arr[i] <= right_arr[j]:
            A[k] = left_arr[i]
            i = i + 1
        else:
            A[k] = right_arr[j]
            j = j + 1

#implement sequential merge sort-----------------------------------------------
def Merge_Sort(A, p, r):
    if p < r:     #ensure left bound is less then right bound
        q = (p + r)//2    #find the median of the array
        #recursively divide the array and using merging to sort the array
        Merge_Sort(A, p, q)
        Merge_Sort(A, q + 1, r)
        Merge(A, p, q, r)

#implement multithread merge sort without parallel merging
def Merge_Sort_Parallelsort(A, p, r):
    if p < r :      #ensure the left bound is less than the right bound
        q = (p + r)//2        #find the median of the array
        #using multithreads to implement recursive merge sort
        t1 = Process(target=Merge_Sort_Parallelsort, args=(A, p, q))
        t1.start()
        t2 = Process(target=Merge_Sort_Parallelsort, args=(A, q + 1, r))
        t2.start()
        #sync the multithread process
        t1.join()
        t2.join()
        #using the same merging as the squential merge sort
        Merge(A, p, q, r)

#implemnt merge sort with multithreads
def P_Merge_Sort(m, A, p, r, B, s):
    n = r - p + 1   #compute the length of the array
    print 'P_M_S(%d):' % os.getpid(), n, r, p, s, A, B
    if n == 1:    #base case when the length is 1
        #B.append(A[p])
        B[s] = A[p]
    else: 
        T = m.list([0] * n)
        print T
        #B = A[s:(s + r - p)]
        q = (p + r)//2
        q1 = q - p + 1    #compute the elements in the first array
        t1 = Process(target=P_Merge_Sort, args=(m, A, p, q, T, 0))
        t1.start()
        t2 = Process(target=P_Merge_Sort, args=(m, A, q + 1, r, T, q1))
        t2.start()
        print "Joining: ", t1.pid, t2.pid
        t1.join()
        t2.join()
        P_Merge(T, 0, q1 - 1, q1, n - 1, B, s)

#using binary search to find the location p2-----------------------------------
def Binary_Search(x, T, p, r):
    low = p
    high = max(p, r+1)
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
    print 'P_M(%d):' % os.getpid(), T
    print 'P_Ma:', r1, p1, n1
    print 'P_Mb:', r2, p2, n2
    print 'P_Mc:', A, p3
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
        t1 = Process(target=P_Merge, args=(T, p1, q1-1, p2, q2-1, A, p3))
        t1.start()
        t2 = Process(target=P_Merge, args=(T, q1+1 , r1, q2, r2 , A, q3 + 1))
        t2.start()
        #sync the multithread implementations
        t1.join()
        t2.join()

if __name__ == "__main__":
    manager = Manager()
    arr = list()
    for i in xrange(10):
        arr.append(randint(0, 100))
    #arr = [22, 11, 33]
    print arr
    arr1 = arr[:]
    Merge_Sort(arr1, 0, len(arr)-1)
    print "Merge_Sort:", arr1

    arr2 = manager.list(arr)
    print arr2
    Merge_Sort_Parallelsort(arr2, 0, len(arr)-1)
    print "Merge_Sourt_parallelsort:", arr2

    arr3 = manager.list(arr)
    arr4 = manager.list([0] * len(arr))
    P_Merge_Sort(manager, arr3, 0, len(arr)-1, arr4, 0)
    print "P_Merge_Sort:", arr4

