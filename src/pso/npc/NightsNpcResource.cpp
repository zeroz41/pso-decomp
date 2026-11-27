#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/npc/NightsNpcResource.h"
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

// The action table both nights NPC bindings point at (motion 0 fly, motion 1 uki).
static TObjMotionAction nights_npc_actions[2] = {
    { 1, 0, 0, 0.6f, 0 },
    { 1, 0, 1, 0.7f, 0 },
};


// Bindings of the two nights NPC chunks 0x11 (default action 1, uki) and 0x12 (default action 0, fly).
const NpcAnimationBinding nights_npc_uki_binding = { NULL, reinterpret_cast<TObjMotionAction *>(nights_npc_actions), 1, 1, 2 };
const NpcAnimationBinding nights_npc_fly_binding = { NULL, reinterpret_cast<TObjMotionAction *>(nights_npc_actions), 0, 0, 2 };
void load_nights_npc_resource(void) {
    BmlResource *resource = new BmlResource(1, &nights_npc_resource_descriptor, 0, 0, NULL);
    nights_npc_resource = resource;
    {
        NpcAnimationBinding r = nights_npc_uki_binding;
        r.motions = resource->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x11, resource->models->model, resource->models->texlist, &r, 10.0f, 0.0f);
    }
    {
        NpcAnimationBinding r = nights_npc_fly_binding;
        r.motions = nights_npc_resource->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x12, nights_npc_resource->models->model, nights_npc_resource->models->texlist, &r, 10.0f, 0.0f);
    }
}
