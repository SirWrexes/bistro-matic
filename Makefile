##
## EPITECH PROJECT, 2019
## [PROJECT NAME]
## File description:
## [PROJECT DESCRIPTION]
##

#
# Config
##########################################
NAME    :=  calc
BIN     :=  $(NAME)
TESTBIN :=  utests_$(NAME)
SHELL   :=  /bin/bash
MAKE    :=  make --no-print-directory -C
RM      :=  rm -rf
CP      :=  cp -t
MV      :=  mv -t
GCOV    :=  gcovr
CC      :=  gcc
.DEFAULT_GOAL := all
COMPILEDBTARGET := all tests
##########################################


#
# Colours
##########################################
CRESET      :=	$$'\033[0m'

# \033[38;2;<R>;<G>;<B>m
CRED        :=	$$'\033[38;2;255;0;0m'
CGREEN      :=	$$'\033[1;32;40m'
CLIGHTGREEN :=  $$'\033[38;2;190;255;200m'
CBLUE       :=	$$'\033[38;2;0;0;255m'
CLIGHTBLUE  :=	$$'\033[38;2;88;255;250m'
CORANGE     :=	$$'\033[38;2;255;167;4m'

# Format
CBOLD       :=  $$'\033[1m'
CUNDERLN    :=  $$'\033[4m'
##########################################


# ----------------------- PYTHON PROGRESS BAR SCRIPT ------------------------ #

define PROGBAR
import argparse
import math
import sys

def main():
  parser = argparse.ArgumentParser(description=__doc__)
  parser.add_argument("--stepno", type=int, required=True)
  parser.add_argument("--nsteps", type=int, required=True)
  parser.add_argument("remainder", nargs=argparse.REMAINDER)
  args = parser.parse_args()

  nchars = int(math.log(args.nsteps, 10)) + 1
  fmt_str = "\033[38;2;255;167;4m[$(NAME) | {:Xd}/{:Xd} | {:6.2f}%]\033[0m".replace("X", str(nchars))
  progress = 100 * args.stepno / args.nsteps
  sys.stdout.write(fmt_str.format(args.stepno, args.nsteps, progress))
  for item in args.remainder:
    sys.stdout.write(" ")
    sys.stdout.write(item)
  sys.stdout.write("\n")

if __name__ == "__main__":
  main()
endef

ifndef ECHO
  $(call export PROGBAR) $(file >progressbar.py,$(PROGBAR))
  T := $(shell $(MAKE) . $(MAKECMDGOALS)	\
       -nrRf $(firstword $(MAKEFILE_LIST)) 	\
       ECHO="PCOUNT$(NAME)" | grep -c "PCOUNT$(NAME)")
  N := x
  C = $(words $N)$(eval N := x $N)
  ECHO = python ./progressbar.py --stepno=$C --nsteps=$T
endif

# ----------------------- MAKEFILE STARTS FROM HERE -------------------------- #



#
# Sources
##########################################
MAIN :=
SRC  :=
SRC  +=
##########################################


#
# Test sources
##########################################
TEST :=
TEST +=
##########################################


#
# Wrapper sources
##########################################
WRAPSRC := ./lib/libfox/extra/tests/wrappers/wrap_malloc.c
WRAPPED := malloc
##########################################


#
# Files created by unit tests function
##########################################
TESTTMP :=
##########################################


#
# Build config
##########################################
INCDIRS   := ./include
# ----------------------------------------
CFLAGS    := -Wall -Wextra
CFLAGS    += -Werror
CFLAGS    += -fno-builtin
CFLAGS    += $(foreach dir, $(INCDIRS), -iquote $(dir))

# ----------------------------------------
OBJ       :=  $(SRC:.c=.o)
DEP       :=  $(OBJ:.o=.d) $(MAIN:.c=.d)
COV       :=  *.gcda *.gcno
.PRECIOUS :=  $(DEP)
-include $(DEP)
##########################################


#
# Libfox automation
##########################################
INCDIRS    += ./lib/libfox/extra/include
# ----------------------------------------
FOXMODULES += datastruct
FOXMODULES += std
FOXMODULES += string
# ----------------------------------------
LDFLAGS    += $(foreach mod, $(FOXMODULES), -L./lib/libfox/$(strip $(mod)))
LDLIBS     += $(foreach mod, $(FOXMODULES), -lfox_$(strip $(mod)))
# ----------------------------------------
RULE := all # Default value
##########################################


#
# Test config
##########################################
UTFLAGS   := --always-succeed --timeout 5
# ----------------------------------------
COVFLAGS  := -s --exclude-unreachable-branches
COVFLAGS  += --exclude='.*test_.*'
COVFLAGS  += --exclude='.*wrap_.*'
##########################################


#
# Reciepes
##########################################
%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO) $(CLIGHTGREEN)Compile OK ✓$(CRESET) $@

%.d: %.c
	@set -e; rm -f $@; 									\
	$(CC) -M $(CFLAGS) $< > $@.$$$$; 					\
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$
##########################################


#
# Rules
##########################################
.PHONY: libfox
libfox:
	@$(ECHO) $(CORANGE)"Make libfox rule(s)"$(CRESET) $(foreach r,$(RULE),$(CBOLD)$r$(CRESET))
	@$(MAKE) ./lib/libfox $(RULE)

.PHONY: compiledb
compiledb:
	@[[ "$(shell which compiledb)" == "" ]] || compiledb -n make -ik $(COMPILEDBTARGET)

.PHONY: build
build: libfox
build: | $(FILES)
	@$(CC) -o $(TARGET) $(CFLAGS) $(FILES) $(LDFLAGS)
	@$(ECHO) $(CBOLD)"Link OK"$(CRESET)
	@$(ECHO) $(CBOLD)$(CLIGHTBLUE)"Done compiling"$(CRESET) $(CLIGHTBLUE)$@$(CRESET)

.PHONY: all
all: $(NAME)
$(NAME): TARGET := $(NAME)
$(NAME): COMPILEDBTARGET = $(NAME)
$(NAME): RULE := $(FOXMODULES)
$(NAME): OBJ  += $(MAIN:.c=.o)
$(NAME): FILES := $(OBJ)
$(NAME): compiledb libfox
$(NAME): $(MAIN:.c=.o) $(OBJ) build

.PHONY: debug
debug: TARGET := $(NAME)
debug: RULE   := $(FOXMODULES)
debug: CFLAGS += -ggdb3 -rdynamic
debug: SRC    += $(MAIN)
debug: libfox
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS)

.PHONY: tests
tests: $(TESTBIN)
$(TESTBIN): TARGET := $(TESTBIN)
$(TESTBIN): COMPILEDBTARGET = $(TESTBIN)
$(TESTBIN): FILES   += $(SRC) $(TEST) $(WRAPSRC)
$(TESTBIN): CFLAGS  += --coverage
$(TESTBIN): CFLAGS  += -Wl$(foreach wrap, $(WRAPPED),,--wrap=$(wrap))
$(TESTBIN): LDFLAGS += -l criterion
$(TESTBIN): RULE    := all
$(TESTBIN): compiledb libfox rm_test_files build

.PHONY: rm_test_files
rm_test_files:
	@$(foreach tmp, $(TESTTMP), $(RM) $(tmp))

.PHONY: tests tests_run test_report
tests: test_report
tests_run: test_report
test_report: $(TESTBIN)
	@$(ECHO) $(CUNDERLN)$(CGREEN)TEST REPORT$(CRESET)
	@./$(TESTBIN) $(UTFLAGS)
	@$(GCOV) $(COVFLAGS)

.PHONY: clean
clean: RULE := clean
clean: OBJ += $(MAIN:.c=.o)
clean: libfox rm_test_files
	@$(ECHO) $(CRED)Delete$(CRESET) objects
	@$(RM) $(OBJ)
	@$(ECHO) $(CRED)Delete$(CRESET) dependancy files
	@$(RM) $(DEP)
	@$(ECHO) $(CRED)Delete$(CRESET) coverage files
	@$(RM) *.gc*

.PHONY: fclean
fclean: RULE := fclean
fclean: OBJ += $(MAIN:.c=.o)
fclean: libfox rm_test_files
	@$(ECHO) $(CRED)Delete$(CRESET) objects
	@$(RM) $(OBJ)
	@$(ECHO) $(CRED)Delete$(CRESET) dependancy files
	@$(RM) $(DEP)
	@$(ECHO) $(CRED)Delete$(CRESET) coverage files
	@$(RM) *.gc*
	@$(ECHO) $(CRED)Delete$(CRESET) $(BIN)
	@$(RM) $(BIN)
	@$(ECHO) $(CRED)Delete$(CRESET) $(TESTBIN)
	@$(RM) $(TESTBIN)

.PHONY: re
re: RULE := re
re: OBJ += $(MAIN:.c=.o)
re: | libfox
re: fclean rm_test_files all
