#include "types.h"
#include "pso/misc/TOGrassJungle_8029CD90.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOKeyJungleMain.h"
#include "pso/misc/TOGrassJungle.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_8029CE64___vt__13TOGrassJungle {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 __ct__13TUnk_804B9870FP7TObject(void *, void *);
extern s32 __vt__13TOGrassJungle[];
extern s32 grass_jungle_class_name;
struct Base_8029CD90 { char pad[0x18]; };
struct VObj_8029CD90 : Base_8029CD90 {
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

s32 play_sound_effect(s32, s32, s32, s32);
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 get_bml_model(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

extern s32 TOGrassJungle__bml_resource;
extern s32 TOGrassJungle__grass_gvm_texture;
extern const f32 lbl_805DDD30;
extern const f32 lbl_805DDD34;

void TOGrassJungle::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_8029CD90 *)arg0)->m8(lbl_805DDD30, lbl_805DDD34) == 1) {
        TObjFish::set_global_param(TOGrassJungle__grass_gvm_texture);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        get_bml_model(TOGrassJungle__bml_resource, this->m_90);
        draw_ginja_object();
        pop_matrix();
    }
}

void *__dt__13TOGrassJungleFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TOGrassJungle;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8029CE64___vt__13TOGrassJungle_size[sizeof(RecoveredGlobal_8029CE64___vt__13TOGrassJungle) == 0x34 ? 1 : -1];
u8 *TOGrassJungle__ct(TOGrassJungle *grass_jungle, s32 parent, s32 arg2) {
    __ct__13TUnk_804B9870FP7TObject((void *)grass_jungle, (void *)parent);
    *(s32 **)((s8 *)grass_jungle + 0x18) = &(*(RecoveredGlobal_8029CE64___vt__13TOGrassJungle *)&__vt__13TOGrassJungle).value;
    *(s32 *)((s8 *)grass_jungle + 0) = (s32) grass_jungle_class_name;
    ((TOGrassJungle *)(grass_jungle))->apply_object_set_data((void *)arg2);
    grass_jungle->m_90 = (s32) grass_jungle->set_params[0];
    if ((s32) grass_jungle->m_90 < 0) {
        grass_jungle->m_90 = 0;
    }
    if ((s32) grass_jungle->m_90 > 1) {
        grass_jungle->m_90 = 1;
    }
    return (u8 *)grass_jungle;
}

void TOKeyJungleMain::play_activate_sound() {
    s32 arg0 = (s32)this;
    s32 var_r31;
    s32 global_state;

    var_r31 = 0x4AD12;
    global_state = get_current_area();
    switch (global_state) {
    case 34:
        var_r31 = 0x4004AD12;
        break;
    case 35:
        var_r31 = 0x4004AD12;
        break;
    }
    play_sound_effect(var_r31, arg0 + 0x38, 0, 0);
}

}
