#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TORockCaveBrakable.h"
#include "pso/player/TObjPlayer.h"

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
struct Vec_80174CFC { f32 x, y, z; };

struct Init_80174CFC { u8 b[0x4C]; };

struct Offs_80174CFC { Vec_80174CFC v[6]; };

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
void *__nw__7TObjectFUl(u32);
void vec3_add_to(void *, void *);
void rotate_vector_by_matrix(int, void *, void *);
void rotate_matrix_y(int, s32);
extern Offs_80174CFC rock_cave_debris_offset_table;
extern Init_80174CFC rock_cave_debris_init_params;
extern u8 identity_matrix[];
extern void *rock_cave_model_resource;
extern s32 tl_05;
void *__ct__18TORockCaveBrakableFv(void *arg0);
void *__dt__18TORockCaveBrakableFv(void *arg0, s16 arg1);
int play_sound_effect(void*, void*, void*, void*);
u8 is_current_floor_switch_set(u16);
void *__ct__10TORockCaveFv(void *arg0);
void __dl__7TObjectFPv(void *);
void *__dt__10TORockCaveFv(void *arg0, s16 arg1);

void TORockCaveBrakable::vfunc_19() {  }
void TORockCaveBrakable::vfunc_18() { play_sound_effect((void*)277521, (char*)this + 0x38, (void*)0, (void*)0); }

void TORockCaveBrakable::vfunc_16() {
    u8 *arg0 = (u8 *)this;
    Vec_80174CFC v;
    Offs_80174CFC offs;
    Init_80174CFC init;
    s32 i;
    void *p;
    offs = rock_cave_debris_offset_table;
    init = rock_cave_debris_init_params;
    *(f32 *)((s8 *)&init + 0xC) = *(f32 *)(arg0 + 0x38);
    *(f32 *)((s8 *)&init + 0x10) = *(f32 *)(arg0 + 0x3C);
    *(f32 *)((s8 *)&init + 0x14) = *(f32 *)(arg0 + 0x40);
    *(f32 *)((s8 *)&init + 0x38) = *(f32 *)((s8 *)&init + 0x10);
    for (i = 0; i < 6; i++) {
        VecCopy((Vec *)&v, (const Vec *)&offs.v[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        VecCopy((Vec *)&init.b[0xC], (const Vec *)&this->position);
        vec3_add_to(&init.b[0xC], &v);
        *(s32 *)((s8 *)&init + 0x40) = get_bml_model(rock_cave_model_resource, i);
        *(s32 *)((s8 *)&init + 0x44) = TObjFish__sub_8001EDB0(rock_cave_model_resource, i);
        p = __nw__7TObjectFUl(0x234);
        if (p != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)p, (u8 *)tl_05, (u8 *)&init);
        }
    }
}

void TORockCaveBrakable::spawn_break_effect() {
    this->vfunc_18();
    spawn_particle_effect(&this->position, 0x45);
    spawn_particle_effect(&this->position, 0x46);
}

void TORockCaveBrakable::run_task() {
    s32 temp_r0_2;

    if (TObjPlayer::check_demo_mode() == 1) {
        this->vfunc_19();
        return;
    }
    switch (this->m_b4) {
    default:
        this->m_b4 = 0;
    case 0:
        temp_r0_2 = this->m_b8;
        if ((temp_r0_2 >= 0) && (temp_r0_2 < 0x100) && (is_current_floor_switch_set((u16) temp_r0_2) == 1)) {
            this->m_b4 = 1;
            this->spawn_break_effect();
            this->vfunc_16();
        }
        break;
    case 1:
        set_flag8();
        queue_destruction__7TObjectFv(this);
        break;
    }
}

extern s32 __vt__18TORockCaveBrakable[];

void *__dt__18TORockCaveBrakableFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TORockCaveBrakable;
        __dt__10TORockCaveFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *lbl_805D3100;

void *__ct__18TORockCaveBrakableFv(void *rock_cave_brakable) {
    __ct__10TORockCaveFv(rock_cave_brakable);
    *(s32 **)((s8 *)rock_cave_brakable + 0x18) = __vt__18TORockCaveBrakable;
    *(void * *)&((TORockCaveBrakable *)rock_cave_brakable)->m_name = lbl_805D3100;
    ((TORockCaveBrakable *)rock_cave_brakable)->m_b4 = 0;
    ((TORockCaveBrakable *)rock_cave_brakable)->m_b8 = -1;
    return rock_cave_brakable;
}

}
