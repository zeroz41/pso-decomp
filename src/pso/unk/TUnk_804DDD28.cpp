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
#include "pso/system/AramPool.h"

// This TU's .rodata, .sdata and .sbss: each sits between TLobby_802A7290's and
// TWindowSnapShot's sections, padded to an 8-byte unit boundary.
#pragma push
#pragma readonly_strings on
const char *player_motion_data_filename_ptr = "PlyMotionData.rlc";
#pragma pop

int player_action_provider_selector;

struct _VBase802A78E4_802a78e4_802A7848 { char pad[8]; };
struct _VObj802A78E4_802a78e4_802A7848 : _VBase802A78E4_802a78e4_802A7848 { virtual s32 m0(s32, s32); };

extern "C" {
void zero_pair_fields(void* p);
void set_slot_size(void *p, s32 v);
void set_slot_offset(void *p, s32 v);
saddr TItemDrop__sub_800F9448(saddr arg0, s32 size);
void set_motion_variant(void* p, s32 _w1);
int matches_loaded_motion(void* p);
int match_coordinate_pair(void*);

void set_motion_variant(void* p, s32 _w1) { ((TLobby *)p)->set_field_4(_w1); }
int matches_loaded_motion(void* p) { return match_coordinate_pair(p); }

void TLobby::set_photon_chair_flag(int photon_chair_flag) { player_action_provider_selector = photon_chair_flag; }
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
    u8 *buf;
    s32 dst;
    temp_r31_2 = (size + 0x1F) & 0xFFFFFFE0;
    buf = (u8 *)mem_alloc(temp_r31_2);
    if (buf == 0) {
        return 0;
    }
    read_player_motion(arg4, buf, temp_r31_2);
    dst = ((_VObj802A78E4_802a78e4_802A7848*)this)->m0(arg1, arg2);
    temp_r31 = ((TLobby *)buf)->write_packet_header(size, dst, 0x4000);
    mem_free(buf);
    return temp_r31;
}

s32 TUnk_804DDD28::load_action_motion_pairs(s32 arg1, s32 id, s32 flags) {
    PlayerMotionAramEntry sp8;
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
        get_player_motion_entry(*slots, &sp8);
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
}
void free_player_motion_directory() {
    if (player_motion_directory != NULL) {
        mem_free(player_motion_directory);
        player_motion_directory = NULL;
    }
}

s32 copy_player_motion_directory() {
    if (player_motion_archive->get_chunk_count() >= 0x258) {
        return 0;
    }
    memcpy(player_motion_directory, player_motion_archive->get_header(), player_motion_directory_size);
    return 1;
}

void alloc_player_motion_directory() {
  s32 count;
  s32 entries_size;
  s32 size;
  RlcHeader *directory;
  s32 header_size;
  if (player_motion_directory == NULL)
  {
    count = get_player_motion_max_entries();
    entries_size = get_rlc_directory_entry_size();
    entries_size = entries_size * count;
    header_size = get_rlc_header_size();
    size = header_size + entries_size;
    directory = (RlcHeader *)mem_alloc(size);
    player_motion_directory = directory;
    if (directory != NULL)
    {
      player_motion_directory_size = size;
    }
  }
}

void get_player_motion_entry(s32 index, PlayerMotionAramEntry *entry) {
    RlcDirectoryEntry *dir;
    dir = (RlcDirectoryEntry *)((u8 *)player_motion_directory + player_motion_directory->get_directory_offset());
    dir = dir + index;
    set_slot_offset(entry, player_motion_aram_addr + dir->get_offset());
    set_slot_size(entry, dir->get_size());
}

void read_player_motion(s32 aram_addr, void *dest, s32 size) {
    aram_dma_blocking(2, aram_addr, dest, size);
}
