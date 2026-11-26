// Character record: TPlyCharData with its inventory and display config, and the
// small record copies the lobby and player code share.
#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyInventory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/player/TPlyCharDataTypes.h"

TPlyCharData::~TPlyCharData() {}

// Built with -inline off: each in-class inline the display config's constructor
// and destructor call comes out right after its first caller (~TPlyDispConfigSmth
// and ~gc_tag after the destructor; TPlyDispConfigSmth(), gc_tag() and gc_tag::init()
// after the constructor).
TPlyDispConfig::~TPlyDispConfig() {}
TPlyDispConfig::TPlyDispConfig() {}

void TLobby::copy_header_struct(void* q) { *(u8 *)&this->m_name = *(u8*)((char*)q + 0x0); *(u8*)((char*)this + 0x1) = *(u8*)((char*)q + 0x1); *(u16*)((char*)this + 0x2) = *(u16*)((char*)q + 0x2); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); }

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


extern "C" {
PlayerVisualRecord *copy_player_visual_record(PlayerVisualRecord *dst, PlayerVisualRecord *src) {
    *dst = *src;
    return dst;
}
}

TPlyCharData::TPlyCharData() { init_inventory_items(); }

void TPlyCharData::init_inventory_items() {
    int i;
    for (i = 0; i < 30; i++) {
        m_inventory.m_items[i].init();
    }
}

void TPlyInventoryItem::init() {
    m_present[0] = 0;
    m_present[1] = -1;
    m_flags = 0;
    m_present[3] = 0;
    m_present[2] = 0;
    m_data.init();
}

PlayerGuildCardTag::PlayerGuildCardTag() {
    tag0 = 0;
    tag1 = 0;
    tag2 = 0;
    guildcard_number = 0;
}
