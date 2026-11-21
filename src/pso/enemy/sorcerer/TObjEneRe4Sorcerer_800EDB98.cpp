#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"

#include "pso/object/base/TObjChara.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"

#include "pso/render/RenderFadeState.h"

#include "pso/system/task/TObject.h"

#include "pso/unk/TLobby.h"

#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer.h"

#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

#include "pso/player/TObjPlayer_800D8FDC.h"

#include "pso/system/vector.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/math/AngleLookup.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/player/TObjPlayer_80011014.h"

extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *);

#include "types.h"
#include "pso/system/AreaSound.h"

#include "pso/map/FloorArea.h"

#include "pso/system/BmlResource.h"

#include "pso/system/BmlResourceDescriptor.h"

#include "pso/math/AngleUnits.h"

extern "C" void has_flag_0x800__9TObjCharaFv();

extern "C" void test_flag30_512__9TObjCharaFv();

extern "C" void test_flag_1000__9TObjCharaFv();

extern "C" void test_flag_256__9TObjCharaFv();

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/enemy/sorcerer/TObjEneRe4Bit.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/render/TUnk_80490470.h"
extern "C" {


s32 post_translate_matrix(void *);

s32 TObjEneRe4Sorcerer__sub_801E3F1C(f32, f32);

s32 scroll_strip_uvs(int, int, int);

s32 translate_matrix(int, f32, f32, f32);


extern uaddr TObjEneRe4Sorcerer__uv_scroll_buffer;

extern s32 model_render_flags;

void TObjEneRe4Sorcerer__sub_800EFE30(void);
}

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"

#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/item/armor/TItemProShield.h"

#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecGiZonde.h"

#include "pso/technique/TTecGrants.h"

#include "pso/technique/TTecMegid.h"

#include "pso/technique/TTecRaFoie.h"

#include "pso/technique/TTecResta.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
extern "C" {
void TObjEneRe4Sorcerer__sub_800EF214(TObjEneRe4Sorcerer *self);


void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *arg0, s32 arg1);

extern s32 TObjEneRe4Sorcerer__render_node_index;

extern s32 TObjEneRe4Sorcerer__saved_render_flags;

extern f32 TObjEneRe4Sorcerer__effect_render_scale;

extern s32 re4_sorcerer_render_node_ptr;

extern s32 saved_model_render_flags;

extern const f32 lbl_805D9E84;

extern const f32 lbl_805D9E88;


u16 get_entity_id(TObjBase *object);

s32 *csnLookAt(s32 arg0, s32 arg1);

s32 enemy_bind_or_clear_target(void *, u16);


int is_target_ranger(void *p);

f32 horizontal_distance_squared(void *, void *);

void scale_matrix(s32, s32, f32, f32, f32);


s32 TObjPlayer__sub_800A04F0(void *);

void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);

void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);

int TObjEneDD__sub_800BA804(u16 arg0);




void TObjEneRe4Bit__sub_800EDAB0(void);

void TObjEneRe4Bit__sub_800EDAB4();

void TObjEneRe4Sorcerer__sub_800EE0F8(TObjEneRe4Sorcerer *self, s32 arg1);

void TObjEneRe4Sorcerer__sub_800EE1CC(TObjEneRe4Sorcerer *self, s32 arg1);

void TObjEneRe4Sorcerer__sub_800EEC00(TObjEneRe4Sorcerer *self, s32 arg1);

void TObjEneRe4Sorcerer__sub_800EEDE4(TObjEneRe4Sorcerer *self, s32 arg1);

void TObjEneRe4Sorcerer__sub_800EEFE4(TObjEneRe4Sorcerer *self, s32 arg1);

void TObjEneRe4Sorcerer__sub_800EF7C8(TObjEneRe4Sorcerer *self);

void TObjEneRe4Sorcerer__sub_800EF844(TObjEneRe4Sorcerer *self);

void TObjEneRe4Sorcerer__sub_800EF95C(TObjEneRe4Sorcerer *self, f32 speed);









void TBoss3Volopt__sub_800F059C(void);
}

void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);

s32 tick_period_counter(s32 arg0, s32 *arg1, s32 arg2);

void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {
s32 approach_angle_limited(s32, s32, s32);

s32 free_collision_body_parts(void *);

s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);

s32 play_sound_effect(void *, void *, int, int);

void __dl__7TObjectFPv(void *);

void __destroy_arr(void *, void *, u32, u32);

void __construct_array(void *, void *, void *, int, int);

void vec3_add_to(void *, void *);

s32 subtract_vector(void *, void *);

extern s32 __dt__15RenderFadeStateFv[];

extern s32 __ct__15RenderFadeStateFv[];

Vec lbl_80501070;

extern saddr lbl_805D52D0;

extern saddr TObjEneRe4Sorcerer__attack_params;

extern saddr TObjEneRe4Sorcerer__resistance_params;

extern s32 *sorcerer_behavior_params;

extern BmlResource *sorcerer_bml_resource;

extern void *tl_04;

void vfunc_6__8TObjBaseFPsl();

void snap_to_ground_at__9TObjEneDDFPUc();

void apply_enemy_state__9TObjEneDDFPl();

void update_immobilizing_statuses__9TObjEneDDFv();

void update_action_state__9TObjEneDDFv();

void has_action_state_changed__9TObjEneDDFv();

void check_collisions__9TObjEneDDFv();

void vfunc_90__9TObjEneDDFv();

void set_invulnerable__9TObjEneDDFv();

void clear_invulnerable__9TObjEneDDFv();

void enable_body_collision__9TObjEneDDFv();

void disable_body_collision__9TObjEneDDFv();

void set_intangible__9TObjEneDDFv();

void clear_intangible__9TObjEneDDFv();

void set_colliders_contact_high__9TObjEneDDFv();

void set_colliders_contact_low__9TObjEneDDFv();

void is_confused__9TObjEneDDFv();

void render_minimap_dot__9TObjEneDDFv();

int acquire_target__12TObjEneDD_STFf(void *p);

void update_status_effects__12TObjEneDD_STFv();

void has_no_target__9TObjCharaFv();

void recalc_stats__9TObjCharaFv();

void consume_timer_field__9TObjCharaFl();

void deliver_attack_hits__9TObjCharaFf();

void vfunc_66__9TObjCharaFv();

void get_anim_node_position__9TObjCharaFlP3Vec();

void run_attack_action__9TObjCharaFv();

void run_move_action__9TObjCharaFv();

void run_idle_action__9TObjCharaFv();

void apply_slow_status__9TObjCharaFv();

void update_shock_clock__9TObjCharaFv();

void vfunc_43__9TObjCharaFv();

void vfunc_18__9TObjCharaFPUc();

void interact__14TObjCollidableFl();

void vfunc_74__9TObjEnemyFl();

void apply_hit_message_flags__9TObjEnemyFPv();

void add_actor_exp__9TObjCharaFl();

void apply_action_hold_status__9TObjCharaFf();

void apply_anti_technique__9TObjCharaFl();

void apply_attack_stat_status__9TObjCharaFPv();

void apply_confusion_status__9TObjCharaFv();

void apply_knockback_from_attacker__9TObjCharaFPUcf();

void apply_movement_ailment__9TObjCharaFl();

void apply_object_set_data__8TObjBaseFPv();

void apply_paralysis__9TObjCharaFv();

void apply_poison_status__9TObjCharaFv();

void apply_set_data__9TObjEnemyFPv();

void apply_shock_status__9TObjCharaFv();

void apply_switch_attack__9TObjCharaFv();

void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();

void classify_actor_view_detail__8TObjBaseFfff();

void clear_all_status_effects__9TObjCharaFv();

void clear_harmful_statuses__9TObjCharaFv();

void cure_paralysis__9TObjCharaFv();

void cure_poison_ailment__9TObjCharaFv();

void enemy_spawn_jellen_effect__9TObjCharaFv();

void enemy_spawn_zalure_effect__9TObjCharaFv();

void vfunc_78__9TObjCharaFl();

void gain_photon_blast_chain_charge__9TObjCharaFv();

void spend_photon_blast_charge__9TObjCharaFf();

void gain_photon_blast_charge__9TObjCharaFf();

void clear_lobby_object_state__9TObjEnemyFv();

void get_center__9TObjCharaFv();

void get_actor_level_index__9TObjCharaFv();

void get_name__9TObjEnemyFv();

void get_pos__9TObjCharaFl();

void is_actor_cadence_frame__9TObjCharaFl();

void is_target_in_attack_range__9TObjCharaFv();

void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();

void receive_physical_attack__9TObjCharaFPvf();

void receive_weapon_special_attack__9TObjCharaFPvPv();

void apply_defense_stat_status__9TObjCharaFPv();

void render_shadows__9TObjEnemyFv(u8 *arg0);

void reset_motion_fields__9TObjCharaFv();

void reset_pose__9TObjCharaFv();

void roll_physical_accuracy__9TObjCharaFPvlf();

void select_melee_contact_body__9TObjCharaFPvf();

void trigger_switch_attack__9TObjCharaFv(s32 arg0);

void try_start_action__9TObjCharaFll();

void update_action_hold_status__9TObjCharaFv();

s32 update_slow_status__9TObjCharaFv(u8 *arg0);

void update_actor_ground_y__9TObjCharaFv();

s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);

s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);

void update_flag30_timer__9TObjCharaFv();

void update_movement_status__9TObjCharaFv();

void update_object_view_visibility__8TObjBaseFff();

void update_poison_status__9TObjCharaFv();

TObjEneRe4InitParams re4_sorcerer_init_params = {225.0f, 0.0f, 0x600};

void *re4_sorcerer_collision_body_part_table[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};

const char *bm_ene_re4_sorcerer_model_names[3] = {
    "re4_b_sorcer_body.nj",
    "re4_b_bit.nj",
    NULL
};

const char *bm_ene_re4_sorcerer_motion_names[9] = {
    "attack2_re4_b_body.njm",
    "attack3_re4_b_body.njm",
    "attack1_re4_b_body.njm",
    "cure_re4_b_body.njm",
    "damage_re4_b_body.njm",
    "die_re4_b_body.njm",
    "enter_re4_b_body.njm",
    "wait_re4_b_body.njm",
    NULL
};

BmlResourceDescriptor bm_ene_re4_sorcerer_resource_descriptor = {
    "bm_ene_re4_sorcerer.bml", bm_ene_re4_sorcerer_model_names, bm_ene_re4_sorcerer_motion_names, 2, 8
};

void *re4_sorcerer_action_params[32] = {
    (void *)0x10000, (void *)0x7, (void *)0x3f19999a, (void *)0x0,
    (void *)0x20002, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f19999a, (void *)0x80000000,
    (void *)0x30000, (void *)0x1, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x6, (void *)0x3f19999a, (void *)0x80000000,
};

// inferred: TObjEneRe4Sorcerer__name, from the string it holds (the ctor stores it as the object's m_name).
const char *TObjEneRe4Sorcerer__name = "TObjEneRe4Sorcerer";

const NpcAnimationBinding re4_sorcerer_spawn_descriptor = { NULL, reinterpret_cast<TObjMotionAction *>(re4_sorcerer_action_params), 0, 0, 8 };
}

#define re4_sorcerer_collision_body_part_table ((f32 *)re4_sorcerer_collision_body_part_table)
extern "C" {
saddr lbl_805D52D0;

saddr TObjEneRe4Sorcerer__attack_params;

saddr TObjEneRe4Sorcerer__resistance_params;

s32 *sorcerer_behavior_params;

BmlResource *sorcerer_bml_resource;

s32 TObjEneRe4Sorcerer__render_node_index;

s32 TObjEneRe4Sorcerer__saved_render_flags;

f32 TObjEneRe4Sorcerer__effect_render_scale;

s32 re4_sorcerer_render_node_ptr;

uaddr TObjEneRe4Sorcerer__uv_scroll_buffer;

void TBoss3Volopt__sub_800F059C(void) {  }

void TObjEneRe4Sorcerer::load_resources() {
    uaddr r;
    lbl_80501070.x = 0.0f;
    lbl_80501070.y = 0.0f;
    lbl_80501070.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        sorcerer_bml_resource = (BmlResource *)load_enemy_bml_resource_named(&bm_ene_re4_sorcerer_resource_descriptor, "bm_ene_re4_sorcerer_a.bml");
    } else {
        sorcerer_bml_resource = (BmlResource *)load_enemy_bml_resource(&bm_ene_re4_sorcerer_resource_descriptor);
    }
    lbl_805D52D0 = (saddr)TLobby::register_boss(0xA);
    TObjEneRe4Sorcerer__attack_params = (saddr)TLobby::dispatch_shared_handler_b(0xA);
    TObjEneRe4Sorcerer__resistance_params = (saddr)TLobby::register_object(0xA);
    sorcerer_behavior_params = (s32 *)TLobby::dispatch_shared_handler_a(0xA);
    TObjEneRe4Sorcerer__render_node_index = 0;
    TObjEneRe4Sorcerer__saved_render_flags = 0;
    TObjEneRe4Sorcerer__effect_render_scale = 0.0f;
    re4_sorcerer_render_node_ptr = 0;
    TObjEneRe4Bit__sub_800EDAB4();
    r = (u32) (saddr)::operator new(0x14);
    if (r != 0) {
        r = (uaddr) ((TLobby *)r)->alloc_tables((saddr)sorcerer_bml_resource->models->model, 2);
    }
    TObjEneRe4Sorcerer__uv_scroll_buffer = r;
    NpcAnimationBinding p = re4_sorcerer_spawn_descriptor;
    p.motions = reinterpret_cast<BmlMotionEntry *>(sorcerer_bml_resource->motions);
    NpcModelRegistry::register_animated_chunk((s16)0x2A, reinterpret_cast<void *>(sorcerer_bml_resource->models->model), reinterpret_cast<void *>(sorcerer_bml_resource->models->m_c), &p, re4_sorcerer_collision_body_part_table[3], 15.0f);
}

TObjEneRe4Sorcerer *TObjEneRe4Sorcerer::create() {
    return new TObjEneRe4Sorcerer((TObject *)tl_04, this);
}

void TObjEneRe4Sorcerer::free_bits() {
    if ((u32) TObjEneRe4Sorcerer__uv_scroll_buffer != 0U) {
        destroy_buffer_pair((void *)TObjEneRe4Sorcerer__uv_scroll_buffer, 1);
        TObjEneRe4Sorcerer__uv_scroll_buffer = 0U;
    }
    TObjEneRe4Bit__sub_800EDAB0();
    if ((uaddr) sorcerer_bml_resource != 0U) {
        delete (BmlResource *)sorcerer_bml_resource;
        sorcerer_bml_resource = 0U;
    }
}

TObjEneRe4Sorcerer::TObjEneRe4Sorcerer(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    m_name = TObjEneRe4Sorcerer__name;
    invoke_initialization_hook(set_data);
    ((void (*)(void *))TObjEneRe4Sorcerer__sub_800EFE30)(this);
    init_enemy();
}
}

#pragma push
#pragma opt_loop_invariants off
extern "C" {
void TObjEneRe4Sorcerer::init_enemy() {
    s32 i;
    u16 id;
    s32 t;
    s32 n;
    BmlModelEntry *models;

    init_position_vectors();
    model = (void *)sorcerer_bml_resource->models->model;
    models = sorcerer_bml_resource->models;
    texlist = (saddr)models->m_c;
    this->init_model((CollisionBody *)re4_sorcerer_collision_body_part_table, 1);
    set_field_d8((saddr)re4_sorcerer_action_params);
    set_field_dc((saddr)sorcerer_bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp((u8 *)lbl_805D52D0, (u8 *)TObjEneRe4Sorcerer__attack_params, (u8 *)TObjEneRe4Sorcerer__resistance_params);
    set_state_8();
    movementParameters = &re4_sorcerer_init_params;
    initialize_enemy_state(0x1F);
    wall_reach = 15.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    set_active();
    mode = 0;
    dispatch_action(mode, 4);
    m_3c0 = 0;
    m_3c4 = 0.0f;
    m_3c8 = 0;
    m_3c8 &= ~2;
    for (i = 0; i < 2; i++) {
        VecCopy(&bit_anchors[i], &position);
    }
    id = entity_id + 1;
    n = set_index + 1;
    bit_ids[0] = id;
    create_disabled(&bit_anchors[0], id++, n++);
    bit_ids[1] = id;
    create_enabled(&bit_anchors[1], id, n);
    m_3e8 = 0;
    m_3ec = 0;
    m_3f0 = 0;
    m_3f4 = m_2cc;
    m_3f8 = 1.0f;
    fade.reset_obstruction_fade();
    clear_target_cursor_list(&targets);
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    TObjEneRe4Sorcerer__sub_800EF844(this);
}
}

#pragma pop
extern "C" {
TObjEneRe4Sorcerer::~TObjEneRe4Sorcerer() {
    s32 i;
    void *p;
    for (i = 0; i < 2; i++) {
        if ((p = find_entity_by_id(bit_ids[i])) != NULL) {
            ((TObject *)p)->queue_destruction();
        }
        bit_ids[i] = 0xFFFF;
    }
    free_collision_body_parts(this);
}

void TObjEneRe4Sorcerer::run_task() {
    s32 i;
    void *p;
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    if (update_status_effects() != 4) {
        if (TObjEneDD__sub_800BA804(target_id) != 0 && find_entity_by_id(target_id) == NULL) {
            ((TObjEneDD_ST *)(this))->enemy_clear_target();
        }
        update_action_state();
        calc_orb_positions();
        m_3c0 += 5;
        m_3c0 = (u8)m_3c0;
        m_3c4 += 0.01f;
        if (m_3c4 >= 1.0f) {
            m_3c4 -= 1.0f;
        }
    } else {
        for (i = 0; i < 2; i++) {
            if ((p = find_entity_by_id(bit_ids[i])) != NULL) {
                ((TObjEneRe4Bit *)p)->set_flag3cc_bit2000();
            }
        }
    }
    update_collision_center();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneRe4Sorcerer::refresh_target() {  }

void TObjEneRe4Sorcerer::run_death_reaction() {
    if (mode != 9) {
        transition_enemy_state(9);
    }
}

void TObjEneRe4Sorcerer::run_hit_reaction() {
    if (mode != 8) {
        if (!(m_3c8 & 8)) {
            transition_enemy_state(8);
            return;
        }
        clear_attack_receipts();
    }
}

void TObjEneRe4Sorcerer::run_miss_reaction() {  }

void TObjEneRe4Sorcerer::update_collision_center() {
    body_center.x = position.x;
    body_center.y = 22.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}

void TObjEneRe4Sorcerer::update_body_colliders() {
    bodies->offset.y = 22.0f;
}

void TObjEneRe4Sorcerer__sub_800EFE30(void) {  }

u8 *TObjEneRe4Sorcerer::move_xz_on_ground(u8 *dest) {
    u8 *ground = TObjEneDD::move_xz_on_ground(dest);
    if (ground == NULL) {
        this->m_3c8 &= ~0x10;
    } else {
        this->m_3c8 |= 0x10;
    }
    return ground;
}

u8 *TObjEneRe4Sorcerer::update_ground_contact() {
    u8 *ground = TObjEneDD::update_ground_contact();
    if (ground == NULL) {
        this->m_3c8 &= ~0x10;
    } else {
        this->m_3c8 |= 0x10;
    }
    return ground;
}
}

#pragma push
#pragma opt_loop_invariants off
extern "C" {
s32 TObjEneRe4Sorcerer::select_attack_target(f32 farg0, f32 farg1) {
    f32 d;
    f32 best;
    s32 id;
    TObjChara *p;
    s32 n;
    int i;
    void *o1;
    void *o2;
    if (this->is_confused() != 0) {
        best = farg1;
        id = 0xFFFF;
        o1 = find_entity_by_id(this->bit_ids[0]);
        o2 = find_entity_by_id(this->bit_ids[1]);
        p = (TObjChara *)TLobby::get_game_mode();
        n = (saddr)p + TObjEneDD::get_enemy_count();
        for (i = (saddr)p; i < n; i++) {
            p = (TObjChara *)TObjPlayer::get_player_data(i);
            if (p != this && p != o1 && p != o2 && ((TObjBase *)p)->is_alive() != 0) {
                d = horizontal_distance_squared(&this->body_center, &p->position);
                if (d < best && csnLookAt((saddr)&this->body_center, (saddr)&p->body_center) == 0) {
                    id = ((s32 (*)(void *))get_entity_id)(p);
                    best = d;
                }
            }
        }
        if (((s32 (*)(void *, s32))enemy_bind_or_clear_target)(this, id) != 0) {
            return 1;
        }
    }
    {
    TObjChara *q; s32 tA; s32 tB; s32 j; s32 m; f32 e;
    tA = 0xFFFF;
    tB = tA;
    m = TLobby::get_game_mode();
    for (j = 0; j < m; j++) {
        q = (TObjChara *)TObjPlayer::get_player_data(j);
        if (((TObjBase *)q)->is_alive() != 0) {
            e = horizontal_distance_squared(&this->body_center, &q->body_center);
            if (is_target_ranger(q) != 0) {
                if (e < farg0 && is_target_unobstructed_from((TObjEneDD *)this, (TObjChara *)q) != 0) {
                    farg0 = e;
                    tA = ((s32 (*)(void *))get_entity_id)(q);
                }
            } else if (e < farg1 && is_target_unobstructed_from((TObjEneDD *)this, (TObjChara *)q) != 0) {
                farg1 = e;
                tB = ((s32 (*)(void *))get_entity_id)(q);
            }
        }
    }
    if ((u16)tA != 0xFFFF) {
        ((void (*)(void *, s32))enemy_set_target_id)(this, tA);
        return 1;
    }
    if ((u16)tB != 0xFFFF) {
        ((void (*)(void *, s32))enemy_set_target_id)(this, tB);
        return 1;
    }
    }
    ((TObjEneDD_ST *)(this))->enemy_clear_target();
    return 0;
}
}

#pragma pop
extern "C" {
s32 TObjEneRe4Sorcerer::try_attack(f32 farg0, f32 farg1) {
    if (tick_period_counter((saddr)this, &acquire_counter, 0x1E) != 0) {
        return select_attack_target(farg0, farg1);
    }
    if (enemy_has_live_target() != 0) {
        return 1;
    }
    ((TObjEneDD_ST *)(this))->enemy_clear_target();
    return 0;
}

void TObjEneRe4Sorcerer__sub_800EF95C(TObjEneRe4Sorcerer *self, f32 speed) {
    s32 i;
    Vec out;
    Vec v;
    Vec t;
    TObjEneRe4Bit *bit;
    self->enemy_copy_target_destination();
    self->update_velocity();
    v.x = speed * sin_table_lookup(self->m_3f0);
    v.y = 0.0f;
    v.z = speed * cos_table_lookup(self->m_3f0);
    vec3_add_to(&v, &self->destination);
    subtract_vector(&v, &self->position);
    speed = normalize_vector_xz(&v);
    calc_wall_clamped_destination(self, &out, v.x, v.z, speed);
    t.x = out.x;
    t.y = 10.0f + out.y;
    t.z = out.z;
    if (csnVectorUnder(&t, (CsnGroup **)&self->m_120, 0xE0) == 0) {
        VecCopy(&self->position, &out);
    }
    self->update_ground_contact();
    VecCopy(&self->prev_position, &self->position);
    self->update_collision_center();
    self->rotation_y = self->m_3f0 + 0x8000;
    self->calc_orb_positions();
    self->m_3f0 += 0x2AAA;
    self->transform_part_positions();
    for (i = 0; i < 2; i++) {
        bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
        if (bit != NULL) {
            bit->reset_transform();
        }
    }
}

void TObjEneRe4Sorcerer::set_motion_by_state() {
    if (this->m_3e8 != 2) {
        this->transition_enemy_state(5);
        return;
    }
    this->transition_enemy_state(7);
}

void TObjEneRe4Sorcerer::request_death_effect() {
    if (m_3e8 != 2) {
        transition_enemy_state(4);
        return;
    }
    transition_enemy_state(6);
}

void TObjEneRe4Sorcerer::advance_anim_frame() {
    m_3e8 = m_3e8 + 1;
    if (m_3e8 >= 3) {
        m_3e8 = 0;
    }
}

void TObjEneRe4Sorcerer__sub_800EF844(TObjEneRe4Sorcerer *self) {
    s32 i;
    self->set_invulnerable();
    self->disable_body_collision();
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
        if (bit != NULL) {
            bit->invoke_state_callbacks();
        }
    }
}

void TObjEneRe4Sorcerer__sub_800EF7C8(TObjEneRe4Sorcerer *self) {
    s32 i;
    self->clear_invulnerable();
    self->enable_body_collision();
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
        if (bit != NULL) {
            bit->call_vt_90_91();
        }
    }
}

s32 TObjEneRe4Sorcerer::check_shield(TObjChara *target) {
    if (TObjEneDD::check_v2_mode() != 0) {
        return target->hp < ((TItemProShield *)target)->get_field_2b8();
    }
    return target->hp < (((TItemProShield *)target)->get_field_2b8() / 4);
}

s32 TObjEneRe4Sorcerer::update_farthest_target(saddr item_pro_shield, f32 *arg2) {
    f32 temp_f1;
    if (((TObjChara *)item_pro_shield)->is_alive() != 0 && check_shield((TObjChara *)item_pro_shield) != 0) {
        temp_f1 = horizontal_distance_squared(&position, &((TObjChara *)item_pro_shield)->position);
        if ((temp_f1 <= 40000.0f) && (temp_f1 > *arg2)) {
            *arg2 = temp_f1;
            target_id = get_entity_id((TObjChara *)item_pro_shield);
            current_target = (TObjChara *)item_pro_shield;
            return 1;
        }
    }
    return 0;
}

void TObjEneRe4Sorcerer::set_photon_state() {
    TObjEneRe4Bit *bit;
    if (m_3e8 == 0) {
        bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            bit->set_state_flag_and_mode(0);
        }
    } else {
        bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            bit->set_state_flag_and_mode(1);
        }
    }
}

void TObjEneRe4Sorcerer::apply_mylla_effect() {
    TObjEneRe4Bit *bit;
    bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[1]);
    if (bit != NULL) {
        bit->set_state_flag_and_mode(2);
    }
}

void TObjEneRe4Sorcerer::calc_orb_positions() {
    f32 temp_f2;
    f32 temp_f31;

    temp_f31 = 15.0f * cos_table_lookup(rotation_y);
    temp_f2 = 15.0f * -sin_table_lookup(rotation_y);
    bit_anchors[1].x = position.x + temp_f31;
    bit_anchors[1].y = 18.0f + position.y;
    bit_anchors[1].z = position.z + temp_f2;
    bit_anchors[0].x = position.x - temp_f31;
    bit_anchors[0].y = 18.0f + position.y;
    bit_anchors[0].z = position.z - temp_f2;
}

void TObjEneRe4Sorcerer::turn_to_target() {
    enemy_copy_target_destination();
    update_velocity();
    rotation_y = approach_angle_limited(rotation_y, (saddr)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z)), 0xA00);
}

s32 TObjEneRe4Sorcerer::cast_technique() {
    Vec v;
    s32 frame;
    Vec *src;
    if (is_target_unobstructed_from((TObjEneDD *)this, current_target) != 0) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            src = bit->get_spell_data();
        } else {
            src = &position;
        }
        if (m_3e8 == 0) {
            clear_target_cursor_list(&targets);
            targets.count = 1;
            targets.records[0].id = get_entity_id(current_target);
            targets.records[0].flag = 0;
            if (TObjEneDD::check_v2_mode() != 0) {
                TTecGrants::create(this, src, &targets, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            } else if (TLobby::get_instance() == 1) {
                TTecGiZonde::create(this, src, &targets, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            } else {
                TTecRaFoie::create_ex(this, src, &targets, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            }
        } else if (TObjEneDD::check_v2_mode() != 0) {
            TTecMegid::create((saddr)this, (saddr)src, (saddr)&current_target->position, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[7]));
        } else {
            VecCopy(&v, &current_target->position);
            subtract_vector(&v, src);
            frame = TObjEneDD::clamp_frame_index(sorcerer_behavior_params[7]);
            TTecGiBarta::create_ex(this, src, (s32)(RADIANS_TO_ANGLE * atan2_float(v.x, v.z)), frame);
        }
        return 1;
    }
    return 0;
}

s32 TObjEneRe4Sorcerer::cast_resta() {
    Vec *spell_data;

    if (current_target->is_alive() != 0) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            spell_data = bit->get_spell_data();
        } else {
            spell_data = &position;
        }
        TTecResta::create(this, spell_data, (void *)TObjEneDD::clamp_frame_index(sorcerer_behavior_params[8]));
        return 1;
    }
    return 0;
}

void TObjEneRe4Sorcerer::create_effect() {
    if (m_3e8 == 0) {
        play_persistent_sound(remap_sound_for_area(0x4003A812), (saddr)this, (uaddr)&position, 0, 0);
        return;
    }
    play_persistent_sound(remap_sound_for_area(0x4003AB13), (saddr)this, (uaddr)&position, 0, 0);
}

void TObjEneRe4Sorcerer__sub_800EF214(TObjEneRe4Sorcerer *self) {
    play_persistent_sound(self->remap_sound_for_area(0x4003A81D), (saddr)self, (uaddr)&self->position, 0, 0);
}

void TObjEneRe4Sorcerer::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_state(reason);
        return;
    case 1:
        TObjEneRe4Sorcerer__sub_800EEFE4(this, reason);
        return;
    case 2:
        TObjEneRe4Sorcerer__sub_800EEDE4(this, reason);
        return;
    case 3:
        TObjEneRe4Sorcerer__sub_800EEC00(this, reason);
        return;
    case 4:
        state_wait(reason);
        return;
    case 5:
        TObjEneRe4Sorcerer__sub_800EE7DC(this, reason);
        return;
    case 6:
        update_state_machine(reason);
        return;
    case 7:
        TObjEneRe4Sorcerer__sub_800EE1CC(this, reason);
        return;
    case 8:
        TObjEneRe4Sorcerer__sub_800EE0F8(this, reason);
        return;
    case 9:
        handle_death_state(reason);
    default:
        return;
    }
}

void TObjEneRe4Sorcerer::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        m_4e4 = 0;
        break;
    case 3:
        if (m_4e4 >= 2) {
            transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        m_4e4 = m_4e4 + 1;
        break;
    }
}

void TObjEneRe4Sorcerer__sub_800EEFE4(TObjEneRe4Sorcerer *self, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD *)self)->set_field_378(1);
        VecCopy(&self->position, &self->home_position);
        VecCopy(&self->prev_position, &self->home_position);
        VecCopy(&self->body_center, &self->home_position);
        self->set_intangible();
        return;
    case 3:
        if (self->try_attack(160000.0f, 62500.0f) != 0) {
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->m_3f0 = (s32)(RADIANS_TO_ANGLE * atan2_float(-self->destination_direction.x, -self->destination_direction.z));
            TObjEneRe4Sorcerer__sub_800EF95C(self, 50.0f);
            self->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        self->update_body_colliders();
        break;
    }
}
}

#pragma push
#pragma opt_common_subs off
extern "C" {
void TObjEneRe4Sorcerer__sub_800EEDE4(TObjEneRe4Sorcerer *self, s32 arg1) {
    s32 i;
    TObjEneRe4Bit *bit;

    switch (arg1) {
    case 4:
        self->requested_action = 7;
        ((TObjEneDD *)self)->set_field_378(3);
        self->m_3c8 |= 0xE;
        self->clear_intangible();
        TObjEneRe4Sorcerer__sub_800EF844(self);
        self->fade.reset_obstruction_fade();
        for (i = 0; i < 2; i++) {
            if ((bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i])) != NULL) {
                bit->reset_transform();
                bit->clear_state_flag_0x10();
            }
        }
        self->m_3f8 = 0.0f;
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        play_area_variant_sound(&self->position);
        break;
    case 3:
        if (self->m_4e4 >= 0x3C) {
            ((TObjEneRe4Sorcerer *)self)->set_motion_by_state();
        }
        break;
    case 0:
        if (*((f32 * (*)(void *))TBoss3Volopt__sub_800F059C)(&self->fade) >= -0.75f) {
            self->advance_animation();
            self->turn_to_target();
        }
        switch (self->m_4e8) {
        case 0:
            if (self->fade.advance_toward_max() != 0) {
                self->m_4e4 = 0;
                self->m_4e8 = 1;
                self->m_3c8 &= ~4;
                TObjEneRe4Sorcerer__sub_800EF7C8(self);
            }
            break;
        case 1:
            self->m_4e4 += 1;
            if (self->m_3f8 < 1.0f) {
                self->m_3f8 += 0.2f;
            }
            self->check_collisions();
            break;
        }
        self->update_ground_contact();
        TObjEneRe4Sorcerer__sub_800EF214(self);
        break;
    case 5:
        self->m_3f8 = 1.0f;
        self->m_3c8 &= ~4;
        break;
    }
}
}

#pragma pop
extern "C" {
void TObjEneRe4Sorcerer__sub_800EEC00(TObjEneRe4Sorcerer *self, s32 arg1) {
    f32 temp_f2;
    s32 i;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)self)->set_field_378(3);
        self->clear_intangible();
        TObjEneRe4Sorcerer__sub_800EF844(self);
        self->m_3c8 |= 2;
        self->m_3c8 &= 0xFFFFFFF7;
        for (i = 0; i < 2; i++) {
            TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
            if (bit != NULL) {
                bit->set_flag_and_notify();
            }
        }
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        self->fade.reset_color();
        play_area_variant_sound(&self->position);
        break;
    case 3:
        if (self->m_4e4 >= 0x1E) {
            self->request_death_effect();
        }
        break;
    case 0:
        self->advance_animation();
        switch (self->m_4e8) {
        case 0:
            temp_f2 = self->m_3f8;
            if (temp_f2 > 0.0f) {
                self->m_3f8 = temp_f2 - 0.2f;
                if (self->m_3f8 < 0.0f) {
                    self->m_3f8 = 0.0f;
                    self->m_3c8 |= 4;
                    self->fade.reset_color();
                }
            } else if (self->fade.decay_value_toward_floor() != 0) {
                self->m_4e4 = 0;
                self->m_4e8 = 1;
                self->m_3c8 &= 0xFFFFFFF9;
            }
            TObjEneRe4Sorcerer__sub_800EF214(self);
            break;
        case 1:
            self->m_4e4 = self->m_4e4 + 1;
            break;
        }
        self->update_ground_contact();
        break;
    case 5:
        self->m_3c8 &= 0xFFFFFFFB;
        self->m_3f8 = 1.0f;
        break;
    }
}

void TObjEneRe4Sorcerer::state_wait(s32 arg1) {
    switch (arg1) {
    case 4:
        m_4e4 = 0;
        set_field_378(4);
        m_3c8 &= 0xFFFFFFFD;
        set_intangible();
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        return;
    case 3:
        if (try_attack(160000.0f, 160000.0f) != 0) {
            if (m_3ec & 1) {
                TObjEneRe4Sorcerer__sub_800EF95C(this, 80.0f);
            } else {
                TObjEneRe4Sorcerer__sub_800EF95C(this, 30.0f);
            }
            transition_enemy_state(2);
            return;
        }
        if (m_4e4 > 0x5A) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        m_4e4 = m_4e4 + 1;
        break;
    }
}

void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *self, s32 arg1) {
    s32 temp_r0;
    s32 state;
    TObjEneRe4Bit *bit;
    bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[0]);
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        ((TObjEneDD *)self)->set_field_378(3);
        self->m_3c8 |= 0xA;
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        return;
    case 3:
        if (self->m_4e8 == 5) {
            self->advance_anim_frame();
            self->m_3ec = self->m_3ec + 1;
            self->transition_enemy_state(3);
        }
        return;
    case 0:
        self->advance_animation();
        self->m_4e4 = self->m_4e4 + 1;
        temp_r0 = self->m_4e8;
        switch (temp_r0) {
        case 0:
            if ((bit != NULL) && (bit->sub_800ED498() != 0)) {
                self->m_4e4 = 0;
                if (self->try_attack(10000.0f, 10000.0f) == 0) {
                    self->m_4e8 = 4;
                } else {
                    self->enemy_copy_target_destination();
                    self->update_velocity();
                    if (self->destination_distance >= 100.0f) {
                        self->m_4e8 = 4;
                    } else {
                        self->m_4e8 = 1;
                        self->requested_action = 1;
                        self->m_3c8 |= 8;
                        self->set_photon_state();
                    }
                    self->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(self->destination_direction.x, self->destination_direction.z));
                }
            } else if (self->m_4e4 >= 0xF0) {
                self->m_4e8 = 5;
            }
            self->turn_to_target();
            self->create_effect();
            break;
        case 1:
            if ((bit != NULL) && (bit->sub_800ED498() == 0)) {
                self->m_4e8 = 5;
            } else if (self->m_4e4 >= 0x5A) {
                self->requested_action = 3;
                self->m_4e8 = 3;
            }
            self->turn_to_target();
            self->create_effect();
            break;
        case 2:
        case 3:
            if ((self->frame >= 11.0f) && (temp_r0 == 3)) {
                if (bit != NULL) {
                    state = bit->get_state();
                } else {
                    state = 3;
                }
                switch (state) {
                case 2:
                    self->m_4e8 = 2;
                    self->cast_technique();
                    break;
                case 3:
                    self->m_4e8 = 2;
                    break;
                }
            }
            if (self->get_flag_b4() != 0) {
                self->m_4e8 = 5;
                if (bit != NULL) {
                    bit->set_attack_flag();
                }
            }
            break;
        case 4:
            if (self->m_4e4 >= 0x3C) {
                self->m_4e8 = 5;
            }
            break;
        case 5:
            break;
        }
        self->check_collisions();
        self->update_body_colliders();
        TObjEneRe4Sorcerer__sub_800EF214(self);
        return;
    case 5:
        if (bit != NULL) {
            bit->set_attack_flag();
        }
        self->m_3c8 &= 0xFFFFFFF7;
        break;
    }
}

void TObjEneRe4Sorcerer::update_state_machine(s32 reason) {
    f32 *t = &m_4ec;
    s32 mask;
    s32 n;
    s32 i;
    TObjChara *p;
    s32 j;
    switch (reason) {
    case 4:
        set_field_378(6);
        set_intangible();
        m_3c8 &= ~2;
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        init_float_params();
        if (is_confused() != 0) {
            m_4e4 = 3;
        } else {
            m_4e4 = 0;
        }
        m_4e8 = 0;
        *t = 0.0f;
        break;
    case 3:
        if (m_4e4 == 4) {
            transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        switch (m_4e4) {
        case 3:
            mask = 0;
            n = TLobby::get_game_mode();
            *t = 0.0f;
            for (i = 0; i < n; i++) {
                p = (TObjChara *)TObjPlayer::get_player_data(i);
                mask |= update_farthest_target((saddr)p, t);
            }
            if (mask != 0) {
                m_4e4 = 2;
            } else {
                m_4e4 = 0;
            }
            break;
        case 0:
            if (check_shield(this) != 0) {
                current_target = this;
                m_4e4 = 2;
            } else {
                m_4e4 = 1;
            }
            break;
        case 1:
            j = TLobby::get_game_mode();
            n = j + TObjEneDD::get_enemy_count();
            *t = 0.0f;
            for (; j < n; j++) {
                p = (TObjChara *)TObjPlayer::get_player_data(j);
                if (p == this) {
                    continue;
                }
                if (p != 0) {
                    s16 a = p->room;
                    if (a != room) {
                        continue;
                    }
                }
                update_farthest_target((saddr)p, t);
            }
            m_4e4 = 2;
            break;
        case 2:
            if (current_target != 0) {
                TObjEneRe4Sorcerer__sub_800EF95C(this, 20.0f);
            } else {
                VecCopy(&destination, &position);
                TObjEneRe4Sorcerer__sub_800EF95C(this, 160.0f);
            }
            m_4e4 = 4;
            break;
        }
        break;
    }
}

void TObjEneRe4Sorcerer__sub_800EE1CC(TObjEneRe4Sorcerer *self, s32 arg1) {
    s32 temp_r0;
    s32 state;
    TObjEneRe4Bit *bit;

    bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[1]);
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        ((TObjEneDD *)self)->set_field_378(3);
        self->m_3c8 |= 0xA;
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        return;
    case 3:
        if (self->m_4e8 == 5) {
            self->advance_anim_frame();
            self->transition_enemy_state(3);
        }
        return;
    case 0:
        self->advance_animation();
        self->m_4e4 = self->m_4e4 + 1;
        temp_r0 = self->m_4e8;
        switch (temp_r0) {
        case 0:
            if ((bit != NULL) && (bit->sub_800ED498() != 0)) {
                self->m_4e4 = 0;
                if (self->current_target->is_alive() != 0) {
                    if (self->current_target != self) {
                        self->enemy_copy_target_destination();
                        self->update_velocity();
                        if (self->destination_distance >= 100.0f) {
                            self->m_4e8 = 4;
                        } else {
                            self->m_4e8 = 1;
                            self->requested_action = 1;
                            self->m_3c8 |= 8;
                            self->apply_mylla_effect();
                        }
                        self->rotation_y = (saddr)(RADIANS_TO_ANGLE * atan2_float(self->destination_direction.x, self->destination_direction.z));
                    } else {
                        self->m_4e8 = 1;
                        self->requested_action = 1;
                        self->m_3c8 |= 8;
                        self->apply_mylla_effect();
                    }
                } else {
                    self->m_4e8 = 4;
                }
            } else if ((f32)self->m_4e4 >= 240.0f) {
                self->m_4e8 = 5;
            }
            break;
        case 1:
            if ((bit != NULL) && (bit->sub_800ED498() == 0)) {
                self->m_4e8 = 5;
            } else if ((f32)self->m_4e4 >= 90.0f) {
                self->requested_action = 4;
                self->m_4e8 = 3;
            }
            play_persistent_sound(self->remap_sound_for_area(0x4003A814), (saddr)self, (uaddr)&self->position, 0, 0);
            break;
        case 2:
        case 3:
            if ((self->frame >= 11.0f) && (temp_r0 == 3)) {
                if (bit != NULL) {
                    state = bit->get_state();
                } else {
                    state = 3;
                }
                switch (state) {
                case 2:
                    self->m_4e8 = 2;
                    self->cast_resta();
                    break;
                case 3:
                    self->m_4e8 = 2;
                    break;
                }
            }
            if (self->get_flag_b4() != 0) {
                self->m_4e8 = 5;
                if (bit != NULL) {
                    bit->set_attack_flag();
                }
            }
            break;
        case 4:
            if ((f32)self->m_4e4 >= 60.0f) {
                self->m_4e8 = 5;
            }
            break;
        case 5:
            break;
        }
        self->check_collisions();
        self->update_body_colliders();
        TObjEneRe4Sorcerer__sub_800EF214(self);
        return;
    case 5:
        if (bit != NULL) {
            bit->set_attack_flag();
        }
        self->m_3c8 &= 0xFFFFFFF7;
        ((TObjEneDD_ST *)(self))->enemy_clear_target();
        break;
    }
}

void TObjEneRe4Sorcerer__sub_800EE0F8(TObjEneRe4Sorcerer *self, s32 arg1) {
    Vec v;
    f32 c;
    switch (arg1) {
    case 4:
        self->requested_action = 5;
        self->advance_animation();
        break;
    case 3:
        if (self->get_flag_b4() != 0) {
            self->transition_enemy_state(self->next_mode);
        }
        break;
    case 0:
        self->advance_animation();
        VecCopy(&v, (Vec *)&self->x_speed);
        c = normalize_vector_xz(&v);
        self->move_to_wall_clamped_destination(v.x, v.z, c);
        self->x_speed *= 0.8f;
        self->m_310 *= 0.8f;
        TObjEneRe4Sorcerer__sub_800EF214(self);
        break;
    case 5:
        self->clear_attack_receipts();
        break;
    }
}

void TObjEneRe4Sorcerer::handle_death_state(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 6;
        m_3c8 |= 6;
        refresh_and_send_entity_flags();
        m_4e4 = 0;
        fn_800D911C(&body_center);
        TObjPlayer__sub_800A04F0(&fade);
        m_3f8 = 0.0f;
        play_sound_effect((void *)remap_sound_for_area(0x4003AD19), &position, 0, 0);
        return;
    case 0:
        advance_animation();
        if (fade.decay_value_toward_floor() != 0) {
            TObjPlayer::apply_effect_variant_b((saddr)&position, 0);
            queue_destruction();
        }
    case 3:
    case 5:
        return;
    }
}
}

#pragma push
#pragma opt_propagation off
extern "C" {
void TObjEneRe4Sorcerer::step_effect_sequence(NJS_OBJECT *) {
    s32 t;
    switch (TObjEneRe4Sorcerer__render_node_index) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 0x34: {
        f32 k = TObjEneRe4Sorcerer__effect_render_scale;
        t = model_render_flags;
        TObjEneRe4Sorcerer__saved_render_flags = t;
        model_render_flags = t & 0xFFFF7FFF;
        scale_matrix(0, t, k, k, k);
        TParticleCtrl::begin_effect_render();
        break;
    }
    case 0x37:
        model_render_flags = TObjEneRe4Sorcerer__saved_render_flags;
        TObjPlayer::toggle_particle_effect();
        break;
    }
    TObjEneRe4Sorcerer__render_node_index += 1;
}
}

#pragma pop
extern "C" {
void TObjEneRe4Sorcerer::render() {
    saddr camera_mode;
    s32 temp_r31;
    s32 var_r28;
    s32 var_r27;
    if (TObjPlayer::check_demo_mode() == 1) {
        render_demo();
        return;
    }
    camera_mode = 0;
    if (is_split_screen() != 0) {
        camera_mode = TCameraCtrl::get_camera_mode();
    }
    camera_mode = (saddr)&fades[camera_mode];
    ((RenderFadeState *)camera_mode)->update();
    temp_r31 = ((RenderFadeState *)camera_mode)->updateFromCamera(&body_center.x);
    if (!(m_3c8 & 2)) {
        var_r28 = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        var_r28 = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        var_r28 = 1;
    } else {
        var_r28 = 0;
    }
    if (var_r28 != 0) {
        if (m_3c8 & 0x10) {
            draw_ground_shadow(0, 0);
        }
        update_secondary_light();
        TObjFish::set_global_param(texlist);
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        scroll_strip_uvs(TObjEneRe4Sorcerer__uv_scroll_buffer, m_3c0, 0);
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, m_3c4);
        TObjPlayer::toggle_particle_effect();
        var_r27 = 1;
        if (m_3c8 & 4) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                var_r27 = 0;
            }
        } else if (temp_r31 != 0) {
            ((RenderFadeState *)camera_mode)->set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                var_r27 = 0;
            }
        }
        if (var_r27 != 0) {
            push_matrix();
            post_translate_matrix(&position);
            translate_matrix(0, 0.0f, 22.0f, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneRe4Sorcerer__render_node_index = 0;
            TObjEneRe4Sorcerer__saved_render_flags = 0;
            TObjEneRe4Sorcerer__effect_render_scale = m_3f8;
            re4_sorcerer_render_node_ptr = (s32)bit_anchors;
            set_chunk_model_node_callback(TObjEneRe4Sorcerer::step_effect_sequence);
            model_render_flags |= 0x01000000;
            if (var_r28 == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            model_render_flags &= 0xFEFFFFFF;
            set_chunk_model_node_callback(NULL);
            pop_matrix();
        }
        if (m_3c8 & 4) {
            fade.clear_flag_and_notify();
        } else if (temp_r31 != 0) {
            ((RenderFadeState *)camera_mode)->clear_flag_and_notify();
        }
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        TParticleCtrl::end_effect_render();
    }
}
}

#undef re4_sorcerer_collision_body_part_table
extern "C" {
void TObjEneRe4Sorcerer::run_demo_task() {
    if (get_target_info() != 0) {
        ((void (*)(void *))TObjEneRe4Sorcerer__sub_800EFE30)(this);
    }
}

void TObjEneRe4Sorcerer::render_demo() {
    get_target_info();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position);
        translate_matrix(0, 0.0f, 22.0f, 0.0f);
        rotate_matrix_y(0, rotation_y);
        m_3c0 = (m_3c0 + 5);
        scroll_strip_uvs(TObjEneRe4Sorcerer__uv_scroll_buffer, m_3c0, 0);
        m_3c4 += 0.01f;
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, m_3c4);
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(model);
        TParticleCtrl::end_effect_render();
        model_render_flags &= 0xFFFDFFFF;
        pop_matrix();
    }
}
}
