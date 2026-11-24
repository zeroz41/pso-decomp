#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjComputer.h"
#include "pso/object/TObjGbAdvance.h"
#include "pso/object/TObjMesBase.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/container/TObjContainerAbeEnemy.h"
#include "pso/map/FloorArea.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include <dolphin/base/PPCArch.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/TLanguage_801E4874.h"


extern u32 actor_frame_tick;
void load_computer_resources(void);
const char *fe_obj_tanmatu02_model_names[3] = {"fe_obj_tanmatu02.gj", "fs_obj_tanmatu01.gj", NULL};
const char *fe_obj_tanmatu02_motion_names[1] = {NULL};
BmlResourceDescriptor fe_obj_tanmatu02_resource_descriptor = {
    "fe_obj_tanmatu02.bml", fe_obj_tanmatu02_model_names, fe_obj_tanmatu02_motion_names, 2, 0,
};
const char *bm_obj_gba_model_names[5] = {
    "gba_white_body.gj", "gba_white_disp.gj", "gba_white_footsw.gj", "gba_white_scan.gj", NULL,
};
const char *bm_obj_gba_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_gba_resource_descriptor = {
    "bm_obj_gba.bml", bm_obj_gba_model_names, bm_obj_gba_motion_names, 4, 0,
};
const char *fs_obj_tanmatu02_model_names[3] = {"fe_obj_tanmatu02.gj", "fs_obj_tanmatu01.gj", NULL};
const char *fs_obj_tanmatu02_motion_names[1] = {NULL};
BmlResourceDescriptor fs_obj_tanmatu02_resource_descriptor = {
    "fs_obj_tanmatu02.bml", fs_obj_tanmatu02_model_names, fs_obj_tanmatu02_motion_names, 2, 0,
};
const char *TObjComputer__class_name = "TObjComputer";
const char *TObjGbAdvance__class_name = "TObjGbAdvance";
const s16 TObjComputer__data_805DBCD8[2] = {1, 0};

BmlResource *TObjComputer__model_archive;
NJS_TEXLIST *TObjComputer__texture_gvm_handle;
u16 computer_uv_scroll_phase;
BmlResource *TObjGbAdvance__data_805D5B74;

CollisionBody obj_computer_collision_body_parts = {{0.0f, 7.0f, 0.0f}, 7.0f, 7.0f, 1, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f};
CollisionBody gb_advance_collision_body_parts = {{0.0f, 20.0f, -10.0f}, 5.0f, 5.0f, 1, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f};


TObjComputer::TObjComputer(TObject *parent, ObjectSetData *placement) : TObjMesBase(parent, placement) {
    m_name = TObjComputer__class_name;
    if (set_params[1] < 0) {
        set_params[1] = 0;
    }
    if (set_params[1] > 1) {
        set_params[1] = 1;
    }
    if (TObjComputer__model_archive != NULL) {
        screen_model = reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TObjComputer__model_archive, TObjComputer__data_805DBCD8[set_params[1]]));
    } else {
        queue_destruction();
        return;
    }
    init_collision_body_parts(this, &obj_computer_collision_body_parts, 1);
    actorFlags |= 0x40000000;
    register_object_by_id();
    cursor_action.set_use();
    uv_scroll_time = 0.0f;
    m_c4 = 0;
}

TObjComputer::~TObjComputer() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void load_computer_resources(void) {
    BmlResource *p;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA: case AREA_JUNGLE_NORTH: case AREA_JUNGLE_EAST: case AREA_MOUNTAIN: case AREA_SEASIDE: case AREA_SEABED_UPPER: case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT: case AREA_TOWER:
        p = new BmlResource(5, (BmlResourceDescriptor *)&fs_obj_tanmatu02_resource_descriptor, 0, 0, NULL);
        TObjComputer__model_archive = p;
        TObjComputer__texture_gvm_handle = load_gvm_texture_file("fs_obj_tanmatu02.gvm");
        computer_uv_scroll_phase = 0;
        break;
    default:
        p = new BmlResource(5, (BmlResourceDescriptor *)&fe_obj_tanmatu02_resource_descriptor, 0, 0, NULL);
        TObjComputer__model_archive = p;
        TObjComputer__texture_gvm_handle = load_gvm_texture_file("fe_obj_computer.gvm");
        computer_uv_scroll_phase = 1;
        break;
    }
}

void TObjComputer::free_resources() {
    if (TObjComputer__texture_gvm_handle != NULL) {
        release_texture_list(TObjComputer__texture_gvm_handle);
        safe_free(TObjComputer__texture_gvm_handle);
        TObjComputer__texture_gvm_handle = NULL;
    }
    if (TObjComputer__model_archive != NULL) {
        delete (BmlResource *)TObjComputer__model_archive;
        TObjComputer__model_archive = NULL;
    }
}

void *create_stage_computer(void *placement) {
    return new TObjComputer(static_cast<TObject *>(tl_05), static_cast<ObjectSetData *>(placement));
}

void TObjComputer::vfunc_14() {
    TObjMesBase::vfunc_14();
    if ((s32) this->messageLabel != 0) {
        submit_cursor_candidate(this, -1);
    }
    this->uv_scroll_time += 0.2f;
}

void TObjComputer::clear_ref_if_destroyed() {
    TObjMesBase::clear_ref_if_destroyed();
    this->uv_scroll_time += 0.2f;
}

void TObjComputer::render() {
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        draw_model();
    }
}

void TObjComputer::draw_model() {
    if (screen_model == NULL) {
        return;
    }
    TObjFish::set_global_param(TObjComputer__texture_gvm_handle);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    if (TObjComputer__data_805DBCD8[set_params[1]] == 1) {
        u32 tick = actor_frame_tick;
        if (tick != m_c4 && uv_scroll_time >= 1.0f) {
            m_c4 = tick;
            scroll_ginja_mesh_uvs(static_cast<GinjaModel *>(screen_model->child->model), 0, (s32)uv_scroll_time, computer_uv_scroll_phase, 1);
            PPCSync();
            f32 time = uv_scroll_time;
            uv_scroll_time = time - (f32)(s32)time;
        }
        post_translate_matrix(screen_model->pos);
        rotate_matrix_by_node_angles(screen_model->ang, screen_model->evalflags & NJD_EVAL_ZXY_ANG);
        draw_ginja_object(screen_model);
        if (screen_model->child != NULL) {
            TParticleCtrl::begin_effect_render();
            draw_ginja_object(screen_model->child);
            TParticleCtrl::end_effect_render();
        }
    } else {
        draw_ginja_object(screen_model);
    }
    pop_matrix();
}

void TObjComputer::debug_draw_label() {
    this->TObjMesBase::debug_draw_label();
    this->set_params[1] = this->set_params[1] % 2;
    screen_model = reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TObjComputer__model_archive, TObjComputer__data_805DBCD8[this->set_params[1]]));
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, "<- MODEL SELECT");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

TObjGbAdvance::TObjGbAdvance(TObject *parent, ObjectSetData *placement) : TObjMesBase(parent, placement) {
    m_name = TObjGbAdvance__class_name;
    init_collision_body_parts(this, &gb_advance_collision_body_parts, 1);
    actorFlags |= 0x40000000;
    register_object_by_id();
    cursor_action.set_use();
}
#undef mes_base

TObjGbAdvance::~TObjGbAdvance() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjGbAdvance::vfunc_14() {
    TObjMesBase::vfunc_14();
    if ((s32) this->messageLabel != 0) {
        submit_cursor_candidate(this, -1);
    }
}

void TObjGbAdvance::render() {
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(get_bml_texlist((BmlResource *)TObjGbAdvance__data_805D5B74, 0));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, this->rotation_y);
        draw_ginja_object((void *)get_bml_model((BmlResource *)TObjGbAdvance__data_805D5B74, 0));
        draw_ginja_object((void *)get_bml_model((BmlResource *)TObjGbAdvance__data_805D5B74, 1));
        draw_ginja_object((void *)get_bml_model((BmlResource *)TObjGbAdvance__data_805D5B74, 2));
        draw_ginja_object((void *)get_bml_model((BmlResource *)TObjGbAdvance__data_805D5B74, 3));
        pop_matrix();
    }
}

void TObjGbAdvance::load_resource_instance() {
    BmlResource *archive = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_gba_resource_descriptor, 0, 0, NULL);
    TObjGbAdvance__data_805D5B74 = archive;
}

void TObjGbAdvance::free_shared_data() {
    if (TObjGbAdvance__data_805D5B74 != NULL) {
        delete (BmlResource *)TObjGbAdvance__data_805D5B74;
        TObjGbAdvance__data_805D5B74 = NULL;
    }
}
