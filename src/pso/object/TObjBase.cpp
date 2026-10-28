#include "types.h"
#include "pso/map/FloorArea.h"
#include "pso/object/TObjMotion.h"
#include "pso/TMainTask.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/system/vector.h"
#include <stddef.h>

// What apply_object_set_data reads: an object set entry from 4 bytes in, so
// entity_id, room, position, rotation and params 1-6 sit as in the .dat entry.
struct ObjectSetData {
    u8 pad_0[0x4];
    u16 entity_id;
    u8 pad_6[0x2];
    s16 room;
    u8 pad_a[0x2];
    Vec position;
    s32 rotation[3];
    Vec scale;
    s32 set_params[3];
};

// A camera-space probe point and where it lands on screen.
struct ViewProbe {
    f32 screen[2];
    Vec point;
};

extern "C" {
s32 is_in_shadow_range(f32, const Vec *);
s32 project_world_to_screen(int, const Vec *, f32 *);
f32 transform_point_by_current_matrix(const Vec *, Vec *);
extern const f32 lbl_805DC098;
extern const f32 lbl_805DC09C;
extern const f32 lbl_805DC0A0;
}

extern u16 lbl_805D5CD0;
extern u16 lbl_805D5CD2;
extern u16 lbl_805D5CD4;
extern u16 lbl_805D5CD6;
extern u16 lbl_805D5CD8;

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
    ((TObjPlayer *)&rotation_x)->copy_xyz(src->rotation);
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
            this->entity_id = fn_801A210C(count);
            break;
        case 0x20000000:
            this->entity_id = TLobby__sub_801A20C8(count);
            break;
        default:
        case 0x40000000:
            this->entity_id = TLobby::alloc_actor_ids(count);
            break;
        }
    }
    return this->entity_id;
}
u16 TLobby::alloc_actor_ids(s32 arg) {
    u16 n = arg;
    s32 id = lbl_805D5CD4;
    if (id + n + 1 >= 0xFFFF) {
        lbl_805D5CD4 = lbl_805D5CD6;
        id = lbl_805D5CD4;
        lbl_805D5CD4 = id + (n + 1);
    } else {
        lbl_805D5CD4 = id + (n + 1);
    }
    return id;
}

u16 TLobby__sub_801A20C8(s32 arg) {
    u16 n = arg;
    s32 id = lbl_805D5CD2;
    if (id + n + 1 >= 0x4000) {
        lbl_805D5CD2 = lbl_805D5CD8;
        id = lbl_805D5CD2;
        lbl_805D5CD2 = id + (n + 1);
    } else {
        lbl_805D5CD2 = id + (n + 1);
    }
    return id;
}

u16 fn_801A210C(s32 n) {
    u16 r = lbl_805D5CD0;
    lbl_805D5CD0 += n + 1;
    return r;
}

void *TObjBase::get_center() { return &center; }

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
s16 TObjBase::classify_actor_view_detail(f32 near_depth, f32 far_depth, f32 radius) {
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
    if (z > lbl_805DC098) {
        visibility = 0;
        return 0;
    }
    if (z < -far_depth) {
        visibility = 0;
        return 0;
    }
    if (probe.point.x < lbl_805DC098) {
        probe.point.x = (camera_right[0] * radius) + position.x;
        probe.point.y = (camera_right[1] * radius) + position.y;
        probe.point.z = (camera_right[2] * radius) + position.z;
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] < lbl_805DC098) {
            visibility = 0;
            return 0;
        }
    } else {
        probe.point.x = -((camera_right[0] * radius) - position.x);
        probe.point.y = -((camera_right[1] * radius) - position.y);
        probe.point.z = -((camera_right[2] * radius) - position.z);
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] > lbl_805DC09C) {
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
    if (probe.point.z > lbl_805DC098) {
        visibility = 0;
        return 0;
    }
    if (probe.point.z < -far_depth) {
        visibility = 0;
        return 0;
    }
    if (probe.point.x < lbl_805DC098) {
        probe.point.x = (camera_right[0] * radius) + position.x;
        probe.point.y = (camera_right[1] * radius) + position.y;
        probe.point.z = (camera_right[2] * radius) + position.z;
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] < lbl_805DC098) {
            visibility = 0;
            return 0;
        }
    } else {
        probe.point.x = -((camera_right[0] * radius) - position.x);
        probe.point.y = -((camera_right[1] * radius) - position.y);
        probe.point.z = -((camera_right[2] * radius) - position.z);
        project_world_to_screen(0, &probe.point, probe.screen);
        if (probe.screen[0] > lbl_805DC09C) {
            visibility = 0;
            return 0;
        }
    }
    visibility = 1;
    return 1;
}
#pragma pop

void advance_enemy_id_counter(s32 arg0) {
    u16 temp_r0;
    temp_r0 = lbl_805D5CD2 + arg0;
    lbl_805D5CD2 = temp_r0;
    lbl_805D5CD8 = temp_r0;
}

void advance_object_id_counter(s32 arg0) {
    u16 temp_r0;
    temp_r0 = lbl_805D5CD4 + arg0;
    lbl_805D5CD4 = temp_r0;
    lbl_805D5CD6 = temp_r0;
}

void TLobby::init_limits() {
    lbl_805D5CD2 = 0x1000;
    lbl_805D5CD4 = 0x4000;
}

void TLobby__sub_801A2550(void) {  }


void TLobby__sub_801A2554(void) {
    lbl_805D5CD0 = 0;
    lbl_805D5CD2 = 0x1000;
    lbl_805D5CD4 = 0x4000;
}

void TObjBase::reset_motion_fields() {
    m_20 = 0;
    prev_position.z = lbl_805DC098;
    prev_position.y = lbl_805DC098;
    prev_position.x = lbl_805DC098;
    home_position.z = lbl_805DC098;
    home_position.y = lbl_805DC098;
    home_position.x = lbl_805DC098;
    rotation_z = 0;
    rotation_y = 0;
    rotation_x = 0;
    center.z = lbl_805DC098;
    center.y = lbl_805DC098;
    center.x = lbl_805DC098;
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
    position.x = lbl_805DC098;
    position.y = lbl_805DC098;
    position.z = lbl_805DC098;
    VecCopy(&prev_position, &position);
    VecCopy(&home_position, &position);
    rotation_x = 0;
    rotation_y = 0;
    rotation_z = 0;
    scale.x = lbl_805DC0A0;
    scale.y = lbl_805DC0A0;
    scale.z = lbl_805DC0A0;
    center.x = lbl_805DC098;
    center.y = lbl_805DC098;
    center.z = lbl_805DC098;
    visibility = 0;
}
