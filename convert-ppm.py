#!/usr/bin/env python
import sys
import os

def oh_shit(CrashMessage):
    print(CrashMessage)
    sys.exit(1)

if len(sys.argv) != 2:
    oh_shit("Usage: " + sys.argv[0] + " <PPM file>")

InputFilename = sys.argv[1]

if not os.path.isfile(InputFilename):
    oh_shit("File not found: " + InputFilename)

with open(InputFilename) as Infile:
    Lines = [Line.strip() for Line in Infile]

if Lines[-1] == "":
    Lines = Lines[:-1]

LineIndex = 0

if Lines[0] != "P3":
    oh_shit("Bad input file type (must be PPM ASCII format P3).")

LineIndex += 1

while Lines[LineIndex][0] == "#":
    LineIndex += 1

Resolution = Lines[LineIndex].split()

Width = int(Resolution[0])
Height = int(Resolution[1])

LineIndex += 1

while Lines[LineIndex][0] == "#":
    LineIndex += 1

MaxColors = Lines[LineIndex].split()

if int(MaxColors[0]) != 255:
    oh_shit("Wrong number of max colors" + MaxColors[0])


LineIndex += 1

while Lines[LineIndex][0] == "#":
    LineIndex += 1


if (len(Lines) - LineIndex) != (Width*Height*3):
    oh_shit("Wrong number of pixels in image.")

RGB = 0
CurrentWidth = 0
CurrentHeight = 0
RGBList = [0, 0, 0]

for CurrentLine in range(LineIndex, len(Lines)):
    RGBList[RGB] = int(Lines[CurrentLine])
    if RGB < 2:
        RGB += 1
    else:
        RGB = 0
        if (RGBList[0] == 255) and (RGBList[1] == 255) and (RGBList[2] == 255):
            ColorNumber = 3
        elif RGBList[0] == 255:
            ColorNumber = 2
        elif RGBList[1] == 255:
            ColorNumber = 1
        else:
            ColorNumber = 0

        print(ColorNumber, sep='', end='')

        CurrentWidth += 1
        if CurrentWidth == Width:
            CurrentWidth = 0
            CurrentHeight += 1
            print()


