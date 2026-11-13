#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/unk/text_802D1C84.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_80011014.h"

#pragma defer_codegen on

struct SpawnParams_802D1130 { BmlMotionEntry *motions; s32 w[3]; };

extern "C" {
extern const f32 lbl_805DE6EC;
extern const f32 lbl_805DE6F4;
extern const f32 lbl_805DE704;
extern const f32 lbl_805DE70C;
extern const f32 lbl_805DE714;
extern const f32 lbl_805DE728;
extern const char *lbl_805D3F28;
extern const s32 lbl_80472318[];
extern const s32 lbl_804722E8[];
extern const s32 lbl_804722F4[];
extern const s32 lbl_80472300[];
extern const s32 lbl_8047230C[];
extern const SpawnParams_802D1130 lbl_80472480;
extern const char lbl_80472324[];
extern const char lbl_80472338[];
extern const char lbl_80472354[];
extern const char lbl_80472370[];
extern const char lbl_8047238C[];
extern const char lbl_804723A8[];
extern const char lbl_804723C4[];
extern const char lbl_804723E0[];
extern const char lbl_804723FC[];
extern const char lbl_80472418[];
extern const char lbl_80472434[];
extern const char lbl_8047244C[];
extern SampledMotionPoints *TBoss4Type3_shared_instance;
extern SampledMotionPoints *lbl_805D6864;
extern s32 lbl_805D686C;
extern u32 lbl_805D6870;
extern u32 lbl_805D6874;
extern u32 lbl_805D6878;
extern void *tl_04;
s32 play_persistent_sound(s32 id, TObject *owner, const Vec *src, s32 a3, s32 flags);
s32 is_valid_target__9TObjEneDDFv(TObjBase *target);
f32 horizontal_distance_squared(void *, void *);
s32 free_collision_body_parts(void *);
void init_collision_body_parts(void *, void *, s32);
void free_bin_model_request(void *, int);
void TObjPlayer__sub_800F0928(void);
}

TObjEneBm9MericarolMovementParameters lbl_804E1548 = {
    { 225.0f, 0.0f, 0x200 }, { 0, 0, 0, 0 },
};
CollisionBody lbl_804E1564[2] = {
    { { 0.0f, 0.0f, 0.0f }, 25.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 50.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
__declspec(section ".data") const char *lbl_804E15BC[2] = {
    lbl_80472324, NULL,
};
const char *lbl_804E15C4[9] = {
    lbl_80472338, lbl_80472354, lbl_80472370, lbl_8047238C,
    lbl_804723A8, lbl_804723C4, lbl_804723E0, lbl_804723FC,
    NULL,
};
BmlResourceDescriptor lbl_804E15E8 = {
    lbl_80472418, lbl_804E15BC, lbl_804E15C4, 1, 8,
};
__declspec(section ".data") const char *lbl_804E15F8[2] = {
    lbl_80472434, NULL,
};
const char *lbl_804E1600[9] = {
    lbl_80472338, lbl_80472354, lbl_80472370, lbl_8047238C,
    lbl_804723A8, lbl_804723C4, lbl_804723E0, lbl_804723FC,
    NULL,
};
BmlResourceDescriptor lbl_804E1624 = {
    lbl_8047244C, lbl_804E15F8, lbl_804E1600, 1, 8,
};
TObjMotionAction lbl_804E1634[9] = {
    { 3, 0, 3, 0.6f, 0 },
    { 1, 0, 5, 1.0f, 0 },
    { 1, 0, 6, 0.5f, 0 },
    { 1, 0, 5, 0.5f, 0 },
    { 2, 3, 7, 0.7f, 0 },
    { 3, 0, 1, 0.8f, 0 },
    { 3, 0, 2, 0.5f, 0 },
    { 1, 0, 4, 0.6f, 0 },
    { 1, 0, 0, 0.7f, 0 },
};
u8 *bm9_mericarol_phase_hp_table[3];
u8 *lbl_80540B64[3];
u8 *lbl_80540B70[3];
TObjEneBm9MericarolParams *mericarol_phase_param_table[3];
f32 lbl_80540B88[4];
BmlResource *lbl_805D6868;

extern "C" void TBoss4Type3__sub_802D1130(void) {
    s32 i;
    BmlMotionEntry *entry;

    if (is_split_screen() != 0) {
        lbl_805D6868 = (BmlResource *)load_enemy_bml_resource((u8 *)&lbl_804E1624);
    } else {
        lbl_805D6868 = (BmlResource *)load_enemy_bml_resource((u8 *)&lbl_804E15E8);
    }
    lbl_805D686C = 0;
    lbl_805D6870 = 0;
    lbl_80540B88[0] = lbl_805DE70C;
    lbl_80540B88[1] = lbl_805DE70C;
    lbl_80540B88[2] = lbl_805DE70C;
    lbl_805D6874 = 0;
    lbl_805D6878 = 0;
    fn_802D1CC8();
    TObjPlayer__sub_800F0928();
    for (i = 0; i < 3; i++) {
        bm9_mericarol_phase_hp_table[i] = (u8 *)TLobby::register_boss(lbl_804722E8[i]);
        lbl_80540B64[i] = (u8 *)TLobby::dispatch_shared_handler_b(lbl_804722F4[i]);
        lbl_80540B70[i] = (u8 *)TLobby::register_object(lbl_80472300[i]);
        mericarol_phase_param_table[i] = (TObjEneBm9MericarolParams *)TLobby::dispatch_shared_handler_a(lbl_8047230C[i]);
    }
    TBoss4Type3_shared_instance = new SampledMotionPoints(2, lbl_805DE70C, lbl_805DE704, 0.7f);
    lbl_805D6864 = new SampledMotionPoints(2, lbl_805DE70C, lbl_805DE704, 0.7f);
    set_motion_packed_rotation();
    entry = lbl_805D6868->motions + lbl_804E1634[8].motion;
    TBoss4Type3_shared_instance->sample_two_nodes((NJS_OBJECT *)lbl_805D6868->models[0].model, (NJS_MOTION *)entry->motion, 0x20, 0x21);
    entry = lbl_805D6868->motions + lbl_804E1634[8].motion;
    lbl_805D6864->sample_two_nodes((NJS_OBJECT *)lbl_805D6868->models[0].model, (NJS_MOTION *)entry->motion, 0x2A, 0x2B);
    clear_motion_packed_rotation();
    {
        SpawnParams_802D1130 params = lbl_80472480;
        entry = lbl_805D6868->motions;
        params.motions = entry;
        TLobby::spawn_npc_enemy(0x42, lbl_805D6868->models[0].model, (NJS_TEXLIST *)lbl_805D6868->models[0].m_c, &params,
            lbl_804E1564[0].radius, lbl_805DE70C);
    }
}

void *TObjEneBm9Mericarol::create(void *arg0) {
    return new TObjEneBm9Mericarol((TObject *)tl_04, arg0);
}

void TObjEneBm9Mericarol::free_shared_instances() {
    if (lbl_805D6864 != NULL) {
        delete lbl_805D6864;
        lbl_805D6864 = NULL;
    }
    if (TBoss4Type3_shared_instance != NULL) {
        delete TBoss4Type3_shared_instance;
        TBoss4Type3_shared_instance = NULL;
    }
    fn_802D1C84();
    if (lbl_805D6868 != NULL) {
        free_bin_model_request(lbl_805D6868, 1);
        lbl_805D6868 = NULL;
    }
}

TObjEneBm9Mericarol::TObjEneBm9Mericarol(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    s32 ph;
    s32 i;

    m_name = lbl_805D3F28;
    invoke_initialization_hook(set_data);
    init_size_tier_and_offsets();
    m_438 = 0;
    if (random_ratio() <= 0.002f) {
        m_438 |= 0x400;
    }
    init_position_vectors();
    model = (void *)lbl_805D6868->models[0].model;
    texlist = lbl_805D6868->models[0].m_c;
    init_model(lbl_804E1564, 1);
    set_field_d8((s32)lbl_804E1634);
    set_field_dc((s32)lbl_805D6868->motions);
    requested_action = 2;
    set_animation(requested_action);
    set_field_b8(requested_action);
    ph = get_phase();
    reset_hp(bm9_mericarol_phase_hp_table[ph], lbl_80540B64[ph], lbl_80540B70[ph]);
    m_3c0[0] = TUnk_80494968::create(0xA0303030, lbl_80472318[ph]);
    m_3c0[1] = TUnk_80494968::create(0xA0303030, lbl_80472318[ph]);
    add_flags_2e4(0x12);
    movementParameters = &lbl_804E1548;
    switch (get_phase()) {
    case 0:
        initialize_enemy_state(0x38);
        break;
    case 1:
        initialize_enemy_state(0x39);
        break;
    case 2:
        initialize_enemy_state(0x3A);
        break;
    }
    m_37c = lbl_805DE6EC;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    m_43c = lbl_805DE70C;
    m_44c = 0;
    m_450 = 0;
    m_454 = 0;
    m_458 = 0;
    m_46c.reset_obstruction_fade();
    m_48c = new TObjCollidable(0);
    init_collision_body_parts(m_48c, &lbl_804E1564[1], 1);
    m_488 = new AreaAttackHistory(8);
    m_490 = 0;
    m_494 = 0;
    m_498 = 0;
    m_49c = 0;
    m_4a0 = 0;
    m_4a4 = lbl_805DE70C;
    m_4ac = 0;
    sync_center_position();
    vfunc_88();
    transform_part_positions();
    mode = 0;
    dispatch_action(mode, 4);
    sub_8002AE64();
    for (i = 0; i < 4; i++) {
        m_3c8[i].activate_and_dispatch();
    }
}

TObjEneBm9Mericarol::~TObjEneBm9Mericarol() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (m_3c0[i] != NULL) {
            m_3c0[i]->queue_destruction();
            m_3c0[i] = NULL;
        }
    }
    if (m_488 != NULL) {
        delete m_488;
        m_488 = NULL;
    }
    if (m_48c != NULL) {
        free_collision_body_parts(m_48c);
        delete m_48c;
        m_48c = NULL;
    }
    if (m_4ac != NULL) {
        m_4ac->queue_destruction();
        m_4ac = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneBm9Mericarol::run_task() {
    s16 state;
    s32 flags;
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_105();
        return;
    }
    flags = m_438;
    if (flags & 0x10) {
        if (m_390 == 0) {
            m_438 = flags & ~0x10;
        }
    } else if (m_390 != 0) {
        m_438 = flags | 0x10;
    }
    if (vfunc_83() != 4) {
        vfunc_85();
    } else {
        state = mode;
        if (state == 0 || state == 1) {
            m_46c.reset_color();
            transition_enemy_state(2);
        }
    }
    sync_center_position();
    submit_default_cursor_candidate();
    vfunc_100();
}

void TObjEneBm9Mericarol::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_action(reason);
        return;
    case 1:
        sub_802D05BC(reason);
        return;
    case 2:
        handle_event(reason);
        return;
    case 3:
        sub_802D01D8(reason);
        return;
    case 4:
        handle_shot_state(reason);
        return;
    case 5:
        sub_802CFB64(reason);
        return;
    case 6:
        sub_802CF7B4(reason);
        return;
    case 10:
        sub_802CF368(reason);
        return;
    case 11:
        state_burrow(reason);
        return;
    case 7:
        sub_802CF4F8(reason);
        return;
    case 8:
        handle_motion_event(reason);
        return;
    case 9:
        sub_802CEDA0(reason);
        return;
    case 12:
        handle_state_message(reason);
    default:
        return;
    }
}

void TObjEneBm9Mericarol::vfunc_28() {  }

void TObjEneBm9Mericarol::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0xB) && (temp_r0 != 0xC)) {
        transition_enemy_state(0xB);
    }
}

void TObjEneBm9Mericarol::vfunc_62() {
    if ((s16) this->mode != 0xA) {
        if (this->m_438 & 0x20) {
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(0xA);
    }
}

void TObjEneBm9Mericarol::vfunc_61() {  }

void TObjEneBm9Mericarol::sync_center_position() {
    VecCopy((Vec *)&m_2fc, &position);
    m_300 = m_300 + lbl_805DE704;
    VecCopy(&center, (Vec *)&m_2fc);
}

void TObjEneBm9Mericarol::vfunc_88() {
    bodies->offset.y = m_300 - position.y;
}

void TObjEneBm9Mericarol::sub_802D0940() {  }

void TObjEneBm9Mericarol::sub_802D093C() {  }

s32 TObjEneBm9Mericarol::try_set_mode8_if_flag2() {
    if (this->m_438 & 2) {
        transition_enemy_state(8);
        return 1;
    }
    return 0;
}

TObjPlayer *TObjEneBm9Mericarol::find_nearby_target() {
    TObjPlayer *best = NULL;
    s32 n = TLobby::get_game_mode();
    TObjPlayer *pl;
    s32 i;
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (is_valid_target__9TObjEneDDFv(pl) != 0 && pl->obj_isState2_324() == 0) {
            best = pl;
            break;
        }
    }
    if (is_valid_target__9TObjEneDDFv(best) != 0 && horizontal_distance_squared(&position, &best->position) < 10000.0f) {
        return best;
    }
    return NULL;
}

#pragma push
#pragma opt_common_subs off
void TObjEneBm9Mericarol::init_size_tier_and_offsets() {
    f32 roll;
    s32 tier;
    m_45c = variant;
    tier = m_45c;
    if (tier < 0 || tier > 2) {
        roll = random_ratio();
        if (roll > lbl_805DE728) {
            m_45c = 2;
        } else if (roll > 0.8f) {
            m_45c = 1;
        } else {
            m_45c = 0;
        }
    }
    m_440 = 0.5f + parameters[0];
    m_444 = 3.0f + parameters[1];
    if (m_444 < lbl_805DE6F4) {
        m_444 = lbl_805DE6F4;
    }
    m_448 = lbl_805DE714 + parameters[2];
}
#pragma pop

s32 TObjEneBm9Mericarol::get_phase() { return m_45c; }

void TObjEneBm9Mericarol::sub_802D073C() {
    play_persistent_sound(remap_sound_for_area(0x3A810), this, &position, 0, 0);
}
