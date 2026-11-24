#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/ObjectFactoryTables.h"
#include "pso/map/FloorPopulation.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/map/TSetManager.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixStack.h"


struct RecoveredGlobal_8020D2B4_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
LAYOUT_ASSERT(RecoveredGlobal_8020D2B4_lbl_8058D490_size, sizeof(RecoveredGlobal_8020D2B4_lbl_8058D490) == 0x30);

typedef struct SpawnAngles_8020D36C { u32 x, y, z; } SpawnAngles_8020D36C;

typedef struct SpawnRecord_8020D36C {
    s16 type;
    u16 flags;
    u16 index;
    s16 children;
    u16 reserved;
    u16 actor_id;
    s16 room;
    s16 wave;
    u32 secondary_wave;
    Vec position;
    SpawnAngles_8020D36C angles;
    f32 parameters[5];
    s16 integers[4];
} SpawnRecord_8020D36C;

struct Out_8020D474 { u8 data[0x18]; };

typedef ObjectFactoryEntry Ent_8020D5AC;

extern "C" {
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
void *find_scene_room_by_id(s32 room);
void apply_room_transform_to_enemy_rows(SpawnRecord_8020D36C *rows, s32 count);
void apply_room_transform_to_object_rows(FloorObjectSetRow *arr, s32 n);
s32 find_set_factory_index(void *, void *);
s32 TLobby__sub_801C2614();
}
extern RecoveredGlobal_8020D2B4_lbl_8058D490 identity_matrix;
void apply_room_transform(saddr arg0, u8 *arg1, u8 *arg2);
void resolve_set_row_factory_indices(void *arg0, FloorObjectSetRow *rows, int count);
s32 is_within_camera_distance(void *arg0, void *arg1, f32 farg0);
void spawn_decorations_in_range(TSetManager *manager);
void apply_room_transform(saddr arg0, u8 *arg1, u8 *arg2) {
    push_matrix_from(&identity_matrix.value);
    translate_matrix(0, (f32) (*(f32 *)((s8 *)arg2 + 4)), (f32) (*(f32 *)((s8 *)arg2 + 8)), (f32) (*(f32 *)((s8 *)arg2 + 0xC)));
    rotate_matrix_z(0, (int) (*(s32 *)((s8 *)arg2 + 0x18)));
    rotate_matrix_x(0, (int) (*(s32 *)((s8 *)arg2 + 0x10)));
    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg2 + 0x14)));
    matrix_mult_vec(0, (void *)arg0, (void *)arg0);
    pop_matrix();
    *(s32 *)((s8 *)arg1 + 0) = (s32) (*(s32 *)((s8 *)arg1 + 0) + *(s32 *)((s8 *)arg2 + 0x10));
    *(s32 *)((s8 *)arg1 + 4) = (s32) (*(s32 *)((s8 *)arg1 + 4) + *(s32 *)((s8 *)arg2 + 0x14));
    *(s32 *)((s8 *)arg1 + 8) = (s32) (*(s32 *)((s8 *)arg1 + 8) + *(s32 *)((s8 *)arg2 + 0x18));
}

void apply_room_transform_to_enemy_rows(SpawnRecord_8020D36C *rows, s32 count) {
    SpawnRecord_8020D36C *row;
    void *cached_room;
    s16 cached_id = -1;
    s32 i;
    for (i = 0; i < count; i++) {
        row = &rows[i];
        if (cached_id != row->room) {
            cached_room = find_scene_room_by_id(row->room);
            cached_id = row->room;
        }
        if (cached_room) {
            apply_room_transform((saddr)&row->position, (u8 *)&row->angles, (u8 *)cached_room);
        }
    }
}

void apply_room_transform_to_object_rows(FloorObjectSetRow *arr, s32 n) {
    FloorObjectSetRow *p;
    void *sec;
    s16 key;
    s32 i;
    key = -1;
    i = 0;
    for (; i < n; i++) {
        p = &arr[i];
        if (key != p->placement.room) {
            sec = find_scene_room_by_id(p->placement.room);
            key = p->placement.room;
        }
        if (sec != NULL) {
            apply_room_transform((saddr)&p->placement.position, (u8 *)p->placement.rotation, (u8 *)sec);
        }
    }
}

void resolve_set_row_factory_indices(void *arg0, FloorObjectSetRow *rows, int count) {
    Out_8020D474 o;
    FloorObjectSetRow *p;
    s32 i;
    s32 r;
    p = rows;
    for (i = 0; i < count; i++, p++) {
        if (p->type != -1) {
            r = find_set_factory_index(p, &o);
            if (r >= 0) {
                p->type = r;
            } else {
                p->type = -1;
            }
        }
    }
}

s32 is_within_camera_distance(void *arg0, void *arg1, f32 farg0) {
    s32 n;
    s32 i;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (camera_ctrl_instance != NULL) {
            n = TCameraCtrl::get_view_count();
            for (i = 0; i < n; i++) {
                if (xyz_distance_squared(static_cast<const Vec *>(arg1), &camera_ctrl_instance->split_pos[i]) < farg0) {
                    return 1;
                }
            }
        }
    } else if (camera_ctrl_instance != NULL && xyz_distance_squared(static_cast<const Vec *>(arg1), &camera_ctrl_instance->pos) < farg0) {
        return 1;
    }
    return 0;
}

void spawn_decorations_in_range(TSetManager *manager) {
    Ent_8020D5AC *tbl;
    FloorObjectSetRow *p;
    s32 i;
    TObjBase *obj;
    tbl = floor_object_factory_tables[get_current_floor_area()];
    if (tbl == NULL) {
        return;
    }
    if (TObjPlayer::get_player_count() != 0 && is_quest_active() != 0 && TLobby__sub_801C2614() == 0) {
        return;
    }
    p = floor_decoration_rows;
    for (i = 0; i < floor_decoration_row_count; i++, p++) {
        if (p->type != -1 && !(p->flags & 2) && !(p->flags & 8)
            && is_within_camera_distance(manager, &p->placement.position, tbl[p->type].creation_distance_squared) == 1) {
            p->placement.entity_id = 0xFFFF;
            p->placement.object_type = -1;
            obj = call_area_set_factory(manager, p);
            if (obj != NULL) {
                p->object = obj;
                obj->room = p->placement.room;
                obj->set_entry = p;
                p->flags |= 2;
            } else {
                p->object = NULL;
                p->flags |= 8;
            }
        }
    }
}

void TSetManager::update_decoration_spawning() { spawn_decorations_in_range(this); }
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TSetManager::apply_floor_set_rows() {
    u8 *arg0 = (u8 *)this;
    s32 current_floor;
    LobbyFloorRows *floor;
    current_floor = get_current_floor();
    active_set_floor = current_floor;
    floor = &floor_enemy_group_table[current_floor];
    if (!(floor->object_placement & 2)) {
        apply_room_transform_to_object_rows(current_floor_object_set_rows, floor->object_count);
        floor->object_placement |= 2U;
    }
    if (!(floor->enemy_placement & 4)) {
        apply_room_transform_to_enemy_rows((SpawnRecord_8020D36C *)(current_floor_enemy_set_rows), floor->enemy_count);
        floor->enemy_placement |= 4U;
    }
    if (floor->object_placement & 2) {
        TLobby::assign_objects_to_slots((u8 *)current_floor_object_set_rows, floor->object_count);
    }
    if (floor->enemy_placement & 4) {
        TLobby::assign_display_objects(current_floor_enemy_set_rows, floor->enemy_count);
    }
    if ((s32) floor_decoration_row_count > 0) {
        apply_room_transform_to_object_rows(floor_decoration_rows, floor_decoration_row_count);
        resolve_set_row_factory_indices(arg0, floor_decoration_rows, floor_decoration_row_count);
    }
    this->step = 1;
}
#pragma pop
