#ifndef PSO_SYSTEM_TGBAARAMUPLOADTASK_H
#define PSO_SYSTEM_TGBAARAMUPLOADTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The task TAdWarningBaseGC::create starts: it copies the downloaded .gba file
// into the ARAM block init_heap reserved, one run_task step per state.
class TGbaAramUploadTask : public TObject {
public:
    TGbaAramUploadTask(TObject *parent);
    virtual ~TGbaAramUploadTask();
    virtual void run_task();
    void enter_request_state();
    void request_aram_load_state();
    void wait_aram_request();
    void destroy();
    s32 state; // 0x1C: the run_task table index
};
LAYOUT_ASSERT(TGbaAramUploadTask_size, sizeof(TGbaAramUploadTask) == 0x20);

#endif
