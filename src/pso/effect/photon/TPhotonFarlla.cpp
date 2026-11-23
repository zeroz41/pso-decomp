#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/photon/TPhotonFarlla.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/MatrixStack.h"

const char *TPhotonFarlla__class_name = "TPhotonFarlla";

#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_801AADE8.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/vector.h"
#include <stddef.h>
#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/text_801AB370.h"
#include "pso/map/FloorArea.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/CollisionActorLookup.h"

struct Self_801AAF00 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x184 - 0x14E];
    NJS_ARGB color;
    u8 pad5[0x1A0 - 0x194];
    s32 started;
};

extern u8 *photon_blast_shared_resource;
extern "C" {
s32 scroll_strip_uvs(void *, s16, int);
extern NJS_ARGB saved_model_draw_color;
extern NJS_ARGB model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
void *farlla_photon_blast_model_buffers;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
u32 get_entity_id();

}


void TPhotonFarlla::sub_801AAE6C() { this->m_184 = 0.0f; *(float*)((char*)this + 0x188) = 0.0f; this->m_18c = 0.0f; *(float*)((char*)this + 0x190) = 0.0f; }

void TPhotonFarlla::update_all_slots() {
    s32 index;

    TObjPlayer::init_all_slots();
    mark_enemy_body_contacts();
    if (*(s32 *)((s8 *)this->bodies + 0x18) & 0x100000) {
        index = 0;
        do {
            if (TObjPlayer::get_battle_param(index) != 0U) {
                queue_photon_blast_hit((u16) get_entity_id(), 0, 0, this->power);
            }
            index += 1;
        } while (index < 0x10);
    }
}
void TPhotonFarlla::render() {
    Self_801AAF00 *self = (Self_801AAF00 *)this;
    if (this->m_1a0 != 0) {
        scroll_strip_uvs(farlla_photon_blast_model_buffers, self->f14C, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
        push_matrix();
        translate_matrix(0, self->pos.x, self->pos.y, self->pos.z);
        rotate_matrix_y(0, this->rotation_y);
        ((TPhotonBlastSummon *)self)->set_photon_blast_joint_callback();
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
        ((TPhotonBlastSummon *)self)->clear_photon_blast_joint_callback();
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

#pragma push
#pragma opt_common_subs off
void TPhotonFarlla::run_task() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_801AB018, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_801AB018, spC) == 0x4);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_801AB018, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_801AB018, sp18) == 0x10);
    LAYOUT_ASSERT(sp20_offset, offsetof(Stack_801AB018, sp20) == 0x18);
    LAYOUT_ASSERT(sp24_offset, offsetof(Stack_801AB018, sp24) == 0x1C);
    Stack_801AB018 stack;
    f32 temp_f1;
    saddr entity;
    saddr temp_r3_3;
    s32 temp_r3_4;
    saddr temp_r3_5;
    *(s32 *)&this->unk_1A4 = (s32) (*(s32 *)&this->unk_1A4 + 1);
    if (((s32) *(s32 *)&this->unk_1A4 == 0x32) && ((s32) this->m_1a0 == 0)) {
        this->m_1a0 = 1;
        entity = (saddr)find_entity_by_id(((s32) this->m_17c));
        if (entity != 0) {
            VecCopy((Vec *)(&stack.sp20), (const Vec *)(entity + 0x38));
            stack.sp24 += 3e+01f;
        }
        new TPhotonMagicSquare((TObject *)arg0, 0, (Vec *)&stack.sp20, 0x78);
    }
    if (((s32) *(s32 *)&this->unk_1A4 == 0x64) && ((s16) this->requested_action == 1)) {
        ((TPhotonBlastSummon *)arg0)->begin_photon_summon_camera(1);
        *(s32 *)&this->unk_1A4 = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        ((TPhotonBlastSummon *)arg0)->spawn_photon_blast_attachment_effects(0);
    }
    this->m_194 = (s16) this->requested_action;
    ((TPhotonBlastSummon *)arg0)->update_state();
    ((TObjMotion *)arg0)->advance_animation();
    ((TPhotonBlastSummon *)arg0)->update_photon_blast_attachments();
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (*(s16 *)((s8 *)arg0 + 0x14C) + 0xF);
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (u8) *(s16 *)((s8 *)arg0 + 0x14C);
    if (1.4e+02f == (f32) *(s32 *)&this->unk_1A4) {
        ((TPhotonFarlla *)arg0)->update_all_slots();
    }
    if (1.3e+02f == (f32) *(s32 *)&this->unk_1A4) {
        temp_r3_3 = (saddr)find_entity_by_id(((s32) this->m_17c));
        if (temp_r3_3 != 0) {
            VecCopy((Vec *)(&stack.sp14), (const Vec *)(temp_r3_3 + 0x38));
        }
        stack.sp18 += 1e+01f;
        spawn_particle_effect((const Vec *)&stack.sp14, 0x151);
        stack.sp18 += 5.0f;
        spawn_particle_effect((const Vec *)&stack.sp14, 0x15F);
    }
    temp_r3_4 = *(s32 *)&this->unk_1A4;
    if ((133.0f == (f32) temp_r3_4) || (135.0f == (f32) temp_r3_4)) {
        temp_r3_5 = (saddr)find_entity_by_id(((s32) this->m_17c));
        if (temp_r3_5 != 0) {
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(temp_r3_5 + 0x38));
            stack.spC += 1e+01f;
        }
        spawn_particle_effect((const Vec *)&stack.sp8, 0x151);
    }
    if ((f32) *(s32 *)&this->unk_1A4 > 138.0f) {
        temp_f1 = this->m_184;
        if (temp_f1 > (-1.0f)) {
            this->m_184 = (f32) (temp_f1 - 0.15f);
        }
    }
    if ((s32) this->m_1a0 != 0) {
        play_persistent_sound(0x4002462F, (saddr)arg0, 0, 0, 0);
    }
}
#pragma pop
s32 free_collision_body_parts(void *);

extern void *lbl_804C3564[];

void *destroy__13TPhotonFarllaFPvs(void *photon_farlla, s16 arg1) {
    if (photon_farlla != NULL) {
        *(s32 **)((s8 *)photon_farlla + 0x18) = (s32 *)lbl_804C3564;
        ((TPhotonFarlla *)photon_farlla)->update_if_active();
        ((TPhotonBlastSummon *)photon_farlla)->free_photon();
        ((TObjCollidable *)photon_farlla)->unregister_object_by_id();
        free_collision_body_parts(photon_farlla);
        __dt__18TPhotonBlastSummonFv(photon_farlla, 0);
        if (arg1 > 0) {
            TObject::operator delete(photon_farlla);
        }
    }
    return photon_farlla;
}

s32 init_collision_body_parts(void *, void *, int);

s32 sub_801AAE6C__13TPhotonFarllaFv(void *, int);
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void interact__14TObjCollidableFl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void enter_scene__18TPhotonBlastSummonFv();
extern "C" void render__13TPhotonFarllaFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__10TObjMotionFv();
extern "C" void run_task__13TPhotonFarllaFv();
extern "C" void update_if_active__18TPhotonBlastSummonFv();
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
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&enter_scene__18TPhotonBlastSummonFv, (void *)&update_if_active__18TPhotonBlastSummonFv,
    (void *)0x0,
};
u8 *TPhotonFarlla__ct(u8 *summon, u8 *arg1) {
    Vec pos;
    u8 *e;
    __ct__18TPhotonBlastSummonFv(summon);
    *(u8 **)((s8 *)summon + 0x18) = (u8 *)lbl_804C3564;
    ((TPhotonFarlla *)summon)->m_name = TPhotonFarlla__class_name;
    *(s32 *)((s8 *)summon + 0x138) = 0;
    VecCopy((Vec *)(summon + 0x38), (const Vec *)arg1);
    ((TPhotonFarlla *)summon)->m_17c = *(u16 *)((s8 *)arg1 + 0xC);
    init_collision_body_parts(summon, (u8 *)lbl_804C3538, 1);
    ((TObjCollidable *)summon)->refresh_collision_body_centers();
    ((TObjPlayer *)summon)->register_object_by_id();
    ((TPhotonFarlla *)summon)->m_180 = (u8 *)find_entity_by_id(((TPhotonFarlla *)summon)->m_17c);
    e = ((TPhotonFarlla *)summon)->m_180;
    if (e != NULL) {
        ((TPhotonFarlla *)summon)->rotation_y = *(s32 *)((s8 *)e + 0x60);
    }
    *(s32 *)((s8 *)summon + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x8);
    ((TPhotonFarlla *)summon)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0xC);
    ((TObjMotion *)summon)->set_field_d8((saddr) photon_blast_farlla_params);
    ((TObjMotion *)summon)->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    ((TPhotonFarlla *)summon)->requested_action = 1;
    ((TObjMotion *)summon)->set_animation(((TPhotonFarlla *)summon)->requested_action);
    ((TObjMotion *)summon)->set_field_b8(((TPhotonFarlla *)summon)->requested_action);
    ((TPhotonFarlla *)summon)->m_194 = 1;
    ((TPhotonFarlla *)summon)->m_198 = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)summon + 0x19C) = *(s32 *)((s8 *)arg1 + 0x14);
    ((TPhotonFarlla *)summon)->m_1a0 = 0;
    ((TPhotonFarlla *)summon)->camera_script = 1;
    ((TPhotonFarlla *)summon)->enter_scene();
    *(s32 *)((s8 *)summon + 0x1A4) = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        new TPhotonRainbow((TObject *)summon, &((TObjBase *)summon)->position, 1);
        break;
    default:
        new TPhotonRainbow((TObject *)summon, &((TObjBase *)summon)->position, 0);
        break;
    }
    sub_801AAE6C__13TPhotonFarllaFv(summon, *(u8 *)((s8 *)arg1 + 0x1C));
    if (*(s32 *)((s8 *)summon + 0x19C) == 1) {
        *(s32 *)((s8 *)summon + 0x154) |= 1;
    }
    ((TPhotonFarlla *)summon)->power = *(f32 *)((s8 *)arg1 + 0x20);
    if (((TPhotonFarlla *)summon)->m_198 == 0) {
        ((TObjMotion *)summon)->set_field_b8(0);
        ((TPhotonBlastSummon *)summon)->begin_photon_summon_camera(1);
        ((TPhotonFarlla *)summon)->m_198 = 1;
        ((TPhotonFarlla *)summon)->m_194 = 0;
        ((TPhotonFarlla *)summon)->m_1a0 = 1;
        e = (u8 *)find_entity_by_id(((TPhotonFarlla *)summon)->m_17c);
        if (e != NULL) {
            VecCopy((Vec *)&pos, (const Vec *)(e + 0x38));
            pos.y += 3e+01f;
        }
        new TPhotonMagicSquare((TObject *)summon, 0, &pos, 0x78);
        ((TPhotonBlastSummon *)summon)->spawn_photon_blast_attachment_effects(0);
        play_cue_stream_file((saddr)"farla2.adx");
    } else {
        spawn_photon_blast_opening_effects(0, ((TPhotonFarlla *)summon)->m_17c);
        play_cue_stream_file((saddr)"farla.adx");
    }
    return summon;
}
}
#pragma pop

void TObjPlayer::destroy_buffers() {
    if (farlla_photon_blast_model_buffers != NULL) {
        destroy_buffer_pair(farlla_photon_blast_model_buffers, 1);
    }
    farlla_photon_blast_model_buffers = NULL;
}

void create_farlla_photon_blast_model(void) {
    saddr temp_r3;
    saddr var_r0;
    temp_r3 = (saddr)::operator new(0x14);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TLobby *)temp_r3)->alloc_tables(*(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 8), 0));
    }
    farlla_photon_blast_model_buffers = (void *)var_r0;
}
