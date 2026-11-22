#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/text_80087278.h"
#include "types.h"
#include "pso/boss/olgaflow/TBoss6RockChase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"

#include <stddef.h>

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"

struct RecoveredGlobal_8036D4E0_lbl_8047ACE8 {
    s32 value;
    u8 remaining[0xC];
};

struct Hit_8036D1B4 {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
};

struct PBase_8036D1B4 { char pad[0x18]; };

struct Player_8036D1B4 : PBase_8036D1B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(TObject *, Hit_8036D1B4 *, s32, s32, s32);
    u8 pad1C[0x38 - 0x1C];
    Vec pos;
};

struct Ent_8036D1B4 { s32 id; f32 range; };

struct Chase_8036D1B4 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0xB0 - 0x44];
    s32 xB0;
};

struct Param_8036D1B4 { u8 pad[0xC]; f32 v; };

extern "C" {
__declspec(section ".rodata") char TBoss6RockChase__class_name_string[] = "TBoss6RockChase";
__declspec(section ".rodata") RecoveredGlobal_8036D4E0_lbl_8047ACE8 boss6_rock_chase_model_radius_table = {
    4, { 0x41, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00 }
};
const char *TBoss6RockChase__name = TBoss6RockChase__class_name_string;
extern RecoveredGlobal_8036D4E0_lbl_8047ACE8 boss6_rock_chase_model_radius_table;
int post_translate_matrix(void*);
int rotate_matrix_z(void*, void*);
int rotate_matrix_x(void*, void*);
int rotate_matrix_y(void*, void*);

#pragma push
#pragma opt_propagation off
void TBoss6RockChase::damage_players_in_range() {
    Chase_8036D1B4 *self = (Chase_8036D1B4 *)this;
    Vec d;
    s32 n;
    s32 dmg;
    s32 i;
    Player_8036D1B4 *pl;
    f32 range;
    n = TLobby::get_game_mode();
    {
        Ent_8036D1B4 *tbl = (Ent_8036D1B4 *)&boss6_rock_chase_model_radius_table;
        range = tbl[self->xB0].range;
    }
    dmg = ((Param_8036D1B4 *)TLobby::dispatch_shared_handler_a(0x2C))->v;
    if (dmg < 1) {
        dmg = 20;
    }
    for (i = 0; i < n; i++) {
        pl = (Player_8036D1B4 *)TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active((TObjPlayer *)pl) != 0) {
            VecCopy((Vec *)&d, (const Vec *)&pl->pos);
            subtract_vector(&d, &self->pos);
            d.y = 0.0f;
            if (!(vector_length(&d) > range)) {
                Hit_8036D1B4 h;
                h.d = (f32)TBoss6PlotFalz::rand_vary_count(dmg, 0.1f);
                s32 z = 0;
                h.a = z;
                h.c = z;
                h.b = *(s32 *)&h.d;
                pl->m21(owner, &h, 0, -1, -1);
            }
        }
    }
}
#pragma pop

void TBoss6RockChase::render() { push_matrix(); post_translate_matrix((char*)this + 0x38); rotate_matrix_y((void*)0, *(void* *)&this->rotation_y); rotate_matrix_x((void*)0, *(void* *)&this->rotation_x); rotate_matrix_z((void*)0, *(void* *)&this->rotation_z); TObjFish::set_global_param((saddr)(textures)); draw_ginja_object(model); pop_matrix(); }

#pragma push
#pragma opt_common_subs off
void TBoss6RockChase::run_task() {
    u8 *self = (u8 *)this;
    s32 temp_r3;
    if (TObjEneDD::query_teammate_state() == 0) {
        temp_r3 = this->m_b4;
        if (temp_r3 > 0) {
            this->m_b4 = (temp_r3 - 1);
            return;
        }
        this->rotation_y = (s32) (this->rotation_y + this->m_bc);
        *(f32 *)&this->_padB8 += -0.9375f;
        if (*(f32 *)&this->_padB8 < -11.25f) {
            *(f32 *)&this->_padB8 = -11.25f;
        }
        *(f32 *)((s8 *)self + 0x3C) = (f32) (*(f32 *)((s8 *)self + 0x3C) + *(f32 *)&this->_padB8);
        if (*(f32 *)((s8 *)self + 0x3C) <= 0.0f) {
            *(f32 *)((s8 *)self + 0x3C) = 0.0f;
            *(f32 *)&this->_padB8 = 0.0f;
            damage_players_in_range();
            play_sound_effect(0x4006B51E, (u8 *)&this->position, 0, 0);
            spawn_particle_effect(&this->position, 0x220);
            spawn_particle_effect(&this->position, 0x222);
            TBoss6PlotFalz::apply_radial_effect_to_players((u8 *)&this->position, 0xC0, 0xF, 100.0f);
            TBoss6Rock::spawn_crush_rocks(&position, m_b0);
            play_sound_effect(0x4006AB1F, (u8 *)&this->position, 0, 0);
            ((TObject *)self)->queue_destruction();
        }
    }
}
#pragma pop

}
TBoss6RockChase::~TBoss6RockChase() {

}


#pragma push
#pragma fp_contract on
LAYOUT_ASSERT(RecoveredGlobal_8036D4E0_lbl_8047ACE8_size, sizeof(RecoveredGlobal_8036D4E0_lbl_8047ACE8) == 0x10);
TBoss6RockChase::TBoss6RockChase(TObject *parent, const Vec *position, s32 size_kind) : TObjCollidable(parent) {
    TBoss6RockChase *boss6_rock_chase = this;
    boss6_rock_chase->m_name = TBoss6RockChase__name;
    boss6_rock_chase->owner = parent;
    boss6_rock_chase->m_b0 = size_kind;
    boss6_rock_chase->m_b4 = (s32) (15.0f * (3.0517578e-05f * (f32) rand()));
    ((TBoss6RockChase *)boss6_rock_chase)->rotation_x = (s32) (2048.0f * ((3.0517578e-05f * (f32) rand()) - 0.5f));
    boss6_rock_chase->rotation_y = (s32) (65535.0f * (3.0517578e-05f * (f32) rand()));
    boss6_rock_chase->rotation_z = (s32) (2048.0f * ((3.0517578e-05f * (f32) rand()) - 0.5f));
    boss6_rock_chase->m_bc = (s32) (8192.0f * ((3.0517578e-05f * (f32) rand()) - 0.5f));
    *(f32 *)((s8 *)boss6_rock_chase + 0xB8) = 0.0f;
    VecCopy((Vec *)((u8 *)boss6_rock_chase + 0x38), (const Vec *)(position));
    boss6_rock_chase->model = (NJS_OBJECT *)get_bml_model((BmlResource *)(TBoss6Rock__sub_80353A0C()), (int) (*(s32 *)((s8 *)&boss6_rock_chase_model_radius_table.value + (size_kind * 8))));
    boss6_rock_chase->textures = (GinjaTextureList *)TBoss6Rock__sub_80353A04();
}
#pragma pop

TBoss6RockChase *TBoss6RockChase::spawn(TObject *parent, const Vec *position) {
    Vec point;
    s32 var_r31;
    VecCopy(&point, position);
    var_r31 = 0;
    point.y = 450.0f;
    if ((3.0517578e-05f * (f32) rand()) < 0.5f) {
        var_r31 = 1;
    }
    return new TBoss6RockChase(parent, &point, var_r31);
}

