#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 clamp_to_max__20PlayerTechniqueStateFUcUc(s32, u8, s32);
s32 is_valid_technique_id__20PlayerTechniqueStateFs(s32);
s32 get_effective_technique_level__10TObjPlayerFPvs(s32, s32);
s32 get_cast_technique_level(PlayerTechniqueState *techs, s32 tech);
s32 get_cast_technique_level(PlayerTechniqueState *techs, s32 tech) {
    u8 level;
    if (is_valid_technique_id__20PlayerTechniqueStateFs(tech) == 0) {
        return 0;
    }
    level = techs->learned_levels[(s16)tech];
    if (techs->check_technique_level(tech, level) == 0) {
        level = 0x1D;
    }
    return ((s32 (*)(void *, u8, s32))clamp_to_max__20PlayerTechniqueStateFUcUc)(techs, level, ((s32 (*)(PlayerTechniqueState *, s32))get_effective_technique_level__10TObjPlayerFPvs)(techs, tech));
}

}
