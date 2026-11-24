#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/enemy/recon/TObjEneReconBomb.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/system/task/TObject.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/base/TObjBase.h"


#pragma readonly_strings on

extern "C" {
BmlResource *recon_bomb_bml_resource;

// 1 once the nearest visible player within 25 stands (xz) within 1 + its first body's radius of the bomb.
s32 TObjEneReconBomb::has_player_nearby() {
    s32 near = 0;
    TObjPlayer *player;
    VecCopy(&body_center, &position);
    u16 id = find_nearest_visible_player(this, NULL, 25.0f);
    if (id != 0xFFFF) {
        player = get_player_by_client_id(id);
        if (player != 0) {
            if (!(horizontal_distance_squared(&body_center, &player->body_center) > (1.0f + player->bodies->radius) * (1.0f + player->bodies->radius))) {
                near = 1;
            }
        }
    }
    return near;
}

#pragma push
#pragma fp_contract on
void TObjEneReconBomb::render() {
    struct { f32 x, y, z; } sc;
    s32 rot_a;
    s32 rot_b;
    f32 height;
    saddr bml_model;
    s32 texlist;
    if (recon_bomb_bml_resource == NULL) {
        queue_destruction();
        return;
    }
    bml_model = (saddr)get_bml_model(recon_bomb_bml_resource, 2);
    texlist = (saddr)get_bml_texlist(recon_bomb_bml_resource, 2);
    push_matrix();
    translate_matrix(0, position.x, 2.0f + position.y, position.z);
    rotate_matrix_zyx(0, rotation_x, rotation_y, rotation_z);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    draw_chunk_object((void *)bml_model);
    pop_matrix();
    push_matrix();
    translate_matrix(0, position.x, 0.1f + ground_y, position.z);
    direction_to_rotation_xz((u8 *)&ground_normal, &rot_a, &rot_b);
    rotate_matrix_z(0, rot_b);
    rotate_matrix_x(0, rot_a + 0x4000);
    height = position.y - ground_y;
    if (height > 40.0f) {
        height = 40.0f;
    } else if (height < 0.0f) {
        height = 0.0f;
    }
    sc.x = sc.y = 0.65f * (1.0f - (height / 40.0f)) + 0.1f;
    sc.z = 1.0f;
    scale_current_matrix(&sc.x);
    draw_blob_shadow(0);
    pop_matrix();
}
#pragma pop

void TObjEneReconBomb::run_task() {
    Vec pos;
    s32 i;
    TObjPlayer *pl;
    if (owner == 0) {
        queue_destruction();
        return;
    }
    if (++age > lifetime || owner->is_dead() != 0) {
        state = 3;
    }
    switch (state) {
    case 0:
    case 1: {
        velocity.x *= 0.95f;
        velocity.y += -0.1f;
        velocity.z *= 0.95f;
        VecCopy(&pos, &position);
        vec3_add_to(&pos, &velocity);
        Vec g = pos;
        if (project_actor_to_ground(this, &g, &ground_normal) != 0) {
            ground_y = g.y;
            if (pos.y <= g.y) {
                pos.y = ground_y;
                if (state == 0) {
                    velocity.y *= -0.5f;
                    state = 1;
                } else {
                    state = 2;
                }
            } else if (csnVector(&position, &pos, 0x100) != 0) {
                VecCopy(&pos, &position);
                state = 3;
            }
        } else {
            state = 3;
        }
        VecCopy(&position, &pos);
        break;
    }
    case 2:
        if (has_player_nearby() != 0) {
            state = 3;
        }
        break;
    case 3:
    default:
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80B), &position, 0, 0);
        spawn_particle_effect_with_flags(&position, 0x45, 0x40);
        spawn_particle_effect_with_flags(&position, 0x46, 0x40);
        for (i = 0; i < lbl_805D5868; i++) {
            pl = TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_valid_and_active((uaddr)pl) != 0 && pl != 0 && pl->get_entity_id() < 0x1000 && pl->has_flag_0x800() == 0) {
                if (horizontal_distance_squared(&pl->body_center, &body_center) <= blast_radius * blast_radius) {
                    DirectAttackPayload attack;
                    attack.kind = 0;
                    attack.power = blast_power;
                    pl->apply_knockback_from_attacker((u8 *)owner, pl->receive_direct_attack(owner, attack, NULL, -1, -1));
                }
            }
        }
        queue_destruction();
        break;
    }
}

}
TObjEneReconBomb::~TObjEneReconBomb() {

}


extern const char *TObjEneReconBomb__name;

TObjEneReconBomb::TObjEneReconBomb(TObject *parent, TObjEneRecon *recon, const Vec *pos) : TObjChara(parent) {
    f32 s;
    f32 c;

    m_name = TObjEneReconBomb__name;
    owner = recon;
    owner_id = owner->get_entity_id();
    blast_radius = owner->get_bomb_radius();
    blast_power = owner->get_bomb_power();
    launch_speed = owner->get_bomb_speed();
    lifetime = owner->calc_scaled_value();
    rotation_y = ((TObjBase *)m_up)->rotation_y;
    VecCopy(&position, pos);
    s = sin_table_lookup(rotation_y);
    c = cos_table_lookup(rotation_y);
    velocity.x = launch_speed * s;
    velocity.y = 0.0f;
    velocity.z = launch_speed * c;
    age = 0;
    state = 0;
}

const char *TObjEneReconBomb__name = "TObjEneReconBomb";


void TObjEneReconBomb::release_resources() {  }

void *TObjEneReconBomb::create(void *parent, void *recon, void *pos) {
    return new TObjEneReconBomb((TObject *)parent, (TObjEneRecon *)recon, (const Vec *)pos);
}

void TObjEneReconBomb::load_resources() { recon_bomb_bml_resource = TObjEneRecobox::get_bml_resource(); }
