#include "types.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/item/TItemData.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"

struct SRock_80224544_8022448C;

struct RecoveredGlobal_802259A0_lbl_80513F70
{
  s32 value;
  u8 remaining[0x67C];
};

struct RecoveredGlobal_802258C8_lbl_80513F70
{
  s32 value;
  u8 remaining[0x67C];
};

struct O_80225B90 { u8 pad[0x20]; char name[1]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct L_80225AD8 { u8 pad[0xcc]; s8 flags; u8 pad2[3]; };

struct L_80225B40 { u8 pad[0xcc]; s8 flags; u8 pad2[3]; };

struct Tag_80225828 { u8 b[0x228]; };

typedef struct Item_8022525C
{
  u8 b0;
  u8 b1;
  u8 b2;
  u8 pad3[7];
  u8 b12;
  u8 b13;
  u8 padC[8];
} Item_8022525C;

typedef struct Pool_8022525C
{
  u8 b[0x68];
} Pool_8022525C;

typedef struct Pair_8022525C
{
  s32 a;
  s32 b;
} Pair_8022525C;

typedef struct Ent_8022525C
{
  u8 id;
  u8 count;
} Ent_8022525C;

typedef struct Tier_8022525C
{
  Ent_8022525C *ents;
  u8 n;
} Tier_8022525C;

typedef struct Hdr_8022525C
{
  Tier_8022525C *tiers;
} Hdr_8022525C;

extern unsigned char lbl_80513F70[];
extern "C" {
s32 strncpy(void *, void *, int);
extern s32 lbl_805D6270;
s32 is_name_too_long__6TLobbyFPv(O_80225B90 *o);
extern int lobby_short_mail_entry_count;
void send_simple_mail__9TProtocolFR12TChatMessage(void *, void *);
extern u8 *TLobby__protocol_instance;

unsigned char lbl_80513F70[0x680];
s32 lbl_805D6270;
int lobby_short_mail_entry_count;

void try_close__6TLobbyFPv(void* p) { if (is_name_too_long__6TLobbyFPv((O_80225B90 *)(p)) == 0) { TLobby__sub_80225A08(p); } }

typedef struct RecoveredGlobal_802258C8_lbl_80513F70 RecoveredGlobal_802258C8_lbl_80513F70;
typedef char RecoveredGlobal_802258C8_lbl_80513F70_size[((sizeof(RecoveredGlobal_802258C8_lbl_80513F70)) == 0x680) ? (1) : (-1)];

void send_simple_mail__6TLobbyFiPv(s32 arg0, void *arg1) {
    Tag_80225828 t;
    s32 mode;
    ((TLobby *)(&t))->init_guild_card_tag();
    if (TLobby__protocol_instance != 0) {
        mode = TWindowSubComCard::get_keyboard_mode();
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&t.b[4], TLobby__protocol_instance + 0x1900);
        strncpy(&t.b[0xC], (void *)(((void *)get_com_card_list__6TLobbyFPv((void*)((void *)mode)))), 0x17);
        *(s32 *)&t.b[0x1C] = arg0;
        t.b[0x23] = 0;
        strncpy(&t.b[0x20], arg1, 0xAB);
        t.b[0xCB] = 0;
        send_simple_mail__9TProtocolFR12TChatMessage(TLobby__protocol_instance, &t);
    }
}

void TLobby__sub_802258C8(void) {
  s32 var_r31;
  s32 *var_r30;
  var_r31 = 0;
  var_r30 = (s32 *) (&(*(RecoveredGlobal_802258C8_lbl_80513F70 *)&lbl_80513F70).value);
  do
  {
    if (((s32)is_flag_set__6TLobbyFPv(var_r30)) != 0)
    {
      TLobby__sub_80225C8C((void*)((int) var_r30));
    }
    var_r31 += 1;
    var_r30 = (s32 *) (((u8 *) var_r30) + 0xD0);
  }
  while (var_r31 < 8);
}

void *find_short_mail_by_id__6TLobbyFUi(u32 id) {
    s32 count = ((s32)get_short_mail_ctrl__6TLobbyFv());
    s32 i;
    for (i = 0; i < count; i++) {
        void *o = TLobby__sub_8022598C(i);
        if (id == get_lobby_id__6TLobbyFPv(o)) {
            return o;
        }
    }
    return 0;
}

void *TLobby__sub_8022598C(int a0) {
  unsigned char *new_var;
  new_var = lbl_80513F70;
  if ((!new_var) && (!new_var))
  {
  }
  return ((char *) new_var) + (a0 * 0xd0);
}

typedef struct RecoveredGlobal_802259A0_lbl_80513F70 RecoveredGlobal_802259A0_lbl_80513F70;
typedef char RecoveredGlobal_802259A0_lbl_80513F70_size[((sizeof(RecoveredGlobal_802259A0_lbl_80513F70)) == 0x680) ? (1) : (-1)];
s32 find_free_slot__6TLobbyFv(void) {
  s32 var_r31;
  s32 *var_r30;
  var_r31 = 0;
  var_r30 = (s32 *) (&(*(RecoveredGlobal_802259A0_lbl_80513F70 *)&lbl_80513F70).value);
  loop_1:
  if (is_flag_set__6TLobbyFPv(var_r30) == 0)
  {
    return var_r31;
  }
  var_r31 += 1;
  var_r30 = (s32 *) ((u8 *) ((s32 *) (((u8 *) var_r30) + 0xD0)));
  if (var_r31 >= 8)
  {
    remove_entry_at__6TLobbyFi(0);
    return 7;
  }
  goto loop_1;
}
}

extern "C" s32 play_sound_effect(int, void *, int, int);

void TLobby__sub_80225A08(void *p) {
    s32 slot = find_free_slot__6TLobbyFv();
    u8 *entry = lbl_80513F70;
    entry += slot * 0xd0;
    fill_list_entry__6TLobbyFPvPv(entry, (u8 *)p);
    lobby_short_mail_entry_count++;
    TLobby__sub_80225CB8();
    play_sound_effect(0x52D17, 0, 0, 0);
}

void remove_short_mail_by_id(u32 id) {
    s32 count = get_short_mail_ctrl__6TLobbyFv();
    s32 i;
    for (i = 0; i < count; i++) {
        if (id == (u32)get_lobby_id__6TLobbyFPv(TLobby__sub_8022598C(i))) {
            remove_entry_at__6TLobbyFi(i);
            return;
        }
    }
}

void remove_entry_at__6TLobbyFi(s32 idx) {
    if (idx < 7) {
        L_80225AD8 *p = &((L_80225AD8 *)&lbl_80513F70)[idx];
        ((TLobby *)p)->move_words((u32 *)(p + 1), (s32)((void *)(((7 - idx) * sizeof(L_80225AD8)) >> 2)));
    }
    ((L_80225AD8 *)&lbl_80513F70)[7].flags &= ~1;
    (*(s32 *)&lobby_short_mail_entry_count) = (*(s32 *)&lobby_short_mail_entry_count) - 1;
}

void clear_all_entries__6TLobbyFPv(void* _w0) {
    s32 i;
    L_80225B40 *p;
    lbl_805D6270 = 0;
    (*(s32 *)&lobby_short_mail_entry_count) = 0;
    clear_lobby_flag__6TLobbyFv();
    p = ((L_80225B40 *)&lbl_80513F70);
    for (i = 0; i < 8; i++) {
        p->flags &= ~1;
        p++;
    }
}

s32 is_name_too_long__6TLobbyFPv(O_80225B90 *o) {
    s32 i = 0;
    char *p = o->name;
    while (*p++ != 0) {
        if (i > 0xaa) {
            return 1;
        }
        i++;
    }
    return 0;
}

void fill_list_entry__6TLobbyFPvPv(u8 *arg0, u8 *arg1) {
    s32 temp_r7;
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 8);
    temp_r7 = lbl_805D6270;
    lbl_805D6270 = temp_r7 + 1;
    *(s32 *)((s8 *)arg0 + 4) = temp_r7;
    *(s8 *)((s8 *)arg0 + 0xCC) = 0xB;
    strncpy(arg0 + 8, arg1 + 0xC, 0x17);
    *(s8 *)((s8 *)arg0 + 0x1F) = 0;
    strncpy(arg0 + 0x20, arg1 + 0x20, 0xAB);
    *(s8 *)((s8 *)arg0 + 0xCB) = 0;
}

void TLobby__sub_80225C44(void* p) { clear_all_entries__6TLobbyFPv(p); }
void TLobby__sub_80225C64(void* p) { clear_all_entries__6TLobbyFPv(p); }
void* get_com_card_list__6TLobbyFPv(void* p) { return (char*)p + 0x8; }
void TLobby__sub_80225C8C(void* p) { *(u8*)((char*)p + 0xcc) &= 0xfffffffd; }
int is_flag_set__6TLobbyFPv(void* p) { return *(u8*)((char*)p + 0xcc) & 0x1; }
s32 get_lobby_id__6TLobbyFPv(void* p) { return *(s32*)((char*)p + 0x4); }

int get_short_mail_ctrl__6TLobbyFv(void) {  return lobby_short_mail_entry_count; }

extern u16 lbl_805D63FC;

void TLobby__sub_80225CB8(void) {
    lbl_805D63FC |= 1;
}

void clear_lobby_flag__6TLobbyFv(void) {
    lbl_805D63FC &= 0xFFFE;
}
