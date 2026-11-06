#include "types.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"

extern "C" {

void *__ct__15TAdSubPlyItemGCFv(void *, void *);
void *__ct__19TAdPlyChrSelPlateGCFv(void *, void *, void *);
void *__ct__20TAdChrSelMovePlateGCFv(void *, void *);
void *__nw__7TObjectFUl(int);

extern s32 chr_sel_b_slot_plate_layout[];

void TAdChrSelBSlotGC::create_children() {
    void *o;
    void *o2;
    void *o3;
    void *o4;
    o = new TAdChrSelSlotGC(this);
    *(void * *)&this->unk_28 = o;
    o2 = __nw__7TObjectFUl(0x3B4);
    if (o2 != NULL) {
        o2 = __ct__19TAdPlyChrSelPlateGCFv(o2, this, chr_sel_b_slot_plate_layout);
    }
    *(void * *)&this->m_2c = o2;
    o3 = __nw__7TObjectFUl(0x48C);
    if (o3 != NULL) {
        o3 = __ct__15TAdSubPlyItemGCFv(o3, this);
    }
    *(void * *)&this->unk_30 = o3;
    o4 = __nw__7TObjectFUl(0x208);
    if (o4 != NULL) {
        o4 = __ct__20TAdChrSelMovePlateGCFv(o4, this);
    }
    this->m_34 = o4;
}

void TAdChrSelBSlotGC::sub_8030FE04() {
    this->m_1c = 0;
    this->m_20 = 0;
    this->m_24 = -1;
    *(s32 *)&this->unk_28 = 0;
    this->m_2c = 0;
    *(s32 *)&this->unk_30 = 0;
    this->m_34 = 0;
    *(s32 *)&this->unk_38 = 0;
    this->m_3c = 0;
    *(s32 *)&this->unk_40 = 0;
    this->m_44 = 0;
    *(s32 *)&this->unk_48 = 0;
    this->m_4c = 0;
    *(s32 *)&this->unk_50 = 0;
    this->m_54 = 0;
    *(s32 *)&this->unk_58 = 0;
    this->m_5c = 0;
    *(s32 *)&this->unk_60 = 0;
    this->m_64 = 0;
    *(s32 *)&this->unk_68 = 0;
    this->m_6c = 0;
    *(s32 *)&this->unk_70 = 0;
    this->m_74 = 0;
    *(s32 *)&this->unk_78 = 0;
    this->m_7c = 0;
}

}
