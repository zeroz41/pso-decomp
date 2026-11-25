#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/unk/text_8035B750.h"
#include "pso/unk/text_8035B788.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


BmlResource *nights_npc_resource;

void free_nights_npc_resource(void) {
    if (nights_npc_resource != NULL) {
        delete nights_npc_resource;
        nights_npc_resource = NULL;
    }
}

const char *bm_ene_npc_nights_model_names[2] = { "npc_nights_body.nj", NULL };
const char *bm_ene_npc_nights_motion_names[3] = { "fly_npc_nights_body.njm", "uki_npc_nights_body.njm", NULL };
BmlResourceDescriptor nights_npc_resource_descriptor = { "bm_ene_npc_nights.bml", bm_ene_npc_nights_model_names, bm_ene_npc_nights_motion_names, 1, 2 };

// inferred: the action table both nights NPC spawn bindings point at (motion 0 fly, motion 1 uki)
static TObjMotionAction nights_npc_actions[2] = {
    { 1, 0, 0, 0.6f, 0 },
    { 1, 0, 1, 0.7f, 0 },
};


// inferred: spawn bindings of the two nights NPCs (TLobby::spawn_npc_enemy 0x11 and 0x12)
const NpcAnimationBinding nights_npc_binding_0x11 = { NULL, reinterpret_cast<TObjMotionAction *>(nights_npc_actions), 1, 1, 2 };
const NpcAnimationBinding nights_npc_binding_0x12 = { NULL, reinterpret_cast<TObjMotionAction *>(nights_npc_actions), 0, 0, 2 };
void load_nights_npc_resource(void) {
    BmlResource *resource = new BmlResource(1, &nights_npc_resource_descriptor, 0, 0, NULL);
    nights_npc_resource = resource;
    {
        NpcAnimationBinding r = nights_npc_binding_0x11;
        r.motions = resource->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x11, resource->models->model, resource->models->texlist, &r, 10.0f, 0.0f);
    }
    {
        NpcAnimationBinding r = nights_npc_binding_0x12;
        r.motions = nights_npc_resource->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x12, nights_npc_resource->models->model, nights_npc_resource->models->texlist, &r, 10.0f, 0.0f);
    }
}
