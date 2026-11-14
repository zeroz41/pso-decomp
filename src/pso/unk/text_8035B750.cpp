#include "types.h"
#include "pso/unk/text_8035B750.h"
#include "pso/unk/text_8035B788.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
void free_bin_model_request(void*, int);
struct Obj_8035B788;
Obj_8035B788 * lbl_805D6F50;

void fn_8035B750(void) {
    if ((u32) lbl_805D6F50 != 0U) {
        free_bin_model_request((void*)lbl_805D6F50, 1);
        lbl_805D6F50 = 0U;
    }
}

}

extern "C" {
const char *bm_ene_npc_nights_model_names[2] = { "npc_nights_body.nj", NULL };
const char *bm_ene_npc_nights_motion_names[3] = { "fly_npc_nights_body.njm", "uki_npc_nights_body.njm", NULL };
BmlResourceDescriptor nights_npc_resource_descriptor = { "bm_ene_npc_nights.bml", bm_ene_npc_nights_model_names, bm_ene_npc_nights_motion_names, 1, 2 };
}

// inferred: the action table both nights NPC spawn bindings point at (motion 0 fly, motion 1 uki)
static TObjMotionAction nights_npc_actions[2] = {
    { 1, 0, 0, 0.6f, 0 },
    { 1, 0, 1, 0.7f, 0 },
};

struct Rec_8035B788 { s32 a; TObjMotionAction *b; s32 c, d; };

struct Inner_8035B788 { u8 pad[8]; s32 x8; NJS_TEXLIST *texlist; };

struct Obj_8035B788 { u8 pad[0x42C]; Inner_8035B788 *x42c; s32 x430; };

extern "C" {
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
// inferred: spawn bindings of the two nights NPCs (TLobby::spawn_npc_enemy 0x11 and 0x12)
const Rec_8035B788 lbl_804798CC = { 0, nights_npc_actions, 0x10001, 0x20000 };
const Rec_8035B788 lbl_804798DC = { 0, nights_npc_actions, 0, 0x20000 };
void fn_8035B788(void) {
    Obj_8035B788 *o = (Obj_8035B788 *)::operator new(0x440);
    if (o != NULL) {
        o = (Obj_8035B788 *)load_resource_from_descriptor(o, 1, &nights_npc_resource_descriptor, 0, 0, 0);
    }
    lbl_805D6F50 = o;
    {
        Rec_8035B788 r = lbl_804798CC;
        r.a = o->x430;
        TLobby::spawn_npc_enemy((s16)0x11, o->x42c->x8, o->x42c->texlist, &r, 10.0f, 0.0f);
    }
    {
        Rec_8035B788 r = lbl_804798DC;
        r.a = lbl_805D6F50->x430;
        TLobby::spawn_npc_enemy((s16)0x12, lbl_805D6F50->x42c->x8, lbl_805D6F50->x42c->texlist, &r, 10.0f, 0.0f);
    }
}

}
