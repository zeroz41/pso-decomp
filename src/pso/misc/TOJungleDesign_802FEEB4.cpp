#include "types.h"
#include "pso/misc/TOJungleDesign_802FEEB4.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOJungleDesign.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct JDBase_802feeb4 { char pad[0x18]; };
struct JDVObj_802feeb4 : JDBase_802feeb4 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_802FEF98_lbl_804E6580 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_802FEF98___vt__14TOJungleDesign {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
s32 init_collision_body_parts(void *, int, int);
extern RecoveredGlobal_802FEF98_lbl_804E6580 TOJungleDesign__collision_desc_table;
extern s32 __vt__14TOJungleDesign[];
extern s32 TOJungleDesign__name;
s32 post_translate_matrix(void *);
void free_collision_body_parts(void *);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

extern const f32 lbl_805DEF20;
extern const f32 lbl_805DEF24;

void TOJungleDesign::render() {
    u8 *arg0 = (u8 *)this;
    if (((JDVObj_802feeb4 *)arg0)->m8(lbl_805DEF20, lbl_805DEF24) == 1) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_yxz(0, (*(s32 *)&this->rotation_x), (this->rotation_y), (this->rotation_z));
        draw_ginja_object((void *)this->m_ac);
        pop_matrix();
    }
}

void *__dt__14TOJungleDesignFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOJungleDesign;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_802FEF98_lbl_804E6580_size[sizeof(RecoveredGlobal_802FEF98_lbl_804E6580) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_802FEF98___vt__14TOJungleDesign_size[sizeof(RecoveredGlobal_802FEF98___vt__14TOJungleDesign) == 0x3C ? 1 : -1];
u8 *TOJungleDesign__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802FEF98___vt__14TOJungleDesign *)&__vt__14TOJungleDesign).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOJungleDesign__name;
    ((TOJungleDesign *)(arg0))->apply_object_set_data((void *)arg2);
    ((TOJungleDesign *)arg0)->init_design_variant();
    init_collision_body_parts(arg0, (int) ((u8 *)&TOJungleDesign__collision_desc_table.value + (((TOJungleDesign *)arg0)->m_b0 * 0x2C)), 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

}
