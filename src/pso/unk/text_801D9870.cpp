#include "types.h"
#include "pso/player/TObjPlayer.h"
typedef struct TechLevel_801D9870 { u8 level; } TechLevel_801D9870;

typedef struct TObjPlayer_801D9870 {
    u8 pad[0x48];
    TechLevel_801D9870 techs[0x14];
} TObjPlayer_801D9870;

extern "C" {
s32 clamp_to_max__20PlayerTechniqueStateFUcUc(s32, u8, s32);
s32 is_valid_technique_id__20PlayerTechniqueStateFs(s32);
s32 get_effective_technique_level__10TObjPlayerFPvs(s32, s32);
s32 get_cast_technique_level(TObjPlayer_801D9870 *arg0, s32 arg1);
s32 get_cast_technique_level(TObjPlayer_801D9870 *arg0, s32 arg1) {
    u8 level;
    if (is_valid_technique_id__20PlayerTechniqueStateFs(arg1) == 0) {
        return 0;
    }
    level = arg0->techs[(s16)arg1].level;
    if (TObjPlayer::check_technique_level((saddr)arg0, (s32)arg1, (u8)level) == 0) {
        level = 0x1D;
    }
    return ((s32 (*)(void *, u8, s32))clamp_to_max__20PlayerTechniqueStateFUcUc)(arg0, level, ((s32 (*)(void *, s32))get_effective_technique_level__10TObjPlayerFPvs)(arg0, arg1));
}

}
