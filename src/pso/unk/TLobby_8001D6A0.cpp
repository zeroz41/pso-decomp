#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_803DE864.h"
#include "pso/system/date.h"
#include "pso/system/byteswap.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_800FBD74.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

void* get_player_entry__6TLobbyFii(int a0, int a1);
void* TLobby__sub_8001E270(int a0, int a1);
void* TLobby__sub_8001E2A8(int a0, int a1);
void* get_entry__6TLobbyFii(int a0, int a1);

struct Ent_8001D768 { u32 f0; u32 f4; u32 f8; u32 fc; };

struct Obj_8001D768 { Ent_8001D768 *ents; u32 count; };

struct Node_8001D7AC { Node_8001D7AC *next; Node_8001D7AC *prev; u32 addr; u32 size; };

struct Pool_8001D7AC { u8 pad[0x2C]; Node_8001D7AC *head; };

struct Node_8001D808 { Node_8001D808 *next; Node_8001D808 *prev; u32 addr; u32 size; };

struct Pool_8001D808 { u8 pad[0x2C]; Node_8001D808 *head; };

struct Node_8001D6E0 { Node_8001D6E0 *next; Node_8001D6E0 *prev; u32 addr; u32 size; };

struct Pool_8001D6E0 { u8 pad[0x2C]; Node_8001D6E0 *head; };

extern "C" {
extern s32 aram_dma_pending;

s32 strncpy(int, int, int);
extern s32 auto_reply_flags;
Ent_8001D768 *find_free_pool_entry__6TLobbyFPv(Obj_8001D768 *self);
void archive_pool_free(Pool_8001D7AC *pool, Node_8001D7AC *node);
Node_8001D808 *archive_pool_alloc(Pool_8001D808 *pool, u32 size);

void send_disable_auto_reply__9TProtocolFv(s32);
extern s32 TLobby__protocol_instance;

s32 aram_read_sync__6TLobbyFllll(s32, s32);
s32 aram_transfer_sync__6TLobbyFlUlll(s32, void *, s32);

void TLobby::send_or_handle_packet(void *arg0, void *arg1, void *arg2, void *arg3, u32 arg4) {
    if (arg4 == 0U) {
        aram_transfer_sync__6TLobbyFlUlll(0, arg1, *(s32 *)((s8 *)arg2 + 8));
        return;
    }
    aram_read_sync__6TLobbyFllll(0, *(s32 *)((s8 *)arg1 + 8));
}

void TLobby::merge_adjacent_free_blocks() {
    Pool_8001D6E0 *pool = (Pool_8001D6E0 *)this;
    Node_8001D6E0 *cur;
    Node_8001D6E0 *n;
    cur = pool->head->next;
    while ((n = cur->next) != 0) {
        if (n->addr == cur->addr + cur->size) {
            cur->next = n->next;
            cur->size = cur->size + n->size;
            if (n->next != 0) {
                n->next->prev = cur;
            }
            TLobby__sub_8001D9E8(n);
        } else {
            cur = n;
        }
    }
}

Ent_8001D768 *find_free_pool_entry__6TLobbyFPv(Obj_8001D768 *self) {
    u32 i;
    if (self->ents != 0) {
        for (i = 1; i < self->count; i++) {
            if (self->ents[i].fc == 0) {
                return &self->ents[i];
            }
        }
    }
    return 0;
}

void archive_pool_free(Pool_8001D7AC *pool, Node_8001D7AC *node) {
    Node_8001D7AC *prev;
    Node_8001D7AC *cur;
    for (prev = pool->head; (cur = prev->next) != 0; prev = cur) {
        if (node->addr < cur->addr) {
            prev->next = node;
            node->next = cur;
            node->prev = prev;
            cur->prev = node;
            ((TLobby *)pool)->merge_adjacent_free_blocks();
            return;
        }
    }
}

struct Ent_8001D768;
struct Obj_8001D768;
Node_8001D808 *archive_pool_alloc(Pool_8001D808 *pool, u32 size) {
    u32 sz = (size + 0x1F) & ~0x1F;
    Node_8001D808 *prev;
    Node_8001D808 *cur;
    Node_8001D808 *n;
    for (prev = pool->head; (cur = prev->next) != 0; prev = cur) {
        if (cur->size >= sz) {
            if (cur->size == sz) {
                prev->next = cur->next;
                if (cur->next != 0) {
                    cur->next->prev = prev;
                }
                cur->next = 0;
                cur->prev = 0;
                return cur;
            }
            if (cur->size > sz) {
                n = (Node_8001D808 *)find_free_pool_entry__6TLobbyFPv((Obj_8001D768 *)pool);
                if (n != 0) {
                    n->next = 0;
                    n->prev = 0;
                    n->addr = cur->addr;
                    n->size = sz;
                    cur->addr += sz;
                    cur->size -= sz;
                    return n;
                }
            }
        }
    }
    return 0;
}

u32 *free_and_delete__6TLobbyFPvs(u32 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if ((u32) *arg0 != 0U) {
            xfree((void *)(*arg0));
            *arg0 = 0U;
        }
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TLobby::init_memory_pool(s32 arg1, s32 arg2, s32 arg3) {
    s32 prev;
    u8 *temp_r3;
    u8 *temp_r5;

    *(void * *)&this->m_name = fn_803DE864(arg3, 0x10);
    if ((void *) *(void * *)&this->m_name != NULL) {
        *(s32 *)&this->m_flags = arg3;
        prev = (arg2 + 0x1F) & 0xFFFFFFE0;
        *(s32 *)&this->m_prev = prev;
        temp_r3 = (unsigned char *) (*(void * *)&this->m_name);
        *(void **)((s8 *)((u8 *)this) + 0x2C) = temp_r3;
        temp_r5 = temp_r3 + 0x10;
        *(void **)((s8 *)(*(void **)((s8 *)((u8 *)this) + 0x2C)) + 0) = temp_r5;
        *(s32 *)((s8 *)(*(void **)((s8 *)((u8 *)this) + 0x2C)) + 4) = 0;
        *(s32 *)((s8 *)(*(void **)((s8 *)((u8 *)this) + 0x2C)) + 8) = 0;
        *(s32 *)((s8 *)(*(void **)((s8 *)((u8 *)this) + 0x2C)) + 0xC) = 0;
        *(s32 *)((s8 *)temp_r5 + 0) = 0;
        *(void **)((s8 *)temp_r5 + 4) = (void *) *(void * *)&this->m_name;
        *(s32 *)((s8 *)temp_r5 + 8) = arg1;
        *(s32 *)((s8 *)temp_r5 + 0xC) = prev;
    }
    return ((u8 *)this);
}

void TLobby__sub_8001D9DC(void) {
    aram_dma_pending = 0;
}

void TLobby__sub_8001D9E8(void* p) { *(s32*)((char*)p + 0x4) = 0; *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0xc) = 0; *(s32*)((char*)p + 0x8) = 0; }

void TLobby::sync_auto_reply_state() {
    if ((auto_reply_flags & 4) || (auto_reply_flags & 1) != ((auto_reply_flags >> 1) & 1)) {
        if (((s32 (*)(void))get_flag_bit0__6TLobbyFv)() != 0) {
            ((TLobby *)TLobby__protocol_instance)->send_text_packet_c7((char *)(get_card_window_area__6TLobbyFv()));
        } else {
            send_disable_auto_reply__9TProtocolFv(TLobby__protocol_instance);
        }
        auto_reply_flags &= ~4;
        auto_reply_flags = ((s32 (*)(void))get_flag_bit0__6TLobbyFv)() != 0 ? (auto_reply_flags | 2) : (auto_reply_flags & ~2);
    }
}

s32 get_card_window_area__6TLobbyFv(void) {
    return get_character_save_record(0xFFFF) + 0x2050;
}
void TLobby::set_short_mail_text() {
    s32 arg0 = (s32)this;
    u8 *temp_r31;
    temp_r31 = (u8 *)(get_character_save_record((0xFFFFU)) + 0x2050);
    TWindowSubComCard::mask_profanity_words((char *)arg0, (char *)get_shared_text_buffer());
    strncpy((int)temp_r31, (int) (((s32 (*)(void))get_shared_text_buffer)()), 0xAB);
    *(s8 *)((s8 *)temp_r31 + 0xAB) = 0;
    auto_reply_flags |= 4;
    if (TLobby::is_active() != 0) {
        TLobby::set_flag_bit0(1);
        return;
    }
    TLobby::set_flag_bit0(0);
}

int get_flag_bit0__6TLobbyFv(void) {  return (auto_reply_flags & 0x1); }

s32 TLobby::set_flag_bit0(s32 arg0) {
    s32 var_r3;
    s32 ret;

    ret = ((s32 (*)(s32))get_flag_bit0__6TLobbyFv)(arg0);
    if (ret == arg0) {
        return 0;
    }
    var_r3 = auto_reply_flags & 0xFFFFFFFE;
    if (arg0 != 0) {
        var_r3 = auto_reply_flags | 1;
    }
    auto_reply_flags = var_r3;
    return 1;
}

}

struct RecoveredGlobal_8001DC24_lbl_80515BC8 {
    s32 value;
    u8 remaining[0xFC];
};

extern RecoveredGlobal_8001DC24_lbl_80515BC8 text_builder_buffer;
extern "C" {

s32 TLobby::is_active() {
    return *((s8* (*)(void))get_card_window_area__6TLobbyFv)() == 0 ? 0 : 1;
}

void TLobby__sub_8001DBD8(s32 _w0) {
    auto_reply_flags = 0;
}

void TLobby::forward_8001DBD8(void* p) { TLobby__sub_8001DBD8((s32)p); }
void TLobby__sub_8001DC04(void* p) { TLobby__sub_8001DBD8((s32)p); }

    extern int TLobby__lobby_instance;

typedef char RecoveredGlobal_8001DC24_lbl_80515BC8_size[sizeof(RecoveredGlobal_8001DC24_lbl_80515BC8) == 0x100 ? 1 : -1];
s32 *get_shared_text_buffer(void) {
    return &text_builder_buffer.value;
}

typedef struct File_8001DC30 File_8001DC30;
typedef struct Pair_8001DC30 Pair_8001DC30;
typedef struct Params_8001DC30 Params_8001DC30;
typedef struct Pkt_8001DC30 Pkt_8001DC30;
typedef struct Stats_8001DC30 Stats_8001DC30;
typedef struct Sw_8001DC30 Sw_8001DC30;
struct Stats_8001DC30
{
  u8 b[0x24];
};
struct Pkt_8001DC30
{
  u8 b[0x30];
};
struct Sw_8001DC30
{
  u8 b[0x20];
};
struct Pair_8001DC30
{
  u32 a[6];
  u32 b[6];
};
struct Params_8001DC30
{
  Stats_8001DC30 stats[0x60];
  Pkt_8001DC30 pkts[0x60];
  Sw_8001DC30 sw[0x60];
  Pair_8001DC30 pairs[0x60];
};
struct File_8001DC30
{
  Stats_8001DC30 stats[4][0x60];
  Pkt_8001DC30 pkts[4][0x60];
  Sw_8001DC30 sw[4][0x60];
  Pair_8001DC30 pairs[4][0x60];
};
s32 is_main_phase_15__9TObjEneDDFv(void);
void read_disc_file(const char *, void *);
void mem_free(void *);
void *mem_alloc(u32 size);
}
extern const char lbl_80434A20[];
extern const char lbl_80434A38[];
extern const char lbl_80434A50[];
extern const char lbl_80434A6C[];
extern s32 battle_param_lab_variant;
void load_battle_param_entry(void) {
  extern Params_8001DC30 *TLobby__battle_parameter_buffer;
  extern s32 battle_parameter_difficulty;
  s32 idx;
  const char *name;
  File_8001DC30 *file;
  Params_8001DC30 *dst;
  Params_8001DC30 *new_var;
  s32 off;
  name = lbl_80434A20;
  if (is_main_phase_15__9TObjEneDDFv() != 0)
  {
    name = lbl_80434A38;
  }
  if (TRaderMapCore::is_not_split_screen() == 1)
  {
    name = lbl_80434A38;
  }
  if (battle_param_lab_variant == 1)
  {
    name = lbl_80434A50;
    if (is_main_phase_15__9TObjEneDDFv() != 0)
    {
      name = lbl_80434A6C;
    }
    if (TRaderMapCore::is_not_split_screen() == 1)
    {
      name = lbl_80434A6C;
    }
  }
  file = (File_8001DC30 *) mem_alloc(0xF600);
  if (file != 0)
  {
    read_disc_file(name, file);
    idx = battle_parameter_difficulty;
    new_var = (dst = TLobby__battle_parameter_buffer);
    ((TLobby *)(dst->stats))->move_data(file->stats[idx], sizeof(dst->stats));
    {
      Stats_8001DC30 *p = ((0, dst))->stats;
      s32 i;
      for (i = 0; i < 0x60; i++)
      {
        bswap__12player_statsFv(p);
        p++;
      }

    }
    ((TLobby *)(new_var->pkts))->move_data((void *) ((((s32) file) + 0x3600) + (idx * 0x1200)), sizeof(dst->pkts));
    {
      Pkt_8001DC30 *p = new_var->pkts;
      s32 i;
      for (i = 0; i < 0x60; i++)
      {
        ((TLobby *)p)->byteswap_packet();
        p++;
      }

    }
    ((TLobby *)(new_var->sw))->move_data((void *) ((((s32) file) + 0x7E00) + (idx * 0xC00)), sizeof(dst->sw));
    {
      s32 i;
      Sw_8001DC30 *p = new_var->sw;
      for (i = 0; i < 0x60; i++)
      {
        ((TLobby *)p)->swap_endian();
        p++;
      }

    }
    ((TLobby *)(new_var->pairs))->move_data((void *) ((((s32) file) + 0xAE00) + (1152 * (4 * idx))), sizeof(dst->pairs));
    {
      s32 i;
      Pair_8001DC30 *p = new_var->pairs;
      for (i = 0; i < 0x60; i++)
      {
        s32 j;
        for (j = 0; j < 6; j++)
        {
          bswap_32(&p->a[j]);
          bswap_32(&p->b[j]);
        }

        p++;
      }

    }
    mem_free(file);
 ;
  }
}

void TLobby::broadcast(void* a0) { ((int (*)(void*, void*))broadcast_to_players__6TLobbyFii)((void*)TLobby__lobby_instance, a0); }

void TLobby__sub_8001DE30(void* a0) { ((int (*)(void*, void*))TLobby__sub_8001DF58)((void*)TLobby__lobby_instance, a0); }

void TLobby::copy_all_entries(void* a0) { ((int (*)(void*, void*))copy_all_entries__6TLobbyFii)((void*)TLobby__lobby_instance, a0); }

void TLobby::copy_data(void* a0) { ((int (*)(void*, void*))copy_all_data__6TLobbyFii)((void*)TLobby__lobby_instance, a0); }

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Blk_8001DF0C { s32 w[6]; };

struct Obj_8001DF0C { Blk_8001DF0C a; Blk_8001DF0C b; };

extern "C" {
Obj_8001DF0C *copy_pair__6TLobbyFPvPv(Obj_8001DF0C *d, Obj_8001DF0C *s);

void TLobby__sub_8001DEA8(s32 arg0) {
    TLobby__lobby_instance = arg0;
}

void broadcast_to_players__6TLobbyFii(s32 arg0, s32 arg1) {
    s32 var_r31;

    if (((s32 (*)(void))is_valid_player_index__6TLobbyFi)() != 0) {
        var_r31 = 0;
        do {
            copy_pair__6TLobbyFPvPv((Obj_8001DF0C *)(((s32 (*)(s32, s32))get_player_entry__6TLobbyFii)(var_r31, arg0)), (Obj_8001DF0C *)(arg1));
            var_r31 += 1;
        } while (var_r31 < 4);
    }
}
Obj_8001DF0C *copy_pair__6TLobbyFPvPv(Obj_8001DF0C *d, Obj_8001DF0C *s) {
    d->a = s->a;
    d->b = s->b;
    return d;
}

void TLobby__sub_8001DF58(s32 arg0, s32 ent) {
    s32 var_r31;

    if (((s32 (*)(void))is_valid_player_index__6TLobbyFi)() != 0) {
        var_r31 = 0;
        do {
            ((TLobby *)(((s32 (*)(s32, s32))get_entry__6TLobbyFii)(var_r31, arg0)))->copy_entry((void *)ent);
            var_r31 += 1;
        } while (var_r31 < 4);
    }
}

void TLobby::copy_entry(void *arg1) {
    *(s16 *)&this->m_name = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)this + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)&this->m_prev = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)this + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(s32 *)&this->m_next = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    *(s32 *)&this->m_up = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)&this->m_down = (s32) *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)this + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    *(s32 *)((s8 *)this + 0x1C) = (s32) *(s32 *)((s8 *)arg1 + 0x1C);
}

void copy_all_entries__6TLobbyFii(s32 arg0, s32 arg1) {
    s32 var_r31;

    if (((s32 (*)(void))is_valid_player_index__6TLobbyFi)() != 0) {
        var_r31 = 0;
        do {
            ((TLobby *)(((s32 (*)(s32, s32))TLobby__sub_8001E270)(var_r31, arg0)))->copy_from((void *)arg1);
            var_r31 += 1;
        } while (var_r31 < 4);
    }
}

void TLobby::copy_from(void *arg1) {
    *(s16 *)&this->m_name = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)this + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(f32 *)&this->m_prev = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(s32 *)&this->m_next = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    *(f32 *)&this->m_up = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    *(s16 *)&this->m_down = (s16) *(s16 *)((s8 *)arg1 + 0x14);
    *(s16 *)((s8 *)this + 0x16) = (s16) *(s16 *)((s8 *)arg1 + 0x16);
    *(s16 *)((s8 *)this + 0x18) = (s16) *(s16 *)((s8 *)arg1 + 0x18);
    *(s16 *)((s8 *)this + 0x1A) = (s16) *(s16 *)((s8 *)arg1 + 0x1A);
    *(s32 *)((s8 *)this + 0x1C) = (s32) *(s32 *)((s8 *)arg1 + 0x1C);
    *(s32 *)((s8 *)this + 0x20) = (s32) *(s32 *)((s8 *)arg1 + 0x20);
    *(s32 *)((s8 *)this + 0x24) = (s32) *(s32 *)((s8 *)arg1 + 0x24);
    *(s32 *)((s8 *)this + 0x28) = (s32) *(s32 *)((s8 *)arg1 + 0x28);
    *(s32 *)((s8 *)this + 0x2C) = (s32) *(s32 *)((s8 *)arg1 + 0x2C);
}

void copy_all_data__6TLobbyFii(s32 arg0, s32 arg1) {
    s32 var_r31;

    if (((s32 (*)(void))is_valid_player_index__6TLobbyFi)() != 0) {
        var_r31 = 0;
        do {
            copy_data__6TLobbyFPvPv((void *)(((s32 (*)(s32, s32))TLobby__sub_8001E2A8)(var_r31, arg0)), (void *)arg1);
            var_r31 += 1;
        } while (var_r31 < 4);
    }
}

void copy_data__6TLobbyFPvPv(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(s16 *)((s8 *)arg0 + 0xC) = (s16) *(s16 *)((s8 *)arg1 + 0xC);
    *(s16 *)((s8 *)arg0 + 0xE) = (s16) *(s16 *)((s8 *)arg1 + 0xE);
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    *(f32 *)((s8 *)arg0 + 0x14) = (f32) *(f32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg1 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg1 + 0x20);
}

u8 is_valid_player_index__6TLobbyFi(s32 arg0) {
    s32 var_r0;

    var_r0 = 0;
    if ((arg0 >= 0) && (arg0 < 0x60)) {
        var_r0 = 1;
    }
    return (u8)var_r0;
}

    extern int battle_parameter_difficulty;
void*TLobby::dispatch_shared_handler_a(s32 index) { return get_player_entry__6TLobbyFii(battle_parameter_difficulty, index); }

    extern int battle_param_movement;
void* get_player_entry__6TLobbyFii(int a0, int a1) {  return (char*)(battle_param_movement) + a1 * 48; }

void*TLobby::register_object(s32 index) { return get_entry__6TLobbyFii(battle_parameter_difficulty, index); }

    extern int TLobby__battle_param_resistances;
void* get_entry__6TLobbyFii(int a0, int a1) {  return (char*)(TLobby__battle_param_resistances) + a1 * 32; }

void*TLobby::dispatch_shared_handler_b(s32 index) { return TLobby__sub_8001E270(battle_parameter_difficulty, index); }

    extern int TLobby__battle_param_attacks;
void* TLobby__sub_8001E270(int a0, int a1) {  return (char*)(TLobby__battle_param_attacks) + a1 * 48; }

void*TLobby::register_boss(s32 index) { return TLobby__sub_8001E2A8(battle_parameter_difficulty, index); }

    extern int battle_param_stats;
void* TLobby__sub_8001E2A8(int a0, int a1) {  return (char*)(battle_param_stats) + a1 * 36; }

void set_difficulty__6TLobbyFi(s32 arg0) {
    battle_param_lab_variant = arg0;
}

extern u32 TLobby__battle_parameter_buffer;

extern s32 game_difficulty_selection;
void mem_free(void*);

extern s32 enable_v2_features;

void TLobby::clamp_difficulty(s32 arg0) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 < 0) {
        var_r3 = 0;
    } else if ((s32) enable_v2_features != 0) {
        if (var_r3 >= 4) {
            var_r3 = 3;
        }
    } else if (var_r3 >= 3) {
        var_r3 = 2;
    }
    battle_parameter_difficulty = var_r3;
}

void TLobby::update_difficulty() {
    s32 temp_r31;
    s32 temp_r30;

    temp_r31 = battle_parameter_difficulty;
    temp_r30 = battle_param_lab_variant;
    TLobby::clamp_difficulty(game_difficulty_selection);
    TLobby::get_instance();
    ((s32 (*)(void))set_difficulty__6TLobbyFi)();
    if (((s32) battle_parameter_difficulty != temp_r31) || ((s32) battle_param_lab_variant != temp_r30)) {
        load_battle_param_entry();
    }
}

void TLobby::free_boss4_rock() {
    if ((u32) TLobby__battle_parameter_buffer != 0U) {
        mem_free((void*)TLobby__battle_parameter_buffer);
        TLobby__battle_parameter_buffer = 0U;
    }
    battle_param_stats = 0;
    TLobby__battle_param_attacks = 0;
    TLobby__battle_param_resistances = 0;
    battle_param_movement = 0;
}
}

void alloc_battle_param_tables(void) {
    u8 *buf = (u8 *)mem_alloc(0x3d80);
    s32 i;
    for (i = 0; i < 0x3d80; i++) {
        buf[i] = 0;
    }
    TLobby__battle_parameter_buffer = (u32)buf;
    battle_param_stats = (s32)buf;
    TLobby__battle_param_attacks = (s32)(buf + 0xd80);
    TLobby__battle_param_resistances = (s32)(buf + 0x1f80);
    battle_param_movement = (s32)(buf + 0x2b80);
    TLobby::clamp_difficulty(game_difficulty_selection);
    TLobby::get_instance();
    ((s32 (*)(void))set_difficulty__6TLobbyFi)();
    load_battle_param_entry();
    TLobby__lobby_instance = 0;
}
extern "C" {

void TLobby::swap_endian() { bswap_16((u16 *)this); bswap_16((u16 *)((char*)this + 0x2)); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_16((u16 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xa)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); bswap_32((u32 *)((char*)this + 0x18)); bswap_32((u32 *)((char*)this + 0x1c)); }

void TLobby::byteswap_packet() { bswap_16((u16 *)this); bswap_16((u16 *)((char*)this + 0x2)); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_16((u16 *)((char*)this + 0x14)); bswap_16((u16 *)((char*)this + 0x16)); bswap_16((u16 *)((char*)this + 0x18)); bswap_16((u16 *)((char*)this + 0x1a)); bswap_32((u32 *)((char*)this + 0x1c)); bswap_32((u32 *)((char*)this + 0x20)); bswap_32((u32 *)((char*)this + 0x24)); bswap_32((u32 *)((char*)this + 0x28)); bswap_32((u32 *)((char*)this + 0x2c)); }

void bswap__12player_statsFv(void *arg0) {
    bswap_16((u16 *)arg0);
    bswap_16((u16 *)((void *)((char *)arg0 + 2)));
    bswap_16((u16 *)((void *)((char *)arg0 + 4)));
    bswap_16((u16 *)((void *)((char *)arg0 + 6)));
    bswap_16((u16 *)((void *)((char *)arg0 + 8)));
    bswap_16((u16 *)((void *)((char *)arg0 + 10)));
    bswap_16((u16 *)((void *)((char *)arg0 + 12)));
    bswap_16((u16 *)((void *)((char *)arg0 + 14)));
    bswap_32((u32 *)((void *)((char *)arg0 + 16)));
    bswap_32((u32 *)((void *)((char *)arg0 + 20)));
    bswap_32((u32 *)((void *)((char *)arg0 + 24)));
    bswap_32((u32 *)((void *)((char *)arg0 + 28)));
    bswap_32((u32 *)((void *)((char *)arg0 + 32)));
}

extern s32 selected_episode;

s32 TLobby::get_instance() {
    return selected_episode;
}

void set_clock_offset_from_server_time(TLobby *packet) {
    u8 *save;
    DateStamp date;
    s32 minutes;
    s32 local_time;
    s32 offset;

    save = (u8 *)TAdSinglePlyChrSelectGC::get_global_state();
    if (save != 0) {
        getDateStamp(&date);
        minutes = date.hour * 60;
        local_time = (date.minute + minutes) * 60;
        local_time = date.second + local_time;
        local_time = (s32)(30.0f * (f32)local_time);
        offset = packet->calc_time_from_hms() - local_time;
        offset += 108000.0f;
        while (offset < 0) {
            offset += 2592000.0f;
        }
        *(s32 *)(save + 8) = offset;
    }
}

s32 TLobby::calc_time_from_hms() {
    s32 arg0 = (s32)this;
  s32 *new_var;
  int new_var2;
  s32 temp_r31_2;
  s32 temp_r31;
  temp_r31_2 = TLobby__sub_8001E75C((void *)(arg0 + 0xC));
  new_var = &arg0;
  temp_r31 = (temp_r31_2 * 0x3C) + TLobby__sub_8001E75C((void *)(arg0 + 0xF));
  new_var2 = (temp_r31 * 0x3C) + TLobby__sub_8001E75C((void *)((void *) ((*new_var) + 0x12)));
  return (s32) (30.0f * ((f32) new_var2));
}
s32 TLobby__sub_8001E75C(void *arg0) {
    s8 *s = (s8 *)arg0;
    s32 v = (s[0] - '0') * 10;
    v += s[1] - '0';
    return v;
}

s32 __cvt_fp2unsigned(f32);

s32 TLobby::calc_alpha_shifted(f32 farg0) {
    return __cvt_fp2unsigned(255.0f * farg0) << 0x18;
}

extern s32 TLobby__data_8050AAAC[];
extern s32 TLobby__data_805D55AC;
extern s32 TLobby__lobby_number;

void TLobby::close_result_windows() {
    text_builder_reset();
    text_builder_append((u8 *)TLobby__data_8050AAAC);
    text_builder_append((u8 *)":");
    append_padded_number(TLobby__data_805D55AC, 2);
    text_builder_append((u8 *)"-");
    append_padded_number(TLobby__lobby_number + 1, 2);
}


f32 TLobby::calc_result_offset() {
    f32 var_f31;

    var_f31 = 0.0f;
    if (get_main_phase() == 0xF) {
        TLobby::close_result_windows();
        var_f31 -= (f32)(u32)get_name_text_width(get_shared_text_buffer());
    }
    return var_f31;
}

static f32 clock_bar_pulse;


f32 TLobby::calc_phase_offset() {
    f32 var_f31;

    var_f31 = -163.0f;
    if (get_main_phase() == 0xF) {
        var_f31 -= 57.0f;
    }
    return var_f31;
}

s32 default_clock_offset_frames(void) {
    return 0x1A5E00;
}

s32 TLobby::get_internet_beat() {
    return (TLobby::get_clock_frames() / 2592) % 1000;
}

typedef struct DateStamp_8001E8FC DateStamp_8001E8FC;
struct DateStamp_8001E8FC
{
  u8 pad0[4];
  u8 h;
  u8 m;
  u8 s;
  u8 pad7;
  u8 pad8[4];
};
u8 *get_global_state__23TAdSinglePlyChrSelectGCFv();
s32 TLobby::get_clock_frames() {
  u8 *new_var;
  u8 *g;
  s32 base;
  DateStamp_8001E8FC d;
  new_var = &d.h;
  g = get_global_state__23TAdSinglePlyChrSelectGCFv();
  if (g == 0)
  {
    base = default_clock_offset_frames();
  }
  else
  {
    base = *((s32 *)(g + 8));
  }
  getDateStamp((DateStamp *)&d);
  s32 secs = (*new_var) * 60;
  s32 mins = d.m;
  if (g && g)
  {
  }
  secs = (mins + secs) * 60;
  secs = d.s + secs;
  s32 t = (s32) (30.0f * ((f32) ((s32) secs)));
  t += base;
  return t;
}

void TLobby__sub_8001E998(f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    f32 scale;
    f32 var_f4;
    s32 temp_r31;
    var_f4 = farg3;
    if (!(var_f4 <= 0.0f)) {
        if (var_f4 > 1.0f) {
            var_f4 = 1.0f;
        }
        scale = -1.0f / farg2;
        temp_r31 = TLobby::calc_alpha_shifted(var_f4);
        if (get_main_phase() == 0xF) {
            TLobby::close_result_windows();
            draw_small_font_text((void *)(temp_r31 | 0xFF0000 | 0xFFFF), (const char *)(((u8* (*)(void))get_shared_text_buffer)()), (f32)farg0, (f32)(-1.0f + farg1), (f32)scale);
        }
    }
}

#pragma fp_contract on
void TLobby__sub_8001EA5C(f32 x, f32 y, f32 size, f32 alpha) {
    s32 frames;
    s32 text_color;
    s32 color;
    s32 beat;
    f32 scale;
    u32 elapsed;
    DateStamp date;
    ColorLineList lines;
    u32 colors[3];
    ColorLineVertex verts[3];
    s32 pulse;
    f32 progress;
    f32 bar_end;
    f32 bar_y;

    if (!(alpha <= 0.0f)) {
        if (alpha > 1.0f) {
            alpha = 1.0f;
        }
        frames = TLobby::get_clock_frames();
        beat = frames / 2592;
        beat %= 1000;
        scale = -1.0f / size;
        color = TLobby::calc_alpha_shifted(alpha);
        if (get_main_phase() == 0xF) {
            getDateStamp(&date);
            DateToSeconds(&date, (int *)&elapsed);
            elapsed -= TLobby__date_seconds;
            text_builder_reset();
            if (elapsed / 3600 > 99) {
                text_builder_append((u8 *)"99:59");
            } else {
                append_padded_number(elapsed / 3600, 2);
                text_builder_append((u8 *)":");
                append_padded_number((elapsed / 60) % 60, 2);
                text_builder_append((u8 *)"/");
            }
            draw_small_font_text((void *)(color | 0xFF0000 | 0xFFFF), (const char *)get_shared_text_buffer(), x,
                                 -1.0f + y, scale);
            x += 57.0f;
        }
        text_color = color | 0xFF0000 | 0xFFFF;
        TWindowSubStatusDisp__sub_800FBD74(text_color, x, y, scale);
        TWindowSubStatusDisp::draw_number_digits((void *)text_color, beat, 3, 163.0f + x, -1.0f + y, scale);
        clock_bar_pulse += 0.01f;
        if (clock_bar_pulse >= 1.0f) {
            clock_bar_pulse -= 1.0f;
        }
        progress = 163.0f * (frames % 2592);
        progress /= 2592.0f;
        lines.verts = verts;
        lines.colors = colors;
        lines.unk_8 = 0;
        lines.count = 3;
        lines.colors[0] = color | 0xFF00;
        lines.colors[1] = color | 0xFF00;
        lines.colors[2] = color | 0xFF00;
        if (clock_bar_pulse > 0.5f) {
            pulse = 2.0f * (255.0f * (1.0f - clock_bar_pulse));
        } else {
            pulse = 255.0f * (2.0f * clock_bar_pulse);
        }
        lines.colors[1] |= (pulse & 0xFF) | ((pulse << 16) & 0xFF0000);
        bar_end = x + progress;
        bar_y = 18.0f + y;
        verts[0].x = bar_end;
        verts[2].x = x;
        verts[1].x = clock_bar_pulse * (verts[0].x - verts[2].x) + verts[2].x;
        verts[0].y = bar_y;
        verts[1].y = bar_y;
        verts[2].y = bar_y;
        draw_color_lines(&lines, 3, 20, size);
    }
}
#pragma fp_contract reset

void TLobby__sub_8001ED70(void) {  }
void TLobby__sub_8001ED74(void) {
    clock_bar_pulse = 0.0f;
}
}
