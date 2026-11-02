#include "types.h"
#include "pso/item/TUnk_804A64E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F7D8.h"

extern "C" {

s32 scale_current_matrix(void *);
s32 rotate_matrix_x(s32, s32);

void TUnk_804A64E8::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        rotate_matrix_x(0, this->m_204);
        return;
    case 2:
        scale_current_matrix((u8 *)&this->unk_1F8);
        return;
    case 3:
        rotate_matrix_x(0, -this->m_204);
        return;
    }
}

}


    
void TUnk_804A64E8::update_idle() { this->m_204 = 0; *(float*)((char*)this + 0x200) = 1.0f; *(float*)((char*)this + 0x1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; }

    
void TUnk_804A64E8::update_attack() { *(int *)&this->m_204 = 10922; *(float*)((char*)this + 0x200) = 1e+01f; *(float *)&this->m_1fc = 1e+01f; *(float*)((char*)this + 0x1f8) = 1e+01f; }


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


extern s32 lbl_804A64E8[];

void *__dt__13TUnk_804A64E8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A64E8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}


extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);


    
void*TUnk_804A64E8::init_position_state() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A64E8; set_weapon_flags(2); *(int *)&(this->m_204) = 0; *(float*)((char*)this + 0x200) = 1.0f; *(float *)&(this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}

extern "C" {
u8 * init_position_state__13TUnk_804A64E8Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_position_state(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x208));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_position_state__13TUnk_804A64E8Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
