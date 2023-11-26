#!/usr/bin/env python
import csv

OutputBytes = bytearray()

with open('castleb.csv', newline='') as CSVFile:
    reader = csv.reader(CSVFile)
    for row in reader:
        for ByteString in row:
            MyByte = int(ByteString).to_bytes(1, byteorder='big')
            OutputBytes.append(MyByte[0])

with open('castleb.map', "wb") as MapFile:
    MapFile.write(OutputBytes)