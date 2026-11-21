#ifndef _DOLPHIN_LIBC_CTYPE_H_
#define _DOLPHIN_LIBC_CTYPE_H_

#include "../../../PowerPC_EABI_Support/include/MSL_C/ctype_api.h"

#ifdef __cplusplus
extern "C" {
#endif

int islower(int c);
int tolower(int c);
int toupper(int c);

#ifdef __cplusplus
}
#endif

#endif
