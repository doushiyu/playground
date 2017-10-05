# -*- coding: utf-8 -*-
"""
Created on Wed Oct 04 18:03:04 2017

@author: Jia
"""
from random import randint
from time import clock

def find_max_subarray_brute_force(A):
    max_sum = float('-inf')
    for i in xrange(len(A)):
        cur_sum = 0
        for j in xrange(i, len(A)):
            cur_sum = cur_sum + A[j]
            if cur_sum > max_sum:
                max_sum = cur_sum
                low = i
                high = j
    return (low, high, max_sum)
                
def find_max_subarray_divide_and_conquer(A, low, high):
    def find_cross_max_subarray(A, low, mid, high):
        left_sum = float('-inf')
        sum = 0
        for i in xrange(mid, low - 1, -1):
            sum += A[i]
            if sum > left_sum:
                left_sum = sum
                left_low = i
        right_sum = float('-inf')
        sum = 0
        for j in xrange(mid + 1, high):
            sum = A[j]
            if sum > right_sum:
                right_sum = sum
                right_high = j
        return (left_low, right_high, left_sum + right_sum)
    if low == high:
        return (low, high, A[low])
    else:      
        mid = (low + high) // 2
        (left_low, left_high, left_sum) = \
            find_max_subarray_divide_and_conquer(A, low, mid)
        (right_low, right_high, right_sum) = \
            find_max_subarray_divide_and_conquer(A, mid + 1, high)
        (cross_low, cross_high, cross_sum) = \
            find_cross_max_subarray(A, low, mid, high)
        if left_sum > right_sum and left_sum > cross_sum:
            return (left_low, left_high, left_sum)
        elif right_sum > left_sum and right_sum > cross_sum:
            return (right_low, right_high, right_sum)
        else:
            return (cross_low, cross_high, cross_sum)
        
def test_effeciency(n):
    a1 = [[randint(-100, 100)] for i in xrange(n)]
    t0 = clock()
    find_max_subarray_brute_force(a1)
    t1 = clock()
    find_max_subarray_divide_and_conquer(a1, 0, len(a1))
    t2 = clock()
    return t1 - t0, t2 - t1

def table():
    print "%-8s, %-8s, %-8s," % ('size', 'time of brute force', 
                                 'time of divide and conquer')
    for n in xrange(1, 101):
        t_bf, t_dc = test_effeciency(n)
        print "%-16g, %-16g, %-10g" % (n, t_bf, t_dc)
           
if __name__ == '__main__':
    table()


        