FTESTSDIR := ./../func_tests
INCDIR := ./inc
OUTDIR := ./out
SRCDIR := ./src
UTESTSDIR := ./../unit_tests
LD_LIBRARY_PATH := .

vpath %.c $(SRCDIR) $(UTESTSDIR)
export LD_LIBRARY_PATH

CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -I $(INCDIR)
DYN_LIB_KEY := -std=c99 -Wall -Werror -fPIC -I $(INCDIR)
UTESTFLGS := -lcheck -lpthread -lrt -lm
SRCS := $(wildcard $(SRCDIR)/*.c)

.PHONY: release
release: CFLAGS += --coverage
release: app.exe

.PHONY: debug
debug: CFLAGS += -g
debug: app.exe

.PHONY: func_tests
func_tests: 
	./func_tests/scripts/func_tests.sh

.PHONY: collect_coverage
collect_coverage:
	cd out && gcov -o ./ ../$(SRCDIR)/*.c

.PHONY: unit
unit: my_unit_tests.exe
unit:
	./my_unit_tests.exe

.PHONY: check
check: unit
check: release
check: func_tests
check: collect_coverage
check: clean

app.exe : $(OUTDIR)/main.o my_lib.so
	$(CC) $(CFLAGS) -o $@ $^

unit_tests.exe: $(OUTDIR)/check_unit_sort.o $(OUTDIR)/check_unit_filt.o $(OUTDIR)/check_main.o my_lib.so
	$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS)

my_unit_tests.exe: $(OUTDIR)/check_unit_sort.o $(OUTDIR)/check_unit_filt.o $(OUTDIR)/check_main.o my_lib.so
	$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS) -lsubunit

my_lib.so : $(SRCDIR)/my_lib.c
	@mkdir -p out
	$(CC) $(DYN_LIB_KEY) -c $< -o $(OUTDIR)/my_lib.o
	$(CC) -o $@ -shared $(OUTDIR)/my_lib.o

$(OUTDIR)/%.o : %.c
	@mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR)/%.d: %.c
	@mkdir -p out
	$(CC) $(CFLAGS) -M $< > $@

include $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.d)

.PHONY: clean
clean:
	$(RM) -f ./*.exe unit_tests/*.o ./*.so
	$(RM) -r out/