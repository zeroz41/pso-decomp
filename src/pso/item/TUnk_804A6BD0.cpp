// ---- pso/unk/text_80130C2C
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80087278.h"
#include "pso/item/TUnk_804A6BD0.h"
#include "pso/player/TObjPlayer.h"
typedef struct Obj_80130CD8 { u8 pad[0x200]; f32 f200; s32 f204; } Obj_80130CD8;

struct Vec_80130C2C { f32 x, y, z; };

struct Ang_80130C2C { s32 x, y, z; };

struct Obj_80130C2C { u8 pad[0x60]; s32 angle; };

struct Pl_80130C2C {
    u8 pad[0xF0];
    struct Obj_80130C2C *f0;
    u8 padF4[0x204 - 0xF4];
    s32 f204;
};

extern "C" {



f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern s32 tl_05;


void TUnk_804A6BD0::emit_marker_effects() {
    struct Vec_80130C2C pos;
    struct Ang_80130C2C ang;
    struct Vec_80130C2C sp8;
    s32 a;
    ((struct Pl_80130C2C *)this)->f204 = 2;
    a = ((struct Pl_80130C2C *)this)->f0->angle - 0x4000;
    pos.x = sin_table_lookup(a);
    pos.y = 1.0f;
    pos.z = cos_table_lookup(a);
    ang.x = 0x4000;
    ang.y = ((struct Pl_80130C2C *)this)->f0->angle;
    ang.z = 0;
    TObjPlayer::launch_weapon_casing((s32)tl_05, (u32)this, 3, (u32)&pos, (u32)&ang);
    get_joint_position(2, &sp8);
    spawn_particle_effect(&sp8, 9);
}

void TUnk_804A6BD0::update_weapon() {
    Obj_80130CD8 *arg0 = (Obj_80130CD8 *)this;
    f32 temp_f1;
    f32 temp_f2;
    switch (arg0->f204) {
    case 1:
        if (0.0f < arg0->f200) {
            arg0->f200 -= 0.5f;
            if (arg0->f200 <= 0.0f) {
                arg0->f200 = 0.0f;
                arg0->f204 = 0;
            }
        }
        break;
    case 2:
        temp_f2 = arg0->f200;
        if (temp_f2 < 1.4f) {
            temp_f2 += 0.5f;
            arg0->f200 = temp_f2;
            if (1.4f <= arg0->f200) {
                arg0->f200 = 1.4f;
                arg0->f204 = 3;
            }
        }
        break;
    case 3:
        arg0->f204 = 1;
        break;
    }
}

}

// ---- pso/item/TItemEquipVariant_80130D84
#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80130D84.h"
#include "pso/player/TObjPlayer.h"

extern s32 lbl_804A6BD0[];

void *__dt__13TUnk_804A6BD0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6BD0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

// ---- pso/player/TObjPlayer_80130DDC
#include "types.h"
#include "pso/player/TObjPlayer_80130DDC.h"
#include "pso/item/TUnk_804A6BD0.h"
#include "pso/item/TItem.h"

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char spawn_weapon_impact_effect[];

    
    
void* yasminkov_3000r_ct(void* a0) { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)a0 + 0x18) = (int)lbl_804A6BD0; *(int*)((char*)a0 + 0x1f0) = 0; *(int*)((char*)a0 + 0x1ec) = (int)spawn_weapon_impact_effect; *(float*)((char*)a0 + 0x1e4) = 2e+01f; *(float*)((char*)a0 + 0x200) = 0.0f; ((TUnk_804A6BD0 *)a0)->m_1fc = 0.0f; *(float*)((char*)a0 + 0x1f8) = 0.0f; ((TUnk_804A6BD0 *)a0)->m_204 = 0; return a0; }

}
