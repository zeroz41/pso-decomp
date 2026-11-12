#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"

struct O_802A15BC {
    u8 a[0x10];
    u8 b[8];
    s32 f18;
    u8 f1c;
    u8 c[15];
    s32 f2c;
    u8 f30, f31, f32_, f33;
    s32 f34;
    s16 d[8];
    f32 f48;
    f32 f4c;
};

extern "C" {

void clear_player_data_block(O_802A15BC *arg0);
void clear_player_data_block(O_802A15BC *arg0) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        arg0->a[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        arg0->b[i] = 0;
    }
    arg0->f1c = 0;
    arg0->f18 = 0;
    for (i = 0; i < 15; i++) {
        arg0->c[i] = 0;
    }
    arg0->f34 = 0;
    arg0->f33 = 0;
    arg0->f32_ = 0;
    arg0->f31 = 0;
    arg0->f30 = 0;
    arg0->f2c = 0;
    for (i = 0; i < 8; i++) {
        arg0->d[i] = 0;
    }
    arg0->f4c = 0.0f;
    arg0->f48 = 0.0f;
}

}

struct Sel_802A16CC {
    u8 pad0[0xC0];
    void *slots[7];
};

struct Ent_802A1740 { u8 b[0x14]; };

struct Sel_802A1740 {
    u8 pad0[0x1C];
    Ent_802A1740 ent[8];
    s32 cnt;
    void *tasks[8];
};

struct Ent_802A1838 {
    u8 pad[0x1C];
    void *f0;
    s32 f4;
    u8 v[8];
    s32 f10;
};

struct Sel_802A1838 {
    u8 pad0[0xBC];
    s32 cnt;
    void *tasks[8];
};

struct Src_802A1838 {
    s32 f0;
    u8 v[8];
};

struct Tbl_802A194C { s32 v[5]; };

extern "C" {
void *__nw__7TObjectFUl(s32);
void *__ct__17TAdSelectTxtSubGCFv(void *, void *, void *);
extern Tbl_802A194C select_gamen_resource_name_table;
extern Tbl_802A194C select_gamen_resource_name_table_b;
extern const s32 current_language;
extern u32 ad_select_text_texture_handle;
void release_texture_list(void*);

void TAdSelectTxtGC::reset_state() { *(short *)&this->m_prev = 0; *(short *)&this->m_id = 0; *(short *)&this->m_flags = 0; *(short*)((char*)this + 0x2) = 0; *(short *)&this->m_name = 0; *(short*)((char*)this + 0xe) = 0; *(short *)&this->m_next = 0; *(short*)((char*)this + 0xa) = 0; *(float *)&this->m_up = 0.0f; *(float *)&this->m_down = 0.0f; *(int*)((char*)this + 0x20) = 0; *(int*)((char*)this + 0x1c) = 0; *(int*)((char*)this + 0x18) = 0; }

void TAdSelectTxtGC__sub_802A16A8(void* p) { *(u8*)((char*)p + 0x0) = 0; *(u8*)((char*)p + 0x1) = 0; *(s16*)((char*)p + 0x2) = 0; *(s32*)((char*)p + 0x4) = 0; }
s32 TAdSelectTxtGC__sub_802A16C0(void* p) { return *(s32*)((char*)p + 0x3e8); }

void TAdSelectTxtGC::render() {  }

void TAdSelectTxtGC::reset_slots(void *arg1, void *arg2) {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (((Sel_802A16CC *)this)->slots[i] != 0) {
            ((TObject *)(((Sel_802A16CC *)this)->slots[i]))->queue_destruction();
            ((Sel_802A16CC *)this)->slots[i] = 0;
        }
    }
    ((TAdSelectTxtGC *)((Sel_802A16CC *)this))->init_slot_entries((Src_802A1838 *)(arg1), arg2);
}

extern void *lbl_805D3D88;

void TAdSelectTxtGC::run_task() {
    Sel_802A1740 *arg0 = (Sel_802A1740 *)this;
    void *o;
    arg0->cnt = arg0->cnt + 1;
    if (arg0->cnt % 3 == 0 && arg0->cnt / 3 < 8) {
        o = __nw__7TObjectFUl(0x88);
        if (o != NULL) {
            o = __ct__17TAdSelectTxtSubGCFv(o, arg0, &arg0->ent[arg0->cnt / 3]);
        }
        arg0->tasks[arg0->cnt / 3] = o;
    }
}

TAdSelectTxtGC::~TAdSelectTxtGC() {}
void TAdSelectTxtGC::init_slot_entries(void *arg1_arg, void *arg2) {
    Sel_802A1838 *arg0 = (Sel_802A1838 *)this;
    Src_802A1838 *arg1 = (Src_802A1838 *)arg1_arg;
    Ent_802A1838 *e;
    s32 i;
    arg0->cnt = -1;
    for (i = 0; i < 8; i++) {
        e = (Ent_802A1838 *)((u8 *)arg0 + i * 0x14);
        e->f0 = arg2;
        e->f4 = i;
        ((TWindowSubSymbolChatPartsSet *)(e->v))->copy_vec2(arg1->v);
        e->f10 = arg1->f0;
        arg0->tasks[i] = NULL;
    }
}

}
TAdSelectTxtGC::TAdSelectTxtGC(TObject *object, void *arg1_arg, void *arg3) : TObject(object) {
    *(void * *)&this->m_name = lbl_805D3D88;
    this->init_slot_entries((Src_802A1838 *)(arg1_arg), arg3);
}

void TLobby__sub_802A1918(void) {
    if ((u32) ad_select_text_texture_handle != 0U) {
        release_texture_list((void*)ad_select_text_texture_handle);
        ad_select_text_texture_handle = 0U;
    }
}
void TLobby__sub_802A194C(void) {
    TLobby::update_menu_cursor();
    Tbl_802A194C a = select_gamen_resource_name_table;
    Tbl_802A194C b = select_gamen_resource_name_table_b;
    s32 i = current_language;
    s32 v = b.v[i];
    ad_select_text_texture_handle = v;
    TLobby__sub_8023E4B4(a.v[i], v);
}
