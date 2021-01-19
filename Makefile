CC = g++
ODIR = obj
SDIR = src
OUT = snake
INC = -Iinc
LIBS = -lSDL2

SRCS = $(wildcard $(SDIR)/*.cpp)
OBJS = $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRCS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(OUT)

.PHONY: clean 
.PHONY: format

clean:
	rm -f $(ODIR)/*.o $(OUT)

format:
	astyle                       \
	--style=java                 \
	--max-code-length=88         \
	--delete-empty-lines         \
	--break-closing-braces       \
	--suffix=none                \
	--indent-switches            \
	--indent-cases               \
	--break-blocks               \
	--max-continuation-indent=50 \
	src/*.cpp src/headers/*.hpp 
