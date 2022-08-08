#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** args) {
	int f1 = open(args[1], O_WRONLY);
	int f2 = open(args[2], O_WRONLY);
	int f1_size = lseek(f1, 0, SEEK_END);
	int f2_size = lseek(f2, 0, SEEK_END);
	int rs = f1_size - f2_size;
	printf("%c", rs);
	for (size_t i = 0; i < rs; i++)
	{
		lseek(f2, 0, SEEK_END);
		write(f2, "\0", 1);
	}
	close(f1);
	close(f2);
	return 0;
}