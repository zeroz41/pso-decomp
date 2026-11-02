// Built with -inline off,deferred (GAME_EXCEPTIONS in configure.py), which emits functions
// in reverse source order: bodies here run from the highest address down.

#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/memory.h"
#include "pso/TObject.h"
#include "pso/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80309D80.h"
#include "pso/TParticleCtrl.h"
#include "pso/TPlayerFootStamp.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/misc/TPlyFollowParticleCtrl.h"
#include "pso/misc/TPlyPtclObjectLeftHand.h"
#include "pso/misc/TPlyPtclObjectRightHand.h"
const char *TPlyFollowParticleCtrl__class_name = "TPlyFollowParticleCtrl";
const char *TPlyPtclObjectLeftHand__class_name = "TPlyPtclObjectLeftHand";
const char *TPlyPtclObjectRightHand__class_name = "TPlyPtclObjectRightHand";
// The follow controller's one collision body: a sphere of radius 20.
CollisionBody lbl_804E7578 = {
    { 0.0f, 0.0f, 0.0f }, 20.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f,
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
s32 set_owner_id__13TParticleCtrlFUs(s32, s32);
u32 find_entity_by_id(s32);
s32 spawn_particle_effect_with_flags(s32, s32, s32);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
}
void *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, s32 flags);
extern "C" {
Fol_80309E9C *TObjPlayer__sub_80309E9C(Fol_80309E9C *o);
struct VOff_80309DD0_arg0_80309dd0_80309D80 { char pad_0[0x4]; char f_4[1]; };
}
typedef struct Stack_8030A1E4 Stack_8030A1E4;

void *TPlyFollowParticleCtrl::get_center() { return 0; }

u16 TPlyFollowParticleCtrl::get_lifetime() { return this->m_ac; }

void TPlyFollowParticleCtrl__sub_8030A694(void) {  }

s32 __dt__22TPlyFollowParticleCtrlFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void TPlyFollowParticleCtrl::set_type(u16 type) { *(u16 *)&this->m_name = type; }

TPlyFollowParticleCtrl::TPlyFollowParticleCtrl(TObjBase *owner) : TObjCollidable(tl_06) {
    m_name = TPlyFollowParticleCtrl__class_name;
    set_collision_body(&lbl_804E7578);
    register_object_by_id();
    bodies->flags &= ~1;
    m_ac = get_entity_id(owner);
    m_ae = 0xFFFF;
    set_position_from(&owner->center);
}

TPlyFollowParticleCtrl::~TPlyFollowParticleCtrl() {
    unregister_object_by_id();
    clear_collision_bodies();
}

// Ends itself once its player is gone.
void TPlyFollowParticleCtrl::run_task() {
    if (get_player_by_client_id(get_lifetime()) == NULL) {
        queue_destruction();
    }
}

TPlyPtclObjectLeftHand::TPlyPtclObjectLeftHand(TObjBase *owner) : TPlyFollowParticleCtrl(owner) {
    m_name = TPlyPtclObjectLeftHand__class_name;
}

TPlyPtclObjectLeftHand::~TPlyPtclObjectLeftHand() {}

// Follows the left hand (node 0x23).
void *TPlyPtclObjectLeftHand::get_center() {
    TObjPlayer *player = get_player_by_client_id(get_lifetime());
    if (player == NULL) {
        return NULL;
    }
    player->get_anim_node_position(0x23, (Vec *)((TObjPlayer *)this)->get_position_ptr());
    return ((TObjPlayer *)this)->get_position_ptr();
}

TPlyPtclObjectRightHand::TPlyPtclObjectRightHand(TObjBase *owner) : TPlyFollowParticleCtrl(owner) {
    m_name = TPlyPtclObjectRightHand__class_name;
}

TPlyPtclObjectRightHand::~TPlyPtclObjectRightHand() {}

// Follows the right hand (node 0x30) of the player it belongs to.
void *TPlyPtclObjectRightHand::get_center() {
    TObjPlayer *player = get_player_by_client_id(get_lifetime());
    if (player == NULL) {
        return NULL;
    }
    player->get_anim_node_position(0x30, (Vec *)((TObjPlayer *)this)->get_position_ptr());
    return ((TObjPlayer *)this)->get_position_ptr();
}

extern "C" s32 emit_player_particle(void* p, void* a1, void* a2) { return spawn_particle_effect(a1, a2); }

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

s32 emit_player_model_particle(s32 owner, s32 position, s32 entry, s32 model) {
  s32 emitter = emit_player_particle((void*)owner, (void*)position, (void*)entry);
  if (emitter)
  {
    attach_particle_model((u8 *)emitter, TParticleCtrl::get_particle_model(model), TParticleCtrl::get_instance(), 0, 1, 1.0f);
  }
  return emitter;
}

void emit_player_sprite_particle(s32 arg0, s32 arg1, s32 arg2) {
    spawn_particle_effect_with_flags(arg1, arg2, 0x2000);
}

void*TObjPlayer::init_follow_particle_ctrl() { TPlyFollowParticleCtrl__sub_8030A694(); *(int*)(this) = 0; *(int*)((char*)this + 0x4) = 0; return this; }

s32 TObjPlayer::dt_follow_particle_ctrl(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __dt__22TPlyFollowParticleCtrlFis(arg0, 0);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

void TObjPlayer::create_left_hand_ptcl(void *arg1) {
    *(void * *)&this->m_name = new TPlyPtclObjectLeftHand((TObjBase *)arg1);
}

void TObjPlayer::create_right_hand_ptcl(void *ply_ptcl_object_right_hand) {
    *(void **)((s8 *)this + 0x4) = new TPlyPtclObjectRightHand((TObjBase *)ply_ptcl_object_right_hand);
}

void emit_water_step_particles(s32 owner, s32 position) {
    emit_player_model_particle(owner, position, 0x237, 2);
    emit_player_model_particle(owner, position, 0x239, 0);
    emit_player_particle((void*)owner, (void*)position, (void*)(0x238));
}

void emit_sand_step_particles(s32 owner, s32 position) {
    emit_player_model_particle(owner, position, 0x23D, 2);
    emit_player_model_particle(owner, position, 0x23F, 0);
    emit_player_particle((void*)owner, (void*)position, (void*)(0x23E));
}

void emit_idle_water_splash(s32 owner, s32 position) {
    emit_player_sprite_particle(owner, position, 0xA2);
    emit_player_model_particle(owner, position, 0xA6, 2);
}

extern "C" {

s32 TObjPlayer::check_hit_by_id_431(void* p, int a1) { return TObjPlayer::check_hit_by_id((s32)p, (s32)a1, 431); }

Fol_80309E9C *TObjPlayer__sub_80309E9C(Fol_80309E9C *o) {
    s32 i;
    V_80309E9C *p;
    ((TObjPlayer *)((u8 *)o + 4))->init_follow_particle_ctrl();
    o->b = 0xFFFF;
    o->a = 0xFFFF;
    for (i = 0; i < 3; i++) {
        p = &o->v[i];
        p->z = 0.0f;
        p->y = 0.0f;
        p->x = 0.0f;
    }
    return o;
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

void TObjPlayer::update_follow_particle(s32 arg1) {
    ((TPlyFollowParticleCtrl *)this)->set_type(get_entity_id((TObjBase *)arg1));
}

void TObjPlayer::update_child(void *ply_ptcl_object_right_hand) {
    struct VOff_80309DD0_arg0_80309dd0_80309D80 *self = (struct VOff_80309DD0_arg0_80309dd0_80309D80 *)this;
    ((TObjPlayer *)(self->f_4))->create_left_hand_ptcl(ply_ptcl_object_right_hand);
    ((TObjPlayer *)(self->f_4))->create_right_hand_ptcl(ply_ptcl_object_right_hand);
}

void TObjPlayer::clear_foot_stamp(s32 arg0, s32 arg1) {
    TPlayerFootStamp::create((void *)arg1, (void *)0);
}

void TObjPlayer::enable_foot_stamp(s32 arg1, s32 arg2) {
    TPlayerFootStamp::create((void *)arg2, (void *)1);
}

}
