#ifndef PSO_QUEST_QUESTDOWNLOADSERVER_H
#define PSO_QUEST_QUESTDOWNLOADSERVER_H

// Record types and data shared by the three quest download server TUs (_803E6970, _803E8918, _803E9A24).

#include "types.h"
#include <string.h>
#include "pso/quest/QuestDownloadRecords.h"
#include "pso/quest/QuestDownloadText.h"
#include "pso/quest/QuestDownloadWorkspace.h"
#include "pso/quest/QuestDownloadCacheTypes.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadCharTables.h"

struct QuestSymbolLookupResult {
    s16 page_index;
    s16 record_offset;
    u8 reserved[8];
    u8 *encodedRecord;
};

struct QuestNameLookupResult {
    s16 page_index;
    s16 record_id;
    s16 match_length;
    s16 prefix_length;
    u8 reserved[4];
    u8 *encodedRecord;
};

LAYOUT_ASSERT(QuestSymbolLookupRecordOffset, offsetof(QuestSymbolLookupResult, encodedRecord) == 0xC);
LAYOUT_ASSERT(QuestNameLookupRecordOffset, offsetof(QuestNameLookupResult, encodedRecord) == 0xC);

// Name cache: eight 0x400-byte record pages (lbl_80591EC8), then the hash buckets (lbl_80593EC8)
// and the free-list node pool that __VIRetraceHandler links up.
struct QuestDownloadNameCacheImage {
    u8 pages[8][0x400];
};

extern "C" {
extern u8 lbl_8058DC98[0x50];
extern u8 quest_download_scratch_storage[0x28] ATTRIBUTE_ALIGN(4);
extern u16 quest_download_buffer_storage[0x64] ATTRIBUTE_ALIGN(4);
extern s32 quest_download_state;
extern s32 lbl_805D7848;
extern u8 *lbl_805D78B8;
extern u8 *lbl_805D78BC;
extern s32 quest_text_end;
extern u16 *quest_download_buffer_ptr;
extern u16 *lbl_805D78D0;
extern u16 *quest_download_buffer_start;
extern u16 *quest_vm_download_buffer_end;
extern s32 quest_download_match_length_limit;
extern s32 quest_download_server_state;
// The ARAM backend returns -1 for a closed file.
extern s32 quest_download_file_handle;
extern char quest_vm_download_server_file_info[0x44] ATTRIBUTE_ALIGN(4);
extern saddr lbl_805D78F8;
extern QuestDownloadNameCacheImage lbl_80591EC8;
extern u8 lbl_805D7868;
extern const u8 romaji_kana_char_class_table[0x100];
extern s32 quest_download_initialized;
extern s32 quest_download_state;
extern s32 lbl_805D7908;
extern s32 lbl_805D790C;
extern s32 lbl_805D7888;
extern u8 quest_name_index_table[1024][4] ATTRIBUTE_ALIGN(4);
void __VIRetraceHandler(void);
extern s32 quest_download_free_cell_count;
void TQuestVmDownLoadServer__free_quest_queue_chain(QuestDownloadQueueNode *p);
void TQuestVmDownLoadServer__free_quest_entry_chain(QuestDownloadEntryNode *p);
void TQuestVmDownLoadServer__free_quest_segment_chain(QuestDownloadSegment *p);
extern QuestDownloadFileCache quest_download_slot_table;
QuestDownloadEntryNode *insert_quest_download_entry(QuestDownloadEntryNode *head, QuestDownloadEntryNode *entry);
extern s32 quest_download_name_search_lo;
extern s32 quest_download_name_search_hi;
QuestDownloadItemNode *TQuestVmDownLoadServer__sub_803ECF84(void);
QuestDownloadItemNode *build_item_list__22TQuestVmDownLoadServerFlP12Hdr_803EA384(s32 arg0, Hdr_803EA384 *arg1);
void TQuestVmDownLoadServer__sub_803EADD4(QuestDownloadSlot *slot, s32 mode);
s32 TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(u16 *, const u8 *, int);
s32 write_entry_group_text(s32 start, s32 count, QuestDownloadTextNode *node, u16 *arg3);
s32 store_name_record(char *, QuestDownloadRequest *, s32);
extern s32 lbl_805D7900;
s32 TQuestVmDownLoadServer__sub_803EEF2C(QuestDownloadRequest *req);
void relocate_name_record(s32 id);
void TQuestVmDownLoadServer__sub_803EF8E0(u8 *p);
extern u32 quest_download_aram_size;
extern u8 lbl_80591AC4[0x404];
extern s32 lbl_805D7820;
extern s32 quest_download_ask_header_size;
extern s32 quest_download_header_name_index_hi_count;
extern s32 lbl_805D7874;
extern s32 lbl_805D78FC;
extern s32 quest_page_text_limit;
extern saddr quest_text_entry_len;
s32 TQuestVmDownLoadServer__sub_803EC71C(u16 *, u8 *, s32);
extern u16 lbl_805A0340[];
extern u8 *quest_download_text_write_ptr;
void pack_entry_text_chain(s32 arg0, QuestDownloadTextNode *arg1);
extern u16 lbl_805A02A8[];
extern s32 quest_page_node_index;
extern QuestDownloadTextNode *quest_page_node_head;
extern s32 lbl_805D78E8;
extern saddr quest_text_cursor_pos;
void DCInvalidateRange(void *, u32);
u32 OSGetTick(void);
u32 __OSBusClock AT_ADDRESS(0x800000F8);
void OSReport(const char *, ...);
extern u32 quest_download_aram_timeout;
extern u32 quest_download_aram_priority;
extern u32 quest_download_aram_owner;
extern u32 quest_download_aram_dma_pending;
extern u32 quest_download_aram_base;
void TQuestVmDownLoadServer__sub_803EB4D4(void);
void TQuestVmDownLoadServer__sub_803EC284(s32, s32);
extern s32 quest_page_node_count;
s32 measure_entry_group_len(QuestDownloadTextNode *quest_download_text_node);
void release_node_chain__22TQuestVmDownLoadServerFPv(QuestDownloadItemNode *p);
s32 TQuestVmDownLoadServer__sub_803F03B4(u8 *data, QuestDownloadQueryEntry *entries, s32 n, s32 *max);
s32 TQuestVmDownLoadServer__sub_803F0268(const char *name, s16 len, QuestDownloadQueryResult *out);
s32 TQuestVmDownLoadServer__sub_803E7390(u8 a, u8 b, u8 c);
extern u8 lbl_805D7894[4];
s32 TQuestVmDownLoadServer__sub_803EC884(u16 arg0);
s32 TQuestVmDownLoadServer__sub_803EDB20(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB58(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB74(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EED9C(u32 index);
s32 TQuestVmDownLoadServer__sub_803F06B8(const char *name, s16 len, QuestDownloadQueryResult *out);
void TQuestVmDownLoadServer__set_text_run_attr(u16 *arg0, s32 arg1, s32 arg2);
QuestDownloadSegment *TQuestVmDownLoadServer__sub_803E9A74(s32, s32, u8, u8);
QuestDownloadEntryNode *TQuestVmDownLoadServer__alloc_quest_entry_node(void);
QuestDownloadEntryNode *TQuestVmDownLoadServer__sub_803E9FFC(s32 start, s32 end, const QuestDownloadItemNode *t);
QuestDownloadTextNode *TQuestVmDownLoadServer__alloc_quest_text_node(void);
QuestDownloadSegment *TQuestVmDownLoadServer__alloc_quest_segment(void);
extern QuestDownloadCachePage *file_page_cache_head;
extern QuestDownloadCachedNameIndex lbl_80593EC8;
s32 lookup_name_prefix(char *name, s16 name_len, QuestNameLookupResult *out);
void TQuestVmDownLoadServer__sub_803EFF20(u8 *data, s32 key, s32 sub_key, s32 *best, u8 *dst, s32 flags);
extern const char ask_header_signature[];
void TQuestVmDownLoadServer__sub_803EFCB4(u8 *data, s32 key, s32 sub_key, s32 *cnt, s32 *total, u8 *buf, s32 flags);
extern u8 *lbl_805D7824;

LAYOUT_ASSERT(QuestDownloadScratchSize, sizeof(quest_download_scratch_storage) == 0x28);
LAYOUT_ASSERT(QuestDownloadBufferSize, sizeof(quest_download_buffer_storage) == 0xC8);
void TQuestVmDownLoadServer__sub_803E79AC(void);
void TQuestVmDownLoadServer__sub_803E7F9C(u8 *text, s16 mode);
}

#endif
