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
#include "pso/system/BmlResource.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/unk/text_803D8F74.h"


TObjMotionAction moja_action_table[2] = {
    {1, 0, 0, 0.5f, 1},
    {1, 0, 1, 0.6f, 1},
};
CollisionBody TObjNpcMoja::collision_body_parts = {{0.0f, 7.5f, 0.0f}, 7.0f, 0.0f, 0, 0x30203, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *TObjNpcMoja::name = "TObjNpcMoja";

TObjNpcMoja::TObjNpcMoja(TObject *parent, void *set_data) : TObjNpcBase(parent) {
    m_name = name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_set_params(0, 1);
    model = get_bml_model(moja_bml_resource, 0);
    texlist = get_bml_texlist(moja_bml_resource, 0);
    init_motion(moja_action_table, moja_bml_resource->motions, requested_action);
    movementParameters = &npc_movement_parameters;
    set_motion_params(&npc_default_battle_stats);
    init_collision_body_parts(this, &collision_body_parts, 1);
    register_object_by_id();
    update_prev_position();
    copy_position();
}

TObjNpcMoja::~TObjNpcMoja() {}

void *TObjNpcMoja::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMoja(control, set_data);
}

void TObjNpcMoja::render() {
    if (update_object_view_visibility(view_distance, view_radius) != 0 && (s32)visible == 1) {
        model_render_flags |= 1;
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix_from(0);
        translate_matrix_vec3((u8 *)0, (u8 *)&position);
        rotate_matrix_y(0, rotation_y);
        draw();
        pop_matrix();
        model_render_flags &= ~1;
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
