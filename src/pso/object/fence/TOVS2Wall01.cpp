#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/object/fence/TOBarrierEnergy01.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/fence/TOVS2Wall01.h"
#include "pso/object/fence/TOVS2WallResources.h"

#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TOVS2Wreck06.h"
#include "pso/object/TOVS2Wreck05.h"
#include "pso/object/TOVS2Wreck04.h"
#include "pso/object/TOVS2Wreck03.h"
#include "pso/object/TOVS2Wreck02.h"
#include "pso/object/TOVS2Wreck01.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TOVS2.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/byteswap.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMapObject.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/TObjChip.h"
#include "pso/system/task/TMainTask.h"

#include "pso/system/SoundEffect.h"
#include "pso/object/fence/WallHitPacket.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/object/base/TObjBase.h"

const char *bm_o_vs2_motion_names[1] = { NULL };

const char *bm_o_vs2_model_names[17] = {
    "fe_obj_o_vs2gareki01.gj", "fe_obj_o_vs2gareki02.gj", "fe_obj_o_vs2gareki03.gj", "fe_obj_o_vs2gareki04.gj", "fe_obj_o_vs2gareki05.gj", "fe_obj_o_vs2gareki06.gj",
    "kakusi_hahen27.gj", "kakusi_hahen01.gj", "kakusi_hahen02.gj", "kakusi_hahen03.gj", "kakusi_hahen04.gj", "kakusi_hahen05.gj",
    "kakusi_hahen06.gj", "kakusi_hahen07.gj", "kakusi_hahen08.gj", "kakusi_hahen09.gj", NULL
};
BmlResourceDescriptor bm_o_vs2_resource_descriptor = { "bm_o_vs2.bml", bm_o_vs2_model_names, bm_o_vs2_motion_names, 16, 0 };

const char *TOVS2__class_name = "TOVS2";
const char *TOVS2Wreck01__class_name = "TOVS2Wreck01";
const char *TOVS2Wreck02__class_name = "TOVS2Wreck02";
const char *TOVS2Wreck03__class_name = "TOVS2Wreck03";
const char *TOVS2Wreck04__class_name = "TOVS2Wreck04";
const char *TOVS2Wreck05__class_name = "TOVS2Wreck05";
const char *TOVS2Wreck06__class_name = "TOVS2Wreck06";
const char *TOVS2Wall01__class_name = "TOVS2Wall01";

extern const TObjChipParams vs2_wall_debris_desc = {
    0.25f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 7.5f, 5.0f },
    { 1024, 256, 1024 }, 1, 20, 0.0f, 0.6f, 0, 0, 20,
};

// One body per wreck model (TOVS2::TOVS2 takes entry `index`), the last one the wall's.
CollisionBody ovs2wall01_collision_parts[7] = {
    {{0.0f, 0.0f, 0.0f}, 20.0f, 30.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 15.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 12.0f, 12.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 12.0f, 12.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 12.0f, 27.0f, 1, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 10.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x38003, {0.0f, 0.0f, 0.0f}, 0.0f}
};

BmlResource *TOVS2Wall01__bml_resource;

// ---- text_8017B9AC
struct WallSetEntry { u8 unk_0[4]; s16 m_4; };

struct Ent_8017B9B0 { s16 a; s16 b; };

extern "C" {

void TOVS2Wall01__sub_8017B9AC(void *) {  }

void handle_6x86_hit_destructible_object(game_command_header *command) {
    WallHitPacket *wall_hit_packet = reinterpret_cast<WallHitPacket *>(command);
    Ent_8017B9B0 spC;
    Ent_8017B9B0 sp8;
    TOVS2Wall01 *o;
    u16 id;
    if (wall_hit_packet == NULL) {
        return;
    }
    wall_hit_packet->byteswap();
    id = wall_hit_packet->entity_id;
    if (id == 0xFFFF) {
        return;
    }
    if (id < 0x4000) {
        return;
    }
    o = (TOVS2Wall01 *)find_entity_by_id(id);
    if (o != NULL) {
        if (reinterpret_cast<TObject *>(o)->check_value_equals(TOVS2Wall01__class_name) == 0) {
            return;
        }
        switch (wall_hit_packet->update_reason) {
        case 0:
            switch (o->mode) {
            case 1:
                break;
            default:
                o->mode = 0;
            case 0:
                if (wall_hit_packet->remaining_hits < o->remaining_hits()) {
                    o->set_remaining_hits(wall_hit_packet->remaining_hits);
                }
                break;
            }
            break;
        case 1:
            o->mode = 1;
            o->break_wall();
            break;
        }
        o->access_object_saved_state(&spC, 1);
        spC.a = o->mode;
        o->access_object_saved_state(&spC, 0);
        o->vfunc_6(&spC.a, 0);
    } else {
        *(s32 *)&sp8 = *(s32 *)&quest_object_entries[wall_hit_packet->set_entry_index];
        if (sp8.a != 1) {
            sp8.a = wall_hit_packet->state;
            TLobby::apply_table_entry(wall_hit_packet->set_entry_index, &sp8);
        }
    }
}

void TOVS2Wall01::save_and_send_state(u16 arg1) {
    s16 state;
    WallHitPacket pkt;
    s16 v = mode;
    WallSetEntry *entry;
    if (arg1 == 1) {
        v = 1;
    }
    if (set_entry != NULL && access_object_saved_state(&state, 1) != 0) {
        state = v;
        access_object_saved_state(&state, 0);
        entry = (WallSetEntry *)set_entry;
        pkt.init();
        pkt.entity_id = entity_id;
        pkt.state = state;
        pkt.set_entry_index = entry->m_4;
        pkt.update_reason = arg1;
        pkt.remaining_hits = m_33c;
        pkt.send();
    }
}

}

// ---- TOVS2Wall01 (vfunc_6, spawn_debris)
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TOVS2Wall01::vfunc_6(s16 *arg1, s32 arg2) {
    s32 mode;

    if (arg1 != NULL) {
        this->mode = (s16) *arg1;
    }
    mode = this->mode;
    if (mode != 1) {
        if ((mode >= 1) || (mode < 0)) {
            this->mode = 0;
        }
    } else {
        this->m_33c = 0;
        if (arg2 != 0) {
            break_wall();
        }
    }
}

// Throws the wall's debris chips (models 7-15 of bm_o_vs2.bml, one per call).
void TOVS2Wall01::spawn_debris(s32 index) {
    TObjChipParams params = vs2_wall_debris_desc;

    params.pos.x = body_center.x;
    params.pos.y = body_center.y;
    params.pos.z = body_center.z;
    params.floor_y = position.y;
    params.model = get_bml_model(TOVS2Wall01__bml_resource, index);
    params.textures = get_bml_texlist(TOVS2Wall01__bml_resource, index);
    new TObjChip(tl_05, &params);
}

#pragma pop

// ---- TOVS2Wall01_8017BCC8


void TOVS2Wall01::break_wall() {
    s32 index;

    clear_player_status_flag(0, 1);
    index = 7;
    do {
        spawn_debris(index);
        index += 1;
    } while (index <= 0xF);
    spawn_particle_effect(&position, 0x45);
    spawn_particle_effect(&position, 0x46);
    play_sound_effect(0x4004BC05, &position, 0, 0);
}

f32 TOVS2Wall01::take_hit(TObjBase *attacker) {
    TObjPlayer *player = NULL;

    attacker->get_entity_id();
    if (attacker->get_entity_id() < 4U) {
        player = (TObjPlayer *)attacker;
    }
    if ((player != NULL) && (TObjPlayer::is_locally_controlled(player) == 1)) {
        m_33c--;
        if ((s32)m_33c <= 0) {
            m_33c = 0;
            save_and_send_state(1);
        } else {
            save_and_send_state(0);
        }
        spawn_particle_effect(&position, 0x1D0);
        spawn_particle_effect(&position, 1);
    }
    return 0.0f;
}


// ---- TOVS2Wall01_8017BE08
struct VBase_14_1eb8da { char pad[0x14]; };
struct VObj_14_1eb8da : VBase_14_1eb8da {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6(s32, s32);
    virtual s32 m7();
};
extern "C" {
s32 post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
int submit_cursor_candidate(void*, int);
// ---- TOVS2Wall01_8017C7A4
#pragma defer_codegen on
// The shared byte-swap entry operates on the first three packet words.
void bswap_header__6TLobbyFv(WallHitPacket *packet);

WallHitPacket *WallHitPacket::init() {
    init_collision_subcommand_header(this);
    update_reason = 0;
    remaining_hits = 0;
    subcommand = 0x86;
    word_count = 4;
    return this;
}

void WallHitPacket::send() {
    byteswap();
    send_subcommand((u8 *)this);
}

void WallHitPacket::byteswap() {
    bswap_header__6TLobbyFv(this);
    bswap_16(&update_reason);
    bswap_16(&remaining_hits);
}

s32 TOVS2Wall01::remaining_hits() { return (s32)m_33c; }
void TOVS2Wall01::set_remaining_hits(s32 count) { m_33c = count; }
}
void TOVS2Wall01::apply_knockback_from_attacker(u8 *, f32) {  }
f32 TOVS2Wall01::receive_weapon_special_attack(void *attacker, void *) { return take_hit((TObjBase *)attacker); }
f32 TOVS2Wall01::receive_direct_attack(void *attacker, DirectAttackPayload, void *, s32, s32) { return take_hit((TObjBase *)attacker); }
f32 TOVS2Wall01::receive_physical_attack(void *attacker, f32) { return take_hit((TObjBase *)attacker); }
int TOVS2Wall01::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }
s32 TOVS2Wall01::select_melee_contact_body(void *, f32) { return 1; }
s32 TOVS2Wall01::roll_physical_accuracy(void *, s32, f32) { return 1; }
s32 TOVS2Wall01::try_start_action(s32, s32) { return 1; }
TOVS2::TOVS2(void *set_data, s32 index) : TObjMapObject((TObject *)tl_05) {
    m_name = TOVS2__class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(TOVS2Wall01__bml_resource, index);
    model_radius = 50.0f + static_cast<GinjaModelBounds *>(static_cast<NJS_OBJECT *>(model)->model)->radius;
    texlist = get_bml_texlist((BmlResource *)TOVS2Wall01__bml_resource, index);
    init_collision_body_parts(this, &ovs2wall01_collision_parts[index], 1);
    register_object_by_id();
    m_c8 = TObjMapCsn::create(set_data);
    m_cc = 1;
}
TOVS2::~TOVS2() {
    if (m_c8 != NULL) {
        m_c8->queue_destruction();
        m_c8 = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOVS2Wall01::load_resources() {
  saddr temp_r3;
  saddr resource;
  resource = (saddr)new BmlResource(1, &bm_o_vs2_resource_descriptor, 0, 0, NULL);
  TOVS2Wall01__bml_resource = (BmlResource *)resource;
  TObjNpcEnemy::register_ginja(0x3A, reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TOVS2Wall01__bml_resource, 5)),
                        reinterpret_cast<NJS_TEXLIST *>(get_bml_texlist((BmlResource *)resource, 5)), 10.0f, 0.0f);
}
void TOVS2Wall01::release_model() {
    if (TOVS2Wall01__bml_resource != NULL) {
        delete TOVS2Wall01__bml_resource;
        TOVS2Wall01__bml_resource = NULL;
    }
}
void TOVS2::render() {
    this->m_cc = this->update_object_view_visibility(this->view_range, this->model_radius);
    if ((s32) this->m_cc == 1) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        draw_ginja_object(this->model);
        pop_matrix();
    }
}
TOVS2Wreck01::TOVS2Wreck01(void *set_data) : TOVS2(set_data, 0) {
    m_name = TOVS2Wreck01__class_name;
}

TOVS2Wreck01::~TOVS2Wreck01() {}

void *TOVS2Wreck01::create(void *set_data) {
    return new TOVS2Wreck01(set_data);
}
TOVS2Wreck02::TOVS2Wreck02(void *set_data) : TOVS2(set_data, 1) {
    m_name = TOVS2Wreck02__class_name;
}

TOVS2Wreck02::~TOVS2Wreck02() {}

void *TOVS2Wreck02::create(void *set_data) {
    return new TOVS2Wreck02(set_data);
}
TOVS2Wreck03::TOVS2Wreck03(void *set_data) : TOVS2(set_data, 2) {
    m_name = TOVS2Wreck03__class_name;
}

TOVS2Wreck03::~TOVS2Wreck03() {}

void *TOVS2Wreck03::create(void *set_data) {
    return new TOVS2Wreck03(set_data);
}
TOVS2Wreck04::TOVS2Wreck04(void *set_data) : TOVS2(set_data, 3) {
    m_name = TOVS2Wreck04__class_name;
}

TOVS2Wreck04::~TOVS2Wreck04() {}

void *TOVS2Wreck04::create(void *set_data) {
    return new TOVS2Wreck04(set_data);
}
TOVS2Wreck05::TOVS2Wreck05(void *set_data) : TOVS2(set_data, 4) {
    m_name = TOVS2Wreck05__class_name;
}

TOVS2Wreck05::~TOVS2Wreck05() {}

void *TOVS2Wreck05::create(void *set_data) {
    return new TOVS2Wreck05(set_data);
}
TOVS2Wreck06::TOVS2Wreck06(void *set_data) : TOVS2(set_data, 5) {
    m_name = TOVS2Wreck06__class_name;
}

TOVS2Wreck06::~TOVS2Wreck06() {}

void *TOVS2Wreck06::create(void *set_data) {
    return new TOVS2Wreck06(set_data);
}
#pragma push
#pragma opt_common_subs off
TOVS2Wall01::TOVS2Wall01(void *set_data) : TObjChara((TObject *)tl_05) {
    s32 initial_hits;
    m_name = TOVS2Wall01__class_name;
    apply_object_set_data(set_data);
    calc_attach_pos();
    set_actor_flags(0x60000000);
    model = (void *)get_bml_model((BmlResource *)TOVS2Wall01__bml_resource, 6);
    texlist = get_bml_texlist((BmlResource *)TOVS2Wall01__bml_resource, 6);
    init_collision_body_parts(this, &ovs2wall01_collision_parts[6], 1);
    set_indexed_flags(0, 0x08000000);
    register_object_by_id();
    mode = 0;
    view_range = 800.0f;
    m_338 = 50.0f + static_cast<GinjaModelBounds *>(static_cast<NJS_OBJECT *>(model)->model)->radius;
    initial_hits = set_params[0];
    m_33c = initial_hits + 0x100;
    m_340.activate_and_dispatch();
    m_35c = 1;
}
#pragma pop
TOVS2Wall01::~TOVS2Wall01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TOVS2Wall01::create(void *set_data) {
    return new TOVS2Wall01(set_data);
}
void TOVS2Wall01::render() {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;
    m_340.update();
    *(s32 *)&this->m_35c = this->update_object_view_visibility(view_range, m_338);
    if ((s32) this->m_35c == 1) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            var_r31 = 0;
        } else {
            var_r31 = m_340.updateFromCamera(&position.x);
        }
        if (var_r31 != 0) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            ((VObj_14_1eb8da *)(arg0 + (832)))->m6(chunk_polygon_flags_and_mask, model_render_flags);
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        draw_ginja_object(this->model);
        pop_matrix();
        if (var_r31 != 0) {
            ((VObj_14_1eb8da *)(arg0 + (832)))->m7();
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}
void TOVS2Wall01::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TOVS2Wall01__sub_8017B9AC(arg0);
        return;
    }
    switch (this->mode) {
    default:
        this->mode = 0;
    case 0:
        interact_player_neg1();
        return;
    case 1:
        release();
        return;
    }
}
int TOVS2Wall01::interact_player_neg1() { return submit_cursor_candidate(this, -1); }
void TOVS2Wall01::release() { set_flag8(); queue_destruction(); }
