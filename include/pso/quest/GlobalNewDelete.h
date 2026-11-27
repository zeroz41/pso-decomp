#ifndef PSO_QUEST_GLOBALNEWDELETE_H
#define PSO_QUEST_GLOBALNEWDELETE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TQuestVmDownLoadServer;
struct CameraParams;

// The demo cameras, picked by demo_camera_index; TCameraDebugView orbits the
// eye of the current one.
extern CameraParams *demo_camera_params_table[16];

TQuestVmDownLoadServer *get_quest_vm_download_server(void);
void init_quest_vm_stub(void);
u8 *alloc_zeroed_array(s32 count, s32 size);

void debug_printf(const char *format, ...);

class TUnk_8048DF58 : public TObject {
public:
    TUnk_8048DF58() : TObject(0) {}
    virtual ~TUnk_8048DF58() {}
};

#endif
