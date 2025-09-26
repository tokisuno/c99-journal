CC = gcc
CFLAGS = -O3 -Wall -Wextra -Winit-self -Werror -std=c99

main:
	$(CC) $(CFLAGS) main.c -o journal

run:
	$(CC) $(CFLAGS) main.c -o journal && ./journal
