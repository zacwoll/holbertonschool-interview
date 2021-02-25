#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void rev_list(int *line, size_t size);

#define SLIDE_RIGHT -1
#define SLIDE_LEFT 1

#endif /* SLIDE_LINE_H */