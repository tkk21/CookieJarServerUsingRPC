CC = gcc
CFLAGS = -g -Wall
LIBS = # None
CSOURCE =
SSOURCE =
RPCSRC =
RPCGEN =
CLIENT = 
SERVER = 

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CSOURCE) $(RPCGEN)
	$(CC) $(LIBS) $(CFLAGS) -o $(CLIENT) $(CSOURCE)

$(SERVER): $(SSOURCE) $(RPCGEN)
	$(CC) $(LIBS) $(CFLAGS) -o $(SERVER) $(SSOURCE)

$(RPCGEN): $(RPCSRC)
	rpcgen $(RPCSRC)

clean:
	@# Using the '@' sign to supress echoing
	@# the line while the command is run
	rm -f $(CLIENT) $(SERVER) $(RPCGEN)
