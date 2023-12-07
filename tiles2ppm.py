#!/usr/bin/env python
import sys
import os

def oh_shit(CrashMessage):
    print(CrashMessage)
    sys.exit(1)

if len(sys.argv) != 3:
    oh_shit("Usage: " + sys.argv[0] + " <input filename> <output filename>")

InputFilename = sys.argv[1]
OutputFilename = sys.argv[2]


if not os.path.isfile(InputFilename):
    oh_shit("File not found: " + InputFilename)

NumTiles = 111

OutputBytes = bytearray()

with open(InputFilename, "rb") as TilesFile:
    TilesFile.read(8) # CGALIB Bitmap header
    for Tile in range(NumTiles):
        TilesFile.read(4) # Bitmap size bytes
        TileData = bytearray()
        TileData = TilesFile.read(64)
        for Byte in TileData:
            # masking and bit-shifting
            for Count in range(4):
                CurrentByte = (Byte&252) >> 6
                Byte <<= 2
                match CurrentByte:
                    case 0:
                        OutputBytes.extend(bytearray([0,0,0]))
                    case 1:
                        OutputBytes.extend(bytearray([0,255,255]))
                    case 2:
                        OutputBytes.extend(bytearray([255,0,0]))
                    case 3:
                        OutputBytes.extend(bytearray([255,255,255]))
                    case _:
                        oh_shit("Impossible value" + str(CurrentByte))


#    reader = csv.reader(CSVFile)
#    for row in reader:
#        for ByteString in row:
#            MyByte = int(ByteString).to_bytes(1, byteorder='big')
#            OutputBytes.append(MyByte[0])

Height = str(16 * NumTiles)
Header = bytes("P6\n16 " + Height + "\n255\n", "ascii")

with open(OutputFilename, "wb") as MapFile:
    MapFile.write(Header)
    MapFile.write(OutputBytes)