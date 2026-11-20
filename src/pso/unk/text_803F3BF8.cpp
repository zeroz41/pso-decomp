#include "types.h"
#include "versions.h"
#include "pso/unk/text_803F3BF8.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F3CF4.h"
#include "pso/network/NetworkInfoLoader.h"
#include <dolphin/os/OSAlloc.h>

// First function of the ntInf library: it publishes the library's version
// string ("ntInf Ver 1.17.00 Build:Jul  9 2002").
extern "C" {
extern const char *ntinf_version_ref;
#ifndef TEXT_803F3BF8_SECOND_FILE
#if VERSION == VERSION_GPOP8P
char lbl_804FCE38[] = "\nntInf Ver 1.30.02 Build:Nov 21 2002 21:38:56\n";
#else
char lbl_804FCE38[] = "\nntInf Ver 1.17.00 Build:Jul  9 2002 09:41:44\n";
#endif
#if VERSION == VERSION_GPOP8P
__declspec(section ".sdata2") extern const char *const lbl_805E10F8 = lbl_804FCE38;
#else
extern const char *const lbl_805E10F8 = lbl_804FCE38;
#endif
// 32-byte aligned like the other ntInf globals (0x805D7980, 0x805D79A0, 0x805D79C0, 0x805D79E0).
s32 lobby_net_config_mode __attribute__((aligned(32)));
// inferred: a second copy of the mode argument; only this function writes it, nothing reads it
s32 lbl_805D7984;
#if VERSION == VERSION_GPOP8P
__declspec(section ".sdata") u8 lbl_805D7988[0x18];
#endif
#endif
extern s32 lobby_net_config_load_state;
extern u8 *lobby_net_config_buffer;
extern u8 *lobby_net_config_card_base;

#ifndef TEXT_803F3BF8_SECOND_FILE
#if VERSION != VERSION_GPOP8P
#pragma push
#pragma scheduling off
#pragma opt_dead_assignments off
// The caller's work buffer is declared 32-byte aligned like lobby_net_config_buffer it lands in; GC/1.3 gives
// the parameter an aligned home, hence the 32-aligned frame.
s32 TLobby__sub_803F3BF8(s32 backup_mode, void *buffer __attribute__((aligned(32))), s32 mode) {
    ntinf_version_ref = lbl_805E10F8;
    if (get_network_config_mode() != 0) {
        return -1;
    }
    lobby_net_config_mode = mode;
    lbl_805D7984 = mode;
    if (backup_mode != 0) {
        return -2;
    }
    get_or_set_network_config_mode(1);
    get_or_set_network_config_backup_mode(backup_mode);
    lobby_net_config_load_state = 0;
    if (buffer == NULL) {
        lobby_net_config_buffer = (u8 *)OSAllocFromHeap(__OSCurrHeap, get_network_config_buffer_size(backup_mode));
        if (lobby_net_config_buffer == NULL) {
            return -4;
        }
        lobby_net_config_load_state = 1;
    } else {
        lobby_net_config_buffer = (u8 *)buffer;
    }
    if (backup_mode == 1) {
        lobby_net_config_card_base = lobby_net_config_buffer + 0x19D4;
    }
    set_network_config_card_channel(2);
    return 0;
}
#pragma pop
#endif

#if VERSION == VERSION_GPOP8P
s32 memset(void *, int, int);
char *strcpy(char *, const char *);
extern s32 lbl_805D7984;
extern s32 lobby_net_config_mode;
extern s32 lobby_net_config_load_state;
s32 get_or_set_network_config_backup_mode__Fl(s32 x);
s32 get_network_config_buffer_size__Fl(s32 mode);
void set_network_config_card_channel__Fl(s32 v);
s32 get_network_config_mode__Fv(void);
s32 get_or_set_network_config_mode__Fl(s32 x);
void fn_803F2710(s32 x);
void fn_803F1C10(s32 arg0);
void fn_803F2C18(void);
extern char lbl_804FDCE8[6][0x20];
extern char lbl_804FDDA8[];
extern char lbl_804FDDC8[];
extern char lbl_804FCEA4[];
extern char lbl_804FCEB4[];
extern char lbl_804FCEC4[];
extern char default_player_name[];
extern char lbl_804FCEE4[];
extern char lbl_804FCF18[];
extern char lbl_804FDE48[];
extern char lbl_804FDE54[];
extern char lbl_804FDE60[];
extern char lbl_804FDE6C[];
extern char lbl_804FDE78[];
extern char lbl_804FDE84[];
extern char lbl_804FDE90[];
extern u8 lbl_805D7988[];

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F3BF8(s32 a, void *b, s32 c) {
    ntinf_version_ref = lbl_805E10F8;
    if (get_network_config_mode__Fv() != 0) {
        return -1;
    }
    lobby_net_config_mode = c;
    lbl_805D7984 = c;
    if (a != 0) {
        return -2;
    }
    get_or_set_network_config_mode__Fl(1);
    get_or_set_network_config_backup_mode__Fl(a);
    lobby_net_config_load_state = 0;
    if (b == 0) {
        lobby_net_config_buffer = (u8*)OSAllocFromHeap(__OSCurrHeap, get_network_config_buffer_size__Fl(a));
        if (lobby_net_config_buffer == NULL) {
            return -4;
        }
        lobby_net_config_load_state = 1;
    } else {
        lobby_net_config_buffer = (u8 *)b;
    }
    if (a == 1) {
        lobby_net_config_card_base = lobby_net_config_buffer + 0x19d4;
    }
    set_network_config_card_channel__Fl(2);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
void fn_803F2694(u32 x) {
    s32 r;
    fn_803F2710(x);
    fn_803F2C18();
    switch ((u8)x) {
    case 0x90:
    default:
        r = 0;
        break;
    case 0x80:
        r = 1;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        r = 2;
        break;
    }
    fn_803F1C10(r);
}
#pragma pop

#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma peephole off
#pragma scheduling off
void fn_803F2710(s32 c) {
    void strncpy(void *dst, void *src, s32 n);

    memset(lbl_804FDCE8, 0, 0xc0);
    memset(lbl_804FDDA8, 0, 0x20);
    switch ((u8)c) {
    case 0x90:
    default:
            strncpy(lbl_804FDCE8[0], lbl_804FDDC8, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_804FCEA4, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_804FCEB4, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_804FCEC4, 0x20);
        strncpy(lbl_804FDCE8[4], default_player_name, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_804FCEE4, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FCF18, 0x20);
        lbl_805D7988[0] = 0;
        break;
    case 0x80:
        strncpy(lbl_804FDCE8[0], lbl_804FDE48, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_804FDE54, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_804FDE60, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_804FDE6C, 0x20);
        strncpy(lbl_804FDCE8[4], lbl_804FDE78, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_804FDE84, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FDE90, 0x20);
        lbl_805D7988[0] = 0xb5;
        break;
    case 0:
        strncpy(lbl_804FDCE8[0], lbl_804FDE48, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_804FDE54, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_804FDE60, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_804FDE6C, 0x20);
        strncpy(lbl_804FDCE8[4], lbl_804FDE78, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_804FDE84, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FDE90, 0x20);
        lbl_805D7988[0] = 0xb4;
        break;
    case 1:
        strncpy(lbl_804FDCE8[0], lbl_805D090C, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_805D0914, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_805D091C, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_805D0924, 0x20);
        strncpy(lbl_804FDCE8[4], lbl_805D092C, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_805D0934, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FDE90, 0x20);
        lbl_805D7988[0] = 0x42;
        break;
    case 2:
        strncpy(lbl_804FDCE8[0], lbl_805D090C, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_805D0914, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_805D091C, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_805D0924, 0x20);
        strncpy(lbl_804FDCE8[4], lbl_805D092C, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_805D0934, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FDE90, 0x20);
        lbl_805D7988[0] = 0x3d;
        break;
    case 3:
        strncpy(lbl_804FDCE8[0], lbl_805D090C, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_805D0914, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_805D091C, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_805D0924, 0x20);
        strncpy(lbl_804FDCE8[4], lbl_805D092C, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_805D0934, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FDE90, 0x20);
        lbl_805D7988[0] = 0xa0;
        break;
    case 4:
        strncpy(lbl_804FDCE8[0], lbl_805D090C, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_805D0914, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_805D091C, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_805D0924, 0x20);
        strncpy(lbl_804FDCE8[4], lbl_805D092C, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_805D0934, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FDE90, 0x20);
        lbl_805D7988[0] = 0xb4;
        break;
    case 5:
        strncpy(lbl_804FDCE8[0], lbl_805D090C, 0x20);
        strncpy(lbl_804FDCE8[1], lbl_805D0914, 0x20);
        strncpy(lbl_804FDCE8[2], lbl_805D091C, 0x20);
        strncpy(lbl_804FDCE8[3], lbl_805D0924, 0x20);
        strncpy(lbl_804FDCE8[4], lbl_805D092C, 0x20);
        strncpy(lbl_804FDCE8[5], lbl_805D0934, 0x20);
        strncpy(lbl_804FDDA8, lbl_804FDE90, 0x20);
        lbl_805D7988[0] = 0x7b;
        break;
    }
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma optimization_level 1
void fn_803F2C18(void) {
  s32 j;
  s32 off;
  char *src;
  char *d;
  s32 k;
  s16 i;
  for (i = 0; i < 6; i++)
  {
    memset((*(char **)&lobby_net_config_buffer) + (off = (j = i) * 0x28) + 8, 0, 0x20);
    d = (*(char **)&lobby_net_config_buffer) + off + 8;
    src = lbl_804FDCE8[j];
    strcpy(d, src);
    strcpy((*(char **)&lobby_net_config_buffer) + (k = j * 0x210) + 0xf8, src);
    ((*(char **)&lobby_net_config_buffer))[k + 0x20a] = lbl_805D7988[0];
  }
  strcpy((*(char **)&lobby_net_config_buffer) + 0xe5c, lbl_804FDDA8);
}
#pragma pop

// Default provider names (Shift-JIS "provider 0".."provider 5", isao.net) and their European replacements.
char lbl_804FDCE8[6][0x20] = {
    "\203v\203\215\203o\203C\203_\202O",
    "\203v\203\215\203o\203C\203_\202P",
    "\203v\203\215\203o\203C\203_\202Q",
    "\203v\203\215\203o\203C\203_\202R",
    "\203v\203\215\203o\203C\203_\202S",
    "\203v\203\215\203o\203C\203_\202T",
};
char lbl_804FDDA8[0x20] = "isao.net\203\201\201[\203\213\203A\203J\203E\203\223\203g";
char lbl_804FDDC8[] = "isao.net\203v\203\215\203o\203C\203_";
char lbl_804FCEA4[] = "\203v\203\215\203o\203C\203_\202P";
char lbl_804FCEB4[] = "\203v\203\215\203o\203C\203_\202Q";
char lbl_804FCEC4[] = "\203v\203\215\203o\203C\203_\202R";
char default_player_name[] = "\203v\203\215\203o\203C\203_\202S";
char lbl_804FCEE4[] = "\203v\203\215\203o\203C\203_\202T";
char lbl_804FCF18[] = "isao.net\203\201\201[\203\213\203A\203J\203E\203\223\203g";
char lbl_804FDE48[] = "Provider 0";
char lbl_804FDE54[] = "Provider 1";
char lbl_804FDE60[] = "Provider 2";
char lbl_804FDE6C[] = "Provider 3";
char lbl_804FDE78[] = "Provider 4";
char lbl_804FDE84[] = "Provider 5";
char lbl_804FDE90[] = "isao.net Mail Account";

#endif
#endif

}

#if VERSION != VERSION_GPOP8P || defined(TEXT_803F3BF8_SECOND_FILE)
#pragma push
#pragma peephole off
s32 update_network_info_request(void) {
    if (get_network_config_mode() == 0) {
        return -1;
    }
    switch (network_info_load_state.request_kind) {
    case 2:
        update_network_info_load();
        break;
    case 1:
        update_network_info_exists();
        break;
    case 3:
    case 4:
        break;
    }
    return 0;
}
#pragma pop


extern "C" {

s32 TLobby__sub_803F3D60(void) {
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (lobby_net_config_load_state == 1 && lobby_net_config_buffer != NULL) {
        OSFreeToHeap(__OSCurrHeap, lobby_net_config_buffer);
        lobby_net_config_buffer = NULL;
    }
    get_or_set_network_config_mode(0);
    get_or_set_network_config_backup_mode(0);
    set_network_config_card_channel(2);
    return 0;
}

}

#if VERSION == VERSION_GPOP8P
#pragma push
#pragma scheduling off
#pragma peephole off
s32 request_network_info_load(s32 a, void *b) {
    NetworkInfoLoadState *p;
    s32 *q;
    switch (get_network_config_mode()) {
    case 0:
        return -1;
    case 2:
    case 3:
    default:
        return -5;
    case 1:
        break;
    }
    p = &network_info_load_state;
    q = (s32 *)&p->request_kind;
    if (*q != 0) {
        return -4;
    }
    set_network_config_card_channel(a);
    *q = 2;
    p->phase = 3;
    p->caller_buffer = b;
    p->result = 200;
    return 0;
}
#pragma pop
#endif
#endif
