#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Base_8016AE84_8016AD58 { char pad[0x18]; };
struct VObj_8016AE84_8016AD58 : Base_8016AE84_8016AD58 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
};

struct VBase18 { char pad[0x18]; };

struct VObj18 : VBase18 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

struct RecoveredGlobal_8016B0A0_lbl_804B29D0 { s32 value; u8 remaining[0x28]; };

struct RecoveredGlobal_8016B0A0___vt__14TOKeyAncient01 { s32 value; u8 remaining[0x70]; };

struct Inner_8016AF84 { u8 pad[0xC]; s32 f0C; };

struct Big_8016AF84 { u8 pad[0x42C]; Inner_8016AF84 *p; };

struct Buf_8016AF84 { s32 a; s32 b; s32 c; s32 d; };

extern "C" {
s32 update_anim_phase__13TUnk_804AFBF8Fv();
s32 rotate_matrix_y(int, void *);
s32 rotate_matrix_z(int, void *);
s32 rotate_matrix_x(int, void *);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(void *, int, f32);
u8 *TLobby__sub_8001FE7C(void *, s16);
void mem_free(void *p);
extern u8 *TOKeyAncient01__shared_resource_object;
extern u32 TOKeyAncient01__texture_lists;
u32 init_collision_body_parts(void *, s32, s32);
void *TOKey__ct(TOKey *arg0);
extern RecoveredGlobal_8016B0A0_lbl_804B29D0 key_ancient01_collision_body_part;
extern s32 __vt__14TOKeyAncient01[];
extern s32 TOKeyAncient01__class_name;
extern const f32 lbl_805DB6E8;
extern const f32 lbl_805DB6EC;
extern const f32 lbl_805DB6F0;
extern const f32 lbl_805DB6F4;
extern const f32 lbl_805DB6F8;
u8 *TOKeyAncient01__ct(TOKeyAncient01 *arg0, s32 arg1, s32 arg2);
Big_8016AF84 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_804419B8[];
extern u8 lbl_804419D0[];
extern u8 lbl_804419E8[];
extern u8 bm_fd_obj_n_switch_resource_descriptor[];
void *__dt__14TOKeyAncient01Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void CursorAction::set_use() { kind = CURSOR_ACTION_USE; }

void TOKeyAncient01::vfunc_25() {  }

void TOKeyAncient01::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj18*)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, (void *)this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        if ((s32) *(s32 *)&this->m_d4 != 1) {
            draw_ginja_model_with_motion((void *) (*(u8 * *)&this->model), (int) (*(s32 *)&this->m_bc), this->m_b0);
        } else {
            push_matrix();
            post_translate_matrix((void *) (*(u8 * *)&this->model + 8));
            rotate_matrix_z(0, (void *) (*(s32 *)((s8 *)(*(u8 * *)&this->model) + 0x1C)));
            rotate_matrix_x(0, (void *) (*(s32 *)((s8 *)(*(u8 * *)&this->model) + 0x14)));
            rotate_matrix_y(0, (void *) (*(s32 *)((s8 *)(*(u8 * *)&this->model) + 0x18)));
            draw_ginja_model((*(s32 *)((s8 *)(*(u8 * *)&this->model) + 4)));
            pop_matrix();
        }
        pop_matrix();
    }
}

void TOKeyAncient01::vfunc_17() {
    update_anim_phase__13TUnk_804AFBF8Fv();
    this->submit_cursor_target();
}

void TOKeyAncient01::vfunc_16() {
    struct VObj_8016AE84_8016AD58 *o = (struct VObj_8016AE84_8016AD58 *)this;
    o->m18();
}

extern void *tl_05;

void *TOKeyAncient01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE8);
    if (o != NULL) {
        o = TOKeyAncient01__ct((TOKeyAncient01 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOKeyAncient01::free_shared_resources() {
  s32 var_r31;
  s32 var_r30;
  if (((u32) TOKeyAncient01__texture_lists) != 0)
  {
    var_r30 = 1;
    var_r31 = 4;
    do
    {
      TObjPlayer::free_if_valid(*((s32 *) (((s8 *) TOKeyAncient01__texture_lists) + var_r31)));
      var_r30 += 1;
      var_r31 += 4;
    }
    while (var_r30 < 4);
    if (((u32) TOKeyAncient01__texture_lists) != 0)
    {
      mem_free((void *)TOKeyAncient01__texture_lists);
      TOKeyAncient01__texture_lists = 0;
    }
  }
  if (((void *) TOKeyAncient01__shared_resource_object) != 0)
  {
    TLobby__sub_8001FE7C(TOKeyAncient01__shared_resource_object, 1);
    TOKeyAncient01__shared_resource_object = 0;
  }
}

void TOKeyAncient01::load_resources() {
    Big_8016AF84 *v = (Big_8016AF84 *)((TAdSinglePlyChrSelectGC *)0x440)->alloc();
    if (v != NULL) {
        v = load_resource_from_descriptor(v, 1, bm_fd_obj_n_switch_resource_descriptor, 0, 0, 0);
    }
    (*(Big_8016AF84 * *)&TOKeyAncient01__shared_resource_object) = v;
    (*(Buf_8016AF84 * *)&TOKeyAncient01__texture_lists) = (Buf_8016AF84 *)mem_alloc(0x10);
    (*(Buf_8016AF84 * *)&TOKeyAncient01__texture_lists)->a = (*(Big_8016AF84 * *)&TOKeyAncient01__shared_resource_object)->p->f0C;
    (*(Buf_8016AF84 * *)&TOKeyAncient01__texture_lists)->b = (s32)load_gvm_texture_file((s32)lbl_804419B8);
    (*(Buf_8016AF84 * *)&TOKeyAncient01__texture_lists)->c = (s32)load_gvm_texture_file((s32)lbl_804419D0);
    (*(Buf_8016AF84 * *)&TOKeyAncient01__texture_lists)->d = (s32)load_gvm_texture_file((s32)lbl_804419E8);
}

void *__dt__14TOKeyAncient01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOKeyAncient01;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__5TOKeyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TOKeyAncient01__ct(TOKeyAncient01 *key_ancient01, s32 arg1, s32 arg2) {
    s32 temp_r0;
    TOKey__ct(key_ancient01);
    *(s32 **)((s8 *)key_ancient01 + 0x18) = &(*(RecoveredGlobal_8016B0A0___vt__14TOKeyAncient01 *)&__vt__14TOKeyAncient01).value;
    *(s32 *)((s8 *)key_ancient01 + 0) = (s32) TOKeyAncient01__class_name;
    ((TOKeyAncient01 *)(key_ancient01))->apply_object_set_data((void *)arg2);
    ((TOKey *)key_ancient01)->init_switch_id();
    temp_r0 = *(s32 *)((s8 *)key_ancient01 + 0x88);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)key_ancient01 + 0x88) = 0;
    } else if (temp_r0 > 3) {
        *(s32 *)((s8 *)key_ancient01 + 0x88) = 3;
    }
    key_ancient01->texture_id = (s32) *(s32 *)((s8 *)(*(s32 *)&TOKeyAncient01__texture_lists) + (*(s32 *)((s8 *)key_ancient01 + 0x88) * 4));
    *(s32 *)((s8 *)key_ancient01 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TOKeyAncient01__shared_resource_object + 0x42C)) + 8);
    *(u8 **)((s8 *)key_ancient01 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)TOKeyAncient01__shared_resource_object + 0x430)) + 4));
    *(f32 *)((s8 *)key_ancient01 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)key_ancient01 + 0xBC)) + 4) - lbl_805DB6E8);
    key_ancient01->m_b8 = (f32) lbl_805DB6EC;
    init_collision_body_parts(key_ancient01, (s32) &key_ancient01_collision_body_part.value, 1);
    ((TUnk_804AF8A0 *)key_ancient01)->refresh_collision_body_centers();
    ((TObjPlayer *)key_ancient01)->reset_photon_effect();
    key_ancient01->m_c0 = (f32) lbl_805DB6F0;
    *(f32 *)((s8 *)key_ancient01 + 0xC4) = (f32) lbl_805DB6F4;
    if ((s32) key_ancient01->m_d0 != 2) {
        if (key_ancient01->scale < lbl_805DB6F8) {
            key_ancient01->m_d0 = 1;
        } else {
            goto block_7;
        }
    } else {
block_7:
        key_ancient01->m_d0 = 0;
    }
    return (u8 *)key_ancient01;
}

}
