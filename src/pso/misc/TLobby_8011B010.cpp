#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/memory.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TItemIdCounters.h"
#include "pso/unk/text_8011A780.h"

// FloorItem::FloorItem() on the packet's item record.
extern "C" void *__ct__9FloorItemFv(void *item);

extern "C" {
void *mem_alloc(u32 size);
extern s32 item_sync_counter_table;
extern s32 item_id_counter_table;
extern s32 quest_object_entries;
void mem_free(void *p);

TItemIdCounters::~TItemIdCounters() {
    mem_free((void *)item_sync_counter_table);
    item_sync_counter_table = 0;
    mem_free((void *)item_id_counter_table);
    item_id_counter_table = 0;
}

TItemIdCounters::TItemIdCounters() {
    item_id_counter_table = (s32)mem_alloc(48);
    item_sync_counter_table = (s32)mem_alloc(48);
    TLobby::reset_item_id_counters();
    lbl_805D54E0 = 0;
    build_item_id_mode = 0;
}
void TLobby::send_item_packet() { bswap_item_packet(); send_subcommand((u8 *)this); }
void TLobby::bswap_item_packet() { ((G_ClientIDHeader *)this)->bswap(); ((TLobby *)((char*)this + 0x4))->bswap_item(); }
void *TLobby::init_header_packet() {
    init_header();
    *(s8 *)&this->m_name = 0x5F;
    *(s8 *)((s8 *)this + 0x28) = 2;
    *(s8 *)((s8 *)this + 0x29) = 0;
    *(s8 *)((s8 *)this + 0x2A) = 0;
    *(s8 *)((s8 *)this + 0x2B) = 0;
    *(s8 *)((s8 *)this + 1) = 0xB;
    return this;
}
void *TLobby::init_header() {
    __ct__9FloorItemFv((char *)this + 4);
    *(u8 *)&this->m_name = 95;
    *(u8 *)((s8 *)this + 0x1) = 10;
    return this;
}
void TLobby::bswap_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0x4)); }
s32 TLobby::apply_table_entry(s16 arg0, void * _w1) {
    if (arg0 > 0xB9F) {
        return 0;
    }
    ((TLobby *)(quest_object_entries + (arg0 * 4)))->copy_short_fields(_w1);
    return 1;
}
void TLobby::copy_short_fields(void *arg1) {
    *(s16 *)&this->m_name = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(u16 *)((s8 *)this + 2) = (u16) *(u16 *)((s8 *)arg1 + 2);
}

}
