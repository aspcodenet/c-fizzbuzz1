PROG=fizzbuzz.exe
SOURCES=main.c fizzbuzz.c password.c fizzbuzztdd.c stringcalculator.c
DEPS=fizzbuzz.h password.h fizzbuzztdd.h
CC=gcc
CFLAGS=-Wall -Werror
DEBUG?=1
GTESTINCLUDE = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=fizzbuzz-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif

#Kommer vi behöva kunna göra massa olika makefiler ute på företag?
#om man nämner makefiles på CV vilken nivå ligger vi på ungefär efter denna utbildning 1-5 :)
# $^ betyder den allt på raden efter exempel $(TEST): ?
OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS) 
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)




$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

$(OUTPUTDIR)/%.o: %.cpp $(DEPS)
	g++ -o $@ -c $< -I $(GTESTINCLUDE)


clean:
	@del /q "$(OUTPUTDIR)" 
	@del /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

check.exe: $(OUTPUTDIR)/fizzbuzztest.o $(OUTPUTDIR)/fizzbuzz.o $(OUTPUTDIR)/password.o $(OUTPUTDIR)/passwordtest.o $(OUTPUTDIR)/fizzbuzztdd.o $(OUTPUTDIR)/fizzbuzztddtest.o $(OUTPUTDIR)/stringcalculator.o $(OUTPUTDIR)/stringcalculatortest.o
	g++ -o $@ $^ $(CFLAGS) -I $(GTESTINCLUDE)  $(LIBGTEST)

test: check.exe
	./check.exe

.PHONY: clean