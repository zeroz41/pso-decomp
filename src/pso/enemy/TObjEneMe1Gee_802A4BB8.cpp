#include "types.h"
#include "pso/enemy/TObjEneMe1Gee_802A4BB8.h"
#include "pso/misc/TNeedleShoot_802A4668.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TNeedleShoot.h"
#include "pso/misc/TObjEneMe1Gee_NEEDLE.h"
#include "pso/enemy/TObjEneMe1Gee.h"
#include "pso/TParticleCtrl.h"

struct RecoveredGlobal_802A4CC4_lbl_804DCFF8 {
    s32 value;
    u8 remaining[0x24];
};

extern "C" {
s32 TObjPlayer__sub_802A445C(void *, s32);
void *find_entity_by_id(u16 id);
s32 update_lifetime__22TObjEneMe1GiGueMissileFv(void *);
u16 get_entity_id(void *);
u8 * TNeedleShoot__ct(void *, s32, void *, void *);
extern RecoveredGlobal_802A4CC4_lbl_804DCFF8 __vt__20TObjEneMe1Gee_NEEDLE;
extern s32 TObjEneMe1Gee_NEEDLE__name;
int TObjEneMe1Gee__sub_800CC2BC(void);
extern u32 me1gee_cached_model_handle;
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 rotate_matrix_x(int, int);
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 set_global_param__8TObjFishFl();
s32 rotate_matrix_y(int, int);
s32 push_matrix();

void TObjEneMe1Gee_NEEDLE::render() {
    u8 *arg0 = (u8 *)this;
    if ((u32) me1gee_cached_model_handle == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    push_matrix();
    TParticleCtrl::begin_effect_render();
    post_translate_matrix((u8 *)&this->m_6c);
    rotate_matrix_y(0, this->m_a4);
    rotate_matrix_x(0, this->m_a0);
    TObjFish__sub_8001EDB0((void *)me1gee_cached_model_handle, 1);
    set_global_param__8TObjFishFl();
    get_bml_model((void *)me1gee_cached_model_handle, 1);
    draw_ginja_object();
    TParticleCtrl::end_effect_render();
    pop_matrix();
}
void TObjEneMe1Gee_NEEDLE::run_task() {
    this->m_1c = (u32)find_entity_by_id(this->m_34);
    if ((u32) this->m_1c == 0U) {
        queue_destruction__7TObjectFv((this));
        return;
    }
    if ((s32) this->m_b8 == 1) {
        update_position();
        update_lifetime__22TObjEneMe1GiGueMissileFv(this);
        TObjPlayer__sub_802A445C(this, 1);
        return;
    }
    TNeedleShoot__sub_802A4668(this);
}
u8 *TObjEneMe1Gee_NEEDLE__ct(TObjEneMe1Gee_NEEDLE *arg0, s32 arg1, u8 *from, u8 *to, f32 farg0, f32 farg1) {
    u8 *temp_r3;
    TNeedleShoot__ct(arg0, arg1, from, to);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__20TObjEneMe1Gee_NEEDLE.value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjEneMe1Gee_NEEDLE__name;
    *(f32 *)((s8 *)arg0 + 0xBC) = farg1;
    *(f32 *)((s8 *)arg0 + 0xAC) = farg0;
    arg0->m_c0 = 0x96;
    arg0->m_b0 = 1;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x1C));
    if (temp_r3 != NULL) {
        arg0->m_34 = get_entity_id(temp_r3);
    }
    return (u8 *)arg0;
}
void TObjEneMe1Gee__sub_802A4D4C(void) {  }
void TObjEneMe1Gee::cache_result_805D6660() { (*(int *)&me1gee_cached_model_handle) = TObjEneMe1Gee__sub_800CC2BC(); }

typedef char RecoveredGlobal_802A4CC4_lbl_804DCFF8_size[sizeof(RecoveredGlobal_802A4CC4_lbl_804DCFF8) == 0x28 ? 1 : -1];

}
