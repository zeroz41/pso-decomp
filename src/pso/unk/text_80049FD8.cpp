
#include "pso/unk/text_80049FD8.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TObjVoloptPillar.h"
#include "pso/system/BmlResource.h"
s32 __nw__7TObjectFUl(s32);
extern u8 *tl_05;
extern "C" {
void fn_80049FD8(TObjVoloptPillar *pillar) {
    BmlModelEntry *models = boss3_volopt_resources->models;
    TObjChipParams params = volopt_pillar_chip_params;
    f32 z = pillar->position.z;
    f32 y = pillar->position.y;
    f32 x = pillar->position.x;
    s32 textures;
    s32 model = models[0xE].model;
    textures = models[0xE].m_c;
    params.pos[0] = x;
    params.pos[1] = y;
    params.pos[2] = z;
    params.model = model;
    params.textures = textures;
    {
        u8 *o = (u8 *)__nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams(o, tl_05, (u8 *)&params);
        }
    }
    {
        u8 *o = (u8 *)__nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams(o, tl_05, (u8 *)&params);
        }
    }
    {
        u8 *o = (u8 *)__nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams(o, tl_05, (u8 *)&params);
        }
    }
}

}

