CC = gcc
CFLAGS = -Iinclude

SOURCES = src/main.c src/mystrfunctions.c src/myfilefunctions.c
OBJECTS = obj/main.o obj/mystrfunctions.o obj/myfilefunctions.o

TARGET = bin/client

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) -o $(TARGET)

obj/main.o: src/main.c
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/mystrfunctions.o: src/mystrfunctions.c
	gcc $(CFLAGS) -c src/mystrfunctions.c -o obj/mystrfunctions.o

obj/myfilefunctions.o: src/myfilefunctions.c
	gcc $(CFLAGS) -c src/myfilefunctions.c -o obj/myfilefunctions.o

clean:
	rm -f obj/*.o bin/client
STATIC_LIB = lib/libmyutils.a
STATIC_TARGET = bin/client_static

$(STATIC_LIB): obj/mystrfunctions.o obj/myfilefunctions.o
	ar rcs $(STATIC_LIB) obj/mystrfunctions.o obj/myfilefunctions.o

static: $(STATIC_TARGET)

$(STATIC_TARGET): obj/main.o $(STATIC_LIB)
	gcc obj/main.o -Llib -lmyutils -o $(STATIC_TARGET)
