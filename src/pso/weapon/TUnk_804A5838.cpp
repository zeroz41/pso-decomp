#include "types.h"
#include "pso/weapon/TUnk_804A5838.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecMegid.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

// The timer event class (0x804A0688) has no real constructor yet.
extern "C" s32 ct__13TUnk_804A0688Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);

void TUnk_804A5838::update_idle() {
    rotation_z = 0;
}

void TUnk_804A5838::vfunc_60() {
    if (TObjPlayer::get_player_list() == 0) {
        rotate_matrix_z(NULL, rotation_z);
    }
}

#pragma push
#pragma fp_contract on
void TUnk_804A5838::update_attack() {
    s32 flag;
    s32 ok;
    s32 lo;
    s32 hi;
    f32 frame;
    f32 flo;
    f32 fhi;

    if (owner != NULL) {
        frame = owner->get_frame();
        flag = owner->is_flag_b0_4();
        ok = 1;
        if (owner->test_action_mask(0x20) != 0) {
            flo = 15.6f;
            lo = 0;
            fhi = 20.4f;
            hi = 0x4000;
        } else if (owner->test_action_mask(0x40) != 0) {
            flo = 12.0f;
            lo = 0x4000;
            fhi = 24.0f;
            hi = -0x4000;
        } else if (owner->test_action_mask(0x80) != 0) {
            flo = 14.4f;
            lo = -0x4000;
            fhi = 20.0f;
            hi = 0x2000;
        } else {
            ok = 0;
        }
        if (ok == 1) {
            if (flag == 0) {
                if (frame < flo) {
                    rotation_z = lo;
                } else if (flo <= frame && frame <= fhi) {
                    rotation_z = (s32)((frame - flo) * ((f32)(hi - lo) / (fhi - flo)) + (f32)lo);
                } else {
                    rotation_z = hi;
                }
            } else {
                rotation_z = hi;
            }
        }
    }
}
#pragma pop

void TUnk_804A5838::vfunc_57() {
    void *event;

    if (effect_objects != NULL) {
        if (get_item_index() == 0) {
            event = TItemHeapObject::operator new(0x2C);
            if (event != NULL) {
                ct__13TUnk_804A0688Fv(event, effect_objects, get_owner_client(), 0x96);
            }
        } else {
            event = TItemHeapObject::operator new(0x2C);
            if (event != NULL) {
                ct__13TUnk_804A0688Fv(event, effect_objects, get_owner_client(), 0x5A);
            }
        }
    }
}

void TUnk_804A5838::emit_marker_effects() {
    WeaponVector pos;

    if (get_item_index() == 1) {
        ((TObjPlayer *)tl_05)->create_item_eff_cane(this, 2, 0x101);
        if (is_mode_two_and_ready() != 0) {
            if (get_joint_position(2, &pos) != 0) {
                TTecMegid::create_ex((s32)owner, (s32)&pos, owner->rotation_y, 0);
                ((TObjPlayer *)this)->drain_owner_hp_fraction(0.07f);
            }
        } else {
            ((TObjPlayer *)this)->update_active_game_effect();
        }
    }
}

TUnk_804A5838::TUnk_804A5838(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_z = 0;
    if (get_item_index() == 1) {
        set_weapon_flags(0x22);
    }
}

u8 *create_soul_eater_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A5838(tl_05, item);
    }
    return NULL;
}

TUnk_804A5838::~TUnk_804A5838() {}
