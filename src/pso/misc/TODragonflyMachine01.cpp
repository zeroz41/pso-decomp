#include "types.h"
#include "pso/misc/TODragonflyMachine01.h"
#include "pso/misc/TODragonflyCave01.h"
#include "pso/misc/TODragonfly.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/TODummyKeyCave01Sound.h"

#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_80165538___vt__20TODragonflyMachine01 {
    s32 value;
    u8 remaining[0x3C];
};

struct T4_80165434 { s32 v[4]; };

struct Sub_80165434 { u8 pad[8]; s32 a; s32 b; };

struct O_80165434 { u8 pad[0x42C]; Sub_80165434 *sub; s32 f430; };

extern "C" {
s32 rand(void);
f32 sin_table_lookup(s32);
extern s32 __vt__20TODragonflyMachine01[];
extern s32 TODragonflyMachine01__class_name;
extern u32 TODragonflyMachine01__model_resource;
extern const f32 lbl_805DB598;
extern const f32 lbl_805DB5B8;
extern const f32 lbl_805DB5BC;
extern const f32 lbl_805DB5C0;
extern const f32 lbl_805DB5C4;
extern const f32 lbl_805DB5C8;
extern const f32 lbl_805DB5CC;
O_80165434 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern s32 dragonfly_machine_attack_effect_params[];
extern char TODragonflyMachine01__attack_effect_descriptor[];
extern s32 lbl_805D599C;
extern s32 lbl_805D59A0;
extern const f32 lbl_805DB5B0;
extern const f32 lbl_805DB5B4;
s32 play_sound_effect(s32, s32, s32, s32);
void TLobby__sub_8001FE7C(void*, int);
s32 TODragonflyMachine01__sub_80164F50(void *);
s32 rotate_matrix_y(s32, s32);
void *__nw__7TObjectFUl(int);

void TODragonflyMachine01::update_timer() {
    if ((s32) lbl_805D599C == 6) {
        rotate_matrix_y(0, lbl_805D59A0);
    }
    lbl_805D599C += 1;
}

void TODragonflyMachine01::run_task() {

    this->m_fc = (s32) (this->m_fc + this->m_f8);
    *(f32 *)((s8 *)this + 0xF0) = (f32) (this->m_ec * sin_table_lookup(this->m_fc));
    if (TObjPlayer::check_demo_mode() == 1) {
        this->vfunc_14();
        return;
    }
    update_anim_phase();
    switch (this->m_ac) {
    case 0:
        TODragonflyMachine01__sub_80164F50(this);
        update_idle();
        return;
    case 1:
        sub_80164A90();
        return;
    case 2:
        TODragonflyMachine01__sub_80164F50(this);
        sub_80164990();
        return;
    case 3:
        move_toward_target();
        return;
    }
}

void *TODragonflyMachine01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x108);
    if (o != NULL) {
        o = TODragonflyMachine01__ct((u8 *)o, (int)arg0);
    }
    return o;
}

void TODragonflyMachine01::unload_static_data() {
    if ((u32) TODragonflyMachine01__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TODragonflyMachine01__model_resource, 1);
        TODragonflyMachine01__model_resource = 0U;
    }
}

void TODragonflyMachine01::create_attack_effect() {
    T4_80165434 sp8;
    O_80165434 *o;
    s32 z = 0;
    o = (O_80165434 *)::operator new(0x440);
    if (o != NULL) {
        o = load_resource_from_descriptor(o, 1, TODragonflyMachine01__attack_effect_descriptor, 0, 0, 0);
    }
    (*(O_80165434 * *)&TODragonflyMachine01__model_resource) = o;
    lbl_805D599C = z;
    lbl_805D59A0 = z;
    sp8.v[0] = dragonfly_machine_attack_effect_params[0];
    sp8.v[1] = dragonfly_machine_attack_effect_params[1];
    sp8.v[2] = dragonfly_machine_attack_effect_params[2];
    sp8.v[3] = dragonfly_machine_attack_effect_params[3];
    sp8.v[0] = o->f430;
    TObjEneMe3Stelth::spawn_attack((s16)0x38, o->sub->a, o->sub->b, (s32)&sp8, (f32)lbl_805DB5B0, (f32)lbl_805DB5B4);
}

}
TODragonflyMachine01::~TODragonflyMachine01() {

}


#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_80165538___vt__20TODragonflyMachine01_size[sizeof(RecoveredGlobal_80165538___vt__20TODragonflyMachine01) == 0x40 ? 1 : -1];
u8 *TODragonflyMachine01__ct(u8 *dragonfly_machine01, int arg1) {
    struct Fields_arg0 { int field_0; u8 pad_4[20]; s32 * field_18; u8 pad_1C[8]; int field_24; u8 pad_28[12]; u8 * field_34; u8 pad_38[76]; int field_84; int field_88; u8 pad_8C[32]; int field_AC; u8 pad_B0[4]; f32 field_B4; f32 field_B8; u8 * field_BC; f32 field_C0; f32 field_C4; u8 pad_C8[36]; f32 field_EC; f32 field_F0; f32 field_F4; int field_F8; int field_FC; s16 field_100; s16 field_102; int field_104; };
    TODragonfly__ct((TODragonfly *)dragonfly_machine01);
    ((Fields_arg0*)dragonfly_machine01)->field_18 = &(*(RecoveredGlobal_80165538___vt__20TODragonflyMachine01 *)&__vt__20TODragonflyMachine01).value;
    ((Fields_arg0*)dragonfly_machine01)->field_0 = (int) TODragonflyMachine01__class_name;
    ((TODragonflyMachine01 *)(dragonfly_machine01))->apply_object_set_data((void *)arg1);
    ((Fields_arg0*)dragonfly_machine01)->field_34 = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODragonflyMachine01__model_resource) + 0x42C)) + 8));
    ((Fields_arg0*)dragonfly_machine01)->field_24 = (int) *(int *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODragonflyMachine01__model_resource) + 0x42C)) + 0xC);
    ((Fields_arg0*)dragonfly_machine01)->field_BC = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODragonflyMachine01__model_resource) + 0x430)) + 4));
    ((Fields_arg0*)dragonfly_machine01)->field_B4 = (f32) ((f32) *(unsigned int *)((s8 *)(((Fields_arg0*)dragonfly_machine01)->field_BC) + 4) - lbl_805DB5B8);
    ((Fields_arg0*)dragonfly_machine01)->field_B8 = (f32) lbl_805DB5B8;
    ((Fields_arg0*)dragonfly_machine01)->field_C0 = (f32) lbl_805DB5BC;
    ((Fields_arg0*)dragonfly_machine01)->field_C4 = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)(((Fields_arg0*)dragonfly_machine01)->field_34) + 4)) + 0x14);
    ((Fields_arg0*)dragonfly_machine01)->field_AC = 0;
    ((Fields_arg0*)dragonfly_machine01)->field_F4 = (f32) ((lbl_805DB5C0 * (f32) ((Fields_arg0*)dragonfly_machine01)->field_84) + lbl_805DB5B8);
    ((Fields_arg0*)dragonfly_machine01)->field_F8 = (int) (lbl_805DB5C4 * (lbl_805DB5C8 / (lbl_805DB5CC / ((Fields_arg0*)dragonfly_machine01)->field_F4)));
    ((Fields_arg0*)dragonfly_machine01)->field_FC = (int) (lbl_805DB5C4 * (lbl_805DB5C8 * (lbl_805DB598 * (f32) rand())));
    ((Fields_arg0*)dragonfly_machine01)->field_EC = (f32) ((lbl_805DB5C0 * (f32) ((Fields_arg0*)dragonfly_machine01)->field_88) + lbl_805DB5B8);
    ((Fields_arg0*)dragonfly_machine01)->field_F0 = (f32) (((Fields_arg0*)dragonfly_machine01)->field_EC * sin_table_lookup(((Fields_arg0*)dragonfly_machine01)->field_FC));
    ((Fields_arg0*)dragonfly_machine01)->field_100 = 0;
    ((Fields_arg0*)dragonfly_machine01)->field_102 = 0;
    ((Fields_arg0*)dragonfly_machine01)->field_104 = 0;
    return dragonfly_machine01;
}
#pragma pop

void TODummyKeyCave01Sound::play_cave01_key_sound() {
    s32 global_state;
    s32 temp_r3_2;

    switch (*(s32 *)((s8 *)this + 0x1C)) {
    case 1:
        play_sound_effect(0x4005281F, 0, 0, 0);
        return;
    case 2:
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    case 3:
        global_state = get_current_area();
        if ((global_state != 0x10) && (global_state != 0x11)) {
            play_sound_effect(0x52812, 0, 0, 0);
            return;
        }
        break;
    case 4:
        temp_r3_2 = get_current_area();
        if ((temp_r3_2 != 0x10) && (temp_r3_2 != 0x11)) {
            play_sound_effect(0x52813, 0, 0, 0);
            return;
        }
        break;
    case 5:
        play_sound_effect(0x4001C112, 0, 0, 0);
        return;
    case 6:
        play_sound_effect(0x4002A60B, 0, 0, 0);
        break;
    }
}

