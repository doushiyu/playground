# -*- coding: utf-8 -*-
"""
Created on Sat Sep 30 07:22:37 2017

@author: Jia
"""
from math import exp, sin, cos, log, pi
def diff(f, x, h = 1E-5):
    return (f(x + h) - f(x - h)) / float(2 * h)

def test_diff():
    #Verify the implamentation of the function diff by using the fact that
    #f(x) is 0.9x^2+0.6x+8.3
    F = lambda x: 0.9 * x ** 2 + 0.6 * x + 8.3
    f = lambda x: 1.8 * x + 0.6
    x = 2.2
    exact = f(x)
    approx = diff(F, x)
    success = abs(exact - approx) < 1.0e-9
    msg = "Error: Cannot differentiate the function exactly."
    print "Verify the implamentation of the function diff by using the fact "\
            "that f(x) is 0.9x^2+0.6x+8.3: the exaxt derivative of f(x) = %g, "\
            "the approximation = %g, the error = %g \n" % (exact, approx, 
                                                        abs(exact - approx))
    assert success, msg
    
def application():
    F_list = [lambda x: exp(x), lambda x: exp(-2 * x ** 2), lambda x: cos(x), 
         lambda x: log(x)]
    f_list = [lambda x: exp(x), lambda x: -4 * x * exp(-2 * x ** 2), 
         lambda x: -sin(x), lambda x: 1 / x]
    x = [0.0, 0.0, 2.0 * pi, 1.0]
    func_name = ['f(x) = e^x', 'f(x) = e^(-2x^2)', 'f(x) = cosx', 
                 'f(x) = lnx']
    print "%-16s %-16s %-16s %-10s" % ('Function', 'Approximation', 
                                       'Exact Value', 'Error')
    for i in xrange(4):
        approx = diff(F_list[i], x[i], h = 0.01)
        exact = f_list[i](x[i])
        error = abs(exact - approx)
        print "%-16s %-16.8f %-16.8f %-8.2e" % (func_name[i], approx, exact, error)
    
if __name__ == '__main__':
    test_diff()
    application()