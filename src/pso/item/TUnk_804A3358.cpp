#include "types.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TUnk_804A3358.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

struct Rec_80127694 {
    s32 kind;
    s16 uid;
    s16 sub;
    u8 rest[0x5C];
};

extern "C" {
void *get_captured_target_entry(void *, int);
void TUnk_804A3358::emit_marker_effects() {
    u8 pos[12];
    Rec_80127694 rec;
    void *st;
    get_joint_position(2, pos);
    spawn_particle_effect(pos, 0x1BE);
    get_joint_position(3, pos);
    spawn_particle_effect(pos, 0x1BE);
    get_joint_position(0, pos);
    if (owner->is_status_subsystem_ready() == 2) {
        if (is_identified() == 1) {
            st = owner->get_extended_state();
            if (get_captured_target_count((s32 *)st) != 0) {
                void *e = get_captured_target_entry(st, 0);
                ((TObjPlayer *)(&rec))->construct_target_cursor_records();
                rec.kind = 1;
                rec.uid = ((TObjPlayer *)e)->get_uid();
                rec.sub = get_captured_target_collider_index(e);
                TObjPlayer::create_tec_zonde(owner, (void *)pos, &rec, (void *)3);
            }
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}

}

TUnk_804A3358::TUnk_804A3358(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

extern "C" {
u8 *TObjPlayer__sub_801277EC(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A3358(tl_05, item);
    }
    return NULL;
}
}

TUnk_804A3358::~TUnk_804A3358() {}
