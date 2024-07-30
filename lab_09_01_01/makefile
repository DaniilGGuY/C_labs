FTESTSDIR := ./func_tests
INCDIR := ./inc
OUTDIR := ./out
SRCDIR := ./src
UTESTSDIR := ./unit_tests

vpath %.c $(SRCDIR) $(UTESTSDIR)

CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -I $(INCDIR) -lm
UTESTFLGS := -lcheck -lpthread -lrt -lm 
SRCS := $(wildcard $(SRCDIR)/*.c)
UNIT := $(wildcard $(UTESTSDIR)/*.c)
OBJSRC := $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.o)
OBJUNIT := $(UNIT:$(UTESTSDIR)/%.c=$(OUTDIR)/%.o)

.PHONY: release
release: CFLAGS += --coverage
release: app.exe

.PHONY: debug
debug: CFLAGS += -g
debug: app.exe

.PHONY: func
func: 
	./func_tests/scripts/func_tests.sh

.PHONY: coverage
coverage:
	cd out && gcov -o ./ ../$(SRCDIR)/*.c

.PHONY: unit
unit: my_unit_tests.exe
unit:
	./my_unit_tests.exe

.PHONY: check
check: unit
check: release
check: func
check: coverage
check: clean

app.exe : $(OBJSRC)
	$(CC) $(CFLAGS) -o $@ $^

unit_tests.exe: $(OBJUNIT) $(OUTDIR)/arr_films.o $(OUTDIR)/film.o
	$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS)

my_unit_tests.exe: $(OBJUNIT) $(OUTDIR)/arr_films.o $(OUTDIR)/film.o
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
	$(RM) -f ./*.exe unit_tests/*.o *.txt
	$(RM) -r out/