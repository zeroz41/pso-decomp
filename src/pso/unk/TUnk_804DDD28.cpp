// TUnk_804DDD28, the base of the player action providers: its constructor,
// destructor and key function (get_cell_address), so its table is emitted here.
#include <string.h>
#include "pso/system/RlcArchive.h"
#include "pso/system/ControllerInputState.h"
#include "types.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

struct Pair_802A7994 { s32 a; s32 b; };

// This TU's .rodata, .sdata and .sbss: each sits between TLobby_802A7290's and
// TWindowSnapShot's sections, padded to an 8-byte unit boundary.
#pragma push
#pragma readonly_strings on
const char *player_motion_data_filename_ptr = "PlyMotionData.rlc";
#pragma pop

int player_action_provider_selector;

extern "C" {
void zero_pair_fields(void* p);
extern uaddr snapshot_image_buffer;
void free_snapshot_image_buffer(void);
void set_slot_size(void *p, s32 v);
void set_slot_offset(void *p, s32 v);
extern s32 lbl_805D669C;
void set_slot_position__6TLobbyFii(s32 arg0, saddr arg1);
s32 aram_dma_blocking__6TLobbyFllll(s32, s32, s32, s32, s32);
saddr TItemDrop__sub_800F9448(saddr arg0, s32 size);
void set_motion_variant(void* p, s32 _w1);
int matches_loaded_motion(void* p);
int match_coordinate_pair(void*);

void set_motion_variant(void* p, s32 _w1) { ((TLobby *)p)->set_field_4(_w1); }
int matches_loaded_motion(void* p) { return match_coordinate_pair(p); }

void TLobby::set_photon_chair_flag(int photon_chair_flag) { player_action_provider_selector = photon_chair_flag; }
struct _VBase802A78E4_802a78e4_802A7848 { char pad[8]; };
struct _VObj802A78E4_802a78e4_802A7848 : _VBase802A78E4_802a78e4_802A7848 { virtual s32 m0(s32, s32); };
void TLobby::set_field_4(s32 v) { *(s32 *)&this->m_flags = v; }
s32 TLobby::get_hold_effect_size_by_type() {
    s32 hold_effect_count;
    hold_effect_count = TObjPlayer::get_hold_effect_count();
    switch (hold_effect_count) {
    case 0:
        return 0x38;
    case 1:
        return 0x10;
    default:
        return 0;
    }
}
s32 TLobby::send_packet(s32 arg1, s32 arg2, s32 size, s32 arg4) {
    s32 temp_r31;
    s32 temp_r31_2;
    saddr temp_r3;
    s32 dst;
    temp_r31_2 = (size + 0x1F) & 0xFFFFFFE0;
    temp_r3 = (saddr)mem_alloc(temp_r31_2);
    if (temp_r3 == 0) {
        return 0;
    }
    TLobby::send_type2_event(arg4, temp_r3, temp_r31_2);
    dst = ((_VObj802A78E4_802a78e4_802A7848*)this)->m0(arg1, arg2);
    temp_r31 = ((TLobby *)temp_r3)->write_packet_header(size, dst, 0x4000);
    mem_free((void *)temp_r3);
    return temp_r31;
}

s32 TUnk_804DDD28::load_action_motion_pairs(s32 arg1, s32 id, s32 flags) {
    Pair_802A7994 sp8;
    const s32 *slots;
    s32 i;
    s32 f4;
    s32 pkt;
    u8 *dst;
    s32 *drop;
    if (this->vfunc_4() == 0U) {
        return 0;
    }
    slots = this->vfunc_8(id, flags);
    if (slots == NULL) {
        return 0;
    }
    zero_pair_fields(&sp8);
    dst = (u8 *)this->get_state_table(id);
    for (i = 0; i < this->vfunc_75(); i++) {
        ((void (*)(s32, void *))set_slot_position__6TLobbyFii)(*slots, &sp8);
        f4 = ((TLobby *)(&sp8))->get_field_04();
        pkt = ((TLobby *)this)->send_packet(arg1, i, f4, ((TLobby *)(&sp8))->get_param());
        if (pkt != 0) {
            drop = (s32 *)TItemDrop__sub_800F9448(this->get_cell_address(arg1, i), pkt);
        }
        ((TUnk_804DDD28 *)dst)->copy_motion_pair(*(void **)drop);
        slots++;
        dst += 8;
    }
    return 1;
}

void TUnk_804DDD28::copy_motion_pair(void*q) { this->unk_0.m_0 = *(u32*)((char*)q + 0x0); this->unk_0.m_4 = *(u32*)((char*)q + 0x4); }

TUnk_804DDD28::~TUnk_804DDD28() {}

TUnk_804DDD28::TUnk_804DDD28() {}

s32 TUnk_804DDD28::get_cell_address(s32, s32) { return 0; }
int TUnk_804DDD28::vfunc_4() { return 0; }
const s32 *TUnk_804DDD28::vfunc_8(s32, s32) { return NULL; }
int TUnk_804DDD28::vfunc_9(s32, s32, s32) { return 0; }
void TUnk_804DDD28::vfunc_14() {  }
int TUnk_804DDD28::vfunc_75() { return 0; }
s32 TLobby::get_param() { return *(s32 *)&this->m_name; }
s32 TLobby::get_field_04() { return *(s32 *)&this->m_flags; }
void zero_pair_fields(void* p) { *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }
void free_snapshot_image_buffer(void) {
    if ((u32) snapshot_image_buffer != 0U) {
        mem_free(((void*)snapshot_image_buffer));
        snapshot_image_buffer = 0U;
    }
}
}
extern s32 snapshot_buffer_size;
s32 copy_if_space(void);
s32 copy_if_space(void) {
    if (shared_snapshot_capture->get_chunk_count() >= 0x258) {
        return 0;
    }
    memcpy((void *)snapshot_image_buffer, (const void *)shared_snapshot_capture->get_size(), snapshot_buffer_size);
    return 1;
}

void TLobby::alloc_snapshot_buffer() {
  saddr temp_r31;
  s32 max_players;
  u32 temp_r3;
  u8 *size;
  if (((u32) snapshot_image_buffer) == 0U)
  {
    temp_r31 = TWindowSnapShot::get_height();
    max_players = TLobby::get_max_players();
    max_players = max_players * temp_r31;
    temp_r31 = TWindowSnapShot::get_width();
    size = (u8 *) (temp_r31 + max_players);
    temp_r3 = ((saddr)mem_alloc((uaddr)size));
    snapshot_image_buffer = temp_r3;
    if (temp_r3 != 0U)
    {
      (*(u8 * *)&snapshot_buffer_size) = size;
    }
  }
}

void set_slot_position__6TLobbyFii(s32 arg0, saddr arg1) {
    saddr temp_r31;
    temp_r31 = ((RlcHeader *)(*(saddr *)&snapshot_image_buffer))->get_directory_offset();
    temp_r31 = (*(s32 *)&snapshot_image_buffer) + temp_r31;
    temp_r31 = temp_r31 + arg0 * 8;
    set_slot_offset((void *)arg1, lbl_805D669C + ((RlcDirectoryEntry *)temp_r31)->get_offset());
    set_slot_size((void *)arg1, ((RlcDirectoryEntry *)temp_r31)->get_size());
}
void TLobby::send_type2_event(s32 arg0, s32 arg1, s32 arg2) {
    aram_dma_blocking__6TLobbyFllll(2, arg0, arg1, arg2, arg0);
}
