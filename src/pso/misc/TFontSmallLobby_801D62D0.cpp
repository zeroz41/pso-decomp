#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TMainCursor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastGauge.h"

struct Lobby_801D6498 {
    u8 pad[0x14];
    u32 arr[10];
    u8 pad2[0x4C - 0x3C];
    u8 fields[1];
};

typedef struct Obj_801D650C {
    u16 a;
    s16 b;
    s16 c;
    u8 pad6[2];
    s32 d;
    f32 e;
    f32 f;
    u8 arr[10][4];
    f32 g;
    u8 sub[4];
    u8 flags[6];
} Obj_801D650C;

extern "C" {
s32 send_6x39_photon_blast_ready();
}
extern const f32 lbl_805DC3DC;
void add_photon_blast_charge(u8 *arg0, f32 farg0);
extern "C" {
int TFontSmallLobby__sub_801D677C(void *);
extern const f32 lbl_805DC3E4;
void add_photon_blast_chain_charge(u8 *arg0, f32 farg0);
s32 send_6x3A_clear_photon_blast_ready_flag();
extern const f32 lbl_805DC3E0;
s32 subtract_photon_blast_charge(TFontSmallLobby *arg0, f32 farg0);
void TFontSmallLobby__sub_80152F28(void *);
void TFontSmallLobby__sub_801D67C8(void* p);
void reset_photon_blast_gauge(struct Lobby_801D6498 *s);
extern const f32 lbl_805DC3E8;
s32 TFontSmallLobby__sub_801D67AC(u8 *arg0);
void *get_player_by_client_id(s32 i);
u16 get_type__15TFontSmallLobbyFPv(void* p);
s32 send_field_state__10TObjPlayerFPv();

s32 subtract_photon_blast_charge(TFontSmallLobby *font_small_lobby, f32 farg0) {
  const f32 *new_var;
  f32 temp_f0;
  f32 temp_f1;
  temp_f0 = *((f32 *) (((s8 *) font_small_lobby) + 0x3C));
  if (temp_f0 < lbl_805DC3DC)
  {
    *((f32 *) (((s8 *) font_small_lobby) + 0x3C)) = (f32) (temp_f0 - farg0);
    if ((*((f32 *) (((s8 *) font_small_lobby) + 0x3C))) < (*(new_var = &lbl_805DC3E0)))
    {
      *((f32 *) (((s8 *) font_small_lobby) + 0x3C)) = (f32) (*new_var);
      return 0;
    }
    goto block_7;
  }
  *((f32 *) (((s8 *) font_small_lobby) + 0x3C)) = (f32) (temp_f0 - farg0);
  temp_f1 = *((f32 *) (((s8 *) font_small_lobby) + 0x3C));
  if (temp_f1 < lbl_805DC3DC)
  {
    send_6x3A_clear_photon_blast_ready_flag();
  }
  else
    if (temp_f1 < lbl_805DC3E4)
  {
    font_small_lobby->update_field_40();
  }
  block_7:
  return 1;
}

void add_photon_blast_chain_charge(u8 *arg0, f32 farg0) {
    f32 temp_f0;
    temp_f0 = *(f32 *)((s8 *)arg0 + 0x3C);
    if (temp_f0 < lbl_805DC3DC) {
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (temp_f0 + farg0);
        if (*(f32 *)((s8 *)arg0 + 0x3C) >= lbl_805DC3DC) {
            send_6x39_photon_blast_ready();
        }
    } else if (temp_f0 < lbl_805DC3E4) {
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (temp_f0 + farg0);
        if (*(f32 *)((s8 *)arg0 + 0x3C) >= lbl_805DC3E4) {
            *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805DC3E4;
            ((TFontSmallLobby *)arg0)->update_ready();
            TFontSmallLobby__sub_801D677C(arg0);
        }
    }
}
}

void add_photon_blast_charge(u8 *arg0, f32 farg0) {
    f32 temp_f0;
    temp_f0 = *(f32 *)((s8 *)arg0 + 0x3C);
    if (temp_f0 < lbl_805DC3DC) {
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (temp_f0 + farg0);
        if (*(f32 *)((s8 *)arg0 + 0x3C) >= lbl_805DC3DC) {
            *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805DC3DC;
            send_6x39_photon_blast_ready();
        }
    }
}

void TFontSmallLobby::send_photon_blast_ready() {
    if (get_player_by_client_id(((u16 (*)())get_type__15TFontSmallLobbyFPv)()) != 0U) {
        send_field_state__10TObjPlayerFPv();
    }
}

void TFontSmallLobby::update_if_ready() { if (TFontSmallLobby__sub_801D67AC((u8 *)this) != 0) { update_ready(); } }
void reset_photon_blast_gauge(struct Lobby_801D6498 *s) {
    s32 i;
    ((void (*)(void))TFontSmallLobby__sub_801D67C8)();
    ((TFontSmallLobby *)s)->set_section_index(0);
    for (i = 0; i < 10; i++) {
        TFontSmallLobby__sub_80152F28(&s->arr[i]);
    }
    ((PhotonBlastGauge *)s)->clear_charge();
    ((TObjPlayer *)s)->clear_photon_blast_state();
    ((TFontSmallLobby *)(s->fields))->reset_fields();
}
void TFontSmallLobby::reset_state() {
    Obj_801D650C *arg0 = (Obj_801D650C *)this;
    s32 i;
    s32 k;
    u8 *fp;
    i = 0;
    arg0->a = 0xFFFF;
    arg0->b = 0;
    arg0->c = 0;
    arg0->d = 0;
    arg0->e = lbl_805DC3E8;
    arg0->f = lbl_805DC3E0;
    do {
        TFontSmallLobby__sub_80152F28(arg0->arr[i]);
        i++;
    } while (i < 10);
    arg0->g = lbl_805DC3E0;
    ((FlagWord *)(arg0->sub))->reset();
    for (k = 0, fp = arg0->flags; k < 6; k++, fp++) {
        *fp = 0;
    }
    ((TFontSmallLobby *)((u8 *)arg0 + 0x4C))->reset_fields();
}

struct Pkt_801D698C { u8 cmd; u8 size; u8 pad[2]; u16 a; u16 b; };

struct Obj_801D6A18 { s32 a[4]; s32 x10; s32 x14; };

typedef struct Rec_801D6AB4 {
    u8 pad0[8];
    f32 a;
    f32 b;
} Rec_801D6AB4;

extern "C" {
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
f32 fn_801D6AB4(void *, s32, s32);
s32 accumulate_damage_stats(u8 *arg0, s32 arg1, s32 arg2);
void TFontSmallLobby__sub_801D698C(Pkt_801D698C *p);
void clear_player_sub_object_slots(Obj_801D6A18 *p);
s32 __construct_array(void *, void *, int, int, int);
extern s32 fn_80152EF8[];
void TFontSmallLobby__sub_801D671C(void* a0, int a1);
int TFontSmallLobby__sub_801D677C(void* p);
void* TFontSmallLobby__sub_801D6804(void* p);
int TFontSmallLobby__sub_801C01BC(void*);
int TFontSmallLobby__sub_801C0228(void*);
int clear__8FlagWordFUl(void*, int);
int set__8FlagWordFUl(void*, int);

s32 TFontSmallLobby::construct_pb_controller() {
    s32 arg0 = (s32)this;
    __construct_array((void *)(arg0 + 0x14), fn_80152EF8, 0, 4, 0xA);
    __ct__8FlagWordFv((void *)(arg0 + 0x40));
    ((TFontSmallLobby *)(arg0 + 0x4C))->init_reset_fields();
    ((TFontSmallLobby *)arg0)->reset_state();
    return arg0;
}

int TFontSmallLobby::is_valid_index(s16 arg0) {
    u8 var_r4;
    var_r4 = 0;
    if (((arg0 >= 0) && (arg0 < 6)) || (arg0 == -1)) {
        var_r4 = 1;
    }
    return var_r4;
}

void TFontSmallLobby::reset_fields() { *(s32*)((char*)this + 0x0) = 0; *(s32*)((char*)this + 0x4) = 0; }
int TFontSmallLobby::set_bit1_at_40() { return clear__8FlagWordFUl((char*)this + 0x40, 2); }
void*TFontSmallLobby::clear_photon_blast_ready_flag() { TFontSmallLobby__sub_801C0228(this); return this; }
int TFontSmallLobby::update_ready() { return set__8FlagWordFUl((char*)this + 0x40, 2); }

s32 TFontSmallLobby::get_state() { return *(s32*)((char*)this + 0x0); }
s32 TFontSmallLobby::get_field_04() { return *(s32*)((char*)this + 0x4); }
int TFontSmallLobby::check_flag_at_40() { return clear__8FlagWordFUl((char*)this + 0x40, 32); }
void TFontSmallLobby::set_target_count(s32 v) { *(s32*)((char*)this + 0x4) = v; }
void TFontSmallLobby::set_target_index(s32 v) { *(s32*)((char*)this + 0x0) = v; }
void TFontSmallLobby__sub_801D671C(void* a0, int a1) { *(int*)((char*)a0 + 0x4) = (*(int*)((char*)a0 + 0x4) + a1); }
int TFontSmallLobby::set_flag_40_bit5() { return set__8FlagWordFUl((char*)this + 0x40, 32); }
int TFontSmallLobby::update_field_40() { return clear__8FlagWordFUl((char*)this + 0x40, 16); }
int TFontSmallLobby__sub_801D677C(void* p) { return set__8FlagWordFUl((char*)p + 0x40, 16); }
u16 get_type__15TFontSmallLobbyFPv(void* p) { return *(u16*)((char*)p + 0x0); }

s32 TFontSmallLobby__sub_801D67AC(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x3C) >= lbl_805DC3DC;
}

void TFontSmallLobby__sub_801D67C8(void* p) { *(s16*)((char*)p + 0x2) = 6; }
void*TFontSmallLobby::init_reset_fields() { reset_fields(); return this; }
void* TFontSmallLobby__sub_801D6804(void* p) { TFontSmallLobby__sub_801C0228(p); return p; }
void TFontSmallLobby::init_pkt_cmd_3B() { *(u8*)((char*)this + 0x0) = 59; *(u8*)((char*)this + 0x1) = 1; }
void TFontSmallLobby::update_and_send() { TFontSmallLobby__sub_801C01BC(this); send_subcommand((u8 *)this); }
void TFontSmallLobby::init_6x3A_packet() { *(u8*)((char*)this + 0x0) = 58; *(u8*)((char*)this + 0x1) = 1; }
void TFontSmallLobby::draw_and_send() { TFontSmallLobby__sub_801C01BC(this); send_subcommand((u8 *)this); }
void TFontSmallLobby::init_6x39_packet() { *(u8*)((char*)this + 0x0) = 57; *(u8*)((char*)this + 0x1) = 1; }
void TFontSmallLobby::update_and_send_60() { TFontSmallLobby__sub_801C01BC(this); send_subcommand((u8 *)this); }
void TFontSmallLobby::bswap_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void*TFontSmallLobby::copy_packet_header_6x38(void* a1) { TFontSmallLobby__sub_801C0228(this); *(short*)((char*)this + 0x4) = *(unsigned short*)((char*)a1 + 0x4); *(short*)((char*)this + 0x6) = *(short*)((char*)a1 + 0x6); return this; }

void TFontSmallLobby__sub_801D698C(Pkt_801D698C *p) {
    p->a = 0xFFFF;
    p->b = 0;
    p->cmd = 0x38;
    p->size = 2;
}

void TFontSmallLobby::send_state() { bswap_fields(); send_subcommand((u8 *)this); }
void*TFontSmallLobby::handle_photon_blast_ready() { TFontSmallLobby__sub_801C0228(this); return this; }

void clear_player_sub_object_slots(Obj_801D6A18 *p) {
    s32 i;
    for (i = 0; i < 4; i++) {
        p->a[i] = 0;
    }
    p->x10 = 0;
    p->x14 = 0;
}

s32 accumulate_damage_stats(u8 *arg0v, s32 arg1, s32 arg2) {
  f32 new_var;
  f32 temp_f1;
  new_var = (f32) arg2;
  *((f32 *) (((s8 *) arg0v) + 4)) = (f32) ((*((f32 *) (((s8 *) arg0v) + 4))) + new_var);
  new_var = fn_801D6AB4(arg0v, arg1, arg2);
  temp_f1 = new_var;
  *((f32 *) (((s8 *) arg0v) + 0)) = (f32) ((*((f32 *) (((s8 *) arg0v) + 0))) + temp_f1);
  return (s32) temp_f1;
}

#define arg0 ((Rec_801D6AB4 *)arg0v)
f32 fn_801D6AB4(void *arg0v, s32 arg1, s32 arg2) {
    f32 v;
    f32 k = (f32)arg2;

    v = arg0->a;
    if (obj_testFlags30__14TObjCollidableFUl((void *)arg1, 0x10000000) != 0) {
        v = arg0->b;
    }
    return k * v;
}
#undef arg0

}
