#ifndef PSO_UNK_TEXT_8036B748_H
#define PSO_UNK_TEXT_8036B748_H

#include "types.h"

struct G_ClientIDHeader;

s32 validate_6x0D_remove_status_effect(G_ClientIDHeader *packet);
s32 validate_6x0C_add_status_effect(G_ClientIDHeader *packet);

extern "C" {
s32 fn_8036B798(void);
s32 fn_8036B7C0(void);
}

#endif
