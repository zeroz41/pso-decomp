#include "types.h"
#include "pso/render/CameraCapture.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/galgryphon/TObjBoss5FloorStone.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_80066F5C.h"

void draw_shadowed_node_tree(NJS_OBJECT *object) {
    if (object != NULL) {
        push_matrix();
        post_translate_matrix(object->pos);
        rotate_matrix_by_node_angles(object->ang, 1);
        scale_current_matrix(object->scl);
        if (!(object->evalflags & NJD_EVAL_HIDE) && object->model != NULL) {
            render_projected_shadow_receiver(object->pos, object->ang);
            ::draw_ginja_model(object->model);
            TScene::apply_single_screen_state();
        }
        draw_shadowed_node_tree(object->child);
        pop_matrix();
        draw_shadowed_node_tree(object->sibling);
    }
}

void draw_shadowed_object(NJS_TEXLIST *texlist, NJS_OBJECT *object) {
    bind_shadow_map_texture();
    set_texture_list(texlist);
    push_matrix();
    draw_shadowed_node_tree(object);
    pop_matrix();
}

