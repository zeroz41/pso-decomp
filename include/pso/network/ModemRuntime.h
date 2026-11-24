#ifndef PSO_NETWORK_MODEMRUNTIME_H
#define PSO_NETWORK_MODEMRUNTIME_H

#include "types.h"

struct LaunchDolContext;
struct OSContext;

typedef struct ModemConnectionInfo {
    s32 value;
    s32 transmit_rate;
    s32 receive_rate;
    char carrier[5];
    char error_control[5];
    char compression[6];
} ModemConnectionInfo;
LAYOUT_ASSERT(ModemConnectionInfoSize, sizeof(ModemConnectionInfo) == 0x1C);

#ifdef __cplusplus
extern "C" {
#endif
void wake_load_thread(s32 chan, struct OSContext *context);
BOOL send_modem_hangup(BOOL final);
void fn_8042BF6C(s32 length);
void fn_8042C124(s32 chan, struct OSContext *context);
void fn_8042C2E4(s32 chan, struct OSContext *context);
void parse_modem_command_response(void);
s32 modem_wait_ok_or_error(void);
s32 modem_init(const char *country);
s32 copy_default_and_get_state(ModemConnectionInfo *out);
void modem_hangup(void);
s32 modem_send_at_command(char *command);
void modem_write_string(char *str);
s32 modem_dial(const char *number, s32 mode, void (*callback)(s32 result));
s32 MDMConnectMode(s32 mode);
s32 MDMErrorCorrectMode(s32 mode);
s32 MDMCompressMode(s32 mode);
s32 MDMWaitToneMode(s32 mode);
s32 fn_8042D7E0(u8 *buffer);
s32 fn_8042DD70(u8 *data, s32 length, void (*callback)(s32 sent));
void fn_8042DDE4(s32 channel, struct OSContext *context);
void fn_8042DE20(void);
void fn_8042DF4C(s32 chan, struct OSContext *context);
s32 fn_8042E184(void);
void fn_8042E488(s32 value);
struct LaunchDolContext *fn_8042E8B8(void);
#ifdef __cplusplus
}
#endif

#endif
