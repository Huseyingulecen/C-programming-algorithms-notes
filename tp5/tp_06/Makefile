# Makefile – TP 6 : Le crible d'Ératosthène

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g

PROG      = tp6
TEST_PROG = tp6_tests

.PHONY: all run test clean

all: $(PROG)

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) -o $@ $<

$(TEST_PROG): $(PROG).c $(TEST_PROG).c
	$(CC) $(CFLAGS) -D TP6_TEST -o $@ $(PROG).c $(TEST_PROG).c

run: $(PROG)
	./$(PROG)

test: $(TEST_PROG)
	./$(TEST_PROG)

clean:
	rm -f $(PROG) $(TEST_PROG)
