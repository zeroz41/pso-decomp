#ifndef PSO_UI_CHARCREATE_TCHCRLOADGMNJREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADGMNJREQ_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

struct BmlResource;

struct TChCrLoadGmNjReqArgs {
    const char *name;
    u32 *model_out;
    s32 load_slot;
    s32 completion_mask;
    u32 *completion_flags;
};
typedef char TChCrLoadGmNjReqArgs_size[sizeof(TChCrLoadGmNjReqArgs) == 0x14 ? 1 : -1];

class TChCrLoadGmNjReq : public TObject {
public:
    u32 *model_out;
    s32 completion_mask;
    s32 load_slot;
    u32 *completion_flags;
    s32 state;
    char name[48];
    // The model-list terminator also serves as the empty motion list.
    void *model_ids[2];
    BmlResource *loaded_bml;
    s32 slot_claimed;
    s32 lifetime_remaining;
    s32 load_timer;

public:
    TChCrLoadGmNjReq(TObject *parent, TChCrLoadGmNjReqArgs *args);
    virtual ~TChCrLoadGmNjReq();
    void sub_8028C8A8();
    void start_character_load_task();
    void update_model_load();
    s32 try_acquire_slot();
    virtual void run_task();
};

typedef char TChCrLoadGmNjReq_size[sizeof(TChCrLoadGmNjReq) == 0x78 ? 1 : -1];
typedef char TChCrLoadGmNjReq_completion_mask_offset[offsetof(TChCrLoadGmNjReq, completion_mask) == 0x20 ? 1 : -1];
typedef char TChCrLoadGmNjReq_load_slot_offset[offsetof(TChCrLoadGmNjReq, load_slot) == 0x24 ? 1 : -1];
typedef char TChCrLoadGmNjReq_completion_flags_offset[offsetof(TChCrLoadGmNjReq, completion_flags) == 0x28 ? 1 : -1];
typedef char TChCrLoadGmNjReq_state_offset[offsetof(TChCrLoadGmNjReq, state) == 0x2C ? 1 : -1];
typedef char TChCrLoadGmNjReq_name_offset[offsetof(TChCrLoadGmNjReq, name) == 0x30 ? 1 : -1];
typedef char TChCrLoadGmNjReq_model_ids_offset[offsetof(TChCrLoadGmNjReq, model_ids) == 0x60 ? 1 : -1];
typedef char TChCrLoadGmNjReq_loaded_bml_offset[offsetof(TChCrLoadGmNjReq, loaded_bml) == 0x68 ? 1 : -1];
typedef char TChCrLoadGmNjReq_slot_claimed_offset[offsetof(TChCrLoadGmNjReq, slot_claimed) == 0x6C ? 1 : -1];
typedef char TChCrLoadGmNjReq_lifetime_remaining_offset[offsetof(TChCrLoadGmNjReq, lifetime_remaining) == 0x70 ? 1 : -1];
typedef char TChCrLoadGmNjReq_load_timer_offset[offsetof(TChCrLoadGmNjReq, load_timer) == 0x74 ? 1 : -1];

TChCrLoadGmNjReq *create_ch_cr_load_gm_nj_req(TObject *parent, TChCrLoadGmNjReqArgs *args);

#endif
