#include "pso/system/ChunkMaterialState.h"
#pragma defer_codegen on
#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TObjBoss5Pillar_8028B810.h"
#include "pso/boss/TObjBoss5Pillar_8028B714.h"
#include "pso/misc/obj_band.h"
#include "pso/ui/TAdMultiConfirmGC_802E03D0.h"
#include "pso/ui/TUnk_804E3008.h"
#include "pso/TChCrLoadAfs.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdMultiConfirmGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TCharaMaking.h"
#include "pso/ui/TAdPlyStatusGC.h"

struct Obj_802E0CB0 {
    u8 pad0[0x38]; f32 x, y, z; u8 pad44[0x5C - 0x44]; s32 rx, ry, rz;
    u8 pad68[0x104 - 0x68]; s32 mode; s32 idx; u8 pad10c[0x11C - 0x10C]; s32 f11C;
};

extern "C" {
extern const char lbl_804728D0[];
const char lbl_804728D0[] = "TAdChrSelPlayerGC";

void *get_index__14TAdPlyStatusGCFv();
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
s32 push_matrix_from();
s32 push_matrix();
s32 pop_matrix();
s32 set_global_param__8TObjFishFl();

}

struct RecoveredGlobal_802E0784_lbl_804E2F78 {
    s32 value;
    u8 remaining[0x8C];
};

extern "C" {
extern RecoveredGlobal_802E0784_lbl_804E2F78 lbl_804E2F78;
extern u8 *TAdMultiPlyChrSelectGC__resource_bundle;
typedef char RecoveredGlobal_802E0784_lbl_804E2F78_size[sizeof(RecoveredGlobal_802E0784_lbl_804E2F78) == 0x90 ? 1 : -1];

s32 copy_player_visual_record(void *, void *);
s32 advance_animation_playback(void *);
u8 *get_entry__23TAdSinglePlyChrSelectGCFi(int);
u8 *get_char_table_entry__23TAdSinglePlyChrSelectGCFi(int);
u8 *get_char_index__23TAdSinglePlyChrSelectGCFUi(int);
void set_load_state__14TAdPlyStatusGCFPvi(u8 *arg0, s32 arg1);
#define F(o, t) (*(t *)(arg0 + (o)))

}

struct RecoveredGlobal_802E0B60_lbl_804E2F68 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_802E0B60_lbl_804E3008 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
void *__dt__10TObjMotionFv(void *arg0, s16 arg1);
void mem_free(void *p);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_802E0B60_lbl_804E2F68 multi_chr_select_player_slot_table;
extern RecoveredGlobal_802E0B60_lbl_804E3008 multi_chr_select_player_actor_ops;
typedef char RecoveredGlobal_802E0B60_lbl_804E2F68_size[sizeof(RecoveredGlobal_802E0B60_lbl_804E2F68) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_802E0B60_lbl_804E3008_size[sizeof(RecoveredGlobal_802E0B60_lbl_804E3008) == 0x38 ? 1 : -1];

__declspec(section ".sdata2") void *const lbl_805DE8A8[1] = {
    (void *)0x3f800000,
};
__declspec(section ".sdata2") void *const lbl_805DE8AC[1] = {
    (void *)0x3b808081,
};
__declspec(section ".sdata2") void *const lbl_805DE8B0[1] = {
    (void *)0x41880000,
};
__declspec(section ".sdata2") void *const lbl_805DE8B4[1] = {
    (void *)0xc1280000,
};
__declspec(section ".sdata2") void *const lbl_805DE8B8[1] = {
    (void *)0xc2200000,
};
__declspec(section ".sdata2") void *const lbl_805DE8BC[1] = {
    (void *)0x0,
};
__declspec(section ".sdata2") void *const lbl_805DE8C0[1] = {
    (void *)0xc1600000,
};
__declspec(section ".sdata2") void *const lbl_805DE8C4[1] = {
    (void *)0x41e00000,
};
__declspec(section ".sdata2") void *const lbl_805DE8C8[1] = {
    (void *)0xc1200000,
};
__declspec(section ".sdata2") void *const lbl_805DE8CC[1] = {
    (void *)0xc2dc0000,
};
__declspec(section ".sdata2") void *const lbl_805DE8D0[1] = {
    (void *)0x43360b61,
};
__declspec(section ".sdata2") void *const lbl_805DE8D4[1] = {
    (void *)0x40e80000,
};
__declspec(section ".sdata2") void *const lbl_805DE8D8[1] = {
    (void *)0x41680000,
};
#define lbl_805DE8A8 (*(const f32 *)lbl_805DE8A8)
#define lbl_805DE8AC (*(const f32 *)lbl_805DE8AC)
#define lbl_805DE8B0 (*(const f32 *)lbl_805DE8B0)
#define lbl_805DE8B4 (*(const f32 *)lbl_805DE8B4)
#define lbl_805DE8B8 (*(const f32 *)lbl_805DE8B8)
#define lbl_805DE8BC (*(const f32 *)lbl_805DE8BC)
#define lbl_805DE8C0 (*(const f32 *)lbl_805DE8C0)
#define lbl_805DE8C4 (*(const f32 *)lbl_805DE8C4)
#define lbl_805DE8C8 (*(const f32 *)lbl_805DE8C8)
#define lbl_805DE8CC (*(const f32 *)lbl_805DE8CC)
#define lbl_805DE8D0 (*(const f32 *)lbl_805DE8D0)
#define lbl_805DE8D4 (*(const f32 *)lbl_805DE8D4)
#define lbl_805DE8D8 (*(const f32 *)lbl_805DE8D8)

#pragma push
#pragma fp_contract on
#pragma pool_data off

void TUnk_804E3008::sub_802E0CB0() {
    ((Obj_802E0CB0 *)this)->f11C = 0;
    switch (((Obj_802E0CB0 *)this)->mode) {
    case 0:
        ((Obj_802E0CB0 *)this)->x = lbl_805DE8B0;
        ((Obj_802E0CB0 *)this)->y = lbl_805DE8B4;
        ((Obj_802E0CB0 *)this)->z = lbl_805DE8B8;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = 0xF3D5;
        ((Obj_802E0CB0 *)this)->rz = 0;
        ((Obj_802E0CB0 *)this)->f11C = 1;
        break;
    case 1:
    case 2:
        ((Obj_802E0CB0 *)this)->x = lbl_805DE8BC;
        ((Obj_802E0CB0 *)this)->y = lbl_805DE8B4;
        ((Obj_802E0CB0 *)this)->z = lbl_805DE8B8;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = 0xF3D5;
        ((Obj_802E0CB0 *)this)->rz = 0;
        ((Obj_802E0CB0 *)this)->f11C = 1;
        break;
    case 3:
        ((Obj_802E0CB0 *)this)->x = lbl_805DE8C4 * ((Obj_802E0CB0 *)this)->idx + lbl_805DE8C0;
        ((Obj_802E0CB0 *)this)->y = lbl_805DE8C8;
        ((Obj_802E0CB0 *)this)->z = lbl_805DE8CC;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = lbl_805DE8D0 * (lbl_805DE8D4 - lbl_805DE8D8 * ((Obj_802E0CB0 *)this)->idx);
        ((Obj_802E0CB0 *)this)->rz = 0;
        break;
    case 4:
        ((Obj_802E0CB0 *)this)->x = 19.0f * ((Obj_802E0CB0 *)this)->idx + -19.0f;
        ((Obj_802E0CB0 *)this)->y = lbl_805DE8C8;
        ((Obj_802E0CB0 *)this)->z = lbl_805DE8CC;
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = lbl_805DE8D0 * (9.8f - 9.8f * ((Obj_802E0CB0 *)this)->idx);
        ((Obj_802E0CB0 *)this)->rz = 0;
        break;
    case 5: {
        f32 xs[4] = { -21.5f, -8.0f, 7.0f, 23.5f };
        f32 zs[4] = { -110.0f, -118.56f, -110.0f, -118.56f };
        f32 rs[4] = { 11.6f, 3.86f, -3.64f, -11.21f };
        ((Obj_802E0CB0 *)this)->x = xs[((Obj_802E0CB0 *)this)->idx];
        ((Obj_802E0CB0 *)this)->y = lbl_805DE8C8;
        ((Obj_802E0CB0 *)this)->z = zs[((Obj_802E0CB0 *)this)->idx];
        ((Obj_802E0CB0 *)this)->rx = 0;
        ((Obj_802E0CB0 *)this)->ry = lbl_805DE8D0 * rs[((Obj_802E0CB0 *)this)->idx];
        ((Obj_802E0CB0 *)this)->rz = 0;
        break;
    }
    }
}
#pragma pop

void TAdMultiPlyChrSelectGC::set_index_and_close_status(s32 arg1) {
    *(s32 *)((s8 *)this + 0x104) = arg1;
    ((s32 (*)(void *, s32))sub_802E0CB0__13TUnk_804E3008Fv)(this, *(s32 *)((s8 *)this + 0x104));
    u32 temp_r3 = ((u32)get_index__14TAdPlyStatusGCFv());
    if (temp_r3 != 0U) {
        ((TAdPlyStatusGC *)temp_r3)->close_window(arg1);
    }
}

void TAdMultiPlyChrSelectGC::set_status_value(s32 arg1) {
    void *temp_r3;
    *(s32 *)((s8 *)this + 0x110) = arg1;
    temp_r3 = get_index__14TAdPlyStatusGCFv();
    if (temp_r3 != 0U) {
        TAdPlyStatusGC::set_status_index((int)temp_r3, (int)(*(s32 *)((s8 *)this + 0x110)));
    }
}

u8 *__dt__13TUnk_804E3008Fv(u8 *arg0, s16 arg1) {
    s32 temp_r4;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &multi_chr_select_player_actor_ops.value;
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x10C) * 4;
        if ((u32) *(s32 *)((s8 *)&multi_chr_select_player_slot_table.value + temp_r4) != 0U) {
            *(s32 *)((s8 *)&multi_chr_select_player_slot_table.value + temp_r4) = 0;
        }
        temp_r3 = *(u32 *)((s8 *)arg0 + 0xE0);
        if (temp_r3 != 0U) {
            mem_free((void *)temp_r3);
            *(u32 *)((s8 *)arg0 + 0xE0) = 0U;
        }
        temp_r3_2 = ((TUnk_804E3008 *)arg0)->m_170;
        if (temp_r3_2 != 0U) {
            free_chcr_resources((u8 *)temp_r3_2, 1);
            ((TUnk_804E3008 *)arg0)->m_170 = 0U;
            temp_r3_3 = (u32) get_index__14TAdPlyStatusGCFv();
            if (temp_r3_3 != 0U) {
                TAdPlyStatusGC::set_status_param((int)temp_r3_3, (int)((void *) (((TUnk_804E3008 *)arg0)->m_170)));
            }
        }
        __dt__10TObjMotionFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
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
            copy_player_visual_record(arg0 + 0x120, get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF) + 0x370);
            p = ::operator new(0x4AC);
            if (p != NULL) {
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (s32)(arg0 + 0x120), 0);
            }
            F(0x170, void *) = p;
            F(0x60, s32) = 0xF3D5;
            break;
        case 1:
            copy_player_visual_record(arg0 + 0x120, get_entry__23TAdSinglePlyChrSelectGCFi(F(0x110, s32)) + 0x370);
            p = ::operator new(0x4AC);
            if (p != NULL) {
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (s32)(arg0 + 0x120), 0);
            }
            F(0x170, void *) = p;
            F(0x60, s32) = 0xF3D5;
            break;
        case 2:
            copy_player_visual_record(arg0 + 0x120, get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF) + 0x370);
            p = ::operator new(0x4AC);
            if (p != NULL) {
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (s32)(arg0 + 0x120), 0);
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
                p = init_appearance_load_request__10TNpcPlayerFPvPvii((u8 *)p, (u8 *)arg0, (s32)(arg0 + 0x120), (s32)(F(0x10C, s32)));
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
            advance_animation_playback(arg0);
        }
        break;
    }
    idx = get_index__14TAdPlyStatusGCFv();
    if (idx != NULL) {
        set_load_state__14TAdPlyStatusGCFPvi((u8 *)idx, F(0xFC, s32));
        TAdPlyStatusGC::set_status_param((int)idx, (int)(F(0x170, void *)));
    }
}

void TUnk_804E3008::sub_802E0784() {
    this->set_field_d8((s32)&lbl_804E2F78.value);
    this->set_field_dc((int) (*(s32 *)((s8 *)TAdMultiPlyChrSelectGC__resource_bundle + 0x430)));
    set_cursor_index__13TUnk_804E3008Fl(this, 0);
    set_animation((this->m_b8));
}

void TUnk_804E3008::set_cursor_index(s32 arg1) {
    s16 temp_r4;

    this->m_b8 = (s16) (arg1 * 3);
    temp_r4 = this->m_b8;
    if ((temp_r4 < 0) || (temp_r4 > 8)) {
        this->m_b8 = 0;
    }
    if (this->m_154 & 2) {
        this->m_b8 = (this->m_b8 + 1);
        if ((s32) this->m_151 == 6) {
            this->m_b8 = (this->m_b8 + 1);
        }
    }
}

void TObjPlayer::update_chara_making_if_state3() { if (this->m_fc == 3) { update_chara_making(); } }

void TObjPlayer::update_chara_making() {
    u8 *arg0 = (u8 *)this;
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    ((TAdPlyStatusGC *)(this->m_170))->get_status_sub();
    set_global_param__8TObjFishFl();
    draw_model_with_arg((void*)((int) (((TAdPlyStatusGC *)(this->m_170))->get_field_4a4())));
    ((TObjMotion *)arg0)->get_item_ptr(0x3A);
    push_matrix_from();
    ((TAdPlyStatusGC *)(this->m_170))->get_status_data();
    set_global_param__8TObjFishFl();
    ((TAdPlyStatusGC *)(this->m_170))->get_field_4a0();
    ((s32 (*)())play_phase_transition_sound__10TObjPlayerFl)();
    pop_matrix();
    if (((TAdPlyStatusGC *)(this->m_170))->get_field_49c() != 0U) {
        ((TObjMotion *)arg0)->get_item_ptr(0x3B);
        push_matrix_from();
        ((TAdPlyStatusGC *)(this->m_170))->get_chara_making_data();
        set_global_param__8TObjFishFl();
        TCharaMaking::enable_making();
        ((TAdPlyStatusGC *)(this->m_170))->get_field_49c();
        ((s32 (*)())play_phase_transition_sound__10TObjPlayerFl)();
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    if (((TAdPlyStatusGC *)(this->m_170))->get_field_498() != 0U) {
        ((TObjMotion *)arg0)->get_item_ptr(0x3B);
        push_matrix_from();
        ((TAdPlyStatusGC *)(this->m_170))->get_chara_making_data();
        set_global_param__8TObjFishFl();
        TCharaMaking::enable_making();
        TObjPlayer__sub_802E0580(arg0, (int)((int) (((TAdPlyStatusGC *)(this->m_170))->get_field_498())), (u8 *)&this->m_120);
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    pop_matrix();
}

void TObjPlayer::draw_model_with_arg(void* a1) { this->model = a1; set_motion_interpolation_flag(); draw_model_with_callback(); }

void TObjPlayer__sub_802E0580(void * _w0, int _w1, void * _w2) {
    ((s32 (*)(f32))TObjPlayer__sub_802E0468)(lbl_805DE8A8);
}

void TObjPlayer__sub_802E0468(long long arg1, u8 *arg2, f32 farg0) {
  Stack_802E0468 stack;
  int new_var;
  saved_model_render_flags = model_render_flags;
  saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
  saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
  model_render_flags |= 0x10;
  new_var = 1;
  if (farg0 < lbl_805DE8A8)
  {
    set_chunk_material_override_pair(-new_var, 0x800);
  }
  stack.sp8 = farg0;
  stack.spC = lbl_805DE8AC * ((f32) (*((s16 *) (((s8 *) arg2) + 0x42))));
  stack.sp10 = lbl_805DE8AC * ((f32) (*((s16 *) (((s8 *) arg2) + 0x44))));
  stack.sp14 = lbl_805DE8AC * ((f32) (*((s16 *) (((s8 *) arg2) + 0x46))));
  set_constant_material((const NJS_ARGB *)((&stack.sp8)));
  play_phase_transition_sound__10TObjPlayerFl(arg1);
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
