#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8028C8E0.h"
#include "pso/misc/TChCrLoadReq.h"
#include "pso/misc/TCharaMaking.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8028D360___vt__12TChCrLoadReq { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8028D360___vt__12TChCrLoadReq_size[sizeof(RecoveredGlobal_8028D360___vt__12TChCrLoadReq) == 0x18 ? 1 : -1];

 s32 chr_select_load_slot_count;

struct B_8028D214 { s32 a0; s32 a4; s32 a8; };

struct Rq_8028D214 { u8 pad0[0x38]; void *f38; s32 f3c; s32 f40; s32 *f44; B_8028D214 *f48; u8 pad4c[0xC]; s32 f58; u8 *f5c; s32 f60; s32 f64; u8 pad68[0xC]; s32 w[6]; s32 f8c; };

extern "C" {
u16 get_entity_id(void *);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__12TChCrLoadReq[];
extern void *lbl_805D3B60;
u8 *TChCrLoadReq__sub_8028D360(TChCrLoadReq *arg0, s32 arg1);
void TLobby__sub_8028D738(s32, s32);
extern u8 class_appearance_table[];
void *__ct__12TChCrLoadReqFP7TObjectPv(void *arg0, void *arg1, void *arg2);
void *__dt__12TChCrLoadReqFv(void *arg0, s16 arg1);
void sub_8028CEEC__12TChCrLoadReqFPl(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void *__nw__7TObjectFUl(int);
}
void * create_ch_cr_load_req(void *arg0, void *arg1);
void TChCrLoadReq::update_load_progress() {
    void *arg0 = this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x64) > 0x1512) {
        if (TAdSinglePlyChrSelectGC__sub_8028CF6C() == 0) {
            *(s32 *)((s8 *)arg0 + 0x64) = 0x1512;
            goto block_3;
        }
    } else {
block_3:
        if (((TAdSinglePlyChrSelectGC *)arg0)->try_claim_load_slot() != 0) {
            ((TAdSinglePlyChrSelectGC *)arg0)->request_model_loads();
            ((TAdSinglePlyChrSelectGC *)arg0)->request_texture_loads();
            *(s32 *)((s8 *)arg0 + 0x60) = 1;
        }
    }
}

void TChCrLoadReq::run_task() {
    if (--timer <= 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    static void (TChCrLoadReq::*tbl[3])() = { &TChCrLoadReq::update_load_progress, &TChCrLoadReq::try_advance_state, &TChCrLoadReq::close_and_destroy };
    (this->*tbl[state])();
}

void *__dt__12TChCrLoadReqFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TChCrLoadReq;
        sub_8028CEEC__12TChCrLoadReqFPl(arg0);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TChCrLoadReq::reset_request() {
    Rq_8028D214 *arg0 = (Rq_8028D214 *)this;
    s32 i;
    s32 t;
    arg0->f58 = (s32)((u8 *)arg0->f48 + 8);
    t = ((TCharaMaking *)(arg0->f38))->get_display_index() * 0x2C;
    arg0->f5c = class_appearance_table + t;
    TLobby__sub_8028D738(arg0->f40, t);
    arg0->f44[0] = 0;
    arg0->f48->a4 = 0;
    arg0->f48->a0 = 0;
    arg0->f48->a8 = 0;
    for (i = 0; i < 6; i++) {
        arg0->w[i] = 0;
    }
    arg0->f8c = 0;
    arg0->f64 = 0x1518;
    arg0->f60 = 0;
}

TChCrLoadReq::TChCrLoadReq(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = lbl_805D3B60;
    ((TChCrLoadReq *)((char *)this + 56))->copy(arg2);
    this->reset_request();
}

void TChCrLoadReq::copy(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); *(u32 *)&this->m_prev = *(u32*)((char*)q + 0x8); *(u32 *)&this->m_next = *(u32*)((char*)q + 0xc); *(u32 *)&this->m_up = *(u32*)((char*)q + 0x10); *(u32 *)&this->m_down = *(u32*)((char*)q + 0x14); *(u32*)((char*)this + 0x18) = *(u32*)((char*)q + 0x18); *(u32*)((char*)this + 0x1c) = *(u32*)((char*)q + 0x1c); }

u8 *TChCrLoadReq__sub_8028D360(TChCrLoadReq *ch_cr_load_req, s32 arg1) {
    __ct__7TObjectFP7TObject((void *)ch_cr_load_req, (void *)arg1);
    *(s32 **)((s8 *)ch_cr_load_req + 0x18) = &(*(RecoveredGlobal_8028D360___vt__12TChCrLoadReq *)&__vt__12TChCrLoadReq).value;
    *(s32 *)((s8 *)ch_cr_load_req + 0) = (s32) (*(s32 *)&lbl_805D3B60);
    ch_cr_load_req->m_38 = (arg1 + 0x85C);
    *(s32 *)((s8 *)ch_cr_load_req + 0x3C) = (arg1 + 0xCFC);
    ch_cr_load_req->m_40 = (s32) get_entity_id((void *)arg1);
    *(s32 *)((s8 *)ch_cr_load_req + 0x44) = (arg1 + 0x34);
    ch_cr_load_req->m_48 = (arg1 + 0x8AC);
    *(s32 *)((s8 *)ch_cr_load_req + 0x4C) = (arg1 + 0xCF4);
    ch_cr_load_req->m_50 = (arg1 + 0xB88);
    *(s32 *)((s8 *)ch_cr_load_req + 0x54) = (arg1 + 0xA1C);
    ch_cr_load_req->reset_request();
    return (u8 *)ch_cr_load_req;
}

void * create_ch_cr_load_req(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x90);
    if (o != NULL) {
        o = __ct__12TChCrLoadReqFP7TObjectPv(o, arg0, arg1);
    }
    return o;
}

void *TChCrLoadReq::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x90);
    if (o != NULL) {
        o = TChCrLoadReq__sub_8028D360((TChCrLoadReq *)((u8 *)o), (s32)arg0);
    }
    return o;
}
