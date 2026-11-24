#include "pso/player/TPlyInventory.h"
#include "pso/player/PlayerLevelTable.h"
#include "pso/player/PhotonBlastRequests.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyCharData_8007214C.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TPlyItem.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/CapturedTargetList.h"

struct E_801C2154 { u8 pad[7]; char v; u8 pad2[0x14]; };

struct O_801C2154 { E_801C2154 recs[8]; };

struct E_801C2180 { u8 pad[7]; char v; u8 pad2[0x14]; };

struct O_801C2180 { E_801C2180 recs[8]; };

struct E_801C21C4 { u8 pad[6]; u8 v; u8 pad2[0x15]; };

struct O_801C21C4 { E_801C21C4 recs[8]; };

struct O_801C21D4 { u8 pad[0x3a1]; u8 id; u8 pad2[0x408 - 0x3a2]; u8 arr[1]; };

struct S_801C20A4 { u16 f0; s16 f2; s32 f4; f32 f8; f32 fC; f32 f10; s32 f14; u8 f18[1]; };

extern "C" {
u8 get_record_byte_at(O_801C21C4 *self, s32 i);
void is_slot_within_limit__10TObjPlayerFllUc(u8 id, s16 i, u8 v);
extern const f32 TObjPlayer__data_805DC278;
S_801C20A4 *init_player_telepipe_record(S_801C20A4 *arg0);
s32 test_flags_any(s32 *flags, s32 mask);

extern const f32 TObjPlayer__data_805DC294;

void *TObjPlayer::init() {
    __ct__8FlagWordFv(((char *)this + 12));
    TObjPlayer__sub_8012AF00((CapturedTargetList *)((char *)this + 48));
    *(f32 *)((s8 *)this + 0x8) = TObjPlayer__data_805DC294;
    reset_movement_state();
    return this;
}

s32 is_field_0_positive(s32 *arg0) {
    return *arg0 > 0;
}

void* get_ptr_8(void* p) { return (char*)p + 0x8; }
void PendingItemDrop::set_source_id(s32 id) { source_id = id; }
PendingItemDrop::PendingItemDrop() {}
Unk_801C2098::Unk_801C2098() { state = 0; }

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

void set_field_0_s32(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
int TObjPlayer::default_action_provider_variant() { return 0; }
u8 get_field_5__10TObjPlayerFv(const PlayerLevelTableRow *row) { return row->growth[5]; }
u8 get_byte_4__10TObjPlayerFv(const PlayerLevelTableRow *row) { return row->growth[4]; }
u8 get_byte_3(const PlayerLevelTableRow *row) { return row->growth[3]; }
u8 get_byte_2(const PlayerLevelTableRow *row) { return row->growth[2]; }
u8 get_team_id__10TObjPlayerFv(const PlayerLevelTableRow *row) { return row->growth[1]; }
u8 get_char_class__10TObjPlayerFv(const PlayerLevelTableRow *row) { return row->growth[0]; }
s32 get_level_row_exp_threshold(const PlayerLevelTableRow *row) { return row->experience; }

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

u8 get_byte_1ab(void* p) { return *(u8*)((char*)p + 0x1ab); }
u8 get_byte_18f(void* p) { return *(u8*)((char*)p + 0x18f); }
u8 get_byte_173(void* p) { return *(u8*)((char*)p + 0x173); }

u8 get_record_byte_at(O_801C21C4 *self, s32 i) {
    return self->recs[i].v;
}

s32 TObjPlayer::get_slot_value_checked(s32 i) {
    O_801C21D4 *self = (O_801C21D4 *)this;
    u8 v = self->arr[i];
    is_slot_within_limit__10TObjPlayerFllUc(self->id, i, v);
    return (u8)(v);
}

TPlyInventoryItem *TPlyInventory::get_items() { return m_items; }
u8 get_byte_157(void* p) { return *(u8*)((char*)p + 0x157); }
u8 get_byte_13b(void* p) { return *(u8*)((char*)p + 0x13b); }
u8 get_byte_11f(void* p) { return *(u8*)((char*)p + 0x11f); }
u8 get_byte_103(void* p) { return *(u8*)((char*)p + 0x103); }
u8 get_byte_e7(void* p) { return *(u8*)((char*)p + 0xe7); }
void PhotonChairSeat::set_owner_id(u16 id) { owner_id = id; }
PhotonChairSeat::PhotonChairSeat() { reset(); }

int TObjPlayer::check_flag_at_428() { return test_flags_any((s32 *)((char*)this + 0x428), 1); }
void*TObjPlayer::get_sub_obj() { return (char*)this + 0x4; }
TPlyCharData *TObjPlayer::get_char_data() { return reinterpret_cast<TPlyCharData *>(reinterpret_cast<u8 *>(this) + 0xC); }
s32 get_field_0_s32(void* p) { return *(s32*)((char*)p + 0x0); }
void*TObjPlayer::init_char_data() { ((TObjPlayer *)((char*)this + 0x4))->clear_header_struct(); __ct__12TPlyCharDataFv((saddr)((char*)this + 0xc)); __ct__8FlagWordFv(((char*)this + 0x428)); *(int*)(this) = 0; return this; }

PhotonBlastRegistry::~PhotonBlastRegistry() {}

PhotonBlastRegistry::PhotonBlastRegistry() {}

}
