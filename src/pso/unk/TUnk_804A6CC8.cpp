#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_80130EF8.h"
#include "pso/unk/TUnk_804A6CC8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/unk/text_801310A8.h"
#include "pso/object/TObjGyaranzoMissile_80131100.h"
#include "pso/object/TUnk_804A6DC0.h"
#include "pso/item/TItem.h"

struct Obj_80131070 { u8 pad[0x208]; s32 state; };

extern "C" {

f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern s32 tl_05;

void TUnk_804A6CC8::update_idle() {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x1F8);
    if (temp_r0 == 1) {
        *(s32 *)((s8 *)((u8 *)this) + 0x1F8) = (s32) (u8) (temp_r0 == 0);
        this->m_204 = (f32) 1e-05f;
        *(f32 *)((s8 *)((u8 *)this) + 0x200) = (f32) 1e-05f;
        this->m_1fc = (f32) 1e-05f;
    }
}
void TUnk_804A6CC8::update_attack() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x1F8);
    if (temp_r0 == 0) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = (s32) (u8) (temp_r0 == 0);
        this->m_204 = (f32) 1.0f;
        *(f32 *)((s8 *)arg0 + 0x200) = (f32) 1.0f;
        this->m_1fc = (f32) 1.0f;
    }
}
#pragma push
#pragma opt_common_subs off
void TUnk_804A6CC8::update_weapon() {
    f32 buffer_14[3];
    s32 buffer_8[3];
    s32 temp_r31;
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x208)) {
    case 1:
        this->m_210 = (f32) (this->m_210 - 0.46666667f);
        if (this->m_210 <= 0.0f) {
            this->m_210 = (f32) 0.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x208) = 0;
            break;
        }
        break;
    case 2:
        this->m_210 += 0.46666667f;
        if (1.4f <= this->m_210) {
            this->m_210 = (f32) 1.4f;
            *(s32 *)((s8 *)((u8 *)this) + 0x208) = 3;
            break;
        }
        break;
    case 3:
        *(s32 *)((s8 *)((u8 *)this) + 0x208) = 1;
        temp_r31 = *(s32 *)((s8 *)this->owner + 0x60) - 0x4000;
        buffer_14[0] = sin_table_lookup(temp_r31);
        buffer_14[1] = 1.0f;
        buffer_14[2] = cos_table_lookup(temp_r31);
        buffer_8[0] = 0x4000;
        buffer_8[1] = *(s32 *)((s8 *)this->owner + 0x60);
        buffer_8[2] = 0;
        TObjPlayer::launch_weapon_casing(tl_05, (u32) this, 3, (u32) &buffer_14[0], (u32) &buffer_8[0]);
        break;
    }
}
#pragma pop

void TUnk_804A6CC8::emit_marker_effects() {
    Obj_80131070 *self = (Obj_80131070 *)this;
    u8 buf[0x18];
    self->state = 2;
    ((TObjPlayer *)self)->draw_status_icon((s32)buf);
    spawn_particle_effect(buf, 9);
}

}

extern s32 lbl_804A6CC8[];

void *__dt__13TUnk_804A6CC8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6CC8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
int TItemWeapon__ct(void);
extern unsigned char spawn_weapon_impact_effect[];
    
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);

}

    // lbl_804A6CC8 declared above (s32[])
    
void* yasminkov_2000h_ct(void* a0, s32 _w1, s32 _w2) { TItemWeapon__ct(); *(int*)((char*)a0 + 0x18) = (int)lbl_804A6CC8; *(int*)((char*)a0 + 0x1f0) = 0; *(int*)((char*)a0 + 0x1ec) = (int)spawn_weapon_impact_effect; *(float*)((char*)a0 + 0x1e4) = 2e+01f; *(int*)((char*)a0 + 0x1f8) = 0; ((TUnk_804A6CC8 *)a0)->m_204 = 1e-05f; *(float*)((char*)a0 + 0x200) = 1e-05f; ((TUnk_804A6CC8 *)a0)->m_1fc = 1e-05f; *(int*)((char*)a0 + 0x208) = 0; *(float*)((char*)a0 + 0x214) = 0.0f; ((TUnk_804A6CC8 *)a0)->m_210 = 0.0f; ((TUnk_804A6CC8 *)a0)->m_20c = 0.0f; return a0; }

u8 *create_yasminkov_2000h(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x218));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)yasminkov_2000h_ct(temp_r3, tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}
