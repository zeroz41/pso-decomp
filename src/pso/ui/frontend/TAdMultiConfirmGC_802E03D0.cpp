#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TUnk_804E3008.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/object/ambient/TObjFish.h"
#pragma defer_codegen on
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/npc/TNpcPlayer_8028B810.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar_8028B714.h"
#include "pso/ui/frontend/TAdMultiConfirmGC_802E03D0.h"

#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/npc/TNpcPlayer.h"

#include "pso/ui/frontend/TAdMultiConfirmGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/ambient/TObjFish.h"


struct Obj_802E0CB0 {
    u8 pad0[0x38]; f32 x, y, z; u8 pad44[0x5C - 0x44]; s32 rx, ry, rz;
    u8 pad68[0x104 - 0x68]; s32 mode; s32 idx; u8 pad10c[0x11C - 0x10C]; s32 f11C;
};

extern "C" {
extern const char lbl_804728D0[];
const char lbl_804728D0[] = "TAdChrSelPlayerGC";

void sub_802E0CB0__13TUnk_804E3008Fv(Obj_802E0CB0 *o);
}

struct Stack_802E0468
{
  f32 sp8;
  f32 spC;
  f32 sp10;
  f32 sp14;
};

extern "C" {
void play_phase_transition_sound__10TObjPlayerFl(s32);
void set_chunk_material_override_pair(s32, s32);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

typedef struct Stack_802E0468 Stack_802E0468;

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);

extern TObjMotionAction lbl_804E2F78[9];
u8 *TAdMultiPlyChrSelectGC__resource_bundle;

s32 copy_player_visual_record(void *, void *);
u8 *get_entry__23TAdSinglePlyChrSelectGCFi(int);
u8 *get_char_table_entry__23TAdSinglePlyChrSelectGCFi(int);
#define F(o, t) (*(t *)(arg0 + (o)))

}

TUnk_804E3008 *multi_chr_select_player_slot_table[4] = { NULL };

extern "C" {

#pragma push
#pragma fp_contract on
#pragma pool_data off

void TUnk_804E3008::sub_802E0CB0() {
    ((Obj_802E0CB0 *)this)->f11C = 0;
    switch (((Obj_802E0CB0 *)this)->mode) {
    case 0:
        ((Obj_802E0CB0 *)this)->x = 17.0f;
        ((Obj_802E0CB0 *)this)->y = -10.5f;
        ((Obj_802E0CB0 *)this)->z = -40.0f;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = 0xF3D5;
        ((Obj_802E0CB0 *)this)->rz = 0;
        ((Obj_802E0CB0 *)this)->f11C = 1;
        break;
    case 1:
    case 2:
        ((Obj_802E0CB0 *)this)->x = 0.0f;
        ((Obj_802E0CB0 *)this)->y = -10.5f;
        ((Obj_802E0CB0 *)this)->z = -40.0f;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = 0xF3D5;
        ((Obj_802E0CB0 *)this)->rz = 0;
        ((Obj_802E0CB0 *)this)->f11C = 1;
        break;
    case 3:
        ((Obj_802E0CB0 *)this)->x = 28.0f * ((Obj_802E0CB0 *)this)->idx + -14.0f;
        ((Obj_802E0CB0 *)this)->y = -10.0f;
        ((Obj_802E0CB0 *)this)->z = -110.0f;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = 182.04445f * (7.25f - 14.5f * ((Obj_802E0CB0 *)this)->idx);
        ((Obj_802E0CB0 *)this)->rz = 0;
        break;
    case 4:
        ((Obj_802E0CB0 *)this)->x = 19.0f * ((Obj_802E0CB0 *)this)->idx + -19.0f;
        ((Obj_802E0CB0 *)this)->y = -10.0f;
        ((Obj_802E0CB0 *)this)->z = -110.0f;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = 182.04445f * (9.8f - 9.8f * ((Obj_802E0CB0 *)this)->idx);
        ((Obj_802E0CB0 *)this)->rz = 0;
        break;
    case 5: {
        f32 xs[4] = { -21.5f, -8.0f, 7.0f, 23.5f };
        f32 zs[4] = { -110.0f, -118.56f, -110.0f, -118.56f };
        f32 rs[4] = { 11.6f, 3.86f, -3.64f, -11.21f };
        ((Obj_802E0CB0 *)this)->x = xs[((Obj_802E0CB0 *)this)->idx];
        ((Obj_802E0CB0 *)this)->y = -10.0f;
        ((Obj_802E0CB0 *)this)->z = zs[((Obj_802E0CB0 *)this)->idx];
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = 182.04445f * rs[((Obj_802E0CB0 *)this)->idx];
        ((Obj_802E0CB0 *)this)->rz = 0;
        break;
    }
    }
}
#pragma pop

void TAdMultiPlyChrSelectGC::set_index_and_close_status(s32 arg1) {
    *(s32 *)((s8 *)this + 0x104) = arg1;
    ((s32 (*)(void *, s32))sub_802E0CB0__13TUnk_804E3008Fv)(this, *(s32 *)((s8 *)this + 0x104));
    uaddr index = ((u32)TAdPlyStatusGC::get_index());
    if (index != 0U) {
        ((TAdPlyStatusGC *)index)->close_window(arg1);
    }
}

void TAdMultiPlyChrSelectGC::set_status_value(s32 arg1) {
    void *index;
    *(s32 *)((s8 *)this + 0x110) = arg1;
    index = (void *)TAdPlyStatusGC::get_index();
    if (index != 0U) {
        TAdPlyStatusGC::set_status_index((saddr)index, (int)(*(s32 *)((s8 *)this + 0x110)));
    }
}

TUnk_804E3008::~TUnk_804E3008() {
    if (multi_chr_select_player_slot_table[slot] != NULL) {
        multi_chr_select_player_slot_table[slot] = NULL;
    }
    if (joint_matrices != NULL) {
        mem_free(joint_matrices);
        joint_matrices = NULL;
    }
    if (m_170 != NULL) {
        free_chcr_resources((u8 *)m_170, 1);
        m_170 = NULL;
        u32 status = (u32)TAdPlyStatusGC::get_index();
        if (status != 0) {
            TAdPlyStatusGC::set_status_param((int)status, (saddr)m_170);
        }
    }
}

void TUnk_804E3008::run_task() {
    u8 *arg0 = (u8 *)this;
    void *p;
    void *idx;
    s32 t;
    switch (F(0xFC, s32)) {
    case 0:
        if (F(0x170, void *) != NULL) {
            free_chcr_resources((u8 *)(F(0x170, void *)), 1);
            F(0x170, void *) = NULL;
        }
        if (F(0x100, s32) != 0) {
            F(0xFC, s32) = F(0x100, s32) - 1;
            F(0x100, s32) = 0;
        }
        break;
    case 1:
        if (F(0x170, void *) != NULL) {
            free_chcr_resources((u8 *)(F(0x170, void *)), 1);
            F(0x170, void *) = NULL;
        }
        if (F(0x100, s32) != 0) {
            F(0xFC, s32) = F(0x100, s32) - 1;
            F(0x100, s32) = 0;
            break;
        }
        switch (F(0x104, s32)) {
        case 0:
            copy_player_visual_record(arg0 + 0x120, (u8 *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF) + 0x370);
            p = ::operator new(0x4AC);
            if (p != NULL) {
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (saddr)(arg0 + 0x120), 0);
            }
            F(0x170, void *) = p;
            F(0x60, s32) = 0xF3D5;
            break;
        case 1:
            copy_player_visual_record(arg0 + 0x120, get_entry__23TAdSinglePlyChrSelectGCFi(F(0x110, s32)) + 0x370);
            p = ::operator new(0x4AC);
            if (p != NULL) {
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (saddr)(arg0 + 0x120), 0);
            }
            F(0x170, void *) = p;
            F(0x60, s32) = 0xF3D5;
            break;
        case 2:
            copy_player_visual_record(arg0 + 0x120, (u8 *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF) + 0x370);
            p = ::operator new(0x4AC);
            if (p != NULL) {
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (saddr)(arg0 + 0x120), 0);
            }
            F(0x170, void *) = p;
            F(0x60, s32) = 0xF3D5;
            break;
        case 3:
        case 4:
        case 5:
            copy_player_visual_record(arg0 + 0x120, get_char_table_entry__23TAdSinglePlyChrSelectGCFi(F(0x10C, s32)) + 0x370);
            p = ::operator new(0x4AC);
            if (p != NULL) {
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (saddr)(arg0 + 0x120), (s32)(F(0x10C, s32)));
            }
            F(0x170, void *) = p;
            break;
        }
        ((TUnk_804E3008 *)arg0)->sub_802E0784();
        F(0xFC, s32) = 2;
        break;
    case 2:
        if (F(0x100, s32) != 0) {
            if (F(0x170, void *) != NULL) {
                free_chcr_resources((u8 *)(F(0x170, void *)), 1);
                F(0x170, void *) = NULL;
            }
            F(0xFC, s32) = F(0x100, s32) - 1;
            F(0x100, s32) = 0;
        } else if (((TChCrLoadAfs *)(F(0x170, void *)))->is_unloaded() != 0) {
            F(0xFC, s32) = 3;
            F(0x118, s32) = 0;
        }
        break;
    case 3:
        if (F(0x100, s32) != 0) {
            if (F(0x170, void *) != NULL) {
                free_chcr_resources((u8 *)(F(0x170, void *)), 1);
                F(0x170, void *) = NULL;
            }
            F(0xFC, s32) = F(0x100, s32) - 1;
            F(0x100, s32) = 0;
        } else {
            if (F(0x11C, s32) == 1) {
                F(0x60, s32) = F(0x60, s32) - 0x100;
            }
            F(0x118, s32) = F(0x118, s32) + 1;
            t = F(0x118, s32);
            if (t == 0x384 || t == 0x708) {
                TAdMultiConfirmGC::set_cursor_index_1(arg0);
            } else if (t == 0x546) {
                TAdMultiConfirmGC::set_cursor_index_2(arg0);
            }
            if (F(0x118, s32) == 0x8CA) {
                TAdMultiConfirmGC::reset_cursor(arg0);
                F(0x118, s32) = 0;
            }
            ((TObjMotion *)arg0)->advance_animation();
        }
        break;
    }
    idx = (void *)TAdPlyStatusGC::get_index();
    if (idx != NULL) {
        ((TAdPlyStatusGC *)idx)->set_load_state(F(0xFC, s32));
        TAdPlyStatusGC::set_status_param((saddr)idx, (saddr)(F(0x170, void *)));
    }
}

void TUnk_804E3008::sub_802E0784() {
    this->set_field_d8((saddr)lbl_804E2F78);
    this->set_field_dc((int) (*(s32 *)((s8 *)TAdMultiPlyChrSelectGC__resource_bundle + 0x430)));
    set_cursor_index(0);
    set_animation((this->requested_action));
}

void TUnk_804E3008::set_cursor_index(s32 arg1) {
    s16 temp_r4;

    this->requested_action = (s16) (arg1 * 3);
    temp_r4 = this->requested_action;
    if ((temp_r4 < 0) || (temp_r4 > 8)) {
        this->requested_action = 0;
    }
    if (this->m_154 & 2) {
        this->requested_action = (this->requested_action + 1);
        if ((s32) this->m_151 == 6) {
            this->requested_action = (this->requested_action + 1);
        }
    }
}

void TUnk_804E3008::render() {
    if (state == 3) {
        update_chara_making();
    }
}

void TUnk_804E3008::update_chara_making() {
    push_matrix();
    post_translate_matrix((u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>((saddr)m_170->get_status_sub()));
    draw_model_with_arg((void *)m_170->get_field_4a4());
    push_matrix_from((void *)get_item_ptr(0x3A));
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>((saddr)m_170->get_status_data()));
    m_170->get_field_4a0();
    ((s32 (*)())play_phase_transition_sound__10TObjPlayerFl)();
    pop_matrix();
    if (m_170->get_field_49c() != 0U) {
        push_matrix_from((void *)get_item_ptr(0x3B));
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>((saddr)m_170->get_chara_making_data()));
        TCharaMaking::enable_making();
        m_170->get_field_49c();
        ((s32 (*)())play_phase_transition_sound__10TObjPlayerFl)();
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    if (m_170->get_field_498() != 0U) {
        push_matrix_from((void *)get_item_ptr(0x3B));
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>((saddr)m_170->get_chara_making_data()));
        TCharaMaking::enable_making();
        TObjPlayer__sub_802E0580(this, m_170->get_field_498(), visual_record);
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    pop_matrix();
}

void TUnk_804E3008::draw_model_with_arg(void *model) {
    this->model = model;
    set_motion_interpolation_flag();
    draw_saving_joints_checked();
}

void TObjPlayer__sub_802E0580(void * _w0, int _w1, void * _w2) {
    ((s32 (*)(f32))TObjPlayer__sub_802E0468)(1.0f);
}

void TObjPlayer__sub_802E0468(long long arg1, u8 *arg2, f32 farg0) {
  Stack_802E0468 stack;
  int new_var;
  saved_model_render_flags = model_render_flags;
  saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
  saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
  model_render_flags |= 0x10;
  new_var = 1;
  if (farg0 < 1.0f)
  {
    set_chunk_material_override_pair(-new_var, 0x800);
  }
  stack.sp8 = farg0;
  stack.spC = 0.003921569f * ((f32) (*((s16 *) (((s8 *) arg2) + 0x42))));
  stack.sp10 = 0.003921569f * ((f32) (*((s16 *) (((s8 *) arg2) + 0x44))));
  stack.sp14 = 0.003921569f * ((f32) (*((s16 *) (((s8 *) arg2) + 0x46))));
  set_constant_material((const NJS_ARGB *)((&stack.sp8)));
  TObjPlayer::play_phase_transition_sound(arg1);
  chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
  chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
  model_render_flags = saved_model_render_flags;
}

bool fn_802E0454(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0xFC) == 3;
}

void TAdMultiConfirmGC__sub_802E0448(void* p) { *(s32*)((char*)p + 0x11c) = 1; }

int TAdMultiConfirmGC::reset_cursor(void* p) { return ((int (*)(void *, int))set_cursor_index__13TUnk_804E3008Fl)(p, 0); }

int TAdMultiConfirmGC::set_cursor_index_1(void* p) { return ((int (*)(void *, int))set_cursor_index__13TUnk_804E3008Fl)(p, 1); }

int TAdMultiConfirmGC::set_cursor_index_2(void* p) { return ((int (*)(void *, int))set_cursor_index__13TUnk_804E3008Fl)(p, 2); }

void TAdMultiConfirmGC__sub_802E03D0(void* p) { *(s32*)((char*)p + 0x118) = 0; }

}

TObjMotionAction lbl_804E2F78[9] = {
    { 1, 0, 0x21, 1.0f, 0 },
    { 1, 0, 0x1, 1.0f, 0 },
    { 1, 0, 0x0, 1.0f, 0 },
    { 1, 0, 0x1F, 1.0f, 0 },
    { 1, 0, 0x20, 1.0f, 0 },
    { 1, 0, 0x1E, 1.0f, 0 },
    { 1, 0, 0x2F, 1.0f, 0 },
    { 1, 0, 0x30, 1.0f, 0 },
    { 1, 0, 0x2E, 1.0f, 0 },
};
