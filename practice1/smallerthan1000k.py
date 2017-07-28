# -*- coding: utf-8 -*-
"""
Created on Tue Jul 25 20:42:39 2017

@author: sarah
"""
n=[]
for i in range (1,10000000,10):
    
    if (i%7 == 0 and i%9 == 0 and i%8 == 1):
        n.append(i)
print n
        