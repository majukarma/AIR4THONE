#include <string.h>
#include "common.h"

int compare_lexemes(const void *a, const void *b) {
    return strcmp(((Word *)a)->name, ((Word *)b)->name);
}
