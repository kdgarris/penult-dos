#!/usr/bin/env python

import random
random.seed()

Rows = 12
LineLength = 8


for Row in range(Rows):
    print("    '", end="")
    for Cols in range(LineLength):
        print(chr(random.randrange(4)+97), ", ", sep="", end="")
    print("'")