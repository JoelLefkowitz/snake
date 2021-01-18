CC = g++
ODIR = obj
SDIR = src
OUT = output

INC = -Iinc
LIBS = -lSDL2

_OBJS = main.o draw.o utils.o colours.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(OUT)

.PHONY: clean 
.PHONY: format
clean:
	rm -f $(ODIR)/*.o $(OUT)

format:
	astyle --style=java --max-code-length=50    \
	--delete-empty-lines --break-closing-braces \
	--suffix=none src/*.cpp src/headers/*.hpp