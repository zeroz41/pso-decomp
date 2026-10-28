#include "types.h"
#include "pso/unk/text_8035B788.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80479870[];
extern char lbl_80479884[];
extern char lbl_8047989C[];
extern char lbl_804798B4[];
extern const char *bm_ene_npc_nights_model_names[2];
extern const char *bm_ene_npc_nights_motion_names[3];
extern BmlResourceDescriptor nights_npc_resource_descriptor;
struct Rec_8035B788 { s32 a, b, c, d; };

struct Inner_8035B788 { u8 pad[8]; s32 x8; s32 xc; };

struct Obj_8035B788 { u8 pad[0x42C]; Inner_8035B788 *x42c; s32 x430; };

extern "C" {
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern Rec_8035B788 lbl_804798CC;
extern Rec_8035B788 lbl_804798DC;
extern Obj_8035B788 *lbl_805D6F50;
extern const f32 lbl_805E0140;
extern const f32 lbl_805E0144;
void fn_8035B788(void) {
    Obj_8035B788 *o = (Obj_8035B788 *)::operator new(0x440);
    if (o != NULL) {
        o = (Obj_8035B788 *)load_resource_from_descriptor(o, 1, &nights_npc_resource_descriptor, 0, 0, 0);
    }
    lbl_805D6F50 = o;
    {
        Rec_8035B788 r = lbl_804798CC;
        r.a = o->x430;
        TLobby::spawn_npc_enemy((s16)0x11, o->x42c->x8, o->x42c->xc, (s32)&r, (f32)lbl_805E0140, (f32)lbl_805E0144);
    }
    {
        Rec_8035B788 r = lbl_804798DC;
        r.a = lbl_805D6F50->x430;
        TLobby::spawn_npc_enemy((s16)0x12, lbl_805D6F50->x42c->x8, lbl_805D6F50->x42c->xc, (s32)&r, (f32)lbl_805E0140, (f32)lbl_805E0144);
    }
}

__declspec(section ".data") const char *bm_ene_npc_nights_model_names[2] = { lbl_80479870, NULL };
__declspec(section ".data") const char *bm_ene_npc_nights_motion_names[3] = { lbl_80479884, lbl_8047989C, NULL };
BmlResourceDescriptor nights_npc_resource_descriptor = { lbl_804798B4, bm_ene_npc_nights_model_names, bm_ene_npc_nights_motion_names, 1, 2 };
}
