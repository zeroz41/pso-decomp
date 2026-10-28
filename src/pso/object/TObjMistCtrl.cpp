#include "types.h"
#include "pso/object/TObjMistCtrl.h"
#include "pso/unk/text_803E29B0.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80141A30.h"
#include "pso/unk/text_803DA798.h"
#include "pso/render/depth_buffer.h"
#include "pso/TPlayerFootStamp.h"
#include "pso/object/TObjMistCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl {
    s32 value;
    u8 remaining[0x34];
};

struct Ent_802AF8BC { f32 x, y, z; u32 a; u32 b; u32 f14; };

struct Vec_802AF8BC { f32 x, y, z; };

struct TPlayerFootStamp_802AF8BC {
    u8 pad0[0x1C];
    Ent_802AF8BC ent[4];
    Vec_802AF8BC base;
    Vec_802AF8BC off[4];
    s32 fB8;
    u8 padBC[4];
    s32 fC0;
};

extern "C" {
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 __ct__13TUnk_804B9870FP7TObject(void *, void *);
extern s32 __vt__12TObjMistCtrl[];
extern s32 lbl_805D3E80;
f32 horizontal_distance_squared(void *, void *);
void __dl__7TObjectFPv(void *);

void TObjMistCtrl::run_task() { { (void)(sub_802AF64C()); return; } }

}
TObjMistCtrl::~TObjMistCtrl() {
    if (*(void **)((s8 *)this + 0x90) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x90)); *(s32 *)((s8 *)this + 0x90) = 0; }
}
extern "C" {

extern s32 camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 player_footstamp_texture_gvm_handle;
extern s32 model_render_flags;
extern const f32 lbl_805DE1F8;

typedef char RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl_size[sizeof(RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl) == 0x38 ? 1 : -1];
u8 *TObjMistCtrl__ct(u8 *mist_ctrl, s32 parent, u32 arg2) {
    __ct__13TUnk_804B9870FP7TObject((void *)mist_ctrl, (void *)parent);
    *(s32 **)((s8 *)mist_ctrl + 0x18) = &(*(RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl *)&__vt__12TObjMistCtrl).value;
    *(s32 *)((s8 *)mist_ctrl + 0) = (s32) lbl_805D3E80;
    if (arg2 != 0U) {
        ((TObjMistCtrl *)(mist_ctrl))->apply_object_set_data((void *)arg2);
    }
    *(s32 *)((s8 *)mist_ctrl + 0x90) = (s32)spawn_continuous_particle_effect_with_flags((mist_ctrl + 0x38), 0x200, 0x800);
    return mist_ctrl;
}

void TPlayerFootStamp::render() {
    u8 *arg0 = (u8 *)this;
    if (horizontal_distance_squared((void *)(arg0 + 0x7C), (void *)(camera_ctrl_instance + 0x178)) < lbl_805DE1F8) {
        saved_model_render_flags = model_render_flags;
        TObjPlayer::reset_transform_state();
        TObjFish::set_global_param(player_footstamp_texture_gvm_handle);
        set_texture_num((*(s16 *)((s8 *)arg0 + 0xBE)));
        set_depth_buffer_settings_1();
        draw_particle_strip((arg0 + 0x1C), (void *)(4), (void *)(1));
        restore_saved_depth_alpha_state();
        model_render_flags = saved_model_render_flags;
    }
}
void TPlayerFootStamp::run_task() {
    TPlayerFootStamp_802AF8BC *o = (TPlayerFootStamp_802AF8BC *)this;
    s32 j;
    Ent_802AF8BC *e;
    s32 i;
    o->fC0 = o->fC0 - 1;
    if (o->fC0 <= 0) {
        queue_destruction__7TObjectFv(o);
        return;
    }
    f32 bx = o->base.x;
    f32 by = o->base.y;
    f32 bz = o->base.z;
    e = o->ent;
    for (i = 0; i < 4; i++) {
        if (o->fC0 < 0x40) {
            e->f14 = o->fB8 - ((0x40 - o->fC0) << 26);
        }
        e->x = bx + o->off[i].x;
        e->y = by + o->off[i].y;
        e->z = bz + o->off[i].z;
        e++;
    }
}

}
