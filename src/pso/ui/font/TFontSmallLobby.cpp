#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/byteswap.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/font/TFontSmallLobby_801C013C.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastGauge.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s16 TAdSinglePlyChrSelectGC__sub_801D5DDC(void *arg0);

s16 TAdSinglePlyChrSelectGC__sub_801D5DDC(void *font_small_lobby) {
    s16 temp_r3;

    temp_r3 = *(s16 *)((s8 *)font_small_lobby + 4);
    if ((temp_r3 < 0) || (temp_r3 > 0xA)) {
        ((TFontSmallLobby *)font_small_lobby)->set_section_index(0);
    }
    return *(s16 *)((s8 *)font_small_lobby + 4);
}

s16 TFontSmallLobby::get_valid_index() {
    s16 var_r31;

    var_r31 = *(s16 *)((s8 *)this + 2);
    if (TFontSmallLobby::is_valid_index(var_r31) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}

}

struct Pkt_801D60B4 { s16 a; u16 b; };

struct Pkt_801D5FC0 { u16 hdr; u16 id; };

extern "C" {
s32 get_current_floor();
void *get_player_by_client_id(s32 i);
s32 validate_6x39_set_photon_blast_ready_flag(void *);
void *TFontSmallLobby__sub_801D6804(void *p, void *src);
s32 validate_6x3B_clear_temporary_photon_blast_state_flags(void *);
s32 validate_6x3A_clear_photon_blast_ready_flag(void *);
void TFontSmallLobby::set_section_index(s16 count) {
    s16 var_r4;

    var_r4 = count;
    if ((var_r4 < 0) || (var_r4 > 0xA)) {
        var_r4 = 0;
    }
    *(s16 *)((s8 *)this + 4) = var_r4;
}
}
void handle_6x39_set_photon_blast_ready_flag(saddr arg0);
void handle_6x3B_clear_temporary_photon_blast_state_flags(saddr arg0);
void reinit_photon_blast_gauge(u16 *arg0);
void handle_6x3A_clear_photon_blast_ready_flag(saddr arg0);
void handle_6x3B_clear_temporary_photon_blast_state_flags(saddr src) {
    struct { s16 a; u16 b; } sp8;
    saddr player;
    ((TFontSmallLobby *)(&sp8))->init_pkt_cmd_3B();
    TFontSmallLobby__sub_801D6804(&sp8, (void *)src);
    bswap_g_client_id_header((&sp8));
    if (validate_6x3B_clear_temporary_photon_blast_state_flags(&sp8) != 0) {
        player = (saddr)get_player_by_client_id(sp8.b);
        if (player != 0) {
            ((TObjPlayer *)(player + 0x4AC))->clear_photon_blast_state();
            if (TObjPlayer::is_locally_controlled((void *)player) != 0) {
                TObjPlayer::update_photon_blast_state();
            }
        }
    }
}

void reinit_photon_blast_gauge(u16 *arg0) {
    struct { s16 a; u16 b; } sp8;
    ((TObjPlayer *)arg0)->clear_photon_blast_state();
    ((TFontSmallLobby *)((u8 *)arg0 + 0x4C))->reset_fields();
    ((TFontSmallLobby *)(&sp8))->init_pkt_cmd_3B();
    sp8.b = *arg0;
    ((TFontSmallLobby *)(&sp8))->update_and_send();
}

void handle_6x3A_clear_photon_blast_ready_flag(saddr src) {
    struct { s16 a; u16 b; } sp8;
    u8 *player;
    ((TFontSmallLobby *)(&sp8))->init_6x3A_packet();
    ((TFontSmallLobby *)(&sp8))->clear_photon_blast_ready_flag((void *)src);
    bswap_g_client_id_header((&sp8));
    if (validate_6x3A_clear_photon_blast_ready_flag(&sp8) != 0) {
        player = (u8 *)get_player_by_client_id(sp8.b);
        if (player != 0) {
            ((TFontSmallLobby *)(player + 0x4AC))->set_bit1_at_40();
        }
    }
}

void send_6x3A_clear_photon_blast_ready_flag(u16 *gauge) {
    struct Pkt_801D5FC0 pkt;
    TObjChara *chara = (TObjChara *)get_player_by_client_id(*gauge);
    if (chara == NULL || chara->obj_isState2_324() == 0) {
        ((TFontSmallLobby *)(&pkt))->init_6x3A_packet();
        pkt.id = *gauge;
        ((TFontSmallLobby *)(&pkt))->draw_and_send();
    }
}

void handle_6x39_set_photon_blast_ready_flag(saddr src) {
    struct { s16 a; u16 b; } sp8;
    s32 temp_r31;
    saddr player;
    s32 v;
    ((TFontSmallLobby *)(&sp8))->init_6x39_packet();
    ((TFontSmallLobby *)(&sp8))->handle_photon_blast_ready((void *)src);
    bswap_g_client_id_header((&sp8));
    if (validate_6x39_set_photon_blast_ready_flag(&sp8) != 0) {
        player = (saddr)get_player_by_client_id(sp8.b);
        if ((player != 0) && (is_current_area_item_enabled() != 0)) {
            temp_r31 = ((TObjPlayer *)player)->get_floor();
            v = get_current_floor();
            if (v == temp_r31) {
                ((TFontSmallLobby *)(player + 0x4AC))->update_ready();
                ((TFontSmallLobby *)(player + 0x4AC))->send_photon_blast_ready();
            }
        }
    }
}

void send_6x39_photon_blast_ready(u16 *p) {
    Pkt_801D60B4 pk;
    ((TFontSmallLobby *)(&pk))->init_6x39_packet();
    pk.b = *p;
    ((TFontSmallLobby *)(&pk))->update_and_send_60();
}

struct Cmd_801D61A0 { u8 hdr[2]; u16 client; u8 body[8]; };

struct Subcommand6x38 { u8 cmd; u8 size; u8 pad[2]; u16 a; u16 b; };
extern "C" {
void TFontSmallLobby__sub_801D698C(Subcommand6x38 *p);
s32 validate_6x38_donate_to_photon_blast(void *);
}
void handle_6x38_donate_to_photon_blast(saddr arg0);

s32 TFontSmallLobby::is_ready() {
    u8 *arg0 = (u8 *)this;
    if ((((TFontSmallLobby *)(arg0 + 0x4C))->get_field_04() < 3) && (*(f32 *)((s8 *)arg0 + 0x3C) > 10.0f) && (((TFontSmallLobby *)(arg0 + 0x4C))->get_state() < 0)) {
        return 1;
    }
    return 0;
}

void TFontSmallLobby::reset_targets() {
    saddr arg0 = (saddr)this;
    ((TFontSmallLobby *)(arg0 + 0x4C))->set_target_index(0);
    ((TFontSmallLobby *)(arg0 + 0x4C))->set_target_count(0);
    ((TFontSmallLobby *)arg0)->check_flag_at_40();
}
void handle_6x38_donate_to_photon_blast(saddr arg0) {
    Cmd_801D61A0 cmd;
    saddr player;
    TFontSmallLobby__sub_801D698C((Subcommand6x38 *)&cmd);
    ((TFontSmallLobby *)(&cmd))->copy_packet_header_6x38((void *)arg0);
    ((TFontSmallLobby *)(&cmd))->bswap_fields();
    if (validate_6x38_donate_to_photon_blast(&cmd) != 0) {
        player = (saddr)get_player_by_client_id(cmd.client);
        if ((player != 0) && (is_current_area_item_enabled() != 0)) {
            if (get_current_floor() == ((TObjPlayer *)player)->get_floor()) {
                TObjPlayer::create_photon_blast_party_effects(cmd.client);
            }
        }
    }
}
extern "C" {

void draw_party_label__15TFontSmallLobbyFiUiUs(saddr arg0, uaddr arg1, u16 arg2);
s32 subtract_photon_blast_charge(PhotonBlastGauge *gauge, f32 amount);
void TFontSmallLobby__sub_801D671C(void *a0, int a1);

struct Sp801D6230_801d6230 { s16 f0; s16 fA; s16 fC; };

void draw_party_label__15TFontSmallLobbyFiUiUs(saddr font_small_lobby, uaddr arg1, u16 to) {
    Sp801D6230_801d6230 sp8;

    ((TFontSmallLobby *)font_small_lobby)->set_flag_40_bit5();
    subtract_photon_blast_charge((PhotonBlastGauge *)font_small_lobby, 10.0f);
    ((TFontSmallLobby *)(font_small_lobby + 0x4C))->set_target_index(8);
    TFontSmallLobby__sub_801D671C((void *)(font_small_lobby + 0x4C), 1);
    TWindowCtrl::create_party_effect(((TObjBase *)(arg1))->get_entity_id(), to);
    if ((arg1 == 0U) || (((TObjChara *)arg1)->obj_isState2_324() == 0)) {
        TFontSmallLobby__sub_801D698C((Subcommand6x38 *)&sp8);
        sp8.fA = ((TObjBase *)(arg1))->get_entity_id();
        sp8.fC = to;
        ((TFontSmallLobby *)((s32 *) &sp8))->send_state();
    }
}
}

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

void add_photon_blast_charge(u8 *gauge, f32 amount);
extern "C" {
void TFontSmallLobby__sub_801D677C(void *);
void add_photon_blast_chain_charge(PhotonBlastGauge *gauge, f32 amount);
void TFontSmallLobby__sub_80152F28(void *);
void TFontSmallLobby__sub_801D67C8(void* p);
void reset_photon_blast_gauge(struct Lobby_801D6498 *s);
s32 TFontSmallLobby__sub_801D67AC(u8 *arg0);
void *get_player_by_client_id(s32 i);

s32 subtract_photon_blast_charge(PhotonBlastGauge *gauge, f32 amount) {
    f32 charge = gauge->charge;
    if (charge < 100.0f) {
        gauge->charge = charge - amount;
        if (gauge->charge < 0.0f) {
            gauge->charge = 0.0f;
            return 0;
        }
    } else {
        gauge->charge = charge - amount;
        charge = gauge->charge;
        if (charge < 100.0f) {
            send_6x3A_clear_photon_blast_ready_flag((u16 *)gauge);
        } else if (charge < 400.0f) {
            ((TFontSmallLobby *)gauge)->update_field_40();
        }
    }
    return 1;
}

void add_photon_blast_chain_charge(PhotonBlastGauge *gauge, f32 amount) {
    f32 charge = gauge->charge;
    if (charge < 100.0f) {
        gauge->charge = charge + amount;
        if (gauge->charge >= 100.0f) {
            send_6x39_photon_blast_ready((u16 *)gauge);
        }
    } else if (charge < 400.0f) {
        gauge->charge = charge + amount;
        if (gauge->charge >= 400.0f) {
            gauge->charge = 400.0f;
            ((TFontSmallLobby *)gauge)->update_ready();
            TFontSmallLobby__sub_801D677C(gauge);
        }
    }
}
}

void add_photon_blast_charge(u8 *gauge, f32 amount) {
    f32 temp_f0;
    temp_f0 = *(f32 *)((s8 *)gauge + 0x3C);
    if (temp_f0 < 100.0f) {
        *(f32 *)((s8 *)gauge + 0x3C) = (f32) (temp_f0 + amount);
        if (*(f32 *)((s8 *)gauge + 0x3C) >= 100.0f) {
            *(f32 *)((s8 *)gauge + 0x3C) = 100.0f;
            send_6x39_photon_blast_ready((u16 *)gauge);
        }
    }
}

void TFontSmallLobby::send_photon_blast_ready() {
    void *tmp_player;
    if ((tmp_player = (void *)get_player_by_client_id(((u16 (*)())TFontSmallLobby::get_type)())) != 0U) {
        ((TObjPlayer *)tmp_player)->play_photon_blast_feedback();
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
    arg0->e = 1.0f;
    arg0->f = 0.0f;
    do {
        TFontSmallLobby__sub_80152F28(arg0->arr[i]);
        i++;
    } while (i < 10);
    arg0->g = 0.0f;
    ((FlagWord *)(arg0->sub))->reset();
    for (k = 0, fp = arg0->flags; k < 6; k++, fp++) {
        *fp = 0;
    }
    ((TFontSmallLobby *)((u8 *)arg0 + 0x4C))->reset_fields();
}


struct Obj_801D6A18 { s32 a[4]; s32 x10; s32 x14; };

typedef struct Rec_801D6AB4 {
    u8 pad0[8];
    f32 a;
    f32 b;
} Rec_801D6AB4;

extern "C" {
f32 fn_801D6AB4(void *, saddr, s32);
s32 accumulate_damage_stats(u8 *arg0, s32 arg1, s32 arg2);
void clear_player_sub_object_slots(Obj_801D6A18 *p);
s32 __construct_array(void *, void *, int, int, int);
extern s32 fn_80152EF8[];
void TFontSmallLobby__sub_801D671C(void* a0, int a1);
void TFontSmallLobby__sub_801D677C(void* p);

s32 TFontSmallLobby::construct_pb_controller() {
    saddr arg0 = (saddr)this;
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
void TFontSmallLobby::set_bit1_at_40() { ((FlagWord *)((char*)this + 0x40))->clear(2); }
void *TFontSmallLobby::clear_photon_blast_ready_flag(void *src) { copy_subcommand_header(this, src); return this; }
void TFontSmallLobby::update_ready() { ((FlagWord *)((char*)this + 0x40))->set(2); }

s32 TFontSmallLobby::get_state() { return *(s32*)((char*)this + 0x0); }
s32 TFontSmallLobby::get_field_04() { return *(s32*)((char*)this + 0x4); }
void TFontSmallLobby::check_flag_at_40() { ((FlagWord *)((char*)this + 0x40))->clear(32); }
void TFontSmallLobby::set_target_count(s32 v) { *(s32*)((char*)this + 0x4) = v; }
void TFontSmallLobby::set_target_index(s32 v) { *(s32*)((char*)this + 0x0) = v; }
void TFontSmallLobby__sub_801D671C(void* a0, int a1) { *(int*)((char*)a0 + 0x4) = (*(int*)((char*)a0 + 0x4) + a1); }
void TFontSmallLobby::set_flag_40_bit5() { ((FlagWord *)((char*)this + 0x40))->set(32); }
void TFontSmallLobby::update_field_40() { ((FlagWord *)((char*)this + 0x40))->clear(16); }
void TFontSmallLobby__sub_801D677C(void* p) { ((FlagWord *)((char*)p + 0x40))->set(16); }
u16 TFontSmallLobby::get_type(void* p) { return *(u16*)((char*)p + 0x0); }

s32 TFontSmallLobby__sub_801D67AC(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x3C) >= 100.0f;
}

void TFontSmallLobby__sub_801D67C8(void* p) { *(s16*)((char*)p + 0x2) = 6; }
void*TFontSmallLobby::init_reset_fields() { reset_fields(); return this; }
void *TFontSmallLobby__sub_801D6804(void *p, void *src) { copy_subcommand_header(p, src); return p; }
void TFontSmallLobby::init_pkt_cmd_3B() { *(u8*)((char*)this + 0x0) = 59; *(u8*)((char*)this + 0x1) = 1; }
void TFontSmallLobby::update_and_send() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void TFontSmallLobby::init_6x3A_packet() { *(u8*)((char*)this + 0x0) = 58; *(u8*)((char*)this + 0x1) = 1; }
void TFontSmallLobby::draw_and_send() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void TFontSmallLobby::init_6x39_packet() { *(u8*)((char*)this + 0x0) = 57; *(u8*)((char*)this + 0x1) = 1; }
void TFontSmallLobby::update_and_send_60() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void TFontSmallLobby::bswap_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void*TFontSmallLobby::copy_packet_header_6x38(void* source) { copy_subcommand_header(this, source); *(short*)((char*)this + 0x4) = *(unsigned short*)((char*)source + 0x4); *(short*)((char*)this + 0x6) = *(short*)((char*)source + 0x6); return this; }

void TFontSmallLobby__sub_801D698C(Subcommand6x38 *p) {
    p->a = 0xFFFF;
    p->b = 0;
    p->cmd = 0x38;
    p->size = 2;
}

void TFontSmallLobby::send_state() { bswap_fields(); send_subcommand((u8 *)this); }
void *TFontSmallLobby::handle_photon_blast_ready(void *src) { copy_subcommand_header(this, src); return this; }

void clear_player_sub_object_slots(Obj_801D6A18 *p) {
    s32 i;
    for (i = 0; i < 4; i++) {
        p->a[i] = 0;
    }
    p->x10 = 0;
    p->x14 = 0;
}

s32 accumulate_damage_stats(u8 *arg0v, s32 collidable, s32 amount) {
  f32 new_var;
  f32 temp_f1;
  new_var = (f32) amount;
  *((f32 *) (((s8 *) arg0v) + 4)) = (f32) ((*((f32 *) (((s8 *) arg0v) + 4))) + new_var);
  new_var = fn_801D6AB4(arg0v, collidable, amount);
  temp_f1 = new_var;
  *((f32 *) (((s8 *) arg0v) + 0)) = (f32) ((*((f32 *) (((s8 *) arg0v) + 0))) + temp_f1);
  return (s32) temp_f1;
}

#define arg0 ((Rec_801D6AB4 *)arg0v)
f32 fn_801D6AB4(void *arg0v, saddr collidable, s32 amount) {
    f32 v;
    f32 k = (f32)amount;

    v = arg0->a;
    if (((TObjCollidable *)collidable)->test_actor_flags(0x10000000) != 0) {
        v = arg0->b;
    }
    return k * v;
}
#undef arg0

}
