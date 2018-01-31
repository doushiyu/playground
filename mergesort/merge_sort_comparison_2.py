# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 16:00:36 2018

@author: sarah
"""
#from math import floor 
from multiprocessing import Process, Array, Queue
import time
import numpy as np
import matplotlib.pyplot as plt

#implement merging-------------------------------------------------------------
def Merge(left, right):
    arr = list()
    left_itr, right_itr = 0, 0
    while left_itr < len(left) and right_itr < len(right):
        #print left_itr, right_itr,left,right
        if left[left_itr] <= right[right_itr]:
            arr.append(left[left_itr])
            left_itr += 1
        else:
            arr.append(right[right_itr])
            right_itr += 1
    if left_itr == len(left):
        arr.extend(right[right_itr:])
    elif right_itr == len(right):
        arr.extend(left[left_itr:])
    return arr

#implement sequential merge sort-----------------------------------------------
def Merge_Sort(A):
    if len(A) <= 1:
        return A
    mid = len(A)//2    #find the median of the array
    #recursively divide the array and using merging to sort the array
    #using slicing divide the array A into half
    left = Merge_Sort(A[:mid])
    right = Merge_Sort(A[mid:])
    return Merge(left, right)

#implement multithread merge sort without parallel merging
def Merge_Sort_Parallelsort(A, queue, process_num):
    if len(A) <= 1 or process_num <= 0:
        queue.put(Merge_Sort(A))
        queue.close()
        return
    queue_left = Queue()
    queue_right = Queue()
    mid = len(A)//2        #find the median of the array
    #using multithreads to implement recursive merge sort
    process_left = Process(target = Merge_Sort_Parallelsort, args = (A[:mid], 
                     queue_left, process_num - 1))
    process_left.start()
    process_right = Process(target = Merge_Sort_Parallelsort, args = (A[mid:], 
                     queue_right, process_num - 1))
    process_right.start()
    queue.put(Merge(queue_left.get(), queue_right.get()))
    queue.close()
    #print 'MSP:', t1.pid, t2.pid
    #sync the multithread process
    process_left.join()
    process_right.join()
    #using the same merging as the squential merge sort

#implemnt merge sort with multithreads-----------------------------------------
def P_Merge_Sort(A, process_num):
    print A, process_num
    #if len(A) <= 17 or process_num <= 0:
        #C = Merge_Sort(A)
        #return C
    queue_left = Queue()
    queue_right = Queue()
    mid = len(A)//2        #find the median of the array
    if mid <= 17 or process_num <= 0:
        leftarr = Merge_Sort(A[:mid])
        rightarr = Merge_Sort(A[mid:])
        C = A[:]
        queue_merge = Queue()
        process_merge = Process(target = P_Merge, args = (leftarr, 
                         rightarr, C, queue_merge, 3))
        process_merge.start()
        C = queue_merge.get()
    else:
        #using multithreads to implement recursive merge sort
        process_left = Process(target = Merge_Sort_Parallelsort, args = (A[:mid], 
                         queue_left, process_num - 1))
        process_left.start()
        process_right = Process(target = Merge_Sort_Parallelsort, args = (A[mid:], 
                         queue_right, process_num - 1))
        process_right.start()
        C = A[:]
        queue_merge = Queue()
        process_merge = Process(target = P_Merge, args = (queue_left.get(), 
                         queue_right.get(), C, queue_merge, process_num))
        process_merge.start()
        C = queue_merge.get()
        queue_left.close()
        queue_right.close()
        queue_merge.close()
        #print 'MSP:', t1.pid, t2.pid
        #sync the multithread process
        process_left.join()
        process_right.join()
        process_merge.join()
        #using the same merging as the squential merge sort
    return C

#using binary search to find the location p2-----------------------------------
def Binary_Search(A, B):
    mid_A = len(A)//2
    low = 0
    high = len(B)
    while low < high:
        mid = (low + high)//2
        if A[mid_A] <= B[mid]:
            high = mid
        else:
            low = mid + 1
    return high

#implement multithread merging-------------------------------------------------
def P_Merge(A, B, C, queue, process_num):
    if len(B) < len(A):
        P_Merge(B, A, queue, process_num)
        return
    if len(C) == 1:
        C[0] = A[0]
        return
    if len(A) == 1 and len(B) == 1:
        if A[0] < B[0]:
            C[0] = A[0]
            C[1] = B[0]
        else:
            C[0] = B[0]
            C[1] = A[0]
        return
    if process_num <= 0:
        queue.put(Merge(A, B))
        queue.close()
        return
    mid_A = len(A)//2
    mid_B = Binary_Search(A, B)
    print mid_A, mid_B
    process_left = Process(target = P_Merge, 
                         args = (A[:mid_A], B[:mid_B], C[:(mid_A + mid_B)], 
                                     queue, process_num - 1))
    process_left.start()
    process_right = Process(target = P_Merge, 
                         args = (A[mid_A:], B[mid_B:], C[(mid_A + mid_B):],
                                     queue, process_num - 1))
    process_right.start()
    queue.put(C)
        #assume n1 >= n2, then the base case is n1 = 0
        #using tuple swap two values
        #using binary search to find the location p2 
        #using multithreads to implemnt the recursive parallel merging
        #sync the multithread implementations
    queue.close()
    process_left.join()
    process_right.join()
    return

if __name__ == "__main__":
    arr = list()    #build a list storing the input arrays
    idx_n = list()      #build a list storing the size of the arrays
    idx_n = [10* 2 ** n for n in xrange(1)]
    aver_t1, aver_t2, aver_t3 = list(), list(), list()
    q1, q2 = Queue(), Queue()
    process_num = 3
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
            p1 = Process(target = Merge_Sort_Parallelsort, 
                             args = (arr, q1, process_num))
            p1.start()
            arr2 = q1.get()
            #print "Merge_Sort_Parallel:", arr2[:]
            p1.join()
            end2 = time.time()
            #arr3 = Array('i', arr)
            start3 = time.time()
            arr3 = P_Merge_Sort(arr, process_num)
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
    print arr, arr1, arr2, arr3
    plt.figure(1)
    plt.plot(aver_t1, idx_n)
    plt.hold("on")
    plt.xlabel("size")
    plt.ylabel("time")
    plt.title("merge sorts time efficiency camparison")
    plt.plot(aver_t2, idx_n)
    plt.plot(aver_t3, idx_n)
    #plt.legend("squential merge sort", "merge sort with parallel sort", 
     #              "parallel merge sort")
    plt.show()