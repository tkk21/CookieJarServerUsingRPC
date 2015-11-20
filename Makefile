CC = gcc
CFLAGS = -g -Wall
LIBS = # None
TINASOURCE = Tina.c Cookie_clnt.c Cookie_xdr.c
JUDYSOURCE = Judy.c Cookie_clnt.c Cookie_xdr.c
MOTHERSOURCE = Mother.c Cookie_svc.c Cookie_xdr.c
RPCSRC = Cookie.x
RPCGEN = Cookie.h Cookie_clnt.c Cookie_svc.c Cookie_xdr.c
JUDY = judy
TINA = tina
MOTHER = mother


all: $(JUDY) $(TINA) $(MOTHER)

$(JUDY): $(JUDYSOURCE) $(RPCGEN)
	$(CC) $(LIBS) $(CFLAGS) -o $(JUDY) $(JUDYSOURCE)

$(TINA): $(TINASOURCE) $(RPCGEN)
	$(CC) $(LIBS) $(CFLAGS) -o $(TINA) $(TINASOURCE)

$(MOTHER): $(MOTHERSOURCE) $(RPCGEN)
	$(CC) $(LIBS) $(CFLAGS) -o $(MOTHER) $(MOTHERSOURCE)

$(RPCGEN): $(RPCSRC)
	rpcgen $(RPCSRC)

RPCGEN: $(RPCSRC)
	rpcgen $(RPCSRC)

clean:
	@# Using the '@' sign to supress echoing
	@# the line while the command is run
	rm -f $(JUDY) $(TINA) $(MOTHER) $(RPCGEN)
