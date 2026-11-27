#ifndef PSO_UI_FRONTEND_TADTRIALMODEMCHKGC_H
#define PSO_UI_FRONTEND_TADTRIALMODEMCHKGC_H

#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/system/SharedMemory.h"

struct TAdTrialModemChkGC : public TAdWarningBaseGC {
    static const char *name;
    TAdTrialModemChkGC(TObject *parent);
    virtual ~TAdTrialModemChkGC();
    virtual const char *get_message_text();
    virtual void on_close();
    static void init_modem_check_phase();
    static void check_modem_result();
    static void exit_modem_check_phase();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdTrialModemChkGC_size, sizeof(TAdTrialModemChkGC) == 0x30);

s32 set_shared_memory_data(u8 *source, u32 size);
void launch_iwanaga_dol(DolHeader *dol_image, s32 param);
void init_shared_memory();
s32 set_disc_error_message(s32 index, const char *text);
s32 ntUtlExSetDialType(s8 value);
s32 get_network_adapter_type(s32 *out_type);
s32 set_modem_check_char(s8 value);
s32 set_modem_check_param(s32 value);
s32 set_modem_check_param_360(s8 value);
s32 set_modem_flag(s8 value);
s32 set_modem_param(s16 value);
s32 set_modem_trial_param(s16 value);

extern "C" {
// Resets the shared-memory connect parameters to the modem check defaults.
s32 init_modem_check_params();
s32 set_connect_param_1C2(s16 value);
s32 set_connect_param_13D(s8 value);
s32 set_disc_messages_byte0(s8 value);
}

#endif
