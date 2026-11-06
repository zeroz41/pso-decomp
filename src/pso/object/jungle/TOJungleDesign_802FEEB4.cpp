#include "types.h"
#include "pso/object/jungle/TOJungleDesign.h"
#include "pso/object/jungle/TOJungleDesign_802FEEB4.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/jungle/TOJungleDesign.h"
#include "pso/object/ambient/TObjFish.h"
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

struct RecoveredGlobal_802FEF98___vt__14TOJungleDesign {
    s32 value;
    u8 remaining[0x38];
};

// One box per design variant (m_b0).
CollisionBody TOJungleDesign__collision_desc_table[3] = {
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

extern "C" {
s32 init_collision_body_parts(void *, int, int);
extern s32 __vt__14TOJungleDesign[];
extern s32 TOJungleDesign__name;
s32 post_translate_matrix(void *);
void free_collision_body_parts(void *);
s32 push_matrix();
void __dl__7TObjectFPv(void *);


void TOJungleDesign::render() {
    u8 *arg0 = (u8 *)this;
    if (((JDVObj_802feeb4 *)arg0)->m8(400.0f, 40.0f) == 1) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_yxz(0, (*(s32 *)&this->rotation_x), (this->rotation_y), (this->rotation_z));
        draw_ginja_object((void *)this->m_ac);
        pop_matrix();
    }
}

}
TOJungleDesign::~TOJungleDesign() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {
typedef char RecoveredGlobal_802FEF98___vt__14TOJungleDesign_size[sizeof(RecoveredGlobal_802FEF98___vt__14TOJungleDesign) == 0x3C ? 1 : -1];
u8 *TOJungleDesign__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802FEF98___vt__14TOJungleDesign *)&__vt__14TOJungleDesign).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOJungleDesign__name;
    ((TOJungleDesign *)(arg0))->apply_object_set_data((void *)arg2);
    ((TOJungleDesign *)arg0)->init_design_variant();
    init_collision_body_parts(arg0, (int)&TOJungleDesign__collision_desc_table[((TOJungleDesign *)arg0)->m_b0], 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

}
