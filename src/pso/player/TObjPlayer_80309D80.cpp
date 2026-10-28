#include "types.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/TPlayerFootStamp.h"

struct VBase_PTR18_8030A400 { char pad[0x18]; };

struct VObj_PTR18_8030A400 : VBase_PTR18_8030A400 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual s32 m63(s32, s32);
};

struct Stack_8030A1E4
{
  s32 sp8;
  s32 spC;
  s32 sp10;
};

struct V_80309E9C { f32 x, y, z; };

struct Fol_80309E9C { u16 a; u16 b; u8 pad[0x8]; V_80309E9C v[3]; };

extern "C" {
int spawn_particle_effect(void*, void*);
void *__nw__7TObjectFUl(int);
void *TPlyPtclObjectRightHand__ct(void *, void *);
void *TPlyPtclObjectLeftHand__ct(void *arg0, u8 *_w1);
void *get_player_by_client_id(s32 i);
u16 get_lifetime__22TPlyFollowParticleCtrlFv();
s32 get_position_ptr__10TObjPlayerFv(s32);
s32 TPlyPtclObjectRightHand__vt7(s32 arg0);
s32 set_owner_id__13TParticleCtrlFUs(s32, s32);
u32 find_entity_by_id(s32);
s32 create_attached_oneshot_emitter(unsigned long long arg1, s32 arg2);
s32 spawn_particle_effect_with_flags(s32, s32, s32);
s32 emit_player_particle(void* p, void* a1, void* a2);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
}
void *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, s32 flags);
void emit_player_sprite_particle(s32 arg0, s32 arg1, s32 arg2);
void emit_sand_step_particles(s32 arg0, s32 arg1);
void emit_water_step_particles(s32 arg0, s32 arg1);
void emit_idle_water_splash(s32 arg0, s32 arg1);
extern f32 lbl_805DF134;
s32 emit_player_model_particle(s32 owner, s32 position, s32 entry, s32 model);
extern const f32 lbl_805DF130;
extern "C" {
Fol_80309E9C *TObjPlayer__sub_80309E9C(Fol_80309E9C *o);
struct VOff_80309DD0_arg0_80309dd0_80309D80 { char pad_0[0x4]; char f_4[1]; };

s32 TObjPlayer__sub_80309E4C(s32 arg0, s16 arg1);
int TPlyFollowParticleCtrl__sub_8030A694(void*);
s32 __dt__22TPlyFollowParticleCtrlFis(s32 arg0, s16 arg1);
s32 get_entity_id(void *);
s32 set_type__22TPlyFollowParticleCtrlFs(void *, void *);

void TObjPlayer::enable_foot_stamp(s32 arg1, s32 arg2) {
    TPlayerFootStamp::create((void *)arg2, (void *)1);
}

void TObjPlayer::clear_foot_stamp(s32 arg0, s32 arg1) {
    TPlayerFootStamp::create((void *)arg1, (void *)0);
}

void TObjPlayer::update_child(void *ply_ptcl_object_right_hand) {
    struct VOff_80309DD0_arg0_80309dd0_80309D80 *self = (struct VOff_80309DD0_arg0_80309dd0_80309D80 *)this;
    ((TObjPlayer *)(self->f_4))->create_left_hand_ptcl(ply_ptcl_object_right_hand);
    ((TObjPlayer *)(self->f_4))->create_right_hand_ptcl(ply_ptcl_object_right_hand);
}

void TObjPlayer::update_follow_particle(s32 arg1) {
    s32 arg0 = (s32)this;
    set_type__22TPlyFollowParticleCtrlFs((void *)arg0, (void *) (get_entity_id((void *)arg1)));
}

s32 TObjPlayer__sub_80309E4C(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        TObjPlayer::dt_follow_particle_ctrl(arg0 + 4, (s16)(-1));
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

Fol_80309E9C *TObjPlayer__sub_80309E9C(Fol_80309E9C *o) {
    s32 i;
    V_80309E9C *p;
    ((TObjPlayer *)((u8 *)o + 4))->init_follow_particle_ctrl();
    o->b = 0xFFFF;
    o->a = 0xFFFF;
    for (i = 0; i < 3; i++) {
        p = &o->v[i];
        p->z = lbl_805DF130;
        p->y = lbl_805DF130;
        p->x = lbl_805DF130;
    }
    return o;
}

s32 TObjPlayer::check_hit_by_id_431(void* p, int a1) { return TObjPlayer::check_hit_by_id((s32)p, (s32)a1, 431); }
}

void emit_idle_water_splash(s32 owner, s32 position) {
    emit_player_sprite_particle(owner, position, 0xA2);
    emit_player_model_particle(owner, position, 0xA6, 2);
}

void emit_sand_step_particles(s32 owner, s32 position) {
    emit_player_model_particle(owner, position, 0x23D, 2);
    emit_player_model_particle(owner, position, 0x23F, 0);
    emit_player_particle((void*)owner, (void*)position, (void*)(0x23E));
}

void emit_water_step_particles(s32 owner, s32 position) {
    emit_player_model_particle(owner, position, 0x237, 2);
    emit_player_model_particle(owner, position, 0x239, 0);
    emit_player_particle((void*)owner, (void*)position, (void*)(0x238));
}

void TObjPlayer::create_right_hand_ptcl(void *ply_ptcl_object_right_hand) {
    void *o;
    o = __nw__7TObjectFUl(0xB0);
    if (o != NULL) {
        o = TPlyPtclObjectRightHand__ct(o, ply_ptcl_object_right_hand);
    }
    *(void **)((s8 *)this + 0x4) = o;
}

void TObjPlayer::create_left_hand_ptcl(void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0xB0);
    if (o != NULL) {
        o = TPlyPtclObjectLeftHand__ct(o, (u8 *)arg1);
    }
    *(void * *)&this->m_name = o;
}

s32 TObjPlayer::dt_follow_particle_ctrl(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __dt__22TPlyFollowParticleCtrlFis(arg0, 0);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}
void*TObjPlayer::init_follow_particle_ctrl() { TPlyFollowParticleCtrl__sub_8030A694(this); *(int*)(this) = 0; *(int*)((char*)this + 0x4) = 0; return this; }

typedef struct Stack_8030A1E4 Stack_8030A1E4;

void emit_player_sprite_particle(s32 arg0, s32 arg1, s32 arg2) {
    spawn_particle_effect_with_flags(arg1, arg2, 0x2000);
}

s32 emit_player_model_particle(s32 owner, s32 position, s32 entry, s32 model) {
  s32 emitter = emit_player_particle((void*)owner, (void*)position, (void*)entry);
  if (emitter)
  {
    attach_particle_model((u8 *)emitter, TParticleCtrl::get_particle_model(model), TParticleCtrl::get_instance(), 0, 1, lbl_805DF134);
  }
  return emitter;
}

s32 create_attached_oneshot_emitter(unsigned long long arg1, s32 arg2) {
  Stack_8030A1E4 stack;
  s32 oneshot_particle_emitter;
  u8 *entity;
  entity = (u8 *) ((u8 *)find_entity_by_id(arg1));
  if (entity == 0)
  {
    return 0;
  }
  stack.spC = 0;
  stack.sp8 = 0;
  stack.sp10 = -0x8000;
  oneshot_particle_emitter = (s32)create_oneshot_particle_emitter((entity + 0x74), (&stack.sp8), arg2, 0x50);
  if (oneshot_particle_emitter != 0)
  {
    set_owner_id__13TParticleCtrlFUs((s32)((void *) oneshot_particle_emitter), arg1);
  }
  return oneshot_particle_emitter;
}

s32 TObjPlayer::check_hit_by_id(s32 arg0, s32 arg1, s32 arg2) {
    s32 particle_effect_with_flags;
    u32 entity;

    entity = find_entity_by_id(arg1);
    if (entity == 0U) {
        return 0;
    }
    particle_effect_with_flags = spawn_particle_effect_with_flags(entity + 0x74, arg2, 0x50);
    if (particle_effect_with_flags != 0) {
        set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, arg1);
    }
    return particle_effect_with_flags;
}

s32 emit_player_particle(void* p, void* a1, void* a2) { return spawn_particle_effect(a1, a2); }
s32 TPlyPtclObjectRightHand__vt7(s32 arg0) {
    void *player;
    player = get_player_by_client_id((u16) get_lifetime__22TPlyFollowParticleCtrlFv());
    if (player == NULL) {
        return 0;
    }
    ((VObj_PTR18_8030A400 *) player)->m63(0x30, get_position_ptr__10TObjPlayerFv(arg0));
    return get_position_ptr__10TObjPlayerFv(arg0);
}
