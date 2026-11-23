#include "types.h"
#include "pso/object/base/TObjBase.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TMainTask.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/unk/TLobby.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/vector.h"
#include <stddef.h>
#include "pso/player/TObjPlayer_80011014.h"

// A camera-space probe point and where it lands on screen.
struct ViewProbe {
    f32 screen[2];
    Vec point;
};

extern "C" {
s32 is_in_shadow_range(f32, const Vec *);
s32 project_world_to_screen(int, const Vec *, f32 *);
f32 transform_point_by_current_matrix(const Vec *, Vec *);
}

u16 next_player_id;
u16 next_enemy_id;
u16 next_object_id;
u16 first_free_object_id;
u16 first_free_enemy_id;

const char *TObjBase::get_name() { return NULL; }
void TObjBase::set_room(s16 room) {
    u32 area;

    if (entity_id < 0x1000U) {
        area = get_current_floor_area();
        if ((area <= 2U) || ((s32) area == AREA_PIONEER2_EP2) || (TContainerAncient01::is_global_state_in_table() != 0) || ((s32) area == AREA_DE_ROL_LE) || ((s32) area == AREA_BARBA_RAY)) {
            alt_room = room;
        }
        this->room = room;
        return;
    }
    this->room = room;
}

s16 TObjBase::get_room() {
    s32 area;

    if ((get_current_floor_area() == AREA_PIONEER2_EP1) || (get_current_floor_area() == AREA_PIONEER2_EP2)) {
        return 0;
    }
    if ((u16) this->entity_id < 0x1000U) {
        area = get_current_floor_area();
        if (((area - 1) <= 1U) || (TContainerAncient01::is_global_state_in_table() != 0) || (area == AREA_DE_ROL_LE) || (area == AREA_BARBA_RAY)) {
            return alt_room;
        }
        return room;
    }
    return room;
}

void TObjBase::apply_object_set_data(void *data) {
    ObjectSetData *src = (ObjectSetData *)data;
    s32 i;
    entity_id = src->entity_id;
    VecCopy(&home_position, VecCopy(&position, &src->position));
    copy_xyz(&rotation_x, src->rotation);
    VecCopy(&scale, &src->scale);
    room = src->room;
    for (i = 0; i < 3; i++) {
        set_params[i] = src->set_params[i];
    }
}

void TObjBase::vfunc_6(s16 *, s32) {  }
u16 TObjBase::get_or_assign_entity_id(s32 count) {

    if (this->entity_id == 0xFFFF) {
        switch (this->actorFlags & 0x70000000) {
        case 0x10000000:
            this->entity_id = alloc_player_ids(count);
            break;
        case 0x20000000:
            this->entity_id = alloc_enemy_ids(count);
            break;
        default:
        case 0x40000000:
            this->entity_id = alloc_object_ids(count);
            break;
        }
    }
    return this->entity_id;
}
u16 alloc_object_ids(s32 count) {
    u16 n = count;
    s32 id = next_object_id;
    if (id + n + 1 >= 0xFFFF) {
        next_object_id = first_free_object_id;
        id = next_object_id;
        next_object_id = id + (n + 1);
    } else {
        next_object_id = id + (n + 1);
    }
    return id;
}

u16 alloc_enemy_ids(s32 count) {
    u16 n = count;
    s32 id = next_enemy_id;
    if (id + n + 1 >= 0x4000) {
        next_enemy_id = first_free_enemy_id;
        id = next_enemy_id;
        next_enemy_id = id + (n + 1);
    } else {
        next_enemy_id = id + (n + 1);
    }
    return id;
}

u16 alloc_player_ids(s32 count) {
    u16 id = next_player_id;
    next_player_id += count + 1;
    return id;
}

void *TObjBase::get_center() { return &center; }

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
s32 TObjBase::classify_actor_view_detail(f32 near_depth, f32 far_depth, f32 radius) {
    ViewProbe probe;
    f32 z;
    if (this->m_flags & 0x400) {
        if (is_in_shadow_range(radius, &position) != 0) {
            visibility = 1;
            return 1;
        }
        visibility = 0;
        return 0;
    }
    if (TMainTask::get_render_pass() == 1) {
        return visibility;
    }
    transform_point_by_current_matrix(&position, &probe.point);
    z = probe.point.z;
    if (z > 0.0f) {
        visibility = 0;
        return 0;
    }
    if (z < -far_depth) {
        visibility = 0;
        return 0;
    }
    if (probe.point.x < 0.0f) {
        probe.point.x = (camera_right.x * radius) + position.x;
        probe.point.y = (camera_right.y * radius) + position.y;
        probe.point.z = (camera_right.z * radius) + position.z;
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] < 0.0f) {
            visibility = 0;
            return 0;
        }
    } else {
        probe.point.x = -((camera_right.x * radius) - position.x);
        probe.point.y = -((camera_right.y * radius) - position.y);
        probe.point.z = -((camera_right.z * radius) - position.z);
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] > 640.0f) {
            visibility = 0;
            return 0;
        }
    }
    if (z < -near_depth) {
        visibility = 2;
        return 2;
    }
    visibility = 1;
    return 1;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on

s32 TObjBase::update_object_view_visibility(f32 far_depth, f32 radius) {
    ViewProbe probe;
    if (this->m_flags & 0x400) {
        if (is_in_shadow_range(radius, &position) != 0) {
            visibility = 1;
            return 1;
        }
        visibility = 0;
        return 0;
    }
    if (TMainTask::get_render_pass() == 1) {
        return visibility;
    }
    transform_point_by_current_matrix(&position, &probe.point);
    if (probe.point.z > 0.0f) {
        visibility = 0;
        return 0;
    }
    if (probe.point.z < -far_depth) {
        visibility = 0;
        return 0;
    }
    if (probe.point.x < 0.0f) {
        probe.point.x = (camera_right.x * radius) + position.x;
        probe.point.y = (camera_right.y * radius) + position.y;
        probe.point.z = (camera_right.z * radius) + position.z;
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] < 0.0f) {
            visibility = 0;
            return 0;
        }
    } else {
        probe.point.x = -((camera_right.x * radius) - position.x);
        probe.point.y = -((camera_right.y * radius) - position.y);
        probe.point.z = -((camera_right.z * radius) - position.z);
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] > 640.0f) {
            visibility = 0;
            return 0;
        }
    }
    visibility = 1;
    return 1;
}
#pragma pop

void advance_enemy_id_counter(s32 count) {
    u16 id;
    id = next_enemy_id + count;
    next_enemy_id = id;
    first_free_enemy_id = id;
}

void advance_object_id_counter(s32 count) {
    u16 id;
    id = next_object_id + count;
    next_object_id = id;
    first_free_object_id = id;
}

void reset_enemy_and_object_ids() {
    next_enemy_id = 0x1000;
    next_object_id = 0x4000;
}

void free_id_counters() {}


void reset_id_counters() {
    next_player_id = 0;
    next_enemy_id = 0x1000;
    next_object_id = 0x4000;
}

void TObjBase::reset_motion_fields() {
    m_20 = 0;
    prev_position.z = 0.0f;
    prev_position.y = 0.0f;
    prev_position.x = 0.0f;
    home_position.z = 0.0f;
    home_position.y = 0.0f;
    home_position.x = 0.0f;
    rotation_z = 0;
    rotation_y = 0;
    rotation_x = 0;
    center.z = 0.0f;
    center.y = 0.0f;
    center.x = 0.0f;
    set_entry = NULL;
}

TObjBase::~TObjBase() {
    if (set_entry != NULL) {
        u16 id = entity_id;
        if (id >= 0x4000 && id < 0xFFFF) {
            mask_object_set_row_flags(-3);
            set_entry = NULL;
        }
    }
}

TObjBase::TObjBase(TObject *parent) : TObject(parent) {
    actorFlags = 0;
    entity_id = 0xFFFF;
    room = -1;
    set_group = 0;
    set_index = -1;
    m_20 = 1;
    texlist = 0;
    model = NULL;
    set_entry = NULL;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    VecCopy(&prev_position, &position);
    VecCopy(&home_position, &position);
    rotation_x = 0;
    rotation_y = 0;
    rotation_z = 0;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    center.x = 0.0f;
    center.y = 0.0f;
    center.z = 0.0f;
    visibility = 0;
}
