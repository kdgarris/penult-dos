#!/usr/bin/env python

OutputBytes = bytearray()
Count = 0

with open('npc.txt') as NPCFile:
    for Line in NPCFile:
        print("#define", Line.split()[0].upper(), Count)
        Count += 1
