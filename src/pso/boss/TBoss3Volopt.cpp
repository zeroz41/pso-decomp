#include "pso/protocol/protocol_types.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/PadRumble.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss3VoloptCore.h"
#include "pso/boss/TBoss3VoloptCtrl.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/boss/TBoss3VoloptMonitor.h"
#include "pso/boss/TBoss3VoloptP01.h"
#include "pso/boss/TBoss3VoloptP02.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TUnk_80483B88.h"
#include "pso/boss/TUnk_804848A0.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/math/AngleLookup.h"
#include "pso/misc/CameraHelpers.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/misc/TCameraCtrl_8006A03C.h"
#include "pso/misc/TFogCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/object/TObjVoloptCage.h"
#include "pso/object/TObjVoloptPillar.h"
#include "pso/object/TObjVoloptShutter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/TMainTask.h"
#pragma readonly_strings on

// Camera offsets for the follow camera, from TLobby's shared parameter tables.
struct VoloptCameraParams {
    f32 target_z;
    f32 target_y;
    f32 position_z;
    f32 position_y;
    u8 pad_10[0x8];
    s32 enabled;
};

// The model node the shutter models hang off.
struct VoloptShutterNode {
    u32 evalflags;
    void *model;
    u8 pad_8[0x24];
    VoloptShutterNode *child;
};

extern "C" {
void *find_entity_by_id(u16 id);
f32 calc_boss4_scale__10TObjPlayerFi(TObject *actor);
f32 fabs_float(f32 x);
f32 newton_sqrtf(f32 x);
s32 get_current_floor(void);
s16 get_actor_hp(u8 *p);
s32 play_persistent_sound(u32 id, TObject *source, f32 *pos, s32, s32);
int rand(void);
u16 find_nearest_visible_player(TObject *self, s32 flags, f32 range);
s32 is_local_client_floor_leader();
void request_follow_camera_offsets(Vec *position, Vec *target, s32 id, f32 blend);
u16 get_entity_id(void *object);
void obj_setFlags30(void *object, s32 flags);
void TLobby__sub_8001FE7C(void *resource, s32 flags);
void *load_resource_from_descriptor(void *resource, s32 kind, BmlResourceDescriptor *descriptor, s32, s32, s32);
u16 TObjRoomId__sub_801A1DB8(u16 id);
void TObjPlayer__sub_801BA42C(void);
extern s32 lbl_805D2ECC;
extern s32 TODoorVoShip__class_name;
extern s32 local_client_id;
extern s32 lbl_805D5868;
extern s32 lbl_805D586C;
extern s32 lbl_805D5870;
}
void reset_status_effect_row(u8 *row);
void reset_cameras_to_actor(void *actor, s32 flags);

static const char *bm_boss3_volopt_model_names[] = {
    "fe_obj_hira_kage.nj",
    "fe_obj_vo_mo_dai_aka.gj",
    "fe_obj_vo_mo_dai_ao.gj",
    "fe_obj_vo_mo_dai_hakai.gj",
    "fe_obj_vo_mo_sho01_aka.gj",
    "fe_obj_vo_mo_sho01_ao.gj",
    "fe_obj_vo_mo_sho01_hakai.gj",
    "fe_obj_vo_mo_sho02_aka.gj",
    "fe_obj_vo_mo_sho02_ao.gj",
    "fe_obj_vo_mo_sho02_hakai.gj",
    "fe_obj_vo_mo_sho03_aka.gj",
    "fe_obj_vo_mo_sho03_ao.gj",
    "fe_obj_vo_mo_sho03_hakai.gj",
    "fe_obj_vo_futa_moto.nj",
    "fe_obj_vo_tenjo_hahen01.nj",
    "fe_obj_vo_tenjo_hahen02.nj",
    "fs_obj_hiraishin_a.nj",
    "me5p01_y_all.nj",
    "me5p02_y_cage.nj",
    "me5p02_y_all.nj",
    "me5p02_y_all_parts.nj",
    "me5p02_y_broken01.nj",
    "me5p02_y_missile.nj",
    "me5p02_y_pillar.nj",
    "me5_y_all.nj",
    NULL,
};

static const char *bm_boss3_volopt_motion_names[] = {
    "attack_me5p01_y_all.njm",
    "b_attack_me5p02_y_all.njm",
    "damage_me5_y_all.njm",
    "damage_me5p01_y_all.njm",
    "damage_me5p02_y_all.njm",
    "death_me5p02_y_all.njm",
    "fs_obj_hiraishin_a.njm",
    "fs_obj_hiraishin_b.njm",
    "fs_obj_hiraishin_c.njm",
    "f_attack_me5p02_y_all.njm",
    "l_attack_me5p02_y_all.njm",
    "r_attack_me5p02_y_all.njm",
    "start_me5p01_y_all.njm",
    "start_me5p02_y_all.njm",
    "wait_me5_y_all.njm",
    "wait_me5p01_y_all.njm",
    "wait_me5p02_y_all.njm",
    NULL,
};

static BmlResourceDescriptor bm_boss3_volopt_resource_descriptor = {
    "bm_boss3_volopt.bml", bm_boss3_volopt_model_names, bm_boss3_volopt_motion_names, 25, 17,
};

static const char *bm_boss3_volopt_ap_model_names[] = {
    "fe_obj_hira_kage.nj",
    "fe_obj_vo_mo_dai_aka.gj",
    "fe_obj_vo_mo_dai_ao.gj",
    "fe_obj_vo_mo_dai_hakai.gj",
    "fe_obj_vo_mo_sho01_aka.gj",
    "fe_obj_vo_mo_sho01_ao.gj",
    "fe_obj_vo_mo_sho01_hakai.gj",
    "fe_obj_vo_mo_sho02_aka.gj",
    "fe_obj_vo_mo_sho02_ao.gj",
    "fe_obj_vo_mo_sho02_hakai.gj",
    "fe_obj_vo_mo_sho03_aka.gj",
    "fe_obj_vo_mo_sho03_ao.gj",
    "fe_obj_vo_mo_sho03_hakai.gj",
    "fe_obj_vo_futa_moto.nj",
    "fe_obj_vo_tenjo_hahen01.nj",
    "fe_obj_vo_tenjo_hahen02.nj",
    "fs_obj_hiraishin_a.nj",
    "me5p01_y_all.nj",
    "me5p02_y_cage.nj",
    "me5p02_y_all.nj",
    "me5p02_y_all_parts.nj",
    "me5p02_y_broken01.nj",
    "me5p02_y_missile.nj",
    "me5p02_y_pillar.nj",
    "me5_y_all.nj",
    NULL,
};

static const char *bm_boss3_volopt_ap_motion_names[] = {
    "attack_me5p01_y_all.njm",
    "b_attack_me5p02_y_all.njm",
    "damage_me5_y_all.njm",
    "damage_me5p01_y_all.njm",
    "damage_me5p02_y_all.njm",
    "death_me5p02_y_all.njm",
    "fs_obj_hiraishin_a.njm",
    "fs_obj_hiraishin_b.njm",
    "fs_obj_hiraishin_c.njm",
    "f_attack_me5p02_y_all.njm",
    "l_attack_me5p02_y_all.njm",
    "r_attack_me5p02_y_all.njm",
    "start_me5p01_y_all.njm",
    "start_me5p02_y_all.njm",
    "wait_me5_y_all.njm",
    "wait_me5p01_y_all.njm",
    "wait_me5p02_y_all.njm",
    NULL,
};

static BmlResourceDescriptor bm_boss3_volopt_ap_resource_descriptor = {
    "bm_boss3_volopt_ap.bml", bm_boss3_volopt_ap_model_names, bm_boss3_volopt_ap_motion_names, 25, 17,
};

static u16 volopt_target_entity_ids[6] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
static Vec boss3_volopt_intro_camera_poses[4] = {
    {0.0f, 20.0f, -4890.0f},
    {0.0f, 20.0f, -6000.0f},
    {0.0f, 20.0f, -4890.0f},
    {0.0f, 20.0f, -6000.0f},
};
static Vec volopt_phase2_player_positions[4] = {
    {0.0f, 0.0f, -5090.0f},
    {0.0f, 0.0f, -4910.0f},
    {-90.0f, 0.0f, -5000.0f},
    {90.0f, 0.0f, -5000.0f},
};
static s32 volopt_phase2_player_angles[4] = {0, 0x8000, 0x4000, 0xC000};

u16 volopt_cage_id = 0xFFFF;
s32 volopt_cage_group = 0xFFFF;
u16 volopt_p02_id = 0xFFFF;
u16 volopt_hiraisin_id = 0xFFFF;
u16 volopt_core_id = 0xFFFF;
static const char *TBoss3Volopt_name = "TBoss3Volopt";

BmlResource *boss3_volopt_resources;
s32 vol_opt_active_hit_zone;
u16 boss3_volopt_monitor_base_actor_id;
static s32 lbl_805D4C1C;
static Vec *volopt_camera_focus;
s32 volopt_death_active;
s32 volopt_breakup_flag;
s32 volopt_resources_loaded;
static VoloptCameraParams *volopt_phase1_camera;
static VoloptCameraParams *volopt_phase2_camera;
static VoloptCameraParams *volopt_cage_camera;
s32 boss3_volopt_cage_flag;
static s32 volopt_v2_mode;
s32 volopt_p01_tech;
static s32 volopt_candidate_count;

Vec boss3_volopt_spawn_pos;
static s8 volopt_p01_order[6];
static Vec boss3_volopt_seq2_camera_position;
static Vec boss3_volopt_seq2_camera_target;
static Vec boss3_volopt_seq4_camera_position;
static Vec boss3_volopt_seq4_camera_target;
TObjPlayer *TBoss3Volopt::candidate_players[5];

extern "C" TBoss3VoloptCore *fn_8003F468(TBoss3Volopt *parent, u16 id, s32 group) {
    return new TBoss3VoloptCore(parent, id, group);
}

BOOL TBoss3VoloptCore::is_mode_0() {
    return mode == 0;
}

BOOL TBoss3VoloptP02::can_action_wait() {
    return !(m_388 & 0x80000);
}

BOOL TBoss3VoloptP02::can_action() {
    return !(m_388 & 0x20000);
}

BOOL TBoss3VoloptP02::can_trigger() {
    return !(m_388 & 0x40000);
}

BOOL TBoss3VoloptP02::can_set_motion() {
    return !(m_388 & 0x10000);
}

BOOL TBoss3VoloptP02::is_mode_0() {
    return mode == 0;
}

int TBoss3VoloptP01::is_broken() {
    return (m_388 >> 18) & 1;
}

void TObject::pause_update() {
    m_flags |= PAUSE_UPDATE;
}

BOOL TUnk_804B6C24::check_value_equals(s32 name) {
    return (s32)m_name == name;
}

void clear_volopt_cage_flag() {
    boss3_volopt_cage_flag = 0;
}

u16 TBoss3Volopt::get_part_id(s32 index) {
    return entity_id + index;
}

s32 TBoss3Volopt::get_part_group(s32 index) {
    return group_index + index;
}

BOOL TBoss3Volopt::is_v2_mode() {
    return volopt_v2_mode;
}

void TBoss3VoloptAttackPacket::init() {
    command = 0x84;
    size = 4;
}

void TBoss3VoloptAttackPacket::send() {
    swap();
    send_subcommand((u8 *)this);
}

void TBoss3VoloptTargetsPacket::init() {
    command = 0x16;
    size = 3;
}

void TBoss3VoloptTargetsPacket::send() {
    swap();
    send_subcommand((u8 *)this);
}

void TBoss3VoloptActionPacket::init() {
    command = 0x15;
    size = 3;
}

void TBoss3VoloptActionPacket::send() {
    swap();
    send_subcommand((u8 *)this);
}

void TBoss3VoloptActionPacket::swap() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)&action);
    bswap_16(&target_id);
    bswap_16((u16 *)&param);
    bswap_16((u16 *)&param2);
}

void TBoss3VoloptTargetsPacket::swap() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)&count);
}

void TBoss3VoloptPositionPacket::init() {
    command = 0x17;
    size = 5;
}

void TBoss3VoloptPositionPacket::send() {
    swap();
    send_subcommand((u8 *)this);
}

void TBoss3VoloptPositionPacket::swap() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)&rotation_y);
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
}

void TBoss3VoloptAttackPacket::swap() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)&tech);
    bswap_16((u16 *)&count);
    bswap_16((u16 *)&reserved);
}

void VoloptPhase2Message::swap() {
    s32 i;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)&mode);
    for (i = 0; i < 7; i++) {
        bswap_16((u16 *)&delays[i]);
    }
}

s32 TBoss3Volopt::get_field_3e0() {
    return m_3e0;
}

void TBoss3Volopt::reset_photon_effect() {
    ((TObjPlayer *)this)->reset_photon_effect();
}

TBoss3Volopt::TBoss3Volopt(void *set_data) : TObjEnemyCustom(tl_04) {
    m_name = TBoss3Volopt_name;
    apply_set_data(set_data);
    reset_photon_effect();
    move_to_arena(0);
    VecCopy((Vec *)position, VecCopy((Vec *)&m_2fc, &boss3_volopt_spawn_pos));
    actorFlags |= 0x06040000;
    volopt_cage_id = get_part_id(0x20);
    volopt_cage_group = get_part_group(0x20);
    next_action = 0;
    mode = 0;
    m_3bc = 0;
    TBoss4DarkFalz::dispatch_by_main_phase(0x29);
    volopt_camera_focus = NULL;
    volopt_p01_tech = -1;
    clear_lobby_object_state();
}

TBoss3Volopt::~TBoss3Volopt() {
    s32 i;
    if (is_death_active() != 0) {
        send_entity_set_flags();
    }
    vol_opt_active_hit_zone = 0xFFFF;
    volopt_cage_id = 0xFFFF;
    volopt_cage_group = 0xFFFF;
    volopt_p02_id = 0xFFFF;
    volopt_hiraisin_id = 0xFFFF;
    for (i = 0; i < 6; i++) {
        volopt_target_entity_ids[i] = 0xFFFF;
    }
    volopt_core_id = 0xFFFF;
}

void TBoss3Volopt::load_resources() {
    s32 v2;
    void *resource;
    v2 = TObjEneDD::check_v2_mode();
    if (v2 != 0) {
        resource = ::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 5, &bm_boss3_volopt_ap_resource_descriptor, 0, 0, 0);
        }
        boss3_volopt_resources = (BmlResource *)resource;
    } else {
        resource = ::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 5, &bm_boss3_volopt_resource_descriptor, 0, 0, 0);
        }
        boss3_volopt_resources = (BmlResource *)resource;
    }
    volopt_v2_mode = v2;
    TBoss3VoloptP01::init_breakup_effect();
    TBoss3VoloptCore::load_resources();
    TBoss3VoloptP02::load_resources();
    TBoss3VoloptHiraisin::init_models();
    TBoss3VoloptMonitor::load_resources();
    volopt_shutter_model_b = ((VoloptShutterNode *)boss3_volopt_resources->models[13].model)->model;
    volopt_shutter_model_a = ((VoloptShutterNode *)boss3_volopt_resources->models[13].model)->child->model;
    volopt_shutter_global_param = boss3_volopt_resources->models[13].m_c;
    TObjVoloptPillar::cache_target_values();
    TObjVoloptCage::init_break_model();
    volopt_p02_id = 0xFFFF;
    volopt_resources_loaded = 0;
    volopt_phase1_camera = (VoloptCameraParams *)TLobby::dispatch_shared_handler_a(0x27);
    volopt_phase2_camera = (VoloptCameraParams *)TLobby::dispatch_shared_handler_a(0x28);
    volopt_cage_camera = (VoloptCameraParams *)TLobby::dispatch_shared_handler_a(0x29);
}

void TBoss3Volopt::free_parts() {
    TObjVoloptCage::destroy();
    if (boss3_volopt_resources != NULL) {
        TLobby__sub_8001FE7C(boss3_volopt_resources, 1);
        boss3_volopt_resources = NULL;
    }
    TBoss3VoloptP01::destroy();
    TBoss3VoloptCore::release();
    TBoss3VoloptP02::free_resources();
    TBoss3VoloptHiraisin::destroy();
    TBoss3VoloptMonitor::release();
}

void *TBoss3Volopt::create(void *set_data) {
    return new TBoss3Volopt(set_data);
}

void TBoss3Volopt::run_task() {
    if (obj_testFlags30(0x800) != 0) {
        queue_destruction();
        return;
    }
    if (obj_testFlags30(0x4000) != 0) {
        if (((TObjPlayer *)this)->add_status_effect_timer(4, -1) <= 0) {
            reset_status_effect_row(unk_284);
            obj_clearFlags30(0x4000);
        }
    } else {
        if ((s32)next_action != mode) {
            if ((s32)state != -1) {
                state = -1;
                dispatch_mode();
            }
            mode = next_action;
            state = 0;
        }
        dispatch_mode();
    }
}

void TBoss3Volopt::dispatch_mode() {
    VoloptCameraParams *camera;
    switch (mode) {
    case 0:
        spawn_parts();
        break;
    case 1:
        update_intro_cutscene();
        play_persistent_sound(0x4003C600, this, 0, 0, 0);
        break;
    case 2:
        update_phase1();
        camera = volopt_phase1_camera;
        if (camera->enabled != 0) {
            boss3_volopt_seq2_camera_position.x = 0.0f;
            boss3_volopt_seq2_camera_position.y = camera->position_y;
            boss3_volopt_seq2_camera_position.z = camera->position_z;
            boss3_volopt_seq2_camera_target.x = 0.0f;
            boss3_volopt_seq2_camera_target.y = camera->target_y;
            boss3_volopt_seq2_camera_target.z = camera->target_z;
            request_follow_camera_offsets(&boss3_volopt_seq2_camera_position, &boss3_volopt_seq2_camera_target, 0xFFFF, 0.0f);
        }
        break;
    case 3:
        update_phase2_intro();
        play_persistent_sound(0x4003C601, this, 0, 0, 0);
        break;
    case 4:
        update_phase2();
        if (boss3_volopt_cage_flag != 0) {
            camera = volopt_cage_camera;
        } else {
            camera = volopt_phase2_camera;
        }
        if (camera->enabled != 0) {
            boss3_volopt_seq4_camera_position.x = 0.0f;
            boss3_volopt_seq4_camera_position.y = camera->position_y;
            boss3_volopt_seq4_camera_position.z = camera->position_z;
            boss3_volopt_seq4_camera_target.x = 0.0f;
            boss3_volopt_seq4_camera_target.y = camera->target_y;
            boss3_volopt_seq4_camera_target.z = camera->target_z;
            request_follow_camera_offsets(&boss3_volopt_seq4_camera_position, &boss3_volopt_seq4_camera_target, 0xFFFF, 0.0f);
        }
        break;
    case 5:
        break;
    }
}

void TBoss3Volopt::render() {}

void TBoss3Volopt::move_to_arena(s32 phase2) {
    s32 allowed;
    s32 i;
    TObjPlayer *player;
    f32 z;

    boss3_volopt_spawn_pos.x = 0.0f;
    boss3_volopt_spawn_pos.y = 0.0f;
    z = 0.0f;
    if (phase2 != 0) {
        z = -5000.0f;
    }
    boss3_volopt_spawn_pos.z = z;
    allowed = 0;
    if (get_main_phase() == 0xF) {
        if (is_local_client_floor_leader() != 0) {
            allowed = 1;
        }
    } else {
        allowed = 1;
    }
    if (allowed != 0) {
        if (phase2 != 0) {
            for (i = 0; i < lbl_805D586C; i++) {
                player = TObjPlayer::get_player_data(i);
                if (player != NULL && TObjRoomId__sub_801A1DB8(get_entity_id(player)) == 0 &&
                    ((TBoss3Volopt *)player)->get_field_3e0() == 0xD) {
                    send_position(player, &volopt_phase2_player_positions[i], volopt_phase2_player_angles[i]);
                }
            }
        }
        push_actors_out(phase2);
    }
}

void TBoss3Volopt::select_phase1_attack() {
    TBoss3VoloptCore *core;
    TBoss3VoloptActionPacket move_core;
    TBoss3VoloptActionPacket release_core;
    TBoss3VoloptAttackPacket attack;
    TBoss3VoloptActionPacket move_core_v1;
    TBoss3VoloptActionPacket release_core_v1;
    TBoss3VoloptTargetsPacket targets;
    s32 i;
    s32 found;
    s32 moves;
    s32 count;
    s32 count_v1;

    if (are_p01s_idle() != 0 && find_nearest_visible_player(this, 0, 400.0f) != 0xFFFF) {
    if (attack_delay > 0) {
        attack_delay--;
    } else if (is_v2_mode() != 0) {
        switch (attack_step) {
        case 0:
            found = 0;
            for (i = 0; i < 6; i++) {
                if (volopt_target_slot_used[i * 4] == 0) {
                    found = 1;
                }
            }
            if (found != 0) {
                if ((core = (TBoss3VoloptCore *)find_entity_by_id(volopt_core_id)) != NULL && core->is_mode_0() != 0) {
                    moves = (s32)(2.0f * calc_boss4_scale__10TObjPlayerFi(this)) + 2;
                    move_core.init();
                    move_core.id = entity_id;
                    move_core.action = 0;
                    move_core.param = core_slot;
                    move_core.param2 = moves;
                    move_core.send();
                    core_slot -= moves;
                    if (core_slot < 0) {
                        core_slot += 6;
                    }
                    attack_delay = 0x1E;
                    attack_step = 1;
                }
            } else {
                attack_step = 2;
            }
            break;
        case 1:
            if (boss3_volopt_core_active_flag != 0) {
                attack_step = 2;
            }
            break;
        case 2:
            breakup_tries = 0;
            volopt_breakup_flag = 0;
            attack_step = 3;
            break;
        case 3:
            if (volopt_breakup_flag == 1 || breakup_tries >= 2) {
                volopt_breakup_flag = 1;
                release_core.init();
                release_core.id = entity_id;
                release_core.action = 1;
                release_core.send();
                attack_step = 0;
                attack_delay = 0x1E;
            } else {
                breakup_tries++;
                count = shuffle_p01_order();
                attack.init();
                attack.id = entity_id;
                attack.count = max_targets < count ? max_targets : count;
                attack.tech = 3.0f * calc_boss4_scale__10TObjPlayerFi(this);
                ((TLobby *)attack.order)->move_data(volopt_p01_order, 6);
                attack.send();
                if (max_targets < 5) {
                    max_targets++;
                }
                attack_delay = 0x1E;
            }
            break;
        }
    } else {
        switch (attack_step) {
        case 0:
            found = 0;
            for (i = 0; i < 6; i++) {
                if (volopt_target_slot_used[i * 4] == 0) {
                    found = 1;
                }
            }
            if (found != 0) {
                if ((core = (TBoss3VoloptCore *)find_entity_by_id(volopt_core_id)) != NULL && core->is_mode_0() != 0) {
                    moves = (s32)(2.0f * calc_boss4_scale__10TObjPlayerFi(this)) + 2;
                    move_core_v1.init();
                    move_core_v1.id = entity_id;
                    move_core_v1.action = 0;
                    move_core_v1.param = core_slot;
                    move_core_v1.param2 = moves;
                    move_core_v1.send();
                    core_slot -= moves;
                    if (core_slot < 0) {
                        core_slot += 6;
                    }
                    attack_delay = 0x1E;
                    attack_step = 1;
                }
            } else {
                attack_step = 2;
            }
            break;
        case 1:
            if (boss3_volopt_core_active_flag != 0) {
                attack_step = 2;
            }
            break;
        case 2:
            breakup_tries = 0;
            volopt_breakup_flag = 0;
            attack_step = 3;
            break;
        case 3:
            if (volopt_breakup_flag == 1 || breakup_tries >= 2) {
                volopt_breakup_flag = 1;
                release_core_v1.init();
                release_core_v1.id = entity_id;
                release_core_v1.action = 1;
                release_core_v1.send();
                attack_step = 0;
                attack_delay = 0x1E;
            } else {
                breakup_tries++;
                count_v1 = shuffle_p01_order();
                targets.init();
                targets.id = entity_id;
                targets.count = max_targets < count_v1 ? max_targets : count_v1;
                ((TLobby *)targets.order)->move_data(volopt_p01_order, 6);
                targets.send();
                if (max_targets < 5) {
                    max_targets++;
                }
                attack_delay = 0x1E;
            }
            break;
        }
    }
    }
}

#pragma push
#pragma fp_contract on
void TBoss3Volopt::select_phase2_attack() {
    TBoss3VoloptP02 *p02;
    if (is_p02_idle() == 0) {
        return;
    }
    if (find_nearest_visible_player(this, 0, 400.0f) == 0xFFFF) {
        return;
    }
    if (attack_delay > 0) {
        attack_delay--;
        return;
    }
    p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
    if (p02 == NULL) {
        return;
    }
    if (is_v2_mode() != 0) {
        s32 kinds[5];
        f32 thresholds[5];
        f32 total = 0.0f;
        u16 target;
        s32 n = 0;
        if (p02->can_action_wait() != 0) {
            total += 0.27f;
            thresholds[0] = 0.27f;
            kinds[n++] = 0;
        }
        if (p02->can_action() != 0) {
            thresholds[n] = 0.15f + total;
            total += 0.15f;
            kinds[n++] = 1;
            thresholds[n] = 0.2f + total;
            total += 0.2f;
            kinds[n++] = 4;
        }
        if (p02->can_trigger() != 0) {
            thresholds[n] = 0.18f + total;
            total += 0.18f;
            kinds[n++] = 2;
        }
        if (p02->can_set_motion() != 0) {
            thresholds[n] = 0.2f + total;
            total += 0.2f;
            kinds[n++] = 3;
        }
        if (n == 0) {
            return;
        }
        {
            f32 roll = total * calc_boss4_scale__10TObjPlayerFi(this);
            s32 i;
            attack_step = -1;
            for (i = 0; i < n; i++) {
                if (thresholds[i] >= roll) {
                    attack_step = kinds[i];
                    break;
                }
            }
        }
        attack_count++;
        if (attack_count >= 3) {
            attack_count = 0;
            target = find_random_player();
        } else {
            target = find_strongest_player();
        }
        targetId = target;
        switch (attack_step) {
        case 0:
            if (p02->can_action_wait() != 0) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 3;
                packet.target_id = target;
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            attack_step++;
            return;
        case 1:
            if (p02->can_action() != 0 && targetId != 0xFFFF) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 4;
                if (is_v2_mode() != 0) {
                    TBoss3VoloptP02::send_random_params();
                }
                packet.target_id = target;
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            attack_step++;
            return;
        case 2:
            if (p02->can_trigger() != 0) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 5;
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            attack_step++;
            return;
        case 3:
            if (p02->can_set_motion() != 0 && target != 0xFFFF) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 6;
                packet.target_id = target;
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            attack_step = 0;
            return;
        case 4:
            if (p02->can_action() != 0) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 7;
                packet.param = 40.0f * calc_boss4_scale__10TObjPlayerFi(this);
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            return;
        }
    } else {
        switch (attack_step) {
        case 0:
            if (p02->can_action_wait() != 0) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 3;
                packet.target_id = p02->find_facing_player();
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            attack_step++;
            return;
        case 1:
            if (p02->can_action() != 0) {
                u16 target = find_nearest_visible_player(this, 0, 400.0f);
                if (target != 0xFFFF) {
                    TBoss3VoloptActionPacket packet;
                    packet.init();
                    packet.id = entity_id;
                    packet.action = 4;
                    if (is_v2_mode() != 0) {
                        TBoss3VoloptP02::send_random_params();
                    }
                    packet.target_id = target;
                    packet.send();
                    attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
                }
            }
            attack_step++;
            return;
        case 2:
            if (p02->can_trigger() != 0) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 5;
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            attack_step++;
            return;
        case 3:
            if (p02->can_set_motion() != 0) {
                u16 target = find_nearest_visible_player(this, 0, 400.0f);
                if (target != 0xFFFF) {
                    TBoss3VoloptActionPacket packet;
                    packet.init();
                    packet.id = entity_id;
                    packet.action = 6;
                    packet.target_id = target;
                    packet.send();
                    attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
                }
            }
            attack_step = 0;
            return;
        case 4:
            if (p02->can_action() != 0) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 7;
                packet.param = 40.0f * calc_boss4_scale__10TObjPlayerFi(this);
                packet.send();
                attack_delay = 30.0f * (f32)p02->count_dead_parts() + 30.0f;
            }
            return;
        }
    }
}
#pragma pop

void TBoss3Volopt::start_phase1() {
    in_phase2 = 0;
    vol_opt_active_hit_zone = -1;
    move_to_arena(0);
    core_slot = 4;
    attack_step = 0;
    attack_delay = 0;
    pad_3f4 = 0;
    breakup_tries = 0;
    pad_3fa = 0;
    lbl_805D4C1C = 0;
    pad_400 = 1;
    max_targets = 2;
    volopt_death_active = 0;
    play_area_music("vol_opt1.adx");
    volopt_resources_loaded = 1;
}

void TBoss3Volopt::start_phase2() {
    in_phase2 = 1;
    TObjEnemyCustom *p02 = (TObjEnemyCustom *)find_entity_by_id(volopt_p02_id);
    if (p02 != NULL) {
        p02->sub_800C7860();
    }
    move_to_arena(1);
    VecCopy((Vec *)position, VecCopy((Vec *)&m_2fc, &boss3_volopt_spawn_pos));
    attack_step = 0;
    attack_delay = 0;
    clear_volopt_cage_flag();
    play_area_music("vol_opt2.adx");
    attack_count = 0;
}

void TBoss3Volopt::update_intro_cutscene() {
    CameraPlayback first;
    CameraPlayback second;
    switch (state) {
    case 0:
        start_phase1();
        TObjPlayer::freeze_all_players();
        TWindowCtrl::init_all_slots();
        {
            TBoss3VoloptHiraisin *hiraisin = (TBoss3VoloptHiraisin *)find_entity_by_id(volopt_hiraisin_id);
            if (hiraisin != NULL) {
                hiraisin->set_flag_08000000();
            }
        }
        m_384 = 0xD2;
        TFogCtrl::apply_all(0xA, 0);
        first.index = 0;
        first.bank = 1;
        first.flags = 0;
        first.frame = 0.0f;
        first.frame_step = 0.0f;
        activate_camera_mode(5);
        ((TCameraCtrl *)&first)->cache_target_and_forward(0x271C);
        state = 1;
    case 1:
        play_persistent_sound(0x4003B202, this, 0, 0, 0);
        if (--m_384 <= 0) {
            m_384 = 0x3C;
            state = 2;
            TFogCtrl::update_all(0);
            second.index = 0;
            second.bank = 1;
            second.flags = 0;
            second.frame = 0.0f;
            second.frame_step = 1.0f;
            activate_camera_mode(5);
            ((TCameraCtrl *)&second)->cache_target_and_forward(0x271C);
        }
        break;
    case 2:
        if (get_scripted_camera_playback()->flags & 1) {
            TObjEnemyCustom *core = (TObjEnemyCustom *)find_entity_by_id(volopt_core_id);
            if (core != NULL) {
                core->sub_800C7860();
            }
            m_384 = 0x5A;
            state = 3;
        }
        break;
    case 3:
        if (--m_384 <= 0) {
            next_action = 2;
        }
        break;
    case -1:
        {
            TBoss3VoloptHiraisin *hiraisin = (TBoss3VoloptHiraisin *)find_entity_by_id(volopt_hiraisin_id);
            if (hiraisin != NULL) {
                hiraisin->clear_flag_08000000();
            }
        }
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        TObjPlayer__sub_801BA42C();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss3Volopt::update_phase1() {
    Vec pos;
    s32 i;
    f32 radius;
    s32 angle;
    play_persistent_sound(0x4003C600, this, 0, 0, 0);
    switch (state) {
    case 0:
        state = 1;
    case 1:
        if (get_main_phase() == 0xF) {
            if (is_local_client_floor_leader() != 0) {
                select_phase1_attack();
            }
        } else {
            select_phase1_attack();
        }
        if (are_p01s_broken() != 0) {
            state = 2;
        }
        break;
    case 2: {
        m_384 = 0x96;
        TCameraCtrl__sub_8006A044(0xB4, 0.03f);
        for (i = 0; i < 6; i++) {
            TObject *p01 = (TObject *)find_entity_by_id(volopt_target_entity_ids[i]);
            if (p01 != NULL) {
                p01->pause_update();
            }
        }
        TObjEnemy *core = (TObjEnemy *)find_entity_by_id(volopt_core_id);
        if (core != NULL) {
            core->actorFlags |= 0x800;
        }
        state = 3;
        start_rumble();
    }
    case 3:
        if (--m_384 <= 0) {
            state = 4;
        }
        angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
        radius = 30.0f * (3.0517578e-05f * (f32)rand()) + 60.0f;
        pos.x = radius * cos_table_lookup(angle);
        pos.y = 50.0f * (3.0517578e-05f * (f32)rand()) + 10.0f;
        pos.z = radius * sin_table_lookup(angle);
        spawn_particle_effect(&pos, 0xFB);
        play_persistent_sound(0x4003AD21, this, 0, 0, 0);
        break;
    case 4:
        new TUnk_804848B8(this, NULL);
        stop_rumble();
        state = 5;
        break;
    case 5:
        if (volopt_fade_out_done == 1) {
            next_action = 3;
        }
        break;
    case -1:
        new TUnk_804848A0(this, NULL);
        break;
    }
}
#pragma pop

void TBoss3Volopt::update_phase2_intro() {
    CameraPlayback playback;
    switch (state) {
    case 0:
        start_phase2();
        activate_camera_mode(9);
        set_active_camera_pose((u8 *)&boss3_volopt_intro_camera_poses[0], (u8 *)&boss3_volopt_intro_camera_poses[1]);
        TObjPlayer::freeze_all_players();
        TWindowCtrl::init_all_slots();
        {
            TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
            if (p02 != NULL) {
                p02->set_flag_08000000();
            }
        }
        state = 1;
        return;
    case 1:
        if (volopt_fade_in_done == 1) {
            m_384 = 0x96;
            state = 2;
        }
        return;
    case 2:
        if (--m_384 <= 0) {
            restore_player_cameras();
            state = 3;
            return;
        }
        break;
    case 3:
        playback.index = 0;
        playback.bank = 2;
        playback.flags = 0;
        playback.frame = 0.0f;
        playback.frame_step = 1.0f;
        activate_camera_mode(5);
        ((TCameraCtrl *)&playback)->cache_target_and_forward(0x160A);
        set_scripted_camera_pose((Vec *)position, (Vec *)position, (CameraAngles *)&rotation_x);
        state = 4;
        return;
    case 4:
        if (get_scripted_camera_playback()->flags & 1) {
            restore_player_cameras();
            next_action = 4;
            return;
        }
        break;
    case -1:
        {
            TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
            if (p02 != NULL) {
                p02->clear_flag_08000000();
            }
        }
        TWindowCtrl::init_all_slots2();
        TObjPlayer__sub_801BA42C();
        break;
    }
}

void TBoss3Volopt::update_phase2() {
    switch (state) {
    case 0:
        state = 1;
    case 1:
        if (get_main_phase() == 0xF) {
            if (is_local_client_floor_leader() != 0) {
                select_phase2_attack();
            }
        } else {
            select_phase2_attack();
        }
        if (is_dead() != 0) {
            update_phase();
            obj_setFlags30(this, 0x800);
            vfunc_74(0);
            next_action = 5;
            new TUnk_80483B88;
        }
        play_persistent_sound(0x4003C601, this, 0, 0, 0);
        break;
    case -1:
        break;
    case 2:
        break;
    }
}

#pragma push
#pragma opt_lifetimes off
#pragma fp_contract on
void TBoss3Volopt::spawn_parts() {
    s32 timer;
    s32 i;
    s32 j;

    switch (state) {
    case 0:
        for (i = 0; i < 6; i++) {
            volopt_target_entity_ids[i] = get_part_id(i + 1);
            new TBoss3VoloptP01(this, i, volopt_target_entity_ids[i], get_part_group(i + 1));
        }
        boss3_volopt_monitor_base_actor_id = get_part_id(7);
        for (j = 0; j < 0x18; j++) {
            timer = (s32)(30.0f * (5.0f * (3.0517578e-05f * (f32)rand())) + 90.0f);
            new TBoss3VoloptMonitor(this, boss3_volopt_monitor_base_actor_id + j, get_part_group(j + 7), j, timer);
        }
        volopt_core_id = get_part_id(0x22);
        fn_8003F468(this, volopt_core_id, get_part_group(0x22));
        volopt_hiraisin_id = get_part_id(0x21);
        if (is_v2_mode() == 0) {
            new TBoss3VoloptHiraisin(this, volopt_hiraisin_id, get_part_group(0x21));
        }
        next_action = 1;
        break;
    }
}
#pragma pop

// Not called anywhere in the game, so the linker drops it; its 400.0f still
// takes its place in this file's constant pool.
u16 TBoss3Volopt::find_attack_target() {
    return find_nearest_visible_player(this, 0, 400.0f);
}

BOOL TBoss3Volopt::are_p01s_idle() {
    s32 i;
    TBoss3VoloptP01 *p01;
    for (i = 0; i < 6; i++) {
        p01 = (TBoss3VoloptP01 *)find_entity_by_id(volopt_target_entity_ids[i]);
        if (p01 != NULL && p01->is_broken() == 0 && p01->is_mode_0() == 0) {
            return 0;
        }
    }
    return 1;
}

BOOL TBoss3Volopt::is_p02_idle() {
    TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
    if (p02 != NULL && p02->is_mode_0() != 0) {
        return 1;
    }
    return 0;
}

BOOL TBoss3Volopt::are_p01s_broken() {
    s32 i;
    TObjEnemy *core = (TObjEnemy *)find_entity_by_id(volopt_core_id);
    if (core != NULL && (core->actorFlags & 0x800)) {
        return 1;
    }
    for (i = 0; i < 6; i++) {
        TBoss3VoloptP01 *p01 = (TBoss3VoloptP01 *)find_entity_by_id(volopt_target_entity_ids[i]);
        if (p01 != NULL && p01->is_broken() == 0) {
            return 0;
        }
    }
    return 1;
}

BOOL TBoss3Volopt::is_dead() {
    return volopt_death_active;
}

#pragma push
#pragma opt_lifetimes off
s32 TBoss3Volopt::shuffle_p01_order() {
    s32 count;
    s32 i;
    s32 a;
    s32 b;
    s32 swap;

    count = 0;
    for (i = 0; i < 6; i++) {
        TBoss3VoloptP01 *p01 = (TBoss3VoloptP01 *)find_entity_by_id(volopt_target_entity_ids[i]);
        if (p01 != NULL && p01->is_broken() == 0) {
            volopt_p01_order[count] = i;
            count++;
        }
    }
    if (count <= 1) {
        return count;
    }
    for (i = 0; i < count * 5; i++) {
        a = (s32)((f32)count * calc_boss4_scale__10TObjPlayerFi(this));
        b = (s32)((f32)count * calc_boss4_scale__10TObjPlayerFi(this));
        if (a != b) {
            swap = volopt_p01_order[a];
            volopt_p01_order[a] = volopt_p01_order[b];
            volopt_p01_order[b] = swap;
        }
    }
    return count;
}
#pragma pop

void TBoss3Volopt::set_primary_p01s(s32 count) {
    s32 i;
    TBoss3VoloptP01 *p01;
    if (count == 0) {
        return;
    }
    p01 = (TBoss3VoloptP01 *)find_entity_by_id(((volatile u16 *)volopt_target_entity_ids)[volopt_p01_order[0]]);
    if (p01 != NULL) {
        p01->set_primary(1);
    }
    for (i = 1; i < count; i++) {
        p01 = (TBoss3VoloptP01 *)find_entity_by_id(((volatile u16 *)volopt_target_entity_ids)[volopt_p01_order[i]]);
        if (p01 != NULL) {
            p01->set_primary(0);
        }
    }
}

Vec *TBoss3Volopt::get_camera_focus() {
    return volopt_camera_focus;
}

void TBoss3Volopt::set_camera_focus(Vec *pos) {
    volopt_camera_focus = pos;
}

void TBoss3Volopt::push_actors_out(s32 phase2) {
    f32 center_z;
    s32 i;
    TObjPlayer *actor;

    center_z = (f32)((phase2 != 0) ? -5000 : 0);
    for (i = lbl_805D586C + lbl_805D5870; i < lbl_805D5868; i++) {
        actor = TObjPlayer::get_player_data(i);
        if (actor == NULL) continue;
        if (actor->m_a4 == NULL) continue;
        if (((TUnk_804B6C24 *)actor)->check_value_equals(lbl_805D2ECC) != 0) continue;
        if (((TUnk_804B6C24 *)actor)->check_value_equals(TODoorVoShip__class_name) != 0) continue;
        if (!(actor->m_a4->flags & 0x20000)) continue;
        if (fabs_float(actor->position[2] - center_z) > 1000.0f) {
            Vec pos = *(Vec *)actor->position;
            pos.z += (f32)((phase2 != 0) ? -5000 : 5000);
            if (phase2 == 1) {
                Vec offset;
                offset.x = pos.x;
                offset.y = 0.0f;
                offset.z = pos.z - center_z;
                if (newton_sqrtf(offset.x * offset.x + offset.z * offset.z) < 50.0f) {
                    vec_set_length((Vec *)&offset, 50.0f);
                    pos.x = offset.x;
                    pos.z = offset.z + center_z;
                }
            }
            send_position(actor, &pos, actor->rotation_y);
        }
    }
}

void handle_6x15_vol_opt_boss_actions(TBoss3VoloptActionPacket *packet) {
    s32 i;

    packet->swap();
    switch (packet->action) {
    case 0: {
        TBoss3VoloptCore *core = (TBoss3VoloptCore *)find_entity_by_id(volopt_core_id);
        if (core != NULL) {
            core->set_boss_target_pos(packet->param, packet->param2, 0x258);
        }
        break;
    }
    case 1:
        TBoss3VoloptCore::set_grabbed_state(0);
        break;
    case 2: {
        TBoss3VoloptHiraisin *hiraisin = (TBoss3VoloptHiraisin *)find_entity_by_id(volopt_hiraisin_id);
        if (hiraisin != NULL) {
            hiraisin->start_attack();
        }
        for (i = 0; i < 6; i++) {
            TBoss3VoloptP01 *p01 = (TBoss3VoloptP01 *)find_entity_by_id(volopt_target_entity_ids[i]);
            if (p01 != NULL) {
                p01->sub_80042F84();
            }
        }
        break;
    }
    case 3: {
        TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
        if (p02 != NULL) {
            p02->set_action_wait(packet->target_id);
        }
        break;
    }
    case 4: {
        TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
        if (p02 != NULL) {
            p02->set_action(packet->target_id);
        }
        break;
    }
    case 5: {
        TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
        if (p02 != NULL) {
            p02->check_and_trigger();
        }
        break;
    }
    case 6: {
        TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
        if (p02 != NULL) {
            p02->set_motion(packet->target_id);
        }
        break;
    }
    case 7: {
        TBoss3VoloptP02 *p02 = (TBoss3VoloptP02 *)find_entity_by_id(volopt_p02_id);
        if (p02 != NULL) {
            p02->apply_hit_reaction(packet->param);
        }
        break;
    }
    }
}

void handle_6x16_vol_opt_boss_actions(TBoss3VoloptTargetsPacket *packet) {
    packet->swap();
    ((TLobby *)volopt_p01_order)->move_data(packet->order, 6);
    TBoss3Volopt::set_primary_p01s(packet->count);
    volopt_p01_tech = -1;
}

void TBoss3Volopt::send_position(TObjPlayer *player, Vec *pos, s32 rotation_y) {
    TBoss3VoloptPositionPacket packet;
    if (player != NULL) {
        packet.init();
        packet.id = get_entity_id(player);
        VecCopy(&packet.pos, pos);
        packet.rotation_y = rotation_y;
        packet.send();
    }
}

void handle_6x17_set_entity_position_and_angle(TBoss3VoloptPositionPacket *packet) {
    TUnk_804AF8A0 *actor;

    packet->swap();
    actor = (TUnk_804AF8A0 *)find_entity_by_id(packet->id);
    if (actor != NULL) {
        VecCopy((Vec *)actor->position, &packet->pos);
        actor->rotation_y = packet->rotation_y;
        actor->refresh_collision_body_centers();
        if ((s32)packet->id == local_client_id) {
            reset_cameras_to_actor(actor, 0);
        }
    }
}

BOOL TBoss3Volopt::is_death_active() {
    if (volopt_death_active != 0) {
        return 1;
    }
    return 0;
}

void TBoss3Volopt::start_rumble() {
    start_pad_rumble(0xA0, 0);
}

void TBoss3Volopt::stop_rumble() {
    cancel_pad_rumble(0);
}

void TBoss3Volopt::update_phase() {
    TBoss4DarkFalz::dispatch_by_main_phase(0x2A);
    if (get_main_phase() == 0xF) {
        TBoss3VoloptCtrl::dispatch_state(0);
        return;
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        TBoss3VoloptCtrl::dispatch_state(5);
        return;
    }
    if (get_story_flag(0x2F) != 0) {
        TBoss3VoloptCtrl::dispatch_state(2);
        return;
    }
    TBoss3VoloptCtrl::dispatch_state(1);
}

void handle_6x84_vol_opt_boss_actions(TBoss3VoloptAttackPacket *packet) {
    packet->swap();
    ((TLobby *)volopt_p01_order)->move_data(packet->order, 6);
    volopt_p01_tech = packet->tech;
    TBoss3Volopt::set_primary_p01s(packet->count);
}

void handle_6x85_vol_opt_phase2_boss_actions(VoloptPhase2Message *message) {
    if (TBoss3Volopt::is_v2_mode() != 0) {
        message->swap();
        switch (message->mode) {
        case 0:
            TBoss3VoloptP02::copy_phase2_positions_to_global(message);
            break;
        }
    }
}

s32 TBoss3Volopt::collect_candidate_players() {
    s32 i;
    TObjPlayer *player;

    volopt_candidate_count = 0;
    for (i = 0; i < lbl_805D586C; i++) {
        player = TObjPlayer::get_player_data(i);
        if ((player->actorFlags & 0x02000800) == 0) {
            s32 floor = get_current_floor();
            s32 room = player->get_field_3e4();
            if (room == floor) {
                candidate_players[volopt_candidate_count++] = player;
            }
        }
    }
    for (i = volopt_candidate_count; i < 4; i++) {
        candidate_players[i] = NULL;
    }
    return volopt_candidate_count;
}

u16 TBoss3Volopt::find_random_player() {
    TObjPlayer *player;
    if (collect_candidate_players() == 0) {
        return 0xFFFF;
    }
    player = candidate_players[(s32)((f32)volopt_candidate_count * (3.0517578e-05f * (f32)rand()))];
    if (player != NULL) {
        return get_entity_id(player);
    }
    return 0xFFFF;
}

u16 TBoss3Volopt::find_strongest_player() {
    s32 best_hp;
    TObjPlayer *best;
    s32 i;
    TObjPlayer *player;

    if (collect_candidate_players() == 0) {
        return 0xFFFF;
    }
    best_hp = 0;
    best = NULL;
    for (i = 0; i < volopt_candidate_count; i++) {
        player = candidate_players[i];
        if (player != NULL) {
            s16 hp = get_actor_hp((u8 *)player);
            if (hp > best_hp) {
                best_hp = hp;
                best = player;
            }
        }
    }
    if (best != NULL) {
        return get_entity_id(best);
    }
    return 0xFFFF;
}
