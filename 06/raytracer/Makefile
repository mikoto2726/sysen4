raytracer:
	gcc -Wall -fopenmp -O3 *.c -lpng -lm -o raytracer

# For macOS:
# raytracer:
# 	clang -Wall -Xpreprocessor -fopenmp -I$(shell brew --prefix)/include -L$(shell brew --prefix)/lib -O3 *.c -lomp -lpng -lm -o raytracer

clean:
	rm -f *.o output.png raytracer
