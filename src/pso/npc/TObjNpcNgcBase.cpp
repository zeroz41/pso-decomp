#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcLappy.h"

#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

TObjNpcNgcBase::~TObjNpcNgcBase() {}


const char *TObjNpcNgcBase__name = "TObjNpcNgcBase";
TObjNpcNgcBase::TObjNpcNgcBase(TObject *parent, void *set_data, void *resource) : TUnk_804A9F50(parent) {
    m_name = TObjNpcNgcBase__name;
    apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (saddr)get_bml_model((BmlResource *)resource, 0);
    texlist = (saddr)get_bml_texlist((BmlResource *)resource, 0);
    setup_common();
}
void fn_803594B4(TBoss4Fade *fade, s32 color, f32 alpha) {
    fade->frames[fade->write_index].active = 1;
    fade->frames[fade->write_index].color = color;
    fade->frames[fade->write_index].alpha = alpha;
}

