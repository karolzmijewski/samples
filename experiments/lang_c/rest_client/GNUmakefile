IDIR=./include
ODIR=./build/obj
BDIR=./build/bin
LDIR=./lib/linux
LIBS=-L$(LDIR) -lcurl
CC=gcc
CFLAGS=-Wall -I$(IDIR)

_DEPS = rc_helper.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = rc_main.o rc_helper.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/rest-client: $(OBJ)
	@mkdir -p $(BDIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@cp $(LDIR)/*.so $(BDIR)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(BDIR)/*