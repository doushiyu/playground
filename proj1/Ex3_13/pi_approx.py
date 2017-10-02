# -*- coding: utf-8 -*-
"""
Created on Sat Sep 30 04:08:20 2017

@author: Jia
"""

from math import sqrt, pow, pi, cos, sin

def pathlength(x, y):
    assert len(x) == len(y)
    def get_delta(lst):
        for ni, cur_e in enumerate(lst[:-1], 1):
            yield (lst[ni] - cur_e)

    L = 0
    for dx, dy in zip(get_delta(x), get_delta(y)):
        term = sqrt(pow(dx, 2) + pow(dy, 2))
        #term = sqrt(pow((x[i] - x[i-1]), 2) + pow((y[i] - y[i-1]), 2))
        L += term
    return L

if __name__ == '__main__':
    for k in xrange(2, 11):
        n = int(pow(2, k))
        x = [(1.0 / 2 * cos(2 * pi * i / n)) for i in xrange(n+1)]
        y = [(1.0 / 2 * sin(2 * pi * i / n)) for i in xrange(n+1)]
        approx_pi = pathlength(x, y) / (1.0 / 2 * 2)
        print "n = %-4d, the approximate pi = %-4.8f, the error = %-4.2e" % (n,
                 approx_pi, abs(pi - approx_pi))
