#define TOBJECT_OUT_OF_LINE_HELPERS
#include <dolphin/mtx.h>
#include "pso/map/CsnQuery.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"

#include "types.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"

#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

#pragma readonly_strings on


const char *TBoss5GryphonLightningWing__name = "TBoss5GryphonLightningWing";


#pragma opt_lifetimes off
struct Stack_80351A80 {
    s32 sp8;
    u8 trailing_storage[0x8];
};

struct Pt_80351C18 { Vec v; f32 w; };

struct Wing_80351C18 {
    s32 x0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1C[0x48 - 0x1C];
    Pt_80351C18 pts[4];
    u8 pad88[8];
    s32 n;
    s32 pad94;
    s32 x98;
    s32 x9C;
};

extern "C" {
extern const f32 lbl_805D8D48;
s32 TBoss5GryphonLightning__ct(f32);
extern u8 __vt__26TBoss5GryphonLightningWing[];
s32 apply_lightning_hit(s32, s32 *, f32);


void TBoss5GryphonLightningWing::apply_lightning_effect() {
    s32 sp8;
    s32 instance_count;
    saddr self = (saddr)this;

    instance_count = TBoss8Dragon::get_instance_count();
    if (instance_count != 0) {
        ((TBoss5GryphonLightningWing *)self)->get_wing_position((Vec *)&sp8);
        apply_lightning_hit(instance_count, &sp8, 10.0f);
    }
}

void TBoss5GryphonLightningWing::render() {  }

#pragma push
#pragma opt_common_subs off
void run_task__26TBoss5GryphonLightningWingFv(TBoss5GryphonLightningWing *boss5_gryphon_lightning_wing) {
    Stack_80351A80 stack;
    *(f32 *)((s8 *)boss5_gryphon_lightning_wing + 0x88) = (f32) ((f32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x94) / (f32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x9C));
    if (*(f32 *)((s8 *)boss5_gryphon_lightning_wing + 0x88) > 1.0f) {
        *(f32 *)((s8 *)boss5_gryphon_lightning_wing + 0x88) = 1.0f;
    }
    *(f32 *)((s8 *)boss5_gryphon_lightning_wing + 0x8C) = (f32) ((f32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x94) / (f32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x98));
    if (*(f32 *)((s8 *)boss5_gryphon_lightning_wing + 0x8C) > 1.0f) {
        *(f32 *)((s8 *)boss5_gryphon_lightning_wing + 0x8C) = 1.0f;
    }
    boss5_gryphon_lightning_wing->update_wing_segments();
    boss5_gryphon_lightning_wing->apply_lightning_effect();
    if ((s32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x94) == (s32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x98)) {
        boss5_gryphon_lightning_wing->get_wing_position((Vec *)&stack.sp8);
        play_sound_effect(0x40032516, &stack.sp8, 0, 0);
    }
    ((TBoss5GryphonLightning *)boss5_gryphon_lightning_wing)->spawn_gryphon_lightning();
    if ((s32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x94) >= (s32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x9C)) {
        boss5_gryphon_lightning_wing->queue_destruction();
    }
}
#pragma pop

TBoss5GryphonLightningWing::~TBoss5GryphonLightningWing() {}
s32 __ct__26TBoss5GryphonLightningWingFv(saddr allocation, void *arg1, void *a, void *mid, void *b, void *arg5, void *arg6) {
    s32 i;
    TBoss5GryphonLightning__ct(20.0f);
    ((Wing_80351C18 *)allocation)->vt = __vt__26TBoss5GryphonLightningWing;
    ((Wing_80351C18 *)allocation)->x0 = ((saddr)TBoss5GryphonLightningWing__name);
    ((Wing_80351C18 *)allocation)->n = 3;
    ((Wing_80351C18 *)allocation)->x98 = (saddr)arg5;
    ((Wing_80351C18 *)allocation)->x9C = (saddr)arg5 + (saddr)arg6;
    VecCopy((Vec *)(&((Wing_80351C18 *)allocation)->pts[0]), (const Vec *)a);
    VecCopy((Vec *)(&((Wing_80351C18 *)allocation)->pts[((Wing_80351C18 *)allocation)->n - 1]), (const Vec *)b);
    for (i = 1; i < ((Wing_80351C18 *)allocation)->n - 1; i++) {
        ((Wing_80351C18 *)allocation)->pts[i].v.x = ((Vec *)mid)->x;
        ((Wing_80351C18 *)allocation)->pts[i].v.y = ((Vec *)mid)->y;
        ((Wing_80351C18 *)allocation)->pts[i].v.z = ((Vec *)mid)->z;
    }
    return allocation;
}

s32 spawn_lightning_wing__12TBoss8DragonFiiiiii(saddr arg0, saddr pos, saddr mid, saddr arg3, saddr arg4, saddr arg5) {
    Vec position;
    f32 ground_height;
    saddr allocation;
    s32 effect;
    u8* collision;
    VecCopy(&position, (const Vec *)arg3);
    collision = (u8 *)csnVecterUnder((saddr)((s32*)&position), 0x16EF);
    if (collision == NULL) {
        position.y = lbl_805D8D48;
    } else {
        ground_height = *(f32*)((s8 *)(*(u8**)((s8 *)collision + 4)) + 4);
        if (ground_height > lbl_805D8D48) {
            position.y = lbl_805D8D48;
        } else {
            position.y = ground_height;
        }
    }
    allocation = (saddr)TObject::operator new(0xA0);
    effect = allocation;
    if (effect != 0) {
        effect = __ct__26TBoss5GryphonLightningWingFv(allocation, (void *)((void*)arg0), (void *)((void*)pos), (void *)((void*)mid), &position, (void *)((void*)arg4), (void *)((void*)arg5));
    }
    return effect;
}

void fn_80351DA8(s32 arg0, u8 *pos, u8 *out, s32 arg3, s32 arg4) {
    Vec stack;
    stack.x = *(f32 *)((s8 *)out + 0);
    stack.y = *(f32 *)((s8 *)pos + 4);
    stack.z = *(f32 *)((s8 *)out + 8);
    spawn_lightning_wing__12TBoss8DragonFiiiiii(arg0, (saddr)((saddr) pos), (saddr)((saddr) &stack.x), (saddr)((saddr) out), arg3, arg4);
}

}
