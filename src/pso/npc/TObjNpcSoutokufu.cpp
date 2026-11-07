#include "types.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_npc_soutokufu_motion_names[1];
extern const char *bm_npc_soutokufu_model_names[2];
const char *bm_npc_soutokufu_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_npc_soutokufu_model_names[2] = { "soutokufu_body.nj", NULL };
BmlResourceDescriptor bm_npc_soutokufu_resource_descriptor = { "bm_npc_soutokufu.bml", bm_npc_soutokufu_model_names, bm_npc_soutokufu_motion_names, 1, 0 };
const char *TObjNpcSoutokufu__name = "TObjNpcSoutokufu";
u32 TObjNpcSoutokufu__shared_model_resource;
}


struct RecoveredGlobal_802895D8_lbl_804D3320 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802895D8_lbl_804D3320_size[sizeof(RecoveredGlobal_802895D8_lbl_804D3320) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80289680___vt__16TObjNpcSoutokufu {
    s32 value;
    u8 remaining[0x174];
};

struct Nd_80289710 { u32 flags; u8 pad4[4]; f32 f8; f32 fc; f32 f10; u8 pad14[0x1C]; Nd_80289710 *next; };

struct Ls_80289710 { u8 pad[0x2C]; Nd_80289710 *head; };

struct Ow_80289710 { u8 pad[0x58]; Ls_80289710 *list; };

struct Gl_80289710 { u8 pad[0x42C]; Ow_80289710 *owner; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 __vt__16TObjNpcSoutokufu[];
f32 calc_sq_offset__12TBoss8DragonFf(void *, void *, f32);
extern void *lbl_805D4DD8;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TObjNpcSoutokufu::close_dialog_window() {
    if ((u32) TObjNpcSoutokufu__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcSoutokufu__shared_model_resource, 1);
        TObjNpcSoutokufu__shared_model_resource = 0U;
    }
}

void TObjNpcSoutokufu::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_npc_soutokufu_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcSoutokufu__shared_model_resource) = var_r0;
}

}
TObjNpcSoutokufu::~TObjNpcSoutokufu() {}
extern "C" {


typedef char RecoveredGlobal_80289680___vt__16TObjNpcSoutokufu_size[sizeof(RecoveredGlobal_80289680___vt__16TObjNpcSoutokufu) == 0x178 ? 1 : -1];
u8 *TObjNpcSoutokufu__ct(u8 *player, s32 arg1, s32 arg2) {
    ((TUnk_804A9F50 *)player)->construct_male_npc_base();
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80289680___vt__16TObjNpcSoutokufu *)&__vt__16TObjNpcSoutokufu).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcSoutokufu__name;
    ((TObjNpcSoutokufu *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcSoutokufu__shared_model_resource)), 0);
    ((TObjNpcSoutokufu *)player)->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TObjNpcSoutokufu__shared_model_resource)), 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void TBoss8Dragon::trigger_switches_in_range(void *arg0, void *arg1, void *arg2) {
    f32 sp[3];
    f32 off;
    Ls_80289710 *list;
    Nd_80289710 *n;
    Ow_80289710 *ow;
    ow = (*(Gl_80289710 * *)&lbl_805D4DD8)->owner;
    list = ow->list;
    off = calc_sq_offset__12TBoss8DragonFf(arg2, ow, 50.0f);
    for (n = list->head; n != NULL; n = n->next) {
        if (!(n->flags & 8) && ((TBoss8Dragon *)arg1)->is_within_xz_distance((u8 *)n, (f32)off) != 0) {
            sp[0] = n->f8;
            sp[1] = n->fc;
            sp[2] = n->f10;
            ((TBoss8Dragon *)sp)->spawn_attack_effect();
            ((TBoss8Dragon *)sp)->spawn_switch_attack();
            n->flags |= 8;
        }
    }
}

}
