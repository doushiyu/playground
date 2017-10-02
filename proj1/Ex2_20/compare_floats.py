# -*- coding: utf-8 -*-
"""
Created on Thu Sep 28 10:32:12 2017

@author: Jia
"""
if __name__ == '__main__':
    a = 1/947.0*947
    b = 1
    tol = 1.0e-15
    msg = "Wrong Results!"
    assert abs(a-b) < tol, msg