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
            cur_sum += A[j]
            if cur_sum > max_sum:
                max_sum = cur_sum
                low = i
                high = j
    return (low, high, max_sum)

def find_max_subarray_divide_and_conquer(A, low, high):
    def find_cross_max_subarray(A, low, mid, high):
        left_sum = float('-inf')
        cur_sum = 0
        for i in xrange(mid, low - 1, -1):
            cur_sum += A[i]
            if cur_sum > left_sum:
                left_sum = cur_sum
                left_low = i
        right_sum = float('-inf')
        cur_sum = 0
        for j in xrange(mid + 1, high + 1):
            cur_sum += A[j]
            if cur_sum > right_sum:
                right_sum = cur_sum
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
        if left_sum >= right_sum and left_sum >= cross_sum:
            return (left_low, left_high, left_sum)
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return (right_low, right_high, right_sum)
        else:
            return (cross_low, cross_high, cross_sum)

def test_effeciency(n):
    a1 = [randint(-100, 100) for i in xrange(n)]
    t0 = clock()
    low_bf, high_bf, max_sum_bf = find_max_subarray_brute_force(a1)
    t1 = clock()
    low_dc, high_dc, max_sum_dc = \
    find_max_subarray_divide_and_conquer(a1, 0, len(a1) - 1)
    t2 = clock()
    if n < 78:
        low_bf, high_bf, max_sum_bf = find_max_subarray_brute_force(a1)
    else:
        low_dc, high_dc, max_sum_dc = \
        find_max_subarray_divide_and_conquer(a1, 0, len(a1) - 1)
    t3 = clock()
    return t1 - t0, t2 - t1, t3 - t2 

def table():
    print "%-6s| %-10s| %-8s| %-8s" % ('size', 'ratio bf over comb', 
                                 'ratio dc over comb', 
                                 'ratio bf over dc')
    for n in xrange(1, 201):
        t_bf, t_dc, t_comb = test_effeciency(n)
        print "%-5g %10.2f%% %16.2f%% %20.2f%%" % (n, t_bf / t_comb * 100,
                                                      t_dc / t_comb * 100,
                                                      t_bf / t_dc * 100)
           
if __name__ == '__main__':
    table()


        