#ifndef PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H

struct AdxfHandle;

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"

struct TChCrLoadAfsTextureReqArgs {
    NJS_TEXLIST *textures;
    s32 completion_mask;
    s32 *completion_flags;
    s32 display_index;
};
LAYOUT_ASSERT(TChCrLoadAfsTextureReqArgs_size, sizeof(TChCrLoadAfsTextureReqArgs) == 0x10);

struct TChCrLoadAfsTextureReq : public TObject {
    TChCrLoadAfsTextureReq(TObject *parent, NJS_TEXLIST *textures, s32 *arg3, s32 arg4);
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

    s32 m_1c;
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s32 state;
    NJS_TEXLIST *textures;
    s32 *m_34;
    uaddr buffers[8];
    s32 count;
    s32 index;
    AdxfHandle *load_handle;
    s32 m_64;
    s32 m_68;
    s32 m_6c;
    s32 m_70;
    u8 m_74[8][0x24];
};

LAYOUT_ASSERT(TChCrLoadAfsTextureReq_size, sizeof(TChCrLoadAfsTextureReq) == 0x194);
#endif
