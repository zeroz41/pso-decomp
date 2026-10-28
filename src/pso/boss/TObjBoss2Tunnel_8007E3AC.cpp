#include "types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/boss/TObjBoss2Tunnel.h"

extern "C" {

s32 TObjBoss2Tunnel::maybe_delete(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

int reset_coords__15TObjBoss2TunnelFv();

s32 TObjBoss2Tunnel::reset_coords_pass(s32 arg0) {
    reset_coords__15TObjBoss2TunnelFv();
    return arg0;
}

}
