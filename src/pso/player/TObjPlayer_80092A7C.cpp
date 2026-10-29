#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/player/TObjPlayer.h"

void TUnk_80493450::vfunc_100() {  }
int TUnk_80493450::test_flag_256() { return 0; }
void TUnk_80493450::request_stand_action() { this->requested_action = 0; }
void TObjPlayer::init_position_vectors() {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(VecCopy((Vec *)(arg0 + 0x290), (const Vec *)(VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(arg0 + 0x38))))));
}
