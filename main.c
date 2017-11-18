#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("Input the hand in this format: Ac, Tc, Kd, 3d, 7s\n");
	char user_input[18];
	fgets(user_input, 18, stdin);
	printf("%s\n", user_input);
}