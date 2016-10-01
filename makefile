strtest: stringy.c
	clang stringy.c -o strtest

clean:
	rm *~

run: strtest
	./strtest