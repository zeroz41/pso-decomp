#include "types.h"
#include "pso/boss/TObjBoss2Tunnel_8007C5C0.h"
#include "pso/boss/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/system/memory.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/TAdPlayerLoadGC.h"

extern "C" {
extern u8 *boss2_tunnel_snapshot_buffer;
extern u8 *TObjBoss2Tunnel__snapshot_buffer;
extern s32 TObjBoss2Tunnel__snapshot_saved_flag;
s32 verify_snapshot_checksum__15TObjBoss2TunnelFv();

s32 TObjBoss2Tunnel::save_snapshot() {
    s32 sp8;

    memcard_check_snapshot(1, &sp8);
    if (sp8 == 1) {
        if ((s32) TObjBoss2Tunnel__snapshot_saved_flag != 0) {
            return -9;
        }
        save_screen_snapshot();
loop_4:
        if (TAdPlayerLoadGC::probe_card_slot(1) == 0) {
            TObjBoss2Tunnel__snapshot_saved_flag = 0;
            return -5;
        }
        if (TObjBoss2Tunnel::load_snapshot() != 0) {
            if (verify_snapshot_checksum__15TObjBoss2TunnelFv() == 0) {
                TObjBoss2Tunnel__snapshot_saved_flag = 1;
                return -9;
            }
            goto block_9;
        }
        goto loop_4;
    }
block_9:
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    return sp8;
}
void TObjBoss2Tunnel::free_buffers() {
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    if ((void *) boss2_tunnel_snapshot_buffer != NULL) {
        xfree(boss2_tunnel_snapshot_buffer);
        boss2_tunnel_snapshot_buffer = NULL;
    }
    TObjPlayer__sub_80084694();
    if ((void *) TObjBoss2Tunnel__snapshot_buffer != NULL) {
        xfree(TObjBoss2Tunnel__snapshot_buffer);
        TObjBoss2Tunnel__snapshot_buffer = NULL;
    }
}

}
