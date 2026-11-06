#ifndef PSO_UI_CHARCREATE_TCHCRLOADGMNJREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADGMNJREQ_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrLoadGmNjReq : public TObject {
public:
 u8 unk_1C[0x4];
 void * m_20; // 0x20
 u8 unk_24[0x4];
 void * m_28; // 0x28
 u8 unk_2C[0x34];
 void * m_60; // 0x60
 u8 unk_64[0x4];
 void* m_68;

public:
    virtual ~TChCrLoadGmNjReq();
    void sub_8028C8A8();
    virtual void run_task();
};

extern "C" {
void *TChCrLoadGmNjReq__ct(void *arg0, void *arg1, void *arg2);
}
void *create_ch_cr_load_gm_nj_req(void *arg0, void *arg1);

#endif
