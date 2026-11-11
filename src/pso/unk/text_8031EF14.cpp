#include "types.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/TObjChip.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80087278.h"
struct Obj_8031EF14 { u8 pad[0x410]; s32 count; u8 pad2[4]; u16 ids[6]; };

struct Obj_8031F0F0 { u8 pad[0x410]; s32 count; u8 pad2[4]; u16 ids[6]; };

struct Obj_8031EFAC { u8 pad[0x410]; s32 count; s32 f414; u16 ids[6]; };

struct Obj_8031F070 { u8 pad[0x410]; s32 count; u8 pad2[4]; u16 ids[6]; };

extern "C" {
u8 *find_entity_by_id(u16);
u16 TObjEneRecon__sub_8031D878();
void remove_tracked_target__12TObjEneReconFPvPv(Obj_8031EFAC *o, u8 *target);
s32 is_anim_5__12TObjEneReconFv();
void TObjEneRecon::remove_child_entity(u8 *arg1) {
    Obj_8031EF14 *arg0 = (Obj_8031EF14 *)this;
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(arg0->ids[i]) == arg1) {
            arg0->count--;
            arg0->ids[i] = arg0->ids[arg0->count];
            arg0->ids[arg0->count] = 0xFFFF;
            return;
        }
    }
}

void remove_tracked_target__12TObjEneReconFPvPv(Obj_8031EFAC *o, u8 *target) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(o->ids[i]) == target) {
            ((TObjEneRecon *)o)->remove_tracked_id(o->ids[i]);
            o->count--;
            o->ids[i] = o->ids[o->count];
            o->ids[o->count] = 0xFFFF;
            o->f414--;
            if (o->f414 < 0) {
                o->f414 = 0;
            }
            return;
        }
    }
}

s32 TObjEneRecon::has_child_in_anim_5() {
    Obj_8031F070 *arg0 = (Obj_8031F070 *)this;
    s32 i;
    if (arg0->count <= 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(arg0->ids[i]) != NULL && is_anim_5__12TObjEneReconFv() == 1) {
            return 1;
        }
    }
    return 0;
}

s32 TObjEneRecon::is_below_child_limit(u16 arg1) {
    Obj_8031F0F0 *arg0 = (Obj_8031F0F0 *)this;
    s32 n = 0;
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        if (find_entity_by_id(arg0->ids[i]) != NULL && arg1 == TObjEneRecon__sub_8031D878()) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

extern BmlResource *TObjEneRecobox__static_instance;
extern const TObjChipParams lbl_804762F0;
extern const TObjChipParams lbl_8047633C;
extern const TObjChipParams lbl_80476388;
// Called from TObjEneRecon::handle_death_state: breaks the Recon into three
// debris chips (models 3-5 of the Recobox archive, textures of model 3).
void TObjEneRecobox__sub_8031F1A8(TObjEneRecon *recon) {
    TObjChipParams chip0 = lbl_804762F0;
    chip0.pos[0] = recon->position.x;
    chip0.pos[1] = recon->position.y;
    chip0.pos[2] = recon->position.z;
    chip0.pad_38[0] = recon->position.y;
    chip0.model = TObjEneRecobox__static_instance->models[3].model;
    chip0.textures = TObjEneRecobox__static_instance->models[3].m_c;
    TObjChipParams chip1 = lbl_8047633C;
    chip1.pos[0] = recon->position.x;
    chip1.pos[1] = recon->position.y;
    chip1.pos[2] = recon->position.z;
    chip1.pad_38[0] = recon->position.y;
    chip1.model = TObjEneRecobox__static_instance->models[4].model;
    chip1.textures = TObjEneRecobox__static_instance->models[3].m_c;
    TObjChipParams chip2 = lbl_80476388;
    chip2.pos[0] = recon->position.x;
    chip2.pos[1] = recon->position.y;
    chip2.pos[2] = recon->position.z;
    chip2.pad_38[0] = recon->position.y;
    chip2.model = TObjEneRecobox__static_instance->models[5].model;
    chip2.textures = TObjEneRecobox__static_instance->models[3].m_c;
    spawn_particle_effect_with_flags(&recon->position, 0x45, 0x40);
    spawn_particle_effect_with_flags(&recon->position, 0x46, 0x40);
    new TObjChip(tl_05, &chip0);
    new TObjChip(tl_05, &chip1);
    new TObjChip(tl_05, &chip2);
}

}
