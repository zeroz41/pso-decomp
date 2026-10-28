#include "types.h"
#include "pso/misc/TTecFoie_802301EC.h"
#include "pso/misc/TTecGiZonde_8023A4CC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/effect/TUnk_804CCC68.h"
#include "pso/misc/TTecFoie.h"
#include "pso/misc/TNowLoading.h"

struct RecoveredGlobal_802302A0___vt__8TTecFoie { s32 value; u8 remaining[0x24]; };
typedef char RecoveredGlobal_802302A0___vt__8TTecFoie_size[sizeof(RecoveredGlobal_802302A0___vt__8TTecFoie) == 0x28 ? 1 : -1];

struct RecoveredGlobal_80230308___vt__8TTecFoie { s32 value; u8 remaining[0x24]; };
typedef char RecoveredGlobal_80230308___vt__8TTecFoie_size[sizeof(RecoveredGlobal_80230308___vt__8TTecFoie) == 0x28 ? 1 : -1];

struct Band_802301EC { void *bindings; u32 count; };

struct Foie_802301EC { u8 pad[0x1C]; u32 owner; u8 pos[0xA6]; s16 band; u16 ownerId; u8 pad2[0x66]; void **emitters; };

extern "C" {
u16 get_entity_id(void *);
u8 * __ct__13TUnk_804CCC68FlPUcPUcl(void *, s32, void *, void *, s16);
extern RecoveredGlobal_802302A0___vt__8TTecFoie __vt__8TTecFoie;
u8 * construct_facing_technique__10TObjPlayerFPviPvii(void *, s32, void *, s32, s16);
extern s32 TTecFoie__name;
extern Band_802301EC TTecFoie__emitter_profile_table[];
void *find_entity_by_id(u16 id);
void dispatch_technique_contact__13TUnk_804CCC68Fv(void *, s32);
void run_task__8TTecFoieFv(Foie_802301EC *self);

void run_task__8TTecFoieFv(Foie_802301EC *self) {
    u32 i;
    self->owner = (u32)find_entity_by_id(self->ownerId);
    if (self->owner == 0) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    for (i = 0; i < TTecFoie__emitter_profile_table[self->band].count; i++) {
        if (self->emitters[i] != 0) {
            ((TNowLoading *)(self->emitters[i]))->copy_pos(self->pos);
        }
    }
    ((TUnk_804CCC68 *)self)->move_technique_projectile();
    ((TUnk_804CCC68 *)self)->advance_lifetime_or_destroy();
    dispatch_technique_contact__13TUnk_804CCC68Fv(self, 1);
}

u8 *TTecFoie::construct_aimed(s32 arg1, u8 *arg2, u8 *arg3, s16 arg4) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    __ct__13TUnk_804CCC68FlPUcPUcl(arg0, arg1, arg2, arg3, arg4);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__8TTecFoie.value;
    temp_r3 = (u8 *)this->source;
    if (temp_r3 != NULL) {
        this->sourceId = get_entity_id(temp_r3);
    }
    ((TTecFoie *)arg0)->init_projectile_params();
    ((TTecFoie *)arg0)->create_particle_emitters();
    ((TTecFoie *)arg0)->play_foie_cast_sound();
    return arg0;
}
u8 *TTecFoie__ct(TTecFoie *tec_foie, s32 arg1, u8 *arg2, s32 arg3, s16 arg4) {
    u8 *temp_r3;
    construct_facing_technique__10TObjPlayerFPviPvii(tec_foie, arg1, arg2, arg3, arg4);
    *(s32 **)((s8 *)tec_foie + 0x18) = &__vt__8TTecFoie.value;
    *(s32 *)((s8 *)tec_foie + 0) = (s32) TTecFoie__name;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)tec_foie + 0x1C));
    if (temp_r3 != NULL) {
        tec_foie->sourceId = get_entity_id(temp_r3);
    }
    tec_foie->init_projectile_params();
    tec_foie->create_particle_emitters();
    tec_foie->play_foie_cast_sound();
    return (u8 *)tec_foie;
}

}
