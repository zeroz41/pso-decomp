#include "types.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/unk/text_801DF280.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/network/protocol/protocol.h"

struct RecoveredFields_801DF394_arg0
{
  s32 field_0;
};

struct RecoveredFields_801DF394_arg1
{
  s32 field_0;
};

struct RecoveredFields_801DF4FC_arg0
{
  s32 field_0;
};

struct RecoveredFields_801DF4FC_arg1
{
  s32 field_0;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Inner_801DF774 { u32 w[5]; };

struct Blk_801DF774 { u32 a; Inner_801DF774 b; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct W4_801DF558 { u32 w[4]; };

struct W8_801DF558 { u32 w[8]; };

struct W12_801DF558 { u32 w[12]; };

struct T3_801DF558 { u32 w[3]; };

struct Entry_801DF558 {
    u32 a;
    W4_801DF558 b;
    W8_801DF558 c;
    W12_801DF558 d;
    T3_801DF558 e;
    u8 ext[0x64];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct W4_801DF61C { s32 v[4]; };

struct Copy_801DF61C { W4_801DF61C a; W4_801DF61C b; };

struct Tag_801DF61C { u8 b[8]; };

struct Obj_801DF61C {
    Tag_801DF61C tags[8];
    s32 w;
    Copy_801DF61C c;
};

extern "C" {
int bswap_32__FPUl(void* a0);
s32 bswap_16__FPUs(s32);
int bswap__13packet_headerFv(void* a0);
Blk_801DF774 *copy_choice_search_parameters(Blk_801DF774 *d, const Blk_801DF774 *s);
int __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void*);
Obj_801DF61C *copy_ply_meet_user_extension(Obj_801DF61C *dst, Obj_801DF61C *src);
s32 __ct__16TPlyGuildCardTagFv(s32);
int bswap_32__FPUl(void* a0 = 0);

void bswap_cmd_db_regist_connect_reply(packet_header *arg0) {
    arg0->bswap();
    bswap_ply_smth_pair(((void *)((char *)arg0 + 68)));
    bswap_32__FPUl((void*)((void *)((char *)arg0 + 76)));
}

s32 construct_cmd_db_regist_connect_reply(s32 arg0) {
    __ct__8TPlySmthFv((void *)(arg0 + 0x44));
    return arg0;
}
}
int bswap_cmd_8a_header(void* p) { return bswap__13packet_headerFv(p); }
void bswap_cmd_88_body(void* p) { ((packet_header *)p)->bswap(); { int i; for (i = 0; i < 16; i++) { bswap_cmd_88_marker_record((void*)((char*)p + 0x4 + i * 12)); } } }

void bswap_cmd_88_marker_record(void* p) { ((TPlyGuildCardTag *)p)->bswap(); bswap_32__FPUl((char*)p + 0x8); }

typedef struct RecoveredFields_801DF394_arg0 RecoveredFields_801DF394_arg0;
typedef struct RecoveredFields_801DF394_arg1 RecoveredFields_801DF394_arg1;

s32 *copy_entry_table(s32 *arg0, s32 *arg1) {
  u32 var_r30;
  s32 var_r29;
  var_r30 = (unsigned long) (((u8 *) arg0) + 4);
  var_r29 = (long) (((u8 *) arg1) + 4);
  ((RecoveredFields_801DF394_arg0 *) arg0)->field_0 = ((RecoveredFields_801DF394_arg1 *) arg1)->field_0;
  do
  {
    copy_cmd_88_marker_record((void*)((int) var_r30), (void*)((int) var_r29));
    var_r30 += 0xC;
    var_r29 += 0xC;
  }
  while (var_r30 < ((u32) (((u8 *) arg0) + 0xC4)));
  return arg0;
}

void* copy_cmd_88_marker_record(void* p, void* a1) { __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(p); *(void**)((char*)p + 0x8) = *(void**)((char*)a1 + 0x8); return p; }
void bswap_cmd_c4_body(void* p) { ((packet_header *)p)->bswap(); { int i; for (i = 0; i < 32; i++) { bswap_cmd_c4_entry((void *)((char*)p + 0x4 + i * 212)); } } }

void bswap_cmd_c4_entry(void *arg0) {
    bswap_32__FPUl(arg0);
    bswap_cmd_c4_reconnect_command((s32)((s32)((void *)((char *)arg0 + 100))));
    bswap__21TPlyMeetUserExtensionFv((s32)((char *)arg0 + 112));
}

void bswap_cmd_c4_reconnect_command(s32 arg0) {
    ((s32)bswap__13packet_headerFv((void*)arg0));
    ((s32)bswap_32__FPUl((void*)(arg0 + 4)));
    bswap_16__FPUs(arg0 + 8);
    bswap_16__FPUs(arg0 + 0xA);
}

typedef struct RecoveredFields_801DF4FC_arg0 RecoveredFields_801DF4FC_arg0;
typedef struct RecoveredFields_801DF4FC_arg1 RecoveredFields_801DF4FC_arg1;
s32 *copy_cmd_c4_entry_table(s32 *arg0, s32 *arg1) {
  u32 var_r30;
  s32 var_r29;
  var_r30 = (unsigned long) (((u8 *) arg0) + 4);
  var_r29 = (long) (((u8 *) arg1) + 4);
  ((RecoveredFields_801DF4FC_arg0 *) arg0)->field_0 = ((RecoveredFields_801DF4FC_arg1 *) arg1)->field_0;
  do
  {
    copy_cmd_c4_entry((int)((int)((int) var_r30)), (int)((int)((int) var_r29)));
    var_r30 += 0xD4;
    var_r29 += 0xD4;
  }
  while (var_r30 < ((u32) (((u8 *) arg0) + 0x1A84)));
  return arg0;
}

struct Obj_801DF61C;
int copy_cmd_c4_entry(int arg0, int arg1) {
    Entry_801DF558 *d = (Entry_801DF558 *)arg0;
    Entry_801DF558 *s = (Entry_801DF558 *)arg1;
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    d->e = s->e;
    copy_ply_meet_user_extension((Obj_801DF61C *)((Obj_801DF61C *)((Obj_801DF61C *)d->ext)), (Obj_801DF61C *)((Obj_801DF61C *)((Obj_801DF61C *)s->ext)));
    return arg0;
}

Obj_801DF61C *copy_ply_meet_user_extension(Obj_801DF61C *dst, Obj_801DF61C *src) {
    Tag_801DF61C *d = dst->tags;
    Tag_801DF61C *s = src->tags;
    do {
        ((int (*)(void *, void *))__ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag)(d, s);
        d++;
        s++;
    } while (d < dst->tags + 8);
    dst->w = src->w;
    dst->c.a = src->c.a;
    dst->c.b = src->c.b;
    return dst;
}

void bswap_choice_search_packet(void* p) { ((packet_header *)p)->bswap(); bswap_choice_search_config((char*)p + 0x4); }
void bswap_choice_search_config(void* p) { bswap_32__FPUl(p); { int i; for (i = 0; i < 5; i++) { bswap_u16_pair_field((void*)((char*)p + 0x4 + i * 4)); } } }

void bswap_u16_pair_field(void* p) { bswap_16__FPUs((s32)p); bswap_16__FPUs((s32)((void*)((char*)p + 0x2))); }

Blk_801DF774 *copy_choice_search_parameters(Blk_801DF774 *d, const Blk_801DF774 *s) {
    d->a = s->a;
    d->b = s->b;
    return d;
}

void bswap_c0_lobby_entries(void* p) { ((packet_header *)p)->bswap(); { int i; for (i = 0; i < 56; i++) { bswap_c0_choice_search_entry((void*)((char*)p + 0x4 + i * 32)); } } }

void bswap_c0_choice_search_entry(void* p) { bswap_u16_pair_field(p); }

int bswap_packet_header_cmd_b1(void* p) { return bswap__13packet_headerFv(p); }

void bswap_save_packet(s32 arg0) {
    ((s32)bswap__13packet_headerFv((void*)arg0));
    ((s32)bswap_32__FPUl((void*)(arg0 + 4)));
    ((s32)bswap_32__FPUl((void*)(arg0 + 8)));
}

void bswap_change_ship_block_packet(void* p) { ((packet_header *)p)->bswap(); ((TPlyGuildCardTag *)((char*)p + 0x4))->bswap(); }

s32 construct_change_ship_block_packet(s32 arg0) {
    __ct__16TPlyGuildCardTagFv(arg0 + 4);
    return arg0;
}
