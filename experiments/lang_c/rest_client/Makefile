ARCH=x86
IDIR=include
ODIR=build\obj
BDIR=build\bin
LDIR=lib\windows\$(ARCH)
LINK=link.exe
CFLAGS=/Fo.\build\obj\ /Wall /I $(IDIR) /c

.c.obj:
	@if NOT EXIST "$(ODIR)" mkdir "$(ODIR)"
	$(CC) $(CFLAGS) *.c

rest-client.exe: rc_main.obj rc_helper.obj rc_utilities.obj
	@if NOT EXIST "$(BDIR)" mkdir "$(BDIR)"
	$(LINK) /incremental:no /libpath:"$(LDIR)" -out:$(BDIR)\rest-client.exe $(ODIR)\*.obj libcurl.lib
	@copy $(LDIR)\libcurl.dll $(BDIR)\

clean: .PHONY
	@if EXIST "build" rd /s /q build

.PHONY:
