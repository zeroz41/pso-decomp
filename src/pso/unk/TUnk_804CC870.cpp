// ---- pso/unk/text_80232934
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/depth_buffer.h"
#include "pso/unk/TUnk_804CC870.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
struct Vec_80232934 { f32 x; f32 y; f32 z; };

struct Quad_80232934 { u32 a; u32 b; u32 c; u32 d; };

struct Obj_80232934 {
    u8 pad[0x20];
    u8 f20[0xC];
    Vec_80232934 pos;
    u8 f38[0x10];
    s32 f48;
    f32 f4c;
};

extern "C" {
s32 get_bml_model(s32, u32);
void init_texture_copy_rect(TextureFrameSlot *, void *, void *, s32, s32);
void approach_position_if_far(Vec_80232934 *, Vec_80232934 *, f32);
void scale_matrix(s32, f32, f32, f32);
void push_matrix(void);
void post_translate_matrix(void *);
void draw_ginja_object(void);
void set_chunk_material_color__13TUnk_80494AE0Fv(void *, s32);
extern Vec_80232934 lbl_8044D5A8;
extern Quad_80232934 grants_flash_quad_vertices;
extern u8 lbl_804CC868[];
extern u8 technique_ringwave_texture_list[];
extern s32 saved_model_render_flags;
extern s32 technique_effect_bml;
extern s32 model_render_flags;


}


// ---- pso/unk/text_80232AA4
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_804CC870.h"

extern "C" {
void *find_entity_by_id(u16 id);

}

// ---- pso/unk/text_80232B24
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/unk/TUnk_804CC870.h"
#include "pso/unk/text_80232B24.h"

// ---- pso/unk/text_80232B7C
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/unk/TUnk_804CC888.h"

#include "pso/misc/TLobby_80226070.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"

struct Ent_80232E0C { u32 a; u32 count; };

struct Obj_80232E0C {
    u8 pad0[0x18];
    void *vt;
    void **items;
    s32 f20;
    s32 kind;
};

struct Vec_80232B7C { f32 x, y, z; };

struct Obj_80232B7C {
    u8 pad0[0x18];
    void *vt;
    u16 id;
    Vec_80232B7C pos;
    Vec_80232B7C scale;
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
    s32 f48;
    f32 f4c;
};

struct Obj_80232B7C;
struct SEnt_80232C50 { s32 a; u32 flags; s32 c; };

struct SGrp_80232C50 { SEnt_80232C50 *ents; u32 count; };

struct Ctl_80232C50 {
    u8 pad0[0x24];
    s32 kind;
    u8 pad28[4];
    s16 timer;
    u16 id;
    u8 f30[4];
};

extern "C" {
void mem_free(void *);
extern Ent_80232E0C grants_effect_emitter_table[];
void __ct__7TObjectFP7TObject(void *self, void *parent);
extern u8 __vt__13TUnk_804CC870[];




Obj_80232B7C *construct_grants_flash(Obj_80232B7C *self, s32 id, void *parent, Vec_80232B7C *pos, f32 scale);

void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
void *spawn_particle_effect(void *pos, s32 id);
void *find_entity_by_id(u16 id);
void *__nw__7TObjectFUl(u32);
}
u8 *construct_timed_sound_voice(u8 *arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5);
extern SGrp_80232C50 technique_effect_entry_table[];
extern void *tl_07;
extern s32 technique_effect_bml;
extern s32 lbl_805D63B0;


// Function definitions in reverse address order (defer_codegen emits them reversed).
#pragma defer_codegen on

TUnk_804CC888::~TUnk_804CC888() {
    u32 i;
    for (i = 0; i < grants_effect_emitter_table[((Obj_80232E0C *)this)->kind].count; i++) {
        if (((Obj_80232E0C *)this)->items[i] != NULL) {
            queue_destruction__7TObjectFv(((Obj_80232E0C *)this)->items[i]);
        }
    }
    stop_sound_request(((Obj_80232E0C *)this)->f20);
    mem_free(((Obj_80232E0C *)this)->items);
}

void TUnk_804CC888::run_task() {
    u32 i;
    s32 dir;
    u8 *obj;
    s32 r;
    void *p;
    ((Ctl_80232C50 *)this)->timer++;
    if (((Ctl_80232C50 *)this)->timer % 5 == 0) {
        p = __nw__7TObjectFUl(0x50);
        if (p != 0) {
            construct_grants_flash((Obj_80232B7C *) p, ((Ctl_80232C50 *)this)->id, tl_07, 0, 1.0f);
        }
    }
    if (((Ctl_80232C50 *)this)->timer >= 30) {
        for (i = 0; i < technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].count; i++) {
            obj = (u8 *)find_entity_by_id(((Ctl_80232C50 *)this)->id);
            if (obj != 0) {
                SEnt_80232C50 *e = &technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].ents[i];
                if (e->flags & 0x20) {
                    r = (s32)spawn_particle_effect(obj + 0x38, e->a);
                    if (r != 0) {
                        attach_particle_model((u8 *)r, (s32)(get_bml_model(technique_effect_bml, technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].ents[i].flags >> 16)), (s32)lbl_805D63B0, 0, 1, (f32)1.0f);
                    }
                } else {
                    spawn_particle_effect(obj + 0x38, e->a);
                }
            }
        }
        switch (((Ctl_80232C50 *)this)->kind) {
        case 0:
        case 1:
            dir = 0x100;
            break;
        case 2:
        case 3:
            dir = 0;
            break;
        case 4:
        case 5:
            dir = -0x100;
            break;
        }
        p = __nw__7TObjectFUl(0x28);
        if (p != 0) {
            construct_timed_sound_voice((u8 *)p, (s32)((Ctl_80232C50 *)this)->f30, (s16)(0xF), 0x4002A60D, (s32)dir, (s32)tl_07);
        }
        queue_destruction__7TObjectFv(((Ctl_80232C50 *)this));
    }
}

Obj_80232B7C *construct_grants_flash(Obj_80232B7C *self, s32 id, void *parent, Vec_80232B7C *pos, f32 scale) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__13TUnk_804CC870;
    self->id = id;
    self->pos.x = 0.0f;
    self->pos.y = 0.0f;
    self->pos.z = 0.0f;
    self->scale.x = 0.05f;
    self->scale.y = 0.05f;
    self->scale.z = 0.05f;
    self->f4c = 0.05f;
    if ((u16)id == 0xffff && pos != 0) {
        VecCopy((Vec *)&self->pos, (const Vec *)pos);
        self->scale.x = scale;
        self->scale.y = scale;
        self->scale.z = scale;
        self->f4c = 2.0f;
    }
    self->f38 = 1.0f;
    self->f3c = 1.0f;
    self->f40 = 1.0f;
    self->f44 = 1.0f;
    self->f48 = 0;
    return self;
}

TUnk_804CC870::~TUnk_804CC870() {

}

void TUnk_804CC870::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 entity;
    entity = (s32)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x1C)));
    if (entity != 0) {
        VecCopy((Vec *)(arg0 + 0x20), (const Vec *)(entity + 0x38));
    }
    this->m_48 = (this->m_48 + 1);
    if ((s32) this->m_48 >= 7) {
        this->m_48 = 0;
    }
    if (this->m_38 <= 0.0f) {
        queue_destruction__7TObjectFv((arg0));
    }
}

void TUnk_804CC870::render() {
    Obj_80232934 *arg0 = (Obj_80232934 *)this;
    TextureFrameSlot ctx;
    s32 id;
    if (TOKeyMachine01::get_global_state() == 0 || TOKeyMachine01::get_global_state() == 0x12 ||
        TOKeyMachine01::get_global_state() == 0xF) {
        return;
    }
    init_texture_copy_rect(&ctx, lbl_804CC868, technique_ringwave_texture_list, 0, this->m_48 + 1);
    Vec_80232934 v = lbl_8044D5A8;
    Quad_80232934 q = grants_flash_quad_vertices;
    approach_alpha_clamped((f32 *)arg0->f38, (const f32 *)&q, 0.1f);
    approach_position_if_far(&arg0->pos, &v, arg0->f4c);
    copy_anim_frame_to_slot(&ctx);
    id = model_render_flags;
    saved_model_render_flags = id;
    model_render_flags = id | 0x10;
    set_chunk_material_color__13TUnk_80494AE0Fv(arg0->f38, id);
    set_depth_buffer_settings_id(3);
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(arg0->f20);
    scale_matrix(0, arg0->pos.x, arg0->pos.y, arg0->pos.z);
    translate_matrix(0, 0.0f, 1e+01f, 0.0f);
    TObjFish::set_global_param((s32)lbl_804CC868);
    get_bml_model(technique_effect_bml, 10);
    draw_ginja_object();
    pop_matrix();
    copy_slot_to_anim_frame(&ctx);
    restore_draw_list_mask();
    model_render_flags = saved_model_render_flags;
}

#pragma defer_codegen off
