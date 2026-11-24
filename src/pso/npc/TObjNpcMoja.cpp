#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/npc/TObjNpcMoja.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/TObjControl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

extern "C" {


void init_collision_body_parts(void *, void *, s32);
s32 rotate_matrix_y(s32, s32);
extern s32 model_render_flags;
}

TObjMotionAction moja_action_table[2] = {
    {1, 0, 0, 0.5f, 1},
    {1, 0, 1, 0.6f, 1},
};
void *lbl_804AABD8[11] = {
    (void *)0x0, (void *)0x40f00000, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x30203, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
const char *TObjNpcMoja__name = "TObjNpcMoja";

TObjNpcMoja::TObjNpcMoja(TObject *parent, void *set_data) : TObjNpcBase(parent) {
    m_name = TObjNpcMoja__name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_set_params(0, 1);
    model = get_bml_model(moja_bml_resource, 0);
    texlist = get_bml_texlist(moja_bml_resource, 0);
    init_motion(moja_action_table, moja_bml_resource->motions, requested_action);
    movementParameters = &npc_movement_parameters;
    set_motion_params(&npc_default_battle_stats);
    init_collision_body_parts(this, lbl_804AABD8, 1);
    ((TObjPlayer *)this)->register_object_by_id();
    update_prev_position();
    copy_position();
}

TObjNpcMoja::~TObjNpcMoja() {}

void *TObjNpcMoja::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMoja(control, set_data);
}

void TObjNpcMoja::render() {
    if (update_object_view_visibility(m_398, m_39c) != 0 && (s32)m_390 == 1) {
        model_render_flags |= 1;
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix_from(0);
        translate_matrix_vec3((u8 *)0, (u8 *)&position);
        rotate_matrix_y(0, rotation_y);
        ((TObjMotion *)this)->draw();
        pop_matrix();
        model_render_flags &= 0xFFFFFFFE;
        draw_ground_shadow(0, 0);
    }
}

void TObjNpcMoja::request_action(s32) {
    if ((s16) this->mode != 2) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}
