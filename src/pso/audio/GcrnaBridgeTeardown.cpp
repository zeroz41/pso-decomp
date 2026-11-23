#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {
void GCRNA_SetPlaySw(void *, s32);
void GCRNA_SetTransSw(void *, s32);
void gcrna_destroy_stream(void *);

void TLobby::unregister_si_polling() {
    GCRNA_SetPlaySw(this, 0);
    GCRNA_SetTransSw(this, 0);
    gcrna_destroy_stream(this);
}

}
