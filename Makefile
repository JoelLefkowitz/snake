CC = g++
ODIR = obj
SDIR = src
OUT = output
INC = -Iinc

_OBJS = main.o init.o input.o draw.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT)
