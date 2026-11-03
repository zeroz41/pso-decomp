#include "types.h"
#include "pso/misc/TPlayerFootStamp_802B01D8.h"
#include "pso/TPlayerFootStamp.h"

#pragma readonly_strings on


struct Obj_802B0204 { u8 pad[0xbe]; s16 fbe; };

extern "C" {

u8 *load_gvm_texture_file(s32 arg0);
}

    extern int player_footstamp_texture_gvm_handle;
void load_player_footstamp(void) { player_footstamp_texture_gvm_handle = (int)load_gvm_texture_file((s32)(unsigned char *)"player_footstamp.GVM"); }

void TPlayerFootStamp::sub_802B0204(s32 v) {
    Obj_802B0204 *self = (Obj_802B0204 *)this;
    if (v < 0 || v > 1) {
        self->fbe = 0;
    } else {
        self->fbe = v;
    }
}
