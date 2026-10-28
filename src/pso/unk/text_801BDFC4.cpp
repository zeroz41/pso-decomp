#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
void *mem_alloc(u32 size);
void *fn_801C2360(void *arg0);
extern u32 TObjPlayer__shared_photon_blast_state;
extern u32 TObjPlayer__shared_model_buffer;
extern u32 player_shared_buffer_base;
void TObjPlayer::alloc_shared_buffers() {
    s32 temp_r3;
    s32 var_r0;
    if ((u32) TObjPlayer__shared_model_buffer == 0U) {
        TObjPlayer__shared_model_buffer = (u32)mem_alloc((u32)((void *)0x9000));
    }
    if ((u32) player_shared_buffer_base == 0U) {
        player_shared_buffer_base = (u32)mem_alloc((u32)((void *)0x4800));
    }
    if ((u32) TObjPlayer__shared_photon_blast_state == 0U) {
        temp_r3 = (int)::operator new(0x60);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = (s32)fn_801C2360((void *)temp_r3);
        }
        TObjPlayer__shared_photon_blast_state = (u32) var_r0;
    }
}

}
