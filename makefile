CC = wcc
LIB = cga-ms.lib
LD = wcl
COPTS = -I=..\cgalib\inc -I=..\keylib\inc -ms
LOPTS =
INCDIR = 
LIBDIR =
CGALIB = ../cgalib/cgalib/cga-ms.lib
KEYLIB = ../keylib/keylib/key-ms.lib

.c.obj
  wcc $(COPTS) $<


all : penult.exe

penult.exe: penult.obj gametxt.obj $(CGALIB) $(KEYLIB)
	$(LD) $(LOPTS) -fe=$@ $<