SRC := $(wildcard *.c)
BIN ?= $(SRC:%.c=%)

all: $(BIN)

%: %.c
	$(CC) -std=c99 $< -o $@ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	$(RM) $(BIN)
