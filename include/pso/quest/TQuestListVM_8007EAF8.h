#ifndef PSO_QUEST_TQUESTLISTVM_8007EAF8_H
#define PSO_QUEST_TQUESTLISTVM_8007EAF8_H

#include "types.h"

struct TQuestVmDownLoadServer;
struct CameraParams;

// The demo cameras, picked by demo_camera_index; TCameraDebugView orbits the
// eye of the current one.
extern CameraParams *demo_camera_params_table[16];

extern "C" {
TQuestVmDownLoadServer *TQuestVmDownLoadServer__sub_8007EB14(void);
void TLobby__sub_8007EB20(const char *format, ...);
void TLobby__sub_8007EB70(void);
void __dl__FPv(void);
u8 *TQuestVmDownLoadServer__sub_8007EBDC(s32 a, s32 b);
}

#endif
