#ifndef PSO_NETWORK_TEXT_80421620_H
#define PSO_NETWORK_TEXT_80421620_H

#include "types.h"

/* text_80421620.c: stack start-up and shutdown. */
#ifdef __cplusplus
extern "C" {
#endif
s16 init_network_stack(void);
s32 cleanup_subsystems(void);
#ifdef __cplusplus
}
#endif

#endif
