#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/frontend/TAdSelectTxtSubGC.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/network/TLobby.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/render/GinjaTexture.h"
#include "pso/player/PlayerStats.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/PlayerGuildCardTag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"

// The select screen's text textures, English set then Japanese set. inferred: names from the f256_selectgamen_*
// texture files they list; load_select_gamen_texture picks a set by current_language (0 = Japanese).
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
const char *TAdSelectTxtGC::class_name = "TAdSelectTxtGC";

void disp_data_part2::clear() {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        name[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        smth[i] = 0;
    }
    extra_model = 0;
    name_colour = 0;
    for (i = 0; i < 15; i++) {
        padding[i] = 0;
    }
    v1_flags = 0;
    version = 0;
    v2_flags = 0;
    char_class = 0;
    section_id = 0;
    name_colour_checksum = 0;
    for (i = 0; i < 8; i++) {
        appearance_data[i] = 0;
    }
    proportions.y = 0.0f;
    proportions.x = 0.0f;
}


NJS_TEXLIST *ad_select_text_texture_handle;
extern const s32 current_language;

void player_stats::clear() {
    stats.dfp = 0;
    stats.hp = 0;
    stats.evp = 0;
    stats.mst = 0;
    stats.atp = 0;
    esp = 0;
    stats.lck = 0;
    stats.ata = 0;
    proportions = 0.0f;
    knockback_resist = 0.0f;
    meseta = 0;
    exp = 0;
    level = 0;
}

void PlayerGuildCardTag::clear() { tag0 = 0; tag1 = 0; tag2 = 0; guildcard_number = 0; }
s32 TObjPlayer::get_control_role() { return control_role; }

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

TAdSelectTxtGC::TAdSelectTxtGC(TObject *parent, TAdSelectTxtLayout *layout, s32 value) : TObject(parent) {
    this->m_name = TAdSelectTxtGC::class_name;
    this->init_slot_entries(layout, value);
}

void free_select_gamen_texture() {
    if (ad_select_text_texture_handle != NULL) {
        release_texture_list(ad_select_text_texture_handle);
        ad_select_text_texture_handle = NULL;
    }
}
void load_select_gamen_texture() {
    update_menu_cursor();
    const char *texture_files[5] = {"f256_selectgamen_a", "f256_selectgamen_a_eng", "f256_selectgamen_a_eng",
                                    "f256_selectgamen_a_eng", "f256_selectgamen_a_eng"};
    NJS_TEXLIST *texture_lists[5] = {&select_gamen_texture_list, &select_gamen_eng_texture_list,
                                     &select_gamen_eng_texture_list, &select_gamen_eng_texture_list,
                                     &select_gamen_eng_texture_list};
    NJS_TEXLIST *list = texture_lists[current_language];
    ad_select_text_texture_handle = list;
    load_streamed_prs_texture(texture_files[current_language], list);
}
