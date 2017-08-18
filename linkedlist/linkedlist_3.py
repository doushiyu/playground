# -*- coding: utf-8 -*-

import random
from linkedlist_2 import LList, LinkedListUnderflow

class LList1(LList):
    def __init__(self):
        super(LList1, self).__init__()
        self._rear = None
        
    def prepend(self, elem):
        if self._head is None:
            self._head = LList.Lnode(elem, self._head)
            self._rear = self._head
        else:
            self._head = LList.Lnode(elem, self._head)
            
    def append(self, elem):
        if self._head is None:
            self._head = LList.Lnond(elem, self._head)
            self._rear = self._head
        else:
            self._rear.next = LList.Lnode(elem)
            self._rear = self._rear.next
            
    def pop_front(self):
        super(LList1, self).pop_front()
        
    def pop_last(self):
        if self._head is None:
            raise LinkedListUnderflow("in pop_last")
        p = self._head
        if p.next is None:
            e = p.elem
            self._head = None
            return e
        while p.next.next is not None:
            p = p.next
        e = p.next.elem
        p.next = None
        self._rear = p
        return e
        
if __name__ == '__main__':
    mlist1 = LList1()
    mlist1.prepend(99)
    for i in range(11, 20):    
        mlist1.append(random.randint(1,20))
    for x in mlist1.filter(lambda y: y % 2 == 1):
        print(x)

