#include "types.h"
#include "pso/unk/text_80209584.h"
#include "pso/unk/text_8020A2AC.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 run_step__9TItemDropFl(int, void *);
s32 __cvt_fp2unsigned(f32);
s32 rand();
extern s32 item_drop_rng;
extern s32 lbl_805D60A4;
extern s32 item_drop_server_seed;
extern const f32 lbl_805DC618;
extern const f32 lbl_805DC61C;
void TLobby__sub_8020A2AC(void) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        item_drop_server_seed = __cvt_fp2unsigned((f32) (lbl_805DC618 * (lbl_805DC61C * (f32) rand())));
    }
    temp_r3 = (int)::operator new(0xE8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = run_step__9TItemDropFl((int)temp_r3, (void *)item_drop_server_seed);
    }
    item_drop_rng = var_r0;
    temp_r3_2 = (int)::operator new(0x14);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = (s32)TLobby__sub_80209584((u8 *)temp_r3_2, 0x20);
    }
    lbl_805D60A4 = var_r0_2;
}

}
