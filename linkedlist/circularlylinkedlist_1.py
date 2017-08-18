# -*- coding: utf-8 -*-


class LinkedListUnderflow(ValueError):
    pass

class CLList(object):
    class LNode(object):
        def __init__(self, elem, next_nd=None):
            self.elem = elem
            self.next = next_nd
        
    def __init__(self):
        self._rear = None
    
    def is_empty(self):
        return self._rear is None
    
    def prepend(self, elem):
        p = CLList.LNode(elem)
        if self._rear is None:
            p.next = p
            self._rear = p
        else:
            p.next = self._rear.next
            self._rear.next = p
            
    def append(self, elem):
        self.prepend(elem)
        self._rear = self._rear.next
        
    def pop_front(self):
        if self._rear is None:
            raise LinkedListUnderflow("in pop_front of CLList")
        p = self._rear.next
        if self._rear is p:
            self._rear = None
        else:
            self._rear.next = p.next
        return p.elem
    
    def printall(self):
        if self.is_empty():
            return
        p = self._rear.next
        list1 = []
        while True:
            list1.append(p.elem) 
            if p is self._rear:
                print list1
                break
            p = p.next
            
    def __len__(self):
        if self._rear is None:
            raise LinkedListUnderflow("in __len__")
        p, n = self._rear.next, 0
        while True:
            n += 1
            if p is self._rear:
                break
            p = p.next
        return n    
            
    def is_loop(self):
            if self._rear == None:
                raise LinkedListUnderflow("in is_loop")
            p = self._rear.next
            q = p
            for j in range(self.__len__()):
                i = self.__len__() - j
                while i > 0:
                    if p.next == q:
                        return p.next is q
                    i -= 1
                    p = p.next
                q = q.next
                p = q
            return False        
        
if __name__ == '__main__':
    mlist1 = CLList()
    mlist1.printall
    for i in range(10):
        mlist1.prepend(i)
    mlist1.printall()
    for i in range(11, 20):
        mlist1.append(i)
    mlist1.printall()
    print 'The length is {}.'.format(len(mlist1))
    print mlist1.is_loop()
    
