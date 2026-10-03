VERSION ?= 1.0.0

SRC := $(wildcard *.c)
BIN ?= $(SRC:%.c=%)

all: $(BIN)

config.h:
	echo "#ifndef HUID_BUILD_H_" > $@
	echo "#define HUID_BUILD_H_" >> $@
	echo "#define VERSION \"$(VERSION)\"" >> $@
	echo "#endif" >> $@

%: %.c huid.h config.h
	$(CC) -std=c99 $< -o $@ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	$(RM) $(BIN) config.h *.exe
