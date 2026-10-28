#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_801ADC6C.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TPhotonPilla.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/misc/obj_band.h"
#include "pso/unk/text_801AE1F8.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

typedef struct { f32 x; f32 y; f32 z; } Vec3;

struct Color_801ADDDC { f32 a, r, g, b; };

struct Vec_801ADDDC { f32 x, y, z; };

struct Self_801ADDDC {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec_801ADDDC pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x180 - 0x14E];
    Color_801ADDDC color;
    u8 pad5[0x1A4 - 0x190];
    s32 started;
};

typedef struct Packet_801ADD10 { Vec pos; u32 w[9]; } Packet_801ADD10;

extern "C" {
s32 scroll_strip_uvs(void *, s16, int);
s32 clear_render_context__10TObjPlayerFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
extern Color_801ADDDC saved_model_draw_color;
extern Color_801ADDDC model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern void *pilla_photon_buffer_pair;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void TPhotonLaser__ct(void *, void *, void *, u16);
void *__nw__7TObjectFUl(u32);
void vec3_add_to(void *, void *);
extern Packet_801ADD10 photon_pilla_laser_packet;
extern void *photon_pilla_laser_offset_table[];

s32 advance_animation_playback(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 spawn_photon_blast_attachment_effects(void *, s32);
u8 *TPhotonMagicSquare__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
void *find_entity_by_id(u16 id);
u32 get_entity_id();

    extern int lbl_805D5D50;
void TObjPlayer__sub_801ADC6C(void) { lbl_805D5D50 = 0; }

void TObjPlayer__sub_801ADC78(void) {  }

void TPhotonPilla::sub_801ADC7C() { this->m_180 = 0.0f; *(float*)((char*)this + 0x184) = 0.0f; this->m_188 = 0.0f; *(float*)((char*)this + 0x18c) = 0.0f; }

void TPhotonPilla::apply_photon_blast_effects() {
    s32 var_r31;

    TObjPlayer::init_all_slots();
    mark_enemy_body_contacts();
    if (*(s32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 0x18) & 0x100000) {
        var_r31 = 0;
        do {
            if (TObjPlayer::get_battle_param(var_r31) != 0U) {
                queue_photon_blast_hit((u16) get_entity_id(), 2, 0, *(f32 *)((s8 *)this + 0x150));
            }
            var_r31 += 1;
        } while (var_r31 < 0x10);
    }
}

void TPhotonPilla::spawn_laser() {
    Vec position;
    u8 *laser;
    position.x = *(f32 *)((s8 *)((u8 *)this) + 0x38);
    position.y = 3e+02f;
    position.z = *(f32 *)((s8 *)((u8 *)this) + 0x40);
    vec3_add_to(&position, &((Vec *)photon_pilla_laser_offset_table)[*(s32 *)((s8 *)((u8 *)this) + 0x194)]);
    (*(s32 *)((s8 *)((u8 *)this) + 0x194))++;
    Packet_801ADD10 packet = photon_pilla_laser_packet;
    packet.pos.x = position.x;
    packet.pos.y = position.y;
    packet.pos.z = position.z;
    laser = (u8 *) __nw__7TObjectFUl(0x380);
    if (laser != NULL) {
        TPhotonLaser__ct(laser, &packet, this, this->m_17c);
    }
}

void TPhotonPilla::render() {
    Self_801ADDDC *self = (Self_801ADDDC *)this;
    if (this->m_1a4 != 0) {
        scroll_strip_uvs(pilla_photon_buffer_pair, self->f14C, 0);
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
        TObjPlayer::set_global_flag();
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
        ((TObjMotion *)self)->draw();
        TObjPlayer::clear_global_state();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        clear_render_context__10TObjPlayerFv(self);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonPilla::run_task() {
    Vec3 sp8;
    s32 entity;
    s32 temp_r3_2;

    *(s32 *)((s8 *)this + 0x1A8) = (s32) (*(s32 *)((s8 *)this + 0x1A8) + 1);
    if (((s32) *(s32 *)((s8 *)this + 0x1A8) == 0x32) && ((s32) this->m_1a4 == 0)) {
        this->m_1a4 = 1;
        *(s32 *)((s8 *)this + 0x1A8) = 0;
        entity = (s32)find_entity_by_id(this->m_17c);
        if (entity != 0) {
            VecCopy((Vec *)&sp8, (const Vec *)(entity + 0x38));
        }
        sp8.y += 3e+01f;
        entity = (s32)__nw__7TObjectFUl(0xD0);
        if (entity != 0U) {
            TPhotonMagicSquare__ct((u8 *)entity, (s32)this, 3, (s32)&sp8, 0xD2, (f32)0.5f);
        }
    }
    if ((5e+01f == (f32) *(s32 *)((s8 *)this + 0x1A8)) && ((s16) this->m_b8 == 1) && ((s32) this->m_1a4 == 1)) {
        begin_photon_summon_camera(4);
        *(s32 *)((s8 *)this + 0x1A8) = 0;
        this->set_field_b8(0);
        spawn_photon_blast_attachment_effects(this, 3);
    }
    this->m_198 = (s16) this->m_b8;
    update_state();
    advance_animation_playback(this);
    update_photon_blast_attachments();
    *(s16 *)((s8 *)this + 0x14C) = (s16) (*(s16 *)((s8 *)this + 0x14C) + 0xF);
    *(s16 *)((s8 *)this + 0x14C) = (s16) (u8) *(s16 *)((s8 *)this + 0x14C);
    temp_r3_2 = *(s32 *)((s8 *)this + 0x1A8);
    if ((8e+01f == (f32) temp_r3_2) || (82.0f == (f32) temp_r3_2) || (84.0f == (f32) temp_r3_2) || (86.0f == (f32) temp_r3_2) || (88.0f == (f32) temp_r3_2) || (9e+01f == (f32) temp_r3_2)) {
        spawn_laser();
    }
    if (1.1e+02f == (f32) *(s32 *)((s8 *)this + 0x1A8)) {
        this->apply_photon_blast_effects();
    }
    if ((s32) this->m_1a4 != 0) {
        play_persistent_sound(0x4002462F, (s32)this, 0, 0, 0);
    }
}

}

extern "C" {

s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

extern void *lbl_804C3ACC[];

void *destroy__12TPhotonPillaFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)lbl_804C3ACC;
        ((TPhotonPilla *)arg0)->update_if_active();
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

struct Vec_801AE1F8 { f32 x, y, z; };

extern "C" {
void *find_entity_by_id(u16 id);
s32 init_collision_body_parts(void *, void *, int);
s32 spawn_photon_blast_attachment_effects(void *, s32);
u8 *TPhotonMagicSquare__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
void sub_801ADC7C__12TPhotonPillaFv(void *, u8);
u8 *TPhotonRainbow__ct(void *, void *, void *, s32);
extern u8 lbl_80446EE0[];
extern u8 lbl_80446EEC[];
extern s32 lbl_805D3518;
extern u8 *photon_blast_shared_resource;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void interact__14TObjCollidableFl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void enter_scene__13TUnk_804C3248Fv();
extern "C" void render__12TPhotonPillaFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__10TObjMotionFv();
extern "C" void update_if_active__13TUnk_804C3248Fv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void run_task__12TPhotonPillaFv();
void *photon_pilla_action_table[8] = {
    (void *)0x30000, (void *)0x3, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0xa, (void *)0x3f800000, (void *)0x0,
};
void *lbl_804C3A58[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x42f00000,
    (void *)0x41f00000, (void *)0x0, (void *)0x8007, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *photon_pilla_laser_offset_table[18] = {
    (void *)0x0, (void *)0x43960000, (void *)0x42480000, (void *)0x41c80000,
    (void *)0x43960000, (void *)0x41c80000, (void *)0x41c80000, (void *)0x43960000,
    (void *)0xc1c80000, (void *)0x0, (void *)0x43960000, (void *)0xc2480000,
    (void *)0xc1c80000, (void *)0x43960000, (void *)0xc1c80000, (void *)0x41c80000,
    (void *)0x43960000, (void *)0x41c80000,
};
void *lbl_804C3ACC[17] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__12TPhotonPillaFPvs, (void *)&run_task__12TPhotonPillaFv,
    (void *)&render__12TPhotonPillaFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&enter_scene__13TUnk_804C3248Fv, (void *)&update_if_active__13TUnk_804C3248Fv,
    (void *)0x0,
};
u8 *TPhotonPilla__ct(u8 *photon_rainbow, u8 *arg1) {
    u8 *temp_r3;
    s32 state;
    void *mem;
    photon_base_ct(photon_rainbow);
    *(u8 **)((s8 *)photon_rainbow + 0x18) = (u8 *)lbl_804C3ACC;
    *(s32 *)((s8 *)photon_rainbow + 0) = lbl_805D3518;
    *(s32 *)((s8 *)photon_rainbow + 0x138) = 3;
    VecCopy((Vec *)(photon_rainbow + 0x38), (const Vec *)arg1);
    ((TPhotonPilla *)photon_rainbow)->m_17c = *(u16 *)((s8 *)arg1 + 0xC);
    init_collision_body_parts(photon_rainbow, (void *)lbl_804C3A58, 1);
    ((TObjCollidable *)photon_rainbow)->refresh_collision_body_centers();
    ((TObjPlayer *)photon_rainbow)->register_object_by_id();
    ((TPhotonPilla *)photon_rainbow)->m_190 = (u8 *)find_entity_by_id(((TPhotonPilla *)photon_rainbow)->m_17c);
    temp_r3 = ((TPhotonPilla *)photon_rainbow)->m_190;
    if (temp_r3 != NULL) {
        ((TPhotonPilla *)photon_rainbow)->rotation_y = *(s32 *)((s8 *)temp_r3 + 0x60);
    }
    *(s32 *)((s8 *)photon_rainbow + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x38);
    ((TPhotonPilla *)photon_rainbow)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x3C);
    ((TObjMotion *)photon_rainbow)->set_field_d8((s32)photon_pilla_action_table);
    ((TObjMotion *)photon_rainbow)->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    ((TPhotonPilla *)photon_rainbow)->m_b8 = 1;
    ((TObjMotion *)photon_rainbow)->set_animation(((TPhotonPilla *)photon_rainbow)->m_b8);
    ((TObjMotion *)photon_rainbow)->set_field_b8(((TPhotonPilla *)photon_rainbow)->m_b8);
    ((TPhotonPilla *)photon_rainbow)->m_198 = 1;
    ((TPhotonPilla *)photon_rainbow)->m_19c = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)photon_rainbow + 0x1A0) = *(s32 *)((s8 *)arg1 + 0x14);
    ((TPhotonPilla *)photon_rainbow)->m_1a4 = 0;
    ((TPhotonPilla *)photon_rainbow)->m_134 = 4;
    ((TPhotonPilla *)photon_rainbow)->enter_scene();
    *(s32 *)((s8 *)photon_rainbow + 0x1A8) = 0;
    state = get_current_area();
    switch (state) {
    case 11:
    case 12:
    case 13:
    case 14:
        mem = __nw__7TObjectFUl(0xAC);
        if (mem != NULL) {
            TPhotonRainbow__ct(mem, photon_rainbow, photon_rainbow + 0x38, 1);
        }
        break;
    default:
        mem = __nw__7TObjectFUl(0xAC);
        if (mem != NULL) {
            TPhotonRainbow__ct(mem, photon_rainbow, photon_rainbow + 0x38, 0);
        }
        break;
    }
    *(s32 *)((s8 *)photon_rainbow + 0x194) = 0;
    sub_801ADC7C__12TPhotonPillaFv(photon_rainbow, *(u8 *)((s8 *)arg1 + 0x1C));
    if (*(s32 *)((s8 *)photon_rainbow + 0x1A0) == 1) {
        *(s32 *)((s8 *)photon_rainbow + 0x154) |= 1;
    }
    ((TPhotonPilla *)photon_rainbow)->m_150 = *(f32 *)((s8 *)arg1 + 0x20);
    if (((TPhotonPilla *)photon_rainbow)->m_19c == 0) {
        ((TObjMotion *)photon_rainbow)->set_field_b8(0);
        ((TUnk_804C3248 *)photon_rainbow)->begin_photon_summon_camera(4);
        ((TPhotonPilla *)photon_rainbow)->m_19c = 1;
        ((TPhotonPilla *)photon_rainbow)->m_198 = 0;
        ((TPhotonPilla *)photon_rainbow)->m_1a4 = 1;
        {
        Vec_801AE1F8 pos = *(Vec_801AE1F8 *)((s8 *)photon_rainbow + 0x38);
        pos.y += 4e+01f;
        mem = __nw__7TObjectFUl(0xD0);
        if (mem != NULL) {
            TPhotonMagicSquare__ct((u8 *)mem, (s32)photon_rainbow, 3, (s32)&pos, 0xAA, (f32)0.5f);
        }
        }
        spawn_photon_blast_attachment_effects(photon_rainbow, 3);
        play_cue_stream_file((s32)lbl_80446EE0);
    } else {
        spawn_photon_blast_opening_effects(3, ((TPhotonPilla *)photon_rainbow)->m_17c);
        play_cue_stream_file((s32)lbl_80446EEC);
    }
    return photon_rainbow;
}

}
