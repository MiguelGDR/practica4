CC = g++
CFLAGS =-Wall -Werror -Wextra
DEPS = centros.hpp menores.hpp
OBJ = centros.o menores.o test_menores.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_menores: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)

clean:
	rm *.o
