#!/usr/bin/env python
import sys

ChunkNum = 0
XStart = 0
YStart = 0

pd0 = open("pd0.txt", "r")
pd1 = open("pd1.txt", "r")
pd2 = open("pd2.txt", "r")
pd3 = open("pd3.txt", "r")
pd4 = open("pd4.txt", "r")
pd5 = open("pd5.txt", "r")

for Count in range(27):
    Line = pd0.readline().strip()
    Line += pd1.readline().strip()
    Line += pd2.readline().strip()
    Line += pd3.readline().strip()
    Line += pd4.readline().strip()
    Line += pd5.readline().strip()
    print(Line)

pd0.close()
pd1.close()
pd2.close()
pd3.close()
pd4.close()
pd5.close()

# with open('penult-data.txt') as DataFile:
#     for Line in DataFile:
#         Line = Line.strip()
#         if Line:
#             LineWords = Line.split()
#             if LineWords[0] == "data":
#                 print("#define", LineWords[1].upper(), SymbolNum)
#                 SymbolNum += 1

# print("\n\nconst char Messages[] = {")

# with open('dialog.txt') as DialogFile:
#     for Line in DialogFile:
#         OutLine = ""
#         Line = Line.strip()
#         if Line:
#             LineWords = Line.split()
#             if LineWords[0][0] == "_":
#                 for Letter in LineWords:
#                     Letter = Letter.strip("_,")
#                     if len(Letter) == 1:
#                         OutLine += Letter
#                     elif Letter == "sp":
#                         OutLine += " "
#                     elif Letter == "ap":
#                         OutLine += "'"
#                     elif Letter == "qu":
#                         OutLine += "?"
#                     elif Letter == "cm":
#                         OutLine += ","
#                     elif Letter == "co":
#                         OutLine += ":"
#                     elif Letter == "hy":
#                         OutLine += "-"
#                     elif Letter == "eq":
#                         OutLine += "="
#                     elif Letter == "pd":
#                         OutLine += "."
#                     elif Letter == "ex":
#                         OutLine += "!"
#                     elif Letter == "sl":
#                         OutLine += "/"
#             if(OutLine):
#                 print('    "' + OutLine + '",')
# print("};")

