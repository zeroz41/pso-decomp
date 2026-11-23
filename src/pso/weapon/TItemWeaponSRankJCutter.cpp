#include "types.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A4238.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801D2E20.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/object/base/TObjBase.h"
#define SLICER_LAUNCH_STATE_OUT_OF_LINE
#include "pso/weapon/SlicerLaunchState.h"

void enlarge_s_rank_j_cutter_blade(void *arg0);

void TUnk_804A4238::emit_marker_effects() {
    SlicerLaunchState tec;
    TObjPlayer__sub_80128A70();
    init_slicer_launch_state(&tec);
    tec.player_id = owner->get_entity_id();
    tec.item_id = get_item_id();
    tec.texlist = texlist;
    tec.model = second_model;
    tec.attack_kind = TObjPlayer__sub_801D2F4C((s16 *)&owner->attack_state);
    tec.combo_stage = owner->attack_state.get_validated_attack_stage();
    tec.damage_multiplier = owner->query_extended_state();
    tec.color.a = 1.0f;
    tec.color.r = 0.6f;
    tec.color.g = 0.5f;
    tec.color.b = 0.3f;
    tec.facing = owner->rotation_y;
    get_joint_position(3, &tec.first_joint);
    get_joint_position(2, &tec.second_joint);
    TItemAttacker::spawn_item_timer(TTecSlicer::create(&tec), (ItemTimerCallback)enlarge_s_rank_j_cutter_blade, 3);
}

TUnk_804A4238::~TUnk_804A4238() {}

TUnk_804A4238::TUnk_804A4238(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(2);
}

TItem *create_s_rank_j_cutter_weapon(u8 *owner) {
    if (owner != NULL) {
        return new TUnk_804A4238(tl_05, owner);
    }
    return NULL;
}

void enlarge_s_rank_j_cutter_blade(void *object) {
    if (object != NULL) {
        TObjBase *slicer = (TObjBase *)object;
        slicer->scale.x = 1.6f;
        slicer->scale.y = 1.6f;
        slicer->scale.z = 1.6f;
    }
}

void init_slicer_launch_state(void *state) {
    SlicerLaunchState *s = (SlicerLaunchState *)state;
    s->player_id = 0xFFFF;
    s->item_id = -1;
    s->texlist = 0;
    s->attack_kind = -1;
    s->combo_stage = -1;
    s->damage_multiplier = 1.0f;
    s->color.b = 0.0f;
    s->color.g = 0.0f;
    s->color.r = 0.0f;
    s->color.a = 0.0f;
    s->spin_velocity = -0x2AAA;
}
