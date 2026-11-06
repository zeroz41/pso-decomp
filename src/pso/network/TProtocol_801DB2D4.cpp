#include "types.h"
#include "pso/unk/text_801DF280.h"
struct Pkt_801DB2D4 { u32 hdr; u8 body[0x700]; };

extern "C" {
void handle_cmd_C0__9TProtocolFR6packet(u8 *arg0, Pkt_801DB2D4 *arg1);
typedef void (*Fn_801DB2D4)(void *);
void handle_cmd_C0__9TProtocolFR6packet(u8 *arg0, Pkt_801DB2D4 *arg1) {
    Pkt_801DB2D4 tmp = *arg1;
    bswap_c0_lobby_entries(&tmp);
    Fn_801DB2D4 f = *(Fn_801DB2D4 *)(arg0 + 0xBC4C);
    if (f != NULL) {
        f(&tmp);
    }
}

}
