# ======== Makefile for Simple Compiler demo ========
include		../../sysidf.mk
include		../../prog2txt.mk

THREAD =	thread
#THREAD =	thread2

help:
		@echo Calls are:
		@echo make test_interpr
		@echo make test_codegen
		@echo make test_itinter
		@echo make test_vnaivcg
		@echo make test_vnaivcg2
		@echo make test_generated
		@echo make test_generated2
		@echo make all

all:		test_interpr test_codegen test_itinter test_vnaivcg \
			test_vnaivcg2 test_generated test_generated2

test_interpr:
		make BACKEND=interpr _test

test_codegen:
		make BACKEND=codegen _test

test_itinter:
		make BACKEND=itinter _test

test_vnaivcg:
		make BACKEND=vnaivcg _test

test_vnaivcg2:
		make BACKEND=vnaivcg2 _test

test_generated:
		make BACKEND=vnaivcg RESULT=testgc _test2

test_generated2:
		make BACKEND=vnaivcg2 RESULT=testgc2 _test2


TEST_OPTIONS =	
BACKEND =	x
RESULT =	y

# ==== $(BACKEND)

_test:		$(BACKEND)$(EXE)
		echo '7' | tr -d "'" | $(BACKEND)$(EXE)
		echo '((7+2)*(3+5))' | tr -d "'" | $(BACKEND)$(EXE)
		echo '(2*((3* 4)+9))' | tr -d "'" | $(BACKEND)$(EXE)

SRC =		lex.c parser.c main.c $(THREAD).c stack.c error.c $(BACKEND).c
OBJ =		lex.o parser.o main.o $(THREAD).o stack.o error.o $(BACKEND).o

$(BACKEND)$(EXE):$(OBJ) Makefile
		$(CC) $(OBJ) -o $@

#
_test2:		$(RESULT)$(EXE)
		echo y | $(RESULT)$(EXE)

$(RESULT)$(EXE):	$(RESULT).c stack.o
		$(CC) $(RESULT).c stack.o -o $@

$(RESULT).c:	$(BACKEND)$(EXE)
		echo '(7*(1+5))' | tr -d "'" | $(BACKEND)$(EXE) >$@

# ==== Auxilairies
figures:	main.ctxt lex.htxt lex.ctxt \
		parser.itxt parserbody.itxt parserch1.htxt \
		backend.htxt codegen.ctxt interpr.ctxt

lint:
		make BACKEND=interpr _lint
		make BACKEND=codegen _lint
		make BACKEND=itinter _lint
		make BACKEND=vnaivcg _lint
		make BACKEND=vnaivcg2 _lint


_lint:		$(SRC) Makefile
		$(LINT) $(SRC)

clean:
		rm -f *.o core a.out *.?txt \
			interpr interpr$(EXE) \
			codegen codegen$(EXE) \
			itinter itinter$(EXE) \
			vnaivcg vnaivcg$(EXE) \
			vnaivcg2 vnaivcg2$(EXE) \
			testgc.c testgc testgc$(EXE) \
			testgc2.c testgc2 testgc2$(EXE)

# DO NOT DELETE THIS LINE -- make depend depends on it.

codegen.o: parser.h
codegen.o: backend.h
error.o: error.h
interpr.o: parser.h
interpr.o: backend.h
itinter.o: parser.h
itinter.o: thread.h
itinter.o: stack.h
itinter.o: backend.h
lex.o: lex.h
main.o: parser.h
main.o: backend.h
main.o: error.h
parser.o: parser.i
parser.o: lex.h
parser.o: error.h
parser.o: parser.h
parser.o: parserbody.i
testgc.o: stack.h
testgc2.o: stack.h
thread.o: parser.h
thread.o: thread.h
thread2.o: parser.h
thread2.o: thread.h
vnaivcg.o: parser.h
vnaivcg.o: thread.h
vnaivcg.o: backend.h
vnaivcg2.o: parser.h
vnaivcg2.o: thread.h
vnaivcg2.o: backend.h
