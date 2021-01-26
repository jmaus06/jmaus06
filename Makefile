make:
	@echo "Targets are:"
	@echo "binary"
	@echo "hex"
	@echo "ones"

binary: inttobinary.c
	gcc -o binary inttobinary.c -lm
	./binary

hex: inttohex.c
	gcc -o hex inttohex.c -lm
	./hex
ones: onesinint.c
	gcc -o ones onesinint.c -lm
	./ones
	
