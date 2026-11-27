#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "types.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TChCrEffCtrlPl.h"
#include "pso/ui/charcreate/TChCrEffWall.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

s32 TChCrLoadAfs::is_load_complete() {
    return load_state == 2;
}

u8 *chr_select_load_buffer_base_table[4];
u8 *chr_select_load_buffer_table[8];
u8 *chr_select_load_buffer_base;
u8 *chr_select_load_buffer;

u8 *TChCrLoadAfs::get_load_buffer() {
    if (is_load_complete() != 0) {
        return buffer_address;
    }
    return 0;
}

uaddr advance_character_load_buffer(s32 slot, s32 size) {
    uaddr p;
    if (chr_select_load_buffer_base == NULL) {
        return 0U;
    }
    check_load_buffer_slot_stub(slot);
    if ((size < 0) || (size > 0xA000)) {
        return 0U;
    }
    size = (size + 0x1F) & ~0x1F;
    if (slot < 4) {
        p = reinterpret_cast<uaddr>(chr_select_load_buffer_base_table[slot]);
        p += size;
        if (p >= reinterpret_cast<uaddr>(chr_select_load_buffer_base) + (slot + 1) * 0xA000) {
            return 0U;
        }
        chr_select_load_buffer_base_table[slot] = reinterpret_cast<u8 *>(p);
        return p;
    }
    {
        s32 j = slot - 4;
        p = reinterpret_cast<uaddr>(chr_select_load_buffer_table[j]);
        p += size;
        if (p >= reinterpret_cast<uaddr>(chr_select_load_buffer) + (j + 1) * 0xA000) {
            return 0U;
        }
        chr_select_load_buffer_table[j] = reinterpret_cast<u8 *>(p);
    }
    return p;
}


void *get_character_load_buffer(s32 slot) { return (void *)advance_character_load_buffer(slot, 0); }

uaddr reset_character_load_buffer(s32 slot) {
    uaddr address;
    s32 extended_slot;
    if (chr_select_load_buffer_base == NULL) {
        return 0U;
    }
    check_load_buffer_slot_stub(slot);
    if (slot < 4) {
        address = reinterpret_cast<uaddr>(chr_select_load_buffer_base) + (u32)slot * 0xA000U;
        chr_select_load_buffer_base_table[slot] = reinterpret_cast<u8 *>(address);
        return address;
    }
    extended_slot = slot - 4;
    address = reinterpret_cast<uaddr>(chr_select_load_buffer) + (u32)extended_slot * 0xA000U;
    chr_select_load_buffer_table[extended_slot] = reinterpret_cast<u8 *>(address);
    return address;
}

void check_load_buffer_slot_stub(s32 i) {
    s32 n = 4;
    if (chr_select_load_buffer_base == 0) return;
    if (chr_select_load_buffer != 0) n = 12;
    if (i < 0) return;
    if (i >= n) return;
}

void TLobby::free_single_player_chr_select() {
    if ((chr_select_load_buffer_base != NULL) && (chr_select_load_buffer != NULL)) {
        safe_free(chr_select_load_buffer);
        chr_select_load_buffer = NULL;
    }
}

void TLobby::alloc_download_server() {
    if ((chr_select_load_buffer_base != NULL) && (chr_select_load_buffer == NULL)) {
        chr_select_load_buffer = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(0x50000));
        if (chr_select_load_buffer == NULL) {
            return;
        }
    }
}

void TLobby::free_chr_select_singleton() {
    if (chr_select_load_buffer_base != NULL) {
        safe_free(chr_select_load_buffer_base);
        chr_select_load_buffer_base = NULL;
    }
}


void alloc_quest_download_buffer(void) {
    if (chr_select_load_buffer_base == 0) {
        if ((chr_select_load_buffer_base = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(0x28000))) == NULL) return;
    }
}

void destroy_character_creation_effects(void) {
    if (character_creation_effects.wall != NULL) {
        character_creation_effects.wall->queue_destruction();
    }
    if (character_creation_effects.heading != NULL) {
        character_creation_effects.heading->queue_destruction();
    }
}

void create_character_creation_effects(void) {
    character_creation_effects.wall = create_TChCrEffWall(tl_03);
    character_creation_effects.heading = create_TChCrEffTag(tl_03);
    character_creation_effects.controller_plate = NULL;
    if (should_show_controller_plate() != 0) {
        character_creation_effects.controller_plate = TChCrEffCtrlPl::create(tl_03);
    }
}
