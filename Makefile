# Makefile
LDFLAGS=-lncurses -lpanel
CC=gcc
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: algebra.c
	$(CC) -o algebra algebra.c $(LDFLAGS)

colors: play_with_colors.c
	$(CC) -o colors play_with_colors.c $(LDFLAGS)

