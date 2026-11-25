#ifndef PSO_AUDIO_ADX_ERROR_H
#define PSO_AUDIO_ADX_ERROR_H

#include "types.h"
#include "pso/audio/AdxCallbacks.h"

extern "C" {
void adxerr_format_id_pair(s32 first_val, s32 second_val, char *out_buf, s32 max_len);
void adxerr_report_pair(const char *msg, const char *arg);
void adxerr_report(const char *msg);
void adxerr_set_callback(AdxMessageCallback callback, s32 context);
void adxerr_finish();
void adxerr_init();
}

#endif
