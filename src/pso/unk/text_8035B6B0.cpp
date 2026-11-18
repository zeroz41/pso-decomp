#include "types.h"
#include "pso/unk/text_8035B6B0.h"

#include <stddef.h>
#include "pso/system/BmlResourceLoad.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"

// The motion binding the chao NPC passes to TLobby::spawn_npc_enemy (laid out like MojaAnimationBinding).
struct ChaoNpcAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};

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

static const ChaoNpcAnimationBinding chao_npc_spawn_descriptor = { NULL, chao_npc_actions, 1, 2, 0 };

BmlResource *chao_npc_instance_handle;

void load_and_spawn_chao_npc(void) {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_ene_npc_chao_resource_descriptor, 0, 0, 0);
    }
    chao_npc_instance_handle = resource;
    ChaoNpcAnimationBinding binding = chao_npc_spawn_descriptor;
    binding.motions = resource->motions;
    TLobby::spawn_npc_enemy(11, resource->models->model, (NJS_TEXLIST *)resource->models->m_c, &binding, 5.0f, 0.0f);
}
