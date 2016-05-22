###########################################
# Based on simple Makefile for HIDAPI test program
#
# Przemysław Kamiński
# (19.08.2014)
#
###########################################

all: k380

CC=gcc
CXX=g++
COBJS=hid.o
CPPOBJS=./k380.o
OBJS=$(COBJS) $(CPPOBJS)
CFLAGS+=-Ihidapi -Wall -g -c 
LIBS=-framework IOKit -framework CoreFoundation

k380: $(OBJS)
	g++ -Wall -g $^ $(LIBS) -o k380

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(CPPOBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f *.o hidtest $(CPPOBJS)

.PHONY: clean
