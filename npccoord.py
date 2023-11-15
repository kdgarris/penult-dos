#!/usr/bin/env python

with open('npccoord.txt') as NPCFile:
    for Line in NPCFile:
        if Line[0] != " ":
            print(Line)
            continue
        SplitLine = Line.split()
        if len(SplitLine) < 3:
            continue
        Coords = SplitLine[1].split(",")
        XCoord = int(Coords[0]) + 5
        if XCoord > 255:
            XCoord -= 256
        YCoord = int(Coords[1]) + 3
        if YCoord > 255:
            YCoord -= 256
        Name = SplitLine[2].upper()
        print("    {", XCoord, ", ", YCoord, ", ", Name, "},", sep='')
