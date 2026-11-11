// CRI adx_amp.c: the ADXAMP volume stage (ADXAMP_SetSfreq, ADXAMP_Destroy).
#include "types.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/unk/TLobby_803CC0B4.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/text_803CE568.h"

extern "C" {

s32 memset(void *, int, int);

void TLobby::set_packet_flags(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x20) = arg1;
}

void TLobby::clear_entry() {
    s32 arg0 = (s32)this;
    if (arg0 != 0) {
        TLobby::init_once();
        memset((void *)arg0, 0, 0x30);
        TLobby::release_ref();
    }
}

}
