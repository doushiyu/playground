# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 23:14:11 2018

@author: sarah
"""

'''
==========================================================================
Python for Parallelism in Introductory Computer Science Education
SC '13 HPC Educators Program
Steven Bogaerts, Wittenberg University
Joshua Stough, Washington and Lee
http://www.joshuastough.com/SC13
MIT License: see README_LICENSE.txt


file: parallelMergesort.py
author: stough
Summary:$ python[3] parallelMergesort.py [500000]

This code uses a Pool of processes to first 
independently sort, then to independently merge.  
Mergesort says simply:
-sort the left side of the list.
-sort the right side of the list.
-merge the results.
But why only split it into two parts, since the
sorts are independent of one another? So.
-sort N independent sublists in parallel
-merge pairs of sorted sublists (also in parallel)
until there is only one left.

A single pool of processes is instantiated.  It first
performs mergesort, then merge.

This attempt was to find a parallel python sort whose 
performance was improved under windows.  

This mergesort is not standard; it is NlogN in memory,
and does not sort the argument lyst as a side effect,
but rather returns a sorted version of the lyst.

See:
http://docs.python.org/library/multiprocessing.html
http://docs.python.org/py3k/library/multiprocessing.html
==========================================================================
'''

from multiprocessing import Pool
import time, random, sys

#Dependencies defined below main()

def main():
    """
    This is the main method, where we:
    -generate a random list.
    -time a sequential mergesort on the list.
    -time a parallel mergesort on the list.
    -time Python's built-in sorted on the list.
    """
    N = 500000
    if len(sys.argv) > 1:  #the user input a list size.
        N = int(sys.argv[1])

    #We want to sort the same list, so make a backup.
    lystbck = [random.random() for x in range(N)]

    #Sequential mergesort a copy of the list.
    lyst = list(lystbck)
    start = time.time()             #start time
    lyst = mergesort(lyst)

    elapsed = time.time() - start   #stop time

    if not isSorted(lyst):
        print('Sequential mergesort did not sort. oops.')
    
    print('Sequential mergesort: %f sec' % (elapsed))


    #So that cpu usage shows a lull.
    time.sleep(3)


    #Now, parallel mergesort. 
    lyst = list(lystbck)
    start = time.time()
    n = 4 #2**(n+1) - 1 processes will be instantiated.

    #Instantiate a Process and send it the entire list,
    #along with a Pipe so that we can receive its response.
    lyst = mergeSortParallel(lyst, n)

    elapsed = time.time() - start

    if not isSorted(lyst):
        print('mergeSortParallel did not sort. oops.')

    print('Parallel mergesort: %f sec' % (elapsed))


    time.sleep(3)
    
    #Built-in test.
    #The underlying c code is obviously the fastest, but then
    #using a calculator is usually faster too.  That isn't the
    #point here obviously.
    lyst = list(lystbck)
    start = time.time()
    lyst = sorted(lyst)
    elapsed = time.time() - start
    print('Built-in sorted: %f sec' % (elapsed))


def merge(left, right):
    """returns a merged and sorted version of the two already-sorted lists."""
    ret = []
    li = ri = 0
    while li < len(left) and ri < len(right):
        if left[li] <= right[ri]:
            ret.append(left[li])
            li += 1
        else:
            ret.append(right[ri])
            ri += 1
    if li == len(left):
        ret.extend(right[ri:])
    else:
        ret.extend(left[li:])
    return ret

def mergesort(lyst):
    """
    The seemingly magical mergesort. Returns a sorted copy of lyst.
    Note this does not change the argument lyst.
    """
    if len(lyst) <= 1:
        return lyst
    ind = len(lyst)//2
    return merge(mergesort(lyst[:ind]), mergesort(lyst[ind:]))

def mergeWrap(AandB):
    a,b = AandB
    return merge(a,b)

def mergeSortParallel(lyst, n):
    """
    Attempt to get parallel mergesort faster in Windows.  There is
    something wrong with having one Process instantiate another.
    Looking at speedup.py, we get speedup by instantiating all the
    processes at the same level. 
    """
    numproc = 2**n
    #Evenly divide the lyst indices.
    endpoints = [int(x) for x in linspace(0, len(lyst), numproc+1)]
    #partition the lyst.
    args = [lyst[endpoints[i]:endpoints[i+1]] for i in range(numproc)]

	#instantiate a Pool of workers
    pool = Pool(processes = numproc)
    sortedsublists = pool.map(mergesort, args)
	#i.e., perform mergesort on the first 1/numproc of the lyst, 
	#the second 1/numproc of the lyst, etc.

    #Now we have a bunch of sorted sublists.  while there is more than
    #one, combine them with merge.
    while len(sortedsublists) > 1:
        #get sorted sublist pairs to send to merge
        args = [(sortedsublists[i], sortedsublists[i+1]) \
				for i in range(0, len(sortedsublists), 2)]
        sortedsublists = pool.map(mergeWrap, args)

	#Since we start with numproc a power of two, there will always be an 
	#even number of sorted sublists to pair up, until there is only one.

    return sortedsublists[0]
    

    
def linspace(a,b,nsteps):
    """
    returns list of simple linear steps from a to b in nsteps.
    """
    ssize = float(b-a)/(nsteps-1)
    return [a + i*ssize for i in range(nsteps)]


def isSorted(lyst):
    """
    Return whether the argument lyst is in non-decreasing order.
    """
    #Cute list comprehension way that doesn't short-circuit.
    #return len([x for x in
    #            [a - b for a,b in zip(lyst[1:], lyst[0:-1])]
    #            if x < 0]) == 0
    for i in range(1, len(lyst)):
        if lyst[i] < lyst[i-1]:
            return False
    return True

#Execute the main method now that all the dependencies
#have been defined.
#The if __name is so that pydoc works and we can still run
#on the command line.
if __name__ == '__main__':
    main()