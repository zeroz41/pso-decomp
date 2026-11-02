#include "pso/network/NetworkTransport.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "dolphin/exi.h"
#include "dolphin/os.h"
#include "dolphin/os/OSReset.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TUdpSocket.h"

struct RecoveredGlobal_80428374_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

struct RecoveredGlobal_8042839C_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_1C { u8 bytes[0x1c]; };

struct RecoveredGlobal_8042E768_lbl_805D1D20 {
    s32 value;
    s32 f4;
    s32 f8;
    char carrier[5];
    char error_control[5];
    char compression[6];
};

struct ModemExiState {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 pad_10[0x18];
    s32 f28;
    u8 pad_2C[0x10];
    s32 f3C;
    s32 f40;
    s32 f44;
    u8 pad_48[0x10];
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad_68[8];
};

struct ModemResponseState {
    void (*callback)(s32 result);
    s32 done;
    s32 result;
    s32 fifo_count;
    s32 length;
    u8 buf[0x80];
};

struct RecoveredGlobal_80427D0C_lbl_805CFC20 {
    s32 value;
    u8 remaining[0xE1C];
};

struct RecoveredGlobal_80428360_lbl_805CFC20 {
    s16 value;
    u8 remaining[0xE1E];
};

struct RecoveredGlobal_8042DD70_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

typedef struct Names_8042E57C {
    char *name[6];
} Names_8042E57C;

typedef struct Names_8042E628 {
    char *name[4];
} Names_8042E628;

typedef struct Names_8042E6C4 {
    char *name[5];
} Names_8042E6C4;

typedef struct Names_8042E7B8 {
    char *name[3];
} Names_8042E7B8;

typedef struct Ent_80426894 {
    s16 count;
    u8 id[6];
} Ent_80426894;

typedef struct Tbl_80426894 {
    u8 pad[6];
    Ent_80426894 ent[6];
} Tbl_80426894;

typedef struct Ent_80425870 {
    s32 used;
    u32 f4;
    u32 base;
} Ent_80425870;

typedef struct Ent_80427C6C {
    u16 pad0;
    u16 id;
    u8 rest[0xE10];
} Ent_80427C6C;

extern "C" {
extern u8 lbl_805CF240[0xA0];
extern u8 TLobby__pppoe_message_queue[0xA0];
extern u8 lbl_805CF380[0x48];
extern OSThreadQueue lbl_805D7CA0;
void TAdSinglePlyChrSelectGC__sub_8042DE20(void);
static RecoveredGlobal_8042E768_lbl_805D1D20 modem_connection_info;
static ModemResponseState modem_command_response_state;
int atoi(const char *);
void *memcpy(void *, const void *, unsigned long);
void *memmove(void *, const void *, unsigned long);
int sscanf(const char *, const char *, ...);
extern s32 lbl_805D7C98;
void TAdSinglePlyChrSelectGC__sub_8042D6A4(char *str);
extern s32 lbl_805D4918;
extern u8 lbl_805CF380[];
extern u8 TLobby__pppoe_message_queue[];
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

extern u8 lbl_805CF240[];
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
s32 TAdSinglePlyChrSelectGC__sub_8042D49C(char *cmd);
extern Names_8042E57C TAdSinglePlyChrSelectGC__modem_type_names;
extern char lbl_805D48AC[2];
extern char lbl_805D495C[7];
extern Names_8042E628 TAdSinglePlyChrSelectGC__modem_error_correction_names;
extern char modem_error_correction_command_prefix[7];
extern Names_8042E6C4 TAdSinglePlyChrSelectGC__modem_compression_names;
extern char lbl_805D4980[5];
extern Names_8042E7B8 lbl_80480234;
extern char lbl_805D4988[4];
void *memset(void *, int, unsigned long);
struct ModemRegs_805D7C90 { u16 f0; u16 f2; u8 f4; u8 f5; u8 f6; u8 f7; };
extern ModemRegs_805D7C90 lbl_805D7C90;
static ModemExiState modem_exi_state;
extern s32 lbl_805D7C9C;
s32 TAdSinglePlyChrSelectGC__sub_8042E184(void);
unsigned long strlen(const char *);
int memcmp(const void *, const void *, unsigned long);
extern char lbl_805D4914[4];
extern char *modem_exi_ptr_table[22];
s32 TAdSinglePlyChrSelectGC__sub_8042CD64(void);
void TAdSinglePlyChrSelectGC__sub_8042D604(void);
void TAdSinglePlyChrSelectGC__sub_8042E488(u8 value);

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma pop

#define arg0 ((s32)argp)
#undef arg0

#pragma push
#pragma dont_inline on
#pragma pop

typedef char RecoveredGlobal_80427D0C_lbl_805CFC20_size[sizeof(RecoveredGlobal_80427D0C_lbl_805CFC20) == 0xE20 ? 1 : -1];

typedef char RecoveredGlobal_80428374_lbl_805D0A40_size[sizeof(RecoveredGlobal_80428374_lbl_805D0A40) == 0x60 ? 1 : -1];

typedef char RecoveredGlobal_80428360_lbl_805CFC20_size[sizeof(RecoveredGlobal_80428360_lbl_805CFC20) == 0xE20 ? 1 : -1];

typedef char RecoveredGlobal_8042839C_lbl_805D0A40_size[sizeof(RecoveredGlobal_8042839C_lbl_805D0A40) == 0x60 ? 1 : -1];

void TAdSinglePlyChrSelectGC::wake_load_thread() {
    OSWakeupThread(&lbl_805D7CA0);
}

static OSResetFunctionInfo modem_reset_function_info = {
    (OSResetFunction)TAdSinglePlyChrSelectGC::send_modem_hangup, 127
};

void TAdSinglePlyChrSelectGC__sub_8042C8D8(void) {
    u8 *p;
    u8 *line;
    u8 *end;
    s32 len;

    end = modem_command_response_state.buf + modem_command_response_state.length;

    for (line = modem_command_response_state.buf; *line == 13 || *line == 10; line++) {
    }
    for (p = modem_command_response_state.buf; p < end; p++) {
        if (*p != 13 || line >= p) {
            continue;
        }
        len = p - line;
        if (len == 2 && memcmp(line, "OK", 2) == 0) {
        } else if (len > 7 && memcmp(line, "CONNECT", 7) == 0) {
            lbl_805D7C98 = 3;
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 3;
            }
            modem_connection_info.value = atoi((char *)line + 8);
        } else if (len >= 9 && memcmp(line, "+MCR: ", 6) == 0) {
            memcpy(modem_connection_info.carrier, line + 6, len - 6);
            modem_connection_info.carrier[len - 6] = 0;
        } else if (len >= 8 && memcmp(line, "+DR: ", 5) == 0) {
            memcpy(modem_connection_info.compression, line + 5, len - 5);
            modem_connection_info.compression[len - 5] = 0;
        } else if (len >= 8 && memcmp(line, "+ER: ", 5) == 0) {
            memcpy(modem_connection_info.error_control, line + 5, len - 5);
            modem_connection_info.error_control[len - 5] = 0;
        } else if (len > 5 && memcmp(line, "+MRR: ", 5) == 0) {
            sscanf((char *)line + 5, "%d,%d", &modem_connection_info.f4, &modem_connection_info.f8);
        } else if ((len == 4 && memcmp(line, "ATE0", 4) == 0) || (len == 5 && memcmp(line, "ERROR", 5) == 0)) {
        } else if (len == 10 && memcmp(line, "NO CARRIER", 10) == 0) {
            lbl_805D7C98 = 1;
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 1;
            }
        } else if (len == 11 && memcmp(line, "NO DIALTONE", 11) == 0) {
            lbl_805D7C98 = 1;
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 0;
            }
        } else if (len == 4 && memcmp(line, "BUSY", 4) == 0) {
            lbl_805D7C98 = 1;
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 2;
            }
        } else if (len == 4 && memcmp(line, "RING", 4) == 0) {
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 4;
            }
        } else if (len == 9 && memcmp(line, "NO ANSWER", 9) == 0) {
            lbl_805D7C98 = 1;
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 5;
            }
        } else if (len >= 7 && memcmp(line, "DELAYED", 7) == 0) {
            lbl_805D7C98 = 1;
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 6;
            }
        } else if (len == 11 && memcmp(line, "BLACKLISTED", 11) == 0) {
            lbl_805D7C98 = 1;
            if (modem_command_response_state.callback != NULL) {
                modem_command_response_state.done = 1;
                modem_command_response_state.result = 7;
            }
        }
        for (line = p; *line == 13 || *line == 10; line++) {
        }
        if (line >= end) {
            line = NULL;
        }
    }
    if (line != NULL && end > line) {
        if (line != modem_command_response_state.buf) {
            modem_command_response_state.length = end - line;
            memmove(modem_command_response_state.buf, line, modem_command_response_state.length);
        }
    } else {
        modem_command_response_state.length = 0;
    }
}

void TAdSinglePlyChrSelectGC__sub_8042D604(void) {
    s32 e;
    memset(&modem_connection_info, 0, sizeof(modem_connection_info));
    lbl_805D7C98 = 1;
    e = OSDisableInterrupts();
    for (;;) {
        if (EXILock(0, 2, (EXICallback)TAdSinglePlyChrSelectGC::wake_load_thread) == 1) {
            OSRestoreInterrupts(e);
            break;
        }
        OSSleepThread(&lbl_805D7CA0);
        OSRestoreInterrupts(e);
    }
    TAdSinglePlyChrSelectGC__sub_8042D6A4((char *)&lbl_805D4918);
    EXIUnlock(0);
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8042DD70_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042DD70_lbl_805D1D20) == 0x1C ? 1 : -1];
s32 TAdSinglePlyChrSelectGC__sub_8042DD70(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_8042DD70_lbl_805D1D20 *)&modem_connection_info).value) + 0xB0) != 0) {
        return -4;
    }
    if ((s32) lbl_805D7C98 != 3) {
        return -7;
    }
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8042DD70_lbl_805D1D20 *)&modem_connection_info).value) + 0xB0) = 1;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8042DD70_lbl_805D1D20 *)&modem_connection_info).value) + 0xB4) = arg0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8042DD70_lbl_805D1D20 *)&modem_connection_info).value) + 0xBC) = arg1;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8042DD70_lbl_805D1D20 *)&modem_connection_info).value) + 0xB8) = arg1;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8042DD70_lbl_805D1D20 *)&modem_connection_info).value) + 0xD8) = arg2;
    TAdSinglePlyChrSelectGC__sub_8042DDE4(0, 0);
    return 1;
}
#pragma pop

void TAdSinglePlyChrSelectGC__sub_8042DDE4(int _w0, int _w1) {
    if (EXILock(0, 2, (EXICallback)TAdSinglePlyChrSelectGC__sub_8042DDE4) != 0) {
        TAdSinglePlyChrSelectGC__sub_8042DE20();
    }
}

typedef char RecoveredGlobal_8042E768_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042E768_lbl_805D1D20) == 0x1C ? 1 : -1];

s32 TAdSinglePlyChrSelectGC::send_at_ms_command(s32 arg0) {
    char buf[0x80];
    s32 pad;
    Names_8042E57C names = TAdSinglePlyChrSelectGC__modem_type_names;
    if (arg0 <= 0 || arg0 >= 5) {
        return -2;
    }
    strcpy(buf, lbl_805D495C);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
    return 1;
}

s32 TAdSinglePlyChrSelectGC::send_at_error_correction_cmd(s32 arg0) {
    char buf[0x80];
    s32 pad;
    Names_8042E628 names = TAdSinglePlyChrSelectGC__modem_error_correction_names;
    if (arg0 <= 0 || arg0 > 3) {
        return -2;
    }
    strcpy(buf, modem_error_correction_command_prefix);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
    return 1;
}

s32 TAdSinglePlyChrSelectGC::send_at_compression_cmd(s32 arg0) {
    char buf[0x80];
    s32 pad;
    Names_8042E6C4 names = TAdSinglePlyChrSelectGC__modem_compression_names;
    if (arg0 <= 0 || arg0 > 4) {
        return -2;
    }
    strcpy(buf, lbl_805D4980);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
    return 1;
}

s32 TAdSinglePlyChrSelectGC::copy_default_and_get_state() {
    u32 arg0 = (u32)this;
    if (arg0 != 0U) {
        *(ByteBlock_1C *)(arg0) = *(const ByteBlock_1C *)(&modem_connection_info.value);
    }
    return lbl_805D7C98;
}

s32 TAdSinglePlyChrSelectGC::send_atx_command(s32 arg0) {
    char buf[0x80];
    Names_8042E7B8 names = lbl_80480234;
    s32 pad;
    if (arg0 <= 0 || arg0 > 2) {
        return -2;
    }
    strcpy(buf, lbl_805D4988);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
    return 1;
}

s32 TAdSinglePlyChrSelectGC::send_modem_hangup(s32 arg0) {
    if ((arg0 == 0) && ((s32) lbl_805D7C98 == 3)) {
        lbl_805D7C98 = 1;
        if (EXILock(0, 2, NULL) == 0) {
            return 1;
        }
        TAdSinglePlyChrSelectGC__sub_8042D6A4((char *)&lbl_805D4918);
        EXIUnlock(0);
        goto block_5;
    }
block_5:
    return 1;
}

s32 fn_8042E8B8(void) {
    return 0x80003100;
}

}
