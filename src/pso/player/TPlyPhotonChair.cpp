#include "pso/npc/ChaoNpcSpawn.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/render/render_util.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TDrawableModel.h"
#include "pso/object/base/TMotionModel.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TObject.h"
#include "pso/player/PlayerSlots.h"


extern const char *bm_ply_photon_chair_model_names[3];
extern const char *bm_ply_photon_chair_motion_names[3];
extern BmlResourceDescriptor photon_chair_resource_descriptor;
__declspec(section ".data") const char *bm_ply_photon_chair_model_names[3] = { "fs_obj_isu_meka.nj", "fs_obj_lobby_isu.nj", NULL };
__declspec(section ".data") const char *bm_ply_photon_chair_motion_names[3] = { "fs_obj_isu_meka.njm", "fs_obj_lobby_isu.njm", NULL };
BmlResourceDescriptor photon_chair_resource_descriptor = { "bm_ply_photon_chair.bml", bm_ply_photon_chair_model_names, bm_ply_photon_chair_motion_names, 2, 2 };
const char *TPlyPhotonChair::class_name = "TPlyPhotonChair";
/* radar marker colour (a, r, g, b) per section id */
const NJS_ARGB section_id_color_table[10] = {
    { 1.0f, 0.2f, 0.6f, 0.2f },
    { 1.0f, 0.0f, 1.0f, 0.3f },
    { 1.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.7f, 0.0f, 1.0f },
    { 1.0f, 1.0f, 0.7f, 0.7f },
    { 1.0f, 0.5f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 0.5f, 0.0f },
    { 1.0f, 0.6f, 0.5f, 0.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
};

extern "C" {

void TPlyPhotonChair::render() {
    Vec node_pos;
    NJS_ARGB color;
    NJS_ARGB half_color;
    TObjPlayer *player = get_player_by_client_id(get_owner_id());
    if (player != NULL) {
        marker.get_color(&color);
        {
            half_color.a = color.a;
            half_color.r = 0.5f * color.r;
            half_color.g = 0.5f * color.g;
            half_color.b = 0.5f * color.b;
        }
        player->get_anim_node_position(2, &node_pos);
        position.x = node_pos.x;
        position.y = node_pos.y - 4.6f;
        position.z = node_pos.z;
        copy_xyz(&rotation_x, &player->rotation_x);
        if (player->is_inactive() != 0) {
            save_model_draw_state(&marker);
            set_texture_list(texlist);
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(NULL, rotation_y);
            scale_current_matrix(&scale.x);
            if (TMainTask::get_render_pass() != 0) {
                begin_constant_color_draw(&marker, &color);
                lobby_seat.draw_model();
            } else {
                begin_constant_color_draw(&marker, &half_color);
                meka_seat.draw_model();
            }
            pop_matrix();
            restore_model_draw_state(&marker);
        }
    }
}

void TPlyPhotonChair::run_task() {
    TObjPlayer *player;
    if ((player = get_player_by_client_id(get_owner_id())) == NULL) {
        queue_destruction();
        return;
    }
    if (owner_dismounted == 0 && player->is_mounted() == 0) {
        owner_dismounted = 1;
        lobby_seat.play_to_end();
        lobby_seat.set_speed(2.0f);
        meka_seat.play_to_end();
        meka_seat.set_speed(2.0f);
    }
    switch ((s32)owner_dismounted) {
    case 0:
        lobby_seat.play_forward();
        meka_seat.play_forward();
        return;
    case 1:
        lobby_seat.play_backward();
        meka_seat.play_backward();
        if (lobby_seat.get_frame() <= 0.0f) {
            queue_destruction();
        }
        return;
    }
}

void TPlyPhotonChair::free_static_model() {
    if (shared_model_resource != NULL) {
        delete shared_model_resource;
        shared_model_resource = NULL;
    }
}

s32 TPlyPhotonChair::load_resources() {
    BmlResource *resource = new BmlResource(5, &photon_chair_resource_descriptor, 0, 0, NULL);
    shared_model_resource = resource;
    if (resource == NULL) {
        return 0;
    }
    return 1;
}

}
TPlyPhotonChair::~TPlyPhotonChair() {}

TPlyPhotonChair::TPlyPhotonChair(s32 owner_id, TObject *parent) : TObjBase(parent) {
    TObjPlayer *player;
    m_name = class_name;
    set_owner_id(owner_id);
    m_92 = 0;
    owner_dismounted = 0;
    player = get_player_by_client_id((u16)owner_id);
    if (player == NULL) {
        queue_destruction();
        return;
    }
    marker.set_color(const_cast<NJS_ARGB *>(&section_id_color_table[(s32)player->get_section_id()]));
    texlist = get_bml_texlist(shared_model_resource, 1);
    lobby_seat.set_model(get_bml_model(shared_model_resource, 1));
    lobby_seat.set_motion(reinterpret_cast<NJS_MOTION *>(get_bml_motion(shared_model_resource, 1)));
    lobby_seat.set_frame_count_from_motion();
    lobby_seat.set_speed(1.0f);
    lobby_seat.play_to_end();
    meka_seat.set_model(get_bml_model(shared_model_resource, 0));
    meka_seat.set_motion(reinterpret_cast<NJS_MOTION *>(get_bml_motion(shared_model_resource, 0)));
    meka_seat.set_frame_count_from_motion();
    meka_seat.set_speed(1.0f);
    meka_seat.play_to_end();
}

int TPlyPhotonChair::is_owner_seated() { return owner_dismounted == 0; }
u16 TPlyPhotonChair::get_owner_id() { return owner_id; }
void TPlyPhotonChair::set_owner_id(s32 owner_id) { this->owner_id = owner_id; }
void MarkerColor::get_color(NJS_ARGB *out) { copy_argb(out, &color); }
void TMotionModel::set_speed(f32 speed) { this->speed = speed; }
void TMotionModel::play_to_end() { state = 2; }

void TMotionModel::set_frame_count_from_motion() {
    if (motion != NULL) {
        frame_count = motion->nbFrame;
    }
}

void TMotionModel::set_motion(NJS_MOTION *motion) { this->motion = motion; }
void TDrawableModel::set_model(void *model) { this->model = model; }

TMotionModel::TMotionModel() {
    reset();
}

void TMotionModel::reset() {
    motion = NULL;
    frame = 0.0f;
    frame_count = 0.0f;
    speed = 0.0f;
    state = 0;
}

TDrawableModel::TDrawableModel() {
    reset();
}

void TDrawableModel::reset() { model = NULL; }

void TPlyPhotonChair::free_instance() {
    if (chao_npc_instance_handle != NULL) {
        delete chao_npc_instance_handle;
        chao_npc_instance_handle = NULL;
    }
}


BmlResource *TPlyPhotonChair::shared_model_resource;
