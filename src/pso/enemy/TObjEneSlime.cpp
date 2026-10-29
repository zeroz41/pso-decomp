#include "types.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/TObjEneSlimeOne_800EC394.h"
#include "pso/object/TObjFish.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneSlime.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define VA virtual void CAT(f,__LINE__)();
struct Base_800EBB18_800EB9F0 { char pad[0x18]; };
struct VObj_800EBB18_800EB9F0 : Base_800EBB18_800EB9F0 {
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
    virtual void m77(s32 *);
};

struct Slot_800EB910 { s32 state; void *obj; };

struct Obj_800EB910 { u8 pad[0x3b8]; Slot_800EB910 slots[4]; };

struct Slot_800EB984 { s32 state; void *obj; };

struct Obj_800EB984 { u8 pad[0x3b8]; Slot_800EB984 slots[4]; };

extern "C" {
void spawn_slime_in_slot(void *, s32, s32, s32);
extern const Slot_800EB984 lbl_8043D218;
s32 TObjFish__sub_8001EDB0(void *, int);
void *get_bml_model(void *, int);
s32 defer_render__7TObjectFv();
void debug_printf_at(s32 id, const char *fmt, ...);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *, void *);
s32 set_global_param__8TObjFishFl();
extern char lbl_8043D298[];
extern s32 slime_debug_label_table[];
extern s32 lbl_80496368[];
extern s32 slime_bml_resource;
extern u32 model_render_flags;
s32 has_no_active_slot(void *);
void queue_destruction__7TObjectFv(void *arg0);

void TObjEneSlime::release_split_slimes() {
    Obj_800EB910 *self = (Obj_800EB910 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        Slot_800EB910 *s = &self->slots[i];
        if (s->state == 1) {
            if (s->obj != 0) {
                TObjEneSlimeOne__sub_800EC470(s->obj);
                s->obj = 0;
            }
            s->state = 2;
        }
    }
}

void TObjEneSlime::init_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TObjEneSlime__sub_800EB9F0(&((Obj_800EB984 *)this)->slots[i], (void *)&lbl_8043D218);
    }
    spawn_slime_in_slot(this, 0, 0, 0);
}

void TObjEneSlime__sub_800EB9F0(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

void TObjEneSlime::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r31;
    temp_r31 = defer_render__7TObjectFv();
    if (TObjPlayer::check_demo_mode() != 0) {
        temp_r30 = (this->state36C * 4) & 4;
        debug_printf_at(0x130020, lbl_8043D298, (int) (*(s32 *)((s8 *)((u8 *)slime_debug_label_table + temp_r30) + 0)));
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        temp_r30_2 = *(s32 *)((s8 *)((u8 *)lbl_80496368 + temp_r30) + 0);
        post_translate_matrix((void *) ((u8 *)arg0 + 0x38), (void *)lbl_80496368);
        TObjFish__sub_8001EDB0((void *)slime_bml_resource, (int)temp_r30_2);
        set_global_param__8TObjFishFl();
        if (temp_r31 != 0) {
            model_render_flags |= 0x400000;
            set_chunk_render_flags(1);
            draw_chunk_object(get_bml_model((void *)slime_bml_resource, (int)temp_r30_2));
            clear_chunk_render_flags();
            model_render_flags &= 0xFFBFFFFF;
        } else {
            set_chunk_render_flags(2);
            set_cull_back();
            draw_chunk_object(get_bml_model((void *)slime_bml_resource, (int)temp_r30_2));
            set_cull_front();
            draw_chunk_object(get_bml_model((void *)slime_bml_resource, (int)temp_r30_2));
            set_cull_none();
            clear_chunk_render_flags();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneSlime::run_task() {
    s32 sp8;

    if ((TObjPlayer::check_demo_mode() == 0) && (has_no_active_slot(this) != 0)) {
        sp8 = 0x800;
        send_6x0A_enemy_state(&sp8);
        exchange_object_state((s32)&sp8, (s16)0);
        ((VObj_800EBB18_800EB9F0 *)this)->m77(&sp8);
        send_entity_set_flags();
        queue_destruction__7TObjectFv(this);
    }
}

void TObjEneSlime::vfunc_63() { this->release_split_slimes(); }

}
