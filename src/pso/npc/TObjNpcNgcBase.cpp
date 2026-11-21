#include "types.h"
#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcLappy.h"

#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

TObjNpcNgcBase::~TObjNpcNgcBase() {}
struct E_803594B4 { s32 a; s32 b; f32 c; };

struct O_803594B4 { u8 pad[0x1c]; s32 idx; E_803594B4 e[2]; };

extern "C" {
saddr get_bml_texlist(void *, int);
saddr get_bml_model(void *, int);
const char *TObjNpcNgcBase__name = "TObjNpcNgcBase";
void fn_803594B4(O_803594B4 *self, s32 v, f32 f);
TObjNpcNgcBase::TObjNpcNgcBase(TObject *parent, void *set_data, void *resource) : TUnk_804A9F50(parent) {
    m_name = TObjNpcNgcBase__name;
    apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = get_bml_model(resource, 0);
    texlist = get_bml_texlist(resource, 0);
    setup_common();
}
void fn_803594B4(O_803594B4 *self, s32 v, f32 f) {
    self->e[self->idx].a = 1;
    self->e[self->idx].b = v;
    self->e[self->idx].c = f;
}

}
