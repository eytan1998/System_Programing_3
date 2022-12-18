.PHONY: clean all

all: isort txtfind

txtfind: txtfind.c
	gcc -Wall -g txtfind.c -o $@

isort: isort.c
	gcc -Wall -g isort.c -o $@
