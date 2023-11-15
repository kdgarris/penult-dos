#!/usr/bin/env python
import sys

SymbolNum = 0;

with open('dialog.txt') as DialogFile:
    for Line in DialogFile:
        Line = Line.strip()
        if Line:
            LineWords = Line.split()
            if LineWords[0] == "data":
                print("#define", LineWords[1].upper(), SymbolNum)
                SymbolNum += 1

print("\n\nconst char Messages[] = {")

with open('dialog.txt') as DialogFile:
    for Line in DialogFile:
        OutLine = ""
        Line = Line.strip()
        if Line:
            LineWords = Line.split()
            if LineWords[0][0] == "_":
                for Letter in LineWords:
                    Letter = Letter.strip("_,")
                    if len(Letter) == 1:
                        OutLine += Letter
                    elif Letter == "sp":
                        OutLine += " "
                    elif Letter == "ap":
                        OutLine += "'"
                    elif Letter == "qu":
                        OutLine += "?"
                    elif Letter == "cm":
                        OutLine += ","
                    elif Letter == "co":
                        OutLine += ":"
                    elif Letter == "hy":
                        OutLine += "-"
                    elif Letter == "eq":
                        OutLine += "="
                    elif Letter == "pd":
                        OutLine += "."
                    elif Letter == "ex":
                        OutLine += "!"
                    elif Letter == "sl":
                        OutLine += "/"
            if(OutLine):
                print('    "' + OutLine + '",')
print("};")

