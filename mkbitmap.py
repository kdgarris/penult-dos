#!/usr/bin/env python
import sys
import os
bitmap_header = bytearray("CGA100B", "ascii") + bytearray([0])
if len(sys.argv) != 3:
    print("Usage: " + sys.argv[0] + " inputfile outputfile")
    sys.exit(1)

InputFilename = sys.argv[1]
OutputFilename = sys.argv[2]

if not os.path.isfile(InputFilename):
    print("Cannot open " + InputFilename + " for reading.")
    sys.exit(1)

if os.path.isfile(OutputFilename):
    NewFile = False
else:
    NewFile = True

with open(OutputFilename, 'ba+') as Outfile:
    if NewFile:
        Outfile.write(bitmap_header)

with open(InputFilename) as Infile:
    Lines = [Line.rstrip() for Line in Infile]

if not len(Lines):
    print("Empty input file", InputFilename)
    sys.exit(1)
if Lines[-1] == "":
    Lines = Lines[:-1]
Height = len(Lines)
if Height % 2:
    print(InputFilename + "Bitmap has", Height, "lines; must be an even number.")
    sys.exit(1)
Width = len(Lines[0])
if Width % 4:
    print(InputFilename + "Bitmap has", Width, "width; must be divisible by 4.")
    sys.exit(1)
for Line in Lines:
    if len(Line) != Width:
        print("Line width does not match:")
        print(Line)
        sys.exit(1)
    CheckString = set(Line)
    if not CheckString.issubset(set('0123')):
        print("Invalid data:")
        print(Line)
        sys.exit(1)

BitmapHeader = bytearray([Width,0,Height,0])

BitmapData = bytearray()

for Line in Lines:
    RemainingWidth = Width
    CurrentByte = 0
    LineOffset = 0
    while RemainingWidth:
        RemainingWidth -= 4
        CurrentByte = int(Line[3 + LineOffset]) + (int(Line[2 + LineOffset]) << 2) + (int(Line[1 + LineOffset]) << 4) + (int(Line[0 + LineOffset]) << 6)
        BitmapData.append(CurrentByte)
        LineOffset += 4

with open(OutputFilename, 'ba+') as Outfile:
    Outfile.write(BitmapHeader + BitmapData)
