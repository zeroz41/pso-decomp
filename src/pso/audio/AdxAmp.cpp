// CRI adx_amp.c: the ADXAMP volume stage (ADXAMP_SetSfreq, ADXAMP_Destroy).
#include "types.h"
#include <string.h>
#include "pso/audio/AdxAmp.h"
#include "pso/unk/TLobby.h"

extern "C" {

void AdxAmp::set_packet_flags(s32 sfreq) {
    this->sfreq = sfreq;
}

void AdxAmp::clear_entry() {
    if (this != NULL) {
        TLobby::init_once();
        memset(this, 0, sizeof(AdxAmp));
        TLobby::release_ref();
    }
}

}
