#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/render/DebugFont.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/memory.h"
#include "pso/camera/RadarMapViewState.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/MatrixStack.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/GinjaView.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/UISprite.h"
#include "pso/system/BmlResource.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"
#include <string.h>

#include "pso/technique/TTecCtrl.h"

#include <stddef.h>
#include "pso/system/THeap.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/render/TextureState.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/system/scene/TScene.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXCull.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/ScreenSpriteDraw.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/model_render_state.h"
#include "pso/network/client_id.h"
#include "pso/ui/hud/RadarMapData.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/math/MatrixReflect.h"

// View distance limits: default (and the follow view's cap), zoom minimum, zoom maximum; then the ctor's f170.
f32 radar_camera_height_default = 2000.0f;
f32 radar_camera_height_min = 1200.0f;
f32 radar_camera_height_max = 3500.0f;
f32 radar_camera_rise_speed = 80.0f;

u8 *TRaderMapCore::floor_map_resource;
s32 lbl_805D5F2C;
s32 radar_marker_count;
s8 lbl_805D5F34;
s32 lbl_805D5F38;
s32 TRaderMapCore::view_mode;
void *TRaderMapCore::instance;
s32 TRaderMapCore::render_mode;
BmlResource *radar_frame_model_resource;
NJS_TEXLIST *radar_frame_texlist;
THeap *TRaderMapCore::map_heap;

extern NJS_TEXANIM radar_sprite_texanims[];
extern f32 radar_compass_positions[][4];
extern RadarScissorRect radar_map_view_scissor_table[3];
extern RadarViewportRect radar_map_view_rect_table[3];
s32 init_radar_floor_flags(s32 floor, RadarPieceInitMap *map);
extern "C" {
}
extern RadarBackdropColor radar_map_backdrop_color;
void set_radar_marker_color(TRaderMapCore *unused, u32 color);
// Marker colours (a, r, g, b) per player slot: red, green, yellow, blue.
static const RadarColor4 radar_player_slot_color_table[4] = {
    { 1.0f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f, 1.0f },
};
extern "C" {
NJS_POINT2 get_follow_marker_position(TRaderMapCore *core);

}
void update_radar_auto_discovery(TRaderMapCore *core, s32 unused, void *pos);
#define RADAR_REGION_MAP ((struct RadarRegionMap *) TRaderMapCore::floor_map_resource)


#define RADAR_MODEL_REGION_MAP ((RadarModelRegionMap *) TRaderMapCore::floor_map_resource)


#define SHOW(t) ((s32 (*)(void *))TRaderMapCore::should_show_map)(t)

RadarBackdropColor radar_map_backdrop_color = { 1.0f, 0.3f, 0.3f, 0.3f };
RadarViewportRect radar_map_view_rect_table[3] = {
    { 544.0f, 128.0f, 640.0f, 480.0f, 500.0f },
    { 256.0f, 352.0f, 640.0f, 480.0f, 500.0f },
    { 320.0f, 240.0f, 640.0f, 480.0f, 500.0f },
};
RadarScissorRect radar_map_view_scissor_table[3] = {
    { 15.0f, 2.0f, 19.0f, 6.0f },
    { 1.0f, 9.0f, 15.0f, 13.0f },
    { 1.0f, 9.0f, 15.0f, 13.0f },
};
// Per map mode: the compass sprite position and the position of the marker sprite drawn with it.
f32 radar_compass_positions[3][4] = {
    { 575.0f, 149.0f, 575.0f, 159.0f },
    { 450.0f, 373.0f, 450.0f, 383.0f },
    { 450.0f, 373.0f, 450.0f, 383.0f },
};
NJS_TEXANIM radar_sprite_texanims[2] = {
    { 32, 32, 16, 27, 0, 0, 256, 256, 0, 0 },
    { 32, 32, 16, 16, 0, 0, 256, 256, 1, 0 },
};

static NJS_POINT2 radar_backdrop_origin[3] = { { 480.0f, 64.0f }, { 32.0f, 288.0f }, { 96.0f, 176.0f } };
static NJS_POINT2 radar_backdrop_size[3] = { { 128.0f, 128.0f }, { 448.0f, 128.0f }, { 448.0f, 128.0f } };
static f32 radar_backdrop_alpha[3] = { 64.0f, 64.0f, 128.0f };
// The radar's frame models, loaded by load_frame_texture.
const char *obj_f_enemy_model_names[] = {
    "obj_f_enemy.gj",
    "obj_f_gate.gj",
    "obj_f_player.gj",
    "obj_f_player_blue.gj",
    "obj_f_player_green.gj",
    "obj_f_player_yellow.gj",
    NULL,
};
const char *obj_f_enemy_motion_names[] = { NULL };
BmlResourceDescriptor obj_f_enemy_resource_descriptor = {
    "obj_f_enemy.bml", obj_f_enemy_model_names, obj_f_enemy_motion_names, 6, 0,
};
const char *rader_map_core_name_ptr = "TRaderMapCore";
// setup_overhead_projection: eye distance factor and field of view (degrees).
f32 radar_eye_scale = 1.0f;
f32 radar_overhead_projection_scale = 75.0f;

#define RADAR_BACKDROP_MAP ((RadarBackdropMap *)TRaderMapCore::floor_map_resource)

RadarMarker radar_marker_buffer[128];
RadarMapViewState radar_map_view_state[3];
s16 *TRaderMapCore::floor_discovery_table[18];


// The unit was built -inline off,deferred, which emits functions in reverse source order: they are
// written here last to first.
#pragma fp_contract on

TUnk_804C88A8::~TUnk_804C88A8() {}

NJS_OBJECT *TRaderMapCore::init_map_ptr(const s32 *, s32 index) {
    return get_bml_model(radar_frame_model_resource, index);
}

void RadarPlayerMarker::reset() {
    z = 0.0f;
    y = 0.0f;
    x = 0.0f;
    rot_y = 0;
    scale = 1.0f;
    unused_14 = 0;
    id = -1;
    color.b = 1.0f;
    color.g = 1.0f;
    color.r = 1.0f;
    color.a = 1.0f;
}

void TRaderMapCore::load_frame_texture() {
    radar_frame_model_resource = new BmlResource(5, &obj_f_enemy_resource_descriptor, 0, 0, NULL);
    radar_frame_texlist = LoadPvmFileTls("RaderMapFrame.gvm");
}

void TRaderMapCore::free_statics() {
    if (radar_frame_texlist != NULL) {
        release_texture_list(radar_frame_texlist);
        safe_free(radar_frame_texlist);
        radar_frame_texlist = NULL;
    }
    if (radar_frame_model_resource != NULL) {
        delete radar_frame_model_resource;
        radar_frame_model_resource = NULL;
    }
}

s32 TRaderMapCore::apply_compass_param(const s32 *counter) {
    if (radar_frame_texlist != NULL) {
        set_texture_list(radar_frame_texlist);
        return 1;
    }
    return -1;
}

void TRaderMapCore::load_map_resources() {
    char buf[32];
    RadarSceneEntry *e;
    s32 status;
    s32 area;
    area = get_current_floor_area();
    status = TScene::get_status();
    e = (RadarSceneEntry *)get_floor_scene_table(area);
    TLobby::replace_file_extension(buf, (char *)e[status].name, (char *)"r.rel");
    TRaderMapCore::floor_map_resource = static_cast<u8 *>(create_named_object(buf));
    if (TRaderMapCore::floor_map_resource != NULL && RADAR_REGION_MAP->textures != 0) {
        TLobby::replace_file_extension(buf, (char *)e[status].name, "r");
        bind_gvm_texture_list(buf, (NJS_TEXLIST *)((u8 *)RADAR_REGION_MAP->textures));
    }
    copy_name("..");
    memcard_access_active = 0;
    TRaderMapCore::load_frame_texture();
    e = (RadarSceneEntry *)TRaderMapCore::floor_map_resource;
    if (e != NULL) {
        init_radar_floor_flags(get_current_floor(), (RadarPieceInitMap *)e);
    }
    radar_marker_count = 0;
    lbl_805D5F34 = 0;
    lbl_805D5F38 = 0;
    TRaderMapCore::render_mode = 1;
}

void TRaderMapCore::unload_floor_map() {
    NJS_TEXLIST *texlist;
    u8 *map_data;
    map_data = (u8 *)TRaderMapCore::floor_map_resource;
    if (map_data != NULL) {
        save_floor_discovery(get_current_floor(), map_data);
    }
    TRaderMapCore::free_statics();
    if ((void *) TRaderMapCore::floor_map_resource != NULL) {
        texlist = (NJS_TEXLIST *)RADAR_REGION_MAP->textures;
        if (texlist != NULL) {
            release_texture_list(texlist);
        }
    }
    if ((void *) TRaderMapCore::floor_map_resource != NULL) {
        TLobby::free_nodes_with_id((saddr)TRaderMapCore::floor_map_resource);
        TRaderMapCore::floor_map_resource = NULL;
    }
    TRaderMapCore::render_mode = 0;
}

void TRaderMapCore::create() {
    if ((TRaderMapCore::is_not_split_screen() != 1) || (TLobby::is_ready() != 1)) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            new TRaderMapCore(tl_clipout);
        } else {
            new TRaderMapCore(tl_radermap);
        }
    }
}

#pragma push
#pragma opt_common_subs off
TRaderMapCore::TRaderMapCore(TObject *parent) : TObjBase(parent) {
    NJS_CAMERA *g;
    s32 i;
    u32 j;
    m_name = rader_map_core_name_ptr;
    player_marker_model = init_map_ptr(&countdown, 2);
    square_marker_model = init_map_ptr(&countdown, 0);
    wide_marker_model = init_map_ptr(&countdown, 1);
    for (i = 0; i < 3; i++) {
        g = &radar_map_view_state[i].camera;
        init_ninja_camera(g);
        g->py = radar_camera_height_default;
        g->vy = -1.0f;
        g->vz = 0.0f;
        g->roll = 0x8000;
    }
    viewport.depth = 500.0f;
    viewport.screen_width = 640.0f;
    viewport.screen_height = 480.0f;
    viewport.center_x = 544.0f;
    viewport.center_y = 140.0f;
    for (j = 0; j < 4; j++) {
        player_marker_records[j].z = 0.0f;
        player_marker_records[j].y = 0.0f;
        player_marker_records[j].x = 0.0f;
        player_marker_records[j].rot_y = 0;
        player_marker_records[j].scale = 22.0f;
        player_marker_records[j].id = -1;
    }
    follow_marker = 0;
    view_flags = 2;
    zoom_state = 0;
    zoom_step = radar_camera_rise_speed;
    TRaderMapCore::view_mode = 0;
    map_angle = 0;
    TRaderMapCore::instance = this;
    countdown = 0x3C;
    angle = 0;
    pulse_alpha = 0.0f;
    target_player = 0;
    pan_x_speed = 0.0f;
    pan_z_speed = 0.0f;
    zoom_speed = 0.0f;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        radar_render_flags = 0x800810;
        TRaderMapCore::view_mode = 2;
    } else {
        radar_render_flags = 0x800810;
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        alpha_limit = 0.8f;
    } else {
        alpha_limit = 0.8f;
    }
    if (TRaderMapCore::floor_map_resource == 0) {
        queue_destruction();
        return;
    }
}
#pragma pop

TRaderMapCore::~TRaderMapCore() {
    TRaderMapCore::instance = 0;
}

void TRaderMapCore::run_task() {
    TObjPlayer *player;
    s32 delay;
    s32 i;
    if ((uaddr) TRaderMapCore::floor_map_resource != 0U) {
        delay = countdown;
        if (delay > 0) {
            countdown = (delay - 1);
            return;
        }
        switch (TRaderMapCore::view_mode) {
        case 0:
            update_target();
            break;
        case 1:
            update_target();
            break;
        case 2:
            update_pan_zoom_input();
            break;
        }
        gather_player_markers();
        if ((TRaderMapCore::is_not_split_screen() == 1) && (target_player != NULL)) {
            follow_marker = (u16)target_player->get_entity_id();
        }
        update_follow_projection(TRaderMapCore::view_mode);
        if (TRaderMapCore::is_not_split_screen() == 1) {
            i = 0;
            do {
                player = get_player_by_client_id(i);
                if (player != 0) {
                    update_radar_auto_discovery(this, 0, &player->position);
                }
                i += 1;
            } while (i < 4);
        } else {
            update_radar_auto_discovery(this, 0, &player_marker_records[follow_marker]);
        }
        advance_scroll();
    }
}

void TRaderMapCore::advance_scroll() {
    this->angle = (this->angle + 0x888);
    this->pulse_alpha = 127.0f + 64.0f * (1.0f + sin_table_lookup(this->angle));
}
#pragma fp_contract reset

// The view_flags bit update_target sets while TWindowKeyBoardHard::is_card_flag_set holds for the
// target's entity id. A const object, not a literal: update_target and set_target_flag load it (lwz).
static const u32 radar_view_target_flag = 1;

void TRaderMapCore::update_target() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        target_player = player;
    }
    if (target_player != NULL) {
        if (TWindowKeyBoardHard::is_card_flag_set(target_player->get_entity_id()) != 0) {
            this->view_flags |= radar_view_target_flag;
            return;
        }
        this->view_flags = (s32) (this->view_flags & 0xFFFFFFFE);
    }
}

void TRaderMapCore::update_pan_zoom_input() {
    TObjPlayer *p;
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL && p->is_controls_locked() != 0) {
            return;
        }
    }
    if (target_player != NULL) {
        for (j = 0; j < 4; j++) {
            p = get_player_by_client_id(j);
            if (p != NULL && test_pressed_buttons_packed(&controller_input_state.controllers[p->get_controller_port()], 0x200) != 0) {
                target_player = NULL;
                return;
            }
        }
        if (test_previous_buttons_packed(&controller_input_state.controllers[target_player->get_controller_port()], 0x10) != 0) {
            pan_z_speed += 6.0f;
        }
        if (test_previous_buttons_packed(&controller_input_state.controllers[target_player->get_controller_port()], 0x20) != 0) {
            pan_z_speed -= 6.0f;
        }
        if (test_previous_buttons_packed(&controller_input_state.controllers[target_player->get_controller_port()], 0x40) != 0) {
            pan_x_speed += 6.0f;
        }
        if (test_previous_buttons_packed(&controller_input_state.controllers[target_player->get_controller_port()], 0x80) != 0) {
            pan_x_speed -= 6.0f;
        }
        if (test_buttons_repeat_packed(&controller_input_state.controllers[target_player->get_controller_port()], 0x20000, 0x27, 1) != 0) {
            zoom_speed -= 6.0f;
        }
        if (test_buttons_repeat_packed(&controller_input_state.controllers[target_player->get_controller_port()], 0x10000, 0x27, 1) != 0) {
            zoom_speed += 6.0f;
        }
        TRaderMapCore::pan_horizontal(pan_x_speed);
        TRaderMapCore::pan_vertical(pan_z_speed);
        TRaderMapCore::add_zoom_distance(zoom_speed);
        pan_x_speed *= 0.8f;
        pan_z_speed *= 0.8f;
        zoom_speed *= 0.8f;
        return;
    }
    for (k = 0; k < 4; k++) {
        p = get_player_by_client_id(k);
        if (p != NULL && test_pressed_buttons_packed(&controller_input_state.controllers[p->get_controller_port()], 0x200) != 0 &&
            test_flags_04_packed(&controller_input_state.controllers[p->get_controller_port()], 0x10000) != 0) {
            target_player = p;
            NJS_CAMERA *camera = &radar_map_view_state[1].camera;
            camera->px = target_player->position.x;
            camera->pz = target_player->position.z;
            pan_x_speed = 0.0f;
            pan_z_speed = 0.0f;
            zoom_speed = 0.0f;
            return;
        }
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literal 500.0f (pooled
// between render_region_records' 0.08f and update_pan_zoom_input's 6.0f). It stores the defaults
// the constructor gives the viewport depth and size, field by field. Name inferred.
void TRaderMapCore::set_default_view_size() {
    viewport.depth = 500.0f;
    viewport.screen_width = 640.0f;
    viewport.screen_height = 480.0f;
}

s32 TRaderMapCore::is_render_admitted(s32 mode) {
    s32 i;
    TObjPlayer *p;
    if (TRaderMapCore::render_mode == 0) {
        return 0;
    }
    if (target_player != NULL) {
        if (target_player->is_body_collision_inactive() != 0) {
            return 0;
        }
        if (target_player->is_controls_locked() != 0 && TRaderMapCore::view_mode != 1) {
            return 0;
        }
    } else {
        return 0;
    }
    if (TCameraCtrl::is_view_override_active() != 0 && TWindowCtrl::get_flag_bit0() == 0) {
        return 0;
    }
    if (TCameraCtrl::view_state.controller == 5 || TCameraCtrl::view_state.controller == 9) {
        target_player = NULL;
        return 0;
    }
    if (countdown > 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL && p->is_controls_locked() != 0 && mode == 2) {
            return 0;
        }
    }
    return all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

void TRaderMapCore::render() {
    if (TRaderMapCore::floor_map_resource != NULL) {
        if (is_render_admitted(TRaderMapCore::view_mode) == 0) {
            lbl_805D5F2C = 0;
            radar_marker_count = 0;
            return;
        }
        switch (TRaderMapCore::view_mode) {
        case 0:
            draw_backdrop(this, TRaderMapCore::view_mode);
            begin_map_view(TRaderMapCore::view_mode);
            render_region_records(TRaderMapCore::view_mode);
            draw_enemy_gate_markers();
            draw_player_markers();
            setup_view(TRaderMapCore::view_mode);
            draw_compass(TRaderMapCore::view_mode);
            break;
        case 1:
            TCameraCtrl::restore_full_screen_view();
            draw_backdrop(this, TRaderMapCore::view_mode);
            TCameraCtrl::restore_saved_view();
            begin_map_view(TRaderMapCore::view_mode);
            render_region_records(TRaderMapCore::view_mode);
            draw_enemy_gate_markers();
            draw_player_markers();
            setup_view(TRaderMapCore::view_mode);
            TCameraCtrl::restore_full_screen_view();
            this->map_angle = 0;
            draw_compass(TRaderMapCore::view_mode);
            TCameraCtrl::restore_saved_view();
            break;
        case 2:
            draw_backdrop(this, TRaderMapCore::view_mode);
            begin_map_view(TRaderMapCore::view_mode);
            render_region_records(TRaderMapCore::view_mode);
            draw_enemy_gate_markers();
            draw_player_markers();
            setup_view(TRaderMapCore::view_mode);
            break;
        }
        lbl_805D5F2C = 0;
        radar_marker_count = 0;
    }
}

void TRaderMapCore::render_region_records(s32 mode) {
    TRaderMapCore *core = this;
    RadarBackdropRecord *r;
    s32 i;
    saved_model_render_flags = model_render_flags;
    copy_argb(&saved_model_draw_color, &model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= core->radar_render_flags;
    set_chunk_material_override_pair(-0xFF01, 0x900);
    if (RADAR_BACKDROP_MAP->tex != NULL) {
        set_texture_list(RADAR_BACKDROP_MAP->tex);
    }
    i = 0;
    {
    RadarBackdropColor c = radar_map_backdrop_color;
    r = RADAR_BACKDROP_MAP->recs;
    for (; i < RADAR_BACKDROP_MAP->count; i++, r++) {
        if (!(r->flags & 1)) {
            r->alpha += 0.08f;
            if (r->alpha > core->alpha_limit) {
                r->alpha = core->alpha_limit;
            }
            c.r = r->alpha;
            set_constant_material((const NJS_ARGB *)(((f32 *)&c)));
            push_matrix();
            translate_matrix(0, r->x, r->y, r->z);
            rotate_matrix_zyx(0, r->rx, r->ry, r->rz);
            draw_ginja_model(r->model->mesh);
            pop_matrix();
            set_constant_material(&chunk_material_color_half_alpha_f32);
        }
    }
    }
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb(&model_material_color, &saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

#pragma push
#pragma opt_common_subs off
void TRaderMapCore::begin_map_view(int mode) {
    RadarViewportParameters viewport;
    TCameraCtrl::restore_full_screen_view();
    memset(&viewport, 0, sizeof(viewport));
    const RadarViewportRect *rect = &radar_map_view_rect_table[mode];
    viewport.center_x = rect->center_x;
    viewport.center_y = rect->center_y;
    viewport.screen_width = rect->screen_width;
    viewport.screen_height = rect->screen_height;
    viewport.depth = rect->depth;
    configure_viewport(&viewport);
    set_view_scissor(2, &radar_map_view_scissor_table[mode]);
    setup_overhead_projection(&radar_map_view_state[mode]);
    Vec dir = { 0.0f, -1.0f, 0.0f };
    NJS_ARGB color = { 1.0f, 1.0f, 1.0f, 1.0f };
    set_light(&dir, &color, 1.0f);
    TParticleCtrl::begin_effect_render();
}
#pragma pop

void TRaderMapCore::setup_view(s32 mode) {
    GXSetScissorBoxOffset(0, 0);
    set_screen_center(320.0f, 240.0f);
    camera_ctrl_instance->setup_default_view(0);
    set_view_scissor(0, &radar_map_view_scissor_table[mode]);
    TObjLight::apply_distant_light();
    TParticleCtrl::end_effect_render();
}

void TRaderMapCore::draw_backdrop(TRaderMapCore *unused, s32 mode) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL desc;
    NJS_COLOR colors[4];
    u32 color;
    NJS_POINT2 *origin;
    NJS_POINT2 *size;
    desc.p = pos;
    desc.col = colors;
    desc.tex = NULL;
    desc.num = 4;
    color = 0;
    ((u8 *)&color)[3] = (u8)radar_backdrop_alpha[mode];
    origin = &radar_backdrop_origin[mode];
    size = &radar_backdrop_size[mode];
    pos[0].x = origin->x;
    pos[0].y = origin->y;
    pos[1].x = origin->x + size->x;
    pos[1].y = origin->y;
    pos[2].x = origin->x + size->x;
    pos[2].y = origin->y + size->y;
    pos[3].x = origin->x;
    pos[3].y = origin->y + size->y;
    colors[0].color = color;
    colors[1].color = color;
    colors[2].color = color;
    colors[3].color = color;
    set_default_alpha_blend();
    TParticleCtrl::begin_effect_render();
    draw_polygon_2d(&desc, 4, 0x16, -10.0f);
    TParticleCtrl::end_effect_render();
}

void TRaderMapCore::draw_compass(s32 mode) {
    NJS_SPRITE sprite;
    u32 color;
    f32 *compass_xy;
    f32 *marker_xy;
    if (apply_compass_param(&countdown) != 0) {
        sprite.p.x = 0.0f;
        sprite.p.y = 0.0f;
        sprite.p.z = 0.0f;
        sprite.sx = 1.0f;
        sprite.sy = 1.0f;
        sprite.ang = 0;
        sprite.tlist = radar_frame_texlist;
        sprite.tanim = radar_sprite_texanims;
        color = 0xFFFFFFFF;
        TParticleCtrl::begin_effect_render();
        compass_xy = &radar_compass_positions[mode][0];
        marker_xy = compass_xy + 2;
        sprite.p.x = marker_xy[0] + radar_sprite_texanims[1].cx;
        sprite.p.y = marker_xy[1] + radar_sprite_texanims[1].cy;
        set_default_alpha_blend();
        ((u8 *)&color)[3] = (u8)pulse_alpha;
        draw_compass_sprite(&sprite, 1, ((color & 0xFF00) << 16) | (color >> 16) | ((color & 0xFF) << 16), 0x21, 0.8f);
        sprite.p.x = compass_xy[0] + radar_sprite_texanims[0].cx;
        sprite.p.y = compass_xy[1] + radar_sprite_texanims[0].cy;
        sprite.ang = map_angle;
        set_additive_blend();
        draw_compass_sprite(&sprite, 0, -1, 0x21, 0.8f);
        TParticleCtrl::end_effect_render();
    }
}

#pragma push
#pragma scheduling off
void RadarMapViewState::copy_transform(const RadarMapViewState *source) {
    camera.px = source->camera.px;
    camera.py = source->camera.py;
    camera.pz = source->camera.pz;
    camera.vx = source->camera.vx;
    camera.vy = source->camera.vy;
    camera.vz = source->camera.vz;
    camera.roll = source->camera.roll;
    camera.ang = source->camera.ang;
    camera.n_clip = source->camera.n_clip;
    camera.f_clip = source->camera.f_clip;
}
#pragma pop

void TRaderMapCore::update_follow_projection(s32 mode) {
    RadarMapViewState *view = &radar_map_view_state[0];
    RadarMapViewState *free_view = view + 1;
    RadarMapViewState *out = view + 2;
    if (this->follow_marker >= 0) {
        view->camera.px = this->player_marker_records[this->follow_marker].x;
        view->camera.pz = this->player_marker_records[this->follow_marker].z;
    }
    if (this->view_flags & 1) {
        view->camera.roll = 0x8000 - camera_ctrl_instance->yaw;
        if (get_current_floor_area() == AREA_DE_ROL_LE) {
            free_view->camera.roll = 0;
            this->map_angle = 0x8000 - camera_ctrl_instance->yaw;
        } else {
            free_view->camera.roll = 0x8000;
            this->map_angle = -camera_ctrl_instance->yaw;
        }
    } else if (get_current_floor_area() == AREA_DE_ROL_LE) {
        view->camera.roll = 0;
        free_view->camera.roll = 0;
        this->map_angle = 0;
    } else {
        view->camera.roll = 0x8000;
        free_view->camera.roll = 0x8000;
        this->map_angle = 0;
    }
    if (this->view_flags & 2) {
        switch (this->zoom_state) {
        case 0:
            this->zoom_step *= 1.2f;
            view->camera.py += this->zoom_step;
            if (view->camera.py > radar_camera_height_default) {
                view->camera.py = radar_camera_height_default;
            }
            break;
        case 1:
            this->zoom_step *= 1.2f;
            view->camera.py += this->zoom_step;
            if (view->camera.py > radar_camera_height_max) {
                view->camera.py = radar_camera_height_max;
            }
            break;
        case 2:
            this->zoom_step *= 1.2f;
            view->camera.py -= this->zoom_step;
            if (view->camera.py < radar_camera_height_min) {
                view->camera.py = radar_camera_height_min;
            }
            break;
        }
    } else {
        view->camera.py = radar_camera_height_default;
    }
    if (mode == 2) {
        out->copy_transform(free_view);
    } else {
        out->copy_transform(view);
    }
}

void TRaderMapCore::draw_player_markers() {
    RadarPlayerMarker *marker;
    s32 i;
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= this->radar_render_flags;
    set_chunk_material_override_pair(-0xFF01, 0x100);
    marker = player_marker_records;
    i = 0;
    do {
        if (marker->id != -1) {
            set_constant_material(&marker->color);
            push_matrix();
            translate_matrix(0, marker->x, 0.0f, marker->z);
            rotate_matrix_y(0, marker->rot_y);
            scale_matrix(0, marker->scale, marker->scale, marker->scale);
            draw_ginja_object(this->player_marker_model);
            pop_matrix();
            set_constant_material(&chunk_material_color_half_alpha_f32);
        }
        i += 1;
        marker++;
    } while (i < 4);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

void TRaderMapCore::draw_enemy_gate_markers() {
    RadarMarker *g;
    s32 i;
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= this->radar_render_flags;
    set_chunk_material_override_pair(-0xFF01, 0x100);
    for (i = 0, g = (RadarMarker *)&radar_marker_buffer; i < radar_marker_count; i++, g++) {
        set_radar_marker_color(this, g->color);
        push_matrix();
        translate_matrix(0, g->x, 0.0f, g->z);
        rotate_matrix_y(0, g->rot);
        switch (g->kind) {
        case 0:
            scale_matrix(0, 13.6f * g->scale, 8.0f, 5.6f * g->scale);
            draw_ginja_object(this->wide_marker_model);
            break;
        case 1:
            scale_matrix(0, 8.0f * g->scale, 8.0f, 8.0f * g->scale);
            draw_ginja_object(this->square_marker_model);
            break;
        }
        pop_matrix();
    }
    set_constant_material(&chunk_material_color_half_alpha_f32);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

void TRaderMapCore::gather_player_markers() {
    s32 floor;
    RadarPlayerMarker *e;
    s32 team;
    s32 i;
    TObjPlayer *p;
    RadarPlayerMarker *me;
    team = 0;
    floor = get_current_floor();
    follow_marker = -1;
    p = get_player_by_client_id(local_client_id);
    me = &player_marker_records[0];
    if (p != NULL) {
        team = p->pk_state.get_team();
        if (p->is_body_collision_inactive() == 0) {
            VecCopy((Vec *)me, &p->position);
            me->y = 10.0f;
            me->rot_y = p->rotation_y;
            me->id = local_client_id;
            follow_marker = 0;
            if (SHOW(this) != 0) {
                if (team == 1) {
                    copy_argb(&me->color, (NJS_ARGB *)&radar_player_slot_color_table[0]);
                } else if (team == 2) {
                    copy_argb(&me->color, (NJS_ARGB *)&radar_player_slot_color_table[1]);
                } else {
                    copy_argb(&me->color, (NJS_ARGB *)&radar_player_slot_color_table[2]);
                }
            } else {
                copy_argb(&me->color, (NJS_ARGB *)(&radar_player_slot_color_table[p->get_entity_id()]));
            }
        } else {
            me->reset();
        }
    } else {
        me->reset();
    }
    e = &player_marker_records[1];
    for (i = 0; i < 4; i++) {
        if (i == local_client_id) {
            continue;
        }
        if (SHOW(this) == 0) {
            p = get_player_by_client_id(i);
            if (p != NULL && floor == p->get_floor() &&
                p->is_body_collision_inactive() == 0) {
                VecCopy((Vec *)e, &p->position);
                e->y = 10.0f;
                e->rot_y = p->rotation_y;
                e->id = i;
                copy_argb(&e->color, (NJS_ARGB *)(&radar_player_slot_color_table[p->get_entity_id()]));
            } else {
                e->reset();
            }
        } else if (team != 0) {
            p = get_player_by_client_id(i);
            if (p != NULL && floor == p->get_floor() &&
                team == p->pk_state.get_team() &&
                p->is_body_collision_inactive() == 0) {
                VecCopy((Vec *)e, &p->position);
                e->y = 10.0f;
                e->rot_y = p->rotation_y;
                e->id = i;
                if (team == 1) {
                    copy_argb(&e->color, (NJS_ARGB *)&radar_player_slot_color_table[0]);
                } else if (team == 2) {
                    copy_argb(&e->color, (NJS_ARGB *)&radar_player_slot_color_table[1]);
                } else {
                    copy_argb(&e->color, (NJS_ARGB *)&radar_player_slot_color_table[2]);
                }
            } else {
                e->reset();
            }
        } else {
            e->reset();
        }
        e++;
    }
    switch (zoom_state) {
    case 0:
        for (s32 j = 0; j < 4; j++) {
            player_marker_records[j].scale = 22.0f;
        }
        break;
    case 1:
        for (s32 j = 0; j < 4; j++) {
            player_marker_records[j].scale = 22.0f;
        }
        break;
    case 2:
        for (s32 j = 0; j < 4; j++) {
            player_marker_records[j].scale = 15.4f;
        }
        break;
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literals 10.0f and -10.0f,
// pooled in that order between the target-flag constant and gather_player_markers'
// 15.4f. gather_player_markers lifts a shown player's marker to 10.0f; this reconstruction drops
// a hidden one below the map. Name inferred.
void TRaderMapCore::set_marker_shown(s32 slot, s32 shown) {
    player_marker_records[slot].y = shown ? 10.0f : -10.0f;
}

// Dead-stripped from the DOL. The target-flag constant is a static const, emitted where its first user is compiled,
// and it sits between reveal_region_by_id's -1.0f and set_marker_shown's 10.0f:
// update_target is compiled much later, so a function compiled here read it first.
// This reconstruction sets the bit as update_target does. Name inferred.
void TRaderMapCore::set_target_flag() {
    view_flags |= radar_view_target_flag;
}

void update_radar_auto_discovery(TRaderMapCore *core, s32 unused, void *pos) {
    Vec v;
    RadarModelRegion *r;
    s32 i;
    if (RADAR_MODEL_REGION_MAP != NULL) {
        r = RADAR_MODEL_REGION_MAP->regions;
        for (i = 0; i < RADAR_MODEL_REGION_MAP->count; i++, r++) {
            if (!(r->flags & 2) && (r->flags & 1)) {
                if (r->flags & 4) {
                    v.x = r->x + r->model->m->b.x;
                    v.y = r->y + r->model->m->b.y;
                    v.z = r->z + r->model->m->b.z;
                } else {
                    v.x = r->x + r->model->m->a.x;
                    v.y = r->y + r->model->m->a.y;
                    v.z = r->z + r->model->m->a.z;
                }
                if (xz_distance_squared(&v, static_cast<Vec *>(pos)) < r->radius * r->radius) {
                    r->flags &= ~1;
                    r->fade = -1.0f;
                }
            }
        }
    }
}

NJS_POINT2 get_follow_marker_position(TRaderMapCore *core) {
    NJS_POINT2 p = { 0.0f, 0.0f };
    if (core->follow_marker >= 0) {
        p.x = core->player_marker_records[core->follow_marker].x;
        p.y = core->player_marker_records[core->follow_marker].z;
    }
    return p;
}

s32 TRaderMapCore::reveal_region_by_id(s16 id) {
    s32 i;
    if (RADAR_REGION_MAP == NULL) {
        return 0;
    }
    for (i = 0; i < RADAR_REGION_MAP->count; i++) {
        if (RADAR_REGION_MAP->regions[i].id == id && (RADAR_REGION_MAP->regions[i].flags & 1)) {
            RADAR_REGION_MAP->regions[i].flags &= ~1;
            RADAR_REGION_MAP->regions[i].fade = -1.0f;
            return 1;
        }
    }
    return 0;
}

s32 TRaderMapCore::block_region_by_id(s16 id) {
    s32 i;
    if (RADAR_REGION_MAP == NULL) {
        return 0;
    }
    for (i = 0; i < RADAR_REGION_MAP->count; i++) {
        if (RADAR_REGION_MAP->regions[i].id == id) {
            RADAR_REGION_MAP->regions[i].flags |= 2;
            return 1;
        }
    }
    return 0;
}

s32 minimap_render_dot(Vec *pos, s32 color, s16 kind, s32 flags) {
    const NJS_CAMERA *cam = &radar_map_view_state[0].camera;
    Vec v;
    u8 pad[0x10];
    RadarDot *d;
    if (radar_marker_count > 0x7F) {
        return 0;
    }
    if (!(flags & 1)) {
        v.x = cam->px;
        v.z = cam->pz;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    ((RadarDot *)&radar_marker_buffer)[radar_marker_count].x = pos->x;
    d = &((RadarDot *)&radar_marker_buffer)[radar_marker_count];
    d->z = pos->z;
    d->w = 1.0f;
    d->color = color;
    d->type = kind;
    d->c = 0;
    radar_marker_count++;
    return 1;
}

s32 minimap_render_gate(Vec *pos, u32 color, u16 rot, s16 kind, s32 flags) {
    const NJS_CAMERA *cam = &radar_map_view_state[0].camera;
    Vec v;
    u8 pad[0x10];
    if (radar_marker_count > 0x7F) {
        return 0;
    }
    if (!(flags & 1)) {
        v.x = cam->px;
        v.z = cam->pz;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    radar_marker_buffer[radar_marker_count].x = pos->x;
    radar_marker_buffer[radar_marker_count].z = pos->z;
    radar_marker_buffer[radar_marker_count].scale = 1.0f;
    radar_marker_buffer[radar_marker_count].color = color;
    radar_marker_buffer[radar_marker_count].kind = kind;
    radar_marker_buffer[radar_marker_count].rot = rot;
    radar_marker_count++;
    return 1;
}

s32 add_radar_scaled_marker(Vec *pos, s32 color, s16 kind, s32 flags, f32 scale) {
    const NJS_CAMERA *cam = &radar_map_view_state[0].camera;
    Vec v;
    u8 pad[0x10];
    RadarDot *d;
    if (radar_marker_count > 0x7F) {
        return 0;
    }
    if (!(flags & 1)) {
        v.x = cam->px;
        v.z = cam->pz;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    ((RadarDot *)&radar_marker_buffer)[radar_marker_count].x = pos->x;
    d = &((RadarDot *)&radar_marker_buffer)[radar_marker_count];
    d->z = pos->z;
    d->w = scale;
    d->color = color;
    d->type = kind;
    d->c = 0;
    radar_marker_count++;
    return 1;
}

s32 add_radar_scaled_gate(Vec *pos, u32 color, u16 rot, s16 kind, s32 flags, f32 scale) {
    const NJS_CAMERA *cam = &radar_map_view_state[0].camera;
    Vec v;
    if (radar_marker_count > 0x7F) {
        return 0;
    }
    if (!(flags & 1)) {
        v.x = cam->px;
        v.z = cam->pz;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    radar_marker_buffer[radar_marker_count].x = pos->x;
    radar_marker_buffer[radar_marker_count].z = pos->z;
    radar_marker_buffer[radar_marker_count].scale = scale;
    radar_marker_buffer[radar_marker_count].color = color;
    radar_marker_buffer[radar_marker_count].kind = kind;
    radar_marker_buffer[radar_marker_count].rot = rot;
    radar_marker_count++;
    return 1;
}

// Dead-stripped from the DOL: no code of it survives, only its literal 22.0f (pooled
// between pan_horizontal's and add_radar_scaled_gate's). It gives every player marker the scale
// that the constructor and gather_player_markers (map modes 0 and 1) store. Name inferred.
void TRaderMapCore::reset_marker_scale() {
    for (s32 i = 0; i < 4; i++) {
        player_marker_records[i].scale = 22.0f;
    }
}

void TRaderMapCore::pan_horizontal(f32 delta) {
    if (TRaderMapCore::view_mode == 1 || TRaderMapCore::view_mode == 2) {
        NJS_CAMERA *camera = &radar_map_view_state[1].camera;
        camera->px -= delta;
        switch (get_current_floor_area()) {
        case AREA_VOL_OPT:
        case AREA_DARK_FALZ:
        case AREA_OLGA_FLOW:
        case AREA_TOWER:
            return;
        default:
            if (camera->px < -6000.0f) {
                camera->px = -6000.0f;
            }
            if (camera->px > 6000.0f) {
                camera->px = 6000.0f;
            }
            break;
        }
    }
}

void TRaderMapCore::pan_vertical(f32 delta) {
    if (TRaderMapCore::view_mode == 1 || TRaderMapCore::view_mode == 2) {
        NJS_CAMERA *camera = &radar_map_view_state[1].camera;
        camera->pz -= delta;
        switch (get_current_floor_area()) {
        case AREA_VOL_OPT:
        case AREA_DARK_FALZ:
        case AREA_OLGA_FLOW:
        case AREA_TOWER:
            return;
        default:
            if (camera->pz < -6000.0f) {
                camera->pz = -6000.0f;
            }
            if (camera->pz > 6000.0f) {
                camera->pz = 6000.0f;
            }
            break;
        }
    }
}

void TRaderMapCore::open_free_map_view() {
    NJS_CAMERA *camera = &radar_map_view_state[1].camera;
    TRaderMapCore::view_mode = 1;
    {
        NJS_POINT2 p = get_follow_marker_position((TRaderMapCore *)TRaderMapCore::instance);
        camera->px = p.x;
        camera->pz = p.y;
    }
}

void TRaderMapCore::add_zoom_distance(f32 delta) {
    f32 py;
    if ((TRaderMapCore::view_mode == 1) || (TRaderMapCore::view_mode == 2)) {
        py = radar_map_view_state[1].camera.py + delta;
        radar_map_view_state[1].camera.py = py;
        if (py < radar_camera_height_min) {
            radar_map_view_state[1].camera.py = radar_camera_height_min;
        }
        if (radar_map_view_state[1].camera.py > radar_camera_height_max) {
            radar_map_view_state[1].camera.py = radar_camera_height_max;
        }
    }
}

void set_radar_marker_color(TRaderMapCore *unused, u32 color) {
    f32 rgba[4];
    rgba[0] = (f32)(color >> 24) / 255.0f;
    rgba[1] = (f32)(u8)(color >> 16) / 255.0f;
    rgba[2] = (f32)(u8)(color >> 8) / 255.0f;
    rgba[3] = (f32)(u8)color / 255.0f;
    set_constant_material((const NJS_ARGB *)rgba);
}

void TRaderMapCore::set_piece_flags(s32 piece_flags) {
    if (TRaderMapCore::floor_map_resource != 0) {
        RadarPieceMap* m = (RadarPieceMap*)TRaderMapCore::floor_map_resource;
        if (m->pieces != 0) {
            RadarPiece* piece = m->pieces;
            s32 i;
            for (i = 0; i < ((RadarPieceMap*)TRaderMapCore::floor_map_resource)->count; i++, piece++) {
                piece->flags |= piece_flags;
            }
        }
    }
}

void TRaderMapCore::create_heap(void) {
    s32 i;
    TRaderMapCore::map_heap = new THeap(0x1000, 0x20);
    for (i = 0; i < 0x12; i++) {
        ((s16* *)&TRaderMapCore::floor_discovery_table)[i] = NULL;
    }
}

void TRaderMapCore::free_heap() {
    delete TRaderMapCore::map_heap;
    TRaderMapCore::map_heap = 0;
}

void TRaderMapCore::free_map_data() {
    s32 i;
    for (i = 0x11; i >= 0; i--) {
        if (((s16* *)&TRaderMapCore::floor_discovery_table)[i] != NULL) {
            TRaderMapCore::map_heap->heap_free(((s16* *)&TRaderMapCore::floor_discovery_table)[i]);
            ((s16* *)&TRaderMapCore::floor_discovery_table)[i] = NULL;
        }
    }
}

s32 init_radar_floor_flags(s32 floor, RadarPieceInitMap *map) {
    s16 *saved = TRaderMapCore::floor_discovery_table[floor];
    s16 *p;
    RadarPieceInit *piece;
    s32 i;
    s32 j;
    if (saved != NULL) {
        for (i = 0, piece = map->pieces, p = saved; i < map->count; i++, piece++, p++) {
            piece->flags = *p;
        }
    } else {
        saved = (s16 *) TRaderMapCore::map_heap->heap_zalloc((u32) map->count * 2);
        if (saved != NULL) {
            TRaderMapCore::floor_discovery_table[floor] = saved;
        } else {
            return 0;
        }
        for (j = 0, piece = map->pieces; j < map->count; j++, piece++) {
            piece->flags |= 1;
        }
    }
    return 1;
}

s32 TRaderMapCore::save_floor_discovery(int floor, void *map_data) {
    RadarPieceMap *map = (RadarPieceMap *)map_data;
    s16* saved = ((s16* *)&TRaderMapCore::floor_discovery_table)[floor];
    s16* p;
    RadarPiece* piece;
    s32 i;
    if (saved != NULL) {
        for (i = 0, piece = map->pieces, p = saved; i < map->count; i++, piece++, p++) {
            *p = piece->flags;
        }
    } else {
        return 0;
    }
    return 1;
}

void TRaderMapCore::setup_overhead_projection(RadarMapViewState *view) {
    Vec up = { 0.0f, 0.0f, -1.0f };
    Vec eye;
    Vec at;
    eye.x = view->camera.px * radar_eye_scale;
    eye.y = view->camera.py * radar_eye_scale;
    eye.z = view->camera.pz * radar_eye_scale;
    at.x = view->camera.vx + eye.x;
    at.y = view->camera.vy + eye.y;
    at.z = view->camera.vz + eye.z;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x8000 - view->camera.roll);
    rotate_vector_by_matrix(0, &up, &up);
    pop_matrix();
    set_perspective_projection_from_fov((182.04445f * radar_overhead_projection_scale), 1.1333334f, 1.0f, 10000.0f);
    set_camera_look_at(&eye, &at, &up);
}
#pragma fp_contract on

void TRaderMapCore::set_view_scissor(int mode, const RadarScissorRect *rect) {
    u32 w;
    u32 h;
    u32 y;
    if (mode == 2) {
        w = 32.0f * (rect->x1 - rect->x0);
        h = 32.0f * (rect->y1 - rect->y0);
        y = 240.0f - 0.5f * h;
        GXSetScissor((u32)(320.0f - 0.5f * w), y, w, h);
    } else {
        GXSetScissor(0, 0, 0x280, 0x1E0);
    }
}

void TRaderMapCore::configure_viewport(const RadarViewportParameters* view) {
    f32 offset_x;
    f32 offset_y;
    GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    GXSetScissorBoxOffset(0, 0);
    offset_x = -(view->center_x - 320.0f);
    offset_y = -(view->center_y - 240.0f);
    set_screen_center(view->center_x, view->center_y);
    GXSetScissorBoxOffset(offset_x, offset_y);
}
#pragma fp_contract reset

void TRaderMapCore::show_radar() {
    if ((void *) (*(u8 * *)&TRaderMapCore::instance) != NULL) {
        ((TRaderMapCore *)(*(u8 * *)&TRaderMapCore::instance))->reset_counter();
        ((TObject *)(*(u8 * *)&TRaderMapCore::instance))->allow_rendering();
    }
}

void TRaderMapCore::hide_radar() {
    if ((void *) (*(u8 * *)&TRaderMapCore::instance) != NULL) {
        ((TRaderMapCore *)(*(u8 * *)&TRaderMapCore::instance))->reset_counter();
        ((TObject *)(*(u8 * *)&TRaderMapCore::instance))->disallow_rendering();
    }
}

void TRaderMapCore::reset_counter() { this->target_player = 0; }

s32 TRaderMapCore::should_show_map(void) {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (TLobby::is_ready() == 0)) {
        return 0;
    }
    return TTecCtrl::is_technique_ready();
}

s32 TRaderMapCore::is_active() {
    if ((void *) TRaderMapCore::instance != NULL) {
        if (((TRaderMapCore *)TRaderMapCore::instance)->m_flags & 0x10) {
            return 0;
        }
        return ((TRaderMapCore *)TRaderMapCore::instance)->is_render_admitted_default();
    }
    return 0;
}

s32 TRaderMapCore::is_render_admitted_default() {
    return is_render_admitted(TRaderMapCore::view_mode);
}
