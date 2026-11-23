#ifndef PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E6970_H
#define PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E6970_H

#include "types.h"

struct QuestDownloadEntryNode;
#include "pso/quest/QuestDownloadText.h"

extern "C" {
void Add_803EB8BC(u8 *key, s32 len);
void CopyText_803E9190(u8 *s, u8 *p);
s32 Copy_803EBD38(u8 *dst, u8 *src, s32 max);
s32 Find_803EB8BC(u8 *key, s32 len);
s32 Hash_803E8B1C(char *s);
s32 Hash_803E8C2C(char *s);
s32 InRange_803ED26C(u8 v);
s32 IsJisPair_803ECAE8(s32 lo, s32 hi);
s32 IsJis_803ECAE8(u8 c);
s32 IsLead_803ECAE8(u32 c);
s32 IsSjisLead_803E90A8(u8 c);
s32 IsSjisLead_803E9190(u8 c);
s32 IsSjisLead_803E92C0(u8 c);
s32 IsSjisLead_803E9348(u8 c);
s32 IsSjis_803ECAE8(s32 lo, s32 hi);
s32 IsSmall_803EEB10(s32 d);
s32 IsTrail_803ECAE8(u8 c);
s32 IsX_803E9FFC(u8 cmd);
s32 Kind_803ECAE8(u16 c, s32 lo);
s32 Open_803E7ACC(void);
s32 Open_803E7B9C(void);
s32 Open_803E8150(void);
s32 Open_803E8624(void);
void Reload_803EB0D8(void);
s32 SeekRetry_803E7ACC(s32 pos);
s32 Seek_803E7ACC(s32 handle, s32 pos, s32 whence);
s32 Seek_803E7B9C(s32 pos);
s32 Seek_803E8150(s32 pos);
s32 Seek_803E8624(s32 handle, s32 pos, s32 whence);
s32 TQuestVmDownLoadServer__sub_803E6970(s32 start, s32 count, u16 *buf, s32 flag);
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
s32 TQuestVmDownLoadServer__sub_803EB0D8(s32 mode, s32 force);
void TQuestVmDownLoadServer__sub_803EC09C(void);
void TQuestVmDownLoadServer__sub_803EC460(s32 pos, s32 x);
s32 TQuestVmDownLoadServer__sub_803EC884(u16 ch);
void TQuestVmDownLoadServer__set_text_run_attr(u16 *run, s32 count, s32 attr);
u16 TQuestVmDownLoadServer__sub_803ED0B4(const QuestDownloadEntryNode *entry, u16 attribute);
s32 TQuestVmDownLoadServer__sub_803EDB20(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB58(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB74(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EED0C(const u8 *input, s32 length, QuestDownloadTextRecord *output);
s32 TQuestVmDownLoadServer__sub_803EED9C(u32 index);
s32 TQuestVmDownLoadServer__sub_803F0048(s32 id, u8 key, u8 sub_key, void *dst);
s32 TQuestVmDownLoadServer__sub_803F0890(void);
s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *quest_vm_down_load_server);
s32 start_askdic(void);
s32 aram_seek(s32 handle, s32 offset, s32 whence);
s32 aram_close(s32 handle);
s32 aram_open(const char *name, s32 mode);
s32 Write_803E7B9C(void);
s32 Write_803E8150(void);
}

// --- C functions defined in TQuestVmDownLoadServer_803E6970.cpp ---
extern "C" {
void Add_803EB8BC(u8 *key, s32 len);
void CopyText_803E9190(u8 *s, u8 *p);
s32 Copy_803EBD38(u8 *dst, u8 *src, s32 max);
s32 Find_803EB8BC(u8 *key, s32 len);
s32 Hash_803E8B1C(char *s);
s32 Hash_803E8C2C(char *s);
s32 InRange_803ED26C(u8 v);
s32 IsJisPair_803ECAE8(s32 lo, s32 hi);
s32 IsJis_803ECAE8(u8 c);
s32 IsLead_803ECAE8(u32 c);
s32 IsSjisLead_803E90A8(u8 c);
s32 IsSjisLead_803E9190(u8 c);
s32 IsSjisLead_803E92C0(u8 c);
s32 IsSjisLead_803E9348(u8 c);
s32 IsSjis_803ECAE8(s32 lo, s32 hi);
s32 IsSmall_803EEB10(s32 d);
s32 IsTrail_803ECAE8(u8 c);
s32 IsX_803E9FFC(u8 cmd);
s32 Kind_803ECAE8(u16 c, s32 lo);
s32 Open_803E7ACC(void);
s32 Open_803E7B9C(void);
s32 Open_803E8150(void);
s32 Open_803E8624(void);
void Reload_803EB0D8(void);
s32 SeekRetry_803E7ACC(s32 pos);
s32 Seek_803E7ACC(s32 handle, s32 pos, s32 whence);
s32 Seek_803E7B9C(s32 pos);
s32 Seek_803E8150(s32 pos);
s32 Seek_803E8624(s32 handle, s32 pos, s32 whence);
s32 TQuestVmDownLoadServer__sub_803E6970(s32 start, s32 count, u16 *buf, s32 flag);
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
s32 TQuestVmDownLoadServer__sub_803EB0D8(s32 mode, s32 force);
void TQuestVmDownLoadServer__sub_803EC09C(void);
void TQuestVmDownLoadServer__sub_803EC460(s32 pos, s32 x);
s32 TQuestVmDownLoadServer__sub_803EC884(u16 ch);
void TQuestVmDownLoadServer__set_text_run_attr(u16 *run, s32 count, s32 attr);
u16 TQuestVmDownLoadServer__sub_803ED0B4(const QuestDownloadEntryNode *entry, u16 attribute);
s32 TQuestVmDownLoadServer__sub_803EDB20(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB58(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EDB74(u8 ch);
s32 TQuestVmDownLoadServer__sub_803EED0C(const u8 *input, s32 length, QuestDownloadTextRecord *output);
s32 TQuestVmDownLoadServer__sub_803EED9C(u32 index);
s32 TQuestVmDownLoadServer__sub_803F0048(s32 id, u8 key, u8 sub_key, void *dst);
s32 TQuestVmDownLoadServer__sub_803F0890(void);
s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *quest_vm_down_load_server);
s32 start_askdic(void);
s32 aram_seek(s32 handle, s32 offset, s32 whence);
s32 aram_close(s32 handle);
s32 aram_open(const char *name, s32 mode);
s32 Write_803E7B9C(void);
s32 Write_803E8150(void);
}
// --- end of C functions

#endif
