#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: ./main.c [5c, Ad, Tc, 9h, Ac]\n");
		return 1;
	}
	char* user_input = argv[1];
	printf("%s\n", user_input);
}