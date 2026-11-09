// Compiled -inline off,deferred: the functions are written from the last
// (0x80354B18 load_resources) back to the first (0x803537D4), so CodeWarrior
// emits them in address order and the TUnk_804F1280 vtable before TBoss6Rock's.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/boss/olgaflow/Boss6Type2Data.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/TUnk_804F1280.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

extern "C" {
// Defined in text_803D96A8.cpp; its header does not declare it yet (the
// callers' private prototypes disagree on the return type).
f32 normalize_vector(Vec *v);
// TBoss6PlotFalz.cpp; same declaration as TBoss6Type1/TBoss6Type2 use.
void TBoss6PlotFalz__sub_802AC724(void *player, void *pos);
// TBoss6Type2.cpp: the arena radius (its centre is declared in Boss6Type2Data.h).
extern const f32 lbl_805DE3F0;
// query_teammate_state__9TObjEneDDFv() is a static the header declares as a
// member; every caller (28) uses this name until that is fixed.
int query_teammate_state__9TObjEneDDFv(void);
}

const char *boss06_rock_dat_model_names[8] = {
    "b_iwa_p_ori.gj",      "b_iwa_p_p01.gj",      "b_iwa_p_p02.gj",       "b_iwa_p_p03.gj",
    "waste_koware_ori.gj", "waste_koware_p01.gj", "waste_koware1_p02.gj", NULL,
};
const char *boss06_rock_dat_motion_names[1] = {NULL};
BmlResourceDescriptor boss6_rock_resource_descriptor = {
    "boss06_rock_dat.bml", boss06_rock_dat_model_names, boss06_rock_dat_motion_names, 7, 0,
};
const char *TBoss6Rock::class_name = "TBoss6Rock";

const RockKindParams TBoss6Rock__data_80479258[2] = {
    {4, 10.0f, 35.0f, 7.2000003f, 19.2f},
    {0, 20.0f, 35.0f, 14.400001f, 33.4f},
};
const s32 lbl_80479280[3] = {0, 0, 0};

BmlResource *TBoss6Rock__data_805D6EF0;        // model resource
GinjaTextureList *TBoss6Rock__data_805D6EF4;   // texture list
TBoss6Type2 *TBoss6Rock__data_805D6EF8;        // the owner; NULL makes every rock go away
s32 lbl_805D6EFC;                              // damage of a landing rock
TBoss6Rock *TBoss6Rock__instance_table[32];
Vec TBoss6Rock__rock_point_table[32];

/* One ring of rock points around the arena centre. */
struct RockRing {
    f32 radius;
    s32 count;
};

void TBoss6Rock::load_resources() {
    BmlResource *resource;
    s32 i;
    resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &boss6_rock_resource_descriptor, 0, 0, 0);
    }
    TBoss6Rock__data_805D6EF0 = resource;
    TBoss6Rock__data_805D6EF4 = (GinjaTextureList *)load_gvm_texture_file((s32) "boss06_rock_dat.gvm");
    if (TBoss6Rock__data_805D6EF0 == NULL || TBoss6Rock__data_805D6EF4 == NULL) {
        return;
    }
    TBoss6Rock__sub_80354188();
    for (i = 0; i < 32; i++) {
        TBoss6Rock__instance_table[i] = NULL;
    }
    lbl_805D6EFC = *(f32 *)((u8 *)TLobby::dispatch_shared_handler_a(0x2C) + 0xC);
    if (lbl_805D6EFC < 1) {
        lbl_805D6EFC = 20;
    }
}

void TBoss6Rock::free_data() {
    if (TBoss6Rock__data_805D6EF0 != NULL) {
        free_bin_model_request(TBoss6Rock__data_805D6EF0, 1);
        TBoss6Rock__data_805D6EF0 = NULL;
    }
    if (TBoss6Rock__data_805D6EF4 != NULL) {
        release_texture_list(TBoss6Rock__data_805D6EF4);
        TAdSinglePlyChrSelectGC::safe_free((u32)TBoss6Rock__data_805D6EF4);
        TBoss6Rock__data_805D6EF4 = NULL;
    }
}

void TBoss6Rock::create_rock_pool(s32 owner) {
    s32 i;
    if (TBoss6Rock__data_805D6EF0 == NULL || TBoss6Rock__data_805D6EF4 == NULL) {
        return;
    }
    TBoss6Rock__data_805D6EF8 = (TBoss6Type2 *)owner;
    for (i = 0; i < 32; i++) {
        TBoss6Rock__instance_table[i] = create(i);
    }
}

void TBoss6Rock__sub_80354A44(void) {
    TBoss6Rock__data_805D6EF8 = NULL;
}

s32 TBoss6Rock::is_active() {
    return TBoss6Rock__data_805D6EF8 != NULL;
}

TBoss6Rock *TBoss6Rock::create(s32 index) {
    return new TBoss6Rock(tl_02, index);
}

TBoss6Rock::TBoss6Rock(TObject *parent, s32 index) : TObjCollidable(parent) {
    m_name = class_name;
    m_ac = index;
    VecCopy(&m_d4, &TBoss6Rock__rock_point_table[m_ac]);
    m_b8 = 0;
    m_b4 = 0;
    m_c0 = 0;
    m_bc = 0;
    m_b0 = 0;
    randomize_motion();
    m_c8 = 0;
    m_c4 = 0;
    m_e4 = create();
}

TBoss6Rock::~TBoss6Rock() {
    if (m_c4 != 0) {
        ((TBoss6Rock *)&m_d4)->spawn_crush_rocks(m_b4);
    }
    release_object();
    TBoss6Rock__instance_table[m_ac] = NULL;
}

void TBoss6Rock::run_task() {
    if (is_active() == 0) {
        queue_destruction();
        return;
    }
    if (query_teammate_state__9TObjEneDDFv() != 0) {
        return;
    }
    switch (m_c4) {
    case 0:
        init_spin_params();
        break;
    case 1:
        update_fall();
        break;
    case 2:
        break_and_release();
        break;
    }
    if (m_e4 != NULL) {
        s32 model = get_bml_model(TBoss6Rock__data_805D6EF0, TBoss6Rock__data_80479258[m_b4].model_id);
        u64 pos = (s32)&position;
        m_e4->set_target(m_c4 != 0, (Vec *)pos, &rotation_x, (s32)TBoss6Rock__data_805D6EF4, model,
                         TBoss6Rock__data_80479258[m_b4].radius);
    }
}

void TBoss6Rock::render() {
    if (is_active() != 0) {
        draw_model();
    }
}

void TBoss6Rock::draw_model() {
    if (m_c4 == 0) {
        return;
    }
    if (m_e4 != NULL) {
        if (TBoss6PlotFalz__sub_802AB6CC(&position, TBoss6Rock__data_80479258[m_b4].radius - 3.0f) != 0) {
            return;
        }
    }
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    rotate_matrix_z(NULL, rotation_z);
    TObjFish::set_global_param((s32)TBoss6Rock__data_805D6EF4);
    draw_ginja_object((void *)get_bml_model(TBoss6Rock__data_805D6EF0, TBoss6Rock__data_80479258[m_b4].model_id));
    pop_matrix();
}

void TBoss6Rock::init_spin_params() {
    if (m_c8 != 0) {
        m_cc = -9.0f * (0.5f * ((m_ac & 3) / 3.0f) + 0.5f * (m_ac / 32.0f));
        m_c4 = 1;
        m_b4 = m_b8;
        m_bc = m_c0;
    }
}

void TBoss6Rock::update_fall() {
    f32 accel = -0.75f;
    f32 max_speed = -9.0f;
    rotation_y += m_d0;
    if (m_bc == 1) {
        accel = -0.9375f;
        max_speed = -11.25f;
    }
    m_cc += accel;
    if (m_cc < max_speed) {
        m_cc = max_speed;
    }
    position.y += m_cc;
    if (position.y <= 0.0f) {
        position.y = 0.0f;
        m_cc = 0.0f;
        TBoss6Rock__sub_803542E8(this, 1);
        sub_80353F5C();
        play_sound_effect(0x4006B51E, &position, 0, 0);
        spawn_particle_effect(&position, 0x220);
        spawn_particle_effect(&position, 0x222);
        TBoss6PlotFalz::apply_radial_effect_to_players(&position, 0xC0, 0xF, 100.0f);
        m_c4 = 2;
    }
}

void TBoss6Rock::break_and_release() {
    TBoss6Rock__sub_803542E8(this, 0);
    if (m_bc == 1) {
        m_c8 = 0;
    }
    if (m_c8 != 2) {
        ((TBoss6Rock *)&m_d4)->spawn_crush_rocks(m_b4);
        play_sound_effect(0x4006AB1F, &position, 0, 0);
        release_object();
        randomize_motion();
        m_c4 = 0;
    }
}

void TBoss6Rock__sub_803542E8(TBoss6Rock *rock, s32 landed) {
    s32 count;
    s32 i;
    TObjPlayer *player;
    f32 radius;
    f32 dist;
    Vec d;

    if (landed == 0) {
        rock->m_e0++;
        if (rock->m_e0 & 1) {
            return;
        }
    }
    count = TLobby::get_game_mode();
    radius = TBoss6Rock__data_80479258[rock->m_b4].radius;
    if (landed != 0) {
        radius += 10.0f;
    }
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (((TBoss6PlotFalz *)player)->is_active() == 0) {
            continue;
        }
        VecCopy(&d, &player->position);
        subtract_vector(&d, &rock->m_d4);
        d.y = 0.0f;
        dist = vector_length(&d);
        if (dist >= radius) {
            continue;
        }
        if (dist <= 1e-05f) {
            d.x = 1.0f;
        }
        normalize_vector(&d);
        d.x *= radius;
        d.z *= radius;
        vec3_add_to(&d, &rock->m_d4);
        TBoss6PlotFalz__sub_802AC724(player, &d);
        if (landed != 0) {
            DirectAttackPayload h;
            s32 damage = TBoss6PlotFalz::rand_vary_count(lbl_805D6EFC, 0.1f);
            h.kind = 0;
            h.power = damage;
            player->receive_direct_attack(TBoss6Rock__data_805D6EF8, h, 0, -1, -1);
        }
    }
}

void TBoss6Rock__sub_80354188(void) {
    static RockRing rings[4] = {
        {5.0f * lbl_805DE3F0 / 7.0f, 8},
        {4.0f * lbl_805DE3F0 / 7.0f, 8},
        {3.0f * lbl_805DE3F0 / 7.0f, 8},
        {2.0f * lbl_805DE3F0 / 7.0f, 8},
    };
    s32 n = 0;
    for (s32 i = 0; i < 4; i++) {
        f32 r = rings[i].radius;
        s32 count = rings[i].count;
        s32 step = 0x10000 / count;
        s32 angle = (i & 1) * (step / 2);
        for (s32 j = 0; j < count; j++) {
            if (n >= 32) {
                return;
            }
            Vec p = boss6_arena_center;
            p.x += r * sin_table_lookup(angle);
            p.z += r * cos_table_lookup(angle);
            VecCopy(&TBoss6Rock__rock_point_table[n], &p);
            angle += step;
            n++;
        }
    }
}

const RockKindParams *TBoss6Rock::get_rock_entry(s32 i) {
    if (i < 0 || i >= 32) {
        return NULL;
    }
    return &TBoss6Rock__data_80479258[TBoss6Rock__instance_table[i]->m_b4];
}

void TBoss6Rock::randomize_motion() {
    rotation_x = 2048.0f * (3.0517578125e-05f * rand() - 0.5f);
    rotation_y = 65535.0f * (3.0517578125e-05f * rand());
    rotation_z = 2048.0f * (3.0517578125e-05f * rand() - 0.5f);
    m_d0 = 8192.0f * (3.0517578125e-05f * rand() - 0.5f);
    VecCopy(&position, &m_d4);
    position.y = 450.0f;
}

void TBoss6Rock::sub_80353F5C() {
    RockKindParams *new_var;
    MapCsnSetData set;
    u8 *new_var2;
    RockKindParams *e;
    do { } while (0);
    if (m_b0 == 0) {
        VecCopy(&set.position, &m_d4);
        copy_xyz(&set.rotation_x, (void *)lbl_80479280);
        new_var2 = (u8 *)((RockKindParams *)&TBoss6Rock__data_80479258);
        new_var2 = (m_b4 * 0x14) + new_var2;
        new_var = (RockKindParams *)new_var2;
        e = new_var;
        set.params[0] = 2;
        set.params[1] = 0;
        set.scale.z = e->width;
        set.scale.x = e->width;
        set.scale.y = e->height;
        m_b0 = TObjMapCsn::create((s32)&set);
    }
}

void TBoss6Rock::release_object() {
    if (m_b0 != 0) {
        ((TObject *)m_b0)->queue_destruction();
        m_b0 = 0;
    }
}

void TBoss6Rock::set_rock_target(s32 i, s32 a, s32 b) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock != NULL) {
        rock->m_c8 = 2;
        rock->m_b8 = a;
        rock->m_c0 = b;
    }
}

void TBoss6Rock::clear_rock_state(s32 i) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock != NULL) {
        rock->m_c8 = 0;
    }
}

void TBoss6Rock::reset_rock_state(s32 i) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock == NULL || rock->m_c4 != 2) {
        return;
    }
    rock->m_c8 = 0;
}

s32 TBoss6Rock::is_rock_valid(s32 i) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return 0;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock == NULL) {
        return 0;
    }
    return rock->m_c4 == 2;
}

s32 TBoss6Rock::is_rock_state_2(int i) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return 0;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock == NULL) {
        return 0;
    }
    return rock->m_c8 == 2;
}

s32 TBoss6Rock::get_point(s32 i, s32 out, f32 *radius) {
    if (is_rock_valid(i) == 0) {
        return 0;
    }
    VecCopy((Vec *)out, &TBoss6Rock__rock_point_table[i]);
    *radius = get_rock_entry(i)->radius;
    return 1;
}

s32 TBoss6Rock::push_out_of_rocks(f32 r) {
    Vec v;
    s32 hit;
    s32 i;
    f32 y = 0.0f;
    f32 lim = 20.0f + r;
    hit = 0;
    for (i = 0; i < 32; i++) {
        f32 d;
        VecCopy(&v, (Vec *)this);
        subtract_vector(&v, &TBoss6Rock__rock_point_table[i]);
        v.y = y;
        d = vector_length(&v);
        if (!(d >= lim)) {
            if (d <= 1e-05f) {
                v.x = 1.0f;
            }
            normalize_vector(&v);
            v.x *= lim;
            v.z *= lim;
            vec3_add_to((Vec *)this, &v);
            hit = 1;
        }
    }
    return hit;
}

void TBoss6Rock::break_rocks_in_radius(f32 r) {
    Vec v;
    s32 i;
    const RockKindParams *kind;
    for (i = 0; i < 32; i++) {
        kind = get_rock_entry(i);
        if (kind != NULL && is_rock_state_2(i) != 0 && !(((Vec *)this)->y > r + kind->height)) {
            f32 lim = r + kind->radius;
            VecCopy(&v, &TBoss6Rock__rock_point_table[i]);
            subtract_vector(&v, (Vec *)this);
            v.y = 0.0f;
            if (vector_length(&v) <= lim) {
                clear_rock_state(i);
            }
        }
    }
}

s32 TBoss6Rock__sub_80353A14(s32 i, Vec *out, f32 *radius) {
    const RockKindParams *kind;
    f32 r;
    f32 d;
    f32 s;
    Vec a;
    Vec b;
    Vec c;
    if (TBoss6Rock::is_rock_valid(i) == 0) {
        return 0;
    }
    if (TBoss6Rock__data_805D6EF8 == NULL) {
        return 0;
    }
    kind = TBoss6Rock::get_rock_entry(i);
    if (kind == NULL) {
        return 0;
    }
    r = kind->radius;
    VecCopy(&a, (Vec *)&TBoss6Rock__data_805D6EF8->position);
    a.y = 0.0f;
    VecCopy(&b, &TBoss6Rock__rock_point_table[i]);
    VecCopy(&c, &b);
    subtract_vector(&c, &a);
    d = vector_length(&c);
    if (d <= 100.0f) {
        return 0;
    }
    if (d > 200.0f) {
        d = 200.0f;
    }
    normalize_vector(&c);
    s = r - r * (1.0f - (d - 100.0f) / 100.0f);
    c.x *= s;
    c.z *= s;
    vec3_add_to(&c, &b);
    VecCopy(out, &c);
    *radius = r;
    return 1;
}

int TBoss6Rock__sub_80353A0C(void) {
    return (int)TBoss6Rock__data_805D6EF0;
}

int TBoss6Rock__sub_80353A04(void) {
    return (int)TBoss6Rock__data_805D6EF4;
}

TUnk_804F1280 *TBoss6Rock::create() {
    return new TUnk_804F1280(tl_06);
}

TUnk_804F1280::TUnk_804F1280(TObject *parent) : TObject(parent) {
    enabled = 0;
}

TUnk_804F1280::~TUnk_804F1280() {
}

void TUnk_804F1280::run_task() {
    if (TBoss6Rock::is_active() == 0) {
        enabled = 0;
        queue_destruction();
    }
}

void TUnk_804F1280::render() {
    if (enabled != 0 && TBoss6PlotFalz__sub_802AB6CC(&position, radius - 3.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        rotate_matrix_x(NULL, rotation_x);
        rotate_matrix_z(NULL, rotation_z);
        TObjFish::set_global_param(texlist);
        TBoss6PlotFalz::set_fade_material_color(0.5f);
        draw_ginja_object((void *)model);
        TObjFish::reset_fish_globals();
        pop_matrix();
    }
}

void TUnk_804F1280::set_target(s32 enabled, Vec *position, s32 *rotation, s32 texlist, s32 model, f32 radius) {
    this->enabled = enabled;
    if (this->enabled != 0) {
        VecCopy(&this->position, position);
        copy_xyz(&rotation_x, rotation);
        this->radius = radius;
        this->texlist = texlist;
        this->model = model;
    }
}
