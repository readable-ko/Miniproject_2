CC = gcc
TARGET = animal
OBJECTS = main.c crud.o manager.o
all : $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^
clean:
	rm *.o animal
