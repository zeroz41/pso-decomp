#include "pso/unk/text_80066F10.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/galgryphon/TObjBoss5FloorStone.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80066F5C.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/system/NinjaTypes.h"

#pragma readonly_strings on

// Shows the switch hit effects of every visible floor stone node within the attack's range of pos
// and hides those nodes.
void TObjBoss5FloorStone::trigger_switches_in_range(const Vec *pos, const DragonAttackParams *params) {
    Vec effect_pos;
    f32 range_squared;
    NJS_OBJECT *root;
    NJS_OBJECT *node;
    BmlModelEntry *models;
    models = boss5_common_bml_resource->models;
    root = models[5].model;
    range_squared = TBoss8Dragon::calc_sq_offset(params, 50.0f);
    for (node = root->child; node != NULL; node = node->sibling) {
        if (!(node->evalflags & NJD_EVAL_HIDE) && TBoss8Dragon::is_within_xz_distance(pos, node, range_squared) != 0) {
            effect_pos.x = node->pos[0];
            effect_pos.y = node->pos[1];
            effect_pos.z = node->pos[2];
            TBoss5Gryphon::spawn_attack_effect(&effect_pos);
            TBoss5Gryphon::spawn_switch_attack(&effect_pos);
            node->evalflags |= NJD_EVAL_HIDE;
        }
    }
}

const char *TObjBoss5FloorStone__name = "TObjBoss5FloorStone";

void TObjBoss5FloorStone::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
    draw_shadowed_object(boss5_common_texture_list, boss5_common_bml_resource->models[5].model);
    }
}

void TObjBoss5FloorStone::run_task() {  }

TObjBoss5FloorStone::~TObjBoss5FloorStone() {}

TObjBoss5FloorStone::TObjBoss5FloorStone(TObject *parent) : TObject(parent) {
    m_name = TObjBoss5FloorStone__name;
}

void *TObjBoss5FloorStone::create() {
    return new TObjBoss5FloorStone(tl_02);
}
