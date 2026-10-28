#include "pso/object/ObjectFactoryTables.h"
#include "pso/misc/TCameraCtrl.h"

#include "types.h"
#include "pso/TSetManager.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_8020D2B4_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_8020D2B4_lbl_8058D490_size[sizeof(RecoveredGlobal_8020D2B4_lbl_8058D490) == 0x30 ? 1 : -1];

struct RecoveredGlobal_8020D6F0_TLobby__data_80513AD0 {
    s32 value;
    u8 remaining[0x1AC];
};

typedef struct SpawnVector_8020D36C { f32 x, y, z; } SpawnVector_8020D36C;

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
    SpawnVector_8020D36C position;
    SpawnAngles_8020D36C angles;
    f32 parameters[5];
    s16 integers[4];
} SpawnRecord_8020D36C;

struct Rec_8020D3F0 { u8 p0[0xC]; s16 key; u8 p1[2]; u8 a[0xC]; u8 b[0x28]; };

struct Out_8020D474 { u8 data[0x18]; };

struct Rec_8020D474 { s16 id; u8 pad[0x42]; };

struct Ent_8020D4E8 { u8 d[0xC]; };

struct Obj_8020D4E8 { u8 p0[0xD4]; Ent_8020D4E8 ents[13]; u8 p1[0x8]; Ent_8020D4E8 single; };

typedef ObjectFactoryEntry Ent_8020D5AC;

struct Rec_8020D5AC {
    s16 id;
    s16 flags;
    s16 s4;
    s16 s6;
    u16 s8;
    s16 sA;
    s16 sC;
    s16 sE;
    u8 data[0x30];
    void *obj;
};

extern "C" {
s32 push_matrix_from(void *src);
s32 pop_matrix(void);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
s32 get_current_floor();
extern RecoveredGlobal_8020D6F0_TLobby__data_80513AD0 TLobby__floor_enemy_group_table;
extern s32 TLobby__data_805D60FC;
extern s32 TLobby__data_805D610C;
extern s32 TLobby__data_805D6114;
extern s32 TLobby__data_805D611C;
extern s32 TLobby__data_805D6120;
void *find_scene_room_by_id(s32 room);
void apply_room_transform_to_enemy_rows(SpawnRecord_8020D36C *rows, s32 count);
void apply_room_transform_to_object_rows(Rec_8020D3F0 *arr, s32 n);
s32 find_set_factory_index(void *, void *);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
s32 is_quest_active();
s32 TLobby__sub_801C2614();
u8 *call_area_set_factory(void *, void *);
}
extern RecoveredGlobal_8020D2B4_lbl_8058D490 identity_matrix;
void apply_room_transform(s32 arg0, u8 *arg1, u8 *arg2);
s32 resolve_set_row_factory_indices(void *arg0, int arg1, int arg2);
extern Obj_8020D4E8 *camera_ctrl_instance;
s32 is_within_camera_distance(void *arg0, void *arg1, f32 farg0);
void spawn_decorations_in_range(void *arg0);
void apply_room_transform(s32 arg0, u8 *arg1, u8 *arg2) {
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
            apply_room_transform((s32)&row->position, (u8 *)&row->angles, (u8 *)cached_room);
        }
    }
}

void apply_room_transform_to_object_rows(Rec_8020D3F0 *arr, s32 n) {
    Rec_8020D3F0 *p;
    void *sec;
    s16 key;
    s32 i;
    key = -1;
    i = 0;
    for (; i < n; i++) {
        p = &arr[i];
        if (key != p->key) {
            sec = find_scene_room_by_id(p->key);
            key = p->key;
        }
        if (sec != NULL) {
            apply_room_transform((s32)p->a, p->b, (u8 *)sec);
        }
    }
}

s32 resolve_set_row_factory_indices(void *arg0, int arg1, int arg2) {
    Out_8020D474 o;
    Rec_8020D474 *p;
    s32 i;
    s32 r;
    p = (Rec_8020D474 *)arg1;
    for (i = 0; i < arg2; i++, p++) {
        if (p->id != -1) {
            r = find_set_factory_index(p, &o);
            if (r >= 0) {
                p->id = r;
            } else {
                p->id = -1;
            }
        }
    }
}

s32 is_within_camera_distance(void *arg0, void *arg1, f32 farg0) {
    s32 n;
    s32 i;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (camera_ctrl_instance != NULL) {
            n = TCameraCtrl::get_instance();
            for (i = 0; i < n; i++) {
                if (xyz_distance_squared((u8 *)arg1, (u8 *)&camera_ctrl_instance->ents[i]) < farg0) {
                    return 1;
                }
            }
        }
    } else if (camera_ctrl_instance != NULL && xyz_distance_squared((u8 *)arg1, (u8 *)&camera_ctrl_instance->single) < farg0) {
        return 1;
    }
    return 0;
}

void spawn_decorations_in_range(void *arg0) {
    Ent_8020D5AC *tbl;
    Rec_8020D5AC *p;
    s32 i;
    u8 *obj;
    tbl = floor_object_factory_tables[get_current_area()];
    if (tbl == NULL) {
        return;
    }
    if (TObjPlayer::get_player_count() != 0 && is_quest_active() != 0 && TLobby__sub_801C2614() == 0) {
        return;
    }
    p = (Rec_8020D5AC *)TLobby__data_805D611C;
    for (i = 0; i < TLobby__data_805D6120; i++, p++) {
        if (p->id != -1 && !(p->flags & 2) && !(p->flags & 8)
            && is_within_camera_distance(arg0, p->data, tbl[p->id].creation_distance_squared) == 1) {
            p->s8 = 0xFFFF;
            p->s4 = -1;
            obj = call_area_set_factory(arg0, p);
            if (obj != NULL) {
                p->obj = obj;
                *(s16 *)((s8 *)obj + 0x28) = p->sC;
                *(void **)((s8 *)obj + 0x80) = p;
                p->flags |= 2;
            } else {
                p->obj = NULL;
                p->flags |= 8;
            }
        }
    }
}

void TSetManager::update_decoration_spawning() { spawn_decorations_in_range(this); }
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
typedef char RecoveredGlobal_8020D6F0_TLobby__data_80513AD0_size[sizeof(RecoveredGlobal_8020D6F0_TLobby__data_80513AD0) == 0x1B0 ? 1 : -1];
void TSetManager::apply_floor_set_rows() {
    u8 *arg0 = (u8 *)this;
    s32 current_floor;
    u8 *temp_r30;
    current_floor = get_current_floor();
    TLobby__data_805D60FC = current_floor;
    temp_r30 = (u8 *)&TLobby__floor_enemy_group_table.value + (current_floor * 0x18);
    if (!(*(s32 *)((s8 *)temp_r30 + 8) & 2)) {
        apply_room_transform_to_object_rows((Rec_8020D3F0 *)(TLobby__data_805D610C), (s32)((int) (*(s32 *)((s8 *)temp_r30 + 0))));
        *(s32 *)((s8 *)temp_r30 + 8) = (s32) (*(s32 *)((s8 *)temp_r30 + 8) | 2);
    }
    if (!(*(s32 *)((s8 *)temp_r30 + 0xC) & 4)) {
        apply_room_transform_to_enemy_rows((SpawnRecord_8020D36C *)(TLobby__data_805D6114), (s32)((int) (*(s32 *)((s8 *)temp_r30 + 4))));
        *(s32 *)((s8 *)temp_r30 + 0xC) = (s32) (*(s32 *)((s8 *)temp_r30 + 0xC) | 4);
    }
    if (*(s32 *)((s8 *)temp_r30 + 8) & 2) {
        TLobby::assign_objects_to_slots((u8 *)TLobby__data_805D610C, (s32)((int) (*(s32 *)((s8 *)temp_r30 + 0))));
    }
    if (*(s32 *)((s8 *)temp_r30 + 0xC) & 4) {
        TLobby::assign_display_objects((u8 *)TLobby__data_805D6114, (s32)((int) (*(s32 *)((s8 *)temp_r30 + 4))));
    }
    if ((s32) TLobby__data_805D6120 > 0) {
        apply_room_transform_to_object_rows((Rec_8020D3F0 *)(TLobby__data_805D611C), TLobby__data_805D6120);
        resolve_set_row_factory_indices(arg0, TLobby__data_805D611C, TLobby__data_805D6120);
    }
    *(s32 *)((s8 *)arg0 + 0x1C) = 1;
}
#pragma pop
