CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDFLAGS = -mconsole

TARGET = uber_eats

SRC = main.c \
      restaurant/restaurant.c \
      restaurant/bst.c \
      orders/order.c \
      orders/queue.c \
      courier/courier.c \
      courier/linkedlist.c \
      map/graph.c \
      map/dijkstra.c \
      utils/menu.c

OBJ = $(SRC:.c=.o)

# Default build
all: $(TARGET)

# Link step
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile step (generic rule)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild from scratch
rebuild: clean all