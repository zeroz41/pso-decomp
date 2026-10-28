#include "pso/TOSwitchAttackSub.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TParticleCtrl.h"
#include "types.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/unk/text_800870BC.h"
#include "pso/unk/text_80177608.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TOSwitchAttack.h"

extern "C" {
f32 horizontal_distance_squared(const f32*, const f32*);
void *get_player_by_client_id(s32 i);
u8 is_current_floor_switch_set(int);
extern u8* camera_ctrl_instance;
extern void* local_client_id;

}

void TOSwitchAttackSub::run_task() {
    f32 playerDistance;
    u8* player;
    if (is_current_floor_switch_set(stopSwitchId) == 1) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (is_current_floor_switch_set(requiredSwitchId) == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (particle != 0 && (player = (u8 *)get_player_by_client_id((s32)local_client_id)) != 0 && camera_ctrl_instance != 0) {
        playerDistance = horizontal_distance_squared((const f32*)(player + 0x38), (const f32*)(camera_ctrl_instance + 0x178));
        if (2.0f * horizontal_distance_squared(position, (const f32*)(camera_ctrl_instance + 0x178)) < playerDistance) {
            ((TParticleCtrl *)particle)->enable();
            return;
        }
        ((TParticleCtrl *)particle)->clear_active_flag();
    }
}

TOSwitchAttackSub::~TOSwitchAttackSub() {
    if (particle != nullptr) queue_destruction__7TObjectFv(particle);
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl_80177608 { s32 v[18]; };

struct Parm_80177608 { s32 a; s32 b; s32 c; };

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern Tbl_80177608 switch_attack_sub_id_table;
extern Tbl_80177608 switch_attack_sub_init_table;
extern s32 __vt__17TOSwitchAttackSub[];
extern s32 lbl_805D317C;

u8 *TOSwitchAttackSub__ct(u8 *object, u8 *arg1, s32 arg2, s32 arg3, u32 arg4, f32 farg0) {
    Parm_80177608 p;
    Tbl_80177608 a;
    Tbl_80177608 b;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)(object + 0x18) = __vt__17TOSwitchAttackSub;
    *(s32 *)(object + 0) = lbl_805D317C;
    disallow_rendering__7TObjectFv((TObject *)object);
    *(s16 *)(object + 0x1C) = arg2;
    *(s16 *)(object + 0x1E) = arg3;
    *(void **)(object + 0x20) = 0;
    VecCopy((Vec *)(object + 0x24), (const Vec *)(arg1 + 0x38));
    a = switch_attack_sub_id_table;
    b = switch_attack_sub_init_table;
    if (arg4 < 18) {
        p.b = 0;
        p.a = 0;
        p.c = b.v[arg4];
        *(void **)(object + 0x20) = spawn_particle_effect_with_rotation(object + 0x24, &p, a.v[arg4], 0x40);
        if (*(void **)(object + 0x20) != 0) {
            if ((s32) arg4 == 10) {
                ((TObjPlayer *)(*(void **)(object + 0x20)))->set_position_xy(1.25f * farg0, 1.25f * farg0);
            } else {
                ((TObjPlayer *)(*(void **)(object + 0x20)))->set_position_xy(farg0, farg0);
            }
        }
    }
    return object;
}

}

extern "C" {

u32 __nw__7TObjectFUl(s32);

void TOSwitchAttack::create_sub(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    void *object;
    object = (void *)__nw__7TObjectFUl(0x30);
    if (object != (void *)0U) {
        TOSwitchAttackSub__ct((u8 *)object, (u8 *)arg0, arg1, arg2, (u32)arg3, farg0);
    }
}

extern s32 game_difficulty_selection;

void TOSwitchAttack::init_params() {
    f32 temp_f0;

    this->m_a7 = (u8) this->rotation_x;
    temp_f0 = this->scale.x;
    this->m_94 = (f32) (temp_f0 * temp_f0);
    *(f32 *)&this->unk_98 = (f32) (this->scale.y * (2.0f * (game_difficulty_selection + 1)));
    *(f32 *)&this->unk_90 = (f32) this->scale.z;
    if ((u8) this->m_a7 >= 0x15U) {
        this->m_a7 = 0U;
    }
    this->m_9c = 0;
    this->m_a0 = (u16) this->set_params[0];
    if ((u16) this->m_a0 >= 0x100U) {
        this->m_a0 = 0xFFFFU;
    }
    this->m_a2 = (u16) this->set_params[1];
    if ((u16) this->m_a2 >= 0x100U) {
        this->m_a2 = 0xFFFFU;
    }
    this->m_a4 = (u16) this->set_params[2];
    if ((u16) this->m_a4 > 1U) {
        this->m_a4 = 1U;
    }
}

}
