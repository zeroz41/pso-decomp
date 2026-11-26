#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include <string.h>
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdEndText.h"
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
#include "pso/ui/charcreate/TCMCharacter.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/system/save/TSaveChCr.h"
#include "pso/math/AngleLookup.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby_801E2F94.h"

extern "C" {
u8 * copy_player_visual_record(void *, void *);
extern CharacterAppearanceFields character_creation_visual_record;
}
CharacterAppearanceFields *get_class_appearance_preset(s32 class_id);

CharacterAppearanceFields *get_character_creation_visual_record(void) {
    return &character_creation_visual_record;
}

void set_character_creation_visual_record(CharacterAppearanceFields *record) {
    if (record->flags & 0xA) {
        clear_character_creation_class();
        return;
    }
    copy_player_visual_record(&character_creation_visual_record, record);
}

void clear_character_creation_class(void) {
    character_creation_visual_record.classId = -1;
}

void copy_char_name(const char *name) {
    strncpy(character_creation_name_buffer, name, 0xC);
    character_creation_name_buffer[0xC] = 0;
}

void select_char_menu() {
    copy_char_name(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2.name);
}

s32 TObjCMMainMenu::validate_character_name(s8 *arg0) {
    s8 buf[13];
    s8 out[16];
    s32 found;
    s8 *p;
    s8 *q;
    strncpy((char *)buf, (const char *)arg0, 0xC);
    buf[12] = 0;
    found = 0;
    p = buf;
    while (*p != 0) {
        if (*p != 0x20) {
            found = 1;
            break;
        }
        p++;
    }
    if (found == 0) {
        *arg0 = 0;
        return 0;
    }
    if (TWindowSubComCard::contains_profanity((char *)buf) != 0) {
        *arg0 = 0;
        return 0;
    }
    p = buf;
    q = out;
    while (*p != 0) {
        if (is_alnum(*p) != 0) {
            *q = *p;
            q++;
        }
        p++;
    }
    *q = 0;
    if (TWindowSubComCard::contains_profanity((char *)out) != 0) {
        *arg0 = 0;
        return 0;
    }
    return 1;
}

s32 get_current_char_flag() {
    s32 x = (s8)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2.section_id;
    return (u32) __cntlzw(-1 - x) >> 5;
}
void reset_current_char_appearance(s32 _w0) {
    CharacterAppearanceFields *character_appearance_fields;
    character_appearance_fields = (CharacterAppearanceFields *)&TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2;
    copy_player_visual_record(character_appearance_fields, get_class_appearance_preset(0));
    character_appearance_fields->section = -1;
}
int TAdSinglePlyChrSelectGC__sub_8028DC14(void) { return 1; }
int TAdSinglePlyChrSelectGC__sub_8028DC1C(void* p) { reset_current_char_appearance((saddr)p); return 1; }

#define TOBJECT_OUT_OF_LINE_HELPERS

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
const char *TCharaMaking::name = "TCharaMaking";
// Per-class value passed with each player_class_texture_archive_table entry
// (19 entries, like the class tables).
const s32 player_class_texture_archive_length[19] = {
    137, 310, 286, 208, 311, 386, 337, 355, 516, 386, 321, 333,
    16, 17, 14, 14, 14, 14, 14,
};

struct P_8028DCCC { f32 a; f32 b; };

u8 player_class_texture_buffer_00[0x228];
u8 player_class_texture_buffer_01[0x384];
u8 player_class_texture_buffer_02[0x354];
u8 player_class_texture_buffer_03[0x2B8];
u8 player_class_texture_buffer_04[0x384];
u8 player_class_texture_buffer_05[0x41C];
u8 player_class_texture_buffer_06[0x3B8];
u8 player_class_texture_buffer_07[0x3DC];
u8 player_class_texture_buffer_08[0x520];
u8 player_class_texture_buffer_09[0x41C];
u8 player_class_texture_buffer_10[0x398];
u8 player_class_texture_buffer_11[0x3B0];
u8 player_class_texture_buffer_12[0x138];
u8 player_class_texture_buffer_13[0x138];
u8 player_class_texture_buffer_14[0x134];
u8 player_class_texture_buffer_15[0x134];
u8 player_class_texture_buffer_16[0x134];
u8 player_class_texture_buffer_17[0x134];
u8 player_class_texture_buffer_18[0x134];
u8 chara_making_load_buffer[0x40C];

void *player_class_texture_buffer_table[19] = {
    player_class_texture_buffer_00, player_class_texture_buffer_01, player_class_texture_buffer_02, player_class_texture_buffer_03, player_class_texture_buffer_04,
    player_class_texture_buffer_05, player_class_texture_buffer_06, player_class_texture_buffer_07, player_class_texture_buffer_08, player_class_texture_buffer_09,
    player_class_texture_buffer_10, player_class_texture_buffer_11, player_class_texture_buffer_12, player_class_texture_buffer_13, player_class_texture_buffer_14,
    player_class_texture_buffer_15, player_class_texture_buffer_16, player_class_texture_buffer_17, player_class_texture_buffer_18,
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
s32 TCharaMaking__sub_8028E3A0(f32 *uv);
}
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
}

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
static const s32 hair_render_flags[1] = {0x81C};

#pragma push
#pragma opt_dead_assignments off
#pragma opt_propagation off

void TCharaMaking__draw_colored_hair(f32 alpha, saddr child, CharacterAppearanceFields *character_appearance_fields, s32 specialColor) {
    struct Color { f32 a, r, g, b; } color;
    s32 flags_masked;
    s32 second;
    s32 first;
    s32 flags;
    flags = model_render_flags;
    first = chunk_polygon_flags_and_mask;
    second = chunk_polygon_flags_or_mask;
    flags_masked = flags & 0xFFFFFFDF;
    model_render_flags = flags_masked;
    saved_model_render_flags = flags;
    saved_chunk_polygon_flags_and_mask = first;
    saved_chunk_polygon_flags_or_mask = second;
    model_render_flags = flags_masked | hair_render_flags[0];
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

CharacterAppearanceFields *get_class_appearance_preset(s32 class_id) {
    s32 index;
    index = class_id;
    if ((index < 0) || (index >= 0xD)) {
        index = 0;
    }
    return &class_appearance_preset_table[index];
}

void TCharaMaking::free_loaded_buffers() {
    u8 *base = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)base + 0x8B8) != 0) {
        if (!(*(s32 *)((s8 *)base + 0xCFC) & 1)) {
            release_texture_list(base + 0xA1C);
        }
        *(s32 *)((s8 *)base + 0x8B8) = 0;
    }
    if ((s32) *(s32 *)((s8 *)base + 0xA24) != 0) {
        if (!(*(s32 *)((s8 *)base + 0xCFC) & 2)) {
            release_texture_list(base + 0xB88);
        }
        *(s32 *)((s8 *)base + 0xA24) = 0;
    }
    if ((s32) *(s32 *)((s8 *)base + 0xB90) != 0) {
        if (!(*(s32 *)((s8 *)base + 0xCFC) & 4)) {
            release_texture_list(base + 0xCF4);
        }
        *(s32 *)((s8 *)base + 0xB90) = 0;
    }
}

void TCharaMaking::update_body_parts() {
    u8 *base = (u8 *)this;
    validate_player_visual_record(base + 0x85C);
    *(f32 *)((s8 *)base + 0xD48) = calc_character_height((CharacterAppearanceFields *)(base + 0x85C));
    TCharaMaking__bind_appearance_texture_lists(reinterpret_cast<CharacterTextureLoadSet *>(base + 0x8B8),
        reinterpret_cast<CharacterTextureLoadSet *>(base + 0xA24),
        reinterpret_cast<CharacterTextureLoadSet *>(base + 0xB90),
        reinterpret_cast<CharacterAppearanceFields *>(base + 0x85C));
    TChCrLoadReq::create(base);
}

s32 validate_player_visual_record(void *record) {
    s32 bad;
    s32 ok;
    s32 flags;
    CharacterAppearanceFields *d;
    s32 i;
    CharacterClassAppearance *row;
    s32 v;
    s32 lim;
    d = (CharacterAppearanceFields *)record;
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
  CharacterClassAppearance *class_entry;
  CharacterTextureList *head_source;
  class_entry = &class_appearance_table[character_display_index(reinterpret_cast<uaddr>(appearance))];
  hair->present = 0;
  definition = class_entry;
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
    head_source = headTextures[appearance->head];
    if (head_source != 0)
    {
      head->build_appearance_texture_names(appearance, definition, head_source);
      head->present = 1;
    }
  }
  body->build_appearance_texture_names(appearance, definition, definition->bodyTextures);
  body->present = 1;
}
s32 TCharaMaking__sub_8028E3A0(f32 *uv) {
    if (uv[0] < 0.0f || uv[0] >= 1.0f || uv[1] < 0.0f || uv[1] >= 1.0f) {
        uv[0] = 0.0f;
        uv[1] = 0.0f;
        return 1;
    }
    return 0;
}


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
        if (open_afs_file_wait_render(player_class_texture_archive_table[i].archiveId, player_class_texture_archive_table[i].archiveName, player_class_texture_buffer_table[i], player_class_texture_archive_length[i]) != 0) {
            if (TQuestVmDownLoadServer::is_ready() == 0) {
                return;
            }
            return;
        }
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        return;
    }
    if (open_afs_file_wait_render(0xDB, "PLZSMPNJ.AFS", chara_making_load_buffer, 0x17A) != 0) {
        if (TQuestVmDownLoadServer::is_ready() == 0) {
            return;
        }
    }
}

void TCharaMaking__sub_8028E790(void) {  }

extern saddr tl_03;

void TCharaMaking::update_light_direction() {
    f32 cos_pitch;
    scene_light_state.direction.y = -1.0f * sin_table_lookup(light_pitch);
    cos_pitch = cos_table_lookup(light_pitch);
    scene_light_state.direction.x = cos_pitch * sin_table_lookup(light_yaw);
    scene_light_state.direction.z = cos_pitch * cos_table_lookup(light_yaw);
}

s32 TCharaMaking::update_main_menu(saddr task) {
    saddr dressing_room;

    if (creation_main_menu_obj->is_state_3() != 0) {
        fn_8028D8F4();
        dressing_room = 0;
        if ((s32) creation_dressing_room_mode_flag == 1) {
            dressing_room = 1;
        }
        TSaveChCr::create(dressing_room);
        end_creation_view();
        ((TObject *)task)->queue_destruction();
        return 1;
    }
    if (creation_main_menu_obj->is_state_4() != 0) {
        ((TObject *)task)->queue_destruction();
        TChCrCharSelect::create((TObject *)tl_03);
        return 1;
    }
    return 0;
}

void TCharaMaking::run_task() {
    if (!TAdSinglePlyChrSelectGC::is_active()) return;
    if (TCharaMaking::update_main_menu((saddr)this)) return;
}

void *TCharaMaking::create(void *parent, void *appearance) {
    creation_player_character = (CharacterAppearanceFields *)appearance;
    return new TCharaMaking((TObject *)parent);
}

TCharaMaking::~TCharaMaking() {
    creation_player_character = NULL;
    creation_main_menu_obj = NULL;
}

TCharaMaking::TCharaMaking(TObject *parent) : TObject(parent) {
    m_name = TCharaMaking::name;
    new TCMCharacter(this);
    creation_main_menu_obj = TObjCMMainMenu::create(this);
    light_pitch = 0x1555;
    light_yaw = 0x9000;
    update_light_direction();
}
