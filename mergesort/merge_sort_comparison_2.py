# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 16:00:36 2018

@author: sarah
"""
#from math import floor
from multiprocessing import Process, Array, Queue
import os
import time
import numpy as np
import math
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
def Merge_Sort_Parallelsort(A, queue, proc_log2):
    if len(A) <= 1 or proc_log2 <= 0:
        queue.put(Merge_Sort(A))
        queue.close()
        return
    queue_left = Queue()
    queue_right = Queue()
    mid = len(A)//2        #find the median of the array
    #using multithreads to implement recursive merge sort
    process_left = Process(target = Merge_Sort_Parallelsort, args = (A[:mid],
                     queue_left, proc_log2 - 1))
    process_left.start()
    process_right = Process(target = Merge_Sort_Parallelsort, args = (A[mid:],
                     queue_right, proc_log2 - 1))
    process_right.start()
    queue.put(Merge(queue_left.get(), queue_right.get()))
    queue.close()
    #print 'MSP:', t1.pid, t2.pid
    #sync the multithread process
    process_left.join()
    process_right.join()
    #using the same merging as the squential merge sort

#implemnt merge sort with multithreads-----------------------------------------
def P_Merge_Sort(A, proc_log2):
    #if len(A) <= 17 or proc_log2 <= 0:
        #C = Merge_Sort(A)
        #return C
    # logging queue, just for logging purpose
    lq = Queue()
    queue_left = Queue()
    queue_right = Queue()
    mid = len(A)//2        #find the median of the array
    if mid <= 17 or proc_log2 <= 0:
        leftarr = Merge_Sort(A[:mid])
        rightarr = Merge_Sort(A[mid:])
        C = A[:]
        queue_merge = Queue()
        #print '>%d' % os.getpid(), leftarr, rightarr
        process_merge = Process(target=P_Merge, args=(leftarr,
                         rightarr, C, queue_merge, 3, lq))
        process_merge.start()
        C = queue_merge.get()
    else:
        #using multithreads to implement recursive merge sort
        process_left = Process(target=Merge_Sort_Parallelsort, args=(A[:mid],
                         queue_left, proc_log2 - 1))
        process_left.start()
        process_right = Process(target=Merge_Sort_Parallelsort, args=(A[mid:],
                         queue_right, proc_log2 - 1))
        process_right.start()
        C = A[:]
        queue_merge = Queue()
        ql, qr = queue_left.get(), queue_right.get()
        #print '>%d' % os.getpid(), ql, qr
        process_merge = Process(target=P_Merge, args=(ql, qr, C, queue_merge, proc_log2, lq))
        process_merge.start()
        C = queue_merge.get()
        queue_left.close()
        queue_right.close()
        queue_merge.close()
        #print 'MSP:', t1.pid, t2.pid
        #sync the multithread process
        process_left.join()
        process_right.join()
        #using the same merging as the squential merge sort
    process_merge.join()
    #N = 0
    #proc_map = dict()
    #while not lq.empty():
    #    ppid, pids, d = lq.get_nowait()
    #    proc_map[ppid] = d if pids is None else pids
    #    N += d
    #print ">>>>>>>>>>", N
    #import pprint; pprint.pprint(proc_map)
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
def P_Merge(A, B, C, queue, proc_log2, lq):
    #print '>>%d' % os.getpid(), A, B, C, queue, proc_log2
    if len(B) > len(A):
        P_Merge(B, A, C, queue, proc_log2, lq)
        return
    if len(C) == 1:
        C[0] = A[0]
        queue.put(C)
        queue.close()
        lq.put((os.getpid(), None, 1));lq.close()
        #print '>>%d(1)--> ' % os.getpid(), C
        return
    if len(A) == 1 and len(B) == 1:
        if A[0] <= B[0]:
            C[0] = A[0]
            C[1] = B[0]
        else:
            C[0] = B[0]
            C[1] = A[0]
        queue.put(C)
        queue.close()
        lq.put((os.getpid(), None, 2));lq.close()
        #print '>>%d(2)--> ' % os.getpid(), C
        return
    if proc_log2 <= 0:
        C = Merge(A,B)
        queue.put(C)
        #print '>>%d(3)--> ' % os.getpid(), C
        queue.close()
        lq.put((os.getpid(), None, len(C)));lq.close()
        return
    mid_A = len(A)//2
    mid_B = Binary_Search(A, B)
    #print '>>%d' % os.getpid(), mid_A, mid_B
    ql, qr = Queue(), Queue()
    process_left = Process(target=P_Merge,
                         args=(A[:mid_A], B[:mid_B], C[:(mid_A + mid_B)],
                                     ql, proc_log2 - 1, lq))
    process_left.start()
    process_right = Process(target=P_Merge,
                         args=(A[mid_A:], B[mid_B:], C[(mid_A + mid_B):],
                                     qr, proc_log2 - 1, lq))
    process_right.start()
    cl, cr = ql.get(), qr.get()
    #print '>>%d' % os.getpid(), cl, cr
        #assume n1 >= n2, then the base case is n1 = 0
        #using tuple swap two values
        #using binary search to find the location p2
        #using multithreads to implemnt the recursive parallel merging
        #sync the multithread implementations
    C = cl + cr
    queue.put(C)
    #print '>>%d(4)--> ' % os.getpid(), C
    queue.close()
    lq.put((os.getpid(), (process_left.pid, process_right.pid), 0))
    lq.close()
    process_left.join()
    process_right.join()
    return

if __name__ == "__main__":
    #idx_n = [10 * 2**n for n in xrange(10)]
    idx_n = [100000 * n for n in xrange(1, 10, 2)]
    #idx_n = [1000000]
    #idx_n = [100]
    aver_t1, aver_t2, aver_t3 = list(), list(), list()
    q1 = Queue()
    max_num_proc = 3
    proc_log2 = int(math.log(max_num_proc, 2))
    for counter,idx in enumerate(idx_n):
        #arr = list(np.random.randint(0, 101, idx))
        arr = list(np.random.randint(0, 100001, idx))
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
            p1 = Process(target=Merge_Sort_Parallelsort,
                    args=(arr, q1, proc_log2))
            p1.start()
            arr2 = q1.get()
            #print "Merge_Sort_Parallel:", arr2[:]
            p1.join()
            end2 = time.time()
            #arr3 = Array('i', arr)
            start3 = time.time()
            arr3 = P_Merge_Sort(arr, proc_log2)
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
    print '>', arr[:3], '...', arr[-3:], idx_n
    print '<', arr1[:3], '...', arr1[-3:], aver_t1
    print '<', arr2[:3], '...', arr2[-3:], aver_t2
    print '<', arr3[:3], '...', arr3[-3:], aver_t3
    plt.figure(1)
    plt.plot(idx_n, aver_t1)
    plt.hold("on")
    plt.xlabel("size")
    plt.ylabel("time")
    plt.title("merge sorts time efficiency camparison")
    plt.plot(idx_n, aver_t2)
    plt.plot(idx_n, aver_t3)
    plt.legend(["squential merge sort", "merge sort with parallel sort",
            "parallel merge sort"])
    plt.show()
