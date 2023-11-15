#!/usr/bin/env python
import sys
import os

def oh_shit(CrashMessage):
    print(CrashMessage)
    sys.exit(1)

if len(sys.argv) != 3:
    oh_shit("Usage: " + sys.argv[0] + " <dungeon raw map> <output filename>")

InputFilename = sys.argv[1]
OutputFilename = sys.argv[2]

if not os.path.isfile(InputFilename):
    oh_shit("File not found: " + InputFilename)

with open(InputFilename) as Infile:
    Lines = [Line.strip() for Line in Infile]

if Lines[-1] == "":
    Lines = Lines[:-1]

with open(OutputFilename, 'ba+') as Outfile:
    for Line in Lines:
        for Byte in range(0, 16):
            Outfile.write(bytes([int(Line[Byte], 16)]))
