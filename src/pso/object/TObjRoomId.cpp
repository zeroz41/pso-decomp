#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D96A8.h"

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_801A1CD8___vt__10TObjRoomId {
    s32 value;
    u8 remaining[0x34];
};

struct Obj_801A1888 { u8 pad[0x38]; f32 pos[3]; };

struct Vec_801A1A60 { f32 x, y, z; };
// The class name, then the direction run_task rotates by the object's yaw into normal, the plane
// normal its vec3_dot side test uses (room_id_base_normal is an inferred name).
const char *TObjRoomId__name = "TObjRoomId";
static const Vec_801A1A60 room_id_base_normal = {0.0f, 0.0f, -1.0f};

struct TObjRoomId {
    u8 pad0[0x38];
    Vec_801A1A60 pos;
    u8 pad44[0x68 - 0x44];
    f32 radius;
    f32 room_pos;
    f32 room_other;
    u8 pad74[0x88 - 0x74];
    s32 yaw;
    u32 mode;
    Vec_801A1A60 normal;
    void run_task();
};

struct Vec_801A18EC { f32 x, y, z; };


struct RoomId_801A18EC {
    u8 pad0[0x38];
    Vec_801A18EC pos;
    u8 pad44[0x24];
    f32 radius;
    u8 pad6c[0x24];
    Vec_801A18EC dir;
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__10TObjRoomId[];
u8 *TObjRoomId__ct(u8 *arg0, s32 arg1, s32 arg2);
u16 TObjRoomId__sub_801A1DB8(u16 x);
f32 horizontal_distance_squared(f32 *a, f32 *b);
s32 is_player_in_range__10TObjRoomIdFPvUsf(Obj_801A1888 *self, u16 id, f32 range);
void draw_debug_line__10TObjRoomIdFUllll(void *, int, int, const char *);
void debug_draw_line(Vec_801A18EC *, Vec_801A18EC *, u32, u32);
void fn_80141CBC(void *a, void *b, f32 s);
void debug_draw_sphere(const Vec_801A18EC *pos, const NJS_ARGB *color, f32 radius);
void render__10TObjRoomIdFv(RoomId_801A18EC *self);
s32 matrix_mult_vec(int, void *, void *);
f32 vec3_dot(Vec_801A1A60 *, Vec_801A1A60 *);
void *__dt__10TObjRoomIdFv(void *arg0, s16 arg1);
void *create__10TObjRoomIdFPv(void *arg0);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

s32 is_player_in_range__10TObjRoomIdFPvUsf(Obj_801A1888 *self, u16 id, f32 range) {
    Obj_801A1888 *p = (Obj_801A1888 *)get_player_by_client_id(id);
    if (p == 0) {
        return 0;
    }
    return horizontal_distance_squared(p->pos, self->pos) < range;
}

#pragma push
#pragma fp_contract on
void render__10TObjRoomIdFv(RoomId_801A18EC *self) {
    if (TObjPlayer::check_demo_mode() != 0) {
        NJS_ARGB c1 = { 0.5f, 1.0f, 1.0f, 0.0f };
        NJS_ARGB c2 = { 0.5f, 0.0f, 1.0f, 1.0f };
        Vec_801A18EC end;
        debug_draw_sphere(&self->pos, &c2, 2.0f * (10.0f * self->radius));
        fn_80141CBC(&self->pos, &c1, 10.0f * self->radius);
        end.x = 10.0f * self->dir.x + self->pos.x;
        end.y = 10.0f * self->dir.y + self->pos.y;
        end.z = 10.0f * self->dir.z + self->pos.z;
        debug_draw_line(&self->pos, &end, 0xFFFF0000, 0xFFFF0000);
        debug_draw_sphere(&end, &c2, 2.0f);
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x1C, "<- SCL_TAMA");
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x1D, "<- + NUMBER");
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x1E, "<- - NUMBER");
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x22, "<- - 10000 : BLOCK ID ");
    }
}
}
extern u8 identity_matrix[];
void set_player_room_control_flag(TObjPlayer *arg0);
#pragma pop

#pragma push
#pragma fp_contract on
void TObjRoomId::run_task() {
    TObjRoomId *o = this;
    Vec_801A1A60 v = room_id_base_normal;
    Vec_801A1A60 d;
    s32 absent;
    f32 r;

    absent = 1;
    if (TObjPlayer::check_demo_mode() == 0) {
        for (s32 i = 0; i < 4; i++) {
            if (get_player_by_client_id(i) != NULL) {
                r = 10.0f * o->radius + 30.0f;
                if (is_player_in_range__10TObjRoomIdFPvUsf((Obj_801A1888 *)o, i, r * r) != 0) {
                    absent = 0;
                }
            }
        }
    }
    if (TObjPlayer::check_demo_mode() == 0 && absent != 0) {
        return;
    }
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, o->yaw);
    matrix_mult_vec(0, &v, &o->normal);
    pop_matrices(1);
    for (s32 i = 0; i < 4; i++) {
        Obj_801A1888 *p = (Obj_801A1888 *)get_player_by_client_id(i);
        if (p == NULL) {
            continue;
        }
        r = 10.0f * o->radius;
        if (is_player_in_range__10TObjRoomIdFPvUsf((Obj_801A1888 *)o, i, r * r) == 0) {
            continue;
        }
        d.x = p->pos[0] - o->pos.x;
        d.y = 0.0f;
        d.z = p->pos[2] - o->pos.z;
        if (vec3_dot(&d, &o->normal) > 0.0f) {
            if (o->mode == 0x10000) {
                *(s16 *)((s8 *)p + 0x28) = (s16)o->room_pos;
                set_player_room_control_flag((TObjPlayer *)p);
            } else {
                ((TObjPlayer *)p)->set_room((s16)o->room_pos);
            }
        } else {
            if (o->mode == 0x10000) {
                *(s16 *)((s8 *)p + 0x28) = (s16)o->room_other;
                set_player_room_control_flag((TObjPlayer *)p);
            } else {
                ((TObjPlayer *)p)->set_room((s16)o->room_other);
            }
        }
    }
}
#pragma pop

void *__dt__10TObjRoomIdFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TObjRoomId;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

typedef char RecoveredGlobal_801A1CD8___vt__10TObjRoomId_size[sizeof(RecoveredGlobal_801A1CD8___vt__10TObjRoomId) == 0x38 ? 1 : -1];
u8 *TObjRoomId__ct(u8 *arg0, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)arg0, (void *)parent);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801A1CD8___vt__10TObjRoomId *)&__vt__10TObjRoomId).value;
    *(const char **)((s8 *)arg0 + 0) = TObjRoomId__name;
    ((VObj_18_1a504b *)(arg0))->m5(arg2);
    *(f32 *)((s8 *)arg0 + 0x90) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x94) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x98) = 0.0f;
    return arg0;
}

void *create__10TObjRoomIdFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x9C);
    if (o != NULL) {
        o = TObjRoomId__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void set_player_room_control_flag(TObjPlayer *player) {
    player->set_state_flags(0x02000000);
}

extern s32 local_client_id;

u16 TObjRoomId__sub_801A1DB8(u16 x) {
    u16 r;
    if (x == 0xFFFF) {
        r = 0xFFFF;
    } else {
        r = x & 0x5000;
    }
    return r;
}

u8 TObjPlayer::sub_801A1DDC() {
    if (is_split_screen() != 0) {
        return 1U;
    }
    return (u8) (this->entity_id == local_client_id);
}
