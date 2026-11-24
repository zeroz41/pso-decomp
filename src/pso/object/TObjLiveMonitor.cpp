#include "pso/system/SubtractiveRng.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/GinjaMaterial.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/object/TObjLiveMonitorSmall.h"
#include "pso/unk/text_8020BFE4.h"
#include "pso/object/TObjLiveMonitor.h"
#include "types.h"
#include <string.h>
#include "pso/object/door/TObjDoorJung.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TObjLiveCameraCtrl.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/TObjControl.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TObjLiveCamera.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/camera/TLiveCameraView.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/render/render_util.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

#pragma defer_codegen on

BmlResource *live_monitor_shared_resource;
s32 TObjLiveCameraCtrl::next_slot;
TObjLiveCameraCtrl *TObjLiveCameraCtrl::instances[1];
extern "C" {
s32 live_monitor_small_spawned_flag;
u8 TObjLiveMonitorSmall__fish_spawned_flag;
const char *bm_obj_boss8_monitor_model_names[4] = {
    "fe_obj_monitor_sho.gj",
    "fe_obj_monitor_dai.gj",
    "fe_obj_monitor_dai_4bunkatu.gj",
    NULL,
};
const char *bm_obj_boss8_monitor_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_boss8_monitor_resource_descriptor = {
    "bm_obj_boss8_monitor.bml", bm_obj_boss8_monitor_model_names, bm_obj_boss8_monitor_motion_names, 3, 0,
};
const char *TObjLiveCameraCtrl__class_name = "TObjLiveCameraCtrl";
const char *TObjLiveCamera__class_name = "TObjLiveCamera";
const char *TObjLiveMonitor__name = "TObjLiveMonitor";
const char *TObjLiveMonitorSmall__name = "TObjLiveMonitorSmall";
}
// The id each camera slot passes to its TLiveCameraView.
const s32 live_camera_view_ids[2] = { 0xF44E8, 0xF44E9 };

extern "C" {
s32 is_split_screen();
extern void *tl_05;
s32 get_current_floor();
extern TObject *tl_particlemodel;
}

void reset_live_camera_ctrl_globals(void) {
    TObjLiveCameraCtrl::next_slot = 0;
    memset(TObjLiveCameraCtrl::instances, 0, sizeof(TObjLiveCameraCtrl::instances));
}

void release_live_camera_ctrl_globals(void) {}

s32 TObjLiveCameraCtrl::is_enabled() { return enabled; }

TObjLiveCameraCtrl *TObjLiveCameraCtrl::get_instance(s32 slot) {
    if (slot < 0) {
        return NULL;
    }
    if (slot > 1) {
        return NULL;
    }
    return instances[slot];
}

TObjLiveCameraCtrl::TObjLiveCameraCtrl(TObject *parent) : TObject(parent) {
    s32 n;
    m_name = TObjLiveCameraCtrl__class_name;
    n = next_slot;
    instances[n] = this;
    next_slot = n + 1;
    slot = n;
    shot = SHOT_NONE;
    shot_frames = 0;
    enabled = 1;
    target_id = 0xFFFF;
    orbit_angle = 0;
    orbit_speed = 0;
    height_offset = 0.0f;
    eye.x = 0.0f;
    eye.y = 0.0f;
    eye.z = 0.0f;
    target.x = 0.0f;
    target.y = 0.0f;
    target.z = 1.0f;
    subtractive_rng_seed(&rng, 0);
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        shot = SHOT_OPENING;
        shot_frames = -1;
        eye.x = 0.0f;
        eye.y = 155.0f;
        eye.z = -710.0f;
        target.x = 0.0f;
        target.y = 155.0f;
        target.z = -720.0f;
    }
    view = new TLiveCameraView(tl_particlemodel, live_camera_view_ids[slot], &eye, &target, 0.5f);
}

TObjLiveCameraCtrl::~TObjLiveCameraCtrl() {
    instances[slot] = NULL;
    if (view != NULL) view->queue_destruction();
}
void TObjLiveCameraCtrl::run_task() {
    update_toggle_state();
    update_live_camera();
    choose_next_camera_shot();
    if (view != NULL) {
        view->set_view(&eye, &target);
    }
}


void TObjLiveCameraCtrl::update_toggle_state() {
    if (slot >= TBoss8Dragon::get_live_monitor_count()) {
        if (enabled == 1) {
            if (view != NULL) {
                view->disable();
            }
            enabled = 0;
        }
    } else if (enabled == 0) {
        if (view != NULL) {
            view->enable();
        }
        enabled = 1;
    }
}

#pragma push
#pragma fp_contract on
void TObjLiveCameraCtrl::update_live_camera() {
    TBoss8Dragon *boss;
    TObjPlayer *player;
    TObjBase *enemy;
    switch (shot) {
    case SHOT_PLAYER_ORBIT:
        player = get_player_by_client_id(target_id);
        if (player != NULL) {
            eye.x = 30.0f * sin_table_lookup(orbit_angle) + player->position.x;
            eye.y = player->position.y + height_offset;
            eye.z = 30.0f * cos_table_lookup(orbit_angle) + player->position.z;
            target.x = player->position.x;
            target.y = player->position.y + height_offset;
            target.z = player->position.z;
            orbit_angle += orbit_speed;
        }
        return;
    case SHOT_BEHIND_PLAYER:
        player = get_player_by_client_id(target_id);
        if (player != NULL) {
            eye.x = 45.42f * sin_table_lookup(orbit_angle) + player->position.x;
            eye.y = 25.43f + player->position.y;
            eye.z = 45.42f * cos_table_lookup(orbit_angle) + player->position.z;
            target.x = -5.0f * sin_table_lookup(orbit_angle) + player->position.x;
            target.y = 19.8f + player->position.y;
            target.z = -5.0f * cos_table_lookup(orbit_angle) + player->position.z;
            turn_orbit_toward(player->rotation_y - 0x8000);
            return;
        }
        break;
    case SHOT_BEHIND_BOSS:
        enemy = (TObjBase *)get_enemy_entity(target_id);
        if (enemy != NULL && enemy->position.y >= 0.0f) {
            eye.x = 50.0f * sin_table_lookup(orbit_angle) + enemy->position.x;
            eye.y = 120.0f + enemy->position.y;
            eye.z = 50.0f * cos_table_lookup(orbit_angle) + enemy->position.z;
            target.x = -120.0f * sin_table_lookup(orbit_angle) + enemy->position.x;
            target.y = 20.0f + enemy->position.y;
            target.z = -120.0f * cos_table_lookup(orbit_angle) + enemy->position.z;
            turn_orbit_toward(enemy->rotation_y - 0x8000);
            return;
        }
        break;
    case SHOT_OPENING:
        boss = TBoss8Dragon::get_part(0);
        if (boss != NULL && boss->has_appeared() != 0) {
            shot_frames = 0;
        }
        break;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on
void TObjLiveCameraCtrl::choose_next_camera_shot() {
    f32 r;
    TObjBase *subject;
    if (shot_frames < 0) {
        return;
    }
    if (--shot_frames > 0) {
        return;
    }
    r = calc_random_ratio__10TObjPlayerFv(&rng);
    if (r < 0.3f) {
        shot = SHOT_PLAYER_ORBIT;
    } else if (r < 0.4f) {
        shot = SHOT_BEHIND_PLAYER;
    } else if (r < 0.6f) {
        shot = SHOT_BEHIND_BOSS;
    } else {
        shot = SHOT_ARENA;
    }
    switch (shot) {
    case SHOT_NONE:
        break;
    case SHOT_PLAYER_ORBIT:
        shot_frames = 180.0f * calc_random_ratio__10TObjPlayerFv(&rng) + 180.0f;
        target_id = get_player_target();
        orbit_angle = 65535.0f * calc_random_ratio__10TObjPlayerFv(&rng);
        orbit_speed = 2.0f * (80.0f * (calc_random_ratio__10TObjPlayerFv(&rng) - 0.5f));
        height_offset = 15.0f * calc_random_ratio__10TObjPlayerFv(&rng) + 5.0f;
        break;
    case SHOT_BEHIND_PLAYER:
        shot_frames = 180.0f * calc_random_ratio__10TObjPlayerFv(&rng) + 180.0f;
        target_id = get_player_target();
        subject = get_player_by_client_id(target_id);
        if (subject != NULL) {
            orbit_angle = subject->rotation_y - 0x8000;
        }
        break;
    case SHOT_BEHIND_BOSS:
        shot_frames = 150.0f * calc_random_ratio__10TObjPlayerFv(&rng) + 150.0f;
        target_id = get_boss_target();
        subject = (TObjBase *)get_enemy_entity(target_id);
        if (subject != NULL) {
            orbit_angle = subject->rotation_y - 0x8000;
        }
        break;
    case SHOT_ARENA:
        shot_frames = 120.0f * calc_random_ratio__10TObjPlayerFv(&rng) + 120.0f;
        orbit_angle = 65535.0f * calc_random_ratio__10TObjPlayerFv(&rng);
        eye.x = 360.0f * sin_table_lookup(orbit_angle);
        eye.y = 250.0f;
        eye.z = 360.0f * cos_table_lookup(orbit_angle);
        target.x = 0.0f;
        target.y = 0.0f;
        target.z = 0.0f;
        break;
    }
}

#pragma pop

void TObjLiveCameraCtrl::turn_orbit_toward(int angle) {
    f32 diff = angle_diff_s16(orbit_angle, angle);
    s32 wanted = (diff *= 0.05f);
    s32 step;
    if (wanted < -0x280) {
        step = -0x280;
    } else {
        step = 0x280;
        if (wanted < 0x280) {
            step = wanted;
        }
    }
    orbit_angle += step;
}

u16 TObjLiveCameraCtrl::get_player_target() { return local_client_id; }

u16 TObjLiveCameraCtrl::get_boss_target() { return TBoss8Dragon::get_part_entity_id(0); }

void TObjLiveCameraCtrl::load_view_texture() {
    if (view != NULL) {
        view->bind_texture();
    }
}

void fn_8030B7B8(void) {  }

void fn_8030B7B4(void) {  }

void *TObjLiveCamera::create(void *set_data) {
    return new TObjLiveCamera((TObject *)tl_05, set_data);
}

TObjLiveCamera::TObjLiveCamera(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjLiveCamera__class_name;
    apply_object_set_data(set_data);
}

TObjLiveCamera::~TObjLiveCamera() {}

void TObjLiveCamera::run_task() {  }

void TObjLiveCamera::render() {  }

void TObjLiveCamera::load_static_resource() {
    live_monitor_shared_resource = new BmlResource(5, &bm_obj_boss8_monitor_resource_descriptor, 0, 0, NULL);
}

void TObjLiveCamera::free_static_resource() { delete live_monitor_shared_resource; }

void *TObjLiveMonitor::create(TObject *parent) {
    return new TObjLiveMonitor(parent);
}

TObjLiveMonitor::TObjLiveMonitor(TObject *parent) : TObject(parent) {
    m_name = TObjLiveMonitor__name;
    model = get_bml_model(live_monitor_shared_resource, 1);
    texlist = get_bml_texlist(live_monitor_shared_resource, 0);
    screen = 5;
    screen_timer = 0;
}

TObjLiveMonitor::~TObjLiveMonitor() {}


void TObjLiveMonitor::run_task() { choose_next_screen(); }

void TObjLiveMonitor::render() {
    TObjLiveCameraCtrl *camera = TObjLiveCameraCtrl::get_instance(0);
    if (camera != NULL && camera->is_enabled() != 0) {
        camera->load_view_texture();
    } else if (is_split_screen() == 0) {
        TObjPlayer::load_capture_texture();
    } else {
        render_live_monitor_screen();
    }
    push_matrix();
    draw_ginja_object(model);
    pop_matrix();
}

#pragma push
#pragma fp_contract on
void TObjLiveMonitor::choose_next_screen() {
    f32 r;
    if (this->screen_timer >= 0) {
        if (--this->screen_timer <= 0) {
            if (is_split_screen() != 0) {
                this->screen = (u32)(3.0f * (3.0517578e-05f * (f32)rand()) + 1.0f);
            } else {
                this->screen = (u32)(5.0f * (3.0517578e-05f * (f32)rand()));
            }
            r = 3.0517578e-05f * (f32)rand();
            this->screen_timer = (s32)(300.0f * r + 300.0f);
        }
    }
}

#pragma pop

int TObjLiveMonitor::render_live_monitor_screen() {
    TObjLiveCameraCtrl *camera;
    s32 slot;
    switch (screen) {
    case 0:
        camera = TObjLiveCameraCtrl::get_instance(screen);
        if (camera != NULL && camera->is_enabled() != 0) {
            camera->load_view_texture();
        } else if (is_split_screen() == 0) {
            TObjPlayer::load_capture_texture();
        } else {
            set_texlist(texlist);
        }
        slot = 0;
        break;
    case 1:
        set_texlist(texlist);
        slot = 2 - ((u32)screen_timer / 3 % 3);
        break;
    case 2:
        set_texlist(texlist);
        slot = 2 - ((u32)screen_timer / 90 % 3);
        slot += 3;
        break;
    case 3:
        set_texlist(texlist);
        slot = 4 - ((u32)screen_timer / 3 % 5);
        slot += 6;
        break;
    case 4:
        if (is_split_screen() == 0) {
            TObjPlayer::load_capture_texture();
        }
        slot = 0;
        break;
    default:
        return screen;
    }
    set_ginja_model_texture_slot(model->model, static_cast<u16>(slot));
    push_matrix();
    ::draw_ginja_model(model->model);
    return pop_matrix();
}

s32 TObjLiveMonitorSmall::spawn_all(TObject *parent) {
    NJS_OBJECT *node;

    if ((s8) TObjLiveMonitorSmall__fish_spawned_flag == 0) {
        live_monitor_small_spawned_flag = 1;
        TObjLiveMonitorSmall__fish_spawned_flag = 1;
    }
    node = get_bml_model(live_monitor_shared_resource, 0)->child;
    while (node != NULL) {
        if (live_monitor_small_spawned_flag != 0) {
            new TObjLiveMonitorSmall(parent, node);
        }
        node = node->sibling;
    }
    return 0;
}

TObjLiveMonitorSmall::TObjLiveMonitorSmall(TObject *parent, NJS_OBJECT *model) : TObjLiveMonitor(parent) {
    m_name = TObjLiveMonitorSmall__name;
    this->model = model;
}

TObjLiveMonitorSmall::~TObjLiveMonitorSmall() {}

void TObjLiveMonitorSmall::run_task() { choose_next_screen(); }

void TObjLiveMonitorSmall::render() { this->render_live_monitor_screen(); }
