#include "types.h"
#include "pso/system/scene/TEndingAB.h"
#include "pso/system/scene/EndingWallTextures.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/render_util.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/GinjaTexture.h"

extern "C" {
extern s32 game_difficulty_selection;
void TEndingAB__sub_8008CCC0(TEndingAB *);
}

struct EndingWallTextureSet {
    NJS_TEXNAME names[14];
    NJS_TEXLIST list;
};
LAYOUT_ASSERT(EndingWallTextureSetSize, sizeof(EndingWallTextureSet) == 0xB0);

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

// Ginja's legacy entry type exposes mutable name pointers. These names are
// read-only archive lookup keys; only the texture handles are updated.
EndingWallTextureSet ending_wall_texture_sets[4] = {
    {
        {
            {const_cast<char *>(ending_texture_name_ed_512kabe_a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_512kabe_b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict00a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict01), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict02a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict03a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict04), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict05a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict06a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict07a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict08), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict09), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict10a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict11a), 0, NULL},
        },
        {ending_wall_texture_sets[0].names, 14}
    },
    {
        {
            {const_cast<char *>(ending_texture_name_ed_512kabe_a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_512kabe_b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict00b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict01), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict02b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict03b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict04), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict05b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict06b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict07b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict08), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict09), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict10b), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_256pict11b), 0, NULL},
        },
        {ending_wall_texture_sets[1].names, 14}
    },
    {
        {
            {const_cast<char *>(ending_texture_name_ed_512kabe_a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_512kabe_b), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict00), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict01), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict02), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict03), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict04), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict05), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict06), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict07), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict08), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict09), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict10), 0, NULL},
            {const_cast<char *>(ending_texture_name_edu_256pict11), 0, NULL},
        },
        {ending_wall_texture_sets[2].names, 14}
    },
    {
        {
            {const_cast<char *>(ending_texture_name_ed_512kabe_a), 0, NULL},
            {const_cast<char *>(ending_texture_name_ed_512kabe_b), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict00), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict01), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict02), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict03), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict04), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict05), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict06), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict07), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict08), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict09), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict10), 0, NULL},
            {const_cast<char *>(ending_texture_name_edura_256pict11), 0, NULL},
        },
        {ending_wall_texture_sets[3].names, 14}
    },
};

extern "C" {
s32 TEndingAB__fade_sequence_state;
NJS_TEXLIST *ending_ab_wall_texture_list;
}

void TEndingAB::advance_fade_sequence() {
    switch (TEndingAB__fade_sequence_state) {
    case 1: {
        s32 ticks = ++elapsed_ticks;
        s32 rate = timing_rate;
        if (ticks > rate * 3 - rate) {
            TEndingAB__fade_sequence_state = 2;
            TEndingPicStage::set_picture(picture_index);
            ++picture_index;
            return;
        }
        break;
    }
    case 2:
        if (++elapsed_ticks > timing_rate * 13) {
            TEndingAB__fade_sequence_state = 3;
            return;
        }
        break;
    case 3: {
        s32 ticks = ++elapsed_ticks;
        s32 rate = timing_rate;
        if (ticks > rate * 14 - rate) {
            TEndingAB__fade_sequence_state = 4;
            TEndingPicStage::set_picture(picture_index);
            ++picture_index;
            return;
        }
        break;
    }
    case 4:
        if (++elapsed_ticks > timing_rate * 24) {
            elapsed_ticks = 0;
            TEndingAB__fade_sequence_state = 1;
            if (++wall_index > 5) {
                wall_index = 5;
                TEndingAB__fade_sequence_state = 5;
                return;
            }
        }
        break;
    case 5:
        wall_index = 5;
        break;
    }
}

void TEndingAB::draw_overlay() {
    switch (TEndingAB__fade_sequence_state) {
    case 1:
    case 3:
        break;
    case 2:
        begin_screen_draw(1);
        set_draw_texture_and_color(wall_index * 2 + 2, -1);
        TWindowSubStatusDisp::get_player();
        set_depth_buffer_settings_2();
        begin_screen_draw(1);
        set_draw_texture_and_color(0, -1);
        draw_textured_quad_at_depth((f32 *)&quads[0], 0.9f);
        draw_textured_quad_at_depth((f32 *)&quads[1], 0.9f);
        TWindowSubStatusDisp::get_player();
        restore_saved_depth_alpha_state();
        break;
    case 4:
    case 5:
        begin_screen_draw(1);
        set_draw_texture_and_color(wall_index * 2 + 3, -1);
        TWindowSubStatusDisp::get_player();
        set_depth_buffer_settings_2();
        begin_screen_draw(1);
        set_draw_texture_and_color(1, -1);
        draw_textured_quad_at_depth((f32 *)&quads[2], 0.9f);
        draw_textured_quad_at_depth((f32 *)&quads[3], 0.9f);
        TWindowSubStatusDisp::get_player();
        restore_saved_depth_alpha_state();
        break;
    }
}

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

extern "C" void TEndingAB__sub_8008CCC0(TEndingAB *) {}

void TEndingAB::init_float_table() {
    quads[0].x0 = 228.0f;
    quads[0].y0 = 0.0f;
    quads[0].x1 = 640.0f;
    quads[0].y1 = 480.0f;
    quads[0].u0 = 0.1953125f;
    quads[0].v0 = 0.0f;
    quads[0].u1 = 1.0f;
    quads[0].v1 = 0.9375f;
    quads[1].x0 = 0.0f;
    quads[1].y0 = 0.0f;
    quads[1].x1 = 100.0f;
    quads[1].y1 = 480.0f;
    quads[1].u0 = 0.0f;
    quads[1].v0 = 0.0f;
    quads[1].u1 = 0.1953125f;
    quads[1].v1 = 0.9375f;
    quads[2].x0 = 228.0f;
    quads[2].y0 = 0.0f;
    quads[2].x1 = 640.0f;
    quads[2].y1 = 480.0f;
    quads[2].u0 = 0.1953125f;
    quads[2].v0 = 0.0f;
    quads[2].u1 = 1.0f;
    quads[2].v1 = 0.9375f;
    quads[3].x0 = 0.0f;
    quads[3].y0 = 0.0f;
    quads[3].x1 = 100.0f;
    quads[3].y1 = 480.0f;
    quads[3].u0 = 0.0f;
    quads[3].v0 = 0.0f;
    quads[3].u1 = 0.1953125f;
    quads[3].v1 = 0.9375f;
    quads[4].x0 = 316.0f;
    quads[4].y0 = 32.0f;
    quads[4].x1 = 616.0f;
    quads[4].y1 = 332.0f;
    quads[4].u0 = 0.0f;
    quads[4].v0 = 0.0f;
    quads[4].u1 = 1.0f;
    quads[4].v1 = 1.0f;
    quads[5].x0 = 316.0f;
    quads[5].y0 = 148.0f;
    quads[5].x1 = 616.0f;
    quads[5].y1 = 448.0f;
    quads[5].u0 = 0.0f;
    quads[5].v0 = 0.0f;
    quads[5].u1 = 1.0f;
    quads[5].v1 = 1.0f;
}

void TEndingAB::render() {
    if (TEndingAB__fade_sequence_state != 0) {
        set_fish_global_param();
        draw_overlay();
        TEndingAB__sub_8008CCC0(this);
    }
}

void TEndingAB::run_task() { advance_fade_sequence(); }

TEndingAB::~TEndingAB() {}
TEndingAB::TEndingAB(TObject *parent) : TObject(parent) {
    m_name = ending_ab_class_name;
    elapsed_ticks = -1;
    TEndingAB__fade_sequence_state = 0;
    field_20 = 255;
    wall_index = 0;
    picture_index = 0;
    init_float_table();
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0: timing_rate = 30; break;
    case 1: timing_rate = 25; break;
    }
}

void TEndingAB::destroy_instance() {
    if (ending_ab_wall_texture_list != NULL) {
        release_texture_list(ending_ab_wall_texture_list);
        ending_ab_wall_texture_list = NULL;
    }
}
void TScene::bind_ending_wall_textures() {
    EndingWallTextureSet *base = ending_wall_texture_sets;
    NJS_TEXLIST *t;
    if (get_ending_scene_active() != 0) {
        t = &base[3].list;
        ending_ab_wall_texture_list = t;
        bind_gvm_texture_list(ending_wall_archive_secret, t);
    } else {
        switch (game_difficulty_selection) {
        case 0:
        case 1:
            t = &base[0].list;
            ending_ab_wall_texture_list = t;
            bind_gvm_texture_list(ending_wall_archive_nh, t);
            break;
        case 2:
            t = &base[1].list;
            ending_ab_wall_texture_list = t;
            bind_gvm_texture_list(ending_wall_archive_sh, t);
            break;
        case 3:
            t = &base[2].list;
            ending_ab_wall_texture_list = t;
            bind_gvm_texture_list(ending_wall_archive_ul, t);
            break;
        }
    }
}

__declspec(section ".rodata") extern const char ending_wall_archive_secret[] = "ed_512kabe_AB_Secret";
__declspec(section ".rodata") extern const char ending_wall_archive_nh[] = "ed_512kabe_AB_NH";
__declspec(section ".rodata") extern const char ending_wall_archive_sh[] = "ed_512kabe_AB_SH";
__declspec(section ".rodata") extern const char ending_wall_archive_ul[] = "ed_512kabe_AB_UL";
