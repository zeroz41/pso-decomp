#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/key/TODummyKeyCave01Sound.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/object/key/TODummyKeyCave01.h"
#include "pso/object/key/TOKeyAncient03.h"
#include "pso/object/key/TOKeyCave01.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/BmlResource.h"
#include "pso/map/FloorArea.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"

const char *TODummyKeyCave01__class_name = "TODummyKeyCave01";
const char *TODummyKeyCave01Sound__class_name = "TODummyKeyCave01Sound";
typedef struct Key_80165940 {
    u8 pad0[0x34];
    void *bml_model;
    u8 pad38[0x84 - 0x38];
    u32 f84;
    u32 f88;
    u32 f8C;
    u32 f90;
    u32 f94;
    u16 id;
    u16 f9A;
    u8 pad9C[0xBC - 0x9C];
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
    u8 padCC[4];
    s32 fD0;
} Key_80165940;

struct Obj_80165C84 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x90 - 0x28];
    s32 f90;
    s32 f94;
    u16 f98;
    u16 f9A;
    u8 pad9C[0xA0 - 0x9C];
    f32 fA0;
    u8 padA4[0xB0 - 0xA4];
    f32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s32 fB8;
    u8 padBC[0xC0 - 0xBC];
    s32 fC0;
    s32 fC4;
    s32 fC8;
    s32 fCC;
};

extern "C" {
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
}

#define dummy_key_cave01 this
TODummyKeyCave01::TODummyKeyCave01(TObject *parent, void *set_data) : TObjBase(parent) {
    ((TObject *)dummy_key_cave01)->m_name = TODummyKeyCave01__class_name;
    ((TODummyKeyCave01 *)(dummy_key_cave01))->apply_object_set_data((void *)set_data);
    *(f32 *)((s8 *)dummy_key_cave01 + 0xA8) = 1.0f;
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_a4 = 1.0f;
    *(f32 *)((s8 *)dummy_key_cave01 + 0xA0) = 1.0f;
    *(f32 *)((s8 *)dummy_key_cave01 + 0x9C) = 1.0f;
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_b4 = 0.0f;
    *(f32 *)((s8 *)dummy_key_cave01 + 0xB0) = 0.0f;
    *(f32 *)((s8 *)dummy_key_cave01 + 0xAC) = 0.0f;
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_b8 = 1;
    ((TODummyKeyCave01 *)dummy_key_cave01)->sub_80165940();
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_cc = 0;
}
#undef dummy_key_cave01

TODummyKeyCave01::~TODummyKeyCave01() {

}


void TODummyKeyCave01__sub_80165E8C(void) {  }
void TODummyKeyCave01__sub_80165E88(void) {  }
void *TODummyKeyCave01::create(void *set_data) {
    return new TODummyKeyCave01(tl_05, set_data);
}

void TODummyKeyCave01::run_task() {
    Obj_80165C84 *self = (Obj_80165C84 *)this;
    u32 st;
    u8 skip;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((TObjBase *)self)->clear_actor_flags(0x08000000);
    }
    if (this->id < 0x100) {
        st = is_current_floor_switch_set(this->id);
        if (st != this->m_9a) {
            this->m_9a = st;
            skip = 0;
            if (*(s32 *)&this->m_c4 == 1 && st == 0) {
                skip = 1;
            }
            if (skip == 0) {
                new TODummyKeyCave01Sound((TObject *)self, (s32)*(s32 *)&this->m_c0, (s32)*(s32 *)&this->m_c8);
            }
        }
    }
    if (this->m_9a == 1) {
        this->texlist = this->on_textures;
        f32 lo = (-0.7f);
        if (lo < self->fB0) {
            self->fB0 += (-0.023333333f);
            if (self->fB0 < lo) {
                self->fB0 = lo;
            }
        }
        if (*(s32 *)&this->m_cc < 0x2000) {
            *(s32 *)&this->m_cc = *(s32 *)&this->m_cc + 0x333;
        }
    } else {
        this->texlist = this->off_textures;
        if (self->fB0 < (0.0f)) {
            self->fB0 = self->fB0 - (-0.023333333f);
            if ((0.0f) < self->fB0) {
                self->fB0 = (0.0f);
            }
        }
        if (*(s32 *)&this->m_b8 == 1) {
            self->fA0 += 0.1f;
            if (1.0f <= self->fA0) {
                self->fA0 = 1.0f;
                *(s32 *)&this->m_b8 = 0;
            }
        } else {
            self->fA0 -= 0.1f;
            if (self->fA0 <= 0.0f) {
                self->fA0 = 0.0f;
                *(s32 *)&this->m_b8 = 1;
            }
        }
        if (*(s32 *)&this->m_cc > 0) {
            *(s32 *)&this->m_cc = *(s32 *)&this->m_cc - 0x333;
        }
    }
}

void TODummyKeyCave01::render() {
    u8 *arg0 = (u8 *)this;
    NJS_TEXLIST *v;
    u8 *node;
    s32 id;
    if (this->update_object_view_visibility((4e+02f), (2e+01f)) != 0 && this->model != NULL &&
        (v = this->texlist) != NULL) {
        set_texlist(v);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_zyx(0, this->rotation_x, this->rotation_y, this->rotation_z);
        scale_current_matrix((u8 *)&this->scale);
        node = *(u8 **)(arg0 + 0x34);
        draw_ginja_model(*(void **)(node + 4));
        if (*(u16 *)(arg0 + 0x9A) == 0) {
            id = model_render_flags;
            saved_model_render_flags = id;
            model_render_flags = id | 0x10;
            set_constant_material((const NJS_ARGB *)(((f32 *)&this->color)));
        }
        TParticleCtrl::begin_effect_render();
        node = *(u8 **)(node + 0x2C);
        if (*(s32 *)(arg0 + 0xD0) != 0) {
            rotate_matrix_y(0, *(s32 *)(arg0 + 0xCC));
        } else {
            post_translate_matrix((u8 *)&this->m_ac);
        }
        post_translate_matrix(node + 8);
        draw_ginja_model(*(void **)(node + 4));
        node = *(u8 **)(node + 0x2C);
        post_translate_matrix(node + 8);
        draw_ginja_model(*(void **)(node + 4));
        if (*(u16 *)(arg0 + 0x9A) == 0) {
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TODummyKeyCave01::sub_80165940() {
    Key_80165940 *self = (Key_80165940 *)this;
    self->fD0 = 0;
    self->id = self->f84;
    if (self->id < 0x100) {
        self->f9A = is_current_floor_switch_set(self->id);
    } else {
        self->id = 0xFFFF;
        self->f9A = 1;
    }
    self->fBC = self->f88 & 0xFFFF;
    self->fC8 = self->f88 >> 16;
    self->fC0 = self->f8C & 0xFFFF;
    if (self->fC0 > 6) {
        self->fC0 = 0;
    }
    self->fC4 = self->f8C >> 16;
    if (self->fC4 > 1) {
        self->fC4 = 0;
    }
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        self->bml_model = (void *)get_bml_model((BmlResource *)TOKeyCave01__resource_bundle, 0);
        this->off_textures = TOKeyCave01__texture_lists[0];
        this->on_textures = TOKeyCave01__texture_lists[1];
        break;
    case AREA_FOREST1:
    case AREA_FOREST2:
    case AREA_MINE1:
    case AREA_MINE2:
        self->bml_model = (void *)get_bml_model((BmlResource *)TOKeyMachine01__resource_bundle, 0);
        this->off_textures = TOKeyMachine01__texture_lists[0];
        this->on_textures = TOKeyMachine01__texture_lists[1];
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        self->bml_model = (void *)get_bml_model((BmlResource *)TOKeyAncient03__model_archive, 0);
        this->off_textures = TOKeyAncient03__texture_variants[0];
        this->on_textures = TOKeyAncient03__texture_variants[1];
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        if (self->fBC == 0) {
            self->bml_model = (void *)get_bml_model((BmlResource *)TOKeyCave01__resource_bundle, 0);
            this->off_textures = TOKeyCave01__texture_lists[0];
            this->on_textures = TOKeyCave01__texture_lists[1];
        } else {
            self->bml_model = (void *)get_bml_model((BmlResource *)TOKeyMachine01__resource_bundle, 0);
            this->off_textures = TOKeyMachine01__texture_lists[0];
            this->on_textures = TOKeyMachine01__texture_lists[1];
        }
        break;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        self->bml_model = (void *)get_bml_model((BmlResource *)TOKeyCave01__resource_bundle, 0);
        this->off_textures = TOKeyCave01__texture_lists[0];
        this->on_textures = TOKeyCave01__texture_lists[1];
        self->fD0 = 1;
        break;
    default:
        self->bml_model = 0;
        this->off_textures = 0;
        this->on_textures = 0;
        break;
    }
}


TODummyKeyCave01Sound::TODummyKeyCave01Sound(TObject *parent, s32 arg2, s32 arg3) : TObject(parent) {
    m_name = TODummyKeyCave01Sound__class_name;
    delay_frames = arg3;
    sound_kind = arg2;
    if ((s32) delay_frames <= 0) {
        play_cave01_key_sound();
        queue_destruction();
    }
}

TODummyKeyCave01Sound::~TODummyKeyCave01Sound() {}
void TODummyKeyCave01Sound::run_task() {
    u8 *arg0 = (u8 *)this;
    this->delay_frames = (s32) (this->delay_frames - 1);
    if ((s32) this->delay_frames == 0) {
        ((TODummyKeyCave01Sound *)arg0)->play_cave01_key_sound();
        ((TObject *)arg0)->queue_destruction();
    }
}
