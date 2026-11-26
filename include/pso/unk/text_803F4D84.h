#ifndef PSO_UNK_TEXT_803F4D84_H
#define PSO_UNK_TEXT_803F4D84_H

#include "types.h"

extern "C" {
// Copies the name of the current network configuration entry into dst (len bytes, zero filled).
s32 copy_current_entry_name(char *dst, s32 len);
s32 TLobby__sub_803F4EBC(char *dst, s32 len);
s32 TLobby__sub_803F4FF4(void *dst);
s32 TLobby__sub_803F50B8(void *dst);
s32 TLobby__sub_803F517C(u8 *dst);
s32 TLobby__sub_803F524C(char *dst, s32 len);
s32 TLobby__sub_803F53A0(s32 n, char *dst, s32 len);
s32 TLobby__sub_803F5524(char *dst, s32 len);
s32 TLobby__sub_803F5678(u8 *dst);
s32 TLobby__sub_803F5748(void *dst);
s32 TLobby__sub_803F5824(void *out);
s32 TLobby__sub_803F5900(void *out);
s32 TLobby__sub_803F59DC(char *buf, u32 n);
s32 TLobby__sub_803F5B20(char *buf, s32 n);
s32 TLobby__sub_803F5C58(char *buf, s32 n);
s32 TLobby__sub_803F5D90(char *buf, s32 n);
s32 TLobby__sub_803F5EC8(char *buf, s32 n);
s32 TLobby__sub_803F6000(char *buf, s32 n);
s32 TLobby__sub_803F6138(char *buf, s32 n);
s32 TLobby__sub_803F6270(u16 *out);
}

#endif
