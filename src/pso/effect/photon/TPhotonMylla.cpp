#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/player/TObjPlayer_801ADC6C.h"
#include "pso/effect/photon/TPhotonMylla.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
struct TPhotonYoulla;
#include "pso/system/vector.h"


#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/effect/photon/TPhotonYoulla.h"
#include "pso/unk/TLobby_802268F4.h"
struct Stack_801AD5D8 {
    s32 sp8;
    f32 spC;
    u8 pad_10[0x4];
    s32 sp14;
    f32 sp18;
    u8 pad_1C[0x4];
    s32 sp20;
    f32 sp24;
    u8 pad_28[0x4];
    s32 sp2C;
    f32 sp30;
};

struct RecoveredFields_801AD5D8_arg0 {
    u8 unknown_0[0xB8];
    s16 field_B8;
    u8 unknown_BA[0x92];
    s16 field_14C;
    u8 unknown_14E[0x2];
    f32 field_150;
    u8 unknown_154[0x28];
    u16 field_17C;
    u8 unknown_17E[0x6];
    f32 field_184;
    u8 unknown_188[0xC];
    s16 field_194;
    u8 unknown_196[0xA];
    s32 field_1A0;
    s32 field_1A4;
};

struct Self_801AD4C0 {
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

#define F_801AD970(o, t, off) (*(t *)((u8 *)(o) + (off)))

struct Pkt_801AD970 {
    Vec pos;
    u16 owner;
    s32 first;
    s32 more;
    u8 pad18[0x1C - 0x18];
    u8 count;
    f32 f20;
};

struct YPkt_801AD970 {
    Vec pos;
    u16 owner;
    s32 first;
    s32 more;
    s32 pad_18;
    u32 pad_1C;
    f32 pad_20;
};

struct VBase_801AD970 { u8 pad[0x18]; };

struct Mylla_801AD970 : VBase_801AD970 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12();
    u8 pad1C[0x38 - 0x1C];
    Vec pos;
};

struct Res_801AD970 { u8 pad[0xA8]; s32 fA8; s32 fAC; };

struct Game_801AD970 { u8 pad[0x42C]; Res_801AD970 *res; s32 f430; };

extern "C" {
u16 get_entity_id(void *);
void *find_entity_by_id(u16 id);
u8 *TPhotonMagicSquare__ct(u8 *arg0, saddr arg1, s32 arg2, saddr arg3, s32 arg4, f32 farg0);
s32 rotate_matrix_y(int, int);
}
void queue_photon_blast_hit(u32 identity, s32 kind, s32 allow_duplicate, f32 scale);
extern NJS_ARGB saved_model_draw_color;
extern NJS_ARGB model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void spawn_photon_blast_opening_effects(s32 arg0, s32 arg1);
extern "C" {
void sub_801AD4A8__12TPhotonMyllaFv(void* a0);
void TPhotonRainbow__ct(void *, void *, void *, s32);
const char *TPhotonMylla__class_name = "TPhotonMylla";

static const YPkt_801AD970 photon_mylla_packet_template = { { 0.0f, 0.0f, 0.0f }, 0, 0, 0, 0, 0x4000000, 1.0f };

extern s32 __vt__12TPhotonMylla[];
extern Game_801AD970 *photon_blast_shared_resource;
void *TPhotonMylla__ct(Mylla_801AD970 *self, Pkt_801AD970 *pkt);

void TPhotonMylla::sub_801AD4A8() { *(float *)&this->m_184 = 0.0f; *(float*)((char*)this + 0x188) = 0.0f; this->m_18c = 0.0f; *(float *)&this->unk_190 = 0.0f; }

#pragma push
#pragma opt_common_subs off
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_B8_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_B8) == 0xB8);
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_14C_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_14C) == 0x14C);
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_150_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_150) == 0x150);
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_17C_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_17C) == 0x17C);
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_184_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_184) == 0x184);
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_194_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_194) == 0x194);
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_1A0_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_1A0) == 0x1A0);
LAYOUT_ASSERT(RecoveredFields_801AD5D8_arg0_1A4_offset, offsetof(RecoveredFields_801AD5D8_arg0, field_1A4) == 0x1A4);

void TPhotonMylla::render() {
    Self_801AD4C0 *self = (Self_801AD4C0 *)this;
    if (*(s32 *)&this->m_1a0 != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
        push_matrix();
        translate_matrix(0, self->pos.x, self->pos.y, self->pos.z);
        rotate_matrix_y(0, this->rotation_y);
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        set_motion_packed_rotation();
        set_material_alpha_compare_reference(0);
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
        ((TPhotonBlastSummon *)self)->set_photon_blast_joint_callback();
        ((TObjMotion *)self)->draw();
        clear_motion_packed_rotation();
        set_material_alpha_compare_reference(0xBF);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        ((TPhotonBlastSummon *)self)->clear_photon_blast_joint_callback();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonMylla::run_task() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_801AD5D8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_801AD5D8, spC) == 0x4);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_801AD5D8, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_801AD5D8, sp18) == 0x10);
    LAYOUT_ASSERT(sp20_offset, offsetof(Stack_801AD5D8, sp20) == 0x18);
    LAYOUT_ASSERT(sp24_offset, offsetof(Stack_801AD5D8, sp24) == 0x1C);
    LAYOUT_ASSERT(sp2C_offset, offsetof(Stack_801AD5D8, sp2C) == 0x24);
    LAYOUT_ASSERT(sp30_offset, offsetof(Stack_801AD5D8, sp30) == 0x28);
    Stack_801AD5D8 stack;
    f32 temp_f1_2;
    u8 *entity;
    u8 *photon_magic_square;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *temp_r3_5;
    if (((s32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4 == 0x32) && ((s32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A0 == 0)) {
        ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A0 = 1;
        entity = (u8 *)(find_entity_by_id(((RecoveredFields_801AD5D8_arg0 *)arg0)->field_17C));
        if (entity != NULL) {
            VecCopy((Vec *)(&stack.sp2C), (const Vec *)(entity + 0x38));
        }
        stack.sp30 += 30.0f;
        photon_magic_square = (u8 *)TObject::operator new(0xD0);
        if (photon_magic_square != NULL) {
            TPhotonMagicSquare__ct((u8 *)photon_magic_square, (saddr)arg0, 5, (saddr)&stack.sp2C, 0xAA, 0.5f);
        }
    }
    if ((100.0f == (f32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4) && ((s16) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_B8 == 1)) {
        ((TPhotonBlastSummon *)arg0)->begin_photon_summon_camera(3);
        ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4 = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        ((TPhotonBlastSummon *)arg0)->spawn_photon_blast_attachment_effects(5);
    }
    ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_194 = (s16) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_B8;
    ((TPhotonBlastSummon *)arg0)->update_state();
    ((TObjMotion *)arg0)->advance_animation();
    ((TPhotonBlastSummon *)arg0)->update_photon_blast_attachments();
    ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_14C = (s16) (((RecoveredFields_801AD5D8_arg0 *)arg0)->field_14C + 0xF);
    ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_14C = (s16) (u8) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_14C;
    ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4 = (s32) (((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4 + 1);
    if (118.0f == (f32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4) {
        temp_r3_3 = (u8 *)(find_entity_by_id(((RecoveredFields_801AD5D8_arg0 *)arg0)->field_17C));
        if (temp_r3_3 != NULL) {
            VecCopy((Vec *)(&stack.sp20), (const Vec *)(temp_r3_3 + 0x38));
        }
        stack.sp24 += 45.0f;
        spawn_particle_effect((const Vec *)&stack.sp20, 0x174);
        spawn_particle_effect((const Vec *)&stack.sp20, 0x175);
    }
    if (120.0f == (f32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4) {
        temp_r3_4 = (u8 *)(find_entity_by_id(((RecoveredFields_801AD5D8_arg0 *)arg0)->field_17C));
        if (temp_r3_4 != NULL) {
            VecCopy((Vec *)(&stack.sp14), (const Vec *)(temp_r3_4 + 0x38));
        }
        stack.sp18 += 45.0f;
        spawn_particle_effect((const Vec *)&stack.sp14, 0x169);
    }
    if (122.0f == (f32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4) {
        temp_r3_5 = (u8 *)(find_entity_by_id(((RecoveredFields_801AD5D8_arg0 *)arg0)->field_17C));
        if (temp_r3_5 != NULL) {
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(temp_r3_5 + 0x38));
        }
        stack.spC += 45.0f;
        spawn_particle_effect((const Vec *)&stack.sp8, 0x169);
        if (temp_r3_5 != NULL) {
            queue_photon_blast_hit((get_entity_id(temp_r3_5)), 5, 0, (f32) (((RecoveredFields_801AD5D8_arg0 *)arg0)->field_150));
        }
    }
    if ((f32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A4 > 116.0f) {
        temp_f1_2 = ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_184;
        if (temp_f1_2 > -1.0f) {
            ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_184 = (f32) (temp_f1_2 - 0.15f);
        }
    }
    if ((s32) ((RecoveredFields_801AD5D8_arg0 *)arg0)->field_1A0 != 0) {
        play_persistent_sound(0x4002462F, (saddr)arg0, (u32)(0U), 0, 0);
    }
}
#pragma pop

TPhotonMylla::~TPhotonMylla() {
    update_if_active();
    free_photon();
}

TObjMotionAction photon_mylla_action_table[2] = {
    {MOTION_MODE_ONCE, 0, 6, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 0xD, 1.0f, 0},
};

void *TPhotonMylla__ct(Mylla_801AD970 *self, Pkt_801AD970 *pkt) {
    Vec v;
    u8 *o;
    u8 *owner;
    __ct__18TPhotonBlastSummonFv(self);
    *(void **)((u8 *)self + 0x18) = __vt__12TPhotonMylla;
    F_801AD970(self, const char *, 0) = TPhotonMylla__class_name;
    F_801AD970(self, s32, 0x138) = 5;
    VecCopy((Vec *)&self->pos, (const Vec *)pkt);
    F_801AD970(self, u16, 0x17C) = pkt->owner;
    F_801AD970(self, u8 *, 0x180) = (u8 *)find_entity_by_id(F_801AD970(self, u16, 0x17C));
    if (F_801AD970(self, u8 *, 0x180) != NULL) {
        F_801AD970(self, s32, 0x60) = F_801AD970(F_801AD970(self, u8 *, 0x180), s32, 0x60);
    }
    F_801AD970(self, s32, 0x34) = photon_blast_shared_resource->res->fA8;
    F_801AD970(self, s32, 0x24) = photon_blast_shared_resource->res->fAC;
    ((TObjMotion *)self)->set_field_d8((saddr)photon_mylla_action_table);
    ((TObjMotion *)self)->set_field_dc(photon_blast_shared_resource->f430);
    F_801AD970(self, s16, 0xB8) = 1;
    ((TObjMotion *)self)->set_animation(F_801AD970(self, s16, 0xB8));
    ((TObjMotion *)self)->set_field_b8(F_801AD970(self, s16, 0xB8));
    F_801AD970(self, s16, 0x194) = 1;
    F_801AD970(self, s32, 0x198) = pkt->first;
    F_801AD970(self, s32, 0x19C) = pkt->more;
    F_801AD970(self, s32, 0x1A0) = 0;
    {
        YPkt_801AD970 y = photon_mylla_packet_template;
        y.pos.x = self->pos.x;
        y.pos.y = self->pos.y;
        y.pos.z = self->pos.z;
        y.owner = F_801AD970(self, u16, 0x17C);
        y.first = F_801AD970(self, s32, 0x198);
        y.more = F_801AD970(self, s32, 0x19C);
        o = (u8 *)TObject::operator new(0x1A8);
        if (o != NULL) {
            TPhotonYoulla__ct((TPhotonYoulla *)o, (u8 *)&y);
        }
    }
    ((void (*)(void *, u8))sub_801AD4A8__12TPhotonMyllaFv)(self, pkt->count);
    F_801AD970(self, s32, 0x134) = 3;
    self->m12();
    F_801AD970(self, s32, 0x1A4) = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON:
    case AREA_DE_ROL_LE:
    case AREA_VOL_OPT:
    case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON:
    case AREA_OLGA_FLOW:
    case AREA_BARBA_RAY:
    case AREA_GOL_DRAGON:
        o = (u8 *)TObject::operator new(0xAC);
        if (o != NULL) {
            TPhotonRainbow__ct(o, self, &self->pos, 1);
        }
        break;
    default:
        o = (u8 *)TObject::operator new(0xAC);
        if (o != NULL) {
            TPhotonRainbow__ct(o, self, &self->pos, 0);
        }
        break;
    }
    if (F_801AD970(self, s32, 0x19C) == 1) {
        F_801AD970(self, u32, 0x154) |= 1;
    }
    F_801AD970(self, f32, 0x150) = pkt->f20;
    if (F_801AD970(self, s32, 0x198) == 0) {
        ((TObjMotion *)self)->set_field_b8(0);
        ((TPhotonBlastSummon *)self)->begin_photon_summon_camera(3);
        F_801AD970(self, s32, 0x198) = 1;
        F_801AD970(self, s16, 0x194) = 0;
        F_801AD970(self, s32, 0x1A0) = 1;
        owner = (u8 *)find_entity_by_id(F_801AD970(self, u16, 0x17C));
        if (owner != NULL) {
            VecCopy((Vec *)&v, (const Vec *)(owner + 0x38));
        }
        v.y += 30.0f;
        o = (u8 *)TObject::operator new(0xD0);
        if (o != NULL) {
            TPhotonMagicSquare__ct((u8 *)o, (saddr)self, 5, (saddr)&v, 0xAA, 0.5f);
        }
        ((TPhotonBlastSummon *)self)->spawn_photon_blast_attachment_effects(5);
        play_cue_stream_file((saddr)"maila2.adx");
    } else {
        spawn_photon_blast_opening_effects(5, F_801AD970(self, u16, 0x17C));
        play_cue_stream_file((saddr)"maila.adx");
    }
    return self;
}


int lbl_805D5D50;
void TObjPlayer__sub_801ADC6C(void) { lbl_805D5D50 = 0; }

void TObjPlayer__sub_801ADC78(void) {  }
}
