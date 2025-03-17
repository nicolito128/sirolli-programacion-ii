# Compila un determinado archivo de C, ejecuta el binario saliente y luego borra el mismo al terminar
run:
	gcc $(f).c $(opt) -o $(f) && ./$(f)
	rm $f

# Similar a `run` pero especificando un .exe para Windows
runwin:
	gcc $(f).c $(opt) -o $(f) && .\$(f).exe
	DEL $(f)

# Similar a `run` pero con atajos para compilar cualquier ejercicio de las clases.
exec-clase:
	gcc source/clases/c$(c)/$(f)/main.c $(opt) -o $(f) && ./$(f)
	rm $f

execwin-clase:
	gcc source\clases\c$(c)\$(f)\main.c $(opt) -o $(f) && .\$(f).exe
	DEL $f