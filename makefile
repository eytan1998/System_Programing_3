.PHONY: clean all

all: isort txtfind
clean:
	rm -f txtfind isort *.o *.txts

txtfind: txtfind.c
	gcc -Wall -g txtfind.c -o $@

isort: isort.c
	gcc -Wall -g isort.c -o $@
