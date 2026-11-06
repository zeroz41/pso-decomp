#ifndef PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADAFSTEXTUREREQ_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TChCrLoadAfsTextureReq : public TObject {
    virtual ~TChCrLoadAfsTextureReq();
    virtual void run_task();
    u8 _pad1C[0xC];
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u8 _pad38[0x2C];
    u32 m_64;
    u8 _pad68[0x4];
    u32 m_6c;
    u32 m_70;
    void update_loading(void *);
    void start_read(void *);
    u8 unk_74[0x120];
};

typedef char TChCrLoadAfsTextureReq_size[sizeof(TChCrLoadAfsTextureReq) == 0x194 ? 1 : -1];
#endif
