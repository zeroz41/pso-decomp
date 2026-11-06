#include "types.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter_Eff_TpAbsorb1.h"
#include "pso/enemy/recon/TObjEneRecon_80302DB0.h"
#include "pso/enemy/recon/TObjEneRecon.h"

    extern unsigned char scene_sora_recon_active_flag;
void TObjEneRecon::set_active() { scene_sora_recon_active_flag = 1; }
