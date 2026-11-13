#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028C8E0.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_8028D714.h"

#pragma push
#pragma readonly_strings on
const char *TChCrLoadReq__name = "TChCrLoadReq";
#pragma pop

 s32 chr_select_load_slot_count;

extern "C" {
u16 get_entity_id(void *);
extern s32 __vt__12TChCrLoadReq[];
void sub_8028CEEC__12TChCrLoadReqFPl(TChCrLoadReq *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
}
void * create_ch_cr_load_req(void *arg0, void *arg1);
void TChCrLoadReq::update_load_progress() {
    if (timer > 0x1512) {
        if (TAdSinglePlyChrSelectGC__sub_8028CF6C() == 0) {
            timer = 0x1512;
            goto claim;
        }
    } else {
claim:
        if (((TAdSinglePlyChrSelectGC *)this)->try_claim_load_slot() != 0) {
            ((TAdSinglePlyChrSelectGC *)this)->request_model_loads();
            ((TAdSinglePlyChrSelectGC *)this)->request_texture_loads();
            state = 1;
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

extern "C" TChCrLoadReq *__dt__12TChCrLoadReqFv(TChCrLoadReq *req, s16 free) {
    if (req != NULL) {
        *(s32 **)((u8 *)req + 0x18) = __vt__12TChCrLoadReq;
        sub_8028CEEC__12TChCrLoadReqFPl(req);
        __dt__7TObjectFv(req, 0);
        if (free > 0) {
            __dl__7TObjectFPv(req);
        }
    }
    return req;
}

void TChCrLoadReq::reset_request() {
    s32 i;
    s32 index;
    m_58 = m_48 + 2;
    index = ((TCharaMaking *)m_38)->get_display_index();
    m_5c = &class_appearance_table[index];
    TLobby__sub_8028D738(m_40);
    m_44[0] = 0;
    m_48[1] = 0;
    m_48[0] = 0;
    m_48[2] = 0;
    for (i = 0; i < 6; i++) {
        m_74[i] = 0;
    }
    m_8c = 0;
    timer = 0x1518;
    state = 0;
}
TChCrLoadReq::TChCrLoadReq(TObject *object, void *arg2) : TObject(object) {
    m_name = TChCrLoadReq__name;
    ((TChCrLoadReq *)((char *)this + 56))->copy(arg2);
    this->reset_request();
}

void TChCrLoadReq::copy(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); *(u32 *)&this->m_prev = *(u32*)((char*)q + 0x8); *(u32 *)&this->m_next = *(u32*)((char*)q + 0xc); *(u32 *)&this->m_up = *(u32*)((char*)q + 0x10); *(u32 *)&this->m_down = *(u32*)((char*)q + 0x14); *(u32*)((char*)this + 0x18) = *(u32*)((char*)q + 0x18); *(u32*)((char*)this + 0x1c) = *(u32*)((char*)q + 0x1c); }

// TObjPlayer has no fields yet at 0xCF4, 0xB88 and 0xA1C.
TChCrLoadReq::TChCrLoadReq(TObjPlayer *player) : TObject(player) {
    m_name = TChCrLoadReq__name;
    m_38 = (CharacterAppearanceFields *)player->name;
    m_3c = (u32 *)&player->m_cfc;
    m_40 = get_entity_id(player);
    m_44 = (s32 *)&player->model;
    m_48 = (s32 *)&player->m_8ac;
    m_4c = (u8 *)player + 0xCF4;
    m_50 = (u8 *)player + 0xB88;
    m_54 = (u8 *)player + 0xA1C;
    reset_request();
}

void *create_ch_cr_load_req(void *parent, void *arg1) {
    return new TChCrLoadReq((TObject *)parent, arg1);
}

void *TChCrLoadReq::create(void *parent) {
    return new TChCrLoadReq((TObjPlayer *)parent);
}
