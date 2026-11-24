#include "pso/system/memory.h"
#include "pso/system/BmlResourceLoader.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlAccessors.h"
// Compiled -inline off,deferred: the functions are written from the last
// (0x80354B18 load_resources) back to the first (0x803537D4), so CodeWarrior
// emits them in address order and the TUnk_804F1280 vtable before TBoss6Rock's.
#include "pso/effect/particle/TParticleCtrl.h"
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
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/dd/TObjEneDD.h"

const char *boss06_rock_dat_model_names[8] = {
    "b_iwa_p_ori.gj",      "b_iwa_p_p01.gj",      "b_iwa_p_p02.gj",       "b_iwa_p_p03.gj",
    "waste_koware_ori.gj", "waste_koware_p01.gj", "waste_koware1_p02.gj", NULL,
};
const char *boss06_rock_dat_motion_names[1] = {NULL};
BmlResourceDescriptor boss6_rock_resource_descriptor = {
    "boss06_rock_dat.bml", boss06_rock_dat_model_names, boss06_rock_dat_motion_names, 7, 0,
};
const char *TBoss6Rock::class_name = "TBoss6Rock";

const RockKindParams boss6_rock_kind_params[2] = {
    {4, 10.0f, 35.0f, 7.2000003f, 19.2f},
    {0, 20.0f, 35.0f, 14.400001f, 33.4f},
};
const s32 boss6_rock_set_rotation[3] = {0, 0, 0};

BmlResource *boss6_rock_resource;        // model resource
NJS_TEXLIST *boss6_rock_texture_list;   // texture list
TBoss6Type2 *boss6_rock_owner;        // the owner; NULL makes every rock go away
s32 boss6_rock_damage;                              // damage of a landing rock
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
    resource = new BmlResource(5, &boss6_rock_resource_descriptor, 0, 0, NULL);
    boss6_rock_resource = resource;
    boss6_rock_texture_list = load_gvm_texture_file("boss06_rock_dat.gvm");
    if (boss6_rock_resource == NULL || boss6_rock_texture_list == NULL) {
        return;
    }
    init_rock_points();
    for (i = 0; i < 32; i++) {
        TBoss6Rock__instance_table[i] = NULL;
    }
    boss6_rock_damage = TLobby::dispatch_shared_handler_a(0x2C)->values.floats[3];
    if (boss6_rock_damage < 1) {
        boss6_rock_damage = 20;
    }
}

void TBoss6Rock::free_data() {
    if (boss6_rock_resource != NULL) {
        delete boss6_rock_resource;
        boss6_rock_resource = NULL;
    }
    if (boss6_rock_texture_list != NULL) {
        release_texture_list(boss6_rock_texture_list);
        safe_free(boss6_rock_texture_list);
        boss6_rock_texture_list = NULL;
    }
}

void TBoss6Rock::create_rock_pool(TBoss6Type2 *owner) {
    s32 i;
    if (boss6_rock_resource == NULL || boss6_rock_texture_list == NULL) {
        return;
    }
    boss6_rock_owner = owner;
    for (i = 0; i < 32; i++) {
        TBoss6Rock__instance_table[i] = create(i);
    }
}

void TBoss6Rock::clear_owner() {
    boss6_rock_owner = NULL;
}

s32 TBoss6Rock::is_active() {
    return boss6_rock_owner != NULL;
}

TBoss6Rock *TBoss6Rock::create(s32 index) {
    return new TBoss6Rock(tl_02, index);
}

TBoss6Rock::TBoss6Rock(TObject *parent, s32 index) : TObjCollidable(parent) {
    m_name = class_name;
    rock_index = index;
    VecCopy(&rock_point, &TBoss6Rock__rock_point_table[rock_index]);
    next_kind_index = 0;
    kind_index = 0;
    next_fast_fall = 0;
    fast_fall = 0;
    map_csn = 0;
    randomize_motion();
    command = 0;
    fall_state = 0;
    marker = create();
}

TBoss6Rock::~TBoss6Rock() {
    if (fall_state != 0) {
        spawn_crush_rocks(&rock_point, kind_index);
    }
    release_object();
    TBoss6Rock__instance_table[rock_index] = NULL;
}

void TBoss6Rock::run_task() {
    if (is_active() == 0) {
        queue_destruction();
        return;
    }
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    switch (fall_state) {
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
    if (marker != NULL) {
        saddr model = (saddr)get_bml_model(boss6_rock_resource, boss6_rock_kind_params[kind_index].model_id);
        u64 pos = (saddr)&position;
        marker->set_target(fall_state != 0, (Vec *)pos, &rotation_x, (saddr)boss6_rock_texture_list, model,
                         boss6_rock_kind_params[kind_index].radius);
    }
}

void TBoss6Rock::render() {
    if (is_active() != 0) {
        draw_model();
    }
}

void TBoss6Rock::draw_model() {
    if (fall_state == 0) {
        return;
    }
    if (marker != NULL) {
        if (TBoss6PlotFalz__sub_802AB6CC(&position, boss6_rock_kind_params[kind_index].radius - 3.0f) != 0) {
            return;
        }
    }
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    rotate_matrix_z(NULL, rotation_z);
    TObjFish::set_global_param(boss6_rock_texture_list);
    draw_ginja_object((void *)get_bml_model(boss6_rock_resource, boss6_rock_kind_params[kind_index].model_id));
    pop_matrix();
}

void TBoss6Rock::init_spin_params() {
    if (command != 0) {
        fall_speed = -9.0f * (0.5f * ((rock_index & 3) / 3.0f) + 0.5f * (rock_index / 32.0f));
        fall_state = 1;
        kind_index = next_kind_index;
        fast_fall = next_fast_fall;
    }
}

void TBoss6Rock::update_fall() {
    f32 accel = -0.75f;
    f32 max_speed = -9.0f;
    rotation_y += spin_speed;
    if (fast_fall == 1) {
        accel = -0.9375f;
        max_speed = -11.25f;
    }
    fall_speed += accel;
    if (fall_speed < max_speed) {
        fall_speed = max_speed;
    }
    position.y += fall_speed;
    if (position.y <= 0.0f) {
        position.y = 0.0f;
        fall_speed = 0.0f;
        push_out_players(1);
        create_map_csn();
        play_sound_effect(0x4006B51E, &position, 0, 0);
        spawn_particle_effect(&position, 0x220);
        spawn_particle_effect(&position, 0x222);
        TBoss6PlotFalz::apply_radial_effect_to_players(&position, 0xC0, 0xF, 100.0f);
        fall_state = 2;
    }
}

void TBoss6Rock::break_and_release() {
    push_out_players(0);
    if (fast_fall == 1) {
        command = 0;
    }
    if (command != 2) {
        spawn_crush_rocks(&rock_point, kind_index);
        play_sound_effect(0x4006AB1F, &position, 0, 0);
        release_object();
        randomize_motion();
        fall_state = 0;
    }
}

void TBoss6Rock::push_out_players(s32 landed) {
    s32 count;
    s32 i;
    TObjPlayer *player;
    f32 radius;
    f32 dist;
    Vec d;

    if (landed == 0) {
        this->push_timer++;
        if (this->push_timer & 1) {
            return;
        }
    }
    count = TLobby::get_game_mode();
    radius = boss6_rock_kind_params[this->kind_index].radius;
    if (landed != 0) {
        radius += 10.0f;
    }
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active((TObjPlayer *)player) == 0) {
            continue;
        }
        VecCopy(&d, &player->position);
        subtract_vector(&d, &this->rock_point);
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
        vec3_add_to(&d, &this->rock_point);
        TBoss6PlotFalz::move_player_to(player, &d);
        if (landed != 0) {
            DirectAttackPayload h;
            s32 damage = TBoss6PlotFalz::rand_vary_count(boss6_rock_damage, 0.1f);
            h.kind = 0;
            h.power = damage;
            player->receive_direct_attack(boss6_rock_owner, h, 0, -1, -1);
        }
    }
}

void TBoss6Rock::init_rock_points() {
    static RockRing rings[4] = {
        {5.0f * boss6_arena_radius / 7.0f, 8},
        {4.0f * boss6_arena_radius / 7.0f, 8},
        {3.0f * boss6_arena_radius / 7.0f, 8},
        {2.0f * boss6_arena_radius / 7.0f, 8},
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
    return &boss6_rock_kind_params[TBoss6Rock__instance_table[i]->kind_index];
}

void TBoss6Rock::randomize_motion() {
    rotation_x = 2048.0f * (3.0517578125e-05f * rand() - 0.5f);
    rotation_y = 65535.0f * (3.0517578125e-05f * rand());
    rotation_z = 2048.0f * (3.0517578125e-05f * rand() - 0.5f);
    spin_speed = 8192.0f * (3.0517578125e-05f * rand() - 0.5f);
    VecCopy(&position, &rock_point);
    position.y = 450.0f;
}

void TBoss6Rock::create_map_csn() {
    const RockKindParams *e;
    MapCsnSetData set;
    do { } while (0);
    if (map_csn == 0) {
        VecCopy(&set.position, &rock_point);
        copy_xyz(&set.rotation_x, (void *)boss6_rock_set_rotation);
        e = boss6_rock_kind_params;
        e += kind_index;
        set.params[0] = 2;
        set.params[1] = 0;
        set.scale.z = e->width;
        set.scale.x = e->width;
        set.scale.y = e->height;
        map_csn = TObjMapCsn::create(&set);
    }
}

void TBoss6Rock::release_object() {
    if (map_csn != 0) {
        map_csn->queue_destruction();
        map_csn = 0;
    }
}

void TBoss6Rock::set_rock_target(s32 i, s32 a, s32 b) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock != NULL) {
        rock->command = 2;
        rock->next_kind_index = a;
        rock->next_fast_fall = b;
    }
}

void TBoss6Rock::clear_rock_state(s32 i) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock != NULL) {
        rock->command = 0;
    }
}

void TBoss6Rock::reset_rock_state(s32 i) {
    TBoss6Rock *rock;
    if (i < 0 || i >= 32) {
        return;
    }
    rock = TBoss6Rock__instance_table[i];
    if (rock == NULL || rock->fall_state != 2) {
        return;
    }
    rock->command = 0;
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
    return rock->fall_state == 2;
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
    return rock->command == 2;
}

s32 TBoss6Rock::get_point(s32 i, Vec *out, f32 *radius) {
    if (is_rock_valid(i) == 0) {
        return 0;
    }
    VecCopy(out, &TBoss6Rock__rock_point_table[i]);
    *radius = get_rock_entry(i)->radius;
    return 1;
}

s32 TBoss6Rock::push_out_of_rocks(Vec *point, f32 r) {
    Vec v;
    s32 hit;
    s32 i;
    f32 y = 0.0f;
    f32 lim = 20.0f + r;
    hit = 0;
    for (i = 0; i < 32; i++) {
        f32 d;
        VecCopy(&v, point);
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
            vec3_add_to(point, &v);
            hit = 1;
        }
    }
    return hit;
}

void TBoss6Rock::break_rocks_in_radius(Vec *point, f32 r) {
    Vec v;
    s32 i;
    const RockKindParams *kind;
    for (i = 0; i < 32; i++) {
        kind = get_rock_entry(i);
        if (kind != NULL && is_rock_state_2(i) != 0 && !(point->y > r + kind->height)) {
            f32 lim = r + kind->radius;
            VecCopy(&v, &TBoss6Rock__rock_point_table[i]);
            subtract_vector(&v, point);
            v.y = 0.0f;
            if (vector_length(&v) <= lim) {
                clear_rock_state(i);
            }
        }
    }
}

s32 TBoss6Rock::get_push_target(s32 i, Vec *out, f32 *radius) {
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
    if (boss6_rock_owner == NULL) {
        return 0;
    }
    kind = TBoss6Rock::get_rock_entry(i);
    if (kind == NULL) {
        return 0;
    }
    r = kind->radius;
    VecCopy(&a, (Vec *)&boss6_rock_owner->position);
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

BmlResource *TBoss6Rock::get_resource() {
    return boss6_rock_resource;
}

NJS_TEXLIST *TBoss6Rock::get_texture_list() {
    return boss6_rock_texture_list;
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
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
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
