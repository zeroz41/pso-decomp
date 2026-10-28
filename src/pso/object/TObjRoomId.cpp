#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

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
struct I3_801A1A60 { s32 a, b, c; };
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

struct Color_801A18EC { f32 r, g, b, a; };

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
extern s32 lbl_805D34B0;
extern const f32 lbl_805DC094;
u8 *TObjRoomId__ct(u8 *arg0, s32 arg1, s32 arg2);
u16 TObjRoomId__sub_801A1DB8(u16 x);
void *get_player_by_client_id(s32 i);
f32 horizontal_distance_squared(f32 *a, f32 *b);
s32 is_player_in_range__10TObjRoomIdFPvUsf(Obj_801A1888 *self, u16 id, f32 range);
void draw_debug_line__10TObjRoomIdFUllll(void *, int, int, void *);
void TObjMapWarp__sub_80141CB0(Vec_801A18EC *, Vec_801A18EC *, u32, u32);
void fn_80141CBC(void *a, void *b, f32 s);
void TObjRoomId__sub_80141CF4(Vec_801A18EC *, Color_801A18EC *, f32);
extern u8 lbl_804468B8[];
extern u8 lbl_804468C4[];
extern u8 lbl_804468D0[];
extern u8 lbl_804468DC[];
extern const f32 lbl_805DC088;
extern const f32 lbl_805DC08C;
void render__10TObjRoomIdFv(RoomId_801A18EC *self);
s32 push_matrix_from(void *);
void rotate_matrix_y(int, s32);
s32 matrix_mult_vec(int, void *, void *);
s32 pop_matrices(s32 arg0);
f32 vec3_dot(Vec_801A1A60 *, Vec_801A1A60 *);
void *__dt__10TObjRoomIdFv(void *arg0, s16 arg1);
void *create__10TObjRoomIdFPv(void *arg0);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
s32 is_split_screen();

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
        Color_801A18EC c1 = { 0.5f, 1.0f, 1.0f, 0.0f };
        Color_801A18EC c2 = { 0.5f, 0.0f, 1.0f, 1.0f };
        Vec_801A18EC end;
        TObjRoomId__sub_80141CF4(&self->pos, &c2, lbl_805DC088 * (lbl_805DC08C * self->radius));
        fn_80141CBC(&self->pos, &c1, lbl_805DC08C * self->radius);
        end.x = lbl_805DC08C * self->dir.x + self->pos.x;
        end.y = lbl_805DC08C * self->dir.y + self->pos.y;
        end.z = lbl_805DC08C * self->dir.z + self->pos.z;
        TObjMapWarp__sub_80141CB0(&self->pos, &end, 0xFFFF0000, 0xFFFF0000);
        TObjRoomId__sub_80141CF4(&end, &c2, lbl_805DC088);
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x1C, lbl_804468B8);
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x1D, lbl_804468C4);
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x1E, lbl_804468D0);
        draw_debug_line__10TObjRoomIdFUllll(self, 0x13, 0x22, lbl_804468DC);
    }
}
}
extern Vec_801A1A60 lbl_8044688C[];
extern u8 identity_matrix[];
extern const f32 lbl_805DC090;
void set_player_room_control_flag(TObjPlayer *arg0);
#pragma pop

#pragma push
#pragma fp_contract on
void TObjRoomId::run_task() {
    TObjRoomId *o = this;
    Vec_801A1A60 v;
    Vec_801A1A60 d;
    s32 absent;
    f32 r;

    ((I3_801A1A60 *)&v)->a = ((I3_801A1A60 *)lbl_8044688C)->a;
    ((I3_801A1A60 *)&v)->b = ((I3_801A1A60 *)lbl_8044688C)->b;
    ((I3_801A1A60 *)&v)->c = ((I3_801A1A60 *)lbl_8044688C)->c;
    absent = 1;
    if (TObjPlayer::check_demo_mode() == 0) {
        for (s32 i = 0; i < 4; i++) {
            if (get_player_by_client_id(i) != NULL) {
                r = lbl_805DC08C * o->radius + lbl_805DC090;
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
        r = lbl_805DC08C * o->radius;
        if (is_player_in_range__10TObjRoomIdFPvUsf((Obj_801A1888 *)o, i, r * r) == 0) {
            continue;
        }
        d.x = p->pos[0] - o->pos.x;
        d.y = lbl_805DC094;
        d.z = p->pos[2] - o->pos.z;
        if (vec3_dot(&d, &o->normal) > lbl_805DC094) {
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
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D34B0;
    ((VObj_18_1a504b *)(arg0))->m5(arg2);
    *(f32 *)((s8 *)arg0 + 0x90) = (f32) lbl_805DC094;
    *(f32 *)((s8 *)arg0 + 0x94) = (f32) lbl_805DC094;
    *(f32 *)((s8 *)arg0 + 0x98) = (f32) lbl_805DC094;
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
