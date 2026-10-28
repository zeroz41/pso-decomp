#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

struct Rec_80116620 { u8 pad[0xC]; };

struct Obj_80116620 { u8 pad[0x4]; Rec_80116620 recs[1]; };

extern "C" {
Rec_80116620 *TObjPlayer__sub_80116620(Obj_80116620 *self, s32 i);

s32 TItem::get_item_flags() { return this->item_flags; }
void TObjPlayer::bswap_fields_x4() { read_be16_field2(); { int i; for (i = 0; i < 4; i++) { bswap_16((u16 *)((char*)this + 0x4 + i * 2)); } } }
void TObjPlayer::bswap_and_send_item() { bswap_fields_x4(); send_subcommand((u8 *)this); }
void TObjPlayer::set_type_bytes() { *(u8*)((char*)this + 0x0) = 102; *(u8*)((char*)this + 0x1) = 3; }

u16 TObjPlayer::get_type_id() { return *(u16*)((char*)this + 0x0); }
Rec_80116620 *TObjPlayer__sub_80116620(Obj_80116620 *self, s32 i) {
    return &self->recs[i];
}

}
