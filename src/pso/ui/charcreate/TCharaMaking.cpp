#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028EA88.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/ui/charcreate/CharacterCreationTextureCache.h"
#include "pso/ui/charcreate/CharacterCreationModels.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/object/TCMCharacter.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/charcreate/TCharaMaking_8028E3F4.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/system/save/TSaveChCr.h"
#include "pso/math/AngleLookup.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/camera/TCameraCtrl.h"

// The character-creation motion archive: no models, 49 body motions.
const char *charamakingmot_model_names[1] = {NULL};
const char *charamakingmot_motion_names[50] = {
    "pxuS01_B02_F_body.njm", "pxuS01_B02_W_body.njm",
    "pxuS01_C01_F_body.njm", "pxuS01_C02_F_body.njm",
    "pxuS01_C03_F_body.njm", "pxuS01_C04_F_body.njm",
    "pxuS01_C07_W_body.njm", "pxuS03_C01_W_body.njm",
    "pxuS03_C02_W_body.njm", "pxuZ00_A01_F_body.njm",
    "pxuZ00_A01_M_body.njm", "pxuZ00_A01_W_body.njm",
    "pxuZ00_A03_F_body.njm", "pxuZ00_A03_M_body.njm",
    "pxuZ00_A03_W_body.njm", "pxuZ00_A04_F_body.njm",
    "pxuZ00_A04_M_body.njm", "pxuZ00_A04_W_body.njm",
    "pxuZ00_A05_F_body.njm", "pxuZ00_A05_M_body.njm",
    "pxuZ00_A05_W_body.njm", "pxuZ00_A06_F_body.njm",
    "pxuZ00_A06_M_body.njm", "pxuZ00_A06_W_body.njm",
    "pxuZ00_A07_F_body.njm", "pxuZ00_A07_M_body.njm",
    "pxuZ00_A07_W_body.njm", "pxuZ00_A08_F_body.njm",
    "pxuZ00_A08_M_body.njm", "pxuZ00_A08_W_body.njm",
    "pxuZ00_B01_F_body.njm", "pxuZ00_B01_M_body.njm",
    "pxuZ00_B01_W_body.njm", "pxuZ00_B02_M_body.njm",
    "pxuZ00_C01_M_body.njm", "pxuZ00_C02_M_body.njm",
    "pxuZ00_C03_M_body.njm", "pxuZ00_C03_W_body.njm",
    "pxuZ00_C04_M_body.njm", "pxuZ00_C04_W_body.njm",
    "pxuZ00_C08_F_body.njm", "pxuZ00_C08_M_body.njm",
    "pxuZ00_C08_W_body.njm", "pxuZ00_C09_F_body.njm",
    "pxuZ00_C09_M_body.njm", "pxuZ00_C09_W_body.njm",
    "pxuZ00_C10_F_body.njm", "pxuZ00_C10_M_body.njm",
    "pxuZ00_C10_W_body.njm",
    NULL,
};
BmlResourceDescriptor creation_menu_resource_descriptor = {
    "charamakingmot.bml", charamakingmot_model_names, charamakingmot_motion_names, 0, 49,
};
const char *TCharaMaking__name = "TCharaMaking";
// Per-class value passed with each player_class_texture_archive_table entry
// (19 entries, like the class tables).
const s32 lbl_8045122C[19] = {
    137, 310, 286, 208, 311, 386, 337, 355, 516, 386, 321, 333,
    16, 17, 14, 14, 14, 14, 14,
};

struct P_8028DCCC { f32 a; f32 b; };


u8 lbl_80518880[0x228];
u8 lbl_80518AA8[0x384];
u8 lbl_80518E2C[0x354];
u8 lbl_80519180[0x2B8];
u8 lbl_80519438[0x384];
u8 lbl_805197BC[0x41C];
u8 lbl_80519BD8[0x3B8];
u8 lbl_80519F90[0x3DC];
u8 lbl_8051A36C[0x520];
u8 lbl_8051A88C[0x41C];
u8 lbl_8051ACA8[0x398];
u8 lbl_8051B040[0x3B0];
u8 lbl_8051B3F0[0x138];
u8 lbl_8051B528[0x138];
u8 lbl_8051B660[0x134];
u8 lbl_8051B794[0x134];
u8 lbl_8051B8C8[0x134];
u8 lbl_8051B9FC[0x134];
u8 lbl_8051BB30[0x134];
u8 chara_making_load_buffer[0x40C];

void *player_class_texture_buffer_table[19] = {
    lbl_80518880, lbl_80518AA8, lbl_80518E2C, lbl_80519180, lbl_80519438,
    lbl_805197BC, lbl_80519BD8, lbl_80519F90, lbl_8051A36C, lbl_8051A88C,
    lbl_8051ACA8, lbl_8051B040, lbl_8051B3F0, lbl_8051B528, lbl_8051B660,
    lbl_8051B794, lbl_8051B8C8, lbl_8051B9FC, lbl_8051BB30,
};
s32 player_class_trait_table[12] = {
    0x25, 0x2A, 0x31, 0x45, 0x51, 0x52, 0x86, 0x89, 0x8A, 0x32, 0x85, 0x46,
};
P_8028DCCC character_proportion_height_table[12] = {
    {15.0f, 20.0f}, {14.0f, 18.0f}, {18.0f, 21.5f}, {16.0f, 20.0f},
    {17.0f, 21.0f}, {14.5f, 19.0f}, {14.5f, 17.5f}, {16.5f, 20.0f},
    {14.0f, 17.5f}, {13.0f, 18.0f}, {14.8f, 20.5f}, {14.2f, 18.3f},
};

extern "C" {
s32 TCharaMaking__sub_8028E3A0(f32 *arg0);
}
CharacterAppearanceFields *get_class_appearance_preset(s32 arg0);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
CharacterAppearanceFields *creation_player_character;
TObjCMMainMenu *creation_main_menu_obj;
extern "C" {
s32 release_texture_list(void *);


s32 TCharaMaking::query_state() {
    if (creation_main_menu_obj == NULL) {
        return -1;
    }
    return TObjCMMainMenu__sub_8028EBCC(creation_main_menu_obj);
}

s32 calc_section_id_from_name(s8 *name) {
    s32 sum = 0;
    s32 i;
    s32 r;
    for (i = 0; i < 12 && name[i] != 0; i++) {
        sum += name[i];
    }
    sum %= 10;
    if (sum < 0 || sum >= 10) sum = 0;
    return sum;
}
}
s32 validate_player_visual_record(void *arg0);
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
f32 calc_character_height(CharacterAppearanceFields *appearance) {
    f32 a;
    f32 b;
    f32 v = appearance->height;
    s32 k = appearance->classId;
    a = character_proportion_height_table[k].a;
    b = character_proportion_height_table[k].b;
    if (v < 0.0f || v > 1.0f) {
        v = 0.0f;
    }
    return v * (a - b) + b;
}
#pragma pop

// Render flags OR'ed into model_render_flags for the hair pass. The original
// loads them from .sdata2 (lwz) between the pool's 1.0 and 1/255, so they are
// a const object, not a folded literal.
static const s32 lbl_805DD930[1] = {0x81C};

#pragma push
#pragma opt_dead_assignments off
#pragma opt_propagation off

void TCharaMaking__draw_colored_hair(f32 alpha, saddr child, CharacterAppearanceFields *character_appearance_fields, s32 specialColor) {
    struct Color { f32 a, r, g, b; } color;
    s32 temp_r3;
    s32 second;
    s32 first;
    s32 temp_r8;
    temp_r8 = model_render_flags;
    first = chunk_polygon_flags_and_mask;
    second = chunk_polygon_flags_or_mask;
    temp_r3 = temp_r8 & 0xFFFFFFDF;
    model_render_flags = temp_r3;
    saved_model_render_flags = temp_r8;
    saved_chunk_polygon_flags_and_mask = first;
    saved_chunk_polygon_flags_or_mask = second;
    model_render_flags = temp_r3 | lbl_805DD930[0];
    if (alpha < 1.0f) {
        set_chunk_material_override_pair(-1, 0x800);
    }
    if (specialColor != 0) {
        set_shadow_material_state();
    } else {
        color.a = alpha;
        color.r = (1.0f / 255.0f) * (f32) character_appearance_fields->red;
        color.g = (1.0f / 255.0f) * (f32) character_appearance_fields->green;
        color.b = (1.0f / 255.0f) * (f32) character_appearance_fields->blue;
        set_constant_material((const NJS_ARGB *)((&color.a)));
    }
    draw_chunk_object((void *)child);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}
#pragma pop

void TCharaMaking::setup_from_data(s32 model, CharacterAppearanceFields *appearance) {
    TCharaMaking__draw_colored_hair(1.0f, model, appearance, 0);
}

CharacterAppearanceFields *get_class_appearance_preset(s32 arg0) {
    s32 var_r3;
    var_r3 = arg0;
    if ((var_r3 < 0) || (var_r3 >= 0xD)) {
        var_r3 = 0;
    }
    return &class_appearance_preset_table[var_r3];
}

void TCharaMaking::free_loaded_buffers() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x8B8) != 0) {
        if (!(*(s32 *)((s8 *)arg0 + 0xCFC) & 1)) {
            release_texture_list(arg0 + 0xA1C);
        }
        *(s32 *)((s8 *)arg0 + 0x8B8) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0xA24) != 0) {
        if (!(*(s32 *)((s8 *)arg0 + 0xCFC) & 2)) {
            release_texture_list(arg0 + 0xB88);
        }
        *(s32 *)((s8 *)arg0 + 0xA24) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0xB90) != 0) {
        if (!(*(s32 *)((s8 *)arg0 + 0xCFC) & 4)) {
            release_texture_list(arg0 + 0xCF4);
        }
        *(s32 *)((s8 *)arg0 + 0xB90) = 0;
    }
}

void TCharaMaking::update_body_parts() {
    u8 *arg0 = (u8 *)this;
    validate_player_visual_record(arg0 + 0x85C);
    *(f32 *)((s8 *)arg0 + 0xD48) = calc_character_height((CharacterAppearanceFields *)(arg0 + 0x85C));
    TCharaMaking__bind_appearance_texture_lists(reinterpret_cast<CharacterTextureLoadSet *>(arg0 + 0x8B8),
        reinterpret_cast<CharacterTextureLoadSet *>(arg0 + 0xA24),
        reinterpret_cast<CharacterTextureLoadSet *>(arg0 + 0xB90),
        reinterpret_cast<CharacterAppearanceFields *>(arg0 + 0x85C));
    TChCrLoadReq::create(arg0);
}

s32 validate_player_visual_record(void *arg0) {
    s32 bad;
    s32 ok;
    s32 flags;
    CharacterAppearanceFields *d;
    s32 i;
    CharacterClassAppearance *row;
    s32 v;
    s32 lim;
    d = (CharacterAppearanceFields *)arg0;
    bad = 0;
    ok = 1;
    flags = 0;
    if (d->name[0] == 0) {
        bad = 1;
    }
    if (bad == 0) {
        char *p;
        char *end;
        s32 found;
        end = d->name + 0xD;
        found = 0;
        for (p = d->name; p < end; p++) {
            if (*p == 0) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            bad = 1;
        }
    }
    if (bad == 0) {
        char *q;
        for (q = d->name; *q != 0; q++) {
            if (*q < 0x20 || *q >= 0x7F) {
                bad = 1;
                break;
            }
        }
    }
    if (bad == 0) {
        char *q;
        q = d->name;
        while (*q == 0x20) {
            q++;
        }
        if (*q == 0) {
            bad = 1;
        }
    }
    if (bad != 0) {
        d->name[0] = d->name[1] = d->name[2] = '-';
        ok = 0;
        d->name[3] = 0;
    }
    if ((u32)(d->nameColor & 0xFF000000) != 0xFF000000) {
        d->nameColor = -1;
    }
    if (d->section == -1) {
        d->section = 0;
    }
    if (d->section < 0 || d->section >= 10) {
        flags |= 1;
        ok = 0;
        d->section %= 10;
    }
    if (d->classId < 0 || d->classId >= 12) {
        flags |= 2;
        d->classId = 0;
        ok = 0;
    }
    if ((s32)d->classFlags != player_class_trait_table[d->classId]) {
        d->classFlags = player_class_trait_table[d->classId];
        flags |= 4;
        ok = 0;
    }
    row = &class_appearance_table[d->classId];
    for (i = 0; i < 5; i++) {
        lim = row->counts[i];
        v = (&d->costume)[i];
        if (v < 0 || (lim == 0 && v != 0) || (lim > 0 && v >= lim)) {
            (&d->costume)[i] = 0;
            ok = 0;
        }
    }
    for (; i < 8; i++) {
        v = (&d->costume)[i];
        if (v < 0 || v > 0xFF) {
            (&d->costume)[i] = 0;
            ok = 0;
        }
    }
    if (TCharaMaking__sub_8028E3A0(&d->width) != 0) {
        ok = 0;
    }
    if (flags != 0) {
        d->flags |= flags;
    }
    return ok;
}

void TCharaMaking::clear_flag_bit0() { restore_alpha_ref(); model_render_flags = (model_render_flags & 0xfffffffe); }

void TCharaMaking::enable_making() { model_render_flags = (model_render_flags | 0x1); set_alpha_ref_override((u8)31); }
void TCharaMaking__bind_appearance_texture_lists(CharacterTextureLoadSet *hair, CharacterTextureLoadSet *head, CharacterTextureLoadSet *body, CharacterAppearanceFields *appearance) {
  CharacterClassAppearance *definition;
  CharacterTextureList **hairTextures;
  CharacterTextureList **headTextures;
  CharacterTextureList *source;
  CharacterClassAppearance *new_var;
  CharacterTextureList *temp_r6_2;
  new_var = &class_appearance_table[character_display_index(reinterpret_cast<uaddr>(appearance))];
  hair->present = 0;
  definition = new_var;
  hairTextures = definition->hairTextures;
  if (hairTextures != 0)
  {
    source = hairTextures[appearance->hair];
    if (source != 0)
    {
      hair->build_appearance_texture_names(appearance, definition, source);
      hair->present = 1;
    }
  }
  head->present = 0;
  headTextures = definition->headTextures;
  if (headTextures != 0)
  {
    temp_r6_2 = headTextures[appearance->head];
    if (temp_r6_2 != 0)
    {
      head->build_appearance_texture_names(appearance, definition, temp_r6_2);
      head->present = 1;
    }
  }
  body->build_appearance_texture_names(appearance, definition, definition->bodyTextures);
  body->present = 1;
}
s32 TCharaMaking__sub_8028E3A0(f32 *arg0) {
    if (arg0[0] < 0.0f || arg0[0] >= 1.0f || arg0[1] < 0.0f || arg0[1] >= 1.0f) {
        arg0[0] = 0.0f;
        arg0[1] = 0.0f;
        return 1;
    }
    return 0;
}

extern "C" {
s32 TLobby__sub_801E3E9C(s32, const void *, void *, s32);

s32 TCharaMaking::is_end() {
    if ((get_main_phase() == 0xF) || (is_quest_active() != 0)) {
        return 1;
    }
    return 0;
}

s32 character_display_index(uaddr appearance_record) {
    const char *appearance = reinterpret_cast<const char *>(appearance_record);
    u8 model;

    if (!(appearance[offsetof(CharacterAppearanceFields, flags)] & 0xA)) {
        return appearance[offsetof(CharacterAppearanceFields, classId)];
    }
    if ((appearance[offsetof(CharacterAppearanceFields, version)] <= 0) ||
        ((s8)(model = appearance[offsetof(CharacterAppearanceFields, extraModel)]) < 0) ||
        ((s8)model >= 7)) {
        return appearance[offsetof(CharacterAppearanceFields, classId)];
    }
    if (TCharaMaking::is_end() != 0) {
        return 0x12 - appearance[offsetof(CharacterAppearanceFields, extraModel)];
    }
    return appearance[offsetof(CharacterAppearanceFields, classId)];
}

}
void CharacterTextureLoadSet::build_appearance_texture_names(CharacterAppearanceFields *appearance, CharacterClassAppearance *definition, CharacterTextureList *source) {
    if (source->count <= 8) {
        int index;
        NJS_TEXNAME *slot;
        const char **entry;
        char *name;
        slot = list.textures = entries;
        index = 0;
        list.nbTexture = source->count;
        entry = source->entries;
        for (; index < source->count; ++index, ++entry, ++slot) {
            name = names[index];
            strlen(*entry);
            strncpy(name, *entry, 31);
            name[31] = 0;
            if (definition->counts[0] > 0) {
                char *digit = &name[6];
                if (*digit++ != '0' || *digit != '0') {
                switch ((s8)name[4]) {
                case 'b': case 't':
                    { int costume = appearance->costume + 1;
                    name[6] = costume / 10 + '0';
                    *digit = costume % 10 + '0'; }
                    break;
                }
            }
            }
            if (definition->counts[1] > 0 && name[8] != 'z') {
                switch ((s8)name[4]) {
                case 'b': case 'f': case 't': name[8] = appearance->skin + 'a'; break;
                }
            }
            if (definition->counts[2] > 0 && name[7] != '0') {
                switch (name[4]) {
                case 'f': name[7] = appearance->face + '1'; break;
                }
            }
            if (name[4] == 'c') {
                if (appearance->flags & 1 || (s8)appearance->section == -1) name[8] = 'z';
                else name[8] = appearance->section + 'a';
            }
            slot->filename = name;
            slot->texaddr = 0;
            slot->attr = 0;
        }
    }
}

void request_chara_making_archives(void) {
    s32 i;
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        return;
    }
    for (i = 0; i < 0x13; i++) {
        if (TQuestVmDownLoadServer::is_ready() != 0) {
            return;
        }
        if (TLobby__sub_801E3E9C(player_class_texture_archive_table[i].archiveId, player_class_texture_archive_table[i].archiveName, player_class_texture_buffer_table[i], lbl_8045122C[i]) != 0) {
            if (TQuestVmDownLoadServer::is_ready() == 0) {
                return;
            }
            return;
        }
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        return;
    }
    if (TLobby__sub_801E3E9C(0xDB, "PLZSMPNJ.AFS", chara_making_load_buffer, 0x17A) != 0) {
        if (TQuestVmDownLoadServer::is_ready() == 0) {
            return;
        }
    }
}
extern "C" {


void TCharaMaking__sub_8028E790(void) {  }
}

extern saddr tl_03;

void TCharaMaking::update_light_direction() {
    f32 temp_f31;
    scene_light_state.direction.y = -1.0f * sin_table_lookup(m_1c);
    temp_f31 = cos_table_lookup(m_1c);
    scene_light_state.direction.x = temp_f31 * sin_table_lookup(m_20);
    scene_light_state.direction.z = temp_f31 * cos_table_lookup(m_20);
}

s32 TCharaMaking::update_main_menu(saddr arg0) {
    saddr var_r3;

    if (creation_main_menu_obj->is_state_3() != 0) {
        fn_8028D8F4();
        var_r3 = 0;
        if ((s32) creation_dressing_room_mode_flag == 1) {
            var_r3 = 1;
        }
        TSaveChCr::create(var_r3);
        end_creation_view();
        ((TObject *)arg0)->queue_destruction();
        return 1;
    }
    if (creation_main_menu_obj->is_state_4() != 0) {
        ((TObject *)arg0)->queue_destruction();
        TChCrCharSelect::create((TObject *)tl_03);
        return 1;
    }
    return 0;
}

void TCharaMaking::run_task() {
    if (!TAdSinglePlyChrSelectGC::is_active()) return;
    if (TCharaMaking::update_main_menu((saddr)this)) return;
}

void *TCharaMaking::create(void *parent, void *arg1) {
    creation_player_character = (CharacterAppearanceFields *)arg1;
    return new TCharaMaking((TObject *)parent);
}

TCharaMaking::~TCharaMaking() {
    creation_player_character = NULL;
    creation_main_menu_obj = NULL;
}

TCharaMaking::TCharaMaking(TObject *parent) : TObject(parent) {
    m_name = TCharaMaking__name;
    new TCMCharacter(this);
    creation_main_menu_obj = TObjCMMainMenu::create(this);
    m_1c = 0x1555;
    m_20 = 0x9000;
    update_light_direction();
}
