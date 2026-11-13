#ifndef PSO_UI_CHARCREATE_TCHCRLOADGMNJREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADGMNJREQ_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TLobby;

class TChCrLoadGmNjReq : public TObject {
public:
    u32 *m_1c;
    s32 m_20;
    TLobby *m_24;
    s32 *m_28;
    s32 state;
    char name[48];
    char *m_60;
    u32 m_64;
    void *m_68;
    s32 m_6c;
    s32 m_70;
    s32 m_74;

public:
    TChCrLoadGmNjReq(TObject *parent, void *args);
    virtual ~TChCrLoadGmNjReq();
    void sub_8028C8A8();
    virtual void run_task();
};

typedef char TChCrLoadGmNjReq_size[sizeof(TChCrLoadGmNjReq) == 0x78 ? 1 : -1];

void *create_ch_cr_load_gm_nj_req(void *arg0, void *arg1);

#endif
