#ifndef PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"

struct TChCrLoadAfsTextureReq : public TObject {
    TChCrLoadAfsTextureReq(TObject *parent, GinjaTextureList *textures, s32 *arg3, s32 arg4);
    TChCrLoadAfsTextureReq(TObject *parent, void *args);
    virtual ~TChCrLoadAfsTextureReq();
    virtual void run_task();
    void update_loading();
    void start_read();
    void try_begin_load();
    void finish_request();
    s32 try_acquire_load_slot();
    void init_texture_table();
    static void *create(void *parent, void *args);

    s32 m_1c;
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s32 state;
    GinjaTextureList *textures;
    s32 *m_34;
    u32 buffers[8];
    s32 count;
    s32 index;
    u32 load_handle;
    s32 m_64;
    s32 m_68;
    s32 m_6c;
    s32 m_70;
    u8 m_74[8][0x24];
};

typedef char TChCrLoadAfsTextureReq_size[sizeof(TChCrLoadAfsTextureReq) == 0x194 ? 1 : -1];
#endif
