#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/player/TObjPlayer.h"

void TUnk_80493450::select_post_attack_mode() {  }
int TUnk_80493450::test_flag_256() { return 0; }
void TUnk_80493450::request_stand_action() { this->requested_action = 0; }
void TObjChara::init_position_vectors() {
    VecCopy(&prev_position, VecCopy(&move_origin, VecCopy(&move_destination, &position)));
}
