#!/usr/bin/env python

import string

MIN_GRP_UPDATE = 20

def normalize_word(wrd):
    wrd.strip().lower()
    if wrd[-1] in string.punctuation:
        wrd = wrd[:-1]
    return wrd

def line_mapper(line):
    line_dict = {}
    for wrd in line.split():
        wrd = normalize_word(wrd)
        if not wrd.isalpha():
            continue
        if line_dict.has_key(wrd):
            line_dict[wrd] += 1
        else:
            line_dict[wrd] = 1
    return line_dict


def mapper(fpath):
    with open(fpath, 'r') as fobj:
        group_dict = {}
        for line in fobj:
            for wrd, frq in line_mapper(line).iteritems():
                if group_dict.has_key(wrd):
                    group_dict[wrd] += frq
                else:
                    group_dict[wrd] = frq
            if len(group_dict.keys()) > MIN_GRP_UPDATE:
                yield group_dict
                group_dict = {}

