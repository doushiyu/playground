# -*- coding: utf-8 -*-
"""
Created on Sat Sep 30 07:22:37 2017

@author: Jia
"""
from math import sin, pi
from itertools import product

FAULT_TOLERANCE = 1.0e-15

def S(t, n, T):
    s = 0
    for i in xrange(1, n + 1):
        term = 1.0 / (2 * i - 1) * sin(2 * (2 * i - 1) * pi * t / T)
        s += term
    s *= 4 / pi
    return s

def f(t, T):
    if 0 < t < T / float(2):
        f_t = 1
    elif abs(t - T / float(2)) < FAULT_TOLERANCE:
        f_t = 0
    elif T / float(2) < t < T:
        f_t = -1
    else:
        raise ValueError("Cannot find f(t) with the given arguments")
    return f_t

def table():
    T = 2 * pi
    print "T = 2 * pi, t = alpha * T:"
    print "%-6s %-6s %-10s %-10s %-10s" % ('alpha', 'n', 'the approximation',
                                        'the exact', 'the error')
    #for n in [1, 3, 5, 10, 30, 100]:
    #    for alpha in [0.01, 0.25, 0.49]:
    #XXX try to reduce unnecessary nested loops.
    for n, alpha in product([1, 3, 5, 10, 30, 100], [0.01, 0.25, 0.49]):
        t = alpha * T
        approx = S(t, n, T)
        exact = f(t, T)
        error = abs(exact - approx)
        print "%-6.2f %-8d %-18.8f %-8.2f %-10.2e" % (alpha, n, approx,
                exact, error)

if __name__ == '__main__':
    table()
