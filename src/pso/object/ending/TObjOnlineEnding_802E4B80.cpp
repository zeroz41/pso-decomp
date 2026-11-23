#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include <string.h>
#include "pso/ui/window/TWindowChallengeResult.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/object/ending/TObjOnlineEndingHexMove.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby_80070A00.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

extern "C" {


    extern int player_unique_pair_entry_count;
__declspec(section ".data") const char *onlineending_dat_model_names[2] = {
    "ending_blue_oya.nj", NULL,
};
const char *onlineending_dat_motion_names[26] = {
    "ed_A_a_body.njm",
    "ed_A_b_body.njm",
    "ed_B_a_body.njm",
    "ed_B_b_body.njm",
    "ed_C_a_body.njm",
    "ed_C_b_body.njm",
    "ed_D_a_body.njm",
    "ed_D_b_body.njm",
    "ed_E_a_body.njm",
    "ed_E_b_body.njm",
    "ed_F_a_body.njm",
    "ed_F_b_body.njm",
    "ed_G_a_body.njm",
    "ed_G_b_body.njm",
    "ed_H_a_body.njm",
    "ed_H_b_body.njm",
    "ed_I_a_body.njm",
    "ed_I_b_body.njm",
    "ed_J_a_body.njm",
    "ed_J_b_body.njm",
    "ed_K_a_body.njm",
    "ed_K_b_body.njm",
    "ed_L_a_body.njm",
    "ed_L_b_body.njm",
    "ending_blue_oya.njm",
    NULL,
};
// inferred: onlineending_dat_resource_descriptor, named after its archive.
BmlResourceDescriptor onlineending_dat_resource_descriptor = {
    "onlineending_dat.bml", onlineending_dat_model_names, onlineending_dat_motion_names, 1, 25,
};
struct OnlineEndingPlayerPlacement {
    Vec position;
    s32 yaw;
    f32 scale;
};


OnlineEndingPlayerPlacement lbl_804E35F8[48] = {
    {{-18.8999996f, -8.0f, -9.0f}, 9466, 1.25f},
    {{5.8499999f, -8.0f, -9.0f}, 0, 1.25f},
    {{-5.8499999f, -13.0f, -9.0f}, 1815, 1.25f},
    {{19.3500004f, -13.0f, -9.0f}, 11026, 1.25f},
    {{-18.0f, -6.0f, -10.0f}, 84815, 1.25f},
    {{6.75f, -6.0f, -10.0f}, 33602, 1.25f},
    {{-6.29999971f, -10.5f, -10.0f}, -4276, 1.25f},
    {{19.7999992f, -11.0f, -10.0f}, -13142, 1.25f},
    {{-18.4499989f, -6.5f, -8.9999752f}, 5694, 1.20000005f},
    {{6.29999971f, -6.5f, -8.9999752f}, -5841, 1.20000005f},
    {{-5.8499999f, -12.0f, -5.4999752f}, 3233, 1.20000005f},
    {{16.1999989f, -13.5f, -5.4999752f}, -2503, 1.20000005f},
    {{-18.0f, -7.5f, -8.5f}, 771, 1.25f},
    {{5.8499999f, -7.5f, -8.5f}, -8093, 1.25f},
    {{-6.75f, -14.0f, -10.5f}, -13246, 1.25f},
    {{19.3500004f, -14.0f, -10.5f}, 7092, 1.25f},
    {{-19.3500004f, -7.0f, -9.0f}, -10537, 1.0f},
    {{6.75f, -6.5f, -9.0f}, -837, 1.0f},
    {{-4.5f, -14.0f, -9.0f}, 10515, 1.0f},
    {{18.4499989f, -14.5f, -9.0f}, -5756, 1.0f},
    {{-18.4499989f, -6.0f, -9.0f}, 8135, 1.25f},
    {{6.29999971f, -5.5f, -9.0f}, 0, 1.25f},
    {{-6.29999971f, -12.0f, -9.0f}, -7301, 1.25f},
    {{19.7999992f, -11.5f, -9.0f}, 1355, 1.25f},
    {{-18.4499989f, -5.5f, -10.0f}, -12516, 1.25f},
    {{6.75f, -6.0f, -10.0f}, -6675, 1.25f},
    {{-6.75f, -12.0f, -10.0f}, 0, 1.25f},
    {{18.4499989f, -12.5f, -10.0f}, -10221, 1.25f},
    {{-19.7999992f, -8.0f, -10.0f}, 7822, 1.25f},
    {{5.8499999f, -7.5f, -10.0f}, -3337, 1.25f},
    {{-7.64999962f, -17.5f, -10.0f}, 13448, 1.25f},
    {{18.4499989f, -16.5f, -10.0f}, -60920, 1.25f},
    {{-18.8999996f, -8.5f, -9.5f}, 12307, 1.25f},
    {{5.8499999f, -6.5f, -9.5f}, 5319, 1.25f},
    {{-5.8499999f, -12.0f, -9.5f}, 5006, 1.25f},
    {{19.3500004f, -13.0f, -9.5f}, -4797, 1.25f},
    {{-17.5762348f, -4.0f, -3.54770803f}, 109, 1.25f},
    {{5.71477032f, -4.0f, -3.54770803f}, -11104, 1.25f},
    {{-6.27946186f, -12.5f, -3.137012f}, 0, 1.25f},
    {{16.7950974f, -12.5f, -3.137012f}, -6371, 1.25f},
    {{-19.8624954f, -7.0f, -14.1389103f}, -30037, 1.25f},
    {{6.29999971f, -7.0f, -14.1389103f}, -8738, 1.25f},
    {{-6.61436462f, -12.5f, -13.6433401f}, -11832, 1.25f},
    {{20.0431976f, -12.5f, -13.6433401f}, -19660, 1.25f},
    {{-19.0971432f, -3.8311491f, -7.84405184f}, 7281, 1.25f},
    {{5.81419611f, -3.8311491f, -7.84405184f}, 1365, 1.25f},
    {{-6.31618214f, -12.2981701f, -7.44805622f}, -13835, 1.25f},
    {{18.3655605f, -12.2981701f, -7.44805622f}, -8556, 1.25f},
};
s32 lbl_804E39B8[24] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
};
s32 lbl_804E3A18[4] = {2, 1, 0, 3};
s32 lbl_804E3A28[4] = {1, 0, 0, 1};
Vec lbl_804E3A38 = {20000.0f, 0.0f, 0.0f};
NJS_POINT2 online_ending_quad_vertices[4] = {
    {256.0f, 0.0f}, {384.0f, 0.0f}, {128.0f, 0.0f}, {514.0f, 0.0f},
};

extern unsigned char lbl_8050DAD0[];
}

struct Cam_802E4E44 {
    u8 pad0[0x14];
    s32 f14;
    u8 pad18[4];
    Vec a;
    Vec b;
    u8 pad34[0x8];
};

extern "C" {
const char *TObjOnlineEnding__name = "TObjOnlineEnding";
// inferred: the camera position and target run_task gives the ending scene.
static const Vec online_ending_camera_eye = {20000.0f, 0.0f, 0.0f};
static const Vec online_ending_camera_target = {20000.0f, 0.0f, -100.0f};
u32 calc_text_width(char *s);
f32 online_ending_scene_scale = 0.88f;
f32 online_ending_quad_y_offset = -24.0f;
f32 online_ending_scene_z_offset;
BmlResource *online_ending_resource;
s8 online_ending_scene_translation_initialized;
s8 online_ending_quad_vertices_initialized;
void reset_hex_line_params();
}

// Built with -inline off,deferred: functions are emitted last to first, so they are written in reverse.

void fn_802E52AC() {
    saddr r;
    if (online_ending_resource == NULL) {
        r = (saddr)new BmlResource(5, &onlineending_dat_resource_descriptor, 0, 0, NULL);
        online_ending_resource = reinterpret_cast<BmlResource *>(r);
        if (online_ending_resource == NULL) {
            return;
        }
    }
}

void TBoss4DarkFalz::free_global_instance() {
    if (online_ending_resource != NULL) {
        delete (BmlResource *)online_ending_resource;
        online_ending_resource = NULL;
    }
}

void *TObjOnlineEnding::create(void *parent) {
    return new TObjOnlineEnding(static_cast<TObject *>(parent));
}

#pragma push
#pragma opt_common_subs off
TObjOnlineEnding::TObjOnlineEnding(TObject *parent) : TObjBase(parent) {
    s32 i;
    u8 *pl;
    OnlineEndingPlayer *e;
    TObjOnlineEnding *self = this;

    m_name = TObjOnlineEnding__name;
    self->ending_area = get_current_floor_area();
    self->ending_variant = 0;
    TObject *object = self;
    switch (self->ending_area) {
    case 14:
        self->ending_variant = 0;
        break;
    case 31:
        self->ending_variant = 1;
        break;
    default:
        object->queue_destruction();
        return;
    }
    self->scene_model = reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)online_ending_resource, 0));
    self->scene_textures = reinterpret_cast<NJS_TEXLIST *>(get_bml_texlist((BmlResource *)online_ending_resource, 0));
    self->scene_motion = get_bml_motion(online_ending_resource, 0x18);
    self->player_count = 0;
    for (i = 0; i < 4; i++) {
        self->players[i].active = 0;
        self->players[i].name[0] = 0;
    }
    for (i = 0; i < 4; i++) {
        pl = (u8 *)get_player_by_client_id(i);
        if (pl != 0 && self->ending_area == ((TObjPlayer *)pl)->get_area()) {
            s32 c;
            e = &self->players[self->player_count];
            e->active = 1;
            e->id = i;
            strncpy(e->name, (char *)(pl + 0x85C), 0x10);
            c = *(s8 *)(pl + 0x88D);
            {
                OnlineEndingPlayerPlacement *placement = &lbl_804E35F8[lbl_804E3A18[self->player_count] + c * 4];
                e->position = &placement->position;
                e->yaw = placement->yaw;
                e->scale = placement->scale;
            }
            e->motion = get_bml_motion(online_ending_resource, lbl_804E39B8[lbl_804E3A28[self->player_count] + c * 2]);
            self->player_count++;
        }
    }
    self->scene_frame = (-0.3f);
    restore_player_cameras();
    switch (self->ending_variant) {
    case 0:
        play_area_music((char *)"ENDING_LOOP.adx");
        break;
    default:
    case 1:
        play_area_music((char *)"CUBE_ENDING_LOOP.adx");
        break;
    }
    reset_hex_line_params();
    TObjOnlineEndingHexMove::create(this);
    self->create_result_window();
    self->elapsed_frames = 0;
    self->scene_state = 0;
}

#pragma pop

TObjOnlineEnding::~TObjOnlineEnding() {
    close_window();
    restore_player_cameras();
}

void TObjOnlineEnding::run_task() {
    s32 i;
    for (i = 0; i < player_count; i++) {
        if (players[i].active != 0 && get_player_by_client_id(players[i].id) == 0) {
            players[i].active = 0;
        }
    }
    switch (scene_state) {
    case 0:
        scene_state = 1;
        break;
    case 1: {
        activate_camera_mode(9);
        Vec t1 = online_ending_camera_eye;
        Vec t2 = online_ending_camera_target;
        Cam_802E4E44 cam;
        VecCopy((Vec *)&cam.a, (const Vec *)&t1);
        VecCopy((Vec *)&cam.b, (const Vec *)&t2);
        cam.f14 = 0x1999;
        set_active_camera_pose_from_params((CameraParams *)&cam);
        scene_state = 2;
        break;
    }
    default:
        if ((scene_frame += 0.3f) >= 17.0f) {
            scene_frame = 17.0f;
        }
        if (++elapsed_frames >= 450) {
            queue_destruction();
        }
        break;
    }
}

void TObjOnlineEnding::render() {
    s32 i;
    OnlineEndingPlayer *e;
    if (online_ending_scene_translation_initialized == 0) {
        lbl_804E3A38.z = (-100.0f) + online_ending_scene_z_offset;
        online_ending_scene_translation_initialized = 1;
    }
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(&lbl_804E3A38.x);
    scale_matrix(0, online_ending_scene_scale, 1.0f, 1.0f);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(scene_textures));
    draw_model_motion(scene_model, scene_motion, scene_frame);
    pop_matrix();
    for (i = 0; i < player_count; i++) {
        e = &players[i];
        if (e->active != 0) {
            if (online_ending_quad_vertices_initialized == 0) {
                online_ending_quad_vertices[0].y = 63.0f + online_ending_quad_y_offset;
                online_ending_quad_vertices[1].y = 343.0f + online_ending_quad_y_offset;
                online_ending_quad_vertices[2].y = 343.0f + online_ending_quad_y_offset;
                online_ending_quad_vertices[3].y = 63.0f + online_ending_quad_y_offset;
                online_ending_quad_vertices_initialized = 1;
            }
            {
                char *name = e->name;
                u32 w = calc_text_width(name);
                NJS_POINT2 v = online_ending_quad_vertices[i];
                v.x -= (f32)(w >> 1);
                TAdSubPlyItemGC::render_status_line(v.x, v.y, 0.1f, name, -1);
            }
            push_matrix();
            post_translate_matrix(&lbl_804E3A38.x);
            post_translate_matrix(&e->position->x);
            rotate_matrix_y(0, e->yaw);
            scale_matrix(0, e->scale, e->scale, e->scale);
            TObjPlayer::draw_player_model_by_client(e->id, reinterpret_cast<saddr>(e->motion), 0.0f, 1.0f);
            pop_matrix();
        }
    }
    TParticleCtrl::end_effect_render();
}

void TObjOnlineEnding::create_result_window() {
    result_window = NULL;
    if (TLobby::is_flag_set() != 0) {
        if (TLobby::get_online_result_value() == TWindowSubStatusDisp::get_layout_id(-1) - 1) {
            result_window = new TWindowChallengeResult((const char *)TLobby__sub_80070ACC(),
                TWindowSubStatusDisp__sub_800718D0(), get_card_window_value());
        }
    }
}

void TObjOnlineEnding::close_window() {
    if (result_window != NULL) {
        result_window->close();
        result_window = NULL;
    }
}

void*TObjOnlineEnding::get_attack_entry(int a0) {  return (char*)lbl_8050DAD0 + a0 * 8; }

int TObjOnlineEnding::get_instance() {  return player_unique_pair_entry_count; }
