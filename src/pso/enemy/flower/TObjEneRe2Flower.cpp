#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"
#include "pso/unk/text_800C3088.h"
#include "pso/unk/text_800C3A60.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecMegid.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/flower/TObjEneRe2Flower_Bomb.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/flower/TObjEneRe2Flower_800C4B78.h"
#include "pso/enemy/dd/TObjEneDD_800C2614.h"
#include "pso/unk/text_800C2A88.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"

struct VBase_18_880cfd
{
  char pad[0x18];
};

struct VObj_18_880cfd : VBase_18_880cfd {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct RecoveredFields_800C3088_arg0
{
  u8 unknown_0[0xB8];
  s16 field_B8;
  u8 unknown_BA[0xA];
  f32 field_C4;
  f32 field_C8;
  u8 unknown_CC[0x2C4];
  u8 *field_390;
  u8 unknown_394[0x30];
  int field_3C4;
  u8 unknown_3C8[0x48];
  int field_410;
  int field_414;
  int field_418;
};

extern "C" {
TParticleCtrl *create_particle_emitter(const void *pos, s32 id);
s32 TObjPlayer__sub_800C4A5C(int, void *, void *, int);
s32 play_sound_effect(s32, void *, int, int);
extern const f32 lbl_805D9FD8;
extern const f32 lbl_805D9FDC;
extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FC0;
extern const f32 lbl_805D9FC4;
extern const f32 lbl_805D9FD4;
typedef struct RecoveredFields_800C3088_arg0 RecoveredFields_800C3088_arg0;

typedef struct VBase_18_880cfd VBase_18_880cfd;

typedef struct VObj_18_880cfd VObj_18_880cfd;

}

#include "pso/enemy/epsilon/TObjEneEpsilon.h"
extern "C" {
extern const f32 lbl_805D9FF0;
f32 atan2_float(f32 y, f32 x);
}

extern "C" {
s32 angle_difference_abs(s32 a, s32 b);
s32 approach_angle_limited(s32 from, s32 to, s32 max_step);
}

extern const f32 lbl_805D9FE0;
extern const f32 lbl_805D9FE4;
extern const f32 lbl_805D9FE8;
extern const f32 lbl_805D9FEC;
struct Base_Sub_800c38d0 { char pad[0x14]; };

struct V_Sub_800c38d0 : Base_Sub_800c38d0 {
    PADV4
    PADV
    virtual s32 m5();
};



extern "C" {

extern const NpcAnimationBinding lbl_8043BB90;
extern char lbl_8043BAAC[];
extern char lbl_8043BAC4[];
extern char lbl_8043BADC[];
extern char lbl_8043BAF4[];
extern char lbl_8043BB08[];
extern char lbl_8043BB20[];
extern char lbl_8043BB38[];
extern char lbl_8043BB50[];
extern char lbl_8043BB64[];
void TObjEneRe2Flower__sub_800C2E64(void *, s32);
f32 horizontal_distance_squared(void *, void *);
void TBoss8Dragon__sub_800BB7D4(void *self, int id);
}

extern const f32 lbl_805D9FBC; // 5.0
extern const f32 lbl_805D9FF4;
extern const f32 lbl_805D9FF8;
extern const f32 lbl_805D9FFC; // 0.002
// Stat block ids by variant (0 normal, 1 rare, 2 the tower's): base stats,
// resistances, attack stats, and the movement block.
extern const s32 lbl_8043BA7C[3];

extern const s32 lbl_8043BA88[3];
extern const s32 lbl_8043BA94[3];
extern const s32 lbl_8043BAA0[3];
extern "C" { extern char TObjEneRe2Flower__class_name_string[]; }
const char *lbl_805D2A48 = TObjEneRe2Flower__class_name_string;
// The variant's movement block (TLobby::dispatch_shared_handler_a of lbl_8043BAA0), set by the constructor.
void *re2_flower_movement_params;
BmlResource *re2_flower_bml_resource;
// State of the chunk node callback TObjPlayer::update_effect_sequence: the node counter, the head yaw
// applied at node 1 and the two points transformed at node 14.
s32 re2_flower_node_index;
s32 re2_flower_node_yaw;
f32 *re2_flower_node_points;
extern void *tl_04;
struct FlowerSetupData {
    f32 value00;
    u32 unknown04;
    u32 flags;
    u32 unknown0c[4];
};

LAYOUT_ASSERT(FlowerSetupData_size, sizeof(FlowerSetupData) == 0x1C);

FlowerSetupData TObjEneRe2Flower__setup_data = { 225.0f, 0, 0x200, { 0, 0, 0, 0 } };
// The two collision part lists the constructor chooses between: the common
// kinds, then the one get_flag_11() selects.
CollisionBody lbl_80493094[2] = {
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f }
};

CollisionBody lbl_804930EC[2] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f }
};

__declspec(section ".data") const char *bm_ene_re2_flower_model_names[2] = {
    lbl_8043BAAC, NULL
};
const char *bm_ene_re2_flower_motion_names[8] = {
    lbl_8043BAC4, lbl_8043BADC, lbl_8043BAF4, lbl_8043BB08,
    lbl_8043BB20, lbl_8043BB38, lbl_8043BB50, NULL
};

BmlResourceDescriptor TObjEneRe2Flower__resource_descriptor = {
    lbl_8043BB64, bm_ene_re2_flower_model_names,
    bm_ene_re2_flower_motion_names, 1, 7
};

TObjMotionAction TObjEneRe2Flower__animation_descriptors[8] = {
    {3, 0, 0, 0.6f, 0}, {1, 0, 4, 0.3f, 0},
    {1, 0, 5, 0.5f, 0}, {2, 2, 6, 0.6f, 0},
    {3, 0, 1, 0.5f, 0}, {3, 0, 2, 0.5f, 0},
    {1, 0, 3, 0.6f, 0}, {1, 0, 0, 2.0f, 0}
};


// The file is compiled -inline off,deferred, which emits the functions in the
// reverse of the order they are written in.
void load_re2_flower_resources(void) {
    NpcAnimationBinding binding;
    BmlModelEntry *models;

    if (get_current_floor_area() == AREA_TOWER) {
        re2_flower_bml_resource = load_enemy_bml_resource_named(&TObjEneRe2Flower__resource_descriptor, "bm_ene_dkflower.bml");
    } else if (TObjEneDD::check_v2_mode() != 0) {
        re2_flower_bml_resource = load_enemy_bml_resource_named(&TObjEneRe2Flower__resource_descriptor, "bm_ene_re2_flower_a.bml");
    } else {
        re2_flower_bml_resource = load_enemy_bml_resource(&TObjEneRe2Flower__resource_descriptor);
    }
    re2_flower_node_index = 0;
    re2_flower_node_yaw = 0;
    re2_flower_node_points = 0;
    TObjPlayer::create_render_texture();
    TObjPlayer__sub_800F0928();
    __memcpy(&binding, &lbl_8043BB90, sizeof(binding));
    binding.motions = re2_flower_bml_resource->motions;
    models = re2_flower_bml_resource->models;
    NpcModelRegistry::register_animated_chunk(0x37, reinterpret_cast<void *>(models->model), reinterpret_cast<void *>(models->m_c), &binding, lbl_805D9FBC, lbl_805D9FAC);
}

void *TObjEneRe2Flower::create(void *arg0) {
    return new TObjEneRe2Flower((TObject *)tl_04, arg0);
}

void TObjEneRe2Flower::destroy_instance() {
    TObjPlayer__sub_800C4D44();
    if (re2_flower_bml_resource != NULL) {
        delete re2_flower_bml_resource;
        re2_flower_bml_resource = NULL;
    }
}

TObjEneRe2Flower::TObjEneRe2Flower(TObject *parent, void *setData) : TObjEneDD_ST(parent) {
    s32 variant;

    m_name = lbl_805D2A48;
    invoke_initialization_hook(setData);
    sub_800C3BA8();
    m_3c4 = 0;
    if (get_current_floor_area() == AREA_TOWER) {
        m_3c4 |= 0x800;
    } else if (random_ratio() <= lbl_805D9FFC) {
        m_3c4 |= 0x400;
    }
    init_position_vectors();
    model = (void *)re2_flower_bml_resource->models->model;
    texlist = (saddr)re2_flower_bml_resource->models->m_c;
    if (get_flag_11()) {
        init_model(lbl_804930EC, 2);
    } else {
        init_model(lbl_80493094, 2);
    }
    set_field_d8((saddr)TObjEneRe2Flower__animation_descriptors);
    set_field_dc((saddr)re2_flower_bml_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_field_b8(requested_action);
    sub_8002AE64();
    if (get_flag_11()) {
        variant = 2;
    } else if (is_rare_variant()) {
        variant = 1;
    } else {
        variant = 0;
    }
    reset_hp((u8 *)TLobby::register_boss(lbl_8043BA7C[variant]),
             (u8 *)TLobby::dispatch_shared_handler_b(lbl_8043BA88[variant]),
             (u8 *)TLobby::register_object(lbl_8043BA94[variant]));
    re2_flower_movement_params = TLobby::dispatch_shared_handler_a(lbl_8043BAA0[variant]);
    if (get_flag_11()) {
        set_state_8();
    } else {
        set_state_flag_2();
    }
    movementParameters = &TObjEneRe2Flower__setup_data;
    if (get_flag_11()) {
        initialize_enemy_state(83);
    } else if (is_rare_variant()) {
        initialize_enemy_state(14);
    } else {
        initialize_enemy_state(13);
    }
    wall_reach = lbl_805D9FBC;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    m_3c0 = rotation_y;
    m_3c8 = lbl_805D9FAC;
    m_3cc = 0;
    m_3d0 = 0;
    m_3d4 = 0;
    m_3d8 = 0;
    for (s32 i = 0; i < 2; i++) {
        VecCopy(&m_3dc[i], &position);
        m_3dc[i].y += lbl_805D9FD8;
    }
    m_3f4.reset_obstruction_fade();
    m_410 = 0;
    m_414 = 0;
    m_418 = 0;
    m_41c = 0;
    m_420 = 0;
    m_424 = lbl_805D9FAC;
    m_428 = NULL;
    sync_center_offset();
    update_body_colliders();
    transform_part_positions();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneRe2Flower::~TObjEneRe2Flower() {
    if (m_428 != NULL) {
        m_428->queue_destruction();
        m_428 = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneRe2Flower::run_task() {
    s16 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
    } else {
        temp_r3 = this->mode;
        if ((temp_r3 == 0) || (temp_r3 == 1)) {
            m_3f4.reset_color();
            transition_enemy_state(2);
        }
    }
    this->sync_center_offset();
    submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TObjEneRe2Flower::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        dispatch_action(reason);
        return;
    case 1:
        handle_state(reason);
        return;
    case 2:
        handle_flower_state_change(this, reason);
        return;
    case 3:
        state_chase_target(reason);
        return;
    case 4:
        fn_800C32DC((u8 *)this, reason);
        return;
    case 5:
        fn_800C3088((u8 *)this, reason);
        return;
    case 9:
        state_damaged(reason);
        return;
    case 10:
        fn_800C2AC4((u8 *)this, reason);
        return;
    case 6:
        TObjEneRe2Flower__sub_800C2E64(this, reason);
        return;
    case 7:
        handle_event(reason);
        return;
    case 8:
        TObjEneDD__sub_800C2628((u8 *)this, reason);
        return;
    case 11:
        fn_800C2A88(this, reason);
    default:
        return;
    }
}

void TObjEneRe2Flower::refresh_target() {  }

void TObjEneRe2Flower::run_death_reaction() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0xA) && (temp_r0 != 0xB)) {
        transition_enemy_state(0xA);
    }
}

void TObjEneRe2Flower::run_hit_reaction() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if (temp_r0 != 9) {
        if (temp_r0 == 8) {
            begin_state_242();
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(9);
    }
}

void TObjEneRe2Flower::run_miss_reaction() {  }

void TObjEneRe2Flower::sync_center_offset() {
    VecCopy(&this->body_center, &this->position);
    this->body_center.y = this->body_center.y + lbl_805D9FF8;
    VecCopy(&this->center, &this->body_center);
}

void TObjEneRe2Flower::update_body_colliders() {
    bodies[1].offset.y = body_center.y - position.y;
    set_part_local_pos(m_3dc, 0);
}

void TObjEneRe2Flower::set_child_flags() {
    if (get_flag_11() != 0) {
        bodies[0].flags |= 1;
        return;
    }
    bodies[1].flags |= 1;
}

void TObjEneRe2Flower::clear_child_flags() {
    if (get_flag_11() != 0) {
        bodies[0].flags &= ~1;
        return;
    }
    bodies[1].flags &= ~1;
}

s32 TObjEneRe2Flower::check_hit_flag() {
    if (m_3c4 & 2) {
        transition_enemy_state(7);
        return 1;
    }
    return 0;
}

void TObjEneRe2Flower::begin_state_242() {
    if (m_3d4 == 0) {
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        m_3d4 = 20;
    }
}

u8 *TObjEneRe2Flower::find_target_in_range() {
    s32 n;
    u8 *result;
    u8 *p;
    s32 i;
    result = NULL;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (((TObjEneDD *)p)->is_valid_target() != 0 && ((TObjChara *)p)->obj_isState2_324() == 0) {
            result = p;
            break;
        }
    }
    if (((TObjEneDD *)result)->is_valid_target() != 0 && horizontal_distance_squared((u8 *)&this->position, result + 0x38) < lbl_805D9FF4) {
        return result;
    }
    return NULL;
}

void TObjEneRe2Flower::sub_800C3BA8() {  }

s32 TObjEneRe2Flower::is_rare_variant() {
    u32 flags = m_3c4;
    if (flags & 0x800) {
        return 0;
    }
    return (flags & 0x400) != 0;
}

int TObjEneRe2Flower::get_flag_11() { return (m_3c4 >> 11) & 0x1; }

extern "C" {
s32 remap_sound_for_variant(saddr arg0, s32 arg1) {
    if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0) {
        switch (arg1) {
        case 0x4003A10E:
            return 0x4003A339;
        case 0x4003A50F:
            return 0x4003A53A;
        case 0x4003AD10:
            return 0x4003A33B;
        case 0x4003A311:
            return 0x4003A63C;
        case 0x4003A812:
            return 0x4003A83D;
        case 0x4003AB13:
            return 0x4003A83E;
        case 0x4003A814:
            return 0x4003A13F;
        case 0x4003A315:
            return 0x4003A341;
        case 0x4003B216:
            return 0x40039942;
        }
    }
    return ((TObjEnemy *)((void *)arg0))->remap_sound_for_area(arg1);
}

void TObjEneDD::noop() {  }

void TObjEneRe2Flower::dispatch_action(s32 arg1) {
    switch (arg1) {
    case 4:
        this->set_intangible();
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

void TObjEneDD::handle_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->set_intangible();
        ((TObjEneRe2Flower *)arg0)->clear_child_flags();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 8);
        ((TObjEneDD *)arg0)->set_field_378(2);
        ((TObjEneDD_ST *)(arg0))->enemy_clear_target();
        ((TUnk_80494938 *)(arg0 + 0x3F4))->start_fade_in();
        if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0) {
            play_area_se_with_particle((Vec *)(arg0 + 0x38));
            return;
        }
        play_area_sound_effect((Vec *)(arg0 + 0x38));
        return;
    case 3:
        if (((V_Sub_800c38d0 *) (arg0 + 0x3F4))->m5() != 0) {
            ((TObjEneDD *)arg0)->transition_enemy_state(2);
        }
    case 1:
        return;
    case 0:
        advance_animation();
        this->update_ground_contact();
        this->update_body_colliders();
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFF7);
        break;
    }
}

}

void handle_flower_state_change(TObjEneDD *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        ene_dd->requested_action = 1;
        ene_dd->clear_intangible();
        ((TObjEneRe2Flower *)ene_dd)->clear_child_flags();
        *(s32 *)((s8 *)ene_dd + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C4) & 0xFFFFFFF7);
        ene_dd->set_field_378(2);
        ((TObjEneDD_ST *)(ene_dd))->enemy_clear_target();
        return;
    case 3:
        if ((((TObjEneRe2Flower *)ene_dd)->check_hit_flag() == 0) && (((TObjEneDD_ST *)ene_dd)->update_linked_position(lbl_805D9FF0) != 0)) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(3);
        }
    case 5:
    case 1:
        return;
    case 0:
        ene_dd->advance_animation();
        ene_dd->update_ground_contact();
        ene_dd->update_body_colliders();
        break;
    }
}

void TObjEneDD_ST::state_chase_target(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 d;
    s32 t;
    u16 idx;

    switch (arg1) {
    case 5:
        break;
    case 4:
        if (this->mode == 2) {
            this->requested_action = 3;
        } else {
            this->requested_action = 2;
        }
        this->clear_intangible();
        ((TObjEneRe2Flower *)arg0)->set_child_flags();
        *(s32 *)((s8 *)arg0 + 0x3C4) &= ~8;
        ((TObjEneDD *)arg0)->set_field_378(3);
        *(s32 *)((s8 *)arg0 + 0x414) = 0;
        *(s32 *)((s8 *)arg0 + 0x420) = 0;
        if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0) {
            play_sound_effect(0x4003A840, (u8 *)&this->position, 0, 0);
        }
        break;
    case 3:
        if (((TObjEneRe2Flower *)arg0)->check_hit_flag() == 0) {
            d = *(f32 *)((s8 *)arg0 + 0x3AC);
            if (d > lbl_805D9FE0 || *(void **)((s8 *)arg0 + 0x390) == NULL) {
                ((TObjEneDD *)arg0)->transition_enemy_state(2);
            } else if (d < lbl_805D9FE4) {
                t = angle_difference_abs(this->rotation_y, *(s32 *)((s8 *)arg0 + 0x420));
                if (t < ((AttackParams *)(this->m_318))->get_attack_angle()) {
                    ((TObjEneDD *)arg0)->transition_enemy_state(5);
                }
            } else if ((f32)*(s32 *)((s8 *)arg0 + 0x414) > lbl_805D9FE8) {
                ((TObjEneDD *)arg0)->transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        idx = 0xFFFF;
        if (tick_period_counter((saddr)arg0, (s32 *)(arg0 + 0x3D0), 0x14) != 0) {
            if (*(f32 *)((s8 *)arg0 + 0x3AC) > lbl_805D9FEC) {
                if (this->is_confused() != 0) {
                    idx = enemy_nearest_visible_enemy(arg0, *(f32 *)((s8 *)arg0 + 0x3AC) - lbl_805D9FEC);
                }
                if (idx == 0xFFFF) {
                    idx = enemy_find_nearest_player_in_range(arg0, *(f32 *)((s8 *)arg0 + 0x3AC) - lbl_805D9FEC);
                }
                if (idx != 0xFFFF) {
                    enemy_set_target_id((TObjEneDD_ST *)arg0, idx);
                }
            }
        } else if (((TObjEneEpsilon *)arg0)->update_death_check() == 0) {
            break;
        }
        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        ((TObjEneDD_ST *)arg0)->update_velocity();
        (*(s32 *)((s8 *)arg0 + 0x414))++;
        *(s32 *)((s8 *)arg0 + 0x420) = (s32)(10430.38043493439 * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8)));
        this->rotation_y = approach_angle_limited(this->rotation_y, *(s32 *)((s8 *)arg0 + 0x420), (saddr)(*(void **)((s8 *)this->movementParameters + 8)));
        this->rotation_y = (s16)this->rotation_y;
        this->update_ground_contact();
        this->update_body_colliders();
        ((TObjEneDD *)arg0)->noop();
        break;
    }
}

extern "C" {
void fn_800C32DC(u8 *owner, s32 arg1) {
    Vec stack;
    uaddr temp_r3;
    uaddr temp_r3_2;
    u32 temp_r3_3;
    uaddr temp_r3_4;
    switch (arg1) {
    case 4:
        ((TObjEneRe2Flower *)owner)->requested_action = 0;
        ((TObjEneDD *)(owner))->clear_intangible();
        ((TObjEneRe2Flower *)owner)->set_child_flags();
        *(s32 *)((s8 *)owner + 0x3C4) = (s32) (*(s32 *)((s8 *)owner + 0x3C4) & 0xFFFFFFF7);
        ((TObjEneDD *)owner)->set_field_378(3);
        *(u32 *)((s8 *)owner + 0x428) = 0U;
        break;
    case 3:
        if ((((TObjEneRe2Flower *)owner)->check_hit_flag() == 0) && (((TObjEneDD *)owner)->get_flag_b4() != 0)) {
            ((TObjEneDD *)owner)->transition_enemy_state(3);
            break;
        }
    case 1:
        break;
    case 0:
        ((TObjMotion *)owner)->advance_animation();
        if ((u32) *(u32 *)((s8 *)owner + 0x428) == 0U) {
            *(u32 *)((s8 *)owner + 0x428) = (uaddr)create_particle_emitter((owner + 0x3E8), 0xD1);
            temp_r3 = *(u32 *)((s8 *)owner + 0x428);
            if (temp_r3 != 0U) {
                ((TParticleCtrl *)temp_r3)->enable();
            }
        }
        temp_r3_2 = *(u32 *)((s8 *)owner + 0x428);
        if (temp_r3_2 != 0U) {
            if (((TObjEneRe2Flower *)owner)->frame < lbl_805D9FD8) {
                ((TParticleCtrl *)temp_r3_2)->set_position(owner + 0x3E8);
            } else {
                ((TParticleCtrl *)temp_r3_2)->enable();
            }
        }
        if (((TObjMotion *)owner)->is_passing_frame(lbl_805D9FDC) != 0) {
            VecCopy((Vec *)(&stack.x), (const Vec *)(owner + 0x3DC));
            stack.y = lbl_805D9FDC + *(f32 *)((s8 *)owner + 0x3C);
            if ((((TObjEneRe2Flower *)owner)->get_flag_11() != 0) || (TObjEneDD::check_v2_mode() != 0)) {
                TTecMegid::create_ex((saddr)owner, (saddr)((void *)&stack.x), (s32)((int) (((TObjEneRe2Flower *)owner)->rotation_y)), (s32)((int) (TObjEneDD::clamp_frame_index((int) (*(s32 *)((s8 *)re2_flower_movement_params + 0x18))))));
            } else {
                temp_r3_3 = (uaddr)TObject::operator new(0x104);
                if (temp_r3_3 != 0U) {
                    TObjPlayer__sub_800C4A5C(temp_r3_3, owner, &stack.x, (int) (((TObjEneRe2Flower *)owner)->rotation_y));
                }
            }
            play_sound_effect((remap_sound_for_variant((saddr)owner, 0x4003A10E)), owner + 0x3DC, 0, 0);
        }
        ((TObjEneDD *)(owner))->update_ground_contact();
        ((TObjEneDD *)(owner))->update_body_colliders();
        ((TObjEneDD *)owner)->noop();
        break;
    case 5:
        temp_r3_4 = *(u32 *)((s8 *)owner + 0x428);
        if (temp_r3_4 != 0U) {
            ((TObject *)temp_r3_4)->queue_destruction();
            *(u32 *)((s8 *)owner + 0x428) = 0U;
        }
        break;
    }
}

void fn_800C3088(u8 *arg0, int arg1) {
  switch (arg1)
  {
    case 4:
      ((RecoveredFields_800C3088_arg0 *) arg0)->field_B8 = 7;
      (((TObjEneDD *)(arg0))->clear_intangible());
      ((TObjEneRe2Flower *)arg0)->set_child_flags();
      ((RecoveredFields_800C3088_arg0 *) arg0)->field_3C4 = (int) (((RecoveredFields_800C3088_arg0 *) arg0)->field_3C4 & 0xFFFFFFF7);
      ((TObjEneDD *)arg0)->set_field_378(3);
      ((RecoveredFields_800C3088_arg0 *) arg0)->field_410 = 0;
      ((RecoveredFields_800C3088_arg0 *) arg0)->field_414 = 0;
      ((RecoveredFields_800C3088_arg0 *) arg0)->field_418 = 0;
      return;
    case 3:
      if (((int) ((RecoveredFields_800C3088_arg0 *) arg0)->field_410) >= 0x14)
    {
      ((TObjEneDD *)arg0)->transition_enemy_state(3);
    }
    case 1:
      return;
    return;
    case 0:
      ((TObjMotion *)arg0)->advance_animation();
      enemy_validate_retained_target((TObjEneDD_ST *)arg0);
      switch (((RecoveredFields_800C3088_arg0 *) arg0)->field_414)
    {
      case 0:
        if (((TObjMotion *)arg0)->is_passing_frame((f32) ((((RecoveredFields_800C3088_arg0 *) arg0)->field_C4 - lbl_805D9FC0) - ((RecoveredFields_800C3088_arg0 *) arg0)->field_C8)) != 0)
      {
        ((RecoveredFields_800C3088_arg0 *) arg0)->field_418 = (int) (((RecoveredFields_800C3088_arg0 *) arg0)->field_418 + 1);
        if (((f32) ((RecoveredFields_800C3088_arg0 *) arg0)->field_418) >= lbl_805D9FD4)
        {
          ((RecoveredFields_800C3088_arg0 *) arg0)->field_414 = 1;
          ((RecoveredFields_800C3088_arg0 *) arg0)->field_C8 = (f32) lbl_805D9FAC;
        }
      }
      else
        if (((TObjMotion *)arg0)->is_passing_frame((f32)((f32) lbl_805D9FC4)) != 0)
      {
        if (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0)
        {
          if ((((VObj_18_880cfd *)((u8 *) ((RecoveredFields_800C3088_arg0 *) arg0)->field_390))->m18((arg0), (lbl_805D9FC0))) != 0)
          {
            (((VObj_18_880cfd *)((u8 *) ((RecoveredFields_800C3088_arg0 *) arg0)->field_390))->m20((arg0), (lbl_805D9FC0)));
            (((VObj_18_880cfd *)((u8 *) ((RecoveredFields_800C3088_arg0 *) arg0)->field_390))->m23((arg0), (lbl_805D9FD4)));
          }
        }
        play_sound_effect(remap_sound_for_variant((saddr)arg0, 0x4003A814), arg0 + 0x38, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
      }
        break;
      case 1:
        ((RecoveredFields_800C3088_arg0 *) arg0)->field_410 = (int) (((RecoveredFields_800C3088_arg0 *) arg0)->field_410 + 1);
        break;
    }
      (((TObjEneDD *)(arg0))->update_ground_contact());
      (((TObjEneDD *)(arg0))->update_body_colliders());
      ((TObjEneDD *)arg0)->noop();
      return;
    case 5:
      ((RecoveredFields_800C3088_arg0 *) arg0)->field_3C4 = (int) (((RecoveredFields_800C3088_arg0 *) arg0)->field_3C4 & 0xFFFFFFFD);
      break;
  }
}

}
