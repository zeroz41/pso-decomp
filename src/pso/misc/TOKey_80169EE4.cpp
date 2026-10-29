#include "types.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/object/TObjMapObject.h"

extern "C" {
void TOKey__sub_80169FB0(void* p);
void __dl__7TObjectFPv(void *);
void *__ct__13TObjMapObjectFP7TObject(void *a0);

extern s32 lbl_804B27D8[];

void *TUnk_804B27D8::destroy_key_object(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)((u8 *)this + 0x18) = lbl_804B27D8;
        __dt__13TObjMapObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_804B27D8::init() {
    __ct__13TObjMapObjectFP7TObject(this);
    *(s32 * *)((u8 *)this + 0x18) = lbl_804B27D8;
    *(u32 *)&this->unk_D0 = -1;
    (*(u32 *)&this->unk_C8) = 0;
    this->m_ac = 0;
    this->m_cc = 0;
    this->m_d4 = 0;
    *(u32 *)&this->unk_D8 = 0;
    TOKey__sub_80169FB0((void*)((void *)((char *)this + 152)));
    this->m_dc = 0;
    this->m_e0 = 1;
    return this;
}

void TOKey__sub_80169FB0(void* p) { *(s32*)((char*)p + 0x0) = 1; }
}
