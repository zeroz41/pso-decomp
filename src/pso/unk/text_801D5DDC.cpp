#include "types.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

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
int TFontSmallLobby__sub_801C01BC(void *p);
s32 send_photon_blast_ready__15TFontSmallLobbyFv(void *);
s32 handle_photon_blast_ready__15TFontSmallLobbyFv(void *, void *);
s32 validate_6x39_set_photon_blast_ready_flag(void *);
void send_6x39_photon_blast_ready(u16 *p);
s32 obj_isState2_324__9TObjCharaFv();
void send_6x3A_clear_photon_blast_ready_flag(u16 *arg0);
s32 is_locally_controlled__10TObjPlayerFPv(int);
s32 TFontSmallLobby__sub_801D6804(void *, void *);
s32 validate_6x3B_clear_temporary_photon_blast_state_flags(void *);
s32 clear_photon_blast_ready_flag__15TFontSmallLobbyFv(void *, void *);
s32 validate_6x3A_clear_photon_blast_ready_flag(void *);
void TFontSmallLobby::set_section_index(s16 arg1) {
    s16 var_r4;

    var_r4 = arg1;
    if ((var_r4 < 0) || (var_r4 > 0xA)) {
        var_r4 = 0;
    }
    *(s16 *)((s8 *)this + 4) = var_r4;
}
}
void handle_6x39_set_photon_blast_ready_flag(s32 arg0);
void handle_6x3B_clear_temporary_photon_blast_state_flags(s32 arg0);
void reinit_photon_blast_gauge(u16 *arg0);
void handle_6x3A_clear_photon_blast_ready_flag(s32 arg0);
void handle_6x3B_clear_temporary_photon_blast_state_flags(s32 arg0) {
    struct { s16 a; u16 b; } sp8;
    s32 temp_r3;
    ((TFontSmallLobby *)(&sp8))->init_pkt_cmd_3B();
    TFontSmallLobby__sub_801D6804(&sp8, (void *)arg0);
    TFontSmallLobby__sub_801C01BC((&sp8));
    if (validate_6x3B_clear_temporary_photon_blast_state_flags(&sp8) != 0) {
        temp_r3 = (s32)get_player_by_client_id(sp8.b);
        if (temp_r3 != 0) {
            ((TObjPlayer *)(temp_r3 + 0x4AC))->clear_photon_blast_state();
            if (is_locally_controlled__10TObjPlayerFPv(temp_r3) != 0) {
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

void handle_6x3A_clear_photon_blast_ready_flag(s32 arg0) {
    struct { s16 a; u16 b; } sp8;
    u8 *player;
    ((TFontSmallLobby *)(&sp8))->init_6x3A_packet();
    clear_photon_blast_ready_flag__15TFontSmallLobbyFv(&sp8, (void *)arg0);
    TFontSmallLobby__sub_801C01BC((&sp8));
    if (validate_6x3A_clear_photon_blast_ready_flag(&sp8) != 0) {
        player = (u8 *)get_player_by_client_id(sp8.b);
        if (player != 0) {
            ((TFontSmallLobby *)(player + 0x4AC))->set_bit1_at_40();
        }
    }
}

void send_6x3A_clear_photon_blast_ready_flag(u16 *arg0) {
    struct Pkt_801D5FC0 pkt;
    if (((u8 *)get_player_by_client_id((*arg0))) == NULL || obj_isState2_324__9TObjCharaFv() == 0) {
        ((TFontSmallLobby *)(&pkt))->init_6x3A_packet();
        pkt.id = *arg0;
        ((TFontSmallLobby *)(&pkt))->draw_and_send();
    }
}

void handle_6x39_set_photon_blast_ready_flag(s32 arg0) {
    struct { s16 a; u16 b; } sp8;
    s32 temp_r31;
    s32 player;
    s32 v;
    ((TFontSmallLobby *)(&sp8))->init_6x39_packet();
    handle_photon_blast_ready__15TFontSmallLobbyFv(&sp8, (void *)arg0);
    TFontSmallLobby__sub_801C01BC((&sp8));
    if (validate_6x39_set_photon_blast_ready_flag(&sp8) != 0) {
        player = (s32)get_player_by_client_id(sp8.b);
        if ((player != 0) && (are_items_enabled_here() != 0)) {
            temp_r31 = ((TObjPlayer *)player)->get_field_3e4();
            v = get_current_floor();
            if (v == temp_r31) {
                ((TFontSmallLobby *)(player + 0x4AC))->update_ready();
                send_photon_blast_ready__15TFontSmallLobbyFv((void *)(player + 0x4AC));
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

extern "C" {
s32 TFontSmallLobby__sub_801D698C(void *);
s32 validate_6x38_donate_to_photon_blast(void *);
}
void handle_6x38_donate_to_photon_blast(s32 arg0);
extern const f32 lbl_805DC3D8;

s32 TFontSmallLobby::is_ready() {
    u8 *arg0 = (u8 *)this;
    if ((((TFontSmallLobby *)(arg0 + 0x4C))->get_field_04() < 3) && (*(f32 *)((s8 *)arg0 + 0x3C) > lbl_805DC3D8) && (((TFontSmallLobby *)(arg0 + 0x4C))->get_state() < 0)) {
        return 1;
    }
    return 0;
}

void TFontSmallLobby::reset_targets() {
    s32 arg0 = (s32)this;
    ((TFontSmallLobby *)(arg0 + 0x4C))->set_target_index(0);
    ((TFontSmallLobby *)(arg0 + 0x4C))->set_target_count(0);
    ((TFontSmallLobby *)arg0)->check_flag_at_40();
}
void handle_6x38_donate_to_photon_blast(s32 arg0) {
    Cmd_801D61A0 cmd;
    s32 player;
    TFontSmallLobby__sub_801D698C(&cmd);
    ((TFontSmallLobby *)(&cmd))->copy_packet_header_6x38((void *)arg0);
    ((TFontSmallLobby *)(&cmd))->bswap_fields();
    if (validate_6x38_donate_to_photon_blast(&cmd) != 0) {
        player = (s32)get_player_by_client_id(cmd.client);
        if ((player != 0) && (are_items_enabled_here() != 0)) {
            if (get_current_floor() == ((TObjPlayer *)player)->get_field_3e4()) {
                TObjPlayer::create_photon_blast_party_effects(cmd.client);
            }
        }
    }
}
extern "C" {

void draw_party_label__15TFontSmallLobbyFiUis(s32 arg0, u32 arg1, s16 arg2);
s32 subtract_photon_blast_charge(TFontSmallLobby *arg0, f32 farg0);
void TFontSmallLobby__sub_801D671C(void *a0, int a1);
s32 set_flag_40_bit5__15TFontSmallLobbyFv();
s32 create_party_effect__11TWindowCtrlFPvPv(s16, s16);
s16 get_entity_id(u32);

struct Sp801D6230_801d6230 { s16 f0; s16 fA; s16 fC; };

void draw_party_label__15TFontSmallLobbyFiUis(s32 font_small_lobby, u32 arg1, s16 arg2) {
    Sp801D6230_801d6230 sp8;

    set_flag_40_bit5__15TFontSmallLobbyFv();
    subtract_photon_blast_charge((TFontSmallLobby *)((u8 *)font_small_lobby), lbl_805DC3D8);
    ((TFontSmallLobby *)(font_small_lobby + 0x4C))->set_target_index(8);
    TFontSmallLobby__sub_801D671C((void *)(font_small_lobby + 0x4C), 1);
    create_party_effect__11TWindowCtrlFPvPv(get_entity_id(arg1), arg2);
    if ((arg1 == 0U) || (((s32 (*)(u32)) obj_isState2_324__9TObjCharaFv)(arg1) == 0)) {
        TFontSmallLobby__sub_801D698C((void *) &sp8);
        sp8.fA = get_entity_id(arg1);
        sp8.fC = arg2;
        ((TFontSmallLobby *)((s32 *) &sp8))->send_state();
    }
}
}
