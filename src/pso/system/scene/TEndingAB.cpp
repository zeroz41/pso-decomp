#include "types.h"
#include "pso/system/scene/TEndingAB.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/scene/TScene.h"

struct EndingTextureName {
    const char *name;
    u32 attributes;
    void *texture;
};
struct EndingTextureList {
    EndingTextureName *entries;
    u32 count;
};
struct EndingWallTextureSet {
    EndingTextureName names[14];
    EndingTextureList list;
};
typedef char EndingTextureNameSize[sizeof(EndingTextureName) == 12 ? 1 : -1];
typedef char EndingWallTextureSetSize[sizeof(EndingWallTextureSet) == 0xB0 ? 1 : -1];

const char ending_texture_name_ed_512kabe_a[] = "ed_512kabe_A";
const char ending_texture_name_ed_512kabe_b[] = "ed_512kabe_B";
const char ending_texture_name_ed_256pict00a[] = "ed_256pict00a";
const char ending_texture_name_ed_256pict01[] = "ed_256pict01";
const char ending_texture_name_ed_256pict02a[] = "ed_256pict02a";
const char ending_texture_name_ed_256pict03a[] = "ed_256pict03a";
const char ending_texture_name_ed_256pict04[] = "ed_256pict04";
const char ending_texture_name_ed_256pict05a[] = "ed_256pict05a";
const char ending_texture_name_ed_256pict06a[] = "ed_256pict06a";
const char ending_texture_name_ed_256pict07a[] = "ed_256pict07a";
const char ending_texture_name_ed_256pict08[] = "ed_256pict08";
const char ending_texture_name_ed_256pict09[] = "ed_256pict09";
const char ending_texture_name_ed_256pict10a[] = "ed_256pict10a";
const char ending_texture_name_ed_256pict11a[] = "ed_256pict11a";
const char ending_texture_name_ed_256pict00b[] = "ed_256pict00b";
const char ending_texture_name_ed_256pict02b[] = "ed_256pict02b";
const char ending_texture_name_ed_256pict03b[] = "ed_256pict03b";
const char ending_texture_name_ed_256pict05b[] = "ed_256pict05b";
const char ending_texture_name_ed_256pict06b[] = "ed_256pict06b";
const char ending_texture_name_ed_256pict07b[] = "ed_256pict07b";
const char ending_texture_name_ed_256pict10b[] = "ed_256pict10b";
const char ending_texture_name_ed_256pict11b[] = "ed_256pict11b";
const char ending_texture_name_edu_256pict00[] = "edu_256pict00";
const char ending_texture_name_edu_256pict01[] = "edu_256pict01";
const char ending_texture_name_edu_256pict02[] = "edu_256pict02";
const char ending_texture_name_edu_256pict03[] = "edu_256pict03";
const char ending_texture_name_edu_256pict04[] = "edu_256pict04";
const char ending_texture_name_edu_256pict05[] = "edu_256pict05";
const char ending_texture_name_edu_256pict06[] = "edu_256pict06";
const char ending_texture_name_edu_256pict07[] = "edu_256pict07";
const char ending_texture_name_edu_256pict08[] = "edu_256pict08";
const char ending_texture_name_edu_256pict09[] = "edu_256pict09";
const char ending_texture_name_edu_256pict10[] = "edu_256pict10";
const char ending_texture_name_edu_256pict11[] = "edu_256pict11";
const char ending_texture_name_edura_256pict00[] = "edura_256pict00";
const char ending_texture_name_edura_256pict01[] = "edura_256pict01";
const char ending_texture_name_edura_256pict02[] = "edura_256pict02";
const char ending_texture_name_edura_256pict03[] = "edura_256pict03";
const char ending_texture_name_edura_256pict04[] = "edura_256pict04";
const char ending_texture_name_edura_256pict05[] = "edura_256pict05";
const char ending_texture_name_edura_256pict06[] = "edura_256pict06";
const char ending_texture_name_edura_256pict07[] = "edura_256pict07";
const char ending_texture_name_edura_256pict08[] = "edura_256pict08";
const char ending_texture_name_edura_256pict09[] = "edura_256pict09";
const char ending_texture_name_edura_256pict10[] = "edura_256pict10";
const char ending_texture_name_edura_256pict11[] = "edura_256pict11";
const char ending_ab_class_name_text[] = "TEndingAB";
extern const char ending_wall_archive_secret[];
extern const char ending_wall_archive_nh[];
extern const char ending_wall_archive_sh[];
extern const char ending_wall_archive_ul[];

const char *ending_ab_class_name = ending_ab_class_name_text;

EndingWallTextureSet ending_wall_texture_sets[4] = {
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_ed_256pict00a, 0, 0},
            {ending_texture_name_ed_256pict01, 0, 0},
            {ending_texture_name_ed_256pict02a, 0, 0},
            {ending_texture_name_ed_256pict03a, 0, 0},
            {ending_texture_name_ed_256pict04, 0, 0},
            {ending_texture_name_ed_256pict05a, 0, 0},
            {ending_texture_name_ed_256pict06a, 0, 0},
            {ending_texture_name_ed_256pict07a, 0, 0},
            {ending_texture_name_ed_256pict08, 0, 0},
            {ending_texture_name_ed_256pict09, 0, 0},
            {ending_texture_name_ed_256pict10a, 0, 0},
            {ending_texture_name_ed_256pict11a, 0, 0},
        },
        {ending_wall_texture_sets[0].names, 14}
    },
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_ed_256pict00b, 0, 0},
            {ending_texture_name_ed_256pict01, 0, 0},
            {ending_texture_name_ed_256pict02b, 0, 0},
            {ending_texture_name_ed_256pict03b, 0, 0},
            {ending_texture_name_ed_256pict04, 0, 0},
            {ending_texture_name_ed_256pict05b, 0, 0},
            {ending_texture_name_ed_256pict06b, 0, 0},
            {ending_texture_name_ed_256pict07b, 0, 0},
            {ending_texture_name_ed_256pict08, 0, 0},
            {ending_texture_name_ed_256pict09, 0, 0},
            {ending_texture_name_ed_256pict10b, 0, 0},
            {ending_texture_name_ed_256pict11b, 0, 0},
        },
        {ending_wall_texture_sets[1].names, 14}
    },
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_edu_256pict00, 0, 0},
            {ending_texture_name_edu_256pict01, 0, 0},
            {ending_texture_name_edu_256pict02, 0, 0},
            {ending_texture_name_edu_256pict03, 0, 0},
            {ending_texture_name_edu_256pict04, 0, 0},
            {ending_texture_name_edu_256pict05, 0, 0},
            {ending_texture_name_edu_256pict06, 0, 0},
            {ending_texture_name_edu_256pict07, 0, 0},
            {ending_texture_name_edu_256pict08, 0, 0},
            {ending_texture_name_edu_256pict09, 0, 0},
            {ending_texture_name_edu_256pict10, 0, 0},
            {ending_texture_name_edu_256pict11, 0, 0},
        },
        {ending_wall_texture_sets[2].names, 14}
    },
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_edura_256pict00, 0, 0},
            {ending_texture_name_edura_256pict01, 0, 0},
            {ending_texture_name_edura_256pict02, 0, 0},
            {ending_texture_name_edura_256pict03, 0, 0},
            {ending_texture_name_edura_256pict04, 0, 0},
            {ending_texture_name_edura_256pict05, 0, 0},
            {ending_texture_name_edura_256pict06, 0, 0},
            {ending_texture_name_edura_256pict07, 0, 0},
            {ending_texture_name_edura_256pict08, 0, 0},
            {ending_texture_name_edura_256pict09, 0, 0},
            {ending_texture_name_edura_256pict10, 0, 0},
            {ending_texture_name_edura_256pict11, 0, 0},
        },
        {ending_wall_texture_sets[3].names, 14}
    },
};

struct RecoveredGlobal_8008CE80___vt__9TEndingAB { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8008CE80___vt__9TEndingAB_size[sizeof(RecoveredGlobal_8008CE80___vt__9TEndingAB) == 0x18 ? 1 : -1];

extern "C" {
void restore_saved_depth_alpha_state(void);
extern s32 TEndingAB__fade_sequence_state;
extern s32 game_difficulty_selection;
extern u32 ending_ab_wall_texture_list;
void TEndingAB::advance_fade_sequence() {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r4;
    s32 temp_r4_2;

    switch ((s32) TEndingAB__fade_sequence_state) {
    case 1:
        temp_r3 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3;
        temp_r4 = *(s32 *)((s8 *)this + 0xEC);
        if (temp_r3 > (s32) ((temp_r4 * 3) - temp_r4)) {
            TEndingAB__fade_sequence_state = 2;
            TEndingPicStage::set_picture(*(s32 *)((s8 *)this + 0x24));
            *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + 1);
            return;
        }
        break;
    case 2:
        temp_r3_2 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_2;
        if (temp_r3_2 > (s32) (*(s32 *)((s8 *)this + 0xEC) * 0xD)) {
            TEndingAB__fade_sequence_state = 3;
            return;
        }
        break;
    case 3:
        temp_r3_3 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_3;
        temp_r4_2 = *(s32 *)((s8 *)this + 0xEC);
        if (temp_r3_3 > (s32) ((temp_r4_2 * 0xE) - temp_r4_2)) {
            TEndingAB__fade_sequence_state = 4;
            TEndingPicStage::set_picture(*(s32 *)((s8 *)this + 0x24));
            *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + 1);
            return;
        }
        break;
    case 4:
        temp_r3_4 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_4;
        if (temp_r3_4 > (s32) (*(s32 *)((s8 *)this + 0xEC) * 0x18)) {
            *(s32 *)((s8 *)this + 0x1C) = 0;
            TEndingAB__fade_sequence_state = 1;
            temp_r0 = *(s32 *)((s8 *)this + 0x28) + 1;
            *(s32 *)((s8 *)this + 0x28) = temp_r0;
            if (temp_r0 > 5) {
                *(s32 *)((s8 *)this + 0x28) = 5;
                TEndingAB__fade_sequence_state = 5;
                return;
            }
        }
        break;
    case 5:
        *(s32 *)((s8 *)this + 0x28) = 5;
        break;
    }
}
#pragma push
#pragma fp_contract on
void TEndingAB::draw_overlay() {
    u8 *arg0 = (u8 *)this;
    switch ((s32) TEndingAB__fade_sequence_state) {
    case 1:
    case 3:
        break;
    case 2:
        begin_screen_draw(1);
        set_draw_texture_and_color((*(s32 *)((s8 *)arg0 + 0x28) * 2) + 2, -1);
        TWindowSubStatusDisp::get_player();
        set_depth_buffer_settings_2();
        begin_screen_draw(1);
        set_draw_texture_and_color(0, -1);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x2C), 0.9f);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x4C), 0.9f);
        TWindowSubStatusDisp::get_player();
        restore_saved_depth_alpha_state();
        break;
    case 4:
    case 5:
        begin_screen_draw(1);
        set_draw_texture_and_color((*(s32 *)((s8 *)arg0 + 0x28) * 2) + 3, -1);
        TWindowSubStatusDisp::get_player();
        set_depth_buffer_settings_2();
        begin_screen_draw(1);
        set_draw_texture_and_color(1, -1);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x6C), 0.9f);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x8C), 0.9f);
        TWindowSubStatusDisp::get_player();
        restore_saved_depth_alpha_state();
        break;
    }
}
#pragma pop

void TEndingAB::set_fish_global_param() {
    switch (game_difficulty_selection) {
    case 0:
    case 1:
        TObjFish::set_global_param(ending_ab_wall_texture_list);
        break;
    case 2:
        TObjFish::set_global_param(ending_ab_wall_texture_list);
        break;
    case 3:
        TObjFish::set_global_param(ending_ab_wall_texture_list);
        break;
    }
}

}

void TEndingAB__sub_8008CCC0(TEndingAB *self) {}

void TEndingAB::init_float_table() { *(float*)((char*)this + 0x2c) = 228.0f; *(float*)((char*)this + 0x30) = 0.0f; *(float*)((char*)this + 0x34) = 640.0f; *(float*)((char*)this + 0x38) = 480.0f; *(float*)((char*)this + 0x3c) = 0.1953125f; *(float*)((char*)this + 0x40) = 0.0f; *(float*)((char*)this + 0x44) = 1.0f; *(float*)((char*)this + 0x48) = 0.9375f; *(float*)((char*)this + 0x4c) = 0.0f; *(float*)((char*)this + 0x50) = 0.0f; *(float*)((char*)this + 0x54) = 100.0f; *(float*)((char*)this + 0x58) = 480.0f; *(float*)((char*)this + 0x5c) = 0.0f; *(float*)((char*)this + 0x60) = 0.0f; *(float*)((char*)this + 0x64) = 0.1953125f; *(float*)((char*)this + 0x68) = 0.9375f; *(float*)((char*)this + 0x6c) = 228.0f; *(float*)((char*)this + 0x70) = 0.0f; *(float*)((char*)this + 0x74) = 640.0f; *(float*)((char*)this + 0x78) = 480.0f; *(float*)((char*)this + 0x7c) = 0.1953125f; *(float*)((char*)this + 0x80) = 0.0f; *(float*)((char*)this + 0x84) = 1.0f; *(float*)((char*)this + 0x88) = 0.9375f; *(float*)((char*)this + 0x8c) = 0.0f; *(float*)((char*)this + 0x90) = 0.0f; *(float*)((char*)this + 0x94) = 100.0f; *(float*)((char*)this + 0x98) = 480.0f; *(float*)((char*)this + 0x9c) = 0.0f; *(float*)((char*)this + 0xa0) = 0.0f; *(float*)((char*)this + 0xa4) = 0.1953125f; *(float*)((char*)this + 0xa8) = 0.9375f; *(float*)((char*)this + 0xac) = 316.0f; *(float*)((char*)this + 0xb0) = 32.0f; *(float*)((char*)this + 0xb4) = 616.0f; *(float*)((char*)this + 0xb8) = 332.0f; *(float*)((char*)this + 0xbc) = 0.0f; *(float*)((char*)this + 0xc0) = 0.0f; *(float*)((char*)this + 0xc4) = 1.0f; *(float*)((char*)this + 0xc8) = 1.0f; *(float*)((char*)this + 0xcc) = 316.0f; *(float*)((char*)this + 0xd0) = 148.0f; *(float*)((char*)this + 0xd4) = 616.0f; *(float*)((char*)this + 0xd8) = 448.0f; *(float*)((char*)this + 0xdc) = 0.0f; *(float*)((char*)this + 0xe0) = 0.0f; *(float*)((char*)this + 0xe4) = 1.0f; *(float*)((char*)this + 0xe8) = 1.0f; }

void TEndingAB::render() {
    s32 arg0 = (s32)this;
    if ((s32) TEndingAB__fade_sequence_state != 0) {
        TEndingAB::set_fish_global_param();
        ((TEndingAB *)arg0)->draw_overlay();
        TEndingAB__sub_8008CCC0((TEndingAB *)arg0);
    }
}

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8008CE80___vt__9TEndingAB __vt__9TEndingAB;

void bind_gvm_texture_list(const char *, void *);

void release_texture_list(void*);

void TEndingAB::run_task() { advance_fade_sequence(); }

TEndingAB::~TEndingAB() {}
u8 *__ct__9TEndingABFv(u8 *ending_ab, u8 *arg1) {
    __ct__7TObjectFP7TObject(ending_ab, arg1);
    *(s32 **)((s8 *)ending_ab + 0x18) = &__vt__9TEndingAB.value;
    *(s32 *)((s8 *)ending_ab + 0) = (s32) ending_ab_class_name;
    *(s32 *)((s8 *)ending_ab + 0x1C) = -1;
    TEndingAB__fade_sequence_state = 0;
    *(s32 *)((s8 *)ending_ab + 0x20) = 0xFF;
    *(s32 *)((s8 *)ending_ab + 0x28) = 0;
    *(s32 *)((s8 *)ending_ab + 0x24) = 0;
    ((TEndingAB *)ending_ab)->init_float_table();
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0:
        *(s32 *)((s8 *)ending_ab + 0xEC) = 0x1E;
        break;
    case 1:
        *(s32 *)((s8 *)ending_ab + 0xEC) = 0x19;
        break;
    }
    return ending_ab;
}

void TEndingAB::destroy_instance() {
    if ((u32) ending_ab_wall_texture_list != 0U) {
        release_texture_list((void*)ending_ab_wall_texture_list);
        ending_ab_wall_texture_list = 0U;
    }
}
void TScene::bind_ending_wall_textures() {
    EndingWallTextureSet *base = ending_wall_texture_sets;
    u8 *t;
    if (get_ending_scene_active() != 0) {
        t = (u8 *)&base[3].list;
        (*(u8 * *)&ending_ab_wall_texture_list) = t;
        bind_gvm_texture_list(ending_wall_archive_secret, t);
    } else {
        switch (game_difficulty_selection) {
        case 0:
        case 1:
            t = (u8 *)&base[0].list;
            (*(u8 * *)&ending_ab_wall_texture_list) = t;
            bind_gvm_texture_list(ending_wall_archive_nh, t);
            break;
        case 2:
            t = (u8 *)&base[1].list;
            (*(u8 * *)&ending_ab_wall_texture_list) = t;
            bind_gvm_texture_list(ending_wall_archive_sh, t);
            break;
        case 3:
            t = (u8 *)&base[2].list;
            (*(u8 * *)&ending_ab_wall_texture_list) = t;
            bind_gvm_texture_list(ending_wall_archive_ul, t);
            break;
        }
    }
}

}

__declspec(section ".rodata") extern const char ending_wall_archive_secret[] = "ed_512kabe_AB_Secret";
__declspec(section ".rodata") extern const char ending_wall_archive_nh[] = "ed_512kabe_AB_NH";
__declspec(section ".rodata") extern const char ending_wall_archive_sh[] = "ed_512kabe_AB_SH";
__declspec(section ".rodata") extern const char ending_wall_archive_ul[] = "ed_512kabe_AB_UL";
