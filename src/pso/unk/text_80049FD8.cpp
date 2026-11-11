#include "types.h"
#include "pso/unk/text_80049FD8.h"
#include "pso/object/TObjChip.h"
#include "pso/boss/volopt/TObjVoloptPillar.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TMainTask.h"

// Throws three debris chips from the pillar's position.
void fn_80049FD8(TObjVoloptPillar *pillar) {
    const TObjChipParams params = {
        {0.5f, 0.03f, 0.25f},
        {pillar->position.x, pillar->position.y, pillar->position.z},
        {4.5f, -3.0f, 4.5f},
        {0x400, 0x100, 0x400},
        {4, 60},
        {0.0f, 1.0f},
        boss3_volopt_resources->models[0xE].model,
        boss3_volopt_resources->models[0xE].m_c,
        2,
    };
    new TObjChip(tl_05, (TObjChipParams *)&params);
    new TObjChip(tl_05, (TObjChipParams *)&params);
    new TObjChip(tl_05, (TObjChipParams *)&params);
}
