# -*- coding: utf-8 -*-
"""
Created on Tue Jul 25 20:42:39 2017

@author: sarah
"""
import time

def f(intrange):
    n=[]
    for i in range(1,intrange,10):
        if (i%7 != 0):
            continue
        elif (i%9 != 0):
            continue
        elif (i%8 != 1):
            continue
        else:
            n.append(i)
    #if len(n) == 0:
    if not n:
      print "There is no valid integer in the range."
    else:
      print n
      with open ('./aaa.txt', 'a') as fobj:
          tm = time.localtime()
          fobj.write(time.strftime("%a, %d %b %Y %H:%M:%S\n",tm))
          for i in range(len(n)):
              fobj.write("%d: %d\n" % (i+1, n[i]))

if __name__ == '__main__':
    a1 = eval(raw_input('input the range:'))
    f(a1)

