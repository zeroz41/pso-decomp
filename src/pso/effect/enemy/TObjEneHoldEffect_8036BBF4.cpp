#include "types.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
struct Pkt_8036BBF4 {
    u8 header[4];
    u8 params[2];
    s16 target_count;
    u8 pad08[4];
    u32 targets[1];
};

extern "C" {
s32 validate_subcommand_client(void *);
}
s32 validate_photon_blast_parameters(void *);
s32 validate_cast_target_entry(void *);
s32 TObjEneHoldEffect::validate_6x49_packet() {
    struct Pkt_8036BBF4 *packet = (struct Pkt_8036BBF4 *)this;
    s32 i;
    if (validate_subcommand_client(packet->header) == 0) {
        return 0;
    }
    if (validate_photon_blast_parameters(packet->params) == 0) {
        return 0;
    }
    for (i = 0; i < packet->target_count; i++) {
        if (validate_cast_target_entry(&packet->targets[i]) == 0) {
            return 0;
        }
    }
    return 1;
}
