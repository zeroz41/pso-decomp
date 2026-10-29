#include <dolphin/mtx.h>
#include "pso/map/CsnQuery.h"
#include "pso/boss/TBoss5GryphonLightningWing.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/TBoss5GryphonLightning.h"
#include "pso/TBoss5GryphonLightningWing.h"

#include "types.h"

struct Stack_80351DA8 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/boss/TBoss8Dragon.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D4368 = "TBoss5GryphonLightningWing";
}


#pragma opt_lifetimes off
struct Stack_80351A80 {
    s32 sp8;
    u8 trailing_storage[0x8];
};

struct Vec_80351C18 { f32 x, y, z; };

struct Pt_80351C18 { Vec_80351C18 v; f32 w; };

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
s32 __nw__7TObjectFUl(int);
extern const f32 lbl_805D8D48;
s32 play_sound_effect(int, void *, int, int);
s32 TBoss5GryphonLightning__ct(f32);
extern u8 __vt__26TBoss5GryphonLightningWing[];
extern const char *lbl_805D4368;
s32 TBoss8Dragon__sub_80063FB8(s32, s32 *, f32);


void TBoss5GryphonLightningWing::apply_lightning_effect() {
    s32 sp8;
    s32 instance_count;
    s32 arg0 = (s32)this;

    instance_count = TBoss8Dragon::get_instance_count();
    if (instance_count != 0) {
        ((TBoss5GryphonLightningWing *)arg0)->get_wing_position((s32)&sp8);
        TBoss8Dragon__sub_80063FB8(instance_count, &sp8, 10.0f);
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
        boss5_gryphon_lightning_wing->get_wing_position((s32)&stack.sp8);
        play_sound_effect(0x40032516, &stack.sp8, 0, 0);
    }
    ((TBoss5GryphonLightning *)boss5_gryphon_lightning_wing)->spawn_gryphon_lightning();
    if ((s32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x94) >= (s32) *(s32 *)((s8 *)boss5_gryphon_lightning_wing + 0x9C)) {
        queue_destruction__7TObjectFv((boss5_gryphon_lightning_wing));
    }
}
#pragma pop

TBoss5GryphonLightningWing::~TBoss5GryphonLightningWing() {}
s32 __ct__26TBoss5GryphonLightningWingFv(int arg0, void *arg1, void *a, void *mid, void *b, void *arg5, void *arg6) {
    s32 i;
    TBoss5GryphonLightning__ct(20.0f);
    ((Wing_80351C18 *)arg0)->vt = __vt__26TBoss5GryphonLightningWing;
    ((Wing_80351C18 *)arg0)->x0 = ((s32)lbl_805D4368);
    ((Wing_80351C18 *)arg0)->n = 3;
    ((Wing_80351C18 *)arg0)->x98 = (s32)arg5;
    ((Wing_80351C18 *)arg0)->x9C = (s32)arg5 + (s32)arg6;
    VecCopy((Vec *)(&((Wing_80351C18 *)arg0)->pts[0]), (const Vec *)a);
    VecCopy((Vec *)(&((Wing_80351C18 *)arg0)->pts[((Wing_80351C18 *)arg0)->n - 1]), (const Vec *)b);
    for (i = 1; i < ((Wing_80351C18 *)arg0)->n - 1; i++) {
        ((Wing_80351C18 *)arg0)->pts[i].v.x = ((Vec_80351C18 *)mid)->x;
        ((Wing_80351C18 *)arg0)->pts[i].v.y = ((Vec_80351C18 *)mid)->y;
        ((Wing_80351C18 *)arg0)->pts[i].v.z = ((Vec_80351C18 *)mid)->z;
    }
    return arg0;
}

s32 spawn_lightning_wing__12TBoss8DragonFiiiiii(s32 arg0, s32 arg1, s32 mid, s32 arg3, s32 arg4, s32 arg5) {
    Vec position;
    f32 ground_height;
    s32 allocation;
    s32 effect;
    u8* collision;
    VecCopy(&position, (const Vec *)arg3);
    collision = (u8 *)csnVecterUnder((s32)((s32*)&position), 0x16EF);
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
    allocation = __nw__7TObjectFUl(0xA0);
    effect = allocation;
    if (effect != 0) {
        effect = __ct__26TBoss5GryphonLightningWingFv(allocation, (void *)((void*)arg0), (void *)((void*)arg1), (void *)((void*)mid), &position, (void *)((void*)arg4), (void *)((void*)arg5));
    }
    return effect;
}

void fn_80351DA8(s32 arg0, u8 *pos, u8 *out, s32 arg3, s32 arg4) {
    Stack_80351DA8 stack;
    stack.sp8 = *(f32 *)((s8 *)out + 0);
    stack.spC = *(f32 *)((s8 *)pos + 4);
    stack.sp10 = *(f32 *)((s8 *)out + 8);
    spawn_lightning_wing__12TBoss8DragonFiiiiii(arg0, (s32)((s32) pos), (s32)((s32) &stack.sp8), (s32)((s32) out), arg3, arg4);
}

}
