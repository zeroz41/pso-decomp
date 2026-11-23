#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/unk/text_800DC420.h"
#include "pso/unk/TUnk_80494E10.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"

#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"


struct D_800DC420 { u8 pad[0x18]; s32 arr[1]; };

struct E_800DC448 { s32 f0; s32 f4; s32 f8; s32 fc; };

struct D_800DC448 { u8 pad[0x42c]; E_800DC448 *entries; };

struct O_800DC448 { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

typedef struct Parm_800DC4B4 {
    s32 a;
    f32 b;
} Parm_800DC4B4;

struct Base_800DC4B4 {
    char pad[0x18];
};

struct Obj_800DC4B4 : Base_800DC4B4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(void *, Parm_800DC4B4, s32, s32, s32);
    u8 pad1C[0x30 - 0x1C];
    u32 flags;
    u8 pad34[0x2FC - 0x34];
    f32 pos[3];
};

typedef struct Src_800DC4B4 {
    u8 pad0[0xAC];
    f32 pos[3];
} Src_800DC4B4;

struct Ang_800DC83C { s32 x, y, z; };

extern "C" {
extern saddr lbl_805D5254;
extern D_800DC448 *nano_drago_entry_params_resource;
s32 is_split_screen();
extern const f32 lbl_805D525C;
extern s32 lbl_805D526C;
extern s32 local_client_id;
void hit_object_in_radius__10TObjPlayerFPvPvPv(Src_800DC4B4 *arg0, Obj_800DC4B4 *obj, void *attacker);
u32 csnVector(void *, void *, int);
s32 vec3_add_to(void *, void *);
f32 atan2_float(f32, f32);
s32 __ct__14TObjCollidableFP7TObject(void *, int);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
extern s32 __vt__13TUnk_80494E10[];
extern s32 tl_06;
TUnk_80494E10 *construct_beam_effect__10TObjPlayerFPvPvPviPv(TUnk_80494E10 *beam, Vec *pos, Vec *target, s32 trail, void *owner);

s32 TObjPlayer__sub_800DC420(void *self, s32 i) {
    return (*(D_800DC420 * *)&lbl_805D5254)->arr[i];
}

f32 TObjPlayer__sub_800DC434(s32 arg0, s32 arg1) {
    return *(f32 *)((s8 *)(lbl_805D5254 + (arg1 * 4)) + 0);
}

void TObjPlayer__sub_800DC444(void) {  }

void TObjEneNanoDrago::load_entry_params_nanodrago(s32 i) {
    O_800DC448 *self = (O_800DC448 *)this;
    self->f34 = nano_drago_entry_params_resource->entries[i].f8;
    self->f24 = nano_drago_entry_params_resource->entries[i].fc;
}

s32 TObjPlayer__sub_800DC478(u8 *arg0, s32 arg1, f32 farg0) {
    f32 temp_f2;
    if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) == arg1) {
        temp_f2 = *(f32 *)((s8 *)arg0 + 0xC0);
        if ((temp_f2 >= farg0) && (temp_f2 < (farg0 + *(f32 *)((s8 *)arg0 + 0xC8)))) {
            return 1;
        }
    }
    return 0;
}

void hit_object_in_radius__10TObjPlayerFPvPvPv(Src_800DC4B4 *arg0, Obj_800DC4B4 *obj, void *attacker) {
    if (obj == NULL) {
        return;
    }
    if ((void *)obj == attacker) {
        return;
    }
    if (obj->flags & 0x4000A00) {
        return;
    }
    if (xyz_distance_squared((Vec *)arg0->pos, (Vec *)obj->pos) > lbl_805D525C * lbl_805D525C) {
        return;
    }
    Parm_800DC4B4 parm = {0, 0.0f};
    parm.b = lbl_805D526C;
    obj->v21(attacker, parm, 0, -1, -1);
    if (attacker != NULL) {
        if (obj->flags & 0x800) {
            ((TObjEneNanoDrago *)attacker)->request_growth();
        }
        if (is_split_screen() == 0 && local_client_id == ((TObjBase *)(obj))->get_entity_id()) {
            ((TObjEneNanoDrago *)attacker)->trigger_hit_camera_shake((uaddr)obj);
        }
    }
    spawn_particle_effect((const Vec *)obj->pos, 0xFB);
    spawn_particle_effect((const Vec *)obj->pos, 0xFC);
}

s32 TUnk_80494E10::snap_to_ground(Vec *origin) {
    CsnHit *hit = csnVecterUnder(origin, 0x16EF);
    if (hit == NULL) {
        return 0;
    }
    VecCopy(origin, &hit->contact->point);
    return 1;
}

void TUnk_80494E10::run_task() {
    void *att;
    s32 i;
    void *pl;
    Vec old = this->pos;
    vec3_add_to(&this->pos, &this->vel);
    if (this->link0 != NULL) {
        this->link0->set_position(&this->pos);
    }
    this->timer += lbl_805D525C;
    if (this->trail != 0) {
        VecCopy(&this->prev, &this->pos);
        this->cnt++;
        if (this->cnt > 4) {
            this->cnt = 0;
            this->snap_to_ground(&this->prev);
        }
        if (this->link1 != NULL) {
            this->link1->set_position(&this->prev);
        }
    }
    if (this->timer >= 500.0f) {
        this->queue_destruction();
        return;
    }
    if (csnVector(&old, &this->pos, -1) != 0) {
        this->queue_destruction();
        return;
    }
    att = find_entity_by_id(this->owner);
    if (att != NULL) {
        for (i = 0; i < registered_player_count + registered_enemy_count; i++) {
            pl = (void *)TObjPlayer::get_player_data(i);
            if (pl != NULL && TObjPlayer::is_valid_and_active((uaddr)pl) != 0) {
                TObjPlayer::hit_object_in_radius((Src_800DC4B4 *)this, (Obj_800DC4B4 *)pl, att);
            }
        }
    }
}

}
TUnk_80494E10::~TUnk_80494E10() {
    if (this->link0 != NULL) {
        this->link0->queue_destruction();
        this->link0 = NULL;
    }
    if (this->link1 != NULL) {
        this->link1->queue_destruction();
        this->link1 = NULL;
    }
}

TUnk_80494E10 *construct_beam_effect__10TObjPlayerFPvPvPviPv(TUnk_80494E10 *beam, Vec *pos, Vec *target, s32 trail, void *owner) {
    Ang_800DC83C ang;
    f32 s;
    __ct__14TObjCollidableFP7TObject(beam, tl_06);
    *(s32 **)((s8 *)beam + 0x18) = __vt__13TUnk_80494E10;
    beam->trail = trail;
    VecCopy(&beam->pos, pos);
    beam->timer = 0.0f;
    VecCopy(&beam->vel, target);
    subtract_vector(&beam->vel, pos);
    s = lbl_805D525C / vector_length(&beam->vel);
    beam->vel.x *= s;
    beam->vel.y *= s;
    beam->vel.z *= s;
    beam->owner = ((TObjBase *)(owner))->get_entity_id();
    ang.x = 0;
    ang.y = (s32)(10430.38043493439 * atan2_float(target->x - pos->x, target->z - pos->z)) + 0x4000;
    ang.z = 0x4000 - (s32)(10430.38043493439 * atan2_float(target->y - pos->y, vec_xz_distance(target, pos)));
    beam->link0 = (TParticleCtrl *)spawn_particle_effect_with_rotation(pos, &ang, 0xF5, 2);
    if (beam->trail != 0) {
        VecCopy(&beam->prev, &beam->pos);
        beam->snap_to_ground(&beam->prev);
        beam->link1 = spawn_continuous_particle_effect_with_flags(&beam->prev, 0xF9, 2);
        beam->cnt = 0;
    } else {
        beam->link1 = NULL;
    }
    return beam;
}
