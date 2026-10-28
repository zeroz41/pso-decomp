#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TUnk_80494E48.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjGyaranzoMissile.h"

struct Vec_800DCD04 { f32 x, y, z; };
 extern const Vec_800DCD04 lbl_8043C920 = {0.0f, 0.0f, 0.0f};
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

struct Vec_800DC9EC { f32 x, y, z; };

struct Me_800DC9EC {
    u8 pad0[0xAC];
    Vec_800DC9EC pos;
    Vec_800DC9EC prev;
    Vec_800DC9EC vel;
    u8 padD0[0xEC - 0xD0];
    s32 timer;
    void *target;
    f32 speed;
    void *effect;
    s32 state;
    u16 owner;
    u16 attacker;
};

extern "C" { u8 *find_entity_by_id(s16);
Obj_800DC4B4 *find_active_entity_by_id(u16);
void queue_destruction__7TObjectFv(void *);
s32 play_sound_effect(int, void *, int, int);
s32 subtract_vector(void *, void *);
s32 vec3_add_to(void *, void *);
u32 csnVector(void *, void *, int);
void spawn_particle_effect(void *, int);
s32 is_split_screen();
extern const f32 lbl_805D5260;
extern const f32 lbl_805D5268;
extern s32 lbl_805D5270;
extern s32 local_client_id;
void TObjPlayer::update_homing_shot() {
    Vec_800DC9EC dir;
    void *att;
    Obj_800DC4B4 *obj;
    Me_800DC9EC *arg0 = (Me_800DC9EC *)this;
    att = ((void *(*)(u16))find_entity_by_id)(arg0->attacker);
    if (att == NULL) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    obj = find_active_entity_by_id(arg0->owner);
    switch (this->m_fc) {
    case 0:
        this->m_ec--;
        if (this->m_ec <= 0) {
            this->m_ec = 0;
            VecCopy((Vec *)&arg0->pos, (const Vec *)arg0->target);
            this->m_fc = 1;
            play_sound_effect(0x4003A328, &arg0->pos, 0, 0);
            return;
        }
        if (arg0->effect != NULL) {
            ((TParticleCtrl *)(arg0->effect))->enable();
        }
        return;
    case 1:
        this->m_ec++;
        if (this->m_ec >= 0x5A) {
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        if (obj != NULL) {
            VecCopy((Vec *)&dir, (const Vec *)obj->pos);
            subtract_vector(&dir, &arg0->pos);
            vec_set_length((Vec *)&dir, arg0->speed);
            arg0->speed += lbl_805D5268;
            vec3_add_to(&arg0->vel, &dir);
            vec_set_length((Vec *)&arg0->vel, lbl_805D5260);
        }
        VecCopy((Vec *)&arg0->prev, (const Vec *)&arg0->pos);
        vec3_add_to(&arg0->pos, &arg0->vel);
        if (arg0->effect != NULL) {
            ((TNowLoading *)(arg0->effect))->copy_pos(&arg0->pos);
        }
        if (csnVector(&arg0->prev, &arg0->pos, -1) != 0) {
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        if (obj == NULL) {
            return;
        }
        if (obj->flags & 0x4000A00) {
            return;
        }
        if (xyz_distance_squared((Vec *)&arg0->pos, (Vec *)obj->pos) <= lbl_805D5260 * lbl_805D5260) {
            Parm_800DC4B4 parm = {0, 0.0f};
            parm.b = lbl_805D5270;
            obj->v21(att, parm, 0, -1, -1);
            if (obj->flags & 0x800) {
                ((TObjPlayer *)att)->set_flag_20000();
            }
            spawn_particle_effect(obj->pos, 0xFB);
            spawn_particle_effect(obj->pos, 0xFC);
            if (is_split_screen() == 0 && local_client_id == arg0->owner) {
                ((TObjPlayer *)att)->trigger_hit_camera_shake((u32)obj);
            }
            queue_destruction__7TObjectFv(arg0);
        }
        break;
    }
}

}

struct Obj_800DCD04 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0xc4 - 0x1c];
    Vec_800DCD04 fc4;
    u8 padd0[0xe8 - 0xd0];
    f32 fe8;
    s32 fec;
    Vec_800DCD04 *pos;
    f32 ff4;
    s32 ff8;
    s32 ffc;
    s16 id;
    s16 f102;
};

extern "C" {
f32 atan2_float(f32, f32);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void __ct__14TObjCollidableFP7TObject(void *, void *);
void matrix_mult_vec(s32, Vec_800DCD04 *, Vec_800DCD04 *);
void rotate_matrix_y(s32, s32);
void rotate_matrix_x(s32, s32);
s32 push_matrix_from(void *src);
s32 pop_matrix(void);
extern s32 lbl_80494E48[];
extern u8 identity_matrix[];
extern f32 lbl_805D5264;
extern void *tl_04;
extern const f32 lbl_805DA480;
extern const f32 lbl_805DA484;
extern const f32 lbl_805DA488;
Obj_800DCD04 *TObjPlayer__sub_800DCD04(Obj_800DCD04 *self, Vec_800DCD04 *pos, s16 id, s32 *rot, s32 arg4, s16 arg5);
void __dl__7TObjectFPv(void *);

void *TUnk_80494E48::destroy_particle_obj(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_80494E48;
        if (this->m_f8 != NULL) { queue_destruction__7TObjectFv(this->m_f8); this->m_f8 = 0; }
        __dt__14TObjCollidableFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
Obj_800DCD04 *TObjPlayer__sub_800DCD04(Obj_800DCD04 *self, Vec_800DCD04 *pos, s16 id, s32 *rot, s32 arg4, s16 arg5) {
    Vec_800DCD04 *pp;
    __ct__14TObjCollidableFP7TObject(self, tl_04);
    self->vt = lbl_80494E48;
    self->id = id;
    self->f102 = arg5;
    self->pos = pos;
    self->fe8 = lbl_805DA480;
    push_matrix_from(identity_matrix);
    {
        Vec_800DCD04 v = lbl_8043C920;
        s32 ang[3];
        v.z = lbl_805D5260;
        rotate_matrix_y(0, rot[1]);
        rotate_matrix_x(0, rot[0]);
        matrix_mult_vec(0, &v, &self->fc4);
        pop_matrix();
        self->fec = arg4;
        pp = (Vec_800DCD04 *)(find_entity_by_id(id) + 0x2fc);
        ang[0] = 0;
        ang[1] = (s32)(10430.38043493439 * atan2_float(pp->x - pos->x, pp->z - pos->z)) + 0x4000;
        ang[2] = 0x4000 - (s32)(10430.38043493439 * atan2_float(pp->y - pos->y, vec_xz_distance((Vec *)pp, (Vec *)pos)));
        self->ff8 = (s32)spawn_particle_effect_with_rotation(pos, ang, 0xf4, 2);
    }
    self->ff4 = lbl_805D5264;
    if (xz_distance_squared((Vec *)pp, (Vec *)pos) < lbl_805DA484) {
        self->ff4 *= lbl_805DA488;
    }
    self->ffc = 0;
    return self;
}

}
