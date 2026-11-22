#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/unk/text_8035B750.h"
#include "pso/unk/text_8035B788.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


struct Obj_8035B788;
Obj_8035B788 * lbl_805D6F50;

void fn_8035B750(void) {
    if ((uaddr) lbl_805D6F50 != 0U) {
        delete (BmlResource *)lbl_805D6F50;
        lbl_805D6F50 = 0U;
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


struct Inner_8035B788 { u8 pad[8]; s32 x8; NJS_TEXLIST *texlist; };

struct Obj_8035B788 { u8 pad[0x42C]; Inner_8035B788 *x42c; s32 x430; };


// inferred: spawn bindings of the two nights NPCs (TLobby::spawn_npc_enemy 0x11 and 0x12)
const NpcAnimationBinding lbl_804798CC = { NULL, reinterpret_cast<TObjMotionAction *>(nights_npc_actions), 1, 1, 2 };
const NpcAnimationBinding lbl_804798DC = { NULL, reinterpret_cast<TObjMotionAction *>(nights_npc_actions), 0, 0, 2 };
void fn_8035B788(void) {
    Obj_8035B788 *o = (Obj_8035B788 *)new BmlResource(1, &nights_npc_resource_descriptor, 0, 0, NULL);
    lbl_805D6F50 = o;
    {
        NpcAnimationBinding r = lbl_804798CC;
        r.motions = reinterpret_cast<BmlMotionEntry *>(o->x430);
        NpcModelRegistry::register_animated_chunk((s16)0x11, reinterpret_cast<void *>(o->x42c->x8), reinterpret_cast<void *>(o->x42c->texlist), &r, 10.0f, 0.0f);
    }
    {
        NpcAnimationBinding r = lbl_804798DC;
        r.motions = reinterpret_cast<BmlMotionEntry *>(lbl_805D6F50->x430);
        NpcModelRegistry::register_animated_chunk((s16)0x12, reinterpret_cast<void *>(lbl_805D6F50->x42c->x8), reinterpret_cast<void *>(lbl_805D6F50->x42c->texlist), &r, 10.0f, 0.0f);
    }
}

