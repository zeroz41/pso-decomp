#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/TObjParticle.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/render/NinjaUtil.h"
#include "pso/map/FloorArea.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {
extern const char TObjParticle__class_name_string[] = "TObjParticle";
const char *obj_particle_class_name = TObjParticle__class_name_string;
}

void TObjParticle::render() {
    if (all_parents_unqueued_for_destruction() != 0) {
        if (emitter == NULL) {
            return;
        }
    }
}

void TObjParticle::run_task() {
    f32 distance_limit;
    if (((get_current_floor_area() == AREA_DARK_FALZ) || (set_params[0] == 1)) && (set_params[2] != 1)) {
        distance_limit = 2250000.0f;
    } else {
        distance_limit = 160000.0f;
    }
    if ((set_params[2] == 1) && (set_params[0] == 1)) {
        distance_limit = 100000000.0f;
    }
    if (xyz_distance_squared(&position, (const Vec *)&camera_ctrl_instance->pos.x) > distance_limit) {
        queue_destruction();
        return;
    }
    if (emitter != NULL) {
        emitter->set_position(&position);
        emitter->set_direction(&rotation_x);
    }
}

TObjParticle::~TObjParticle() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
    mask_object_set_row_flags(-3);
}

TObjParticle::TObjParticle(TObject *parent, ParticleSetData *set_data) : TObjBase(parent) {
    u32 i;
    s32 entry;
    u16 flags;
    u16 base;
    s32 continuous_flags = 0;
    m_name = obj_particle_class_name;
    VecCopy(&position, &set_data->position);
    copy_xyz(&rotation_x, &set_data->rotation);
    VecCopy(&scale, &set_data->params);
    for (i = 0; i < 3; i++) {
        set_params[i] = set_data->set_params[i];
    }
    particle_id = (s32)set_data->params.x;
    emitter = NULL;
    entry = (s32)scale.x;
    if (entry < 0) {
        entry = 0;
    }
    if (scale.z < 0.0f) {
        base = 2;
        if (set_params[0] == 1) {
            base = 0x42;
        }
        flags = base;
        if (set_params[1] == 1) {
            flags = base | 0x2000;
        }
        emitter = (TParticleCtrl *)spawn_particle_effect_with_rotation(&position, &rotation_x, entry, flags);
    } else if ((s32)scale.z == 2) {
        flags = 8;
        if (set_params[0] == 1) {
            flags = 0x48;
        }
        if (set_params[1] == 1) {
            flags |= 0x2000;
        }
        emitter = (TParticleCtrl *)spawn_particle_effect_with_rotation(&position, &rotation_x, entry, flags);
    } else if ((s32)scale.z == 3) {
        flags = 4;
        if (set_params[0] == 1) {
            flags = 0x44;
        }
        if (set_params[1] == 1) {
            flags |= 0x2000;
        }
        emitter = (TParticleCtrl *)spawn_particle_effect_with_rotation(&position, &rotation_x, entry, flags);
    } else {
        if (set_params[0] == 1) {
            continuous_flags = 0x40;
        }
        if (set_params[1] == 1) {
            continuous_flags = (continuous_flags | 0x2000) & 0xFFFF;
        }
        if (set_params[0] == 1 || set_params[1] == 1) {
            emitter = (TParticleCtrl *)spawn_particle_effect_with_rotation(&position, &rotation_x, entry, continuous_flags);
        } else {
            emitter = (TParticleCtrl *)spawn_continuous_particle_with_direction(&position, &rotation_x, entry);
        }
    }
    disallow_rendering();
}
#undef arg0

void *TObjParticle::create(void *set_data) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TObjParticle(tl_05, (ParticleSetData *)set_data);
}
