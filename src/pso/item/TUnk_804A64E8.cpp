// ---- pso/unk/text_8012F704
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A64E8.h"

    
void TUnk_804A64E8::update_idle() { this->m_204 = 0; *(float*)((char*)this + 0x200) = 1.0f; *(float*)((char*)this + 0x1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; }

    
void TUnk_804A64E8::update_attack() { *(int *)&this->m_204 = 10922; *(float*)((char*)this + 0x200) = 1e+01f; *(float *)&this->m_1fc = 1e+01f; *(float*)((char*)this + 0x1f8) = 1e+01f; }

#include "pso/misc/TTecSlicer.h"
#include "pso/player/TObjPlayer.h"

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
    ((TObjPlayer *)this)->draw_icon(5, (s32)&tec.pos);
    ((TObjPlayer *)this)->draw_icon(4, (s32)&tec.dir);
    TTecSlicer::create((u16*)&tec);
}

}

// ---- pso/item/TItemEquipVariant_8012F7D8
#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F7D8.h"
#include "pso/player/TObjPlayer.h"

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

// ---- pso/player/TObjPlayer_8012F830
#include "types.h"
#include "pso/item/TUnk_804A64E8.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int TItemWeapon__ct(void);
int set_status_flags__10TObjPlayerFUl(void*, void*);


    
void*TUnk_804A64E8::init_position_state() { TItemWeapon__ct(); *(int*)((char*)this + 0x18) = (int)lbl_804A64E8; set_status_flags__10TObjPlayerFUl(this, (void*)2); *(int *)&(this->m_204) = 0; *(float*)((char*)this + 0x200) = 1.0f; *(float *)&(this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}
