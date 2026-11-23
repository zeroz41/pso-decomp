#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/weapon/TUnk_804A3358.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TargetCursorList.h"
#include "pso/player/CapturedTargetList.h"

struct Rec_80127694 {
    s32 kind;
    s16 uid;
    s16 sub;
    u8 rest[0x5C];
};

extern "C" {
void TUnk_804A3358::emit_marker_effects() {
    u8 pos[12];
    Rec_80127694 rec;
    CapturedTargetList *st;
    get_joint_position(2, pos);
    spawn_particle_effect((const Vec *)pos, 0x1BE);
    get_joint_position(3, pos);
    spawn_particle_effect((const Vec *)pos, 0x1BE);
    get_joint_position(0, pos);
    if (owner->is_status_subsystem_ready() == 2) {
        if (is_identified() == 1) {
            st = owner->get_extended_state();
            if (st->get_captured_target_count() != 0) {
                CapturedTarget *e = st->get_captured_target_entry(0);
                __ct__16TargetCursorListFv((&rec));
                rec.kind = 1;
                rec.uid = e->get_uid();
                rec.sub = e->get_captured_target_collider_index();
                TObjPlayer::create_tec_zonde(owner, pos, &rec, 3);
            }
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}

}

TUnk_804A3358::TUnk_804A3358(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}


TItem *TObjPlayer__sub_801277EC(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A3358(tl_05, item);
    }
    return NULL;
}

TUnk_804A3358::~TUnk_804A3358() {}
