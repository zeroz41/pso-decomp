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
void ModemRecvCallback(s32 chan, struct OSContext *context);
void parse_modem_command_response(void);
s32 modem_wait_ok_or_error(void);
s32 MDMInit(const char *country);
s32 copy_default_and_get_state(ModemConnectionInfo *out);
void MDMHangUp(void);
s32 MDMATCommand(char *command);
void modem_write_string(char *str);
s32 MDMDial(const char *number, s32 mode, void (*callback)(s32 result));
s32 MDMConnectMode(s32 mode);
s32 MDMErrorCorrectMode(s32 mode);
s32 MDMCompressMode(s32 mode);
s32 MDMWaitToneMode(s32 mode);
s32 ModemRecv(u8 *buffer);
s32 ModemSend(u8 *data, s32 length, void (*callback)(s32 sent));
void ModemSendLockCallback(s32 channel, struct OSContext *context);
void ModemSendChunk(void);
void ModemSendCallback(s32 chan, struct OSContext *context);
s32 ModemCanSend(void);
void ModemSetFwt(s32 value);
struct LaunchDolContext *get_launch_dol_context(void);
#ifdef __cplusplus
}
#endif

#endif
