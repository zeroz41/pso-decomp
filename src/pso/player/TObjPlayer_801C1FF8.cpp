#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TPlyCharData_8007214C.h"
#include "pso/player/TObjPlayer_801AA508.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecLuker.h"

struct E_801C2154 { u8 pad[7]; char v; u8 pad2[0x14]; };

struct O_801C2154 { E_801C2154 recs[8]; };

struct E_801C2180 { u8 pad[7]; char v; u8 pad2[0x14]; };

struct O_801C2180 { E_801C2180 recs[8]; };

struct E_801C21C4 { u8 pad[6]; u8 v; u8 pad2[0x15]; };

struct O_801C21C4 { E_801C21C4 recs[8]; };

struct O_801C21D4 { u8 pad[0x3a1]; u8 id; u8 pad2[0x408 - 0x3a2]; u8 arr[1]; };

struct S_801C20A4 { u16 f0; s16 f2; s32 f4; f32 f8; f32 fC; f32 f10; s32 f14; u8 f18[1]; };

extern "C" {
u8 TObjPlayer__sub_801C21C4(O_801C21C4 *self, s32 i);
void is_slot_within_limit__10TObjPlayerFllUc(u8 id, s16 i, u8 v);
void __destroy_arr(void *, void *, int, int);
void __construct_array(void *, void *, void *, int, int);
void init_arrays__10TObjPlayerFv(void);
extern const f32 TObjPlayer__data_805DC278;
S_801C20A4 *init_player_telepipe_record(S_801C20A4 *arg0);
int test_flags_any(void*, int);
void TObjPlayer__sub_8012AF00(void *);
int fn_8035B00C(void*);

extern const f32 TObjPlayer__data_805DC294;

void *TObjPlayer::init() {
    __ct__8FlagWordFv(((char *)this + 12));
    TObjPlayer__sub_8012AF00((void *)((char *)this + 48));
    *(f32 *)((s8 *)this + 0x8) = TObjPlayer__data_805DC294;
    reset_movement_state();
    return this;
}

s32 TObjPlayer__sub_801C2044(s32 *arg0) {
    return *arg0 > 0;
}

void* TObjPlayer__sub_801C2058(void* p) { return (char*)p + 0x8; }
void TObjPlayer::set_field4(s32 v) { *(s32*)((char*)this + 0x4) = v; }
void*TObjPlayer::init_c2098_return_self() { TObjPlayer__sub_801C2098(this); return this; }
void TObjPlayer__sub_801C2098(void* p) { *(s32*)((char*)p + 0x0) = 0; }

S_801C20A4 *init_player_telepipe_record(S_801C20A4 *arg0) {
    __ct__8FlagWordFv((arg0->f18));
    arg0->f0 = 0xFFFF;
    arg0->f4 = 0;
    arg0->f8 = TObjPlayer__data_805DC278;
    arg0->fC = TObjPlayer__data_805DC278;
    arg0->f10 = TObjPlayer__data_805DC278;
    arg0->f14 = 0;
    arg0->f2 = 0;
    ((TTecLuker *)(arg0->f18))->set_state(0xFFFF);
    return arg0;
}

void TObjPlayer__sub_801C210C(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
int TObjPlayer__sub_801C2114(void) { return 0; }
u8 TObjPlayer::get_field_5() { return *(u8*)((char*)this + 0x5); }
u8 TObjPlayer::get_byte_4() { return *(u8*)((char*)this + 0x4); }
u8 TObjPlayer__sub_801C212C(void* p) { return *(u8*)((char*)p + 0x3); }
u8 TObjPlayer__sub_801C2134(void* p) { return *(u8*)((char*)p + 0x2); }
u8 TObjPlayer::get_team_id() { return *(u8*)((char*)this + 0x1); }
u8 TObjPlayer::get_char_class() { return *(u8*)((char*)this + 0x0); }
s32 get_level_row_exp_threshold(void* p) { return *(s32*)((char*)p + 0x8); }

u32 TObjPlayer::unpack_u32_hi() {
    O_801C2154 *self = (O_801C2154 *)this;
    u32 r = (u8)self->recs[4].v;
    r |= (u8)self->recs[5].v << 8;
    r |= (u8)self->recs[6].v << 16;
    r |= (u8)self->recs[7].v << 24;
    return r;
}

u32 TObjPlayer::unpack_u32_lo() {
    O_801C2180 *self = (O_801C2180 *)this;
    u32 r = (u8)self->recs[0].v;
    r |= (u8)self->recs[1].v << 8;
    r |= (u8)self->recs[2].v << 16;
    r |= (u8)self->recs[3].v << 24;
    return r;
}

u8 TObjPlayer__sub_801C21AC(void* p) { return *(u8*)((char*)p + 0x1ab); }
u8 TObjPlayer__sub_801C21B4(void* p) { return *(u8*)((char*)p + 0x18f); }
u8 TObjPlayer__sub_801C21BC(void* p) { return *(u8*)((char*)p + 0x173); }

u8 TObjPlayer__sub_801C21C4(O_801C21C4 *self, s32 i) {
    return self->recs[i].v;
}

u8 TObjPlayer::get_slot_value_checked(s32 i) {
    O_801C21D4 *self = (O_801C21D4 *)this;
    u8 v = self->arr[i];
    is_slot_within_limit__10TObjPlayerFllUc(self->id, i, v);
    return v;
}

void*TObjPlayer::get_ptr_4() { return (char*)this + 0x4; }
u8 TObjPlayer__sub_801C221C(void* p) { return *(u8*)((char*)p + 0x157); }
u8 TObjPlayer__sub_801C2224(void* p) { return *(u8*)((char*)p + 0x13b); }
u8 TObjPlayer__sub_801C222C(void* p) { return *(u8*)((char*)p + 0x11f); }
u8 TObjPlayer__sub_801C2234(void* p) { return *(u8*)((char*)p + 0x103); }
u8 TObjPlayer__sub_801C223C(void* p) { return *(u8*)((char*)p + 0xe7); }
void TObjPlayer__sub_801C2244(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }
void*TObjPlayer::setup_ctrl() { fn_8035B00C(this); return this; }

int TObjPlayer::check_flag_at_428() { return test_flags_any((char*)this + 0x428, 1); }
void*TObjPlayer::get_sub_obj() { return (char*)this + 0x4; }
void*TObjPlayer::get_char_data() { return (char*)this + 0xc; }
s32 TObjPlayer__sub_801C22B4(void* p) { return *(s32*)((char*)p + 0x0); }
void*TObjPlayer::init_char_data() { ((TObjPlayer *)((char*)this + 0x4))->clear_header_struct(); __ct__12TPlyCharDataFv((s32)((char*)this + 0xc)); __ct__8FlagWordFv(((char*)this + 0x428)); *(int*)(this) = 0; return this; }

void *fn_801C2308(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr(arg0, (void *)TObjPlayer__sub_801AA528, 0x18, 4);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}
void *fn_801C2360(void *arg0) {
    __construct_array(arg0, (void *)init_arrays__10TObjPlayerFv, (void *)TObjPlayer__sub_801AA528, 0x18, 4);
    return arg0;
}

}
