onda.dat : a.out
	./a.out > onda.dat
	python animacion.py
	rm onda.dat
	rmdir pngs
	gcc placas.c -lm
	./a.out >datos.dat
	python grafica.py
	rm a.out
	rm datos.dat

a.out : cuerda.c
	gcc cuerda.c -lm


