#ifndef PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H

struct AdxfHandle;

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTextureInput.h"

struct TChCrLoadAfsTextureReqArgs {
    NJS_TEXLIST *textures;
    s32 completion_mask;
    s32 *completion_flags;
    s32 display_index;
};
LAYOUT_ASSERT(TChCrLoadAfsTextureReqArgs_size, sizeof(TChCrLoadAfsTextureReqArgs) == 0x10);

struct TChCrLoadAfsTextureReq : public TObject {
    static const char *name;
    static s32 active_load_count;
    TChCrLoadAfsTextureReq(TObject *parent, NJS_TEXLIST *textures, s32 *completion_flags, s32 display_index);
    TChCrLoadAfsTextureReq(TObject *parent, TChCrLoadAfsTextureReqArgs *args);
    virtual ~TChCrLoadAfsTextureReq();
    virtual void run_task();
    void update_loading();
    void start_read();
    void try_begin_load();
    void finish_request();
    s32 try_acquire_load_slot();
    void init_texture_table();
    static TChCrLoadAfsTextureReq *create(TObject *parent, TChCrLoadAfsTextureReqArgs *args);

    s32 textures_loaded;
    s32 stop_count;
    s32 read_frames;
    s32 suspended;
    s32 state;
    NJS_TEXLIST *textures;
    s32 *completion_flags;
    uaddr buffers[8];
    s32 count;
    s32 index;
    AdxfHandle *load_handle;
    s32 timeout_frames;
    s32 holds_load_slot;
    s32 completion_mask;
    s32 display_index;
    GinjaTextureInput texture_inputs[8];
};

LAYOUT_ASSERT(TChCrLoadAfsTextureReq_size, sizeof(TChCrLoadAfsTextureReq) == 0x194);
TChCrLoadAfsTextureReq *create_ch_cr_load_afs_texture_req(TObject *parent, NJS_TEXLIST *textures, void *slot, void *index);

#endif
