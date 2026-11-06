#ifndef PSO_UI_WINDOW_TWINDOWAREA_H
#define PSO_UI_WINDOW_TWINDOWAREA_H

#include "types.h"

struct TWindowArea
{
    u8 _pad1C[0x8];
    void* m_24;
    u8 _pad28[0x18];
    void* m_40;
    void run_task();
};

extern "C" {
u8 *TWindowArea__ct(u8 *window_room);
void *__dt__11TWindowAreaFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowArea.cpp ---
extern "C" {
u8 *TWindowArea__ct(u8 *window_room);
void *__dt__11TWindowAreaFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
