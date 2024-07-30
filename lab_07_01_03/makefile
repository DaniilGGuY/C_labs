FTESTSDIR := ./func_tests
INCDIR := ./inc
OUTDIR := ./out
SRCDIR := ./src
UTESTSDIR := ./unit_tests

vpath %.c $(SRCDIR) $(UTESTSDIR)

CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -I $(INCDIR)
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

.PHONY: my_unit_tests
my_unit_tests: my_unit_tests.exe
my_unit_tests:
	./my_unit_tests.exe

.PHONY: check
check: my_unit_tests
check: release
check: func_tests
check: collect_coverage
check: clean

app.exe : $(OUTDIR)/main.o $(OUTDIR)/arr_funcs.o $(OUTDIR)/file_funcs.o
	$(CC) $(CFLAGS) -o $@ $^

unit_tests.exe: $(OUTDIR)/check_unit_sort.o $(OUTDIR)/check_unit_filt.o $(OUTDIR)/arr_funcs.o $(OUTDIR)/check_main.o
	$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS)

my_unit_tests.exe: $(OUTDIR)/check_unit_sort.o $(OUTDIR)/check_unit_filt.o $(OUTDIR)/arr_funcs.o $(OUTDIR)/check_main.o
	$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS) -lsubunit

$(OUTDIR)/%.o : %.c
	@mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR)/%.d: %.c
	@mkdir -p out
	$(CC) $(CFLAGS) -M $< > $@

include $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.d)

.PHONY: clean
clean:
	$(RM) -f ./*.exe unit_tests/*.o
	$(RM) -r out/