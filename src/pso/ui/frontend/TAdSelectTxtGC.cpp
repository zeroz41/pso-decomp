#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/frontend/TAdSelectTxtSubGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

// The select screen's text textures, English set then Japanese set. inferred: names from the f256_selectgamen_*
// texture files they list; TLobby__sub_802A194C picks a set by current_language (0 = Japanese).
static NJS_TEXNAME select_gamen_eng_texture_names[2] = {
    {"f256_selectgamen_a_eng", 0, 0},
    {"f256_selectgamen_b_eng", 0, 0},
};
static NJS_TEXLIST select_gamen_eng_texture_list = {select_gamen_eng_texture_names, 2};
static NJS_TEXNAME select_gamen_texture_names[2] = {
    {"f256_selectgamen_a", 0, 0},
    {"f256_selectgamen_b", 0, 0},
};
static NJS_TEXLIST select_gamen_texture_list = {select_gamen_texture_names, 2};
// inferred: same <Class>__class_name pattern as the other frontend tasks
const char *TAdSelectTxtGC__class_name = "TAdSelectTxtGC";

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


uaddr ad_select_text_texture_handle;
extern "C" {
extern const s32 current_language;
void release_texture_list(void*);

void TAdSelectTxtGC::reset_state() { *(short *)&this->m_prev = 0; *(short *)&this->m_id = 0; *(short *)&this->m_flags = 0; *(short*)((char*)this + 0x2) = 0; *(short *)&this->m_name = 0; *(short*)((char*)this + 0xe) = 0; *(short *)&this->m_next = 0; *(short*)((char*)this + 0xa) = 0; *(float *)&this->m_up = 0.0f; *(float *)&this->m_down = 0.0f; *(int*)((char*)this + 0x20) = 0; *(int*)((char*)this + 0x1c) = 0; *(int*)((char*)this + 0x18) = 0; }

void TAdSelectTxtGC__sub_802A16A8(void* p) { *(u8*)((char*)p + 0x0) = 0; *(u8*)((char*)p + 0x1) = 0; *(s16*)((char*)p + 0x2) = 0; *(s32*)((char*)p + 0x4) = 0; }
s32 TAdSelectTxtGC__sub_802A16C0(void* p) { return *(s32*)((char*)p + 0x3e8); }

void TAdSelectTxtGC::render() {  }

void TAdSelectTxtGC::reset_slots(TAdSelectTxtLayout *layout, s32 value) {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (lines[i] != NULL) {
            lines[i]->queue_destruction();
            lines[i] = NULL;
        }
    }
    init_slot_entries(layout, value);
}

void TAdSelectTxtGC::run_task() {
    spawn_count = spawn_count + 1;
    if (spawn_count % 3 == 0 && spawn_count / 3 < 8) {
        lines[spawn_count / 3] = new TAdSelectTxtSubGC(this, &entries[spawn_count / 3]);
    }
}

TAdSelectTxtGC::~TAdSelectTxtGC() {}
void TAdSelectTxtGC::init_slot_entries(TAdSelectTxtLayout *layout, s32 value) {
    s32 i;
    spawn_count = -1;
    for (i = 0; i < 8; i++) {
        entries[i].value = value;
        entries[i].index = i;
        copy_vec2(entries[i].position, layout->position);
        entries[i].text_id = layout->text_id;
        lines[i] = NULL;
    }
}

}
TAdSelectTxtGC::TAdSelectTxtGC(TObject *parent, TAdSelectTxtLayout *layout, s32 value) : TObject(parent) {
    this->m_name = TAdSelectTxtGC__class_name;
    this->init_slot_entries(layout, value);
}

void TLobby__sub_802A1918(void) {
    if ((u32) ad_select_text_texture_handle != 0U) {
        release_texture_list((void*)ad_select_text_texture_handle);
        ad_select_text_texture_handle = 0U;
    }
}
void TLobby__sub_802A194C(void) {
    TLobby::update_menu_cursor();
    const char *texture_files[5] = {"f256_selectgamen_a", "f256_selectgamen_a_eng", "f256_selectgamen_a_eng",
                                    "f256_selectgamen_a_eng", "f256_selectgamen_a_eng"};
    NJS_TEXLIST *texture_lists[5] = {&select_gamen_texture_list, &select_gamen_eng_texture_list,
                                     &select_gamen_eng_texture_list, &select_gamen_eng_texture_list,
                                     &select_gamen_eng_texture_list};
    NJS_TEXLIST *list = texture_lists[current_language];
    ad_select_text_texture_handle = (uaddr)list;
    load_streamed_prs_texture((saddr)texture_files[current_language], (saddr)list);
}
