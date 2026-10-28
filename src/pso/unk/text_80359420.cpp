#include "types.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/unk/text_80359420.h"
#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80359420___vt__14TObjNpcNgcBase {
    s32 value;
    u8 remaining[0x174];
};

struct E_803594B4 { s32 a; s32 b; f32 c; };

struct O_803594B4 { u8 pad[0x1c]; s32 idx; E_803594B4 e[2]; };

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
extern RecoveredGlobal_80359420___vt__14TObjNpcNgcBase __vt__14TObjNpcNgcBase;
extern s32 TObjNpcNgcBase__name;
void fn_803594B4(O_803594B4 *self, s32 v, f32 f);
typedef char RecoveredGlobal_80359420___vt__14TObjNpcNgcBase_size[sizeof(RecoveredGlobal_80359420___vt__14TObjNpcNgcBase) == 0x178 ? 1 : -1];
u8 *TObjNpcNgcBase__ct(u8 *player, s32 arg1, s32 arg2, s32 arg3) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &__vt__14TObjNpcNgcBase.value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcNgcBase__name;
    ((TObjNpcNgcBase *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((void *)arg3, 0);
    ((TObjNpcNgcBase *)player)->texlist = TObjFish__sub_8001EDB0((void *)arg3, 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}
void fn_803594B4(O_803594B4 *self, s32 v, f32 f) {
    self->e[self->idx].a = 1;
    self->e[self->idx].b = v;
    self->e[self->idx].c = f;
}

}
