#ifndef PSO_NETWORK_TPLYRECVLOGIN_H
#define PSO_NETWORK_TPLYRECVLOGIN_H

#include "types.h"

struct TPlyRecvLoginClientConfigCopy {
    u8 data[0x20];
};

struct TPlyRecvLoginCopy {
    u8 header[4];
    u8 tag[8];
    TPlyRecvLoginClientConfigCopy client_config;
};

extern "C" {
s32 __ct__13TPlyRecvLoginFRC13TPlyRecvLogin(saddr arg0, saddr arg1);
void bswap__13TPlyRecvLoginFv(saddr arg0);
}

// --- C functions defined in TPlyRecvLogin.cpp ---
extern "C" {
s32 __ct__13TPlyRecvLoginFRC13TPlyRecvLogin(saddr arg0, saddr arg1);
void bswap__13TPlyRecvLoginFv(saddr arg0);
}
// --- end of C functions

#endif
