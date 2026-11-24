#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/unk/text_8035B6B0.h"

#include <stddef.h>
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"

// The motion binding the chao NPC passes to TLobby::spawn_npc_enemy (laid out like MojaAnimationBinding).

const char *bm_ene_npc_chao_model_names[2] = { "nps_chao_body.nj", NULL };
const char *bm_ene_npc_chao_motion_names[3] = { "talk_nps_chao_body.njm", "walk_nps_chao_body.njm", NULL };
BmlResourceDescriptor bm_ene_npc_chao_resource_descriptor = {
    "bm_ene_npc_chao.bml", bm_ene_npc_chao_model_names, bm_ene_npc_chao_motion_names, 1, 2
};

// inferred: the chao NPC's action table (motion 0 talk, motion 1 walk), like nights_npc_actions
static TObjMotionAction chao_npc_actions[2] = {
    { 1, 0, 0, 0.8f, 0 },
    { 1, 0, 1, 0.6f, 0 },
};

static const NpcAnimationBinding chao_npc_spawn_descriptor = { NULL, reinterpret_cast<TObjMotionAction *>(chao_npc_actions), 0, 1, 2 };

BmlResource *chao_npc_instance_handle;

void load_and_spawn_chao_npc(void) {
    BmlResource *resource = new BmlResource(1, &bm_ene_npc_chao_resource_descriptor, 0, 0, NULL);
    chao_npc_instance_handle = resource;
    NpcAnimationBinding binding = chao_npc_spawn_descriptor;
    binding.motions = reinterpret_cast<BmlMotionEntry *>(resource->motions);
    TObjNpcEnemy::register_animated_chunk(11, resource->models->model, resource->models->texlist, &binding, 5.0f, 0.0f);
}
