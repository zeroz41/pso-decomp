#include "types.h"
#include "pso/unk/TLobby_80145E40.h"
#include "pso/unk/text_803F4D84.h"
#include "pso/unk/TLobby.h"

    extern unsigned short lbl_805D56CC;
extern "C" {
int TLobby__sub_80145E40(void) {  return (lbl_805D56CC & 0x1); }

s32 TLobby::is_status_zero() {
    u8 sp8;

    if ((TLobby__sub_803F517C(&sp8) == 0) && (sp8 == 0)) {
        return 1;
    }
    return 0;
}

s32 TLobby::is_state_active() {
    u8 sp8;

    if (TLobby__sub_803F5678((&sp8)) != 0) {
        return 0;
    }
    if (sp8 == 0) {
        return 0;
    }
    return (u32) __cntlzw(1 - sp8) >> 5;
}
s32 TLobby__sub_80145EE4(void) {
    u8 sp8;
    if (TLobby__sub_803F5678((&sp8)) != 0) {
        return 0;
    }
    if (sp8 == 0) {
        return 1;
    }
    return (sp8 == 1) ? 0 : 0;
}

s32 memset(void *, s32, s32);
}

extern u16 lbl_805D56CC;

s32 init_struct(u8 *arg0) {
    u8 sp8;

    if (!(lbl_805D56CC & 1)) {
        return 0;
    }
    memset((void *)((int)arg0), 0, 0x26C);
    if (TLobby__sub_803F5678(&sp8) != 0) {
        return 0;
    }
    *(s32 *)((s8 *)arg0 + 4) = (s32) sp8;
    TLobby__sub_803F5748(arg0 + 0xA8);
    TLobby__sub_803F5824(arg0 + 0xAC);
    TLobby__sub_803F5900(arg0 + 0xBC);
    TLobby__sub_803F59DC((char *)(arg0 + 0xC4), 0x40);
    TLobby__sub_803F5B20((char *)(arg0 + 0x144), 0x20);
    TLobby__sub_803F5C58((char *)(arg0 + 0x164), 0x40);
    TLobby__sub_803F5EC8((char *)(arg0 + 0x1A4), 0x40);
    TLobby__sub_803F6000((char *)(arg0 + 0x1E4), 0x20);
    TLobby__sub_803F6138((char *)(arg0 + 0x204), 0x20);
    TLobby__sub_803F6138((char *)(arg0 + 0x204), 0x20);
    TLobby__sub_803F6270((u16 *)(arg0 + 0x244));
    ((TLobby *)(arg0 + 8))->copy_current_entry_name(0x80);
    TLobby__sub_803F4EBC((char *)(arg0 + 0x88), 0x20);
    TLobby__sub_803F4FF4(arg0 + 0xB4);
    TLobby__sub_803F50B8(arg0 + 0xB8);
    return 0;
}

s32 init_work(s32 arg0, u8 *arg1) {
    u8 sp28[0x40];
    u8 dst[0x20];

    memset(arg1, 0, 0x270);
    if (!(lbl_805D56CC & 1)) {
        return 0;
    }
    ((TLobby *)(arg1 + 0x4))->copy_current_entry_name(0x80);
    TLobby__sub_803F4EBC((char *)(arg1 + 0x84), 0x20);
    TLobby__sub_803F4FF4(arg1 + 0x164);
    TLobby__sub_803F50B8(arg1 + 0x168);
    TLobby__sub_803F5C58((char *)(arg1 + 0x16C), 0x20);
    TLobby__sub_803F5D90((char *)(arg1 + 0x18C), 0x40);
    TLobby__sub_803F5EC8((char *)(arg1 + 0x1CC), 0x40);
    TLobby__sub_803F6000((char *)(arg1 + 0x20C), 0x20);
    TLobby__sub_803F6138((char *)(arg1 + 0x22C), 0x20);
    memset(dst, 0, 0x20);
    memset(sp28, 0, 0x40);
    TLobby__sub_803F524C((char *)((s32 *)dst), 0x20);
    TLobby__sub_803F53A0(0, (char *)(arg1 + 0xA4), 0x40);
    TLobby__sub_803F53A0(1, (char *)(arg1 + 0xE4), 0x40);
    TLobby__sub_803F53A0(2, (char *)(arg1 + 0x124), 0x40);
    return 0;
}
