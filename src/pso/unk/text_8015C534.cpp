#include "types.h"
#include "pso/unk/text_8015C534.h"
#include "pso/unk/text_8018A150.h"
#include "pso/player/TUnk_804B08BC.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8015C534_lbl_804B00C8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015C534_lbl_804B08BC {
    s32 value;
    u8 remaining[0x148];
};

extern "C" {
s32 TLobby__sub_8001FE7C(u32, int);
void mem_free(void *p);
extern u32 ancient_container_resource_bundle;
extern u32 ancient_container_fragment_texture_lists;
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 init_collision_body_parts(void *, void *, int);
}
extern RecoveredGlobal_8015C534_lbl_804B00C8 TOContainerAncientEnemy__collision_body_params;
extern RecoveredGlobal_8015C534_lbl_804B08BC lbl_804B08BC;
extern s32 tl_05;

typedef char RecoveredGlobal_8015C534_lbl_804B00C8_size[sizeof(RecoveredGlobal_8015C534_lbl_804B00C8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015C534_lbl_804B08BC_size[sizeof(RecoveredGlobal_8015C534_lbl_804B08BC) == 0x14C ? 1 : -1];
u8 *init_ancient_container(u8 *arg0, s32 arg1) {
    init_container_base((arg0), (tl_05), (arg1));
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804B08BC.value;
    ((TUnk_804B08BC *)arg0)->mode = 0;
    ((TUnk_804B08BC *)arg0)->actorFlags = (s32) (((TUnk_804B08BC *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (void *)&TOContainerAncientEnemy__collision_body_params.value, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&TOContainerAncientEnemy__collision_body_params.value + 4));
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    ((TUnk_804B08BC *)arg0)->texlist = TObjFish__sub_8001EDB0((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    return arg0;
}

#pragma push
#pragma fp_contract on

void fn_8015C5F8(void) {
    s32 var_r31;
    s32 var_r30;
    u32 p;
    if ((u32) ancient_container_fragment_texture_lists != 0U) {
        var_r30 = 0;
        var_r31 = 0;
        do {
            TObjPlayer::free_if_valid((int) (*(s32 *)((s8 *)ancient_container_fragment_texture_lists + var_r31)));
            var_r30 += 1;
            var_r31 += 4;
        } while (var_r30 < 3);
        p = ancient_container_fragment_texture_lists;
        if (p != 0U) {
            mem_free((void *)p);
            ancient_container_fragment_texture_lists = 0U;
        }
    }
    p = ancient_container_resource_bundle;
    if (p != 0U) {
        TLobby__sub_8001FE7C(p, 1);
        ancient_container_resource_bundle = 0U;
    }
}
#pragma pop
