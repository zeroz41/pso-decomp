#ifndef PSO_ITEM_TITEMLOAD_8010FDF0_H
#define PSO_ITEM_TITEMLOAD_8010FDF0_H

#include "types.h"

// A data file TItemLoad::load_buffer read, decompressed and relocated: the
// buffer and its relocated root (apply_rel_relocations).
struct RelocatedFile {
    void *get_root();

    void *buffer;
    void *root;
};

extern "C" {
s32 *__dt__9TItemLoadFPvs(s32 *arg0, s16 arg1);
}

// --- C functions defined in TItemLoad_8010FDF0.cpp ---
extern "C" {
s32 *__dt__9TItemLoadFPvs(s32 *arg0, s16 arg1);
}
// --- end of C functions

#endif
