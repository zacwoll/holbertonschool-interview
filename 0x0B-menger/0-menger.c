#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//TODO write a freeCarpet
char **createCarpet(int side_length) {
	int i, j;
	char **carpet;

	carpet = malloc( sizeof (char*) * side_length);
	for (i = 0; i < side_length; i++) {
		carpet[i] = malloc(sizeof(char) * (side_length + 1));
		for (j = 0; j < side_length; j++) {
			carpet[i][j] = '#';
		}
		carpet[i][j] = '\0';
	}
	return carpet;
}

void freeCarpet(char **carpet) {
	int i, length = strlen(carpet[0]);

	for (i = 0; i < length; i++) {
		free(carpet[i]);
	}
	free(carpet);
}

char **createNewCarpet(char **old) {
	int i, j, k, l, old_length = strlen(old[0]);
	char **new;

	new = createCarpet(old_length * 3);

	for (i = 0; i < old_length; i++) {
		for (j = 0; j < old_length; j++) {
			for (k = 0; k < 3; k++) {
				for (l = 0; l < 3; l++) {
					if (old[i][j] == ' ') {
						new[3 * i + k][3 * j + l] = ' ';
					}
				}
			}
			new[3 * i + 1][3 * j + 1] = ' ';
		}
	}

	freeCarpet(old);
	return new;
}

void printCarpet(char **carpet) {
	int height = strlen(carpet[0]);
	int i;

	for (i = 0; i < height; i++)
		printf("%s\n", carpet[i]);
}

void menger(int level) {
	char **carpet = createCarpet(1);
	int i;

	for (i = 0; i < level; i++) {
		printCarpet(carpet);
		carpet = createNewCarpet(carpet);
	}
	printCarpet(carpet);
	freeCarpet(carpet);
}
