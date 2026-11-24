#include "pso/player/TPlyInventory.h"
#include "pso/player/PlayerLevelTable.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TPlyItem.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCharDataEntry.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/player/PlayerTelepipe.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/PhotonBlastResults.h"

struct O_801C21D4 { u8 pad[0x3a1]; u8 id; u8 pad2[0x408 - 0x3a2]; u8 arr[1]; };

extern "C" {
s32 __ct__12TPlyCharDataFv(s32 arg0);
u8 get_record_byte_at(TPlyCharData *data, s32 tech);
void is_slot_within_limit__10TObjPlayerFllUc(u8 id, s16 i, u8 v);
extern const f32 TObjPlayer__data_805DC278;
s32 test_flags_any(s32 *flags, s32 mask);

extern const f32 TObjPlayer__data_805DC294;

PlayerAttackController *PlayerAttackController::init() {
    __ct__8FlagWordFv(&flags);
    TObjPlayer__sub_8012AF00(&lockon_targets);
    evp_scale = TObjPlayer__data_805DC294;
    reset();
    return this;
}

s32 is_field_0_positive(s32 *count) {
    return *count > 0;
}

TItemData *get_ptr_8(TPlyInventoryItem *item) { return &item->m_data; }
void PendingItemDrop::set_source_id(s32 id) { source_id = id; }
PendingItemDrop::PendingItemDrop() {}
Unk_801C2098::Unk_801C2098() { state = 0; }

PlayerTelepipe *init_player_telepipe_record(PlayerTelepipe *telepipe) {
    __ct__8FlagWordFv(&telepipe->flags);
    telepipe->state.owner_client_id = 0xFFFF;
    telepipe->state.room_id = 0;
    telepipe->state.pos.x = TObjPlayer__data_805DC278;
    telepipe->state.pos.y = TObjPlayer__data_805DC278;
    telepipe->state.pos.z = TObjPlayer__data_805DC278;
    telepipe->state.angle_y = 0;
    telepipe->state.floor = 0;
    ((TTecLuker *)&telepipe->flags)->set_state(0xFFFF);
    return telepipe;
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
    TPlyInventoryItem *items = reinterpret_cast<TPlyCharData *>(this)->m_inventory.m_items;
    u32 r = (u8)items[4].m_present[3];
    r |= (u8)items[5].m_present[3] << 8;
    r |= (u8)items[6].m_present[3] << 16;
    r |= (u8)items[7].m_present[3] << 24;
    return r;
}

u32 TObjPlayer::unpack_u32_lo() {
    TPlyInventoryItem *items = reinterpret_cast<TPlyCharData *>(this)->m_inventory.m_items;
    u32 r = (u8)items[0].m_present[3];
    r |= (u8)items[1].m_present[3] << 8;
    r |= (u8)items[2].m_present[3] << 16;
    r |= (u8)items[3].m_present[3] << 24;
    return r;
}

u8 get_byte_1ab(const TPlyCharData *data) { return data->m_inventory.m_items[15].m_present[3]; }
u8 get_byte_18f(const TPlyCharData *data) { return data->m_inventory.m_items[14].m_present[3]; }
u8 get_byte_173(const TPlyCharData *data) { return data->m_inventory.m_items[13].m_present[3]; }

u8 get_record_byte_at(TPlyCharData *data, s32 tech) {
    return data->m_inventory.m_items[tech].m_present[2];
}

s32 TObjPlayer::get_slot_value_checked(s32 i) {
    O_801C21D4 *self = (O_801C21D4 *)this;
    u8 v = self->arr[i];
    is_slot_within_limit__10TObjPlayerFllUc(self->id, i, v);
    return (u8)(v);
}

TPlyInventoryItem *TPlyInventory::get_items() { return m_items; }
u8 TPlyCharData::get_luck_materials_used() { return m_inventory.m_items[12].m_present[3]; }
u8 TPlyCharData::get_def_materials_used() { return m_inventory.m_items[11].m_present[3]; }
u8 TPlyCharData::get_evade_materials_used() { return m_inventory.m_items[10].m_present[3]; }
u8 TPlyCharData::get_mind_materials_used() { return m_inventory.m_items[9].m_present[3]; }
u8 TPlyCharData::get_power_materials_used() { return m_inventory.m_items[8].m_present[3]; }
void PhotonChairSeat::set_owner_id(u16 id) { owner_id = id; }
PhotonChairSeat::PhotonChairSeat() { reset(); }

int PlayerCharDataEntry::has_character() { return test_flags_any((s32 *)&flags, 1); }
u8 *PlayerCharDataEntry::get_lobby_header() { return lobby_header; }
TPlyCharData *PlayerCharDataEntry::get_char_data() { return &char_data; }
s32 PlayerCharDataEntry::get_role() { return role; }
PlayerCharDataEntry *PlayerCharDataEntry::construct() { ((TObjPlayer *)lobby_header)->clear_header_struct(); __ct__12TPlyCharDataFv((saddr)&char_data); __ct__8FlagWordFv(&flags); role = 0; return this; }

}

PhotonBlastRequestTable::~PhotonBlastRequestTable() {}

PhotonBlastRequestTable::PhotonBlastRequestTable() {}
