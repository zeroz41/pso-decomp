#include "pso/network/NetworkTransport.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "dolphin/exi.h"
#include "dolphin/os.h"
#include "dolphin/os/OSReset.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TUdpSocket.h"

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

// Transmit side of the modem EXI transfer (cleared as one 0x2C block by sub_8042CEF8).
struct ModemSendState {
    s32 busy;
    u8 *data;
    s32 remaining;
    s32 length;
    u8 *head;
    s32 head_length;
    u8 *body;
    s32 body_length;
    u8 *tail;
    s32 tail_length;
    void (*callback)(s32 length);
};

// Receive side of the modem EXI transfer (cleared as one 0x40 block by sub_8042CEF8).
struct ModemRecvState {
    u8 *buffer;
    u8 *head;
    u8 *body;
    u8 *tail;
    s32 f10;
    s32 f14;
    s32 received;
    s32 length;
    s32 head_length;
    s32 body_length;
    s32 tail_length;
    s32 available;
    s32 capacity;
    s32 f34;
    s32 f38;
    void (*callback)(s32 received);
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
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

char *strcat(char *, const char *);
char *strcpy(char *, const char *);
s32 TAdSinglePlyChrSelectGC__sub_8042D49C(char *cmd);
extern Names_8042E57C TAdSinglePlyChrSelectGC__modem_type_names;
extern char lbl_805D48AC[2];
extern char lbl_805D489C[5];
extern char lbl_805D48A4[8];
extern char lbl_805D48B0[6];
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
static ModemSendState modem_send_state;
static ModemRecvState modem_recv_state;
extern s32 lbl_805D7C9C;
s32 TAdSinglePlyChrSelectGC__sub_8042E184(void);
unsigned long strlen(const char *);
int memcmp(const void *, const void *, unsigned long);
extern char lbl_805D4914[4];
extern char lbl_805D4920[5];
extern char lbl_805D4928[7];
extern char lbl_805D4930[5];
extern char lbl_805D4938[7];
extern char *modem_exi_ptr_table[22];
s32 modem_wait_ok_or_error(void);
void TAdSinglePlyChrSelectGC__sub_8042D604(void);
void TAdSinglePlyChrSelectGC__sub_8042E488(s32 value);

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

void TAdSinglePlyChrSelectGC__sub_8042BF6C(s32 length);
void TAdSinglePlyChrSelectGC__sub_8042C124(s32 chan, OSContext *context);
void parse_modem_command_response(void);
void TAdSinglePlyChrSelectGC__sub_8042DF4C(s32 chan, OSContext *context);

// Modem register access over EXI channel 0, device 2: a read sends the register number in the
// high byte of a 16-bit command and reads one byte back; a write sets bit 0x40 of the register
// number and sends the value.
static inline s32 ModemMin(s32 a, s32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

// `selected` holds EXISelect's result in the stack slot the original frames keep for it; the check that
// read it is not in this build.
static inline u8 ModemReadRegister(u8 reg) {
    BOOL selected;
    u16 cmd = reg << 8;
    u8 value;

    selected = EXISelect(0, 2, 4);
    EXIImm(0, &cmd, 2, EXI_WRITE, NULL);
    EXISync(0);
    EXIImm(0, &value, 1, EXI_READ, NULL);
    EXISync(0);
    EXIDeselect(0);
    return value;
}

// Command 0x23 reads modem FIFO data; the byte after the opcode is the byte count.
static inline u8 ModemReadFifoByte(void) {
    u32 cmd = 0x23000100;
    u8 value;

    EXISelect(0, 2, 4);
    EXIImm(0, &cmd, 4, EXI_WRITE, NULL);
    EXISync(0);
    EXIImm(0, &value, 1, EXI_READ, NULL);
    EXISync(0);
    EXIDeselect(0);
    return value;
}

static inline void ModemWriteRegister(u8 reg, u8 value) {
    BOOL selected;
    u16 cmd = (reg | 0x40) << 8;

    selected = EXISelect(0, 2, 4);
    EXIImm(0, &cmd, 2, EXI_WRITE, NULL);
    EXISync(0);
    EXIImm(0, &value, 1, EXI_WRITE, NULL);
    EXISync(0);
    EXIDeselect(0);
}

// Takes the EXI channel 0 lock for the modem, sleeping until wake_load_thread wakes the queue.
static inline void ModemLockExi(void) {
    BOOL enabled = OSDisableInterrupts();

    for (;;) {
        if (EXILock(0, 2, (EXICallback)TAdSinglePlyChrSelectGC::wake_load_thread) == 1) {
            OSRestoreInterrupts(enabled);
            break;
        }
        OSSleepThread(&lbl_805D7CA0);
        OSRestoreInterrupts(enabled);
    }
}

void TAdSinglePlyChrSelectGC__sub_8042BF6C(s32 length) {
    BOOL selected;
    u32 cmd;
    u8 *body;
    u8 *tail;
    s32 offset;
    s32 count;

    modem_recv_state.length = length;
    modem_recv_state.tail = NULL;
    modem_recv_state.body = NULL;
    modem_recv_state.head = NULL;
    modem_recv_state.tail_length = 0;
    modem_recv_state.body_length = 0;
    modem_recv_state.head_length = 0;
    body = (u8 *)OSRoundUp32B(modem_recv_state.buffer);
    tail = (u8 *)OSRoundDown32B(modem_recv_state.buffer + modem_recv_state.length);
    if (body >= tail) {
        modem_recv_state.head = modem_recv_state.buffer;
        modem_recv_state.head_length = modem_recv_state.length;
    } else {
        if (modem_recv_state.buffer != body) {
            modem_recv_state.head = modem_recv_state.buffer;
            modem_recv_state.head_length = body - modem_recv_state.buffer;
        }
        modem_recv_state.body = body;
        modem_recv_state.body_length = tail - body;
        if (tail < modem_recv_state.buffer + modem_recv_state.length) {
            modem_recv_state.tail = tail;
            modem_recv_state.tail_length = modem_recv_state.buffer + modem_recv_state.length - tail;
        }
    }
    cmd = 0x28000000 | ((u16)modem_recv_state.length << 8);
    selected = EXISelect(0, 2, 4);
    EXIImm(0, &cmd, 4, EXI_WRITE, NULL);
    EXISync(0);
    for (offset = 0; modem_recv_state.head_length > 0; modem_recv_state.head_length -= 4) {
        count = ModemMin(modem_recv_state.head_length, 4);
        EXIImm(0, modem_recv_state.head + offset, count, EXI_READ, NULL);
        EXISync(0);
        offset += 4;
    }
    if (modem_recv_state.body_length > 0) {
        EXIDma(0, modem_recv_state.body, modem_recv_state.body_length, EXI_READ,
               TAdSinglePlyChrSelectGC__sub_8042C124);
    } else {
        TAdSinglePlyChrSelectGC__sub_8042C124(0, NULL);
    }
}

void TAdSinglePlyChrSelectGC__sub_8042C124(s32 chan, OSContext *context) {
    s32 offset;
    s32 count;
    void (*callback)(s32);

    for (offset = 0; modem_recv_state.tail_length > 0; modem_recv_state.tail_length -= 4) {
        count = ModemMin(modem_recv_state.tail_length, 4);
        EXIImm(0, modem_recv_state.tail + offset, count, EXI_READ, NULL);
        EXISync(0);
        offset += 4;
    }
    if (modem_recv_state.body_length > 0) {
        DCInvalidateRange(modem_recv_state.body, modem_recv_state.body_length);
        modem_recv_state.body_length = 0;
    }
    modem_recv_state.received += modem_recv_state.length;
    modem_recv_state.buffer += modem_recv_state.length;
    EXIDeselect(0);
    ModemWriteRegister(1, lbl_805D7C90.f4);
    EXIUnlock(0);
    if (modem_recv_state.capacity - modem_recv_state.received < lbl_805D7C90.f0 || modem_recv_state.f10 == 1) {
        modem_recv_state.f10 = 0;
        modem_recv_state.f14 = 0;
        if (modem_recv_state.callback != NULL) {
            callback = modem_recv_state.callback;
            modem_recv_state.callback = NULL;
            lbl_805D7C9C = 1;
            callback(modem_recv_state.received);
            lbl_805D7C9C = 0;
        }
        modem_recv_state.received = 0;
    }
}

void TAdSinglePlyChrSelectGC__sub_8042C2E4(s32 chan, OSContext *context) {
    u8 status;
    u32 cmd;
    s32 count;

    if (EXILock(0, 2, TAdSinglePlyChrSelectGC__sub_8042C2E4) != 0) {
        status = ModemReadRegister(2);
        status &= lbl_805D7C90.f4;
        if (status == 0) {
            EXIUnlock(0);
        } else {
            ModemWriteRegister(1, 0);
            switch (__cntlzw(status)) {
            case 27:
                TAdSinglePlyChrSelectGC__sub_8042DE20();
                break;
            case 26:
                if (modem_recv_state.f34 == 0) {
                    modem_recv_state.f38 = 1;
                    lbl_805D7C90.f4 &= ~0x20;
                    ModemWriteRegister(1, lbl_805D7C90.f4);
                    EXIUnlock(0);
                } else if (modem_recv_state.f14 != 0) {
                    TAdSinglePlyChrSelectGC__sub_8042BF6C(lbl_805D7C90.f0);
                } else {
                    lbl_805D7C90.f4 &= ~0x20;
                    ModemWriteRegister(1, lbl_805D7C90.f4);
                    EXIUnlock(0);
                }
                break;
            case 25:
                modem_recv_state.available = ModemReadRegister(0xB) << 8;
                modem_recv_state.available += ModemReadRegister(0xC);
                if (modem_recv_state.available == 0 || modem_recv_state.f14 == 0) {
                    ModemWriteRegister(1, lbl_805D7C90.f4);
                    EXIUnlock(0);
                } else {
                    if (modem_recv_state.capacity - modem_recv_state.received < modem_recv_state.available) {
                        modem_recv_state.available = modem_recv_state.capacity - modem_recv_state.received;
                    }
                    modem_recv_state.f10 = 1;
                    TAdSinglePlyChrSelectGC__sub_8042BF6C(modem_recv_state.available);
                }
                break;
            case 30:
                modem_command_response_state.fifo_count = ModemReadRegister(5);
                cmd = 0x23000000 | ((u8)modem_command_response_state.fifo_count << 8);
                EXISelect(0, 2, 4);
                EXIImm(0, &cmd, 4, EXI_WRITE, NULL);
                EXISync(0);
                while (modem_command_response_state.fifo_count > 0) {
                    count = ModemMin(modem_command_response_state.fifo_count, 4);
                    EXIImm(0, modem_command_response_state.buf + modem_command_response_state.length, count,
                           EXI_READ, NULL);
                    EXISync(0);
                    modem_command_response_state.fifo_count -= count;
                    modem_command_response_state.length += count;
                }
                EXIDeselect(0);
                parse_modem_command_response();
                ModemWriteRegister(1, lbl_805D7C90.f4);
                EXIUnlock(0);
                if (modem_command_response_state.done == 1 && modem_command_response_state.callback != NULL) {
                    modem_command_response_state.done = 0;
                    lbl_805D7C9C = 1;
                    modem_command_response_state.callback(modem_command_response_state.result);
                    lbl_805D7C9C = 0;
                }
                break;
            }
        }
    }
}

void parse_modem_command_response(void) {
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

// Polls the modem FIFO (register 5 holds the byte count, command 0x23 reads one byte) and
// appends each byte to the response buffer until it sees "OK" (returns 1) or "ERROR" (returns -6).
s32 modem_wait_ok_or_error(void) {
    u8 count;
    s32 i;
    s32 saw_o;
    s32 error_index;
    const char *error;

    saw_o = 0;
    error_index = 0;
    error = "ERROR";
    for (;;) {
        count = ModemReadRegister(5);
        if (count == 0) {
            OSYieldThread();
            continue;
        }
        for (i = 0; i < count; i++) {
            u8 c = ModemReadFifoByte();

            modem_command_response_state.buf[modem_command_response_state.length++] = c;
            if (c == error[error_index]) {
                if (++error_index == 5) {
                    return -6;
                }
            } else {
                error_index = 0;
            }
            if (c == 0x4F) { // 'O'
                saw_o = 1;
            } else if (saw_o == 1 && c == 0x4B) { // 'K'
                return 1;
            } else {
                saw_o = 0;
            }
        }
    }
}

// Sends one AT command and waits for OK/ERROR, the same pair TAdSinglePlyChrSelectGC__sub_8042D49C runs
// (name inferred). Each expansion keeps a stack slot for result in 0x8042CEF8's frame.
static inline s32 ModemSendCommand(char *command) {
    s32 result;

    TAdSinglePlyChrSelectGC__sub_8042D6A4(command);
    result = modem_wait_ok_or_error();
    return result;
}

s32 TAdSinglePlyChrSelectGC__sub_8042CEF8(const char *country) {
    char buf[0x80];
    u16 cmd;
    u32 id;
    BOOL selected;
    u16 reset;

    ModemLockExi();
    lbl_805D7C98 = 0;
    lbl_805D7C90.f0 = 480;
    lbl_805D7C90.f2 = 33;
    lbl_805D7C90.f4 = 0x62;
    lbl_805D7C90.f5 = 5;
    memset(&modem_connection_info, 0, sizeof(modem_connection_info));
    memset(&modem_recv_state, 0, sizeof(modem_recv_state));
    memset(&modem_send_state, 0, sizeof(modem_send_state));
    OSInitThreadQueue(&lbl_805D7CA0);
    lbl_805D7C9C = 0;
    modem_recv_state.f10 = 0;
    modem_command_response_state.done = 0;
    modem_command_response_state.length = 0;
    lbl_805D7C98 = 1;
    modem_recv_state.f14 = 0;
    modem_recv_state.f38 = 0;
    modem_send_state.busy = 0;
    modem_recv_state.capacity = 0;
    modem_recv_state.f34 = 1;
    selected = EXISelect(0, 2, 0);
    cmd = 0;
    EXIImm(0, &cmd, 2, EXI_WRITE, NULL);
    EXISync(0);
    EXIImm(0, &id, 4, EXI_READ, NULL);
    EXISync(0);
    EXIDeselect(0);
    if (id != 0x02020000) {
        EXIUnlock(0);
        return -1;
    }
    reset = 0x8000;
    selected = EXISelect(0, 2, 4);
    EXIImm(0, &reset, 2, EXI_WRITE, NULL);
    EXISync(0);
    EXIDeselect(0);
    ModemWriteRegister(0x13, lbl_805D7C90.f5);
    ModemWriteRegister(6, 0x32);
    ModemWriteRegister(7, 0x40);
    ModemWriteRegister(0x10, lbl_805D7C90.f0 >> 8);
    ModemWriteRegister(0x11, lbl_805D7C90.f0);
    ModemWriteRegister(0xE, lbl_805D7C90.f2 >> 8);
    ModemWriteRegister(0xF, lbl_805D7C90.f2);
    ModemSendCommand(lbl_805D489C);
    strcpy(buf, lbl_805D48A4);
    strcat(buf, country);
    strcat(buf, lbl_805D48AC);
    ModemSendCommand(buf);
    ModemSendCommand(lbl_805D48B0);
    ModemSendCommand("ATW1\\V0\r");
    ModemSendCommand("ATS95=44\r");
    ModemWriteRegister(1, lbl_805D7C90.f4);
    EXISetExiCallback(2, TAdSinglePlyChrSelectGC__sub_8042C2E4);
    OSRegisterResetFunction(&modem_reset_function_info);
    EXIUnlock(0);
    return 1;
}

s32 TAdSinglePlyChrSelectGC__sub_8042D49C(char *cmd) {
    u32 length;
    u32 i;
    char c;
    s32 result;

    length = strlen(cmd);
    if (length <= 1 || cmd[length - 1] != '\r') {
        return -8;
    }
    for (i = 0; i < length; i++) {
        c = cmd[i];
        if (c >= 'a' && c <= 'z') {
            c -= 'a' - 'A';
        }
        cmd[i] = c;
    }
    if (memcmp(cmd, lbl_805D4914, 2) != 0) {
        return -8;
    }
    for (i = 0; i < 22; i++) {
        if (memcmp(cmd + 2, modem_exi_ptr_table[i], strlen(modem_exi_ptr_table[i])) == 0) {
            return -8;
        }
    }
    ModemLockExi();
    TAdSinglePlyChrSelectGC__sub_8042D6A4(cmd);
    result = modem_wait_ok_or_error();
    EXIUnlock(0);
    return result;
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

void TAdSinglePlyChrSelectGC__sub_8042D6A4(char *str) {
    s32 length;
    u32 cmd;
    s32 count;

    length = strlen(str);
    while (ModemReadRegister(4) > 0x40 - length) {
    }
    cmd = 0x63000000 | ((u16)length << 8);
    EXISelect(0, 2, 4);
    EXIImm(0, &cmd, 4, EXI_WRITE, NULL);
    EXISync(0);
    while (length > 0) {
        count = length > 4 ? 4 : length;
        EXIImm(0, str, count, EXI_WRITE, NULL);
        EXISync(0);
        length -= 4;
        str += 4;
    }
    EXIDeselect(0);
}

s32 TAdSinglePlyChrSelectGC__sub_8042D7E0(u8 *buf) {
    u8 *head;
    u8 *body;
    u8 *tail;
    s32 head_len;
    s32 body_len;
    s32 tail_len;
    u8 *body_end;
    u8 *head_end;
    u32 cmd;
    BOOL selected;
    s32 len;
    s32 count;

    if (modem_recv_state.f14 != 0) {
        return -5;
    }
    if (modem_recv_state.f34 == 0) {
        if (modem_recv_state.f38 == 0) {
            return 0;
        }
        ModemLockExi();
    } else {
        modem_recv_state.f34 = 0;
        modem_recv_state.f38 = 0;
        ModemLockExi();
        lbl_805D7C90.f4 |= 0x20;
        ModemWriteRegister(0x01, lbl_805D7C90.f4);
        ModemWriteRegister(0x13, 0);
        ModemWriteRegister(0x10, 0);
        ModemWriteRegister(0x11, 1);
    }
    modem_recv_state.f38 = 0;

    len = ModemReadRegister(0x0B) << 8;
    len += ModemReadRegister(0x0C);
    if (len == 0) {
        EXIUnlock(0);
        return 0;
    }

    cmd = 0x28000000 | ((len << 8) & 0xFFFF00);
    selected = EXISelect(0, 2, 4);
    EXIImm(0, &cmd, 4, EXI_WRITE, NULL);
    EXISync(0);

    head_end = (u8 *)OSRoundUp32B(buf);
    body_end = (u8 *)OSRoundDown32B(buf + len);
    tail = NULL;
    body = NULL;
    head = NULL;
    tail_len = 0;
    body_len = 0;
    head_len = 0;
    if (head_end >= body_end) {
        head = buf;
        head_len = len;
    } else {
        if (buf != head_end) {
            head = buf;
            head_len = head_end - buf;
        }
        body = head_end;
        body_len = body_end - head_end;
        if (body_end < buf + len) {
            tail = body_end;
            tail_len = (buf + len) - body_end;
        }
    }

    while (head_len > 0) {
        count = head_len > 4 ? 4 : head_len;
        EXIImm(0, head, count, EXI_READ, NULL);
        EXISync(0);
        head_len -= 4;
        head += 4;
    }
    if (body_len > 0) {
        EXIDma(0, body, body_len, EXI_READ, NULL);
        EXISync(0);
    }
    while (tail_len > 0) {
        count = tail_len > 4 ? 4 : tail_len;
        EXIImm(0, tail, count, EXI_READ, NULL);
        EXISync(0);
        tail_len -= 4;
        tail += 4;
    }
    if (body_len > 0) {
        DCInvalidateRange(body, body_len);
    }
    EXIDeselect(0);

    lbl_805D7C90.f4 |= 0x20;
    ModemWriteRegister(0x01, lbl_805D7C90.f4);
    EXIUnlock(0);
    return len;
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
    if (EXILock(0, 2U, (EXICallback)TAdSinglePlyChrSelectGC__sub_8042DDE4) != 0) {
        TAdSinglePlyChrSelectGC__sub_8042DE20();
    }
}

void TAdSinglePlyChrSelectGC__sub_8042DE20(void) {
    s32 length;
    u8 *data;
    u8 *body;
    u8 *tail;
    s32 max;
    u32 cmd;

    data = modem_send_state.data;
    max = 0x201 - lbl_805D7C90.f2;
    length = modem_send_state.remaining;
    if (length >= max) {
        length = max;
    }
    modem_send_state.remaining -= length;
    modem_send_state.tail = NULL;
    modem_send_state.body = NULL;
    modem_send_state.head = NULL;
    modem_send_state.tail_length = 0;
    modem_send_state.body_length = 0;
    modem_send_state.head_length = 0;
    body = (u8 *)OSRoundUp32B(data);
    tail = (u8 *)OSRoundDown32B(data + length);
    if (body >= tail) {
        modem_send_state.head = data;
        modem_send_state.head_length = length;
    } else {
        if (data != body) {
            modem_send_state.head = data;
            modem_send_state.head_length = body - data;
        }
        modem_send_state.body = body;
        modem_send_state.body_length = tail - body;
        DCStoreRange(modem_send_state.body, modem_send_state.body_length);
        if (tail < data + length) {
            modem_send_state.tail = tail;
            modem_send_state.tail_length = (data + length) - tail;
        }
    }
    EXISelect(0, 2, 4);
    cmd = 0x68000000 | ((u16)length << 8);
    EXIImm(0, &cmd, 4, EXI_WRITE, TAdSinglePlyChrSelectGC__sub_8042DF4C);
}

void TAdSinglePlyChrSelectGC__sub_8042DF4C(s32 chan, OSContext *context) {
    s32 offset;
    s32 count;
    void (*callback)(s32);

    for (offset = 0; modem_send_state.head_length > 0; modem_send_state.head_length -= 4) {
        count = ModemMin(modem_send_state.head_length, 4);
        EXIImm(0, modem_send_state.head + offset, count, EXI_WRITE, NULL);
        EXISync(0);
        offset += 4;
    }
    if (modem_send_state.body_length > 0) {
        EXIDma(0, modem_send_state.body, modem_send_state.body_length, EXI_WRITE,
               TAdSinglePlyChrSelectGC__sub_8042DF4C);
        modem_send_state.body_length = 0;
        return;
    }
    for (offset = 0; modem_send_state.tail_length > 0; modem_send_state.tail_length -= 4) {
        count = ModemMin(modem_send_state.tail_length, 4);
        EXIImm(0, modem_send_state.tail + offset, count, EXI_WRITE, NULL);
        EXISync(0);
        offset += 4;
    }
    EXIDeselect(0);
    if (modem_send_state.remaining > 0) {
        modem_send_state.data += 0x201 - lbl_805D7C90.f2;
        lbl_805D7C90.f4 |= 0x10;
    } else {
        modem_send_state.busy = 0;
        modem_send_state.data = NULL;
        lbl_805D7C90.f4 &= ~0x10;
    }
    ModemWriteRegister(1, lbl_805D7C90.f4);
    EXIUnlock(0);
    if (modem_send_state.remaining == 0 && modem_send_state.callback != NULL) {
        callback = modem_send_state.callback;
        modem_send_state.callback = NULL;
        lbl_805D7C9C = 1;
        callback(modem_send_state.length);
        lbl_805D7C9C = 0;
    }
}

s32 TAdSinglePlyChrSelectGC__sub_8042E184(void) {
    u16 space;

    if (modem_send_state.busy == 1) {
        return 1;
    }
    if (lbl_805D7C9C == 0) {
        ModemLockExi();
    }
    space = ModemReadRegister(9) << 8;
    space += ModemReadRegister(0xA);
    if (lbl_805D7C9C == 0) {
        EXIUnlock(0);
    }
    if (space < lbl_805D7C90.f2) {
        return 0;
    }
    return 1;
}

s32 TAdSinglePlyChrSelectGC__sub_8042E320(const char *number, s32 mode, void (*callback)(s32 result)) {
    char buf[0x40];
    s32 result;

    memset(&modem_connection_info, 0, sizeof(modem_connection_info));
    if (mode <= 0 || mode > 3) {
        return -2;
    }
    if (lbl_805D7C98 == 3) {
        return -3;
    }
    modem_command_response_state.callback = callback;
    switch (mode) {
    case 1:
        strcpy(buf, lbl_805D4920);
        break;
    case 2:
        result = TAdSinglePlyChrSelectGC__sub_8042D49C(lbl_805D4928);
        strcpy(buf, lbl_805D4930);
        break;
    case 3:
        result = TAdSinglePlyChrSelectGC__sub_8042D49C(lbl_805D4938);
        strcpy(buf, lbl_805D4930);
        break;
    }
    strcat(buf, number);
    strcat(buf, lbl_805D48AC);
    lbl_805D7C98 = 2;
    ModemLockExi();
    TAdSinglePlyChrSelectGC__sub_8042D6A4(buf);
    EXIUnlock(0);
    return 1;
}

void TAdSinglePlyChrSelectGC__sub_8042E488(s32 value) {
    lbl_805D7C90.f5 = value;
    ModemLockExi();
    ModemWriteRegister(0x13, lbl_805D7C90.f5);
    EXIUnlock(0);
}

typedef char RecoveredGlobal_8042E768_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042E768_lbl_805D1D20) == 0x1C ? 1 : -1];

s32 TAdSinglePlyChrSelectGC::send_at_ms_command(s32 arg0) {
    char buf[0x80];
    s32 result;
    Names_8042E57C names = TAdSinglePlyChrSelectGC__modem_type_names;
    if (arg0 <= 0 || arg0 >= 5) {
        return -2;
    }
    strcpy(buf, lbl_805D495C);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    result = TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
    return 1;
}

s32 TAdSinglePlyChrSelectGC::send_at_error_correction_cmd(s32 arg0) {
    char buf[0x80];
    s32 result;
    Names_8042E628 names = TAdSinglePlyChrSelectGC__modem_error_correction_names;
    if (arg0 <= 0 || arg0 > 3) {
        return -2;
    }
    strcpy(buf, modem_error_correction_command_prefix);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    result = TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
    return 1;
}

s32 TAdSinglePlyChrSelectGC::send_at_compression_cmd(s32 arg0) {
    char buf[0x80];
    s32 result;
    Names_8042E6C4 names = TAdSinglePlyChrSelectGC__modem_compression_names;
    if (arg0 <= 0 || arg0 > 4) {
        return -2;
    }
    strcpy(buf, lbl_805D4980);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    result = TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
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
    s32 result;
    if (arg0 <= 0 || arg0 > 2) {
        return -2;
    }
    strcpy(buf, lbl_805D4988);
    strcat(buf, names.name[arg0]);
    strcat(buf, lbl_805D48AC);
    result = TAdSinglePlyChrSelectGC__sub_8042D49C(buf);
    return 1;
}

s32 TAdSinglePlyChrSelectGC::send_modem_hangup(s32 arg0) {
    if ((arg0 == 0) && ((s32) lbl_805D7C98 == 3)) {
        lbl_805D7C98 = 1;
        if (EXILock(0, 2U, NULL) == 0) {
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
