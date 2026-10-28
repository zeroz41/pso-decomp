#include "types.h"
#include "pso/misc/TOMineTrap_8016F6F8.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TOMine.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOMineTrap.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_801711D0_lbl_804B2F2C { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_801711D0_lbl_804B2F2C_size[sizeof(RecoveredGlobal_801711D0_lbl_804B2F2C) == 0x10 ? 1 : -1];

struct RecoveredFields_80170F0C_arg0
{
  u8 unknown_0[0x2A8];
  s32 field_2A8;
  u8 unknown_2AC[0xA0];
  f32 field_34C;
  u8 unknown_350[0xC];
  u16 field_35C;
};

struct VBase_801710E4 { char pad[0x18]; };

struct VObj_801710E4 : VBase_801710E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Obj_80171278 { s32 f00; u8 pad0[0x14]; u32 vptr; u8 pad1[0x14]; u32 flags30; u8 pad2[0x30C]; s32 f340; u8 pad3[8]; f32 f34C; f32 f350; s32 f354; f32 f358; u16 f35C; u8 pad4[2]; f32 f360; f32 f364; f32 f368; f32 f36C; s32 f370; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_801711D0_lbl_804B2F2C mine_resource_desc;
extern u32 lbl_805D5A50;
u16 find_nearest_visible_player(void *, int, f32);
void *get_player_by_client_id(s32 i);
void rotate_matrix_y(int, int);
void push_matrix();
void post_translate_matrix(void *);
void set_chunk_material_color__13TUnk_80494AE0Fv(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805DB854;
extern const f32 lbl_805DB858;
void __ct__13TUnk_804806E8FP7TObject(void *);
void obj_setFlags30(void *, u32);
extern s32 __vt__6TOMine[];
extern s32 TOMine__name;
extern const f32 lbl_805DB85C;
Obj_80171278 *TOMine__ct(Obj_80171278 *arg0);
void *__dt__6TOMineFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 submit_cursor_candidate(void *, int);
int submit_target_to_player_cursor(void*);
void __dl__7TObjectFPv(void *);

int TOMine::get_player_state() { return submit_target_to_player_cursor(this); }

typedef struct RecoveredFields_80170F0C_arg0 RecoveredFields_80170F0C_arg0;
int TOMine::find_target_player() {
    u8 *arg0 = (u8 *)this;
  u16 temp_r3;
  unsigned short new_var;
  ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C = find_nearest_visible_player((void *) arg0, 0, (f32) ((RecoveredFields_80170F0C_arg0 *) arg0)->field_34C);
  temp_r3 = ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C;
  new_var = -1;
  if (temp_r3 != new_var)
  {
    ((RecoveredFields_80170F0C_arg0 *) arg0)->field_2A8 = (s32)get_player_by_client_id(temp_r3);
    ((TOMine *)arg0)->update_trigger();
  }
  return ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C;
}

void TOMine::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    if (TObjPlayer::check_demo_mode() != 1) {
        this->vfunc_79();
        ((TOMine *)arg0)->update_float_height();
        switch (this->mode) {
        case 2:
        case 0:
            find_target_player();
            VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x334));
            VecCopy((Vec *)(*(s32 *)&this->m_a4 + 0x1C), (const Vec *)(arg0 + 0x334));
            return;
        case 3:
            temp_r3 = this->m_8c;
            this->m_8c = (temp_r3 - 1);
            if (temp_r3 < 0) {
                this->mode = 4;
            }
            switch (this->m_344) {
            default:
                TOMineTrap__sub_80170CD4((arg0));
                break;
            case 1:
                ((TOMine *)arg0)->sub_80170BEC();
                break;
            case 2:
                ((TOMine *)arg0)->follow_target();
                break;
            }
            submit_cursor_candidate(arg0, -1);
            return;
        case 4:
            ((TOMine *)arg0)->detonate();
            break;
        }
    }
}

void TOMine::free_sub_objects() { TObjFish::set_global_param((s32)(*(void**)((char*)this + 0x378))); draw_ginja_object(*(void**)((char*)this + 0x374)); }

void TOMine::free_parts() { TObjFish::set_global_param(this->texture_id); draw_ginja_object(this->model); }

void TOMine::render() {
    VObj_801710E4 *arg0 = (VObj_801710E4 *)this;
    s32 t;
    if (*(s16 *)((s8 *)arg0 + 0x326) == 3 && arg0->m8(lbl_805DB854, lbl_805DB858) != 0) {
        push_matrix();
        post_translate_matrix((u8 *) arg0 + 0x38);
        rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x370));
        free_parts();
        TParticleCtrl::begin_effect_render();
        t = model_render_flags;
        saved_model_render_flags = t;
        model_render_flags = t | 0x20;
        ((void (*)(void *, s32)) set_chunk_material_color__13TUnk_80494AE0Fv)((u8 *) arg0 + 0x360, t);
        free_sub_objects();
        set_chunk_material_color__13TUnk_80494AE0Fv(chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TOMine::free_instance() {
    if ((u32) lbl_805D5A50 != 0U) {
        TLobby__sub_8001FE7C((void*)lbl_805D5A50, 1);
        lbl_805D5A50 = 0U;
    }
}

void TOMine::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &mine_resource_desc.value, 0, 0, 0));
    }
    (*(s32 *)&lbl_805D5A50) = var_r0;
}

void *__dt__6TOMineFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__6TOMine;
        ((TUnk_804806E8 *)arg0)->destroy_motion_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
Obj_80171278 *TOMine__ct(Obj_80171278 *arg0) {
    __ct__13TUnk_804806E8FP7TObject(arg0);
    arg0->vptr = (u32)((s32 *)&__vt__6TOMine);
    arg0->f00 = TOMine__name;
    ((TOMine *)arg0)->phase = 0;
    arg0->f350 = lbl_805DB85C;
    arg0->f34C = lbl_805DB85C;
    arg0->f358 = lbl_805DB85C;
    arg0->f354 = 0;
    arg0->f35C = 0xFFFF;
    arg0->f360 = lbl_805DB85C;
    arg0->f364 = lbl_805DB85C;
    arg0->f368 = lbl_805DB85C;
    arg0->f36C = lbl_805DB85C;
    arg0->f340 = 0;
    arg0->f370 = 0;
    obj_setFlags30(arg0, 0x60000000);
    arg0->flags30 &= 0xFFFBFFFF;
    return arg0;
}

}
