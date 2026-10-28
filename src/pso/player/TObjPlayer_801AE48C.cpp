#include "types.h"
#include "pso/player/TObjPlayer_801AE48C.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern u8 *photon_blast_shared_resource;
extern u32 pilla_photon_buffer_pair;

void TObjPlayer::free_buffer_pair() {
    if ((u32) pilla_photon_buffer_pair != 0U) {
        destroy_buffer_pair((void *)pilla_photon_buffer_pair, 1);
    }
    pilla_photon_buffer_pair = 0U;
}
void create_pilla_photon_blast_model(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x14);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TLobby *)temp_r3)->alloc_tables(*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 8)) + 0x2C), 0));
    }
    (*(s32 *)&pilla_photon_buffer_pair) = var_r0;
}
