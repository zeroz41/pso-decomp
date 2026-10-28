// ---- pso/unk/text_80130898
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80087278.h"
#include "pso/item/TUnk_804A6AD8.h"

struct PlB_80130974 { char pad[0x18]; };

struct Pl_80130974 : PlB_80130974 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual s32 m49(void *, s32, s32, s32);
};

struct Pl2_80130974 : Pl_80130974 { u8 pad[0x1F8-0x1C]; s32 f1f8; u8 pad2[0xC]; u8 f208[12]; u8 f214[12]; };

extern "C" {
s32 spawn_weapon_casing__10TObjPlayerFlUlUlUlUl(int, void *, void *, void *, void *, int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern s32 tl_05;





#pragma push
#pragma opt_common_subs off
void TUnk_804A6AD8::update_weapon() {
    u8 *arg0 = (u8 *)this;
    switch (*(s32 *)((s8 *)arg0 + 0x1F8)) {
    case 1:
        *(f32 *)((s8 *)arg0 + 0x200) = (f32) (*(f32 *)((s8 *)arg0 + 0x200) - 0.29999998f);
        if (*(f32 *)((s8 *)arg0 + 0x200) <= 0.0f) {
            *(f32 *)((s8 *)arg0 + 0x200) = (f32) 0.0f;
            *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
            break;
        }
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x200) += 0.29999998f;
        if (0.9f <= *(f32 *)((s8 *)arg0 + 0x200)) {
            *(f32 *)((s8 *)arg0 + 0x200) = (f32) 0.9f;
            *(s32 *)((s8 *)arg0 + 0x1F8) = 3;
            break;
        }
        break;
    case 3:
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
        ((TUnk_804A6AD8 *)arg0)->yasminkov_9000m_eject_casing((s32)(arg0 + 0x220), 0x4000);
        ((TUnk_804A6AD8 *)arg0)->yasminkov_9000m_eject_casing((s32)(arg0 + 0x22C), -0x4000);
        break;
    }
}
#pragma pop

void TUnk_804A6AD8::emit_marker_effects() {
    Pl2_80130974 *arg0 = (Pl2_80130974 *)this;
    arg0->f1f8 = 2;
    if (arg0->m49(arg0->f208, 0, 0, 1) != 0) {
        arg0->m49(arg0->f214, 0, 0, 0);
    } else {
        arg0->m49(arg0->f214, 0, 0, 1);
    }
    spawn_particle_effect(arg0->f208, 9);
    spawn_particle_effect(arg0->f214, 9);
}

void TUnk_804A6AD8::yasminkov_9000m_eject_casing(s32 arg1, s32 arg2) {
    f32 buffer_14[3];
    s32 buffer_8[3];
    s32 temp_r31;
    s32 temp_r8;
    u8 *temp_r3;
    temp_r3 = (u8 *)this->owner;
    if (temp_r3 != NULL) {
        temp_r31 = *(s32 *)((s8 *)temp_r3 + 0x60) - arg2;
        buffer_14[0] = sin_table_lookup(temp_r31);
        buffer_14[1] = 1.0f;
        buffer_14[2] = cos_table_lookup(temp_r31);
        buffer_8[0] = 0x4000;
        temp_r8 = *(s32 *)((s8 *)this->owner + 0x60);
        buffer_8[1] = temp_r8;
        buffer_8[2] = 0;
        spawn_weapon_casing__10TObjPlayerFlUlUlUlUl((int)tl_05, this, (void *)arg1, &buffer_14[0], &buffer_8[0], (int)temp_r8);
    }
}

}

// ---- pso/item/TItemEquipVariant_80130AC4
#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80130AC4.h"
#include "pso/player/TObjPlayer.h"

extern s32 lbl_804A6AD8[];

void *__dt__13TUnk_804A6AD8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6AD8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

// ---- pso/player/TObjPlayer_80130B1C
#include "types.h"
#include "pso/player/TObjPlayer_80130B1C.h"
#include "pso/item/TUnk_804A6AD8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char spawn_weapon_impact_effect[];

    
    
void* yasminkov_9000m_ct(void* a0) { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)a0 + 0x18) = (int)lbl_804A6AD8; *(int*)((char*)a0 + 0x1f0) = 0; *(int*)((char*)a0 + 0x1ec) = (int)spawn_weapon_impact_effect; *(float*)((char*)a0 + 0x1e4) = 2e+01f; ((TItemWeapon *)a0)->set_weapon_flags(515); *(int*)((char*)a0 + 0x1f8) = 0; ((TUnk_804A6AD8 *)a0)->m_204 = 0.0f; *(float*)((char*)a0 + 0x200) = 0.0f; ((TUnk_804A6AD8 *)a0)->m_1fc = 0.0f; return a0; }

}
