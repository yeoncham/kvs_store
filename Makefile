SRCS = main.c
LIBSRCS = open.c close.c put.c get.c randLevel.c
TARG = kvs_static
TARG_DYNAMIC = kvs_dynamic
CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs
OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
LARSO = libkvs.so

all: 

static: $(TARG)

$(TARG): $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) -static

$(LARS): $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

dynamic: $(TARG_DYNAMIC)

$(TARG_DYNAMIC): $(OBJS) $(LARSO)
	$(CC) -o $(TARG_DYNAMIC) $(OBJS) $(LIBS)

$(LARSO): $(LOBJS)
	$(CC) -shared -o $(LARSO) $(LOBJS)

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(LARSO) $(TARG) $(TARG_DYNAMIC)

