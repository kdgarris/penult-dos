#!/usr/bin/env python

with open("et.txt") as ETFile:
    for Num in ETFile:
        print("    ", hex(int(Num, 2)), ",", sep="")