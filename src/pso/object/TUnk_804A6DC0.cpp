#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/object/TObjGyaranzoMissile_80131100.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/TUnk_804A6CC8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TUnk_804A6DC0.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/item/TItem.h"

struct Obj_80131334 { u8 pad[0x1f8]; s32 state; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
extern s32 lbl_804A6DC0[];
int TItemWeapon__ct(void);
extern unsigned char spawn_weapon_impact_effect[];
    
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);

int post_translate_matrix(void*);
int get_player_list__10TObjPlayerFv(void*);
}

void yasminkov_7000v_node_callback(void* p) { if (get_player_list__10TObjPlayerFv(p) == 1) { post_translate_matrix((char*)p + 0x1fc); } }

#pragma push
#pragma opt_common_subs off

void TUnk_804A6DC0::update_weapon() {
    f32 buffer_14[3];
    s32 buffer_8[3];
    s32 temp_r31;
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x1F8)) {
    case 1:
        this->m_200 = (f32) (this->m_200 - 0.90000004f);
        if (this->m_200 <= 0.0f) {
            this->m_200 = (f32) 0.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x1F8) = 0;
            break;
        }
        break;
    case 2:
        this->m_200 += 0.90000004f;
        if (2.7f <= this->m_200) {
            this->m_200 = (f32) 2.7f;
            *(s32 *)((s8 *)((u8 *)this) + 0x1F8) = 3;
            break;
        }
        break;
    case 3:
        *(s32 *)((s8 *)((u8 *)this) + 0x1F8) = 1;
        temp_r31 = *(s32 *)((s8 *)this->owner + 0x60) - 0x4000;
        buffer_14[0] = sin_table_lookup(temp_r31);
        buffer_14[1] = 1.0f;
        buffer_14[2] = cos_table_lookup(temp_r31);
        buffer_8[0] = 0x4000;
        buffer_8[1] = *(s32 *)((s8 *)this->owner + 0x60);
        buffer_8[2] = 0;
        TObjPlayer::launch_weapon_casing(tl_05, (u32) this, 2, (u32) &buffer_14[0], (u32) &buffer_8[0]);
        break;
    }
}
#pragma pop

void TUnk_804A6DC0::emit_marker_effects() {
    Obj_80131334 *self = (Obj_80131334 *)this;
    u8 buf[0x18];
    self->state = 2;
    ((TObjPlayer *)self)->draw_status_icon((s32)buf);
    spawn_particle_effect(buf, 9);
}

void *__dt__13TUnk_804A6DC0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6DC0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
void* yasminkov_7000v_ct(void* a0, s32 _w1, void * _w2) { TItemWeapon__ct(); *(int*)((char*)a0 + 0x18) = (int)((unsigned char *)&lbl_804A6DC0); *(int*)((char*)a0 + 0x1f0) = 0; *(int*)((char*)a0 + 0x1ec) = (int)spawn_weapon_impact_effect; *(float*)((char*)a0 + 0x1e4) = 2e+01f; *(int*)((char*)a0 + 0x1f8) = 0; *(float*)((char*)a0 + 0x204) = 0.0f; ((TUnk_804A6DC0 *)a0)->m_200 = 0.0f; ((TUnk_804A6DC0 *)a0)->m_1fc = 0.0f; return a0; }
u8 *create_yasminkov_7000v(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x208));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)yasminkov_7000v_ct(temp_r3, tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}
