#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/weapon/TUnk_804A2678.h"
#include "pso/item/TUnk_804A0688.h"
#include "pso/system/task/TObject.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/system/ItemEffects.h"
#include "pso/map/FloorArea.h"
#include "pso/system/TUnk_804A2660.h"
#include "dolphin/mtx.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" s32 is_item_area_enabled(s32 area);


int get_item_system_generation(void);
extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 item_follow_effect_vtable[];
void run_task__13TUnk_804A2660Fv(void *arg0);
void __dt__7TObjectFv(void *, int);

void render__7TObjectFv();
void render_shadows__7TObjectFv();
s32 item_follow_effect_vtable[6] = { 0, 0, (saddr)&destroy_item_follow_effect, (saddr)&run_task__13TUnk_804A2660Fv, (saddr)&render__7TObjectFv, (saddr)&render_shadows__7TObjectFv };
void TUnk_804A2660::run_task() {
    s32 sp8[5];
    s32 var_r31;
    saddr item;

    if ((u32) this->m_28 != get_item_system_generation()) {
        queue_destruction();
        return;
    }
    var_r31 = 0;
    if ((u32) *(u32 *)&this->unk_24 != 0U) {
        item = (saddr)find_item_by_id(*(s32 *)&this->unk_1C);
        if ((item != 0) && (((TItem *)item)->get_mode() == 2)) {
            var_r31 = 1;
            if (((TItemWeapon *)item)->get_joint_position(this->m_20, sp8) != 0) {
                ((TParticleCtrl *)*(uaddr *)&this->unk_24)->set_position(sp8);
                if ((((TItem *)item)->is_hidden() == 0) || (((TObjCollidable *)item)->obj_testFlags30(0x08000000) == 0)) {
                    ((TParticleCtrl *)(*(uaddr *)&this->unk_24))->clear_active_flag();
                } else {
                    ((TParticleCtrl *)(*(uaddr *)&this->unk_24))->enable();
                }
            } else {
                ((TParticleCtrl *)(*(uaddr *)&this->unk_24))->enable();
            }
        }
    }
    if (var_r31 == 0) {
        queue_destruction();
    }
}
}

void *destroy_item_follow_effect(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = item_follow_effect_vtable;
        if (*(void **)((s8 *)object + 0x24) != NULL) { ((TObject *)((void *)(*(void **)((s8 *)object + 0x24))))->queue_destruction(); }
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}
u8 *construct_item_follow_effect(u8 *arg0, saddr parent, saddr arg2, s32 arg3, s32 arg4) {
    Vec position;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)parent);
    *(s32 **)((s8 *)arg0 + 0x18) = item_follow_effect_vtable;
    ((TObject *)(arg0))->disallow_rendering();
    *(s32 *)((s8 *)arg0 + 0x1C) = ((TItem *)arg2)->get_item_id();
    ((TUnk_804A2660 *)arg0)->m_20 = arg3;
    ((TItemWeapon *)arg2)->get_joint_position(((s32)((int) (((TUnk_804A2660 *)arg0)->m_20))), &position);
    *(s32 *)((s8 *)arg0 + 0x24) = (saddr)create_particle_emitter((&position), (arg4));
    ((TUnk_804A2660 *)arg0)->m_28 = ((s32)get_item_system_generation());
    return arg0;
}
void spawn_item_follow_effect(saddr arg0, uaddr arg1, s32 arg2, s32 arg3) {
    uaddr obj;
    if ((arg0 != 0) && (arg1 != 0U) && ((obj = (uaddr)TObject::operator new(0x2C)) != 0U)) {
        construct_item_follow_effect((u8 *)obj, (s32)arg0, (s32)arg1, (s32)arg2, (s32)arg3);
    }
}

void TUnk_804A2678::emit_marker_effects() {
    s32 sp8;
    if (is_mode_two_and_ready() != 0) {
        if ((((TObjPlayer *)((u8 *)this->owner + 0x7CC))->get_stage_strike_count() == 0) && (get_joint_position(0, &sp8) != 0)) {
            TTecGiFoie::create(this->owner, &sp8, ((TItemWeapon *)this)->get_tp());
            roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}
void TUnk_804A2678::on_unequipped() { floor_area = -1; }
void TUnk_804A2678::on_equipped() {
    floor_area = -1;
    if (effect_objects != NULL) {
        new TUnk_804A0688(effect_objects, get_owner_client(), 0x5A);
    }
    this->roll_technique();
    this->roll_technique();
}
void TUnk_804A2678::update_weapon() {
    s32 area;
    area = get_current_floor_area();
    if ((area != floor_area) && (this->is_model_shown() != 0)) {
        floor_area = area;
        if (is_item_area_enabled(area) != 0) {
            spawn_item_follow_effect((saddr)tl_05, (uaddr)this, 1, 0x1AE);
            spawn_item_follow_effect((saddr)tl_05, (uaddr)this, 2, 0x1AE);
        }
    }
}

TUnk_804A2678::~TUnk_804A2678() {

}

TUnk_804A2678::TUnk_804A2678(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    ((TObjPlayer *)this)->set_effect_state(10);
    floor_area = -1;
}

TItem *TObjPlayer::create_state_vt2678(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2678(tl_05, item);
    }
    return NULL;
}
