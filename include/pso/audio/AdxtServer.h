#ifndef PSO_AUDIO_ADXT_SERVER_H
#define PSO_AUDIO_ADXT_SERVER_H

#include "types.h"

struct AdxtPlayer;

extern "C" {
void adxt_exec_handle(AdxtPlayer *player);
}

#endif
