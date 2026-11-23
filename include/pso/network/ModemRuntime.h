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
s32 modem_init(const char *country);
s32 copy_default_and_get_state(ModemConnectionInfo *out);
void modem_hangup(void);
s32 modem_send_at_command(char *command);
s32 modem_dial(const char *number, s32 mode, void (*callback)(s32 result));
s32 TAdSinglePlyChrSelectGC__sub_8042D7E0(u8 *buffer);
s32 TAdSinglePlyChrSelectGC__sub_8042DD70(u8 *data, s32 length, void (*callback)(s32 sent));
void TAdSinglePlyChrSelectGC__sub_8042DDE4(s32 channel, struct OSContext *context);
s32 TAdSinglePlyChrSelectGC__sub_8042E184(void);
void TAdSinglePlyChrSelectGC__sub_8042E488(s32 value);
struct LaunchDolContext *fn_8042E8B8(void);
#ifdef __cplusplus
}
#endif

#endif
