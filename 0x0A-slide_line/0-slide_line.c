#include <stdio.h>
#include <stdbool.h>
#include "slide_line.h"


void rev_list(int *line, size_t size) {
    int temp = 0;
    for (int i = 0, j = size - 1; i < j; i++) {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
}

int slide_line(int *line, size_t size, int direction)
{
    bool merged_last = false;
    int val;
    int start = 0, end = size - 1;

    if (!line)
        return (0);
    if (direction == -1) {
        rev_list(line, size);
    }
    for (int i = start; i <= end; i++) {
        if (line[i] == 0)
            continue;
        val = line[i];
        for (int j = i - 1; j >= start && j <= end; j -= 1) {
            if (line[j] == val && merged_last == false) {
                line[i] = 0;
                line[j] += val;
                val = line[j];
                merged_last = true;
            }
            else if (line[j] > 0) {
                line[j + 1] = val;
                line[i] = 0;
                merged_last = false;
                start++;
                break;
            }
            else {
                line[j] = 0;
            }
        }
    }
    if (direction == -1)
        rev_list(line, size);
    return (1);
}
