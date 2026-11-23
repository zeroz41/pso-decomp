#include "types.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/unk/text_801DF280.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/TProtocol.h"

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
int __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void*);
Obj_801DF61C *copy_ply_meet_user_extension(Obj_801DF61C *dst, Obj_801DF61C *src);
s32 __ct__16TPlyGuildCardTagFv(s32);
}

void TSendVerifyLicense::bswap() {
    header.bswap();
    bswap_ply_smth_pair(&hardware_id);
    bswap_32(&sub_version);
}

TSendVerifyLicense::TSendVerifyLicense() {}
void bswap_cmd_8a_header(void *p) { ((packet_header *)p)->bswap(); }
void bswap_cmd_88_body(void* p) { ((packet_header *)p)->bswap(); { int i; for (i = 0; i < 16; i++) { bswap_cmd_88_marker_record((void*)((char*)p + 0x4 + i * 12)); } } }

void bswap_cmd_88_marker_record(void* p) { ((TPlyGuildCardTag *)p)->bswap(); bswap_32((u32 *)((char*)p + 0x8)); }

typedef struct RecoveredFields_801DF394_arg0 RecoveredFields_801DF394_arg0;
typedef struct RecoveredFields_801DF394_arg1 RecoveredFields_801DF394_arg1;

s32 *copy_entry_table(s32 *arg0, s32 *arg1) {
  uaddr var_r30;
  saddr var_r29;
  var_r30 = (uaddr) (((u8 *) arg0) + 4);
  var_r29 = (saddr) (((u8 *) arg1) + 4);
  ((RecoveredFields_801DF394_arg0 *) arg0)->field_0 = ((RecoveredFields_801DF394_arg1 *) arg1)->field_0;
  do
  {
    copy_cmd_88_marker_record((void*)var_r30, (void*)var_r29);
    var_r30 += 0xC;
    var_r29 += 0xC;
  }
  while (var_r30 < ((uaddr) (((u8 *) arg0) + 0xC4)));
  return arg0;
}

void* copy_cmd_88_marker_record(void* p, void* a1) { __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(p); *(void**)((char*)p + 0x8) = *(void**)((char*)a1 + 0x8); return p; }
void bswap_cmd_c4_body(void* p) { ((packet_header *)p)->bswap(); { int i; for (i = 0; i < 32; i++) { bswap_cmd_c4_entry((void *)((char*)p + 0x4 + i * 212)); } } }

void bswap_cmd_c4_entry(void *arg0) {
    bswap_32((u32 *)arg0);
    bswap_cmd_c4_reconnect_command((saddr)((void *)((char *)arg0 + 100)));
    ((TPlyMeetUserExtension *)((char *)arg0 + 112))->bswap();
}

void bswap_cmd_c4_reconnect_command(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    ((s32)bswap_32__FPUl((void*)(arg0 + 4)));
    bswap_16__FPUs(arg0 + 8);
    bswap_16__FPUs(arg0 + 0xA);
}

typedef struct RecoveredFields_801DF4FC_arg0 RecoveredFields_801DF4FC_arg0;
typedef struct RecoveredFields_801DF4FC_arg1 RecoveredFields_801DF4FC_arg1;
s32 *copy_cmd_c4_entry_table(s32 *arg0, s32 *arg1) {
  u8 *dst;
  u8 *src;
  dst = (u8 *)arg0 + 4;
  src = (u8 *)arg1 + 4;
  ((RecoveredFields_801DF4FC_arg0 *) arg0)->field_0 = ((RecoveredFields_801DF4FC_arg1 *) arg1)->field_0;
  do
  {
    copy_cmd_c4_entry(dst, src);
    dst += 0xD4;
    src += 0xD4;
  }
  while (dst < (u8 *)arg0 + 0x1A84);
  return arg0;
}

struct Obj_801DF61C;
void *copy_cmd_c4_entry(void *dst, void *src) {
    Entry_801DF558 *d = (Entry_801DF558 *)dst;
    Entry_801DF558 *s = (Entry_801DF558 *)src;
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    d->e = s->e;
    copy_ply_meet_user_extension((Obj_801DF61C *)d->ext, (Obj_801DF61C *)s->ext);
    return dst;
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

void ChoiceSearchPacket::bswap() {
    header.bswap();
    parameters.bswap();
}
void TPlyChoiceSearchConfig::bswap() {
    bswap_32(&disabled);
    for (int i = 0; i < 5; i++) {
        bswap_u16_pair_field(&entries[i]);
    }
}

void bswap_u16_pair_field(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((void*)((char*)p + 0x2))); }

TPlyChoiceSearchConfig *copy_choice_search_parameters(TPlyChoiceSearchConfig *dst, const TPlyChoiceSearchConfig *src) {
    *dst = *src;
    return dst;
}

void bswap_c0_lobby_entries(void* p) { ((packet_header *)p)->bswap(); { int i; for (i = 0; i < 56; i++) { bswap_c0_choice_search_entry((void*)((char*)p + 0x4 + i * 32)); } } }

void bswap_c0_choice_search_entry(void* p) { bswap_u16_pair_field(p); }

void bswap_packet_header_cmd_b1(void *p) { ((packet_header *)p)->bswap(); }

void bswap_save_packet(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    ((s32)bswap_32__FPUl((void*)(arg0 + 4)));
    ((s32)bswap_32__FPUl((void*)(arg0 + 8)));
}

void bswap_change_ship_block_packet(void* p) { ((packet_header *)p)->bswap(); ((TPlyGuildCardTag *)((char*)p + 0x4))->bswap(); }

s32 construct_change_ship_block_packet(s32 arg0) {
    __ct__16TPlyGuildCardTagFv(arg0 + 4);
    return arg0;
}
