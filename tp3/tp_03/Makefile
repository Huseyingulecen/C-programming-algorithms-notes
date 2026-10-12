# Makefile – TP 3 : Le nombre secret

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g

PROG      = tp3
TEST_PROG = tp3_tests

.PHONY: all run test clean

all: $(PROG)

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) -o $@ $<

$(TEST_PROG): $(PROG).c $(TEST_PROG).c
	$(CC) $(CFLAGS) -D TP3_TEST -o $@ $(PROG).c $(TEST_PROG).c

run: $(PROG)
	./$(PROG)

test: $(TEST_PROG)
	./$(TEST_PROG)

clean:
	rm -f $(PROG) $(TEST_PROG)
