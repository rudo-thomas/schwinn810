#CC=i586-mingw32msvc-gcc
#CXX=i586-mingw32msvc-g++
#LD=i586-mingw32msvc-ld
#DLLTOOL=i586-mingw32msvc-dlltool
CC=i686-w64-mingw32-gcc
DLLTOOL=i686-w64-mingw32-dlltool

all: SiUSBXp.dll test.exe

proxy.o: hexdump.h log.h SiUSBXp.h

hexdump.o: log.h

OBJECT_FILES = proxy.o hexdump.o log.o

CFLAGS=-D_WIN32_IE=0x0500 -Wall -Wpedantic

#-Wl,--output-def,my.def
# It is important to keep ordinals in def file
SiUSBXp.dll: ${OBJECT_FILES} SiUSBXp.def libSiUSBXp.a
	$(CC) -shared -Wl,--enable-stdcall-fixup -o $@ ${OBJECT_FILES} SiUSBXp.def -L. -lSiUSBXp

# libSiUSBXp.a # use this prereq only for direct linking tests
test.exe: test.o x86/SiUSBXp.lib SiUSBXp.h
	$(CC) -o $@ test.o x86/SiUSBXp.lib
# -L. -lsiusbxp # to link against renamed original
# x86/SiUSBXp.lib # to link against original name (proxy in fact)

libSiUSBXp.a: SiUSBXp_orig.def
	$(DLLTOOL) -d $^ -l $@ --kill-at

clean:
	rm -f SiUSBXp.dll test.exe libSiUSBXp.a ${OBJECT_FILES} test.o
