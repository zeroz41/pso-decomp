#include "types.h"
#include "versions.h"
#include "pso/network/TProtocol.h"

void bswap_cmd_88_body(void *p);
extern "C" {
s32 copy_entry_table(s32 *);
}
void bswap_cmd_c4_body(void *p);
extern "C" {
s32 copy_cmd_c4_entry_table(s32 *);
}
#if VERSION == VERSION_GPOP8P
extern "C" {
s32 fn_801DFA24(void *p);
void fn_801DF9E8(void *p);
s32 fn_800F9554(u8 *self, s32 arg);
u32 fn_8000F824(u8 *data, s32 len);
void DCFlushRange(void *, u32);
void ICInvalidateRange(void *, u32);
}
#endif

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

#if VERSION == VERSION_GPOP8P
void TProtocol::handle_cmd_B2(packet &pkt) {
    struct {
        packet_header header;
        u32 zero;
        u32 val;
    } msg;
    u8 *p = (u8 *)&pkt;
    u32 zero;

    fn_801DFA24(p);
    if (*(u32 *)(p + 4) != 0) {
        void **obj = (void **)fn_800F9554(p + 0x10, *(s32 *)(p + 4));
        DCFlushRange(p + 0x10, *(u32 *)(p + 4));
        ICInvalidateRange(p + 0x10, *(u32 *)(p + 4));
        __sync();
        __isync();
        zero = ((u32 (*)(void))*obj)();
    } else {
        zero = 0;
    }
    msg.header.command = 0xb3;
    msg.header.flags = p[1];
    msg.header.size = 0xc;
    msg.zero = zero;
    msg.val = fn_8000F824(*(u8 **)(p + 8), *(s32 *)(p + 0xc));
    fn_801DF9E8(&msg);
    send((u8 *)&msg, 0xc);
}
#endif

void TProtocol::handle_cmd_C4(packet &) {
    char sp8[0x1A84];
    s32 (*temp_r12)(s32 *);

    copy_cmd_c4_entry_table((s32 *) sp8);
    bswap_cmd_c4_body((s32 *) sp8);
    temp_r12 = *(s32 (**)(s32 *))((s8 *)this + 0xBC50);
    if (temp_r12 != NULL) {
        temp_r12((s32 *) sp8);
    }
}
