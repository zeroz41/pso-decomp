#include "types.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

struct Npc_801491B4 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1C[0x30 - 0x1C];
    s32 f30;
    u8 pad34[0x98 - 0x34];
    u8 sub98[0x326 - 0x98];
    s16 f326;
    u8 pad328[0x358 - 0x328];
    f32 f358;
    f32 f35C;
    f32 f360;
    f32 f364;
    u8 pad368[0x388 - 0x368];
    s32 f388;
    s32 f38C;
    s32 f390;
    s32 f394;
    f32 f398;
    f32 f39C;
    s32 f3A0;
    s32 f3A4;
    s32 f3A8;
    s32 f3AC;
    s32 f3B0;
    s32 f3B4;
};

extern "C" {
void __ct__9TObjEnemyFP7TObject(void *, void *, void *);
void TObjNpcBase__sub_80149368(void* p);
extern s32 __vt__11TObjNpcBase[];
extern s32 TObjNpcBase__name;
extern const f32 lbl_805DB1B8;
extern const f32 lbl_805DB1BC;
extern const f32 lbl_805DB1E0;
void *TObjNpcBase__ct(void *arg0, void *arg1, void *arg2);
void *__dt__11TObjNpcBaseFv(void *arg0, s16 arg1);
s32 play_sound_effect(s32, s32, s32, s32);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);

void *__dt__11TObjNpcBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjNpcBase;
        free_collision_body_parts(arg0);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define self ((Npc_801491B4 *)arg0)
void *TObjNpcBase__ct(void *arg0, void *arg1, void *arg2) {
    __ct__9TObjEnemyFP7TObject(arg0, arg1, arg2);
    self->vt = __vt__11TObjNpcBase;
    self->f0 = TObjNpcBase__name;
    self->f388 = 0;
    self->f390 = 1;
    switch (get_current_floor_area()) {
    case AREA_LOBBY:
        self->f394 = 1;
        break;
    default:
        self->f394 = 0;
        break;
    }
    self->f326 = 0;
    self->f30 = 0x44000000;
    self->f38C = 0;
    if (lbl_805DB1B8 <= self->f358) {
        self->f38C = 1;
        self->f3A0 = self->f358 - lbl_805DB1B8;
    } else {
        self->f3A0 = self->f358;
    }
    if (lbl_805DB1B8 <= self->f35C) {
        self->f38C = 1;
        self->f3A4 = self->f35C - lbl_805DB1B8;
    } else {
        self->f3A4 = self->f35C;
    }
    self->f3A8 = self->f364;
    self->f3AC = self->f360;
    self->f398 = lbl_805DB1BC;
    self->f39C = lbl_805DB1E0;
    TObjNpcBase__sub_80149368(self->sub98);
    self->f3B0 = 0;
    self->f3B4 = 0;
    return arg0;
}
#undef self

void TObjNpcBase::vfunc_88() {  }
void TObjNpcBase::play_voice() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x40003804, arg0 + 0x38, 0, 0);
}
void TObjNpcBase::sub_80149358(s32 v) { this->m_3ac = v; }
void TObjNpcBase::sub_80149360(s32 v) { this->m_3a8 = v; }
void TObjNpcBase__sub_80149368(void* p) { *(s32*)((char*)p + 0x0) = 2; }

}
