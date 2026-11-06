#include "types.h"
#include "pso/object/fence/TLazerFenceSw.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/object/container/TContainerAncient01.h"

void TContainerAncient01::trigger_spawn(void* p, void* a1, void* a2) { spawn_particle_effect(a1, (s32)a2); }
