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

.PHONY: unit
unit: my_unit_tests.exe
unit:
	./my_unit_tests.exe

unit_tests.exe: $(OBJUNIT) $(OUTDIR)/my_snprintf.o
	$(CC) $(CFLAGS) -o $@ $^ $(UTESTFLGS)

my_unit_tests.exe: $(OBJUNIT) $(OUTDIR)/my_snprintf.o
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
	$(RM) -f ./*.exe
	$(RM) -r out/