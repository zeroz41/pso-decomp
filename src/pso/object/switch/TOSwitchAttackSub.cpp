#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/switch/TOSwitchAttackSub.h"
#include "pso/system/task/TObject_80019A50.h"
#include "types.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/unk/text_800870BC.h"
#include "pso/unk/text_80177608.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/switch/TOSwitchAttack.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"

const char *TOSwitchAttack__name = "TOSwitchAttack";
const char *TOSwitchAttackSub__name = "TOSwitchAttackSub";

extern "C" {
f32 horizontal_distance_squared(const f32*, const f32*);
u8 is_current_floor_switch_set(int);
extern u8* camera_ctrl_instance;
extern void* local_client_id;

}

void TOSwitchAttackSub::run_task() {
    f32 playerDistance;
    u8* player;
    if (is_current_floor_switch_set(stopSwitchId) == 1) {
        queue_destruction();
        return;
    }
    if (is_current_floor_switch_set(requiredSwitchId) == 0) {
        queue_destruction();
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
    if (particle != nullptr) ((TObject *)particle)->queue_destruction();
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Parm_80177608 { s32 a; s32 b; s32 c; };

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__17TOSwitchAttackSub[];

u8 *TOSwitchAttackSub__ct(u8 *object, u8 *arg1, s32 arg2, s32 arg3, u32 arg4, f32 farg0) {
    Parm_80177608 p;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)(object + 0x18) = __vt__17TOSwitchAttackSub;
    *(const char **)(object + 0) = TOSwitchAttackSub__name;
    ((TObject *)object)->disallow_rendering();
    *(s16 *)(object + 0x1C) = arg2;
    *(s16 *)(object + 0x1E) = arg3;
    *(void **)(object + 0x20) = 0;
    VecCopy((Vec *)(object + 0x24), (const Vec *)(arg1 + 0x38));
    // Particle effect id and z rotation per sub type (arg4); the rotation is
    // the third word of the direction spawn_particle_effect_with_rotation reads.
    s32 effect_ids[18] = {132, 149, 175, 196, 207, 223, 225, 371, 430,
                          34, 69, 232, 332, 333, 412, 200, 244, 452};
    s32 rotation_z[18] = {0x8000, 0, 0x8000, 0x8000};
    if (arg4 < 18) {
        p.b = 0;
        p.a = 0;
        p.c = rotation_z[arg4];
        *(void **)(object + 0x20) = spawn_particle_effect_with_rotation(object + 0x24, &p, effect_ids[arg4], 0x40);
        if (*(void **)(object + 0x20) != 0) {
            if ((s32) arg4 == 10) {
                ((TParticleCtrl *)(*(void **)(object + 0x20)))->set_scale(1.25f * farg0, 1.25f * farg0);
            } else {
                ((TParticleCtrl *)(*(void **)(object + 0x20)))->set_scale(farg0, farg0);
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
