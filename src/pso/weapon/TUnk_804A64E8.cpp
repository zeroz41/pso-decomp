#include "types.h"
#include "pso/weapon/TUnk_804A64E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A64E8::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        rotate_matrix_x(NULL, rotation_x);
        return;
    case 2:
        scale_current_matrix(&scale.x);
        return;
    case 3:
        rotate_matrix_x(NULL, -rotation_x);
        return;
    }
}

void TUnk_804A64E8::update_idle() {
    rotation_x = 0;
    scale.x = scale.y = scale.z = 1.0f;
}

void TUnk_804A64E8::update_attack() {
    rotation_x = 10922;
    scale.x = scale.y = scale.z = 10.0f;
}

extern "C" {

struct Owner_8012F704 { u8 pad[0x60]; s32 f60; };
struct Self_8012F704 { u8 pad0[0x24]; s32 f24; u8 pad28[0xF0 - 0x28]; Owner_8012F704 *owner; u8 padF4[0x188 - 0xF4]; s32 f188; };
struct Vec_8012F704 { f32 x, y, z; };
struct Tec_8012F704 {
    s16 id;
    u8 pad2[2];
    s32 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    s32 f28;
    u8 pad2C[4];
    Vec_8012F704 pos;
    Vec_8012F704 dir;
};

s16 get_entity_id(void *);
f32 query_extended_state__10TObjPlayerFv(void *);
struct SlicerState_801295FC;
void init_slicer_launch_state(void *arg0);
s16 get_validated_attack_stage(u8 *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);




void TUnk_804A64E8::emit_marker_effects() {
    Tec_8012F704 tec;

    init_slicer_launch_state((SlicerState_801295FC *)&tec);
    tec.id = get_entity_id(((Self_8012F704 *)this)->owner);
    tec.fC = ((TItem *)this)->get_item_id();
    tec.f4 = ((Self_8012F704 *)this)->f24;
    tec.f8 = ((Self_8012F704 *)this)->f188;
    tec.f10 = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)((Self_8012F704 *)this)->owner + 0x7CC));
    tec.f12 = get_validated_attack_stage((u8 *)((Self_8012F704 *)this)->owner + 0x7CC);
    tec.f14 = query_extended_state__10TObjPlayerFv(((Self_8012F704 *)this)->owner);
    tec.f18 = 1.0f;
    tec.f1C = 0.0f;
    tec.f20 = 1.0f;
    tec.f24 = 0.7f;
    tec.f28 = ((Self_8012F704 *)this)->owner->f60;
    get_joint_position(5, &tec.pos);
    get_joint_position(4, &tec.dir);
    TTecSlicer::create((u16*)&tec);
}

}


TUnk_804A64E8::~TUnk_804A64E8() {}

TUnk_804A64E8::TUnk_804A64E8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    rotation_x = 0;
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_position_state(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A64E8(tl_05, item);
    }
    return NULL;
}
