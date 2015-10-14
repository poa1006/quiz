CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

SRCS_common = main.c

iterative: $(SRCS_common) iterative.c iterative.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

recursive: $(SRCS_common) recursive.c recursive.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

clean:
	$(RM) $(EXEC) *.o perf.*

