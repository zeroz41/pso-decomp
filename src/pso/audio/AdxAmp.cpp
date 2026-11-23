// CRI adx_amp.c: the ADXAMP volume stage (ADXAMP_SetSfreq, ADXAMP_Destroy).
#include "types.h"
#include <string.h>
#include "pso/audio/AdxAmp.h"
#include "pso/unk/TLobby.h"

extern "C" {

static inline AdxAmp *adx_amp_from_lobby(void *self) {
    return (AdxAmp *)self;
}

void TLobby::set_packet_flags(s32 sfreq) {
    adx_amp_from_lobby(this)->sfreq = sfreq;
}

void TLobby::clear_entry() {
    AdxAmp *amp = adx_amp_from_lobby(this);
    if (amp != NULL) {
        TLobby::init_once();
        memset(amp, 0, sizeof(AdxAmp));
        TLobby::release_ref();
    }
}

}
