INCDIR := ./../lab_10_03_common
OUTDIR := ./out
SRCDIR := ./
UTESTSDIR := ./../lab_10_03_common

vpath %.c $(SRCDIR) $(UTESTSDIR)

CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra
UTESTFLGS := -lcheck -lpthread -lrt -lm 
SRCS := $(wildcard $(SRCDIR)/*.c)
UNIT := $(wildcard $(UTESTSDIR)/*.c)
OBJSRC := $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.o)
OBJUNIT := $(UNIT:$(UTESTSDIR)/%.c=$(OUTDIR)/%.o)

.PHONY: unit
unit: my_unit_tests.exe
unit:
	./my_unit_tests.exe

unit_tests.exe: $(OUTDIR)/associative_array_impl_1.o $(OUTDIR)/associative_array_node.o $(OUTDIR)/list.o $(OBJUNIT)
	$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS)

my_unit_tests.exe: $(OUTDIR)/associative_array_impl_1.o $(OUTDIR)/associative_array_node.o $(OUTDIR)/list.o $(OBJUNIT)
		$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS) -lsubunit

$(OUTDIR)/%.o : %.c
	@mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@ -lm

$(OUTDIR)/%.d: %.c
	@mkdir -p out
	$(CC) $(CFLAGS) -M $< > $@ -lm

include $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.d)

.PHONY: clean
clean:
	$(RM) -r out/ *.exe