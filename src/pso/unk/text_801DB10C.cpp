#include "types.h"
#include "pso/network/TProtocol.h"

void bswap_cmd_88_body(void *p);
extern "C" {
s32 copy_entry_table(s32 *);
void fn_801DF42C(void *p);
s32 fn_801DF4FC(s32 *);

void TProtocol::handle_cmd_88(packet &) {
    char sp8[0xC4];
    s32 (*temp_r12)(s32 *);

    copy_entry_table((s32 *) sp8);
    bswap_cmd_88_body((s32 *) sp8);
    temp_r12 = *(s32 (**)(s32 *))((s8 *)this + 0xBC84);
    if (temp_r12 != NULL) {
        temp_r12((s32 *) sp8);
    }
}

void TProtocol::handle_cmd_C4(packet &) {
    char sp8[0x1A84];
    s32 (*temp_r12)(s32 *);

    fn_801DF4FC((s32 *) sp8);
    fn_801DF42C((s32 *) sp8);
    temp_r12 = *(s32 (**)(s32 *))((s8 *)this + 0xBC50);
    if (temp_r12 != NULL) {
        temp_r12((s32 *) sp8);
    }
}
}
