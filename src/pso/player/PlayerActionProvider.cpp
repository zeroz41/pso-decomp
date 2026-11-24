// PlayerActionProvider, the base of the player action providers: its constructor,
// destructor and key function (get_cell_address), so its table is emitted here.
#include <string.h>
#include "pso/system/RlcArchive.h"
#include "pso/system/ControllerInputState.h"
#include "types.h"
#include "pso/player/PlayerActionProvider.h"
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
#include "pso/item/drop/TItemDrop_800F93F0.h"
#include "pso/quest/TQuestListVM.h"

// This TU's .rodata, .sdata and .sbss: each sits between GamePlayerActionProvider's and
// TWindowSnapShot's sections, padded to an 8-byte unit boundary.
#pragma push
#pragma readonly_strings on
const char *player_motion_data_filename_ptr = "PlyMotionData.rlc";
#pragma pop

int player_action_provider_selector;

extern "C" {
void set_motion_variant(void* p, s32 _w1);
int matches_loaded_motion(void* p);
int match_coordinate_pair(void*);

void set_motion_variant(void* p, s32 _w1) { ((TLobby *)p)->set_field_4(_w1); }
int matches_loaded_motion(void* p) { return match_coordinate_pair(p); }
}

void set_player_action_provider_selector(int selector) { player_action_provider_selector = selector; }
void TLobby::set_field_4(s32 v) { *(s32 *)&this->m_flags = v; }
s32 get_player_action_motion_count() {
    s32 selector;
    selector = get_player_action_provider_selector();
    switch (selector) {
    case 0:
        return 0x38;
    case 1:
        return 0x10;
    default:
        return 0;
    }
}

extern "C" {
s32 PlayerActionProvider::load_motion(s32 set, s32 index, s32 size, s32 aram_addr) {
    s32 result;
    s32 aligned;
    QuestDownloadFile *file;
    s32 dst;
    aligned = (size + 0x1F) & 0xFFFFFFE0;
    file = (QuestDownloadFile *)mem_alloc(aligned);
    if (file == 0) {
        return 0;
    }
    read_player_motion(aram_addr, file, aligned);
    dst = get_cell_address(set, index);
    result = file->decrypt(size, (void *)dst, 0x4000);
    mem_free(file);
    return result;
}

s32 PlayerActionProvider::load_action_motion_pairs(s32 set, s32 id, s32 flags) {
    PlayerMotionAramEntry entry;
    const s32 *slots;
    s32 i;
    s32 size;
    s32 decrypted_size;
    u8 *dst;
    s32 *root;
    if (this->vfunc_4() == 0U) {
        return 0;
    }
    slots = this->vfunc_8(id, flags);
    if (slots == NULL) {
        return 0;
    }
    entry.clear();
    dst = (u8 *)this->get_state_table(id);
    for (i = 0; i < this->vfunc_75(); i++) {
        get_player_motion_entry(*slots, &entry);
        size = entry.get_size();
        decrypted_size = load_motion(set, i, size, entry.get_aram_addr());
        if (decrypted_size != 0) {
            root = (s32 *)relocate_rel_data((void *)this->get_cell_address(set, i), decrypted_size);
        }
        ((PlayerActionProvider *)dst)->copy_motion_pair(*(void **)root);
        slots++;
        dst += 8;
    }
    return 1;
}

void PlayerActionProvider::copy_motion_pair(void*q) { this->unk_0.m_0 = *(u32*)((char*)q + 0x0); this->unk_0.m_4 = *(u32*)((char*)q + 0x4); }

PlayerActionProvider::~PlayerActionProvider() {}

PlayerActionProvider::PlayerActionProvider() {}

s32 PlayerActionProvider::get_cell_address(s32, s32) { return 0; }
int PlayerActionProvider::vfunc_4() { return 0; }
const s32 *PlayerActionProvider::vfunc_8(s32, s32) { return NULL; }
int PlayerActionProvider::vfunc_9(s32, s32, s32) { return 0; }
void PlayerActionProvider::vfunc_14() {  }
int PlayerActionProvider::vfunc_75() { return 0; }
}

s32 PlayerMotionAramEntry::get_aram_addr() { return aram_addr; }
s32 PlayerMotionAramEntry::get_size() { return size; }
void PlayerMotionAramEntry::clear() { aram_addr = 0; size = 0; }

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
    entry->set_aram_addr(player_motion_aram_addr + dir->get_offset());
    entry->set_size(dir->get_size());
}

void read_player_motion(s32 aram_addr, void *dest, s32 size) {
    aram_dma_blocking(2, aram_addr, dest, size);
}
