#include "types.h"
#include "pso/unk/text_80049FD8.h"
#include "pso/object/TObjChip.h"
#include "pso/boss/volopt/TObjVoloptPillar.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TMainTask.h"

// Throws three debris chips from the pillar's position.
void fn_80049FD8(TObjVoloptPillar *pillar) {
    TObjChipParams params = volopt_pillar_chip_params;
    params.pos[0] = pillar->position.x;
    params.pos[1] = pillar->position.y;
    params.pos[2] = pillar->position.z;
    params.model = boss3_volopt_resources->models[0xE].model;
    params.textures = boss3_volopt_resources->models[0xE].m_c;
    new TObjChip(tl_05, &params);
    new TObjChip(tl_05, &params);
    new TObjChip(tl_05, &params);
}
