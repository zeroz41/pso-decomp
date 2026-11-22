#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/enemy/EnemyTargetCandidate.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"

#include "types.h"

#include "pso/render/NinjaUtil.h"

#include "pso/enemy/gibon/TObjEneBm5GibonU.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/base/TObjChara.h"

#include "pso/enemy/TObjEnemyCustom.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/gyaranzo/TObjEneGyaranzo.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/system/SoundEffect.h"

#include "pso/player/TObjPlayer_801AF2F0.h"


#include "pso/unk/text_803D96A8.h"





#include "pso/system/vector.h"

#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"

#include "pso/object/TUnk_8049442C.h"

#include "pso/object/TObjChip.h"

#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"

#include "pso/system/BmlResourceDescriptor.h"

#include "pso/render/TUnk_80494938.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/TObjControl.h"

#include <stddef.h>
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"

LAYOUT_ASSERT(GyaranzoPositionOffset, offsetof(TObjEneGyaranzo, position) == 0x38);

LAYOUT_ASSERT(GyaranzoYawOffset, offsetof(TObjEneGyaranzo, rotation_y) == 0x60);




#include "dolphin/mtx.h"

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off



extern "C" {



u8 *__ct__8TObjChipFP7TObjectPC14TObjChipParams(u8 *object, u8 *arg1, u8 *arg2);
}


u32 *gyaranzo_model_resources[0x16];

u8 *gyaranzo_resource_ptrs[13];

EnemyTargetCandidate TObjGyaranzoMissile_target_slots[4];

extern BmlResource *gyaranzo_bml_resource;

extern u8 *tl_05;


void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
extern "C" {

void calc_velocity_toward_destination(void *, Vec, Vec, f32);


}
void move_with_wall_slide(u8 *arg0);


#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

struct Desc_800D23D4 { Vec *pos; s32 a; s32 angle; f32 b; f32 c; f32 d; };

f32 get_gyaranzo_missile_float_parameter(s32);

extern f32 lbl_805D51F0;

extern f32 TObjGyaranzoMissile__speed_scale;

extern f32 TObjGyaranzoMissile__max_range;

extern "C" {


s32 check_path_obstructed(void *, void *);


u16 get_entity_id(void *);

s32 subtract_vector(void *, void *);







extern s32 gyaranzo_missile_volley_end_time;

void spawn_missile_volley__19TObjGyaranzoMissileFPv(u8 *arg0);

void update__19TObjGyaranzoMissileFPv(u8 *self);

s32 TBoss3Volopt__sub_800D8D88(void *, s32);
}
s32 get_gyaranzo_missile_int_parameter(s32 i);


#include "pso/unk/TLobby.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/enemy/dd/TObjEneDD.h"


#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"

#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/enemy/berura/TObjEneRe7Berura.h"


#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/object/ambient/TObjLight_80133568.h"

struct Obj_800D30A8 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xB4 - 0x34];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    Vec pos;
    Vec vel;
    u8 pad314[0x374 - 0x314];
    s32 f374;
    u8 pad378[0x37C - 0x378];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
};

extern "C" {



u8 *find_active_entity_by_id(u16);

extern s32 actor_frame_tick;

void TObjPlayer__sub_800D3314(u8 *arg0);

#define spawn_missile_volley__19TObjGyaranzoMissileFPv ((s32 (*)())spawn_missile_volley__19TObjGyaranzoMissileFPv)
void TObjPlayer__sub_800D30A8(Obj_800D30A8 *enemy);

typedef struct Ene_800D2E8C {
    u8 pad0[0x38C];
    s32 count;
    u8 pad390[0x3A8 - 0x390];
    s32 f3A8;
} Ene_800D2E8C;

typedef struct Ene_800D2F6C {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x38 - 0x28];
    f32 pos[3];
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    f32 v2FC[3];
    u8 pad308[0x33C - 0x308];
    s16 timer;
    u8 pad33E[0x37C - 0x33E];
    s32 state;
} Ene_800D2F6C;

struct Ene_800D2E8C;

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as MojaAnimationBinding).






s32 is_split_screen();















void TObjPlayer__sub_800D2E8C(Ene_800D2E8C *self);

void run_death_reaction__15TObjEneGyaranzoFv(u8 *arg0);

void run_hit_reaction__15TObjEneGyaranzoFv(u8 *arg0);

void TObjPlayer__sub_800D35D4(void);

void render__15TObjEneGyaranzoFv(u8 *arg0);

void run_task__15TObjEneGyaranzoFv(u8 *arg0);







void create_dead_spot__10TObjPlayerFllf(void *, s32, f32);


}

int initialize_enemy_photon_effect(void *p);

extern "C" {






s32 minimap_render_dot(void *, s32, s32, s32);






s32 post_translate_matrix(void *);

s32 draw_chunk_object(int);



extern saddr gyaranzo_boss_stats_handle;

extern saddr gyaranzo_boss_stats_ptr_b;

extern saddr gyaranzo_object_handle;

extern saddr gyaranzo_missile_param_table;

extern u32 *lbl_805D5200;

extern u32 *lbl_805D5204;

extern TUnk_8048FA00 *gyaranzo_breakup_model_obj;

extern s32 saved_model_render_flags;

extern s32 model_render_flags;

extern void *tl_04;


const char *bm_ene_gyaranzo_model_names[8] = {
    "me4_y_hahen01.nj", "me4_y_hahen02.nj", "me4_y_hahen03.nj", "me4_y_me4.nj",
    "me4_y_me4p.nj", "me4_y_mine.nj", "me4_y_missile.nj", NULL,
};

const char *bm_ene_gyaranzo_motion_names[9] = {
    "attack_me4_y_me4.njm", "damage01_me4_y_me4.njm", "damage02_me4_y_me4.njm", "deth_me4_y_me4.njm",
    "wait_me4_y_me4.njm", "walk01_me4_y_me4.njm", "walk02_me4_y_me4.njm", "walk03_me4_y_me4.njm",
    NULL,
};

BmlResourceDescriptor bm_ene_gyaranzo_resource_descriptor = {
    "bm_ene_gyaranzo.bml", bm_ene_gyaranzo_model_names, bm_ene_gyaranzo_motion_names, 7, 8,
};

const char *TObjEneGyaranzo__class_name = "TObjEneGyaranzo";

TObjMotionAction gyaranzo_action_table[8] = {
    {2, 0, 4, 0.7f, 0},
    {2, 5, 5, 0.7f, 1},
    {2, 0, 0, 1.0f, 4},
    {2, 0, 2, 0.8f, 8},
    {3, 4, 3, 1.0f, 0x10},
    {1, 5, 6, 0.7f, 1},
    {2, 0, 7, 0.8f, 1},
    {2, 0, 1, 1.0f, 8},
};

void *lbl_804941DC[7] = {
    (void *)0x43160000, (void *)0x3f0e38e3, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};

CollisionBody lbl_804941F8[1] = {
    {{0.0f, 18.0f, 0.0f}, 18.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

void *gyaranzo_resource_index_table[11] = {
    (void *)0x60007, (void *)0xa000b, (void *)0xc000f, (void *)0xe0009,
    (void *)0x80025, (void *)0x210036, (void *)0x2c0010, (void *)0x110012,
    (void *)0x130014, (void *)0x150016, (void *)0x170018,
};

void *gyaranzo_flagged_resource_index_table[7] = {
    (void *)0x20003, (void *)0x4000b, (void *)0xc0000, (void *)0x10005,
    (void *)0x60007, (void *)0x80009, (void *)0xa0000,
};

void *gyaranzo_death_breakup_params[7] = {
    (void *)0x14, (void *)0x3d75c28f, (void *)0x3fc00000, (void *)0x3f666666,
    (void *)0x3df5c28f, (void *)0x3f0ccccd, (void *)0x3f000000,
};


#define gyaranzo_death_breakup_params ((u8 *)gyaranzo_death_breakup_params)
#define gyaranzo_flagged_resource_index_table ((s16 *)gyaranzo_flagged_resource_index_table)
#define gyaranzo_resource_index_table ((s16 *)gyaranzo_resource_index_table)
saddr gyaranzo_boss_stats_handle;

saddr gyaranzo_boss_stats_ptr_b;

saddr gyaranzo_object_handle;

saddr gyaranzo_missile_param_table;

}
f32 lbl_805D51F0;

f32 TObjGyaranzoMissile__speed_scale;

f32 TObjGyaranzoMissile__max_range;

BmlResource *gyaranzo_bml_resource;
extern "C" {

u32 *lbl_805D5200;

u32 *lbl_805D5204;

TUnk_8048FA00 *gyaranzo_breakup_model_obj;

s32 gyaranzo_missile_volley_end_time;

TObjEneGyaranzo::TObjEneGyaranzo(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    s32 i;

    m_name = TObjEneGyaranzo__class_name;
    apply_set_data(set_data);
    VecCopy(&move_origin, VecCopy(&move_destination, &position));
    motion_list = gyaranzo_bml_resource->motions;
    action_table = gyaranzo_action_table;
    set_field_d8((saddr)action_table);
    init_collision_body_parts(this, lbl_804941F8, 1);
    variant = 0;
    movementParameters = (u8 *)lbl_804941DC;
    bind_enemy_combat_stats((u8 *)gyaranzo_boss_stats_handle, (u8 *)gyaranzo_boss_stats_ptr_b, (u8 *)gyaranzo_object_handle);
    init_params_from_table();
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    m_3b0 = hp / 3;
    m_38c = 0;
    m_3a8 = 0;
    m_3ac = 0;
    m_3b4 = 0;
    m_3b8 = 0;
    set_param(0x19);
    add_flags_2e4(4);
    update_prev_position();
    initialize_enemy_photon_effect(this);
    actorFlags |= 0x40000;
    model = gyaranzo_bml_resource->models[3].model;
    texlist = (saddr)gyaranzo_bml_resource->models[3].m_c;
    if (*(s16 *)((u8 *)set_data + 0xA) != 0) {
        sub_800C7860();
    }
    for (i = 0; i < 4; i++) {
        m_3ec[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneGyaranzo::~TObjEneGyaranzo() {
    free_collision_body_parts(this);
}

#pragma push
#pragma opt_propagation off
void TLobby::load_gyaranzo_resources() {
    s32 i;
    void *p;

    if (TObjEneDD::check_v2_mode() != 0) {
        gyaranzo_bml_resource = load_enemy_bml_resource_named(&bm_ene_gyaranzo_resource_descriptor, "bm_ene_gyaranzo_a.bml");
    } else {
        p = new BmlResource(5, &bm_ene_gyaranzo_resource_descriptor, 0, 0, NULL);
        gyaranzo_bml_resource = (BmlResource *)p;
    }
    for (i = 0; i < 0x16; i++) {
        ((s32 *)gyaranzo_model_resources)[i] = (s32)find_model_node((uaddr)gyaranzo_bml_resource->models[3].model, gyaranzo_resource_index_table[i]);
    }
    for (i = 0; i < 0xD; i++) {
        gyaranzo_resource_ptrs[i] = (u8 *)find_model_node((uaddr)gyaranzo_bml_resource->models[4].model, gyaranzo_resource_index_table[i]);
    }
    for (i = 0; i < 0xD; i++) {
        *(s32 *)((s8 *)gyaranzo_resource_ptrs[i] + 0x30) = 0;
    }
    (*(s32 *)&lbl_805D5200) = (s32)find_model_node((uaddr)gyaranzo_bml_resource->models[3].model, 0x19);
    (*(s32 *)&lbl_805D5204) = (s32)find_model_node((uaddr)gyaranzo_bml_resource->models[3].model, 0xD);
    p = new TUnk_8048FA00(gyaranzo_bml_resource->models[3].model, (NJS_MOTION *)get_bml_motion(gyaranzo_bml_resource, 3), 54.0f);
    gyaranzo_breakup_model_obj = (TUnk_8048FA00 *)p;
    gyaranzo_boss_stats_handle = (saddr)TLobby::register_boss(0x1D);
    gyaranzo_boss_stats_ptr_b = (saddr)TLobby::dispatch_shared_handler_b(0x1D);
    gyaranzo_object_handle = (saddr)TLobby::register_object(0x1D);
    gyaranzo_missile_param_table = (saddr)TLobby::dispatch_shared_handler_a(0x1D);
    {
        NpcAnimationBinding pos = { NULL, reinterpret_cast<TObjMotionAction *>(gyaranzo_action_table), 0, 1, 8 };
        pos.motions = gyaranzo_bml_resource->motions;
        NpcModelRegistry::register_animated_chunk(0x20, gyaranzo_bml_resource->models[3].model, gyaranzo_bml_resource->models[3].m_c, &pos, 18.0f, 0.0f);
        NpcModelRegistry::register_animated_chunk(0x21, gyaranzo_bml_resource->models[4].model, gyaranzo_bml_resource->models[3].m_c, &pos, 18.0f, 0.0f);
    }
}
#pragma pop

void TObjEneGyaranzo::free_static_instances() {
    if (gyaranzo_bml_resource != NULL) {
        delete gyaranzo_bml_resource;
        gyaranzo_bml_resource = NULL;
    }
    if (gyaranzo_breakup_model_obj != NULL) {
        delete gyaranzo_breakup_model_obj;
        gyaranzo_breakup_model_obj = NULL;
    }
}

void *TObjEneGyaranzo::create(void *set) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneGyaranzo(control, set);
}

void TObjEneGyaranzo::run_task() {
    s32 temp_r3;

    if (TObjPlayer::check_demo_mode() == 1) {
        ((s32 (*)(void *))TObjPlayer__sub_800D35D4)(this);
        return;
    }
    this->sub_800D37F4();
    temp_r3 = this->m_3b8;
    if (temp_r3 >= 0) {
        this->m_3b8 = (temp_r3 - 1);
    }
    if ((s16) this->mode != this->next_action) {
        if ((s32) this->state != -1) {
            this->state = -1;
            ((TObjPlayer *)((u8 *)this))->dispatch_state_update();
        }
        this->mode = (s16) this->next_action;
        this->state = 0;
    }
    ((TObjPlayer *)((u8 *)this))->dispatch_state_update();
    this->update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    submit_cursor_candidate(this, -1);
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
}

void TObjPlayer::dispatch_state_update() {
    u8 *self = (u8 *)this;
  s16 temp_r0;
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        ((TObjEnemyCustom *)self)->update_state();
        return;
      case 1:
        TObjPlayer__sub_800D3314((u8 *)((void *) self));
        return;
      case 2:
        ((TObjPlayer *)self)->update_aim_and_fire();
        return;
      case 4:
        TObjPlayer__sub_800D30A8((Obj_800D30A8 *)((void *) self));
        return;
      case 5:
        update_death_breakup();
        return;
      case 7:
        update__19TObjGyaranzoMissileFPv(self);
        return;
      case 9:
        TObjPlayer__sub_800D3314((u8 *)((void *) self));
        return;
      case 8:
        ((TObjEneGyaranzo *)self)->update_walk_to_target();
        break;
    }
  }
}

void TObjEneGyaranzo::sub_800D37F4() {
    s32 a;
    u16 r;
    switch (this->mode) {
    case 0:
    case 8:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            this->select_targets();
            if (*(s32 *)&this->unk_3CC > 0) {
                switch (*(s32 *)&this->m_3a8) {
                case 0:
                    if (this->hp <= *(s32 *)&this->m_3b0) {
                        this->targetId = this->m_3c8;
                        a = 9;
                    } else {
                        this->targetId = this->m_3c0;
                        a = 1;
                    }
                    if (this->targetId != 0xFFFF) {
                        update_if_active(a);
                        *(s32 *)&this->m_378 = 2;
                    }
                    break;
                case 1:
                    this->targetId = this->m_3c0;
                    if (this->targetId != 0xFFFF) {
                        update_if_active(9);
                        *(s32 *)&this->m_378 = 2;
                    }
                    break;
                case 2:
                    this->targetId = *(s32 *)((s8 *)((u8 *)this) + 0x3BC);
                    if (this->targetId != 0xFFFF) {
                        update_if_active(9);
                        *(s32 *)&this->m_378 = 2;
                    }
                    break;
                }
            } else if (this->is_actor_cadence_frame(0x1E) != 0 &&
                       xz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)(((u8 *)this) + 0x50)) > 100.0f) {
                update_if_active(8);
            }
        }
        break;
    case 1:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            f32 *p = *(f32 * *)&this->movementParameters;
            r = find_nearest_visible_player(this, NULL, 50.0f + *p);
            if (this->targetId == 0xFFFF) {
                this->targetId = r;
            }
            if (this->targetId == 0xFFFF) {
                update_if_active(8);
            }
        }
        break;
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneGyaranzo::render() {
    s32 temp_r3;
    saddr var_r30;
    s32 var_r29;
    if (!(this->actorFlags & 0x02000000)) {
        var_r30 = 0;
        if (is_split_screen() != 0) {
            var_r30 = TCameraCtrl::get_camera_mode();
        }
        var_r29 = 1;
        temp_r3 = this->classify_actor_view_detail(200.0f, 400.0f, 40.0f);
        if (temp_r3 != 0) {
            saved_model_render_flags = model_render_flags;
            var_r30 = (saddr)&m_3ec[var_r30];
            ((RenderFadeState *)var_r30)->update_fast();
            if (((RenderFadeState *)var_r30)->updateFromCamera((const f32*)(((u8 *)this) + 0x2FC)) != 0) {
                ((RenderFadeState *)var_r30)->set_flags_and_apply_damage_color();
                if (defer_render() != 0) {
                    model_render_flags = saved_model_render_flags;
                    return;
                }
            }
            TObjPlayer__sub_800D2E8C((Ene_800D2E8C *) (this));
            TObjFish::set_global_param(this->texlist);
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            rotate_matrix_y(0, this->rotation_y);
            if (TObjPlayer::check_demo_mode() == 1) {
                draw_chunk_object((int) (*(s32 *)((s8 *)((u8 *)this) + 0x34)));
            } else if (this->m_388 & 4) {
                if (m_3d0.has_visible_opacity() != 0) {
                    m_3d0.set_flags_and_apply_damage_color();
                    if (temp_r3 == 1) {
                        this->draw();
                    } else {
                        this->draw_motion_model();
                    }
                    m_3d0.clear_flag_and_notify();
                } else {
                    var_r29 = 0;
                }
            } else if (temp_r3 == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(this->actorFlags & 0x800) && (var_r29 != 0)) {
                Vec sp8 = {3.0f, 3.0f, 3.0f};
                this->TObjEnemy::draw_ground_shadow(&sp8, 0);
            }
            ((RenderFadeState *)var_r30)->clear_flag_and_notify();
        }
    }
}
#pragma pop

void TObjPlayer__sub_800D35D4(void) {  }

void TObjPlayer__sub_800D3314(u8 *arg0) {
    Vec v;
    u8 *p;
    *(u8 **)((s8 *)arg0 + 0x2A8) = find_active_entity_by_id(*(u16 *)((s8 *)arg0 + 0x338));
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        p = *(u8 **)((s8 *)arg0 + 0xA4);
        *(u32 *)((s8 *)p + 0x18) &= ~0x380000;
        *(u32 *)((s8 *)arg0 + 0x30) &= ~0x100;
        ((TObjEnemyCustom *)arg0)->sub_8004292C();
        *(f32 *)((s8 *)arg0 + 0x39C) = 0.0f;
        *(f32 *)((s8 *)arg0 + 0x3A4) = 0.0f;
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        if (*(s16 *)((s8 *)arg0 + 0x326) == 1) {
            *(f32 *)((s8 *)arg0 + 0x3A0) = get_gyaranzo_missile_float_parameter(0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x3A0) = 120.0f;
            (*(s32 *)((s8 *)arg0 + 0x3B4))++;
        }
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003B209)), arg0 + 0x38, 0, 0);
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        }
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        break;
    case 1:
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        } else {
            ((TObjEnemyCustom *)arg0)->run_idle_action();
            return;
        }
        ((TObjEnemy *)arg0)->enemy_turn_toward_dest(*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8));
        ((TObjEnemyCustom *)arg0)->move_along_ground_avoiding_walls(*(Vec *)((s8 *)arg0 + 0x390), *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4), *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0xC));
        *(f32 *)((s8 *)arg0 + 0x39C) += *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4);
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        if (*(s16 *)((s8 *)arg0 + 0x326) == 9) {
            *(f32 *)((s8 *)arg0 + 0x3A4) += *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4);
            if (*(f32 *)((s8 *)arg0 + 0x3A4) >= 20.0f) {
                *(f32 *)((s8 *)arg0 + 0x3A4) -= 20.0f;
                ((TObjEneGyaranzo *)arg0)->spawn_missile();
            }
        }
        if (!(actor_frame_tick & 3)) {
            ((TObjEnemyCustom *)arg0)->render_anim_model_at_pos();
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x1F, (Vec *)&v);
            spawn_particle_effect(&v, 0xF3);
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x27, (Vec *)&v);
            spawn_particle_effect(&v, 0xF3);
        }
        ((TObjPlayer *)arg0)->update_collisions();
        if (*(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0x18) & 0x380000) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        } else if (*(f32 *)((s8 *)arg0 + 0x39C) >= *(f32 *)((s8 *)arg0 + 0x3A0)) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        }
        break;
    case -1:
        ((TObjEnemyCustom *)arg0)->update_if_active(*(s32 *)((s8 *)arg0 + 0x378));
        break;
    }
}

void TObjEneGyaranzo::run_hit_reaction() {
    u8 *self = (u8 *)this;
  s32 temp_r0;
  unsigned long var_r3;
  if ((this->mode) != 4)
  {
    if (((s32)this->m_3b8) <= 0)
    {
      this->m_3b8 = 0x3C;
      ((TObjEneGyaranzo *)self)->sub_800D2A68();
    }
    temp_r0 = this->m_3a8;
    var_r3 = 0;
    switch (temp_r0)
    {
      case 0:
        var_r3 = (this->hp) <= ((this->hpmax) / 3);
        break;
      case 1:
        var_r3 = (this->hp) <= ((this->hpmax) / 4);
        break;
    }
    if (((s32) var_r3) != 0)
    {
      ((TObjEneGyaranzo *)self)->sub_800D2900();
    }
    this->referenceHp = this->hp;
    play_sound_effect(((TObjEnemy *)((void *) self))->remap_sound_for_area(0x4003AD0F), (u8 *)&this->position, 0, 0);
    if (!((this->m_388) & 0x40000))
    {
      ((TObjEnemyCustom *)self)->set_state(4);
      this->m_388 = (s32) ((this->m_388) | 1);
      return;
    }
    ((TObjBase *)self)->obj_clearFlags30(0x200200);
  }
}

void TObjPlayer__sub_800D30A8(Obj_800D30A8 *enemy) {
    switch (enemy->state) {
    case 0:
        enemy->f30 &= ~0x200000;
        enemy->fB8 = 3;
        enemy->state = 1;
    case 1: {
        ((TObjMotion *)enemy)->advance_animation();
        Vec v = enemy->pos;
        v.x += enemy->vel.x;
        v.z += enemy->vel.z;
        if (check_path_obstructed(enemy, &v) == 0) {
            move_with_wall_slide((u8 *)enemy);
        } else {
            enemy->vel.x = enemy->vel.z = 0.0f;
        }
        enemy->vel.x *= 0.5f;
        enemy->vel.z *= 0.5f;
        apply_actor_gravity((TObjEnemy *)enemy, (s32 *)(0), 0.0f);
        ((TObjPlayer *)enemy)->update_collisions();
        if (enemy->fB4 != 8) {
            enemy->state = -1;
        }
        break;
    }
    case -1:
        enemy->f30 &= ~0x200;
        enemy->f388 &= ~1;
        enemy->f374 = 1;
        break;
    }
}

void TObjEneGyaranzo::run_death_reaction() {
    u8 *self = (u8 *)this;
    ((TObjEnemyCustom *)self)->set_state(5);
    this->m_388 = (s32) (this->m_388 | 1);
}

void TObjPlayer::update_death_breakup() {
    Ene_800D2F6C *self = (Ene_800D2F6C *)this;
    switch (this->m_37c) {
    case 0:
        this->requested_action = 4;
        ((TObjPlayer *)self)->refresh_lobby_state();
        self->timer = 0x5A;
        create_dead_spot__10TObjPlayerFllf(self->v2FC, 0x5A, 20.0f);
        create_dead_spot__10TObjPlayerFllf(self->v2FC, 0x5A, 20.0f);
        this->m_37c = 1;
    case 1:
        ((TObjMotion *)self)->advance_animation();
        self->timer--;
        if (self->timer < 0) {
            TBoss3Volopt::create_breakup_mdl((saddr)gyaranzo_breakup_model_obj, (saddr)gyaranzo_death_breakup_params, (s32)this->texlist, (saddr)self->v2FC, (s32)this->rotation_y);
            ((TObjEnemy *)self)->send_entity_set_flags();
            ((TObjPlayer *)(self->v2FC))->trigger_dell_biter_events();
            play_sound_effect(((TObjEnemy *)(self))->remap_sound_for_area(0x4003AD10), self->pos, 0, 0);
            ((TObject *)self)->queue_destruction();
        }
        break;
    case -1:
        return;
    }
}

void TObjPlayer__sub_800D2E8C(Ene_800D2E8C *self) {
    s32 i;
    for (i = 0; i < self->count; i++) {
        *gyaranzo_model_resources[gyaranzo_flagged_resource_index_table[i]] |= 8;
    }
    for (; i < 13; i++) {
        *gyaranzo_model_resources[gyaranzo_flagged_resource_index_table[i]] &= ~8;
    }
    if (self->f3A8 >= 1) {
        *lbl_805D5200 |= 8;
        *lbl_805D5204 |= 8;
    } else {
        *lbl_805D5200 &= ~8;
        *lbl_805D5204 &= ~8;
    }
}

void TObjPlayer::update_aim_and_fire() {
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r30;
    u8 *temp_r6;
    void *uninit;
    switch (this->m_37c) {
    case 0:
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 0x40000);
        this->requested_action = 0;
        this->m_37c = 1;
    case 1:
        var_r30 = 0;
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            ((TObjEnemyCustom *)((u8 *)this))->find_target_in_range(300.0f);
        }
        temp_r6 = this->target;
        if (temp_r6 != NULL) {
            Vec v = *(Vec *)(temp_r6 + 0x38);
            subtract_vector(&v, (void *) (((u8 *)this) + 0x38));
            temp_r3 = ((TObjEnemy *)this)->turn_toward_direction((*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x350)) + 8)), (Vec *)&v);
            temp_r4 = temp_r3 >> 0x1F;
            if ((s32) ((temp_r4 ^ temp_r3) - temp_r4) < 0xE38) {
                var_r30 = 1;
            }
        } else {
            var_r30 = 1;
        }
        if (var_r30 != 0) {
            *(s16 *)&this->unk_33C = get_gyaranzo_missile_int_parameter(0);
            this->requested_action = 2;
            this->m_37c = 2;
        }
        break;
    case 2:
        if (this->frame >= 28.0f) {
            spawn_missile_volley__19TObjGyaranzoMissileFPv();
            this->m_37c = 3;
        }
        break;
    case 3:
        *(s16 *)&this->unk_33C = (s16) (*(s16 *)&this->unk_33C - 1);
        if (*(s16 *)&this->unk_33C <= 0) {
            this->m_37c = -1;
            ((TObjEnemyCustom *)uninit)->update_if_active(0);
        }
        break;
    case -1:
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 & 0xFFFBFFFF);
        break;
    }
    advance_animation();
    apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
    update_collisions();
}

#pragma push
#pragma fp_contract on
void TObjEneGyaranzo::spawn_missile() {
    Vec launch_position;
    s32 temp_r31;
    render_anim_model_at_pos();
    this->get_anim_node_position(0x18, &launch_position);
    temp_r31 = (s32) (182.04445f * ((240.0f * random_ratio()) - 120.0f));
    new TUnk_8049442C(this, &launch_position, rotation_y, temp_r31);
    spawn_particle_effect(&launch_position, 0xF3);
    play_sound_effect(this->remap_sound_for_area(0x4003B20D), &position, 0, 0);
}
#pragma pop

// Throws three chips of the body from 25 units above its position.
// pool_data off: each chip's initializer template is reached with its own lis/addi.
#pragma pool_data off
void TObjEneGyaranzo::sub_800D2A68() {
    Vec pos = position;
    pos.y += 25.0f;
    const TObjChipParams first = {
        {0.5f, 0.04f, 0.28f}, {pos.x, pos.y, pos.z}, {6.0f, 7.0f, 6.0f},
        {0x400, 0x100, 0x400}, {5, 50}, {position.y, 1.0f},
        (saddr)gyaranzo_bml_resource->models[0].model, (saddr)gyaranzo_bml_resource->models[0].m_c, 2,
    };
    const TObjChipParams second = {
        {0.5f, 0.04f, 0.2f}, {pos.x, pos.y, pos.z}, {5.5f, 6.5f, 5.5f},
        {0x400, 0x100, 0x400}, {4, 50}, {position.y, 1.0f},
        (saddr)gyaranzo_bml_resource->models[1].model, (saddr)gyaranzo_bml_resource->models[1].m_c, 2,
    };
    const TObjChipParams third = {
        {0.5f, 0.04f, 0.22f}, {pos.x, pos.y, pos.z}, {5.5f, 7.0f, 5.5f},
        {0x400, 0x100, 0x400}, {5, 50}, {position.y, 1.0f},
        (saddr)gyaranzo_bml_resource->models[2].model, (saddr)gyaranzo_bml_resource->models[2].m_c, 2,
    };

    new TObjChip((TObject *)tl_05, &first);
    new TObjChip((TObject *)tl_05, &second);
    new TObjChip((TObject *)tl_05, &third);
}
#pragma pool_data reset

void TObjEneGyaranzo::sub_800D2900() {
    s32 start;
    s32 end;
    s32 i;
    s32 idx;
    Vec v;
    void *obj;
    if (*(s32 *)&this->m_3a8 < 2) {
        (*(s32 *)&this->m_3a8)++;
        switch (*(s32 *)&this->m_3a8) {
        case 1:
            start = 0;
            *(s32 *)&this->m_38c = 5;
            end = 5;
            break;
        case 2:
            start = 5;
            *(s32 *)&this->m_38c = 0xD;
            end = 0xD;
            break;
        }
        render_anim_model_at_pos();
        for (i = start; i < end; i++) {
            idx = gyaranzo_flagged_resource_index_table[i];
            this->get_anim_node_position(gyaranzo_resource_index_table[idx], (Vec *)&v.x);
            {
                TObjChipParams p = {
                    {0.5f, 0.03f, 0.15f}, {0.0f, 0.0f, 0.0f}, {3.5f, 5.0f, 3.5f},
                    {0x400, 0x100, 0x400}, {3, 50}, {0.0f, 1.0f}, 0, 0, 2,
                };
                p.pos[0] = v.x;
                p.pos[1] = v.y;
                p.pos[2] = v.z;
                p.pad_38[0] = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
                p.model = ((s32 *)&gyaranzo_resource_ptrs)[idx];
                p.textures = (saddr)gyaranzo_bml_resource->models[3].m_c;
                obj = TObject::operator new(0x234);
                if (obj != NULL) {
                    __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)obj, tl_05, (u8 *)&p);
                }
            }
        }
    }
}

#undef spawn_missile_volley__19TObjGyaranzoMissileFPv
#define NEW(d, id) { new TObjGyaranzoMissile(arg0, (u8 *)&d, id); }
#pragma pool_data off
void spawn_missile_volley__19TObjGyaranzoMissileFPv(u8 *arg0) {
    Vec pos;
    s32 i;
    gyaranzo_missile_volley_end_time = get_gyaranzo_missile_int_parameter(1) + 0x96;
    ((TObjEnemyCustom *)arg0)->render_anim_model_at_pos();
    {
        Desc_800D23D4 d1 = { &pos, -0x1000, ((TObjEnemyCustom *)arg0)->rotation_y + 0x800, 1024.0f, 3.0f, 0.0f };
        Desc_800D23D4 d2 = { &pos, -0x2000, ((TObjEnemyCustom *)arg0)->rotation_y + 0x800, 2048.0f, 10.0f, 0.4f };
        Desc_800D23D4 d3 = { &pos, -0x1000, ((TObjEnemyCustom *)arg0)->rotation_y - 0x800, 1024.0f, 3.0f, 0.0f };
        Desc_800D23D4 d4 = { &pos, -0x2000, ((TObjEnemyCustom *)arg0)->rotation_y - 0x800, 2048.0f, 10.0f, 0.4f };
        u16 ids[4] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
        s32 idx[4] = { 0, 3, 1, 2 };
        for (i = 0; i < 4; i++) {
            ids[i] = *(s32 *)(arg0 + idx[i] * 4 + 0x3BC);
        }
        ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x10, &pos);
        NEW(d1, ids[0]);
        NEW(d2, ids[1]);
        spawn_particle_effect(&pos, 0xF3);
        ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x14, &pos);
        NEW(d3, ids[0]);
        NEW(d4, ids[1]);
        spawn_particle_effect(&pos, 0xF3);
        if (*(s32 *)((s8 *)arg0 + 0x3A8) >= 1) {
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x11, &pos);
            NEW(d1, ids[0]);
            NEW(d2, ids[1]);
            spawn_particle_effect(&pos, 0xF3);
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x15, &pos);
            NEW(d3, ids[2]);
            NEW(d4, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
        }
        if (*(s32 *)((s8 *)arg0 + 0x3A8) >= 2) {
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x12, &pos);
            NEW(d1, ids[0]);
            NEW(d2, ids[1]);
            spawn_particle_effect(&pos, 0xF3);
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x16, &pos);
            NEW(d3, ids[2]);
            NEW(d4, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x13, &pos);
            NEW(d1, ids[2]);
            NEW(d2, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
            ((TObjEnemyCustom *)arg0)->get_anim_node_position(0x17, &pos);
            NEW(d3, ids[2]);
            NEW(d4, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
        }
    }
    play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003AD0A), arg0 + 0x38, 0, 0);
}
#pragma pool_data reset

#undef NEW
#pragma push
#pragma scheduling off
void EnemyTargetCandidate::copy_from(const EnemyTargetCandidate *source) {
    id = source->id;
    distance_squared = source->distance_squared;
}
#pragma pop

void TObjEneGyaranzo::select_targets() {
    s32 count;
    s32 n;
    s32 best;
    s32 i;
    u8 *p;
    s32 j;
    s32 k;
    f32 dist;
    Vec d;
    u8 *self = (u8 *)this;
    TObjGyaranzoMissile_target_slots[0].id = 0xFFFF;
    TObjGyaranzoMissile_target_slots[0].distance_squared = 0.0f;
    n = 0;
    best = 0;
    k = ((TObjCollidable *)self)->obj_testFlags30(0x10);
    count = registered_player_count;
    if (k != 0) {
        count += registered_enemy_count;
    }
    for (i = 0; i < count; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)p) == 0) continue;
        if (p == self) continue;
        if (*(u32 *)((s8 *)p + 0x30) & 0x2000800) continue;
        VecCopy((Vec *)&d, (const Vec *)(p + 0x2FC));
        subtract_vector(&d, (u8 *)&this->body_center);
        dist = d.x * d.x + d.z * d.z;
        if (!(dist < 90000.0f)) continue;
        if (check_path_obstructed(self, p + 0x2FC) == 1) continue;
        TObjGyaranzoMissile_target_slots[n].distance_squared = dist;
        TObjGyaranzoMissile_target_slots[n].id = get_entity_id(p);
        if (n > 0 && TObjGyaranzoMissile_target_slots[n].distance_squared > TObjGyaranzoMissile_target_slots[best].distance_squared) {
            best = n;
        }
        n++;
        if (n >= 4) break;
    }
    {
        EnemyTargetCandidate def = { 0xFFFF, 0.0f };
        switch (n) {
        case 0:
            for (i = 0; i < 4; i++) {
                TObjGyaranzoMissile_target_slots[i].copy_from(&def);
            }
            break;
        case 2:
            for (i = n; i < 4; i++) {
                TObjGyaranzoMissile_target_slots[i].copy_from(&TObjGyaranzoMissile_target_slots[i % n]);
            }
            break;
        default:
            for (i = n; i < 4; i++) {
                TObjGyaranzoMissile_target_slots[i].copy_from(&TObjGyaranzoMissile_target_slots[best]);
            }
            break;
        }
    }
    *(s32 *)((s8 *)self + 0x3CC) = n;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (TObjGyaranzoMissile_target_slots[i].distance_squared > TObjGyaranzoMissile_target_slots[j].distance_squared) {
                EnemyTargetCandidate tmp;
                tmp.copy_from(&TObjGyaranzoMissile_target_slots[i]);
                TObjGyaranzoMissile_target_slots[i].copy_from(&TObjGyaranzoMissile_target_slots[j]);
                TObjGyaranzoMissile_target_slots[j].copy_from(&tmp);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        *(u32 *)(self + i * 4 + 0x3BC) = TObjGyaranzoMissile_target_slots[i].id;
    }
}

void update__19TObjGyaranzoMissileFPv(u8 *self) {
    s32 temp_r4;
    s32 temp_r5;

    switch (*(s32 *)((s8 *)self + 0x37C)) {
    case 0:
        *(s32 *)((s8 *)self + 0x388) = (s32) (*(s32 *)((s8 *)self + 0x388) | 4);
        temp_r4 = *(s32 *)((s8 *)self + 0x30) | 0x04000000;
        *(s32 *)((s8 *)self + 0x30) = temp_r4;
        ((TObjMotion *)self)->requested_action = 0;
        TBoss3Volopt__sub_800D8D88(self + 0x2FC, temp_r4);
        ((TObjEneGyaranzo *)self)->m_3d0.start_fade_in();
        *(s32 *)((s8 *)self + 0x37C) = 1;
    case 1:
        ((TObjMotion *)self)->advance_animation();
        if (((TObjEneGyaranzo *)self)->m_3d0.advance_toward_max() == 1) {
            *(s32 *)((s8 *)self + 0x37C) = -1;
        }
        return;
    case -1:
        temp_r5 = *(s32 *)((s8 *)self + 0x388);
        *(s32 *)((s8 *)self + 0x388) = (s32) (temp_r5 & ~5);
        *(s32 *)((s8 *)self + 0x30) = (s32) (*(s32 *)((s8 *)self + 0x30) & 0xFBFFFFFF);
        ((TObjEnemyCustom *)self)->update_if_active(0);
        break;
    }
}

void TObjEneGyaranzo::init_params_from_table() {
    *(f32 *)((s8 *)this->movementParameters + 4) = get_gyaranzo_missile_float_parameter(1);
    lbl_805D51F0 = get_gyaranzo_missile_float_parameter(2);
    TObjGyaranzoMissile__speed_scale = get_gyaranzo_missile_float_parameter(3);
    TObjGyaranzoMissile__max_range = get_gyaranzo_missile_float_parameter(4);
}

// Mode 8: walk back to home_position, then resume through update_if_active.
void TObjEneGyaranzo::update_walk_to_target() {
    switch ((s32)state) {
    case -1:
        break;
    case 0:
        bodies->flags &= ~0x380000;
        actorFlags &= ~0x100;
        requested_action = 1;
        VecCopy(&move_destination, &home_position);
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        VecCopy(&move_origin, &body_center);
        calc_velocity_toward_destination(this, move_origin, move_destination, ((EnemyMoveParams *)movementParameters)->min_distance);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        move_with_wall_slide((u8 *)this);
        ((TObjPlayer *)(u8 *)this)->update_collisions();
        if (xz_distance_squared(&position, &home_position) <= 100.0f) {
            update_if_active(0);
        }
        break;
    }
}

}

s32 TObjEneGyaranzo::update_shock_clock() {
    if (TObjChara::update_shock_clock() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}

s32 TObjEneGyaranzo::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}

void TObjEneGyaranzo::clear_flag_and_update() {
    if (next_action == 7) {
        m_388 &= ~1;
        update_if_active(0);
    }
}
