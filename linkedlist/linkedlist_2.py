# -*- coding: utf-8 -*-

from __future__ import print_function
        
class LinkedListUnderflow(ValueError):
    pass
        
class LList(object):
    
    class Lnode(object): 
        def __init__(self, elem, next_nd=None):
            self.elem = elem
            self.next = next_nd
                        
    def __init__(self):
        self._head = None
        
    def is_empty(self):
        return self._head is None
    
    def prepend(self, elem):
        self._head = LList.Lnode(elem, self._head)
        
    def pop_front(self):
        if self._head is None:
            raise LinkedListUnderflow("in pop_front")
            #raise ValueError("in pop")
        e = self._head.elem
        self._head = self._head.next
        return e
    
    def append(self, elem):
        if self._head is None:
            self._head = LList.Lnode(elem)
            return
        p = self._head
        while p.next is not None:
            p = p.next
        p.next = LList.Lnode(elem)
        
    def pop_last(self):
        if self._head is None:
            raise LinkedListUnderflow("in pop_last")
        p =  self._head
        if p.next is None:
            e = p.elem
            self._head = None
            return e
        while p.next.next is not None:
            p = p.next
        e = p.next.elem
        p.next = None
        return e
    
    def find(self, pred):
        p = self._head
        while p is not None:
            if pred(p.elem):
                return p.elem
            p = p.next
            
    def printall(self):
        p = self._head
        while p is not None:
            print(p.elem, end='')
            if p.next is not None:
                print(', ', end='')
            p = p.next
        print('')
        
    def for_each(self, proc):
        p = self._head
        while p is not None:
            proc(p.elem)
            p = p.next
            
    def elements(self):
        p = self._head
        while p is not None:
            yield p.elem
            p = p.next  
        
    def filter(self, pred):
        p = self._head
        while p is not None:
            if pred(p.elem):
                yield p.elem
            p = p.next
            
    def insert(self, index, elem):
        if self._head is None:
            self._head = LList.Lnode(elem)
            self._head.next = None
        elif  index == 0:         
            q = LList.Lnode(elem)
            q.next = self._head
            self._head = q
        else:
            i = index-1
            p = self._head
            while p is not None and i > 0:
                i -= 1
                p = p.next
            if p is None:
                raise LinkedListUnderflow("in insert")
            q = LList.Lnode(elem)
            q.next = p.next
            p.next = q
    
    def delete(self, index):
        if self._head is None:
            raise LinkedListUnderflow("in delete")
        p = self._head
        if index == 0:
            self._head = self._head.next
        else:
            i = index-1
            while p is not None and i > 0:
                i -= 1
                p = p.next
            if p is None:
                raise LinkedListUnderflow("in delete")
            p.next = p.next.next
            
    def __len__(self):
        if self._head is None:
            raise LinkedListUnderflow("in __len__")
        p, n = self._head, 0
        while p is not None:
            n += 1
            p = p.next
        return n
        
    def is_loop(self):
        if self._head == None:
            raise LinkedListUnderflow("in is_loop")
        slow_p = self._head
        fast_p = self._head
        while slow_p and fast_p and fast_p.next:
            slow_p = slow_p.next
            fast_p = fast_p.next.next
            if slow_p == fast_p:
                    return slow_p is fast_p
        return False
        
if __name__ == "__main__": 
    mlist1 = LList()      
    mlist1.insert(0,1)
    mlist1.printall()
    print('length = %d' % len(mlist1))
    for i in range(10):
        mlist1.prepend(i)
    mlist1.printall()
    print('length = %d' % len(mlist1))
    for i in range(11,20):
        mlist1.append(i)
    mlist1.printall()
    print('length = %d' % len(mlist1))
    mlist1.insert(0,10)
    mlist1.printall()
    print('length = %d' % len(mlist1))
    mlist1.delete(0)
    mlist1.printall()
    print('length = %d' % len(mlist1))
    print(mlist1.is_loop())

    

