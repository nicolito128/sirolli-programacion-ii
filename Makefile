# Compila un determinado archivo de C, ejecuta el binario saliente y luego borra el mismo al terminar
run:
	gcc -o $f $f.c && ./$f
	rm $f

# Similar a `run` pero especificando un .exe para Windows
runwin:
	gcc -o $f.exe $f.c && .\$f.exe
	DEL $f

# Similar a `run` pero con atajos para compilar cualquier folder de source/
exec:
	gcc -o $f source/$f/main.c && ./$f
	rm $f
