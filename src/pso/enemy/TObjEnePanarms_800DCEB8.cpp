#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/TObject.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"

#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/boss/TBoss4Type2.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEnePanarmsAtkColli.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_80086B64.h"

struct Stack_800DDFDC
{
  s32 sp8;
  f32 spC;
};

struct Stack_800DD9A0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    s32 sp14;
    f32 sp18;
};

struct RecoveredGlobal_800DD9A0_lbl_80494F4C {
    s32 value;
    u8 remaining[0x20C];
};

struct Vec_800DECC4 { f32 x; f32 y; f32 z; };

struct Obj_800DECC4 { u8 pad[0x38]; Vec_800DECC4 pos; u8 pad2[0x248 - 0x44]; u8 f248[0x384 - 0x248]; f32 f384; };

struct Obj_800DF1B8 { u8 pad[0x394]; u32 handles[2]; };

struct Obj_800DE124 { u8 pad0[0x60]; s32 f60; u8 pad1[0x388 - 0x64]; s32 f388; u8 pad2[0x474 - 0x38C]; s32 f474; };

struct Obj_800DE2D0 { u8 pad0[0x30]; u32 f30; u8 pad1[0x374 - 0x34]; s32 f374; u8 pad2[0x3AC - 0x378]; u8 f3AC[0x18]; u8 f3C4[4]; };

struct Obj_800DE390 { u8 pad0[0x374]; s32 f374; u8 pad1[0x3E4 - 0x378]; s32 f3E4; s32 f3E8; };

struct Obj_800DE9F0 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x60 - 0x1E]; s32 f60; };

struct Obj_800DEA88 { u8 pad0[0x60]; s32 f60; u8 pad1[0x38C - 0x64]; s32 f38C; };

struct Obj_800DED30;
typedef void (Obj_800DED30::*PMF_800DED30)();
struct Obj_800DED30 {
    u8 pad0[0x374]; s32 f374;
    void m();
};

struct Ent_800DED30 { PMF_800DED30 fn; PMF_800DED30 update; };

struct Obj_800DF634 { u8 pad0[0x42C]; u8 *f42C; s32 f430; };

struct S_800DF634 { s32 a, b, c, d; };

struct Vec_800DDAD8 { f32 x, y, z; };

struct Vec_800DE528 { f32 x, y, z; };

struct Vec_800DE6A8 { f32 x, y, z; };

struct Vec_800DEB48 { f32 x, y, z; };

struct Vec_800DE7EC { f32 x, y, z; };

struct Sub_800DD690 { u8 b[0xC]; };

struct Obj_800DD690 { u8 pad0[0xB0]; u32 flags; u8 padb4[0xC0 - 0xB4]; f32 fc0; u8 padc4[0x394 - 0xC4]; u32 items[2]; u8 pad39c[4]; Sub_800DD690 subs[1]; };

struct Sub_800DD8AC { u8 b[0xC]; };

struct Obj_800DD8AC { u8 pad0[0xB0]; u32 flags; u8 padb4[0xC0 - 0xB4]; f32 fc0; u8 padc4[0x394 - 0xC4]; u32 items[2]; u8 pad39c[4]; Sub_800DD8AC subs[1]; };

struct Vec_800DDC30 { f32 x, y, z; };

struct Obj_800DDC30 {
    u8 pad0[0x38]; Vec_800DDC30 pos; u8 pad44[0x60 - 0x44]; s32 f60;
    u8 pad64[0xC0 - 0x64]; f32 fc0; u8 padc4[0x32C - 0xC4]; s16 f32C;
    u8 pad32e[0x388 - 0x32E]; s32 f388; s32 f38C; u8 pad390[0x3EC - 0x390];
    s32 f3EC; s32 f3F0; s32 f3F4; s32 f3F8; s32 f3FC;
};

extern "C" {
s32 obj_setFlags30(void *, int);
int TObjEnePanarms__sub_800E1D94(void *);
void *spawn_particle_effect(void *pos, s32 id);
extern const f32 TObjEnePanarms__data_805DA490;
extern const f32 lbl_805DA494;
extern const f32 TObjEnePanarms__data_805DA49C;
extern const f32 TObjEnePanarms__data_805DA4A0;
extern const f32 lbl_805DA4DC;
s32 spawn_continuous_particle_with_direction(void *, void *, int, int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
void TObjEnePanarms__sub_800DD7F4(u8 *arg0);
void *spawn_directional_particle(void *pos, void *dir, s32 id);
void TObjEnePanarms__sub_800DD5C8(u8 *arg0);
s32 play_sound_effect(s32, void *, s32, s32);
void TObjEnePanarms__sub_800DCFE0(u8 *arg0);
void set_field_b8__10TObjMotionFs(void *, int);
void TObjEnePanarms__sub_800DD488(u8 *arg0);
s32 TObjEnePanarms__sub_800DFB44(s32);
void TObjEnePanarms__sub_800E1E14(u8 *arg0);
void TObjEnePanarms__sub_800DD368(u8 *arg0);
extern const f32 TObjEnePanarms__data_805DA4A4;
void TObjEnePanarms__sub_800DE430(s32 arg0, s32 arg1, s32 arg2);
f32 vec3_add_to(void *, void *);
extern const f32 lbl_805DA4D8;
s32 queue_destruction__7TObjectFv(void *);
s32 TObjEnePanarms__sub_800DFB74(void *);
s32 TObjEnePanarms__sub_800DFB9C(void *);
s32 TObjEnePanarms__sub_800DFBB0(void *);
extern const f32 lbl_805DA498;
extern RecoveredGlobal_800DD9A0_lbl_80494F4C lbl_80494F4C;
extern f32 lbl_805D527C;
extern u8 lbl_805D5280;
extern const f32 lbl_805DA4A8;
extern const f32 lbl_805DA4AC;
extern const f32 lbl_805DA4B0;
void TObjEnePanarms__sub_800DD9A0(u8 *arg0);
s32 project_actor_to_ground(void *, void *, int);
u16 find_nearest_visible_player(void *, f32 *, f32);
f64 atan2_float(f32, f32);
extern const f64 TObjEnePanarms__data_8043CD20;
void TObjEnePanarms__sub_800DE124(Obj_800DE124 *arg0);
s32 approach_angle_limited(s32, s32, s32);
extern const f32 lbl_805DA4F0;
f32 vector_length(void *);
extern const f32 lbl_805DA4B4;
extern const f32 lbl_805DA4F4;
extern Ent_800DED30 lbl_8049515C[];
Obj_800DF634 *load_resource_from_descriptor(Obj_800DF634 *, s32, void *, s32, s32, s32);
s32 spawn_npc_enemy__6TLobbyFslllff(s32, s32, s32, void *, s32, void *, f32, f32);
extern S_800DF634 panarms_npc_spawn_descriptor[];
extern u8 lbl_80494F10[];
extern u32 TObjEnePanarms__entry_params_resource;
extern const f32 lbl_805DA51C;
f32 random_ratio__9TObjCharaFv(s32 arg0);
extern const f32 lbl_805DA4BC;
extern const f32 lbl_805DA4D4;
void TObjEnePanarms__sub_800DDED8(u8 *arg0);
void TObjEnePanarms__sub_800E1D38(void *arg0);
s32 refresh_lobby_state__10TObjPlayerFv();
void TObjEnePanarms__sub_800DDAD8(u8 *arg0);
extern const f32 lbl_805DA4E8;
extern const f32 lbl_805DA4EC;
s32 TObjEnePanarms__sub_800DE528(void *arg0, Vec_800DE528 *arg1);
s32 subtract_vector(void *, void *);
s32 normalize_vector(void *);
s32 check_ground_along_path__14TObjEnePanarmsFPvPvPvff(void *arg0, Vec_800DE6A8 *arg1, Vec_800DE6A8 *arg2, f32 step, f32 dy);
u32 csnLookAt(void *, void *);
f32 horizontal_distance_squared(void *, void *);
extern const f32 lbl_805DA4E4;
s32 try_warp_to_position__14TObjEnePanarmsFPvPv(u8 *arg0, Vec_800DEB48 *arg1);
void *create_particle_emitter(void *pos, s32 id);
extern s32 lbl_8043CD04[];
extern s32 lbl_8043CD0C[];
extern s32 lbl_8043CCF4[];
extern s32 lbl_8043CCFC[];
s32 TObjEnePanarms__sub_800DE494(void *);
extern s32 registered_player_count;
int TObjEnePanarms__sub_800DFBC4(void *p);
extern const f32 lbl_805DA4B8;
extern const f32 lbl_805DA4C4;
extern const f32 lbl_805DA4C8;
extern const f32 lbl_805DA4CC;
extern const f32 lbl_805DA4D0;
void TObjEnePanarms__sub_800DDC30(Obj_800DDC30 *o);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(s32);
s32 __destroy_arr(void *, void *, int, int);
extern s32 __dt__15RenderFadeStateFv[];
extern s32 __vt__14TObjEnePanarms[];
u8 *__dt__14TObjEnePanarmsFv(u8 *arg0, s16 arg1);
void TObjEnePanarms__sub_800DE2B0(void* p);
void TObjEnePanarms__sub_800DEEF8(void* p);
void init_state__14TObjEnePanarmsFPv(u8 *arg0);
void TLobby__sub_8001FE7C(void*, int);
int post_translate_matrix(void*);
int rotate_matrix_y(void*, void*);
int push_matrix(void*);
int pop_matrix(void);
typedef struct { f32 x, y, z; } Vec_800DEDC4;
void draw_blob_shadow(s32 arg0);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 rotate_matrix_z(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
s32 scale_current_matrix(Vec_800DEDC4 *);
extern const f32 lbl_805DA4F8;
extern const f32 lbl_805DA4FC;
extern const f32 lbl_805DA500;
extern const f32 lbl_805DA504;
extern const f32 lbl_805DA508;
extern const f32 lbl_805DA50C;
extern const f32 lbl_805DA510;
extern const f32 lbl_805DA514;
extern const f32 lbl_805DA518;
int check_demo_mode__10TObjPlayerFv(void*);
int clear_render_callback__8TObjFishFv(void*);

void TObjEnePanarms::update_spin() {
    s32 temp_r0;

    if (this->m_3ec & 2) {
        this->rotation_y = (this->rotation_y + 0x111);
    } else {
        this->rotation_y = (this->rotation_y - 0x111);
    }
    temp_r0 = this->m_388 - 1;
    this->m_388 = temp_r0;
    if (temp_r0 < 0) {
        set_state((s32)((void*)(7)));
    }
}

void TObjEnePanarms::enter_down_state() {
    u8 *temp_r5;
    temp_r5 = (u8 *)this->m_390;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    obj_clearFlags30(0x04040000U);
    this->m_388 = 0x1E;
    *(s32 *)&this->_pad3F0 = (s32) (*(s32 *)&this->_pad3F0 + 1);
    set_field_b8__10TObjMotionFs(this, 0xB);
}

void TObjEnePanarms::update_state_effect() {
    f32 temp_f1;
    temp_f1 = this->frame;
    if ((temp_f1 >= TObjEnePanarms__data_805DA490) && (temp_f1 < lbl_805DA494)) {
        spawn_particle_effect((((u8 *)this) + 0x38), 0xF0);
    }
    if (this->motion_flags & 0x10) {
        set_state((s32)((void*)(3)));
    }
}

void TObjEnePanarms__sub_800DCFE0(u8 *ene_panarms) {
    u8 *temp_r5;
    *(s32 *)((s8 *)ene_panarms + 0x3DC) = 1;
    temp_r5 = (u8 *)(*(u8 **)((s8 *)ene_panarms + 0x390));
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFFFFFE);
    ((TObjBase *)ene_panarms)->obj_clearFlags30((u32)(0x40000));
    obj_setFlags30(ene_panarms, 0x04000000);
    play_sound_effect((s32)((void *) (((s32)((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003BC31))))), ene_panarms + 0x3AC, 0, 0);
    play_sound_effect((s32)((void *) (((s32)((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003BC30))))), ene_panarms + 0x3C4, 0, 0);
    ((TObjEnePanarms *)ene_panarms)->init(0xA);
}

void TObjEnePanarms::update_timed_action() {
    s32 temp_r0;

    if ((TObjEnePanarms__sub_800DFB44(this->m_3e4) != 0) || (TObjEnePanarms__sub_800DFB44(this->m_3e8) != 0)) {
        set_state((s32)((void*)(0xA)));
        return;
    }
    temp_r0 = this->m_388 - 1;
    this->m_388 = temp_r0;
    if (temp_r0 <= 0) {
        set_state((s32)((void*)(0xC)));
        return;
    }
    if ((s32) this->m_388 == 0x13) {
        play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x4003BC32)), ((u8 *)this) + 0x38, 0, 0);
    }
}

extern const f32 lbl_805DA4E0;

void TObjEnePanarms::merge_halves() {
    u8 *temp_r5;
    this->m_3dc = 0;
    temp_r5 = (u8 *)this->m_390;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFFFFFE);
    obj_clearFlags30(0x40000U);
    obj_setFlags30(this, (int)(0x04000000U));
    TObjEnePanarms__sub_800DE430((s32)this, 0x2D, 0x25);
    this->hp = (s16) (*(s16 *)(this->m_3e4 + 0x32C) + *(s16 *)(this->m_3e8 + 0x32C));
    TObjEnePanarms__sub_800E1D94(*(u8 * *)&this->m_3e4);
    TObjEnePanarms__sub_800E1D94(*(u8 * *)&this->m_3e8);
    this->m_388 = 0x40;
}

void TObjEnePanarms::update_separated_parts() {
    s32 temp_r0;
    this->hp = (s16) ((*(s16 *)(this->m_3e4 + 0x32C)) + *(s16 *)(this->m_3e8 + 0x32C));
    if ((TObjEnePanarms__sub_800DFBB0((void *)this->m_3e4) != 0) && (TObjEnePanarms__sub_800DFBB0((void *)this->m_3e8) != 0)) {
        this->send_entity_set_flags();
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (TObjEnePanarms__sub_800DFB44(this->m_3e4) == 0) {
        switch (TObjEnePanarms__sub_800DFB44(this->m_3e8)) {
        case 0:
        this->m_388 = (this->m_388 - 1);
        temp_r0 = this->m_388;
        if (temp_r0 == 0) {
            if ((TObjEnePanarms__sub_800DFB9C((void *)this->m_3e4) != 0) || (TObjEnePanarms__sub_800DFB9C((void *)this->m_3e8) != 0)) {
                this->m_388 = (s32) ((f32) this->m_388 + lbl_805DA498);
                return;
            }
            TObjEnePanarms::find_combine_position(this);
            ((TObjEnePanarms *)(this->m_3e4))->init_state();
            ((TObjEnePanarms *)(this->m_3e8))->init_state();
            return;
        }
        if (temp_r0 < 0) {
            if ((TObjEnePanarms__sub_800DFB74((void *)this->m_3e4) != 0) && (TObjEnePanarms__sub_800DFB74((void *)this->m_3e8) != 0)) {
                if ((((TObjEnePanarms *)(this->m_3e4))->get_state_flag() != 0) || (((TObjEnePanarms *)(this->m_3e8))->get_state_flag() != 0)) {
                    this->m_388 = -1;
                    return;
                }
                set_state((s32)((void*)(0xB)));
                return;
            }
            if ((s32) this->m_388 < -0x12C) {
                TObjEnePanarms::do_action_2((void *)this->m_3e4);
                TObjEnePanarms::do_action_2((void *)this->m_3e8);
                this->m_388 = 0x384;
            }
        }
        break;
        }
    }
}

void TObjEnePanarms__sub_800DD368(u8 *ene_panarms) {
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(u8 **)((s8 *)ene_panarms + 0x390));
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFFFFFE);
    ((TObjBase *)ene_panarms)->obj_clearFlags30((u32)(0x40000));
    obj_setFlags30(ene_panarms, 0x04000000);
    *(s32 *)((s8 *)ene_panarms + 0x3DC) = 0;
    ((TObjEnePanarms *)ene_panarms)->m_388 = 0x384;
    ((TObjEnePanarms *)ene_panarms)->m_3f8 = 1;
    play_sound_effect((s32)((void *) (((s32)((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003BC2E))))), ene_panarms + 0x38, 0, 0);
    if (TObjEnePanarms__sub_800DFB44((s32)((int) (((TObjEnePanarms *)ene_panarms)->m_3e4))) == 0) {
        TObjEnePanarms__sub_800E1E14((u8 *)(((TObjEnePanarms *)ene_panarms)->m_3e4));
    }
    if (TObjEnePanarms__sub_800DFB44((s32)((int) (((TObjEnePanarms *)ene_panarms)->m_3e8))) == 0) {
        TObjEnePanarms__sub_800E1E14((u8 *)(((TObjEnePanarms *)ene_panarms)->m_3e8));
    }
}

void TObjEnePanarms::update_hit_effect() {
    f32 temp_f1;
    temp_f1 = this->frame;
    if ((temp_f1 >= TObjEnePanarms__data_805DA490) && (temp_f1 < lbl_805DA494)) {
        spawn_particle_effect((((u8 *)this) + 0x38), 0xF0);
    }
    if (this->motion_flags & 0x10) {
        set_state((s32)((void*)(0xA)));
    }
}

void TObjEnePanarms__sub_800DD488(u8 *ene_panarms) {
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(u8 **)((s8 *)ene_panarms + 0x390));
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFFFFFE);
    ((TObjBase *)ene_panarms)->obj_clearFlags30((u32)(0x40000));
    obj_setFlags30(ene_panarms, 0x04000000);
    TObjEnePanarms__sub_800DE430((s32)ene_panarms, 0x22, 0x3C);
    play_sound_effect((s32)((void *) (((s32)((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003BC2D))))), ene_panarms + 0x3AC, 0, 0);
    play_sound_effect((s32)((void *) (((s32)((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003BC2C))))), ene_panarms + 0x3C4, 0, 0);
    set_field_b8__10TObjMotionFs(ene_panarms, 0xA);
}

void TObjEnePanarms::update_wait_then_set_state() {
    s32 temp_r0;
    u32 temp_r3;
    if (this->frame >= TObjEnePanarms__data_805DA49C) {
        temp_r3 = *(u32 *)&this->unk_394;
        if (temp_r3 != 0) {
            TParticleCtrl::release((void *)temp_r3);
            *(u32 *)&this->unk_394 = 0U;
        }
    }
    temp_r0 = this->m_388 - 1;
    this->m_388 = temp_r0;
    if (temp_r0 <= 0) {
        if (!(*(s32 *)&this->m_3ec & 1) && ((s32) *(s32 *)&this->_pad3F0 < 4)) {
            set_state((s32)((void*)(0xD)));
            return;
        }
        set_state((s32)((void*)(3)));
    }
}

void TObjEnePanarms__sub_800DD5C8(u8 *ene_panarms_atk_colli) {
    s32 buffer_14[3];
    f32 buffer_8[3];
    s32 temp_r6;
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(u8 **)((s8 *)ene_panarms_atk_colli + 0x390));
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    ((TObjBase *)ene_panarms_atk_colli)->obj_clearFlags30(0x04040000U);
    spawn_directional_particle((ene_panarms_atk_colli + 0x3D0), (ene_panarms_atk_colli + 0x5C), 0x109);
    temp_r6 = ((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->rotation_y - 0x4000;
    buffer_14[1] = 0;
    buffer_14[0] = temp_r6;
    buffer_14[2] = 0x4000;
    *(s32 *)((s8 *)ene_panarms_atk_colli + 0x394) = spawn_continuous_particle_with_direction(ene_panarms_atk_colli + 0x3D0, &buffer_14[0], 0x108, temp_r6);
    buffer_8[1] = TObjEnePanarms__data_805DA4A0;
    buffer_8[0] = sin_table_lookup((int) (((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->rotation_y));
    buffer_8[2] = cos_table_lookup((int) (((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->rotation_y));
    ((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->create(ene_panarms_atk_colli + 0x3D0, &buffer_8[0], (void *)1);
    set_field_b8__10TObjMotionFs(ene_panarms_atk_colli, 9);
    ((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->m_388 = 0x5A;
}

void TObjEnePanarms::update_particle_emitters() {
    s32 i;
    if (((Obj_800DD690 *)this)->fc0 >= TObjEnePanarms__data_805DA4A4) {
        for (i = 0; i < 2; i++) {
            u32 *slot = &((Obj_800DD690 *)this)->items[i];
            if (*slot == 0) {
                *slot = (u32)create_particle_emitter(&((Obj_800DD690 *)this)->subs[lbl_8043CD0C[i]], lbl_8043CD04[i]);
            }
        }
    }
    if (((Obj_800DD690 *)this)->flags & 0x10) {
        set_state(8);
    }
}

void TObjEnePanarms::set_flags_and_field_b8() {
    u8 *temp_r5;
    temp_r5 = (u8 *)this->m_390;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    obj_clearFlags30(0x04040000U);
    set_field_b8__10TObjMotionFs(this, 8);
}

void TObjEnePanarms::update_destroy_child() {
    s32 temp_r0;
    u32 temp_r3;
    if (this->frame >= TObjEnePanarms__data_805DA49C) {
        temp_r3 = *(u32 *)&this->unk_394;
        if (temp_r3 != 0) {
            TParticleCtrl::release((void *)temp_r3);
            *(u32 *)&this->unk_394 = 0U;
        }
    }
    temp_r0 = this->m_388 - 1;
    this->m_388 = temp_r0;
    if (temp_r0 <= 0) {
        set_state((s32)((void*)(3)));
    }
}

void TObjEnePanarms__sub_800DD7F4(u8 *ene_panarms_atk_colli) {
    s32 buffer_14[3];
    f32 buffer_8[3];
    s32 temp_r6;
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(u8 **)((s8 *)ene_panarms_atk_colli + 0x390));
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    ((TObjBase *)ene_panarms_atk_colli)->obj_clearFlags30(0x04040000U);
    temp_r6 = ((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->rotation_y + 0x4000;
    buffer_14[1] = 0;
    buffer_14[0] = temp_r6;
    buffer_14[2] = 0x4000;
    *(s32 *)((s8 *)ene_panarms_atk_colli + 0x394) = spawn_continuous_particle_with_direction(ene_panarms_atk_colli + 0x3B8, &buffer_14[0], 0x105, temp_r6);
    buffer_8[1] = TObjEnePanarms__data_805DA4A0;
    buffer_8[0] = sin_table_lookup((int) (((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->rotation_y));
    buffer_8[2] = cos_table_lookup((int) (((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->rotation_y));
    ((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->create(ene_panarms_atk_colli + 0x3B8, &buffer_8[0], NULL);
    set_field_b8__10TObjMotionFs(ene_panarms_atk_colli, 7);
    ((TObjEnePanarmsAtkColli *)ene_panarms_atk_colli)->m_388 = 0x5A;
}

void TObjEnePanarms::update_particle_emitters_set2() {
    s32 i;
    if (((Obj_800DD8AC *)this)->fc0 >= TObjEnePanarms__data_805DA4A4) {
        for (i = 0; i < 2; i++) {
            u32 *it = &((Obj_800DD8AC *)this)->items[i];
            if (*it == 0) {
                *it = (u32)create_particle_emitter(&((Obj_800DD8AC *)this)->subs[lbl_8043CCFC[i]], lbl_8043CCF4[i]);
            }
        }
    }
    if (((Obj_800DD8AC *)this)->flags & 0x10) {
        set_state(6);
    }
}

void TObjEnePanarms::set_state_flags_6() {
    u8 *temp_r5;
    temp_r5 = (u8 *)this->m_390;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    obj_clearFlags30(0x04040000U);
    set_field_b8__10TObjMotionFs(this, 6);
}

typedef struct Stack_800DDFDC Stack_800DDFDC;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
typedef char RecoveredGlobal_800DD9A0_lbl_80494F4C_size[sizeof(RecoveredGlobal_800DD9A0_lbl_80494F4C) == 0x210 ? 1 : -1];
void TObjEnePanarms__sub_800DD9A0(u8 *object) {
    typedef char sp8_offset[(offsetof(Stack_800DD9A0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800DD9A0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800DD9A0, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800DD9A0, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_800DD9A0, sp18) == 0x10) ? 1 : -1];
    Stack_800DD9A0 stack;
    f32 temp_f2;
    s32 temp_r0;
    *(s32 *)((s8 *)object + 0x388) = (s32) (*(s32 *)((s8 *)object + 0x388) - 1);
    if ((s8) lbl_805D5280 == 0) {
        lbl_805D5280 = 1;
        lbl_805D527C = *(f32 *)((s8 *)&lbl_80494F4C.value + 0x48);
    }
    temp_f2 = *(f32 *)((s8 *)object + 0xC0);
    if ((temp_f2 >= lbl_805DA4A8) && (temp_f2 < (lbl_805DA4A8 + lbl_805D527C))) {
        VecCopy((Vec *)(&stack.sp14), (const Vec *)(object + 0x2FC));
        stack.sp18 += TObjEnePanarms__data_805DA49C;
        spawn_particle_effect((&stack.sp14), 0xF0);
    }
    temp_r0 = *(s32 *)((s8 *)object + 0x388);
    if (temp_r0 <= 0x78) {
        if (temp_r0 == 0x78) {
            stack.sp8 = (lbl_805DA4AC * *(f32 *)((s8 *)object + 0x38)) + (lbl_805DA4AC * *(f32 *)((s8 *)object + 0x3A0));
            stack.spC = *(f32 *)((s8 *)object + 0x3C);
            stack.sp10 = (lbl_805DA4AC * *(f32 *)((s8 *)object + 0x40)) + (lbl_805DA4AC * *(f32 *)((s8 *)object + 0x3A8));
            ((TObjPlayer *)(&stack.sp8))->spawn_ground_effect(0x78);
            TObjPlayer::spawn_dead_spot_default((s32)((void *)&stack.sp8), 6);
        }
        if ((s32) *(s32 *)((s8 *)object + 0x388) == 0x5A) {
            *(s32 *)((s8 *)object + 0x3E0) = 0;
        }
        *(f32 *)((s8 *)object + 0x3C) = (f32) (*(f32 *)((s8 *)object + 0x3C) - lbl_805DA4B0);
        if ((s32) *(s32 *)((s8 *)object + 0x388) <= 0) {
            queue_destruction__7TObjectFv(object);
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEnePanarms__sub_800DDAD8(u8 *ene_panarms) {
    s16 st;
    Vec_800DDAD8 v;
    ((TObjEnePanarms *)ene_panarms)->m_388 = 0xA4;
    refresh_lobby_state__10TObjPlayerFv();
    ((TObjEnemy *)ene_panarms)->send_entity_set_flags();
    st = 5;
    if (find_nearest_visible_player(ene_panarms, &v.x, lbl_805DA4B4) != 0xFFFF) {
        if (v.x * sin_table_lookup(((TObjEnePanarms *)ene_panarms)->rotation_y) + v.z * cos_table_lookup(((TObjEnePanarms *)ene_panarms)->rotation_y) < TObjEnePanarms__data_805DA4A0) {
            st = 4;
        }
    }
    set_field_b8__10TObjMotionFs(ene_panarms, st);
    play_sound_effect(((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003B836)), ene_panarms + 0x3AC, 0, 0);
    play_sound_effect(((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003BB35)), ene_panarms + 0x3C4, 0, 0);
    if (*(s32 *)((s8 *)ene_panarms + 0x3DC) != 0) {
        if (TObjEnePanarms__sub_800DFB44(((TObjEnePanarms *)ene_panarms)->m_3e4) == 0) {
            ((TObjEnePanarms *)(((TObjEnePanarms *)ene_panarms)->m_3e4))->reset_split();
        }
        if (TObjEnePanarms__sub_800DFB44(((TObjEnePanarms *)ene_panarms)->m_3e8) == 0) {
            ((TObjEnePanarms *)(((TObjEnePanarms *)ene_panarms)->m_3e8))->reset_split();
        }
    } else {
        if (TObjEnePanarms__sub_800DFB44(((TObjEnePanarms *)ene_panarms)->m_3e4) == 0) {
            TObjEnePanarms__sub_800E1D38((void *)(((TObjEnePanarms *)ene_panarms)->m_3e4));
        }
        if (TObjEnePanarms__sub_800DFB44(((TObjEnePanarms *)ene_panarms)->m_3e8) == 0) {
            TObjEnePanarms__sub_800E1D38((void *)(((TObjEnePanarms *)ene_panarms)->m_3e8));
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
struct Vec_800DEB48;
struct Obj_800DE9F0;
struct Obj_800DEA88;
void TObjEnePanarms__sub_800DDC30(Obj_800DDC30 *o) {
    f32 s;
    if (o->fc0 >= TObjEnePanarms__data_805DA4A0 && o->fc0 <= lbl_805DA4B8) {
        s32 mode = 1;
        if ((f32)o->f388 < lbl_805DA4BC) {
            mode = 0;
        }
        if (TObjEnePanarms__sub_800DFBC4(o) != 0) {
            ((TObjEnePanarms *)o)->turn_toward_target(0x100);
        } else {
            ((TObjEnePanarms *)o)->turn_to_nearest_player(0x100, mode);
        }
    }
    if (o->fc0 >= 14.0f && o->fc0 <= 20.0f) {
        s = sin_table_lookup((s32)(lbl_805DA4C4 * (o->fc0 - 14.0f) / lbl_805DA4C8));
    } else {
        s = TObjEnePanarms__data_805DA4A0;
    }
    if (s > TObjEnePanarms__data_805DA4A0) {
        Vec_800DDC30 pos = o->pos;
        f32 r = lbl_805DA4CC * s;
        if (o->f38C == 1) {
            r *= lbl_805DA4D0;
        }
        pos.x += r * cos_table_lookup(o->f60);
        pos.z += -r * sin_table_lookup(o->f60);
        try_warp_to_position__14TObjEnePanarmsFPvPv((u8 *)o, (Vec_800DEB48 *)&pos);
    }
    if (TObjEnePanarms__sub_800DFBC4(o) == 0) {
        if (TObjEnePanarms__sub_800DE494(o) != 0) {
            ((TObjEnePanarms *)o)->set_state(1);
            return;
        }
        if (o->f3F8 == 0 && o->f32C <= o->f3F4 / 3 &&
            TObjEnePanarms__sub_800DE528(o, (Vec_800DE528 *)&o->pos) != 0) {
            ((TObjEnePanarms *)o)->set_state(9);
            return;
        }
    }
    if (--o->f388 > 0) {
        return;
    }
    if (TObjEnePanarms__sub_800DFBC4(o) == 0 && o->f3FC >= 3 &&
        TObjEnePanarms__sub_800DE528(o, (Vec_800DE528 *)&o->pos) != 0) {
        o->f3FC = 0;
        ((TObjEnePanarms *)o)->set_state(9);
        return;
    }
    switch (o->f38C) {
    case 0:
        o->f3EC++;
        o->f3F0 = 0;
        ((TObjEnePanarms *)o)->set_state(7);
        break;
    case 1:
        ((TObjEnePanarms *)o)->set_state(5);
        break;
    }
}
#pragma pop

void TObjEnePanarms__sub_800DDED8(u8 *actor) {
    s16 var_r30;
    switch (*(s32 *)((s8 *)actor + 0x38C)) {
    case 0:
        *(s32 *)((s8 *)actor + 0x38C) = 1;
        var_r30 = 2;
        break;
    case 1:
        *(s32 *)((s8 *)actor + 0x38C) = 0;
        var_r30 = 1;
        break;
    default:
        return;
    }
    *(s32 *)((s8 *)actor + 0x3FC) += 1;
    *(u32 *)((s8 *)(*(u8 **)((s8 *)actor + 0x390)) + 0x18) &= ~0x08000000;
    *(u32 *)((s8 *)(*(u8 **)((s8 *)actor + 0x390)) + 0x18) |= 1;
    ((TObjBase *)actor)->obj_clearFlags30(0x04040000);
    *(s32 *)((s8 *)actor + 0x388) = (s32) (lbl_805DA4BC * (f32) ((s32) (lbl_805DA4D4 * random_ratio__9TObjCharaFv((s32)actor)) + 1));
    set_field_b8__10TObjMotionFs(actor, var_r30);
}

void TObjEnePanarms::update_fall() {
    u8 *arg0 = (u8 *)this;
  Stack_800DDFDC stack;
  f32 temp_f1;
  *((f32 *) (((s8 *) arg0) + 0x37C)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x37C))) + lbl_805DA4D8);
  vec3_add_to((u8 *)&this->position, (u8 *)&this->m_378);
  if ((*((f32 *) (((s8 *) arg0) + 0x37C))) <= TObjEnePanarms__data_805DA4A0)
  {
    ;
    if ((*((f32 *) (((s8 *) arg0) + 0x3C))) <= (*((f32 *) (((s8 *) arg0) + 0x384))))
    {
      *((f32 *) (((s8 *) arg0) + 0x3C)) = *((f32 *) (((s8 *) arg0) + 0x384));
      spawn_particle_effect(((u8 *)&this->position), 0xF0);
      set_state((s32)((void*)(3)));
      return;
    }
  }
  this->m_388 = (s32) ((this->m_388) + 1);
  if ((!((this->m_388) & 7)) && ((*((f32 *) (((s8 *) arg0) + 0x37C))) > TObjEnePanarms__data_805DA4A0))
  {
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x2FC));
    stack.spC = TObjEnePanarms__data_805DA49C + (*((f32 *) (((s8 *) arg0) + 0x384)));
    spawn_particle_effect((&stack.sp8), 0xF0);
  }
}

void TObjEnePanarms::set_hidden_flags() {
    u8 *temp_r5;
    *(f32 *)&this->m_378 = (f32) TObjEnePanarms__data_805DA4A0;
    *(f32 *)&this->unk_37C = (f32) lbl_805DA4DC;
    *(f32 *)&this->m_380 = (f32) TObjEnePanarms__data_805DA4A0;
    *(s32 *)&this->unk_3E0 = 1;
    *(s32 *)&this->m_3dc = 1;
    temp_r5 = (u8 *)(*(u8 * *)&this->m_390);
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFFFFFE);
    obj_clearFlags30(0x40000U);
    obj_setFlags30(this, (int)(0x04000000U));
}

void TObjEnePanarms__sub_800DE124(Obj_800DE124 *arg0) {
    f32 sp[3];
    s32 r = 0;
    s32 t;
    if (--arg0->f388 < 0) {
        r = 1;
    } else if ((t = find_nearest_visible_player(arg0, sp, (f32) arg0->f474)) != 0xFFFF) {
        arg0->f60 = (s32) (TObjEnePanarms__data_8043CD20 * atan2_float(sp[0], sp[2]));
        r = 1;
    }
    if (r != 0) {
        ((TObjEnePanarms *)arg0)->set_state((s32)((void*)((void *)2)));
    }
}

void init_state__14TObjEnePanarmsFPv(u8 *ene_panarms) {
    u8 *temp_r4;
    u8 *temp_r4_2;

    VecCopy((Vec *)(ene_panarms + 0x38), (const Vec *)(ene_panarms + 0x50));
    ((TObjEnePanarms *)ene_panarms)->snap_to_ground();
    *(f32 *)((s8 *)ene_panarms + 0x3C) = (f32) (lbl_805DA4E0 + *(f32 *)((s8 *)ene_panarms + 0x384));
    obj_setFlags30(ene_panarms, 0x04040000);
    temp_r4 = (unsigned char *) (*(void **)((s8 *)ene_panarms + 0x390));
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    temp_r4_2 = (unsigned char *) (*(void **)((s8 *)ene_panarms + 0x390));
    *(s32 *)((s8 *)temp_r4_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0x18) | 0x08000000);
    *(s32 *)((s8 *)ene_panarms + 0x3E0) = 0;
    *(s32 *)((s8 *)ene_panarms + 0x3DC) = 0;
    ((TObjEnePanarms *)ene_panarms)->m_388 = (s32) ((TObjEnePanarms *)ene_panarms)->m_478;
}

void TObjEnePanarms::try_activate() { if (check_demo_mode__10TObjPlayerFv(this) == 0) { set_state((s32)((void*)((void*)1))); } }
void TObjEnePanarms__sub_800DE2B0(void* p) { *(s32*)((char*)p + 0x3e0) = 1; *(s32*)((char*)p + 0x3dc) = 1; }
void TObjEnePanarms::vfunc_61() { this->actorFlags &= 0xfffffeff; }

void TObjEnePanarms::vfunc_62() {
    Obj_800DE2D0 *arg0 = (Obj_800DE2D0 *)this;
    switch (arg0->f374) {
    case 1:
    case 2:
        return;
    default:
        arg0->f30 &= 0xFFFFFDFF;
        play_sound_effect((s32)(((int)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003BC34)))), arg0->f3AC, 0, 0);
        play_sound_effect((s32)(((int)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003BC33)))), arg0->f3C4, 0, 0);
        break;
    }
}

void TObjEnePanarms::vfunc_63() { if (*(int *)&this->unk_374 != 4) { set_state((s32)((void*)((void*)4))); } }

s32 TObjEnePanarms::sub_800DE390() {
    Obj_800DE390 *arg0 = (Obj_800DE390 *)this;
    switch (arg0->f374) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 10:
    case 11:
        return 0;
    default:
        if (TObjEnePanarms__sub_800DFB44(this->m_3e4) != 0 || TObjEnePanarms__sub_800DFB44(this->m_3e8) != 0) {
            ((TObjEnePanarms *)arg0)->set_state((s32)((void*)((void *)10)));
            return 1;
        }
        return 0;
    }
}

void TObjEnePanarms__sub_800DE430(s32 arg0, s32 arg1, s32 arg2) {
    Vec position;
    VecCopy((Vec *)(&position.x), (const Vec *)(arg0 + 0x2FC));
    position.y += TObjEnePanarms__data_805DA4A4;
    create_particle_controller_with_rotation(&position, (ParticleAngles *)(arg0 + 0x5C), 0x106, arg1, arg2);
}

#pragma push
#pragma opt_loop_invariants off
s32 TObjEnePanarms__sub_800DE494(void *self) {
    s32 i;
    f32 best = lbl_805DA4E4;
    for (i = 0; i < registered_player_count; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (player != NULL) {
            f32 d = horizontal_distance_squared((u8 *)self + 0x38, (u8 *)player + 0x2FC);
            if (d < best) {
                best = d;
            }
        }
    }
    if (best < lbl_805DA4E4) {
        return 0;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjEnePanarms__sub_800DE528(void *arg0, Vec_800DE528 *arg1) {
    Vec_800DE528 v;
    f32 r;
    s32 step;
    s32 a;
    VecCopy((Vec *)&v, (const Vec *)arg1);
    v.y += TObjEnePanarms__data_805DA4A4;
    if (project_actor_to_ground(arg0, &v, 0) == 0) {
        return 0;
    }
    for (r = TObjEnePanarms__data_805DA4A4; r <= TObjEnePanarms__data_805DA490; r += TObjEnePanarms__data_805DA4A4) {
        step = (s32)(lbl_805DA4E8 / (lbl_805DA4EC * r));
        for (a = 0; a < 0x10000; a += step) {
            VecCopy((Vec *)&v, (const Vec *)arg1);
            v.x += r * sin_table_lookup(a);
            v.y += TObjEnePanarms__data_805DA4A4;
            v.z += r * cos_table_lookup(a);
            if (project_actor_to_ground(arg0, &v, 0) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
#pragma pop

s32 check_ground_along_path__14TObjEnePanarmsFPvPvPvff(void *arg0, Vec_800DE6A8 *arg1, Vec_800DE6A8 *arg2, f32 step, f32 dy) {
    Vec_800DE6A8 p = *arg1;
    Vec_800DE6A8 d = *arg2;
    f32 len;
    f32 t;
    subtract_vector(&d, &p);
    len = vector_length(&d);
    if (len < step) {
        return 1;
    }
    normalize_vector(&d);
    d.x *= step;
    d.y *= step;
    d.z *= step;
    for (t = TObjEnePanarms__data_805DA4A0; t < len; ) {
        p.y += dy;
        if (project_actor_to_ground(arg0, &p, 0) == 0) {
            return 0;
        }
        t += step;
        vec3_add_to(&p, &d);
    }
    return 1;
}

#pragma push
#pragma opt_common_subs off
struct Vec_800DE528;
struct Vec_800DE6A8;
#define arg0 ((u8 *)p)
s32 TObjEnePanarms::find_combine_position(void *p) {
    Vec_800DE7EC sp14;
    Vec_800DE7EC sp8;
    f32 dist;
    f32 t;
    VecCopy((Vec *)&sp14, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x3E4) + 0x38));
    vec3_add_to(&sp14, *(u8 **)((s8 *)arg0 + 0x3E8) + 0x38);
    sp14.x *= lbl_805DA4AC;
    sp14.y *= lbl_805DA4AC;
    sp14.z *= lbl_805DA4AC;
    VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0x38));
    subtract_vector(&sp8, &sp14);
    dist = vector_length(&sp8);
    if (dist >= TObjEnePanarms__data_805DA4A4) {
        normalize_vector(&sp8);
        sp8.x *= TObjEnePanarms__data_805DA4A4;
        sp8.y *= TObjEnePanarms__data_805DA4A4;
        sp8.z *= TObjEnePanarms__data_805DA4A4;
    }
    t = TObjEnePanarms__data_805DA4A0;
    while (t < dist) {
        sp14.y += TObjEnePanarms__data_805DA4A4;
        if (project_actor_to_ground(arg0, &sp14, 0) != 0 &&
            TObjEnePanarms__sub_800DE528(arg0, (Vec_800DE528 *) &sp14) != 0 &&
            check_ground_along_path__14TObjEnePanarmsFPvPvPvff(arg0, (Vec_800DE6A8 *) (*(u8 **)((s8 *)arg0 + 0x3E4) + 0x38), (Vec_800DE6A8 *) &sp14, TObjEnePanarms__data_805DA4A4, TObjEnePanarms__data_805DA4A4) != 0 &&
            check_ground_along_path__14TObjEnePanarmsFPvPvPvff(arg0, (Vec_800DE6A8 *) (*(u8 **)((s8 *)arg0 + 0x3E8) + 0x38), (Vec_800DE6A8 *) &sp14, TObjEnePanarms__data_805DA4A4, TObjEnePanarms__data_805DA4A4) != 0) {
            u8 *a;
            u8 *b;
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&sp14);
            a = *(u8 **)((s8 *)arg0 + 0x3E4);
            b = *(u8 **)((s8 *)arg0 + 0x3E8);
            ((TObjEnePanarms *)arg0)->rotation_y = (s32) (TObjEnePanarms__data_8043CD20 * atan2_float(
                *(f32 *)((s8 *)b + 0x38) - *(f32 *)((s8 *)a + 0x38),
                *(f32 *)((s8 *)b + 0x40) - *(f32 *)((s8 *)a + 0x40))) + 0x4000;
            return 1;
        }
        t += TObjEnePanarms__data_805DA4A4;
        vec3_add_to(&sp14, &sp8);
    }
    return 0;
}
#undef arg0
#pragma pop

void TObjEnePanarms::turn_toward_target(s32 arg1) {
    f32 sp[3];
    if (this->find_nearest_enemy_with_flag((s32)sp, (f32)lbl_805DA4F0) == 0xFFFF) {
        if (((Obj_800DE9F0 *)this)->f1C & 1) {
            arg1 *= -1;
        }
        ((Obj_800DE9F0 *)this)->f60 = ((Obj_800DE9F0 *)this)->f60 + arg1;
        return;
    }
    ((Obj_800DE9F0 *)this)->f60 = approach_angle_limited(((Obj_800DE9F0 *)this)->f60, (s32) (TObjEnePanarms__data_8043CD20 * atan2_float(sp[0], sp[2])), arg1);
}

u16 TObjEnePanarms::turn_to_nearest_player(s32 arg1, s32 arg2) {
    f32 sp[3];
    s32 t;
    s32 var;
    if ((t = find_nearest_visible_player(this, sp, lbl_805DA4B4)) != 0xFFFF) {
        if (arg2 == 0 || vector_length(sp) < lbl_805DA4F4) {
            var = 0;
        } else {
            var = -0x1800;
            if (((Obj_800DEA88 *)this)->f38C == 1) {
                var *= -1;
            }
        }
        ((Obj_800DEA88 *)this)->f60 = approach_angle_limited(((Obj_800DEA88 *)this)->f60, var + (s32) (TObjEnePanarms__data_8043CD20 * atan2_float(sp[0], sp[2])), arg1);
    }
    return t;
}

#pragma push
#pragma fp_contract on
s32 try_warp_to_position__14TObjEnePanarmsFPvPv(u8 *player, Vec_800DEB48 *arg1) {
    s32 ok;
    s32 i;
    s32 ang;
    f32 c;
    f32 s;
    f32 x;
    Vec_800DEB48 d;
    Vec_800DEB48 p;
    Vec_800DEB48 hit;
    ok = 0;
    if (!(horizontal_distance_squared(player + 0x38, player + 0x50) > lbl_805DA4E4)) {
        VecCopy((Vec *)&d, (const Vec *)arg1);
        subtract_vector(&d, player + 0x38);
        if (TObjEnePanarms__data_805DA4A0 != vector_length(&d)) {
            i = 1;
            do {
                VecCopy((Vec *)&p, (const Vec *)(player + 0x38));
                vec3_add_to(&p, &d);
                p.y += TObjEnePanarms__data_805DA4A4;
                if (((s32 (*)(void *, void *, void *))project_actor_to_ground)(player, &p, &hit) != 0 && csnLookAt(player + 0x38, &p) == 0) {
                    VecCopy((Vec *)(player + 0x44), (const Vec *)(player + 0x38));
                    VecCopy((Vec *)(player + 0x38), (const Vec *)&p);
                    *(f32 *)((s8 *)player + 0x384) = p.y;
                    VecCopy((Vec *)(player + 0x248), (const Vec *)&hit);
                    ok = 1;
                    break;
                }
                ang = i << 12;
                if (i & 1) {
                    ang *= -1;
                }
                c = sin_table_lookup(ang);
                s = cos_table_lookup(ang);
                i++;
                x = s * d.x - c * d.z;
                d.x = x;
                d.z = c * x + s * d.z;
            } while (i < 0x10);
        }
    }
    ((TObjPlayer *)player)->update_collisions();
    return ok;
}
#pragma pop

void TObjEnePanarms::snap_to_ground() {
    Vec_800DECC4 v = ((Obj_800DECC4 *)this)->pos;
    v.y += TObjEnePanarms__data_805DA4A4;
    if (project_actor_to_ground(((Obj_800DECC4 *)this), &v, (int)((Obj_800DECC4 *)this)->f248) != 0) {
        ((Obj_800DECC4 *)this)->f384 = v.y;
    }
}

void TObjEnePanarms::set_state(s32 arg1) {
    ((Obj_800DED30 *)this)->f374 = arg1;
    if (((Obj_800DED30 *)this)->f374 < 0 || ((Obj_800DED30 *)this)->f374 >= 14) {
        return;
    }
    destroy_handles();
    PMF_800DED30 p = lbl_8049515C[((Obj_800DED30 *)this)->f374].fn;
    if (p) {
        (((Obj_800DED30 *)this)->*p)();
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEnePanarms::draw_shadow() {
    Vec_800DEDC4 v;
    s32 spC;
    s32 sp8;
    f32 d;
    f32 k;
    f32 t;

    if (!(*(f32 *)&this->unk_384 > lbl_805DA4F8 + *(f32 *)((s8 *)((u8 *)this) + 0x3C))) {
        push_matrix(this);
        translate_matrix(0, lbl_805DA4FC * *(f32 *)((s8 *)((u8 *)this) + 0x38) + lbl_805DA500 * *(f32 *)&this->m_3a0, lbl_805DA504 + *(f32 *)&this->unk_384, lbl_805DA4FC * *(f32 *)((s8 *)((u8 *)this) + 0x40) + lbl_805DA500 * this->m_3a8);
        direction_to_rotation_xz(((u8 *)this) + 0x248, &spC, &sp8);
        rotate_matrix_z(0, sp8);
        rotate_matrix_y((void *) 0, *(void * *)&this->rotation_y);
        rotate_matrix_x(0, spC + 0x4000);
        d = *(f32 *)((s8 *)((u8 *)this) + 0x3C) - *(f32 *)&this->unk_384;
        if (d > lbl_805DA508) {
            d = lbl_805DA508;
        } else if (d < TObjEnePanarms__data_805DA4A0) {
            d = TObjEnePanarms__data_805DA4A0;
        }
        t = lbl_805DA514 - d / lbl_805DA508;
        k = lbl_805DA510 * t + lbl_805DA50C;
        v.z = lbl_805DA514;
        v.x = TObjEnePanarms__data_805DA49C * k;
        v.y = lbl_805DA518 * k;
        scale_current_matrix(&v);
        draw_blob_shadow(0);
        pop_matrix();
    }
}

#pragma pop

void TObjEnePanarms__sub_800DEEF8(void* p) { push_matrix(p); post_translate_matrix((char*)p + 0x38); rotate_matrix_y((void*)0, *(void**)((char*)p + 0x60)); TObjFish::set_global_param((s32)(*(void**)((char*)p + 0x24))); ((TObjFish *)(((TObjEneRe7Berura *)p)->m_39c))->set_draw_callback_list(); ((TObjMotion *)p)->draw(); clear_render_callback__8TObjFishFv(((TObjEneRe7Berura *)p)->m_39c); pop_matrix(); }

#include "pso/misc/RenderFadeState.h"

// The camera-obstruction fade (vtable __vt__15RenderFadeState) keeps its vtable pointer at +0x14.
struct VFade_800DEF5C {
    u8 pad[0x14];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void begin_draw();
    virtual void end_draw();
};

extern "C" {
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
void update__15RenderFadeStateFv(RenderFadeState *);
s32 defer_render__7TObjectFv(void *);
extern s32 model_render_flags;
extern s32 saved_model_render_flags;
s32 submit_cursor_candidate(void *, s32);
s32 minimap_render_dot(void *, s32, s32, s32);
}

struct VObj_18_800DEF5C {
    u8 pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Obj_800DEF5C { u8 pad[0x400]; RenderFadeState fades[4]; };

void TObjEnePanarms::render() {
    s32 cam;
    RenderFadeState *fade;
    s32 draw;
    if (((VObj_18_800DEF5C *)this)->m8(lbl_805DA4F0, TObjEnePanarms__data_805DA490) == 0) {
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    if (*(s32 *)&this->m_3dc == 0) {
        return;
    }
    TObjPlayer::toggle_particle_effect();
    saved_model_render_flags = model_render_flags;
    fade = &((Obj_800DEF5C *)this)->fades[cam];
    update__15RenderFadeStateFv(fade);
    if (fade->updateFromCamera(&this->m_2fc) != 0) {
        ((VFade_800DEF5C *)fade)->begin_draw();
        draw = 1;
        if (defer_render__7TObjectFv(this) != 0) {
            draw = 0;
        }
        if (draw != 0) {
            TObjEnePanarms__sub_800DEEF8(this);
        }
        ((VFade_800DEF5C *)fade)->end_draw();
    } else {
        model_render_flags |= 0x01000000;
        TObjEnePanarms__sub_800DEEF8(this);
    }
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    if (*(s32 *)&this->unk_3E0 != 0) {
        draw_shadow();
    }
}

void TObjEnePanarms::run_task() {
    PMF_800DED30 p;
    if (*(s32 *)&this->unk_374 != 0 && TObjPlayer::check_demo_mode() != 0) {
        set_state(0);
    }
    sub_800DE390();
    p = lbl_8049515C[*(s32 *)&this->unk_374].update;
    if (p) {
        (((Obj_800DED30 *)this)->*p)();
        if (*(s32 *)&this->m_3dc != 0) {
            this->actorFlags &= ~0x02000000;
        } else {
            this->actorFlags |= 0x02000000;
        }
        update_prev_position();
        if (*(s32 *)&this->unk_374 != 0) {
            if (*(s32 *)&this->m_3dc != 0) {
                submit_cursor_candidate(this, -1);
                advance_animation();
            }
            if ((*(s32 *)&this->m_3dc != 0 && *(s32 *)&this->unk_374 != 4) || *(s32 *)&this->unk_374 == 1) {
                minimap_render_dot(&this->m_2fc, -0x5DB4, 1, 0);
            }
        }
    }
}

void TObjEnePanarms::destroy_handles() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (((Obj_800DF1B8 *)this)->handles[i] != 0) {
            TParticleCtrl::release((void *)((Obj_800DF1B8 *)this)->handles[i]);
            ((Obj_800DF1B8 *)this)->handles[i] = 0;
        }
    }
}

u8 *__dt__14TObjEnePanarmsFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjEnePanarms;
        TObjFish::init_state_1(*(u8 **)((s8 *)arg0 + 0x39C));
        queue_destruction__7TObjectFv(*(u8 **)((s8 *)arg0 + 0x3E4));
        queue_destruction__7TObjectFv(*(u8 **)((s8 *)arg0 + 0x3E8));
        free_collision_body_parts(arg0);
        ((TObjEnePanarms *)arg0)->m_390 = 0;
        ((TObjEnePanarms *)arg0)->destroy_handles();
        __destroy_arr(arg0 + 0x400, __dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

void TObjEnePanarms::free_data() {
    if ((u32) TObjEnePanarms__entry_params_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEnePanarms__entry_params_resource, 1);
        TObjEnePanarms__entry_params_resource = 0U;
    }
}
void TObjEnePanarms::load_and_spawn_npc() {
    Obj_800DF634 *o = (Obj_800DF634 *) ::operator new(0x440);
    if (o != NULL) {
        o = load_resource_from_descriptor(o, 1, lbl_80494F10, 0, 0, 0);
    }
    TObjEnePanarms__entry_params_resource = (u32) o;
    if (o != NULL) {
        S_800DF634 sp = panarms_npc_spawn_descriptor[0];
        sp.a = o->f430;
        spawn_npc_enemy__6TLobbyFslllff(0x23, *(s32 *)(o->f42C + 8), *(s32 *)(o->f42C + 0xC), &sp, panarms_npc_spawn_descriptor[0].a, panarms_npc_spawn_descriptor, lbl_805DA51C, TObjEnePanarms__data_805DA4A0);
        TObjEnePanarms::spawn_npc_pair();
    }
}
}
