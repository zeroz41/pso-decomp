#include "types.h"
#include "pso/misc/TOKey_8015845C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"

struct VBase_18_ca64a0 { char pad[0x18]; };

struct VObj_18_ca64a0 : VBase_18_ca64a0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
f32 post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern const f32 lbl_805DB2E8;
extern const f32 lbl_805DB2EC;
int __ct__13TUnk_804AF8A0FP7TObject(void);
extern s32 lbl_804AFBF8[];
    extern const float lbl_805DB2F0;
    extern const float lbl_805DB2F4;
    extern const float lbl_805DB2F8;
void __dl__7TObjectFPv(void *);

void TUnk_804AFBF8::render() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    s32 temp_r3;
    u32 temp_r4;
    temp_f2 = this->m_c0;
    temp_r3 = ((VObj_18_ca64a0 *)(arg0))->m9(lbl_805DB2E8 * temp_f2, temp_f2, *(f32 *)&this->m_c4);
    if ((temp_r3 != 0) && (((TUnk_804AFBF8 *)arg0)->is_in_view_depth(lbl_805DB2EC) != 0)) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        temp_r4 = *(u32 *)&this->m_bc;
        if (temp_r4 != 0U) {
            if (temp_r3 == 1) {
                draw_model_motion((void *)(*(s32 *)&this->model), (void *)temp_r4, (f32)this->m_b0);
            } else {
                draw_model_motion((void *)(*(s32 *)&this->model), (void *)temp_r4, (f32)this->m_b0);
            }
        } else if (temp_r3 == 1) {
            draw_chunk_object((void *)(*(s32 *)&this->model));
        } else {
            draw_chunk_object((void *)(*(s32 *)&this->model));
        }
        pop_matrix();
    }
}

void *TUnk_804AFBF8::destroy_key_base(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)((u8 *)this + 0x18) = lbl_804AFBF8;
        __dt__13TUnk_804AF8A0Fv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
void* init_map_object_base(void* a0) { __ct__13TUnk_804AF8A0FP7TObject(); *(int*)((char*)a0 + 0x18) = (int)((unsigned char *)&lbl_804AFBF8); ((TUnk_804AFBF8 *)a0)->m_ac = 0; ((TUnk_804AFBF8 *)a0)->m_b0 = lbl_805DB2F0; *(float*)((char*)a0 + 0xb4) = lbl_805DB2F0; ((TUnk_804AFBF8 *)a0)->m_b8 = lbl_805DB2F4; ((TUnk_804AFBF8 *)a0)->m_bc = 0; ((TUnk_804AFBF8 *)a0)->actorFlags = (((TUnk_804AFBF8 *)a0)->actorFlags | 0x40000000); ((TUnk_804AFBF8 *)a0)->m_c0 = lbl_805DB2F8; *(float*)((char*)a0 + 0xc4) = (*(const float *)&lbl_805DB2EC); return a0; }
void TORainbowCave01__sub_80158604(void) {  }

}
