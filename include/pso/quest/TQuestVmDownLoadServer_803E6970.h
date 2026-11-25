#ifndef PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E6970_H
#define PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E6970_H

#include "types.h"

struct QuestDownloadEntryNode;
#include "pso/quest/QuestDownloadText.h"

extern "C" {
s32 Hash_803E8B1C(char *s);
s32 Hash_803E8C2C(char *s);
s32 IsSjisLead_803E90A8(u8 c);
s32 IsSjisLead_803E9190(u8 c);
s32 IsSjisLead_803E92C0(u8 c);
s32 IsSjisLead_803E9348(u8 c);
s32 render_input_entries_text(s32 start, s32 count, u16 *buf, s32 flag);
void TQuestVmDownLoadServer__sub_803E6ACC(s32 arg0);
void TQuestVmDownLoadServer__sub_803E6B70(u8 *dst, s32 start, s32 count, s32 mode);
s32 TQuestVmDownLoadServer__sub_803E719C(u8 ch, s32 jis);
u16 TQuestVmDownLoadServer__sub_803E721C(u16 ch);
s32 TQuestVmDownLoadServer__sub_803E779C(u32 id, s32 *file_offset, s32 *cached_id, s32 *value);
s32 TQuestVmDownLoadServer__sub_803E8084(void);
s32 TQuestVmDownLoadServer__sub_803E8150(void);
s32 TQuestVmDownLoadServer__sub_803E86C8(void);
s32 TQuestVmDownLoadServer__sub_803E8788(s32 handle, const void *src, s32 size);
void mark_name_cache_dirty(void);
void save_name_cache(void);
s32 TQuestVmDownLoadServer__sub_803E9F54(s32 arg0);
void TQuestVmDownLoadServer__sub_803EAE84(s32 begin, s32 end, s32 mode);
}
s32 quest_text_prev_page(s32 mode, s32 force);
extern "C" {
void TQuestVmDownLoadServer__sub_803EC09C(void);
void TQuestVmDownLoadServer__sub_803EC460(s32 pos, s32 x);
}
s32 is_jis_kanji_code(u16 ch);
extern "C" {
void set_quest_text_run_attr(u16 *run, s32 count, s32 attr);
}
u16 calc_quest_entry_score(const QuestDownloadEntryNode *entry, u16 attribute);
extern "C" {
s32 TQuestVmDownLoadServer__sub_803EDB20(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB58(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB74(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EED0C(const u8 *input, s32 length, QuestDownloadTextRecord *output);
s32 TQuestVmDownLoadServer__sub_803EED9C(u32 index);
s32 TQuestVmDownLoadServer__sub_803F0048(s32 id, u8 key, u8 sub_key, void *dst);
s32 TQuestVmDownLoadServer__sub_803F0890(void);
s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *quest_vm_down_load_server);
}
s32 start_askdic(void);
extern "C" {
s32 aram_seek(s32 handle, s32 offset, s32 whence);
}
s32 aram_close(s32 handle);
extern "C" {
s32 aram_open(const char *name, s32 mode);
}


#endif
