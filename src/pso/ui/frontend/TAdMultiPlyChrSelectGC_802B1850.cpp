#include "pso/ui/frontend/TAdGuideTxtGC.h"

void TAdGuideTxtGC::set_line(s32 index, const char *line) {
    if (previous_text[index] != line) {
        text[index] = line;
        alpha[index] = 0;
    }
    previous_text[index] = line;
}
