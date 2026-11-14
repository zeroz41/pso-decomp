#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/flower/TObjEneRe2Flower_Bomb.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/vector.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/flower/TObjEneRe2Flower_800C4B78.h"
#include "pso/enemy/dd/TObjEneDD_800C2614.h"
#include "pso/unk/text_800C2A88.h"
#include "pso/unk/text_800C3088.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/player/TObjPlayer.h"

struct Stack_800C44C4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};
struct RecoveredGlobal_800C44C4_lbl_8043BB90 {
    s32 value;
    u8 remaining[0xC];
};
typedef char RecoveredGlobal_800C44C4_lbl_8043BB90_size[sizeof(RecoveredGlobal_800C44C4_lbl_8043BB90) == 0x10 ? 1 : -1];

extern "C" {
u8 *load_enemy_bml_resource_named(s32 *, const char *);
s32 load_enemy_bml_resource(u8 *arg0);
extern RecoveredGlobal_800C44C4_lbl_8043BB90 lbl_8043BB90;
extern char lbl_8043BAAC[];
extern char lbl_8043BAC4[];
extern char lbl_8043BADC[];
extern char lbl_8043BAF4[];
extern char lbl_8043BB08[];
extern char lbl_8043BB20[];
extern char lbl_8043BB38[];
extern char lbl_8043BB50[];
extern char lbl_8043BB64[];
s32 TObjEneRe2Flower__sub_800C2E64(void *, void *);
s32 obj_isState2_324__9TObjCharaFv(void *);
s32 is_valid_target__9TObjEneDDFv(void *);
f32 horizontal_distance_squared(void *, void *);
int TBoss8Dragon__sub_800BB7D4(void *, void *);
}

// The pooled float constants of the file this unit is a part of (the pool
// starts in the functions before 0x800C3B80, which are other units today).
extern const f32 lbl_805D9FAC; // 0.0
extern const f32 lbl_805D9FBC; // 5.0
extern const f32 lbl_805D9FD8; // 15.0
extern const f32 lbl_805D9FF4;
extern const f32 lbl_805D9FF8;
extern const f32 lbl_805D9FFC; // 0.002

// Stat block ids by variant (0 normal, 1 rare, 2 the tower's): base stats,
// resistances, attack stats, and the movement block.
extern const s32 lbl_8043BA7C[3];
extern const s32 lbl_8043BA88[3];
extern const s32 lbl_8043BA94[3];
extern const s32 lbl_8043BAA0[3];

extern const char *lbl_805D2A48; // "TObjEneRe2Flower"
extern void *lbl_805D5170;       // TLobby::dispatch_shared_handler_a's block for the variant
extern BmlResource *lbl_805D5174;
extern s32 lbl_805D5178;
extern s32 lbl_805D517C;
extern s32 lbl_805D5180;
extern void *tl_04;

struct FlowerSetupData {
    f32 value00;
    u32 unknown04;
    u32 flags;
    u32 unknown0c[4];
};
typedef char FlowerSetupData_size[sizeof(FlowerSetupData) == 0x1C ? 1 : -1];
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
void TObjPlayer__sub_800C44C4(void) {
    Stack_800C44C4 stack;
    BmlModelEntry *models;

    if (get_current_floor_area() == AREA_TOWER) {
        lbl_805D5174 = (BmlResource *)load_enemy_bml_resource_named((s32 *)&TObjEneRe2Flower__resource_descriptor, "bm_ene_dkflower.bml");
    } else if (TObjEneDD::check_v2_mode() != 0) {
        lbl_805D5174 = (BmlResource *)load_enemy_bml_resource_named((s32 *)&TObjEneRe2Flower__resource_descriptor, "bm_ene_re2_flower_a.bml");
    } else {
        lbl_805D5174 = (BmlResource *)load_enemy_bml_resource((u8 *)&TObjEneRe2Flower__resource_descriptor);
    }
    lbl_805D5178 = 0;
    lbl_805D517C = 0;
    lbl_805D5180 = 0;
    TObjPlayer::create_render_texture();
    TObjPlayer__sub_800F0928();
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043BB90.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043BB90.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8043BB90.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&lbl_8043BB90.value + 0xC);
    stack.sp8 = (s32)lbl_805D5174->motions;
    models = lbl_805D5174->models;
    TLobby::spawn_npc_enemy(0x37, models->model, (NJS_TEXLIST *)models->m_c, &stack.sp8, lbl_805D9FBC, lbl_805D9FAC);
}

void *TObjEneRe2Flower::create(void *arg0) {
    return new TObjEneRe2Flower((TObject *)tl_04, arg0);
}

void TObjEneRe2Flower::destroy_instance() {
    TObjPlayer__sub_800C4D44();
    if (lbl_805D5174 != NULL) {
        free_bin_model_request(lbl_805D5174, 1);
        lbl_805D5174 = NULL;
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
    model = (void *)lbl_805D5174->models->model;
    texlist = lbl_805D5174->models->m_c;
    if (get_flag_11()) {
        init_model(lbl_804930EC, 2);
    } else {
        init_model(lbl_80493094, 2);
    }
    set_field_d8((s32)TObjEneRe2Flower__animation_descriptors);
    set_field_dc((s32)lbl_805D5174->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_field_b8(requested_action);
    sub_8002AE64();
    if (get_flag_11()) {
        variant = 2;
    } else if (sub_800C3B8C()) {
        variant = 1;
    } else {
        variant = 0;
    }
    reset_hp((u8 *)TLobby::register_boss(lbl_8043BA7C[variant]),
             (u8 *)TLobby::dispatch_shared_handler_b(lbl_8043BA88[variant]),
             (u8 *)TLobby::register_object(lbl_8043BA94[variant]));
    lbl_805D5170 = TLobby::dispatch_shared_handler_a(lbl_8043BAA0[variant]);
    if (get_flag_11()) {
        set_state_8();
    } else {
        check_state_flag_2();
    }
    movementParameters = &TObjEneRe2Flower__setup_data;
    if (get_flag_11()) {
        initialize_enemy_state(83);
    } else if (sub_800C3B8C()) {
        initialize_enemy_state(14);
    } else {
        initialize_enemy_state(13);
    }
    m_37c = lbl_805D9FBC;
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
    sub_800C3DC4();
    vfunc_88();
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
        this->vfunc_105();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    } else {
        temp_r3 = this->mode;
        if ((temp_r3 == 0) || (temp_r3 == 1)) {
            m_3f4.reset_color();
            transition_enemy_state(2);
        }
    }
    this->sub_800C3DC4();
    submit_default_cursor_candidate();
    this->vfunc_100();
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
        TObjEneRe2Flower__sub_800C2E64(this, (void *)reason);
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

void TObjEneRe2Flower::vfunc_28() {  }

void TObjEneRe2Flower::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0xA) && (temp_r0 != 0xB)) {
        transition_enemy_state(0xA);
    }
}

void TObjEneRe2Flower::vfunc_62() {
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

void TObjEneRe2Flower::vfunc_61() {  }

void TObjEneRe2Flower::sub_800C3DC4() {
    VecCopy((Vec *)&this->m_2fc, &this->position);
    this->m_300 = this->m_300 + lbl_805D9FF8;
    VecCopy(&this->center, (const Vec *)&this->m_2fc);
}

void TObjEneRe2Flower::vfunc_88() {
    bodies[1].offset.y = m_300 - position.y;
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
        TBoss8Dragon__sub_800BB7D4(this, (void *)242);
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
        if (is_valid_target__9TObjEneDDFv(p) != 0 && obj_isState2_324__9TObjCharaFv(p) == 0) {
            result = p;
            break;
        }
    }
    if (is_valid_target__9TObjEneDDFv(result) != 0 && horizontal_distance_squared((u8 *)&this->position, result + 0x38) < lbl_805D9FF4) {
        return result;
    }
    return NULL;
}

void TObjEneRe2Flower::sub_800C3BA8() {  }

s32 TObjEneRe2Flower::sub_800C3B8C() {
    u32 flags = m_3c4;
    if (flags & 0x800) {
        return 0;
    }
    return (flags & 0x400) != 0;
}

int TObjEneRe2Flower::get_flag_11() { return (m_3c4 >> 11) & 0x1; }
