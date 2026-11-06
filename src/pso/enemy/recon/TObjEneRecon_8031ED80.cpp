#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/enemy/recon/TObjEneRecon.h"

void TObjEneRecobox::update_if_800BB858() { if (get_target_info() != 0) { sub_8031F800(); } }
