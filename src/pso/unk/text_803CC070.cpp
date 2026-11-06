#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {
void GCRNA_SetPlaySw(void *, s32);
void GCRNA_SetTransSw(void *, s32);
void gcrna_destroy_stream(void *);
void TLobby::unregister_si_polling() {
    u8 *arg0 = (u8 *)this;
    GCRNA_SetPlaySw(arg0, 0);
    GCRNA_SetTransSw(arg0, 0);
    gcrna_destroy_stream(arg0);
}

}
