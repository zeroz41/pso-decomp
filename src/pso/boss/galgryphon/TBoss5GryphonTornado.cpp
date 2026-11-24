#include "pso/system/BmlAccessors.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/galgryphon/TBoss5GryphonTornado.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"


void TBoss5GryphonTornado::get_target_direction(Vec *dir) {
    TObjPlayer *player;
    dir->x = 0.0f;
    dir->y = 0.0f;
    dir->z = 0.0f;
    if (this->target_client_id != 0xFFFF) {
        player = get_player_by_client_id(this->target_client_id);
        if (player != NULL) {
            dir->x = player->position.x - this->position.x;
            dir->z = player->position.z - this->position.z;
            normalize_vector_safe(dir);
        }
    }
}


// The particle ids run_task spawns (installed by select_particle_table at the end of
// the file). Defined first: the table opens the unit's .rodata, before the class name.
static const s32 gryphon_tornado_particle_ids[3] = {0x203, 0x204, 0x205};
const char *TBoss5GryphonTornado__class_name = "TBoss5GryphonTornado";
extern "C" {

const s32 *gryphon_tornado_particle_id_table;

void TBoss5GryphonTornado::render() {  }

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TBoss5GryphonTornado::run_task() {
    Vec v;
    CsnHit *r;
    f32 h;
    if (this->gryphon->get_flag_bit6() != 0) {
        queue_destruction();
        return;
    }
    switch (this->state) {
    case 0:
        this->state = 1;
    case 1:
        this->position.y = gryphon_max_floor_height;
        r = csnVecterUnder(&this->position, 0x16EF);
        if (r == NULL) {
            queue_destruction();
            return;
        }
        h = r->contact->point.y;
        if (h > gryphon_max_floor_height) {
            this->position.y = gryphon_max_floor_height;
        } else {
            this->position.y = h;
        }
        if (this->particles[0] == NULL) {
            this->particles[0] = spawn_continuous_particle_effect_with_flags(&this->position, gryphon_tornado_particle_id_table[0], 0x40);
        }
        if (this->particles[1] == NULL) {
            this->particles[1] = spawn_continuous_particle_effect_with_flags(&this->position, gryphon_tornado_particle_id_table[1], 0x40);
            if (this->particles[1] != NULL) {
                attach_particle_model(this->particles[1], get_bml_model(boss5_gryphon_bml_resource, 0), boss5_gryphon_texture_list, get_bml_motion(boss5_gryphon_bml_resource, 0), 0, 1.0f);
            }
        }
        if (this->particles[2] == NULL) {
            this->particles[2] = spawn_continuous_particle_effect_with_flags(&this->position, gryphon_tornado_particle_id_table[2], 0x40);
        }
        if (this->particles[0] != NULL) {
            this->particles[0]->set_position(&this->position);
        }
        if (this->particles[1] != NULL) {
            this->particles[1]->set_position(&this->position);
        }
        if (this->particles[2] != NULL) {
            this->particles[2]->set_position(&this->position);
        }
        if (this->timer > 0x168) {
            this->state = 2;
            this->timer = 0;
        }
        TBoss5Gryphon::apply_tornado_hit(TBoss5Gryphon::get_instance(), &this->position);
        get_target_direction(&v);
        this->velocity.x = 0.01f * v.x + this->velocity.x;
        this->velocity.z = 0.01f * v.z + this->velocity.z;
        this->velocity.x *= 0.995f;
        this->velocity.z *= 0.995f;
        this->position.x += this->velocity.x;
        this->position.z += this->velocity.z;
        add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 1.5f);
        play_persistent_sound(0x40032D05, this, &this->position, 0, 0);
        this->timer++;
        break;
    case 2:
        if (this->particles[0] != NULL) {
            this->particles[0]->enable();
        }
        if (this->particles[1] != NULL) {
            this->particles[1]->enable();
        }
        if (this->particles[2] != NULL) {
            this->particles[2]->enable();
        }
        if (this->timer > 0x3C) {
            queue_destruction();
        } else {
            this->timer++;
        }
        break;
    }
}
#pragma pop

}
TBoss5GryphonTornado::~TBoss5GryphonTornado() {
    if (this->particles[2] != NULL) { this->particles[2]->queue_destruction(); this->particles[2] = NULL; }
    if (this->particles[1] != NULL) { this->particles[1]->queue_destruction(); this->particles[1] = NULL; }
    if (this->particles[0] != NULL) { this->particles[0]->queue_destruction(); this->particles[0] = NULL; }
}

TBoss5GryphonTornado::TBoss5GryphonTornado(TObject *parent, TBoss5Gryphon *gryphon, const Vec *pos, u16 target_client_id) : TObject(parent) {
    m_name = TBoss5GryphonTornado__class_name;
    VecCopy(&this->position, pos);
    this->target_client_id = target_client_id;
    this->gryphon = gryphon;
    this->velocity.x = 0.0f;
    this->velocity.y = 0.0f;
    this->velocity.z = 0.0f;
    this->particles[0] = NULL;
    this->particles[1] = NULL;
    this->particles[2] = NULL;
    this->timer = 0;
    this->state = 0;
}

TBoss5GryphonTornado *TBoss5GryphonTornado::spawn(TObject *parent, TBoss5Gryphon *gryphon, const Vec *pos_src,
                                                  u16 target_client_id) {
    Vec pos;
    CsnHit *under;
    f32 y;
    TBoss5GryphonTornado *tornado;
    VecCopy(&pos, pos_src);
    pos.y = gryphon_max_floor_height;
    under = csnVecterUnder(&pos, 0x16EF);
    if (under == NULL) {
        return NULL;
    }
    y = under->contact->point.y;
    if (y > gryphon_max_floor_height) {
        return NULL;
    }
    pos.y = y;
    tornado = new TBoss5GryphonTornado(parent, gryphon, &pos, target_client_id);
    return tornado;
}

void TBoss5GryphonTornado::release_particle_table() {  }
void TBoss5GryphonTornado::select_particle_table() {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        gryphon_tornado_particle_id_table = gryphon_tornado_particle_ids;
        break;
    }
}
