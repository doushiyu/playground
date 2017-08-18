#!/usr/bin/env python

import pprint

from mapper import mapper

all_dict = {}

def reducer(group_dict):
    for wrd, frq in group_dict.iteritems():
        # grab lock
        if all_dict.has_key(wrd):
            all_dict[wrd] += frq
        else:
            all_dict[wrd] = frq
        # release lock

def reverse_dict(src_dict):
    rev_dict = {}
    for w, f in all_dict.iteritems():
        if rev_dict.has_key(f):
            rev_dict[f].append(w)
        else:
            rev_dict[f] = [w]
    return rev_dict

if __name__ == '__main__':
    for grp_dict in mapper('C:/Users/sarah/Python/practice/The Hunger Games.'
                           'txt'):
        reducer(grp_dict)

    freq_wrd = reverse_dict(all_dict)
    #pprint.pprint(all_dict)
    #pprint.pprint(freq_wrd)

    x = 60
    topx = sorted(freq_wrd.keys(), reverse=True)[:x]
    for i in topx:
        print "%s:  \t%s" % (freq_wrd[i], i)

