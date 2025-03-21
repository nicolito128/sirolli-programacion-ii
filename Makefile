# Compila un determinado archivo de C, ejecuta el binario saliente y luego borra el mismo al terminar
run:
	gcc $(f).c $(opt) -o $(f) && ./$(f)
	@echo ""
	rm $f

# Similar a `run` pero especificando un .exe para Windows
runwin:
	gcc $(f).c $(opt) -o $(f) && .\$(f).exe
	@echo ""
	DEL $(f)

# Similar a `run` pero con atajos para compilar cualquier ejercicio de las clases.
exec-clase:
	gcc source/clases/c$(c)/$(f)/main.c $(opt) -o bin/$(f) && ./bin/$(f)
	@echo ""
	rm bin/$(f)

execwin-clase:
	gcc source\clases\c$(c)\$(f)\main.c $(opt) -o bin\$(f) && .\bin\$(f).exe
	@echo ""
	echo "\t\n" && DEL bin\$(f)