#include "types.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/TLobby.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"

#pragma readonly_strings on
const char *TBoss6Demo15_TYPE2_WAIT__class_name = "TBoss6Demo15_TYPE2_WAIT";

static const Vec lbl_80478430 = {-10000.0f, 0.0f, 0.0f};
static const WaitDemoCsnEntry lbl_8047843C[10] = {
    {{-10010.0f, 0.0f, -30.0f}, {145.0f, 100.0f, 80.0f}, 0},
    {{-10040.0f, 0.0f, 50.0f}, {110.0f, 75.0f, 100.0f}, 0},
    {{-10095.0f, 0.0f, -35.0f}, {80.0f, 15.0f, 15.0f}, 0xD800},
    {{-10000.0f, 0.0f, -125.0f}, {30.0f, 10.0f, 150.0f}, 0xEE00},
    {{-9958.0f, 0.0f, -95.0f}, {15.0f, 10.0f, 50.0f}, 0},
    {{-9930.0f, 0.0f, -37.0f}, {38.0f, 40.0f, 100.0f}, 0xEE00},
    {{-9982.0f, 0.0f, 125.0f}, {17.0f, 10.0f, 75.0f}, 0xFA00},
    {{-9958.0f, 0.0f, 140.0f}, {45.0f, 10.0f, 5.0f}, 0x1000},
    {{-10005.0f, 0.0f, 137.0f}, {45.0f, 10.0f, 5.0f}, 0xDC00},
    {{-10112.0f, 0.0f, 125.0f}, {20.0f, 10.0f, 120.0f}, 0xF2C0},
};
static const Vec lbl_80478554 = {-10000.0f, 0.0f, 0.0f};

__declspec(section ".data") s32 lbl_804EFB70[2] = {0x1F, 0x21};

void TBoss6Demo15_TYPE2_WAIT::draw_parts() {
    s32 i;
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&lbl_80478430.x);
    for (i = 0; i < 2; i++) {
        TObjFish::set_global_param(parts[i].texlist);
        draw_model_motion(parts[i].model, parts[i].motion, 0.0f);
    }
    clear_motion_packed_rotation();
    pop_matrix();
}

s32 TBoss6Demo15_TYPE2_WAIT::get_plot_state() { return player_near; }

#pragma push
#pragma fp_contract on
void TBoss6Demo15_TYPE2_WAIT::update_orbit_position() {
    f32 radius = (40.0f * sin_table_lookup(radius_phase)) + 230.0f;
    f32 s = sin_table_lookup(orbit_angle);
    f32 c = cos_table_lookup(orbit_angle);
    VecCopy(&position, &lbl_80478554);
    position.x = (s * radius) + position.x;
    position.z = (c * radius) + position.z;
    position.y += 20.0f;
}
#pragma pop

void TBoss6Demo15_TYPE2_WAIT::advance_offset() {
    orbit_angle += 54.613335f;
    radius_phase += 873.81335f;
}

void TBoss6Demo15_TYPE2_WAIT::reset_orbit() {
    orbit_angle = 0x6000;
    radius_phase = 0;
}

void TBoss6Demo15_TYPE2_WAIT::check_any_player_near() {
    Vec v;
    s32 n;
    s32 i;
    TObjPlayer *p;
    player_near = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(p) != 0) {
            VecCopy(&v, &position);
            subtract_vector(&v, &p->position);
            v.y = 0.0f;
            if (vector_length(&v) <= 25.0f) {
                player_near = 1;
                return;
            }
        }
    }
}

void TBoss6Demo15_TYPE2_WAIT::destroy_csn_objects() {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (csn_objects[i] != NULL) {
            csn_objects[i]->queue_destruction();
            csn_objects[i] = NULL;
        }
    }
}

void TBoss6Demo15_TYPE2_WAIT::create_csn_objects() {
    MapCsnSetData set;
    s32 i;
    s32 j;
    for (j = 0; j < 10; j++) {
        csn_objects[j] = NULL;
    }
    set.params[0] = 2;
    set.params[1] = 0;
    for (i = 0; i < 10; i++) {
        const WaitDemoCsnEntry *e = &lbl_8047843C[i];
        VecCopy(&set.position, &e->position);
        set.rotation_x = 0;
        set.rotation_y = e->rotation_y;
        set.rotation_z = 0;
        VecCopy(&set.scale, &e->scale);
        csn_objects[i] = TObjMapCsn::create(&set);
    }
}

void TBoss6Demo15_TYPE2_WAIT::render() { draw_parts(); }

void TBoss6Demo15_TYPE2_WAIT::run_task() {
    if (TObjEneDD::query_teammate_state() == 0) {
        advance_offset();
        VecCopy(&prev_position, &position);
        update_orbit_position();
        if (emitter != NULL) {
            emitter->set_position(&position);
        }
        check_any_player_near();
        play_persistent_sound(0x4003A126, this, &position, 0, 0);
        if (plot->get_scene_state() != 4) {
            queue_destruction();
        }
    }
}

TBoss6Demo15_TYPE2_WAIT::~TBoss6Demo15_TYPE2_WAIT() {
    if (emitter != NULL) {
        TParticleCtrl::release(emitter);
        emitter = NULL;
    }
    destroy_csn_objects();
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
TBoss6Demo15_TYPE2_WAIT::TBoss6Demo15_TYPE2_WAIT(TBoss6PlotFalz *plot) : TObject(plot) {
    s32 id;
    BmlResource *bml;
    s32 i;
    m_name = TBoss6Demo15_TYPE2_WAIT__class_name;
    this->plot = plot;
    bml = TBoss6PlotFalz::get_scene_archive();
    for (i = 0; i < 2; i++) {
        {
            s32 t = boss6_type1_part_model_ids[i];
            id = t;
            parts[i].model = get_bml_model(bml, t);
        }
        parts[i].texlist = get_bml_texlist(bml, id);
        parts[i].motion = get_bml_motion(bml, lbl_804EFB70[i]);
    }
    create_csn_objects();
    reset_orbit();
    update_orbit_position();
    VecCopy(&prev_position, &position);
    emitter = create_particle_emitter(&position, 0x225);
    if (emitter != NULL) {
        emitter->set_flags(0x40);
    }
    player_near = 0;
}
#pragma pop

TBoss6Demo15_TYPE2_WAIT *TBoss6Demo15_TYPE2_WAIT::alloc(TBoss6PlotFalz *plot) { return new TBoss6Demo15_TYPE2_WAIT(plot); }
