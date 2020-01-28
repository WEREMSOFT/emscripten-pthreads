CC=emcc
OPTIMIZATION_LEVEL=0
PROJECT_NAME=main

all: main

main: ../main.c
	$(CC) -O$(OPTIMIZATION_LEVEL) ../$(PROJECT_NAME).c -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=4 -o $(PROJECT_NAME).html

clean:
	rm $(PROJECT_NAME).html $(PROJECT_NAME).js $(PROJECT_NAME).wasm $(PROJECT_NAME).worker.js
