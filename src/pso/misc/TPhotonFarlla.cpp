#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_801AADE8.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TPhotonFarlla.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#include <stddef.h>
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/misc/TPhotonRainbow_801AE640.h"
#include "pso/unk/text_801AB370.h"
#include "pso/map/FloorArea.h"

struct Color_801AAF00 { f32 a, r, g, b; };

struct Vec_801AAF00 { f32 x, y, z; };

struct Self_801AAF00 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec_801AAF00 pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x184 - 0x14E];
    Color_801AAF00 color;
    u8 pad5[0x1A0 - 0x194];
    s32 started;
};

extern u8 *photon_blast_shared_resource;
extern u32 estlla_photon_blast_model;
extern "C" {
s32 scroll_strip_uvs(void *, s16, int);
s32 clear_render_context__10TObjPlayerFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
extern Color_801AAF00 saved_model_draw_color;
extern Color_801AAF00 model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern void *farlla_photon_blast_model_buffers;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
u32 get_entity_id();

void TObjPlayer::destroy_global_buffer() {
    if ((u32) estlla_photon_blast_model != 0U) {
        destroy_buffer_pair((void *)estlla_photon_blast_model, 1);
    }
    estlla_photon_blast_model = 0U;
}
}

void create_estlla_photon_blast_model(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x14);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TLobby *)temp_r3)->alloc_tables(*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x98)) + 0x2C), 0));
    }
    (*(s32 *)&estlla_photon_blast_model) = var_r0;
}

void TPhotonFarlla::sub_801AAE6C() { this->m_184 = 0.0f; *(float*)((char*)this + 0x188) = 0.0f; this->m_18c = 0.0f; *(float*)((char*)this + 0x190) = 0.0f; }

void TPhotonFarlla::update_all_slots() {
    s32 var_r31;

    TObjPlayer::init_all_slots();
    mark_enemy_body_contacts();
    if (*(s32 *)((s8 *)this->bodies + 0x18) & 0x100000) {
        var_r31 = 0;
        do {
            if (TObjPlayer::get_battle_param(var_r31) != 0U) {
                queue_photon_blast_hit((u16) get_entity_id(), 0, 0, this->m_150);
            }
            var_r31 += 1;
        } while (var_r31 < 0x10);
    }
}
void TPhotonFarlla::render() {
    Self_801AAF00 *self = (Self_801AAF00 *)this;
    if (this->m_1a0 != 0) {
        scroll_strip_uvs(farlla_photon_blast_model_buffers, self->f14C, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        translate_matrix(0, self->pos.x, self->pos.y, self->pos.z);
        rotate_matrix_y(0, this->rotation_y);
        ((TUnk_804C3248 *)self)->set_photon_blast_joint_callback();
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        set_motion_packed_rotation();
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
        ((TObjMotion *)self)->draw();
        clear_motion_packed_rotation();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        clear_render_context__10TObjPlayerFv(self);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

struct Stack_801AB018 {
    s32 sp8;
    f32 spC;
    u8 pad_10[0x4];
    s32 sp14;
    f32 sp18;
    u8 pad_1C[0x4];
    s32 sp20;
    f32 sp24;
    u8 trailing_storage[0x4];
};

extern "C" {
void *find_entity_by_id(u16 id);
s32 spawn_photon_blast_attachment_effects(void *, int);
}
u8 *construct_photon_magic_square_normal(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" {
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u32 __nw__7TObjectFUl(int);

#pragma push
#pragma opt_common_subs off
void TPhotonFarlla::run_task() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_801AB018, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801AB018, spC) == 0x4) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_801AB018, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_801AB018, sp18) == 0x10) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_801AB018, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_801AB018, sp24) == 0x1C) ? 1 : -1];
    Stack_801AB018 stack;
    f32 temp_f1;
    s32 entity;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    u32 photon_magic_square;
    *(s32 *)&this->unk_1A4 = (s32) (*(s32 *)&this->unk_1A4 + 1);
    if (((s32) *(s32 *)&this->unk_1A4 == 0x32) && ((s32) this->m_1a0 == 0)) {
        this->m_1a0 = 1;
        entity = (s32)find_entity_by_id(((s32) this->m_17c));
        if (entity != 0) {
            VecCopy((Vec *)(&stack.sp20), (const Vec *)(entity + 0x38));
            stack.sp24 += 3e+01f;
        }
        photon_magic_square = __nw__7TObjectFUl(0xD0);
        if (photon_magic_square != 0U) {
            construct_photon_magic_square_normal((u8 *)photon_magic_square, (s32)arg0, 0, (s32)&stack.sp20, 0x78);
        }
    }
    if (((s32) *(s32 *)&this->unk_1A4 == 0x64) && ((s16) this->requested_action == 1)) {
        ((TUnk_804C3248 *)arg0)->begin_photon_summon_camera(1);
        *(s32 *)&this->unk_1A4 = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        spawn_photon_blast_attachment_effects(arg0, 0);
    }
    this->m_194 = (s16) this->requested_action;
    ((TUnk_804C3248 *)arg0)->update_state();
    ((TObjMotion *)arg0)->advance_animation();
    ((TUnk_804C3248 *)arg0)->update_photon_blast_attachments();
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (*(s16 *)((s8 *)arg0 + 0x14C) + 0xF);
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (u8) *(s16 *)((s8 *)arg0 + 0x14C);
    if (1.4e+02f == (f32) *(s32 *)&this->unk_1A4) {
        ((TPhotonFarlla *)arg0)->update_all_slots();
    }
    if (1.3e+02f == (f32) *(s32 *)&this->unk_1A4) {
        temp_r3_3 = (s32)find_entity_by_id(((s32) this->m_17c));
        if (temp_r3_3 != 0) {
            VecCopy((Vec *)(&stack.sp14), (const Vec *)(temp_r3_3 + 0x38));
        }
        stack.sp18 += 1e+01f;
        spawn_particle_effect((&stack.sp14), 0x151);
        stack.sp18 += 5.0f;
        spawn_particle_effect((&stack.sp14), 0x15F);
    }
    temp_r3_4 = *(s32 *)&this->unk_1A4;
    if ((133.0f == (f32) temp_r3_4) || (135.0f == (f32) temp_r3_4)) {
        temp_r3_5 = (s32)find_entity_by_id(((s32) this->m_17c));
        if (temp_r3_5 != 0) {
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(temp_r3_5 + 0x38));
            stack.spC += 1e+01f;
        }
        spawn_particle_effect((&stack.sp8), 0x151);
    }
    if ((f32) *(s32 *)&this->unk_1A4 > 138.0f) {
        temp_f1 = this->m_184;
        if (temp_f1 > (-1.0f)) {
            this->m_184 = (f32) (temp_f1 - 0.15f);
        }
    }
    if ((s32) this->m_1a0 != 0) {
        play_persistent_sound(0x4002462F, (s32)arg0, 0, 0, 0);
    }
}
}
#pragma pop

extern "C" {

s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

extern void *lbl_804C3564[];

void *destroy__13TPhotonFarllaFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)lbl_804C3564;
        ((TPhotonFarlla *)arg0)->update_if_active();
        ((TUnk_804C3248 *)arg0)->free_photon();
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        destroy_photon_motion_object(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

struct Stack_801AB370 { f32 x, y, z; };

extern "C" {
void *find_entity_by_id(u16 id);
s32 init_collision_body_parts(void *, void *, int);

s32 sub_801AAE6C__13TPhotonFarllaFv(void *, int);
}
u8 *construct_photon_magic_square_normal(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" {

extern u8 lbl_80446D40[];
extern u8 lbl_80446D4C[];
extern s32 lbl_805D34E0;
extern u8 *photon_blast_shared_resource;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void interact__14TObjCollidableFl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void enter_scene__13TUnk_804C3248Fv();
extern "C" void render__13TPhotonFarllaFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__10TObjMotionFv();
extern "C" void run_task__13TPhotonFarllaFv();
extern "C" void update_if_active__13TUnk_804C3248Fv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
#pragma push
#pragma opt_propagation off
void *photon_blast_farlla_params[8] = {
    (void *)0x30000, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x8, (void *)0x3f800000, (void *)0x0,
};
void *lbl_804C3538[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x432a0000,
    (void *)0x41f00000, (void *)0x0, (void *)0x2003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804C3564[17] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__13TPhotonFarllaFPvs, (void *)&run_task__13TPhotonFarllaFv,
    (void *)&render__13TPhotonFarllaFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&enter_scene__13TUnk_804C3248Fv, (void *)&update_if_active__13TUnk_804C3248Fv,
    (void *)0x0,
};
u8 *TPhotonFarlla__ct(u8 *arg0, u8 *arg1) {
    Stack_801AB370 pos;
    u8 *e;
    void *p;
    photon_base_ct(arg0);
    *(u8 **)((s8 *)arg0 + 0x18) = (u8 *)lbl_804C3564;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D34E0;
    *(s32 *)((s8 *)arg0 + 0x138) = 0;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)arg1);
    ((TPhotonFarlla *)arg0)->m_17c = *(u16 *)((s8 *)arg1 + 0xC);
    init_collision_body_parts(arg0, (u8 *)lbl_804C3538, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TPhotonFarlla *)arg0)->m_180 = (u8 *)find_entity_by_id(((TPhotonFarlla *)arg0)->m_17c);
    e = ((TPhotonFarlla *)arg0)->m_180;
    if (e != NULL) {
        ((TPhotonFarlla *)arg0)->rotation_y = *(s32 *)((s8 *)e + 0x60);
    }
    *(s32 *)((s8 *)arg0 + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x8);
    ((TPhotonFarlla *)arg0)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0xC);
    ((TObjMotion *)arg0)->set_field_d8((s32) photon_blast_farlla_params);
    ((TObjMotion *)arg0)->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    ((TPhotonFarlla *)arg0)->requested_action = 1;
    ((TObjMotion *)arg0)->set_animation(((TPhotonFarlla *)arg0)->requested_action);
    ((TObjMotion *)arg0)->set_field_b8(((TPhotonFarlla *)arg0)->requested_action);
    ((TPhotonFarlla *)arg0)->m_194 = 1;
    ((TPhotonFarlla *)arg0)->m_198 = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x19C) = *(s32 *)((s8 *)arg1 + 0x14);
    ((TPhotonFarlla *)arg0)->m_1a0 = 0;
    ((TPhotonFarlla *)arg0)->m_134 = 1;
    ((TPhotonFarlla *)arg0)->enter_scene();
    *(s32 *)((s8 *)arg0 + 0x1A4) = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        p = (void *)__nw__7TObjectFUl(0xAC);
        if (p != NULL) {
            ((u8 *(*)(void *, void *, void *, int)) TPhotonRainbow__ct)(p, arg0, arg0 + 0x38, 1);
        }
        break;
    default:
        p = (void *)__nw__7TObjectFUl(0xAC);
        if (p != NULL) {
            ((u8 *(*)(void *, void *, void *, int)) TPhotonRainbow__ct)(p, arg0, arg0 + 0x38, 0);
        }
        break;
    }
    sub_801AAE6C__13TPhotonFarllaFv(arg0, *(u8 *)((s8 *)arg1 + 0x1C));
    if (*(s32 *)((s8 *)arg0 + 0x19C) == 1) {
        *(s32 *)((s8 *)arg0 + 0x154) |= 1;
    }
    ((TPhotonFarlla *)arg0)->m_150 = *(f32 *)((s8 *)arg1 + 0x20);
    if (((TPhotonFarlla *)arg0)->m_198 == 0) {
        ((TObjMotion *)arg0)->set_field_b8(0);
        ((TUnk_804C3248 *)arg0)->begin_photon_summon_camera(1);
        ((TPhotonFarlla *)arg0)->m_198 = 1;
        ((TPhotonFarlla *)arg0)->m_194 = 0;
        ((TPhotonFarlla *)arg0)->m_1a0 = 1;
        e = (u8 *)find_entity_by_id(((TPhotonFarlla *)arg0)->m_17c);
        if (e != NULL) {
            VecCopy((Vec *)&pos, (const Vec *)(e + 0x38));
            pos.y += 3e+01f;
        }
        p = (void *)__nw__7TObjectFUl(0xD0);
        if (p != NULL) {
            construct_photon_magic_square_normal((u8 *)p, (s32)arg0, 0, (s32)&pos, 0x78);
        }
        spawn_photon_blast_attachment_effects(arg0, 0);
        play_cue_stream_file((s32)lbl_80446D40);
    } else {
        spawn_photon_blast_opening_effects(0, ((TPhotonFarlla *)arg0)->m_17c);
        play_cue_stream_file((s32)lbl_80446D4C);
    }
    return arg0;
}
}
#pragma pop
