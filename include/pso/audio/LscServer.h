#ifndef PSO_AUDIO_LSCSERVER_H
#define PSO_AUDIO_LSCSERVER_H

#include "types.h"

// --- C functions defined in LscServer.cpp ---
extern "C" {
void end_803D1D28(LscStream *lsc_stream);
void lsc_poll(LscStream *lsc_stream);
void read_803D1D28(LscStream *lsc_stream);
void wait_803D1D28(LscStream *lsc_stream);
}
// --- end of C functions

#endif
