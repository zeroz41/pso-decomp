#include "types.h"
struct VBase_18_801D9FA0 { char pad[0x18]; };

struct VObj_18_801D9FA0 : VBase_18_801D9FA0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(void *, s32);
};

struct Pkt_801D9FA0 {
    u8 cmd;
    u8 flag;
    u16 size;
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    u32 data[8];
};

extern "C" {
void bswap_packet__9TProtocolFv(void *);
void *memset(void *, int, int);
void send_statistic_aa(VObj_18_801D9FA0 *obj, s16 a, s16 c, s16 d, u32 *src);
void send_statistic_aa(VObj_18_801D9FA0 *obj, s16 a, s16 c, s16 d, u32 *src) {
    Pkt_801D9FA0 pkt;
    s32 i;
    memset(&pkt, 0, 0x2C);
    pkt.cmd = 0xAA;
    pkt.flag = 0;
    pkt.size = 0x2C;
    pkt.a = a;
    pkt.b = 0;
    pkt.c = c;
    pkt.d = d;
    for (i = 0; i < 8; i++) {
        pkt.data[i] = src[i];
    }
    bswap_packet__9TProtocolFv(&pkt);
    obj->m8(&pkt, 0x2C);
}

}
