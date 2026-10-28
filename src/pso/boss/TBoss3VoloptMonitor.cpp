#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/boss/TBoss3VoloptCore.h"
#include "pso/boss/TBoss3VoloptMonitor.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaMaterialState.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80086D50.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_80141550.h"

extern "C" {
s32 play_sound_effect(s32 id, Vec *pos, s32 a2, s32 flags);
void obj_setFlags30(TObject *obj, u32 mask);
void *find_entity_by_id(u16 id);
void submit_cursor_candidate(TObject *obj, s32 a1);
s32 minimap_render_dot(Vec *pos, s32 color, s16 a2, s32 a3);
void init_collision_body_parts(TObject *obj, void *parts, s32 count);
void free_collision_body_parts(TObject *obj);
void push_matrix(void);
s32 pop_matrix(void);
void set_matrix_identity(void *mtx);
void rotate_matrix_y(void *mtx, s32 angle);
void matrix_mult_vec(void *mtx, const Vec *src, Vec *dst);
void scroll_ginja_mesh_uvs(void *mesh, s16 du, s16 dv, u16 cmd, s32 rewrite);
void PPCSync(void);
int rand(void);
void release_texture_list(GinjaTextureList *list);


extern u32 model_render_flags;
extern s32 actor_frame_tick;
extern TObject *tl_04;
}

struct EnemyMovementParams {
    f32 pad_0;
    f32 pad_4;
    s32 pad_8;
    s32 pad_c;
    s32 pad_10;
    s32 pad_14;
    s32 pad_18;
};

struct CollisionBodyPart {
    Vec offset;
    f32 radius;
    u8 pad_10[0x8];
    s32 flags;
    u8 pad_1c[0x10];
};

struct CollisionState {
    u8 pad_0[0x18];
    u32 flags;
};

struct BossStats {
    u8 pad_0[0x6];
    s16 hp;
};

struct MonitorStatTable {
    u8 pad_0[0x18];
    s32 hp[2];
};

enum MonitorScreen {
    MONITOR_SCREEN_TEXT = 0,
    MONITOR_SCREEN_NOISE = 8,
    MONITOR_SCREEN_TARGET = 16,
    MONITOR_SCREEN_BROKEN = 24
};

#pragma readonly_strings on

static const char *TBoss3VoloptMonitor_name = "TBoss3VoloptMonitor";

static EnemyMovementParams volopt_monitor_movement = {
    150.0f, 0.5555555f, 0x400, 0x1E0000, 0, 1, 0,
};

static CollisionBodyPart volopt_monitor_collision[4] = {
    { { 0.0f, 43.0f, 0.0f }, 20.0f, { 0 }, 0x8005 },
    { { 0.0f, 15.0f, 0.0f }, 10.0f, { 0 }, 0x8003 },
    { { 0.0f, 15.0f, 0.0f }, 15.0f, { 0 }, 0x8003 },
    { { 0.0f, 15.0f, 0.0f }, 10.0f, { 0 }, 0x8003 },
};

static Vec volopt_monitor_offsets[4] = {
    { 0.0f, 0.0f, -110.0f },
    { -26.0f, 0.0f, -110.0f },
    { 0.0f, 0.0f, -115.0f },
    { 26.0f, 0.0f, -110.0f },
};

static s32 volopt_monitor_models[3][4] = {
    { 2, 5, 8, 11 },
    { 1, 4, 7, 10 },
    { 3, 6, 9, 12 },
};

static GinjaTextureList volopt_monitor_screen = { NULL, 2 };

static GinjaTextureEntry volopt_monitor_texture_entries[25] = {
    { "ki_u256_vo_mo_moji001" },
    { "ki_u256_vo_mo_moji002" },
    { "ki_u256_vo_mo_moji003" },
    { "ki_u256_vo_mo_moji004" },
    { "ki_u256_vo_mo_moji005" },
    { "ki_u256_vo_mo_moji006" },
    { "ki_u256_vo_mo_moji007" },
    { "ki_u256_vo_mo_moji008" },
    { "ki_u256_vo_mo_noize001" },
    { "ki_u256_vo_mo_noize002" },
    { "ki_u256_vo_mo_noize003" },
    { "ki_u256_vo_mo_noize004" },
    { "ki_u256_vo_mo_noize005" },
    { "ki_u256_vo_mo_noize006" },
    { "ki_u256_vo_mo_noize007" },
    { "ki_u256_vo_mo_noize008" },
    { "ki_u256_vo_mo_target001" },
    { "ki_u256_vo_mo_target002" },
    { "ki_u256_vo_mo_target003" },
    { "ki_u256_vo_mo_target004" },
    { "ki_u256_vo_mo_target005" },
    { "ki_u256_vo_mo_target006" },
    { "ki_u256_vo_mo_target007" },
    { "ki_u256_vo_mo_target008" },
    { "ki_u064_vo_mo" },
};

static GinjaTextureList volopt_monitor_texture_table = { volopt_monitor_texture_entries, 25 };


static BossStats *volopt_monitor_stats;
static void *volopt_monitor_stats_b;
static void *volopt_monitor_object_params;
static MonitorStatTable *volopt_monitor_stat_table;
static BmlResource *volopt_monitor_resources;
static GinjaTextureList *volopt_monitor_textures;
static s32 volopt_monitor_last_tick;

static void *volopt_monitor_screen_meshes[4];
s8 volopt_target_slot_used[VOLOPT_MONITOR_SLOTS];
Vec volopt_slot_positions[VOLOPT_MONITOR_SLOTS];

s32 fn_80042960(s32 i);
s32 fn_80042960(s32 i) {
    return volopt_monitor_stat_table->hp[i];
}

void TBoss3VoloptMonitor::set_model(s32 index) {
    model = (void *)volopt_monitor_resources->models[index].model;
}

void TObjEnemyCustom::sub_8004292C() {
    actorFlags &= ~0x04040000;
}

void TObjEnemyCustom::set_flags_30() {
    actorFlags |= 0x04040000;
}

TBoss3VoloptMonitor::TBoss3VoloptMonitor(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    m_name = TBoss3VoloptMonitor_name;
    apply_set_data(set_data);
    variant = 0;
    timer = 0;
    init_params();
    init_collision_body_parts(this, volopt_monitor_collision, 1);
    set_model(1);
}

TBoss3VoloptMonitor::TBoss3VoloptMonitor(TUnk_804B9870 *parent, u16 id, s32 index, s32 slot_index, s32 start_timer) : TObjEnemyCustom(parent) {
    m_name = TBoss3VoloptMonitor_name;
    entity_id = id;
    set_index = index;
    set_entry = NULL;
    room = parent->room;
    set_group = parent->set_group;
    slot = slot_index;
    variant = slot_index & 3;
    timer = start_timer;
    init_params();
    rotation_y = 182.04445f * (f32)((slot_index / 4) * 60);
    set_model(volopt_monitor_models[0][variant]);
    push_matrix();
    set_matrix_identity(NULL);
    rotate_matrix_y(NULL, rotation_y);
    matrix_mult_vec(NULL, &volopt_monitor_offsets[variant], &position);
    pop_matrix();
    VecCopy(&volopt_slot_positions[slot], &position);
    volopt_slot_positions[slot].y = (slot & 3) == 0 ? 43.0f : 15.0f;
    init_collision_body_parts(this, &volopt_monitor_collision[variant], 1);
    ((CollisionState *)m_a4)->flags |= 0x500;
}

TBoss3VoloptMonitor::~TBoss3VoloptMonitor() {
    free_collision_body_parts(this);
}

void TBoss3VoloptMonitor::init_params() {
    movementParameters = &volopt_monitor_movement;
    volopt_monitor_stats->hp = fn_80042960(slot % 4 ? 1 : 0);
    recalc_combat_stats(volopt_monitor_stats, volopt_monitor_stats_b, volopt_monitor_object_params, 1.0f, 1.0f);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    set_param(0x2E);
    update_prev_position();
    ((TBoss3Volopt *)this)->reset_photon_effect();
    anim_frame = 8.0f * (3.0517578e-05f * (f32)rand());
    anim_timer = 3.0f * (3.0517578e-05f * (f32)rand());
    add_flags_2e4(4);
    volopt_target_slot_used[slot] = 0;
    obj_setFlags30(this, 0x8000);
    clear_lobby_object_state();
}

void *TBoss3VoloptMonitor::create(void *set_data) {
    return new TBoss3VoloptMonitor(tl_04, set_data);
}

void TBoss3VoloptMonitor::load_resources() {
    s32 i;
    volopt_monitor_textures = &volopt_monitor_texture_table;
    volopt_monitor_resources = boss3_volopt_resources;
    clear_texlist_names((NJS_TEXLIST *)&volopt_monitor_texture_table);
    TLobby::load_texture_pvm_file("fe_obj_vo_momitor.gvm", (s32)volopt_monitor_textures);
    for (i = 0; i < 4; i++) {
        volopt_monitor_screen_meshes[i] = ((void **)get_bml_model(volopt_monitor_resources, volopt_monitor_models[2][i]))[1];
    }
    volopt_monitor_stats = (BossStats *)TLobby::register_boss(0x23);
    volopt_monitor_stats_b = TLobby::dispatch_shared_handler_b(0x23);
    volopt_monitor_object_params = TLobby::register_object(0x23);
    volopt_monitor_stat_table = (MonitorStatTable *)TLobby::dispatch_shared_handler_a(0x23);
}

void TBoss3VoloptMonitor::release() {
    if (volopt_monitor_textures != NULL) {
        release_texture_list(volopt_monitor_textures);
        volopt_monitor_textures = NULL;
    }
}

void TBoss3VoloptMonitor::run_task() {
    s32 i;
    s32 in_zone;
    s32 base;
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_800420D8();
        return;
    }
    if (has_flag_0x800() != 0) {
        vfunc_63();
    } else if (test_flag30_512() != 0) {
        vfunc_62();
    }
    if (mode != (s32)next_action) {
        if ((s32)state != -1) {
            state = -1;
            dispatch_state();
        }
        mode = next_action;
        state = 0;
    }
    dispatch_state();
    update_prev_position();
    if (obj_testFlags30(0x800) == 0) {
        ((TBoss3VoloptHiraisin *)this)->copy_position();
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
    if (!(actorFlags & 0x800)) {
        if (--anim_timer <= 0) {
            anim_timer = 3;
            if (++anim_frame >= 8) {
                anim_frame = 0;
                if (m_388 & 0x10000) {
                    m_388 &= ~0x10000;
                } else if (3.0517578e-05f * (f32)rand() <= 0.1f) {
                    m_388 |= 0x10000;
                }
            }
        }
    }
    if (volopt_monitor_last_tick != actor_frame_tick) {
        volopt_monitor_last_tick = actor_frame_tick;
        for (i = 0; i < 4; i++) {
            scroll_ginja_mesh_uvs(volopt_monitor_screen_meshes[i], 0, 0x20, 0, 1);
            PPCSync();
        }
    }
    in_zone = 0;
    if (vol_opt_active_hit_zone >= 0) {
        base = (vol_opt_active_hit_zone / 4) * 4;
        if (slot >= base && slot < base + 4) {
            in_zone = 1;
        }
    }
    if (in_zone != 0) {
        sub_8004292C();
    } else {
        set_flags_30();
    }
    clear_all_status_effects();
}

void TBoss3VoloptMonitor::dispatch_state() {
    switch (mode) {
    case 0:
        sub_80041C78();
        return;
    case 1:
        sub_80041D0C();
        return;
    case 4:
        sub_80041E88();
        return;
    case 5:
        sub_80041D3C();
        return;
    }
}

void TBoss3VoloptMonitor::sub_800420D8() {}

void TBoss3VoloptMonitor::render() {
    s32 frame;
    s32 aligned;
    if (!(actorFlags & 0x02000000) && update_object_view_visibility(400.0f, 40.0f) != 0) {
        if (actorFlags & 0x800) {
            set_model(volopt_monitor_models[2][variant]);
            frame = MONITOR_SCREEN_BROKEN;
        } else {
            aligned = 0;
            if (vol_opt_active_hit_zone >= 0 && vol_opt_active_hit_zone / 4 == slot / 4) {
                aligned = 1;
            }
            if (aligned != 0) {
                set_model(volopt_monitor_models[1][variant]);
                frame = anim_frame + MONITOR_SCREEN_TARGET;
            } else {
                set_model(volopt_monitor_models[0][variant]);
                frame = anim_frame;
                if (m_388 & 0x10000) {
                    frame += MONITOR_SCREEN_NOISE;
                }
            }
        }
        volopt_monitor_screen.entries = &volopt_monitor_textures->entries[frame];
        TObjFish::set_global_param((s32)&volopt_monitor_screen);
        set_depth_buffer_settings_id(3);
        push_matrix();
        model_render_flags &= ~0x400;
        rotate_matrix_y(NULL, rotation_y);
        draw_ginja_object(model);
        pop_matrix();
        restore_draw_list_mask();
    }
}

void TBoss3VoloptMonitor::sub_80041E88() {
    switch (state) {
    case -1:
        break;
    case 0:
        m_388 |= 1;
        anim_timer = 3;
        anim_frame = 0;
        m_388 |= 0x10000;
        play_sound_effect(0x4003BC03, &position, 0, 0);
        damage_player_if_aligned();
        referenceHp = hp;
        *(s16 *)&timer = 3;
        state = 1;
        break;
    case 1:
        if (--*(s16 *)&timer <= 0) {
            obj_clearFlags30(0x200200);
            ((TObjEneMe1GiGue *)this)->update_if_active(0);
            m_388 &= ~1;
        }
        break;
    }
}

void TBoss3VoloptMonitor::sub_80041D3C() {
    s32 base;
    s32 all;
    s32 j;
    TBoss3VoloptMonitor *other;
    switch (state) {
    case 0:
        play_sound_effect(0x4003A804, &position, 0, 0);
        damage_player_if_aligned();
        spawn_effects();
        volopt_target_slot_used[slot] = 1;
        if (slot % 4 > 0) {
            all = 1;
            base = (slot / 4) * 4;
            for (j = base + 1; j < base + 4; j++) {
                if (volopt_target_slot_used[j] == 0) {
                    all = 0;
                }
            }
            if (all != 0) {
                other = (TBoss3VoloptMonitor *)find_entity_by_id(boss3_volopt_monitor_base_actor_id + base);
                if (other != NULL) {
                    other->set_hit_flags_and_notify();
                }
            }
        } else {
            for (j = slot + 1; j < slot + 4; j++) {
                other = (TBoss3VoloptMonitor *)find_entity_by_id(boss3_volopt_monitor_base_actor_id + j);
                if (other != NULL) {
                    other->set_hit_flags_and_notify();
                }
            }
        }
        state = 1;
        break;
    case -1:
        return;
    case 1:
        break;
    case 2:
        break;
    }
}

void TBoss3VoloptMonitor::sub_80041D0C() {
    switch (state) {
    case -1:
        break;
    case 0:
        actorFlags &= ~0x40000;
        state = 1;
        break;
    case 1:
        break;
    }
}

void TBoss3VoloptMonitor::sub_80041C78() {
    switch (state) {
    case 0:
        actorFlags |= 0x02040000;
        state = 1;
    case 1:
        if (--*(s16 *)&timer <= 0) {
            vfunc_59();
        }
        break;
    case -1:
        actorFlags &= ~0x02040000;
        break;
    }
}

void TBoss3VoloptMonitor::damage_player_if_aligned() {
    if (!(m_388 & 0x40000) && vol_opt_active_hit_zone >= 0 && vol_opt_active_hit_zone / 4 == slot / 4) {
        TBoss3VoloptCore::link_photon(m_2d4, 0);
    }
}

void TBoss3VoloptMonitor::spawn_effects() {
    s32 angle[3];
    angle[0] = 0;
    angle[1] = rotation_y;
    angle[2] = 0;
    spawn_directional_particle(&m_2fc, angle, (slot & 3) == 0 ? 0x62 : 0x61);
    spawn_particle_effect(&m_2fc, 0x45);
}

void TBoss3VoloptMonitor::set_hit_flags_and_notify() {
    m_388 |= 0x40000;
    obj_setFlags30(this, 0x800);
    vfunc_63();
}
