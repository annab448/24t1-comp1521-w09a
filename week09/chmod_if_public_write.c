#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void chmod_if_needs(char *path) {
	// look at mode, see if public write
	struct stat s;
	if (stat(path, &s) != 0) {
		perror(path);
		exit(1);
	}
	
	mode_t mode = s.st_mode;
	// is it publically writable?
	if (mode & S_IWOTH) {
		// change permissions
		printf("changing %s... ", path);
		mode = mode & (~S_IWOTH);
		if (chmod(path, mode) != 0) {
			perror(path);
			exit(1);
		}
		printf("done!\n");
	} else {
		printf("%s is not publically writeable\n", path);
	}
}

int main(int argc, char *argv[]) {
	printf("changing file permissions...\n");
	for (int i = 1; i < argc; i++) {
		chmod_if_needs(argv[i]);
	}
}
