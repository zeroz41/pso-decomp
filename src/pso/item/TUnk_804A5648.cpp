#include "types.h"
#include "pso/unk/text_8012CC74.h"
#include "pso/item/TUnk_804A5648.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012CD90.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_8012CE44.h"

struct PlB_8012CCCC { char pad[0x18]; };

struct Pl_8012CCCC : PlB_8012CCCC {
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

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;

void TUnk_804A5648::emit_marker_effects() {
    Pl_8012CCCC *arg0 = (Pl_8012CCCC *)this;
    if (arg0->m49((u8 *)arg0 + 0x1F8, 0, 0, 1) != 0) {
        arg0->m49((u8 *)arg0 + 0x204, 0, 0, 0);
    } else {
        arg0->m49((u8 *)arg0 + 0x204, 0, 0, 1);
    }
}

void TUnk_804A5648::reserved_53() {
    u8 *arg0 = (u8 *)this;
    ((TObjPlayer *)arg0)->draw_status_icons(arg0 + 0x1F8, arg0 + 0x204);
}

extern s32 lbl_804A5648[];

void *__dt__13TUnk_804A5648Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5648;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char spawn_shoot_particle_9f[];
void*TUnk_804A5648::enter_state_515() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A5648; set_weapon_flags(515); *(int*)((char*)this + 0x1f0) = (int)spawn_shoot_particle_9f; (*(float *)((u8 *)this + 0x1E4)) = 11.0f; return this; }

}

extern "C" {
u8 * enter_state_515__13TUnk_804A5648Fv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_8012CE44(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x210));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(enter_state_515__13TUnk_804A5648Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
