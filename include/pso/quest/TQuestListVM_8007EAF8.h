#ifndef PSO_QUEST_TQUESTLISTVM_8007EAF8_H
#define PSO_QUEST_TQUESTLISTVM_8007EAF8_H

#include "types.h"

struct TQuestVmDownLoadServer;
struct CameraParams;

// The demo cameras, picked by demo_camera_index; TCameraDebugView orbits the
// eye of the current one.
extern CameraParams *demo_camera_params_table[16];

TQuestVmDownLoadServer *get_quest_vm_download_server(void);
extern "C" {
void init_quest_vm_stub(void);
void __dl__FPv(void);
u8 *alloc_zeroed_array(s32 a, s32 b);
}

void debug_printf(const char *format, ...);

#endif
