#include "types.h"
#include "pso/TObject.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/system/ItemEffects.h"
#include "pso/map/FloorArea.h"
extern "C" s32 is_item_area_enabled(s32 area);
#include "pso/item/TUnk_804A2678.h"
#include "pso/system/TUnk_804A2660.h"

#include "dolphin/mtx.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TTecGiFoie.h"
#include "pso/map/FloorArea.h"

extern "C" {
void disallow_rendering__7TObjectFv(TObject *arg0);
void *create_particle_emitter(void *pos, s32 id);
}
int get_item_system_generation(void);
extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 item_follow_effect_vtable[];
u32 __nw__7TObjectFUl(s32 a0 = 0);
s32 get_owner_client__5TItemFv(void *);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 ct__13TUnk_804A0688Fv(s32, u32, s32, s32);
extern s32 tl_05;
void run_task__13TUnk_804A2660Fv(void *arg0);
s8 get_mode__5TItemFv();
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 obj_testFlags30__14TObjCollidableFUl(s32, s32);
void queue_destruction__7TObjectFv(void *);

void render__7TObjectFv();
void render_shadows__7TObjectFv();
s32 item_follow_effect_vtable[6] = { 0, 0, (s32)&destroy_item_follow_effect, (s32)&run_task__13TUnk_804A2660Fv, (s32)&render__7TObjectFv, (s32)&render_shadows__7TObjectFv };
void TUnk_804A2660::run_task() {
    s32 sp8[5];
    s32 var_r31;
    s32 var_r30;

    if ((u32) this->m_28 != get_item_system_generation()) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    var_r31 = 0;
    if ((u32) *(u32 *)&this->unk_24 != 0U) {
        var_r30 = (s32)find_item_by_id(*(s32 *)&this->unk_1C);
        if ((var_r30 != 0) && (get_mode__5TItemFv() == 2)) {
            var_r31 = 1;
            if (((TItemWeapon *)var_r30)->get_joint_position(this->m_20, sp8) != 0) {
                ((TNowLoading *)(*(u32 *)&this->unk_24))->copy_pos(sp8);
                if ((((TItem *)var_r30)->is_hidden() == 0) || (obj_testFlags30__14TObjCollidableFUl(var_r30, 0x08000000) == 0)) {
                    ((TParticleCtrl *)(*(u32 *)&this->unk_24))->clear_active_flag();
                } else {
                    ((TParticleCtrl *)(*(u32 *)&this->unk_24))->enable();
                }
            } else {
                ((TParticleCtrl *)(*(u32 *)&this->unk_24))->enable();
            }
        }
    }
    if (var_r31 == 0) {
        queue_destruction__7TObjectFv(this);
    }
}
}

void *destroy_item_follow_effect(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = item_follow_effect_vtable;
        if (*(void **)((s8 *)arg0 + 0x24) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x24))); }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *construct_item_follow_effect(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Vec position;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = item_follow_effect_vtable;
    disallow_rendering__7TObjectFv((TObject *)(arg0));
    *(s32 *)((s8 *)arg0 + 0x1C) = ((TItem *)arg2)->get_item_id();
    ((TUnk_804A2660 *)arg0)->m_20 = arg3;
    ((TItemWeapon *)arg2)->get_joint_position(((s32)((int) (((TUnk_804A2660 *)arg0)->m_20))), &position);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32)create_particle_emitter((&position), (arg4));
    ((TUnk_804A2660 *)arg0)->m_28 = ((s32)get_item_system_generation());
    return arg0;
}
void spawn_item_follow_effect(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    u32 obj;
    if ((arg0 != 0) && (arg1 != 0U) && ((obj = __nw__7TObjectFUl(0x2C)) != 0U)) {
        construct_item_follow_effect((u8 *)obj, (s32)arg0, (s32)arg1, (s32)arg2, (s32)arg3);
    }
}

void TObjPlayer::cast_gifoie() {
    s32 sp8;
    if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
        if ((((TObjPlayer *)(*(s32 *)&this->unk_F0 + 0x7CC))->get_stage_strike_count() == 0) && (((TItemWeapon *)this)->get_joint_position(0, &sp8) != 0)) {
            TTecGiFoie::create((void *)(*(s32 *)&this->unk_F0), &sp8, (void *)(get_tp()));
            ((TItemWeapon *)this)->roll_technique();
        }
    } else {
        update_active_game_effect();
    }
}
void TObjPlayer__sub_80125C70(void* p) { *(s32*)((char*)p + 0x1f8) = -1; }
void TObjPlayer::create_pro_armor() {
    s32 temp_r3;
    *(s32 *)&this->unk_1F8 = -1;
    if ((u32) *(u32 *)((s8 *)this + 0x174) != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            ct__13TUnk_804A0688Fv(temp_r3, *(u32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x5A);
        }
    }
    ((TItemWeapon *)this)->roll_technique();
    ((TItemWeapon *)this)->roll_technique();
}
void TUnk_804A2678::update_weapon() {
    s32 area;
    area = get_current_floor_area();
    if ((area != (s32) *(s32 *)&this->unk_1F8) && (((TItem *)this)->is_model_shown() != 0)) {
        *(s32 *)&this->unk_1F8 = area;
        if (is_item_area_enabled(area) != 0) {
            spawn_item_follow_effect((s32)tl_05, (u32)this, 1, 0x1AE);
            spawn_item_follow_effect((s32)tl_05, (u32)this, 2, 0x1AE);
        }
    }
}
