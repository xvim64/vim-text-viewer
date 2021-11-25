CC =cl
CFLAGS =/W4 /WX /LD /Zi /Oy- # highest warning level; treat warnings as errors; enable dbg info
DEBUG_FLAGS=/Od /Ob0 /D "_DEBUG"
RELEASE_FLAGS =/O2 /Ob2 /D "NDEBUG"
LIBS =user32.lib gdi32.lib

all: clean release

release: gvimfullscreen.c
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) $(LIBS) gvimfullscreen.c

debug: gvimfullscreen.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) gvimfullscreen.c

clean:
	del *.obj
	del *.exp
	del *.lib
	del *.pdb
	del *.ilk

distclean: clean
	del *.dll
