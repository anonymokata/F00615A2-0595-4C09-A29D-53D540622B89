export CC := gcc
export LD := gcc
export AR := ar
export RANLIB := ranlib
export LIBS :=
export CFLAGS := $(CFLAGS) -g -Wall -Werror
export LDFLAGS := $(LDFLAGS)
export COMPILE := $(CC) $(CFLAGS)

all:
	@echo Building calculator.
	$(MAKE) -C src

.PHONY: check
check: all
	@echo Building unit-tests.
	$(MAKE) -C unit-tests
	@echo Running unit-tests.
	$(MAKE) -C unit-tests check

.PHONY: clean
clean :
	$(MAKE) -C src clean
	$(MAKE) -C unit-tests clean
