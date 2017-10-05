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
        _sum = 0 #XXX jma: don't use name "sum", it's a built-in function name
        for i in xrange(mid, low - 1, -1):
            _sum += A[i]
            if _sum > left_sum:
                left_sum = _sum
                left_low = i
        right_sum = float('-inf')
        _sum = 0
        #for j in xrange(mid + 1, high): #XXX issue 3: wrong iter range.
        for j in xrange(mid + 1, high + 1):
            _sum += A[j] #XXX issue 5, missing +
            if _sum > right_sum:
                right_sum = _sum
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
        if left_sum >= right_sum and left_sum >= cross_sum: #XXX issue 4, translate error
            return (left_low, left_high, left_sum)
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return (right_low, right_high, right_sum)
        else:
            return (cross_low, cross_high, cross_sum)

def test_effeciency(n):
    #XXX issue 1, extra bracket created a nested list
    #a1 = [[randint(-100, 100)] for i in xrange(n)]
    a1 = [randint(-100, 100) for i in xrange(n)]
    t0 = clock()
    low, high, bf_sum = find_max_subarray_brute_force(a1)
    t1 = clock()
    assert bf_sum == sum(a1[low:high+1])
    #XXX issue 2, IndexError, you'll need to figure out what's the range of
    # low and high, if it's index, len(a1) will be last idx + 1, and cause error
    #find_max_subarray_divide_and_conquer(a1, 0, len(a1))
    t2 = clock()
    low, high, dc_sum = find_max_subarray_divide_and_conquer(a1, 0, len(a1) - 1)
    t3 = clock()
    assert dc_sum == sum(a1[low:high+1]) == bf_sum
    return t1 - t0, t3 - t2

def table():
    print "%-8s, %-8s, %-8s,\t %s" % ('size', 'time of brute force',
                                 'time of divide and conquer', 'dc over bf')
    for n in xrange(1, 501):
        t_bf, t_dc = test_effeciency(n)
        print "%-16g, %-16g, %-10g, \t%10.2f%% %s" % \
                (n, t_bf, t_dc, t_dc/t_bf*100, ('<<<< bf is better?' if t_bf <= t_dc else ''))

if __name__ == '__main__':
    #XXX it would be much better to have doc-string for each function as well
    # as some important places, especially for those logic intense blocks.
    table()
