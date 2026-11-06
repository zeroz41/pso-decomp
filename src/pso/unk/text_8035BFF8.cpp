#include "pso/system/vector.h"
#include <dolphin/mtx.h>
#include "pso/unk/text_8035BFF8.h"
#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *);
s32 fn_8035BFF8(void) {
    Vec position;
    VecCopy__FP3VecPC3Vec(&position.x);
    return normalize_vector_xz((Vec *)(&position.x)) > 373.0f;
}

}
