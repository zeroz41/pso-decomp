#ifndef PSO_AUDIO_AIFF_HEADER_H
#define PSO_AUDIO_AIFF_HEADER_H

#include "types.h"

// "FORM" chunk that starts an AIFF file (big-endian size).
struct AiffFormHeader {
    char id[4];
    u32 size;
    char type[4];
};

#endif
