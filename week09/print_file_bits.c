#include <stdio.h>
#include <stdint.h>
int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return 1;
	}
	
	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		perror(argv[1]);
		return 1;
	}

	int32_t num;
	while (fscanf(f, "%x\n", &num) != EOF) {
		int low_byte = num & 0xFF;
		printf("unsigned = %d, signed = ", low_byte);
		// is low_byte negative?
		if (low_byte & (1<<7)) {
		// negative :(
			low_byte = low_byte | 0xFFFFFF00;
		}

		printf("%d\n", low_byte);
	}
}
