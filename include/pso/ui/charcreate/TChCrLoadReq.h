#ifndef PSO_UI_CHARCREATE_TCHCRLOADREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADREQ_H
#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

class TChCrLoadReq : public TObject {
public:
    TChCrLoadReq(TObject *arg1, void *arg2);
    virtual ~TChCrLoadReq();
    void sub_8028CEEC(s32 *);
public:
    u8 unk_1C[0x1C];
    s32 m_38;
    u8 unk_3C[0x4];
    s32 m_40;
    u8 unk_44[0x4];
    s32 m_48;
    u8 unk_4C[0x4];
    s32 m_50;
    u8 unk_54[0xC];
    s32 state;
    s32 timer;
    s32 calc_preview_last_index(s32 display_index, s32 region_index);
    virtual void run_task();
    void close_and_destroy();
    void try_advance_state();
    void update_load_progress();
public:
    void reset_request();
    void copy(void* q);
    static void *create(void *arg0);
    u8 unk_68[0x24];
    s32 m_8c;
};
typedef char TChCrLoadReq_state_offset[(offsetof(TChCrLoadReq,state)==0x60)?1:-1];
typedef char TChCrLoadReq_timer_offset[(offsetof(TChCrLoadReq,timer)==0x64)?1:-1];
typedef char TChCrLoadReq_size[sizeof(TChCrLoadReq) == 0x90 ? 1 : -1];
#endif
