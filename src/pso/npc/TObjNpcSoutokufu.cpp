#include "types.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/TObjBoss5FloorStone.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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
extern RecoveredGlobal_802895D8_lbl_804D3320 bm_npc_soutokufu_resource_descriptor;
extern u32 TObjNpcSoutokufu__shared_model_resource;
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 __vt__16TObjNpcSoutokufu[];
extern s32 TObjNpcSoutokufu__name;
f32 calc_sq_offset__12TBoss8DragonFf(void *, void *, f32);
extern void *lbl_805D4DD8;
extern const f32 lbl_805DD8E8;
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
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_npc_soutokufu_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcSoutokufu__shared_model_resource) = var_r0;
}

void *__dt__16TObjNpcSoutokufuFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjNpcSoutokufu;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 boss5_common_texture_list;

typedef char RecoveredGlobal_80289680___vt__16TObjNpcSoutokufu_size[sizeof(RecoveredGlobal_80289680___vt__16TObjNpcSoutokufu) == 0x178 ? 1 : -1];
u8 *TObjNpcSoutokufu__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80289680___vt__16TObjNpcSoutokufu *)&__vt__16TObjNpcSoutokufu).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcSoutokufu__name;
    ((TObjNpcSoutokufu *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcSoutokufu__shared_model_resource)), 0);
    ((TObjNpcSoutokufu *)player)->texture_id = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TObjNpcSoutokufu__shared_model_resource)), 0);
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
    off = calc_sq_offset__12TBoss8DragonFf(arg2, ow, lbl_805DD8E8);
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

void TObjBoss5FloorStone::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        ((TObjBoss5FloorStone *)boss5_common_texture_list)->render_impl((void*)(*(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4DD8 + 0x42C)) + 0x58)));
    }
}

void TObjBoss5FloorStone::run_task() {  }

}
