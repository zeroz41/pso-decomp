#include "types.h"
#include "pso/object/TObjParticle.h"
#include "pso/system/NinjaUtil.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjParticle.h"
#include "pso/TObject.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct P_8019527C { u8 pad[0x90]; u32 f90; };

struct Vec_80195400 { f32 x, y, z; };

struct Src_80195400 {
    u8 pad0[0xC];
    Vec_80195400 pos;
    Vec_80195400 ang;
    f32 params[3];
    s32 ints[3];
};

struct Part_80195400 {
    s32 f0;
    u8 pad4[0x14];
    s32 *vt;
    u8 pad1c[0x38 - 0x1C];
    Vec_80195400 pos;
    u8 pad44[0x5C - 0x44];
    Vec_80195400 ang;
    f32 params[3];
    u8 pad74[0x84 - 0x74];
    s32 ints[3];
    s32 emitter;
    s32 sel;
};

extern "C" {
s32 is_split_screen(void);
u8 *__nw__7TObjectFUl(s32);
extern s32 tl_05;
s32 spawn_particle_effect_with_rotation(void *, void *, s32, u16);
s32 spawn_continuous_particle_with_direction(void *, void *, s32);
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__12TObjParticle[];
extern s32 obj_particle_class_name;
extern const f32 lbl_805DBEEC;
Part_80195400 *TObjParticle__ct(Part_80195400 *arg0, s32 arg1, Src_80195400 *arg2);
void __dl__7TObjectFPv(void *);

extern s32 camera_ctrl_instance;
extern const f32 lbl_805DBEE0;
extern const f32 lbl_805DBEE4;
extern const f32 lbl_805DBEE8;

void TObjParticle::render() {
    P_8019527C *arg0 = (P_8019527C *)this;
    if (((TObject *)arg0)->all_parents_unqueued_for_destruction() != 0) {
        if (this->m_90 == 0) {
            return;
        }
    }
}

void TObjParticle::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 var_f31;

    if (((get_current_area() == 0xE) || ((s32) this->set_params[0] == 1)) && ((s32) this->set_params[2] != 1)) {
        var_f31 = lbl_805DBEE0;
    } else {
        var_f31 = lbl_805DBEE4;
    }
    if (((s32) this->set_params[2] == 1) && ((s32) this->set_params[0] == 1)) {
        var_f31 = lbl_805DBEE8;
    }
    if (xyz_distance_squared((Vec *)&this->position, (Vec *)(camera_ctrl_instance + 0x178)) > var_f31) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if ((u32) this->m_90 != 0U) {
        ((TNowLoading *)(this->m_90))->copy_pos((u8 *)&this->position);
        ((TBoss4Type2 *)(this->m_90))->copy_vec3((u8 *)&this->rotation_x);
    }
}

}
TObjParticle::~TObjParticle() {
    if (*(void **)((s8 *)this + 0x90) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x90))); this->m_90 = 0; }
    ((TObjBase *)this)->mask_object_set_row_flags(-3);
}
extern "C" {

Part_80195400 *TObjParticle__ct(Part_80195400 *arg0, s32 parent, Src_80195400 *arg2) {
    u32 i;
    s32 entry;
    u16 flags;
    u16 base;
    u16 other;
    __ct__8TObjBaseFP7TObject(arg0, (void *) parent);
    arg0->vt = __vt__12TObjParticle;
    other = 0;
    arg0->f0 = obj_particle_class_name;
    VecCopy((Vec *)&arg0->pos, (const Vec *)&arg2->pos);
    ((TObjPlayer *)(&arg0->ang))->copy_xyz(&arg2->ang);
    VecCopy((Vec *)arg0->params, (const Vec *)arg2->params);
    for (i = 0; i < 3; i++) {
        arg0->ints[i] = arg2->ints[i];
    }
    arg0->sel = (s32) arg2->params[0];
    arg0->emitter = 0;
    entry = (s32) arg0->params[0];
    if (entry < 0) {
        entry = 0;
    }
    if (arg0->params[2] < lbl_805DBEEC) {
        base = 2;
        if (arg0->ints[0] == 1) {
            base = 0x42;
        }
        flags = base;
        if (arg0->ints[1] == 1) {
            flags = base | 0x2000;
        }
        arg0->emitter = spawn_particle_effect_with_rotation(&arg0->pos, &arg0->ang, entry, flags);
    } else if ((s32) arg0->params[2] == 2) {
        flags = 8;
        if (arg0->ints[0] == 1) {
            flags = 0x48;
        }
        if (arg0->ints[1] == 1) {
            flags |= 0x2000;
        }
        arg0->emitter = spawn_particle_effect_with_rotation(&arg0->pos, &arg0->ang, entry, flags);
    } else if ((s32) arg0->params[2] == 3) {
        flags = 4;
        if (arg0->ints[0] == 1) {
            flags = 0x44;
        }
        if (arg0->ints[1] == 1) {
            flags |= 0x2000;
        }
        arg0->emitter = spawn_particle_effect_with_rotation(&arg0->pos, &arg0->ang, entry, flags);
    } else {
        if (arg0->ints[0] == 1) {
            other = 0x40;
        }
        if (arg0->ints[1] == 1) {
            other |= 0x2000;
        }
        if (arg0->ints[0] == 1 || arg0->ints[1] == 1) {
            arg0->emitter = spawn_particle_effect_with_rotation(&arg0->pos, &arg0->ang, entry, (u16)other);
        } else {
            arg0->emitter = spawn_continuous_particle_with_direction(&arg0->pos, &arg0->ang, entry);
        }
    }
    disallow_rendering__7TObjectFv((TObject *)arg0);
    return arg0;
}

u8 *TObjParticle__create(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x98));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TObjParticle__ct((Part_80195400 *)(temp_r3), tl_05, (Src_80195400 *)(arg0)));
    }
    return var_r0;
}

}
