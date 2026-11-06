#include "types.h"
#include "pso/network/TTcpSocket.h"
#include "pso/network/TPacket.h"

extern "C" {

struct Base_80078064_801a5598_801A558C { char pad[0x18]; };
struct VObj_80078064_801a5598_801A558C : Base_80078064_801a5598_801A558C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5();
};

void *TUdpSocket__ct(void *arg0);
s32 __dl__7TObjectFPv(void *);

void TPacket::clear_send_buffer() { *(s32*)((char*)this + 0x8b8) = 0; }

extern s32 __vt__7TPacket[];

void *__dt__7TPacketFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        struct VObj_80078064_801a5598_801A558C *o = (struct VObj_80078064_801a5598_801A558C *)arg0;
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__7TPacket;
        o->m5();
        __dt__10TUdpSocketFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *lbl_805D34C0;

void *TPacket__ct(void *packet) {
    TUdpSocket__ct(packet);
    *(s32 **)((s8 *)packet + 0x18) = __vt__7TPacket;
    *(void **)((s8 *)packet + 0x0) = lbl_805D34C0;
    ((TPacket *)packet)->clear_send_buffer();
    return packet;
}

}
