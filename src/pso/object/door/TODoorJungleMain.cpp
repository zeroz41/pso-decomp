#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"

struct BmlResource;
struct NJS_TEXLIST;
struct AnimationMotion;

#include "pso/object/door/TODoorJungleMain.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/object/door/TODoorBase.h"


#include "pso/object/key/TOKeyJungleMain.h"

#include "pso/ui/TLevelSelect.h"

#include "pso/object/door/TODoorAncient01.h"

#include "pso/map/TObjMapCsn.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/object/base/ActorCollision.h"

#include "pso/player/TObjPlayer.h"


#include "pso/system/BmlResourceDescriptor.h"

#include "pso/system/SoundEffect.h"

#include "pso/player/TObjPlayer_801AF2F0.h"

#include "pso/object/base/TObjCharaHelpers.h"


#include "pso/unk/text_803D96A8.h"

#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/DebugFont.h"
#include "pso/unk/text_803D8F74.h"

#include "pso/render/GinjaMaterial.h"

#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/player/PlayerSlots.h"
#include "pso/quest/QuestStoryFlags.h"


struct Ids_8029B428 {
    s32 v[3];
};


const char *bm_o_jungle_doormain_model_names[5] = {
    "map_jungle01_light1.gj", "map_jungle01_light2.gj", "map_jungle01_light3.gj", "map_jungle01_tobira.gj", NULL,
};

const char *bm_o_jungle_doormain_motion_names[2] = {"tobira.njm", NULL};

BmlResourceDescriptor bm_o_jungle_doormain_resource_descriptor = {
    "bm_o_jungle_doormain.bml", bm_o_jungle_doormain_model_names, bm_o_jungle_doormain_motion_names, 4, 1,
};

CollisionBody TODoorJungleMain_collision_body_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 20.0f, 80.0f, 1, 0x10003},
};


// Story-flag ids of the three jungle switches (shared with TOKeyJungleMain).
const s32 TOKeyJungleMain::story_flags[3] = {0x46, 0x47, 0x48};

const char *TODoorJungleMain::class_name = "TODoorJungleMain";

s32 is_any_player_near(TObjBase *door);


#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off


BmlResource *TODoorJungleMain::bml_resource;

NJS_TEXLIST *door_jungle_main_gvm_texture;

TODoorJungleMain::TODoorJungleMain(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    motion = (AnimationMotion *)get_bml_motion(TODoorJungleMain::bml_resource, 0);
    animation_step = 1.0f;
    animation_end_frame = 0.0f;
    init_collision_body_parts(this, TODoorJungleMain_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    view_range = 800.0f;
    model_radius = 120.0f;
    switch_count = 0;
    smoke_timer = 0;
    ObjectSetData csn_data;
    __memcpy(&csn_data, set_data, sizeof(csn_data));
    csn_data.scale.x = 160.0f;
    csn_data.scale.y = 100.0f;
    csn_data.scale.z = 40.0f;
    csn_data.set_params[0] = 2;
    map_csn = TObjMapCsn::create(&csn_data);
}

TODoorJungleMain::~TODoorJungleMain() {
    if (map_csn != NULL) {
        map_csn->queue_destruction();
        map_csn = NULL;
    }
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


void TODoorJungleMain::run_task() {
    GC_Mtx mtx;
    s32 flag;
    f32 t;

    this->update_door_switch_state();
    if (this->door_flags & 1) {
        flag = 0;
        animation_end_frame += this->animation_step;
        t = animation_end_frame;
        if ((f32)(u32)(motion->frameCount - 1) - 70.0f < t &&
            t < (f32)(u32)(motion->frameCount - 1)) {
            set_indexed_flags(0, 8);
            if (map_csn != NULL) {
                map_csn->queue_destruction();
                map_csn = NULL;
            }
        } else {
            flag = 1;
        }
        if (animation_end_frame > (f32)(u32)(motion->frameCount - 1)) {
            flag = 0;
            animation_end_frame = (f32)(u32)(motion->frameCount - 1);
        } else {
            play_persistent_sound(0x43220, this, &this->position, 0, 0);
        }
        if (flag != 0) {
            if (++smoke_timer % 30 == 0) {
                Vec a = {40.0f, 0.0f, 0.0f};
                Vec b = {-40.0f, 0.0f, 0.0f};
                set_matrix_identity((u8 *)&mtx);
                translate_matrix_vec3((u8 *)&mtx, (u8 *)&this->position);
                rotate_matrix_y(mtx, this->rotation_y);
                matrix_mult_vec(mtx, &a, &a);
                matrix_mult_vec(mtx, &b, &b);
                spawn_particle_effect_with_flags(&a, 0x229, 0x800);
                spawn_particle_effect_with_flags(&b, 0x229, 0x800);
            }
        }
        minimap_render_gate(&this->position, 0xFF00FF00, this->rotation_y, 0, 0);
    } else {
        minimap_render_gate(&this->position, 0xFFFF0000, this->rotation_y, 0, 0);
        clear_player_status_flag(0, 8);
    }
}

void TODoorJungleMain::update_door_switch_state() {
    s16 saved_state;
    s32 lvl;
    s32 prev;
    s32 i;

    if (!(door_flags & 1)) {
        lvl = game_difficulty_selection;
        prev = switch_count;
        switch_count = 0;
        for (i = 0; i < 3; i++) {
            if (get_story_flag_in_bank(lvl, TOKeyJungleMain::story_flags[i]) != 0) {
                switch_count++;
            }
        }
        if (switch_count > 0 && switch_count != prev) {
            play_sound_effect(0x4C123, &position, 0, 0);
        }
        if (switch_count == 3 && is_any_player_near(this) != 0) {
            door_flags |= 1;
        } else {
            door_flags &= ~1;
        }
        if ((door_flags & 1) && access_object_saved_state(&saved_state, 1) == 1) {
            saved_state = 1;
            send_object_state_update(&saved_state);
        }
    }
}

void TODoorJungleMain::render() {
    Ids_8029B428 ids = {{2, 1, 0}};
    s32 i;
    if (update_object_view_visibility(view_range, model_radius) == 1) {
        TObjFish::set_global_param(door_jungle_main_gvm_texture);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (door_flags & 1) {
            draw_ginja_model_with_motion(get_bml_model(TODoorJungleMain::bml_resource, 3), motion, animation_end_frame);
        } else {
            draw_ginja_object(get_bml_model(TODoorJungleMain::bml_resource, 3));
            for (i = 0; i < 3 - switch_count; i++) {
                draw_ginja_object(get_bml_model(TODoorJungleMain::bml_resource, ids.v[i]));
            }
        }
        pop_matrix();
    }
}

void TODoorJungleMain::load_resources() {
    saddr created;
    created = (saddr)new BmlResource(0x1, &bm_o_jungle_doormain_resource_descriptor, 0, 0, NULL);
    TODoorJungleMain::bml_resource = (BmlResource *)created;
    door_jungle_main_gvm_texture = LoadPvmFileTls("o_jungle_doormain.gvm");
}

void TODoorJungleMain::free_static_resources() {
    if (door_jungle_main_gvm_texture != NULL) {
        release_texture_list(door_jungle_main_gvm_texture);
        safe_free(door_jungle_main_gvm_texture);
        door_jungle_main_gvm_texture = NULL;
    }
    if (TODoorJungleMain::bml_resource != NULL) {
        delete (BmlResource *)TODoorJungleMain::bml_resource;
        TODoorJungleMain::bml_resource = NULL;
    }
}

void *TODoorJungleMain::create(void *set_data) {
    return new TODoorJungleMain(tl_05, set_data);
}

void init_jungle_key_slots() {
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            clear_story_flag_in_bank(i, TOKeyJungleMain::story_flags[j]);
        }
    }
}

void unload_jungle_key_slots() { init_jungle_key_slots(); }


s32 is_any_player_near(TObjBase *door) {
    f32 max_dist_sq;
    s32 player_floor;
    s32 client;
    s32 current_floor;
    TObjPlayer *player;
    max_dist_sq = 2500.0f;
    for (client = 0; client < 4; client++) {
        player = get_player_by_client_id(client);
        if (player != NULL) {
            player_floor = player->get_floor();
            current_floor = get_current_floor();
            if (current_floor == player_floor && xz_distance_squared(&player->position, &door->position) < max_dist_sq) {
                return 1;
            }
        }
    }
    return 0;
}


void TODoorJungleMain::apply_saved_state(s16 *state, s32 live) {
    if ((state != NULL) && ((s16) *state == 1)) {
        this->door_flags = (s32) (this->door_flags | 1);
        if (live == 0) {
            this->animation_end_frame = (f32) (this->motion->frameCount - 1);
            set_indexed_flags(0, 8);
            if (map_csn != NULL) {
                map_csn->queue_destruction();
                map_csn = NULL;
            }
        }
    }
}

s32 TODoorJungleMain::update_object_view_visibility(f32 far_dist, f32 near_dist) {
    if (xz_distance_squared(&this->position, &camera_ctrl_instance->pos) < (near_dist * near_dist)) {
        return 1;
    }
    return TObjBase::update_object_view_visibility(far_dist, near_dist);
}

