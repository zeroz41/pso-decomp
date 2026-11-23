#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/byteswap.h"
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
#include "pso/player/PlayerSlots.h"

s32 PhotonBlastGauge::fn_801D5DDC() {
    if ((target_count < 0) || (target_count > 0xA)) {
        set_section_index(0);
    }
    return target_count;
}

s16 PhotonBlastGauge::get_valid_index() {
    s16 var_r31;

    var_r31 = blast;
    if (is_valid_index(var_r31) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}

extern "C" {
s32 get_current_floor();
s32 validate_6x39_set_photon_blast_ready_flag(void *);
s32 validate_6x3B_clear_temporary_photon_blast_state_flags(void *);
s32 validate_6x3A_clear_photon_blast_ready_flag(void *);
}

void PhotonBlastGauge::set_section_index(s16 count) {
    s16 var_r4;

    var_r4 = count;
    if ((var_r4 < 0) || (var_r4 > 0xA)) {
        var_r4 = 0;
    }
    target_count = var_r4;
}

void handle_6x3B_clear_temporary_photon_blast_state_flags(saddr src) {
    G_ClearTemporaryPhotonBlastStateFlags_6x3B sp8;
    TObjPlayer *player;
    sp8.init_pkt_cmd_3B();
    sp8.fn_801D6804((void *)src);
    bswap_g_client_id_header(&sp8);
    if (validate_6x3B_clear_temporary_photon_blast_state_flags(&sp8) != 0) {
        player = get_player_by_client_id(sp8.header.client_id);
        if (player != NULL) {
            player->photon_blast_gauge.clear_photon_blast_state();
            if (TObjPlayer::is_locally_controlled(player) != 0) {
                TObjPlayer::update_photon_blast_state();
            }
        }
    }
}

void PhotonBlastGauge::reinit_photon_blast_gauge() {
    G_ClearTemporaryPhotonBlastStateFlags_6x3B sp8;
    clear_photon_blast_state();
    donation.reset_fields();
    sp8.init_pkt_cmd_3B();
    sp8.header.client_id = client_id;
    sp8.update_and_send();
}

void handle_6x3A_clear_photon_blast_ready_flag(saddr src) {
    G_ClearPhotonBlastReadyFlag_6x3A sp8;
    TObjPlayer *player;
    sp8.init_6x3A_packet();
    sp8.clear_photon_blast_ready_flag((void *)src);
    bswap_g_client_id_header(&sp8);
    if (validate_6x3A_clear_photon_blast_ready_flag(&sp8) != 0) {
        player = get_player_by_client_id(sp8.header.client_id);
        if (player != NULL) {
            player->photon_blast_gauge.set_bit1_at_40();
        }
    }
}

void PhotonBlastGauge::send_6x3A_clear_photon_blast_ready_flag() {
    G_ClearPhotonBlastReadyFlag_6x3A pkt;
    TObjChara *chara = (TObjChara *)get_player_by_client_id(client_id);
    if (chara == NULL || chara->obj_isState2_324() == 0) {
        pkt.init_6x3A_packet();
        pkt.header.client_id = client_id;
        pkt.draw_and_send();
    }
}

void handle_6x39_set_photon_blast_ready_flag(saddr src) {
    G_SetPhotonBlastReadyFlag_6x39 sp8;
    s32 temp_r31;
    TObjPlayer *player;
    s32 v;
    sp8.init_6x39_packet();
    sp8.handle_photon_blast_ready((void *)src);
    bswap_g_client_id_header(&sp8);
    if (validate_6x39_set_photon_blast_ready_flag(&sp8) != 0) {
        player = get_player_by_client_id(sp8.header.client_id);
        if ((player != NULL) && (is_current_area_item_enabled() != 0)) {
            temp_r31 = player->get_floor();
            v = get_current_floor();
            if (v == temp_r31) {
                player->photon_blast_gauge.update_ready();
                player->photon_blast_gauge.send_photon_blast_ready();
            }
        }
    }
}

void PhotonBlastGauge::send_6x39_photon_blast_ready() {
    G_SetPhotonBlastReadyFlag_6x39 pk;
    pk.init_6x39_packet();
    pk.header.client_id = client_id;
    pk.update_and_send_60();
}

extern "C" {
s32 validate_6x38_donate_to_photon_blast(void *);
}

s32 PhotonBlastGauge::is_ready() {
    if ((donation.get_field_04() < 3) && (charge > 10.0f) && (donation.get_state() < 0)) {
        return 1;
    }
    return 0;
}

void PhotonBlastGauge::reset_targets() {
    donation.set_target_index(0);
    donation.set_target_count(0);
    check_flag_at_40();
}

void handle_6x38_donate_to_photon_blast(saddr src) {
    G_DonateToPhotonBlast_6x38 cmd;
    TObjPlayer *player;
    cmd.fn_801D698C();
    cmd.copy_packet_header_6x38((void *)src);
    cmd.bswap_fields();
    if (validate_6x38_donate_to_photon_blast(&cmd) != 0) {
        player = get_player_by_client_id(cmd.header.client_id);
        if ((player != NULL) && (is_current_area_item_enabled() != 0)) {
            if (get_current_floor() == player->get_floor()) {
                TObjPlayer::create_photon_blast_party_effects(cmd.header.client_id);
            }
        }
    }
}

void PhotonBlastGauge::draw_party_label(TObjChara *target, u16 effect) {
    G_DonateToPhotonBlast_6x38 sp8;

    set_flag_40_bit5();
    subtract_photon_blast_charge(10.0f);
    donation.set_target_index(8);
    donation.fn_801D671C(1);
    TWindowCtrl::create_party_effect(target->get_entity_id(), effect);
    if ((target == NULL) || (target->obj_isState2_324() == 0)) {
        sp8.fn_801D698C();
        sp8.header.client_id = target->get_entity_id();
        sp8.target_client_id = effect;
        sp8.send_state();
    }
}

extern "C" {
void add_photon_blast_chain_charge(PhotonBlastGauge *gauge, f32 amount);
void TFontSmallLobby__sub_80152F28(void *);
}

s32 PhotonBlastGauge::subtract_photon_blast_charge(f32 amount) {
    f32 charge = this->charge;
    if (charge < 100.0f) {
        this->charge = charge - amount;
        if (this->charge < 0.0f) {
            this->charge = 0.0f;
            return 0;
        }
    } else {
        this->charge = charge - amount;
        charge = this->charge;
        if (charge < 100.0f) {
            send_6x3A_clear_photon_blast_ready_flag();
        } else if (charge < 400.0f) {
            update_field_40();
        }
    }
    return 1;
}

extern "C" {
void add_photon_blast_chain_charge(PhotonBlastGauge *gauge, f32 amount) {
    f32 charge = gauge->charge;
    if (charge < 100.0f) {
        gauge->charge = charge + amount;
        if (gauge->charge >= 100.0f) {
            gauge->send_6x39_photon_blast_ready();
        }
    } else if (charge < 400.0f) {
        gauge->charge = charge + amount;
        if (gauge->charge >= 400.0f) {
            gauge->charge = 400.0f;
            gauge->update_ready();
            gauge->fn_801D677C();
        }
    }
}
}

void PhotonBlastGauge::add_photon_blast_charge(f32 amount) {
    f32 temp_f0;
    temp_f0 = charge;
    if (temp_f0 < 100.0f) {
        charge = temp_f0 + amount;
        if (charge >= 100.0f) {
            charge = 100.0f;
            send_6x39_photon_blast_ready();
        }
    }
}

void PhotonBlastGauge::send_photon_blast_ready() {
    void *tmp_player;
    if ((tmp_player = get_player_by_client_id(get_type())) != 0U) {
        ((TObjPlayer *)tmp_player)->play_photon_blast_feedback();
    }
}

void PhotonBlastGauge::update_if_ready() { if (fn_801D67AC() != 0) { update_ready(); } }
void PhotonBlastGauge::reset_photon_blast_gauge() {
    s32 i;
    fn_801D67C8();
    set_section_index(0);
    for (i = 0; i < 10; i++) {
        TFontSmallLobby__sub_80152F28(&targets[i]);
    }
    clear_charge();
    clear_photon_blast_state();
    donation.reset_fields();
}
void PhotonBlastGauge::reset_state() {
    s32 i;
    s32 k;
    s8 *fp;
    i = 0;
    client_id = 0xFFFF;
    blast = 0;
    target_count = 0;
    countdown = 0;
    frame_step = 1.0f;
    complete_threshold = 0.0f;
    do {
        TFontSmallLobby__sub_80152F28(&targets[i]);
        i++;
    } while (i < 10);
    charge = 0.0f;
    ((FlagWord *)&flags)->reset();
    for (k = 0, fp = blast_levels; k < 6; k++, fp++) {
        *fp = 0;
    }
    donation.reset_fields();
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
}

PhotonBlastGauge *PhotonBlastGauge::construct_pb_controller() {
    __construct_array(targets, fn_80152EF8, 0, 4, 0xA);
    __ct__8FlagWordFv(&flags);
    donation.init_reset_fields();
    reset_state();
    return this;
}

int PhotonBlastGauge::is_valid_index(s16 blast) {
    u8 var_r4;
    var_r4 = 0;
    if (((blast >= 0) && (blast < 6)) || (blast == -1)) {
        var_r4 = 1;
    }
    return var_r4;
}

void Obj_801D67D4::reset_fields() { state = 0; count = 0; }
void PhotonBlastGauge::set_bit1_at_40() { ((FlagWord *)&flags)->clear(2); }
void *G_ClearPhotonBlastReadyFlag_6x3A::clear_photon_blast_ready_flag(void *src) { copy_subcommand_header(this, src); return this; }
void PhotonBlastGauge::update_ready() { ((FlagWord *)&flags)->set(2); }

s32 Obj_801D67D4::get_state() { return state; }
s32 Obj_801D67D4::get_field_04() { return count; }
void PhotonBlastGauge::check_flag_at_40() { ((FlagWord *)&flags)->clear(32); }
void Obj_801D67D4::set_target_count(s32 v) { count = v; }
void Obj_801D67D4::set_target_index(s32 v) { state = v; }
void Obj_801D67D4::fn_801D671C(int n) { count = count + n; }
void PhotonBlastGauge::set_flag_40_bit5() { ((FlagWord *)&flags)->set(32); }
void PhotonBlastGauge::update_field_40() { ((FlagWord *)&flags)->clear(16); }
void PhotonBlastGauge::fn_801D677C() { ((FlagWord *)&flags)->set(16); }
u16 PhotonBlastGauge::get_type() { return client_id; }

s32 PhotonBlastGauge::fn_801D67AC() {
    return charge >= 100.0f;
}

void PhotonBlastGauge::fn_801D67C8() { blast = 6; }
void *Obj_801D67D4::init_reset_fields() { reset_fields(); return this; }
void *G_ClearTemporaryPhotonBlastStateFlags_6x3B::fn_801D6804(void *src) { copy_subcommand_header(this, src); return this; }
void G_ClearTemporaryPhotonBlastStateFlags_6x3B::init_pkt_cmd_3B() { header.subcommand = 59; header.size = 1; }
void G_ClearTemporaryPhotonBlastStateFlags_6x3B::update_and_send() { bswap_g_client_id_header(this); send_subcommand(this); }
void G_ClearPhotonBlastReadyFlag_6x3A::init_6x3A_packet() { header.subcommand = 58; header.size = 1; }
void G_ClearPhotonBlastReadyFlag_6x3A::draw_and_send() { bswap_g_client_id_header(this); send_subcommand(this); }
void G_SetPhotonBlastReadyFlag_6x39::init_6x39_packet() { header.subcommand = 57; header.size = 1; }
void G_SetPhotonBlastReadyFlag_6x39::update_and_send_60() { bswap_g_client_id_header(this); send_subcommand(this); }
void G_DonateToPhotonBlast_6x38::bswap_fields() { header.bswap(); bswap_16(&target_client_id); bswap_16((u16 *)&unused); }

void *G_DonateToPhotonBlast_6x38::copy_packet_header_6x38(void *src) { G_DonateToPhotonBlast_6x38 *s = (G_DonateToPhotonBlast_6x38 *)src; copy_subcommand_header(this, src); target_client_id = s->target_client_id; unused = s->unused; return this; }

void G_DonateToPhotonBlast_6x38::fn_801D698C() {
    target_client_id = 0xFFFF;
    unused = 0;
    header.subcommand = 0x38;
    header.size = 2;
}

void G_DonateToPhotonBlast_6x38::send_state() { bswap_fields(); send_subcommand(this); }
void *G_SetPhotonBlastReadyFlag_6x39::handle_photon_blast_ready(void *src) { copy_subcommand_header(this, src); return this; }

extern "C" {
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
