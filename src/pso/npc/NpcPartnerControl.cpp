#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecReverser.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerTaskEffects.h"

// One TU: apply_player_slot_status (jumptable after the TNpcPartnerSpawner vtable in .data),
// TNpcPartnerSpawner, TObjBase::is_active, the 4-player notifiers and the
// partner dialogue code share one .data block (dialogue state, vtable, jumptable).

PartnerRemark npc_partner_dialogue_state[25] = { 0 };

#pragma opt_pointer_analysis on

PartnerDialogueSet partner_dialogue_table[4];
int partner_chatter_flags;
// Compiled with -inline off,deferred: the functions are written in reverse of their
// address order (the .text order is the reverse of the source order).

void G_NPCControl_6x69::init() {
    header.subcommand = 0x69;
    header.size = 3;
}

void G_NPCControl_6x69::send() {
    bswap();
    send_subcommand(this);
}

void G_NPCControl_6x69::bswap() {
    header.bswap();
    bswap_16(&controller_id);
    bswap_16(&npc_client_id);
    bswap_16((u16 *)&command);
    bswap_16((u16 *)&npc_type);
}

void TObjPlayer::set_npc_controller(u16 client) { npc_control.controller_client_id = client; }

void TObjPlayer::set_npc_control_state(s32 state) { npc_control.state = state; }

s32 TObjPlayer::get_npc_control_state() { return npc_control.state; }

void apply_to_battle_player_slot(u16 client, s16 photon_blast) {
    TObjPlayer *player;
    if (photon_blast < 0x10 && (player = get_player_by_client_id(client)) != NULL) {
        player->init_photon_blast(photon_blast);
    }
}

void end_camera_pan_for_client(u16 client) {
    TObjPlayer *player;
    if ((player = get_player_by_client_id(client)) != NULL) {
        player->end_camera_pan();
    }
}

void update_player_field(u16 client, s32 frames) {
    TObjPlayer *player = get_player_by_client_id(client);
    if (player != NULL) {
        player->protection.set_frames(frames);
    }
}

void reset_player_lobby_model(u16 client) {
    TObjPlayer *player = get_player_by_client_id(client);
    if (player != NULL) {
        player->protection.reset_lobby_model();
    }
}

void init_partner_dialogue() {
    s32 i;
    s32 j;
    partner_chatter_flags = 0;
    clear_partner_dialogue_flags();
    quest_npc_visual_pending = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            partner_dialogue_table[i].text[j] = 0;
            partner_dialogue_table[i].kind[j] = 0x19;
        }
    }
}

void release_partner_dialogue() { partner_chatter_flags = 0; }

void send_npc_create(s32 controller_id, s32 npc_type) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.npc_client_id = 0xFFFF;
    cmd.controller_id = controller_id;
    cmd.command = 0;
    cmd.npc_type = npc_type;
    cmd.npc_client_id = 1;
    cmd.send();
}

void send_npc_control_notify_players(s32 controller_id, s32 npc_client_id, s32 npc_type) {
    TObjPlayer *player;
    G_NPCControl_6x69 cmd;
    s32 i;
    cmd.init();
    cmd.controller_id = controller_id;
    i = 0;
    cmd.npc_client_id = 0xFFFF;
    cmd.command = 3;
    cmd.npc_type = npc_type;
    cmd.npc_client_id = npc_client_id;
    for (; i < 4; i++) {
        if ((player = get_player_by_client_id(i)) != NULL) {
            TObjPlayer::send_enable_pk_mode(player);
            break;
        }
    }
    cmd.send();
}

void create_default_companion(u16 leader, s32 appearance, Vec *pos, s32 heading) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.npc_client_id = 0xFFFF;
    cmd.controller_id = leader;
    cmd.command = 0;
    cmd.npc_type = appearance;
    cmd.npc_client_id = 1;
    set_arrival_override_coords(1, heading, pos->x, pos->y, pos->z);
    cmd.send();
    send_6x24_teleport_player(cmd.npc_client_id, pos, heading);
}

void create_companion(u16 leader, u16 slot, s32 appearance, Vec *pos, s32 heading) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.controller_id = leader;
    cmd.npc_client_id = 0xFFFF;
    cmd.command = 0;
    cmd.npc_type = appearance;
    cmd.npc_client_id = slot;
    set_arrival_override_coords(cmd.npc_client_id, heading, pos->x, pos->y, pos->z);
    cmd.send();
    send_6x24_teleport_player(cmd.npc_client_id, pos, heading);
}

void send_npc_control_create(u16 controller_id, u16 npc_client_id, s32 npc_type, Vec *pos, s32 heading) {
    TObjPlayer *player;
    G_NPCControl_6x69 cmd;
    s32 i;
    cmd.init();
    cmd.controller_id = controller_id;
    i = 0;
    cmd.npc_client_id = 0xFFFF;
    cmd.command = 3;
    cmd.npc_type = npc_type;
    for (; i < 4; i++) {
        if ((player = get_player_by_client_id(i)) != NULL) {
            TObjPlayer::send_enable_pk_mode(player);
            break;
        }
    }
    cmd.npc_client_id = npc_client_id;
    set_arrival_override_coords(cmd.npc_client_id, heading, pos->x, pos->y, pos->z);
    cmd.send();
}

void send_npc_stop_6x69(s32 controller_id) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.controller_id = controller_id;
    cmd.command = 1;
    cmd.send();
}

void send_npc_control_6x69(s32 controller_id) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.controller_id = controller_id;
    cmd.command = 2;
    cmd.send();
}

void handle_6x69_npc_control(G_NPCControl_6x69 *cmd) {
    u16 controller_id;
    TObjPlayer *p;
    s32 i;
    cmd->bswap();
    controller_id = cmd->controller_id;
    if (controller_id == 0xFFFF) {
        return;
    }
    switch (cmd->command) {
    case 0:
        if (cmd->npc_client_id == local_client_id) {
            return;
        }
        if (cmd->npc_client_id == 0xFFFF) {
            return;
        }
        if (controller_id == local_client_id) {
            p = create_player_object(cmd->npc_client_id, 5, load_npc_player_template(cmd->npc_type));
            if (p == NULL) {
                return;
            }
            p->reset_motion_fields();
            p->set_npc_controller((u16)local_client_id);
            p->set_npc_control_state(cmd->npc_type);
            new TNpcPlayer((u16)local_client_id, cmd->npc_client_id, cmd->npc_type, tl_00);
        } else {
            p = create_player_object(cmd->npc_client_id, 4, load_npc_player_template(cmd->npc_type));
            if (p != NULL) {
                p->reset_motion_fields();
            }
        }
        break;
    case 1:
        p = get_player_by_client_id(controller_id);
        if (p != NULL && p->obj_isState3_324() != 0) {
            p->set_npc_controller(0xFFFF);
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != NULL && p->obj_isState3_324() != 0) {
                p->set_npc_controller(cmd->controller_id);
            }
        }
        break;
    case 3:
        if (cmd->npc_client_id == 0xFFFF) {
            return;
        }
        if (controller_id == local_client_id) {
            p = create_player_object(cmd->npc_client_id, 5, load_npc_player_template(cmd->npc_type));
            if (p == NULL) {
                return;
            }
            TObjPlayer::send_enable_pk_mode(p);
            p->reset_motion_fields();
            p->set_npc_controller((u16)local_client_id);
            p->set_npc_control_state(cmd->npc_type);
            new TNpcPlayer((u16)local_client_id, cmd->npc_client_id, cmd->npc_type, 1, tl_00);
        } else {
            p = create_player_object(cmd->npc_client_id, 4, load_npc_player_template(cmd->npc_type));
            if (p != NULL) {
                p->reset_motion_fields();
                TObjPlayer::send_enable_pk_mode(p);
            }
        }
        break;
    }
}

void send_inter_level_warp_all(s32 value) {
    s32 i;
    TObjPlayer *player;

    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != NULL && player->obj_isState3_324() != 0 && player->get_npc_controller() != 0xFFFF) {
            send_6x21_inter_level_warp(player, value);
        }
    }
}

void apply_to_players(s32 value, const Vec *pos, s32 heading) {
    s32 client;
    TObjPlayer *player;
    client = 0;
    do {
        player = get_player_by_client_id(client);
        if ((player != NULL) && (player->obj_isState3_324() != 0) && (player->get_npc_controller() != 0xFFFF)) {
            set_arrival_override_coords(player->get_entity_id(), heading, pos->x, pos->y, pos->z);
            send_6x21_inter_level_warp(player, value);
        }
        client += 1;
    } while (client < 4);
}

void send_6x3e_to_all_players(const Vec *pos, s32 angle) {
    G_StopAtPosition_6x3E cmd;
    s32 i;
    TObjPlayer *player;
    s16 near_enemy;
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != NULL && player->obj_isState3_324() != 0 && player->get_npc_controller() != 0xFFFF) {
            near_enemy = 0;
            if (player->test_actor_flags(0x100000) != 0) {
                near_enemy = 1;
            }
            cmd.init();
            cmd.header.client_id = player->get_entity_id();
            VecCopy((Vec *)&cmd.pos, pos);
            cmd.angle = angle;
            cmd.is_near_enemy = near_enemy;
            cmd.send();
        }
    }
}

void show_partner_chatter_for_key(s16 key) {
    s32 i;
    TObjPlayer *player;
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player && player->obj_isState3_324() && key == player->get_room()
            && !(partner_chatter_flags & 2) && npc_partner_dialogue_state[21].text[0]) {
            TWindowCtrl::open(player->get_entity_id(), npc_partner_dialogue_state[21].text, 0x1B);
        }
    }
}

void notify_partner_room_cleared(s32 room) {
    char *remark = npc_partner_dialogue_state[18].text;
    s32 i;
    TObjPlayer *player;
    i = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL && player->obj_isState3_324() != 0 && room == player->get_room() && !(partner_chatter_flags & 2) && *remark != 0) {
            TWindowCtrl::open(player->get_entity_id(), remark, 0x1B);
        }
        i += 1;
    } while (i < 4);
}

void quest_remove_npc_player(u16 client) {
    TObjPlayer *player;
    player = get_player_by_client_id(client);
    if (player != NULL) {
        TObjPlayer::send_disable_pk_mode(player);
        delete player;
    }
}

void delete_npc_players() {
    s32 i;
    TObjPlayer *player;
    i = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL && player->obj_isState3_324() != 0) {
            delete player;
        }
        i += 1;
    } while (i < 4);
}

void disable_partner_chatter() { partner_chatter_flags |= 2; }

void enable_partner_chatter() { partner_chatter_flags &= ~2; }

void send_stop_at_position(u16 id, const Vec *pos, s32 angle) {
    G_StopAtPosition_6x3E cmd;
    s16 near_enemy;
    TObjPlayer *player;
    cmd.init();
    player = get_player_by_client_id(id);
    near_enemy = 0;
    if (player != NULL) {
        if (player->test_actor_flags(0x100000) != 0) {
            near_enemy = 1;
        }
        cmd.header.client_id = id;
        VecCopy((Vec *)&cmd.pos, pos);
        cmd.angle = angle;
        cmd.is_near_enemy = near_enemy;
        cmd.send();
    }
}

void quest_player_look_at_partner(u16 src) {
    G_StopAtPosition_6x3E cmd;
    TObjPlayer *player;
    TObjPlayer *partner;
    s32 i;
    s16 near_enemy;
    s32 angle;
    player = get_player_by_client_id(src);
    if (player == NULL) {
        return;
    }
    if (player->obj_isState3_324() != 0) {
        for (i = 0; i < 4; i++) {
            if (i != src) {
                partner = get_player_by_client_id(i);
                if (partner != NULL && partner->obj_isState3_324() == 0) {
                    break;
                }
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (i != src) {
                partner = get_player_by_client_id(i);
                if (partner != NULL && partner->obj_isState3_324() != 0) {
                    break;
                }
            }
        }
    }
    if (partner == NULL) {
        return;
    }
    cmd.init();
    near_enemy = 0;
    if (player->test_actor_flags(0x100000) != 0) {
        near_enemy = 1;
    }
    angle = (s32)((65536.0 / (2.0 * 3.141592f)) *
                  atan2_float(partner->position.x - player->position.x, partner->position.z - player->position.z));
    cmd.header.client_id = src;
    VecCopy((Vec *)&cmd.pos, &player->position);
    cmd.angle = angle;
    cmd.is_near_enemy = near_enemy;
    if (near_enemy == 1) {
        cmd.send();
    } else {
        cmd.send();
    }
}

void quest_player_face_actor(u16 src, u16 dst) {
    G_StopAtPosition_6x3E cmd;
    TObjPlayer *player;
    TObjPlayer *target;
    s32 angle;
    player = get_player_by_client_id(src);
    if (player == NULL) {
        return;
    }
    target = get_player_by_client_id(dst);
    if (target == NULL) {
        return;
    }
    cmd.init();
    player->test_actor_flags(0x100000);
    angle = (s32)((65536.0 / (2.0 * 3.141592f)) *
                  atan2_float(target->position.x - player->position.x, target->position.z - player->position.z));
    cmd.header.client_id = src;
    VecCopy((Vec *)&cmd.pos, &player->position);
    cmd.angle = angle;
    cmd.send();
}

void play_effect(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);

    if (player != NULL && player->obj_isState2_324() == 0) {
        send_impose_hold(player, -1);
    }
}

void send_code_45_to_player(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);

    if (player != NULL && player->obj_isState2_324() == 0) {
        send_release_hold(player);
    }
}

void send_warp_toward_player(u16 id, const Vec *destination) {
    TObjPlayer *npc = get_player_by_client_id(id);
    TObjPlayer *local_player = get_player_by_client_id(local_client_id);
    if (local_player == NULL || id == 0) {
        return;
    }
    if (npc->get_npc_controller() != 0xFFFF) {
        send_6x55_intra_map_warp(id, destination,
            (65536.0 / (2.0 * 3.141592f)) * atan2_float(destination->x - local_player->position.x,
                                                       destination->z - local_player->position.z));
    }
}

void clear_partner_dialogue_flags() {
    s32 i;
    for (i = 0; i < 25; i++) {
        npc_partner_dialogue_state[i].text[0] = 0;
    }
}

void set_partner_common_remark(s32 kind, const char *text) {
    char buf[0x40];

    if (kind < 25 && strlen(text) < 53) {
        sprintf(buf, "%s", text);
        strcpy(npc_partner_dialogue_state[kind].text, buf);
    }
}

void disable_pk_mode_for_all_players() {
    s32 i;
    TObjPlayer *player;

    i = 0;
    do {
        if ((player = get_player_by_client_id(i)) != NULL) {
            TObjPlayer::send_disable_pk_mode(player);
        }
        i += 1;
    } while (i < 4);
}

void enable_pk_mode_for_all_players() {
    TObjPlayer *player;
    s32 i;

    i = 0;
    do {
        if ((player = get_player_by_client_id(i)) != NULL) {
            TObjPlayer::send_enable_pk_mode(player);
        }
        i += 1;
    } while (i < 4);
}

s32 TObjBase::is_active() {
    int active;

    active = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction() != 0) && !(actorFlags & 0x02040800)) {
        active = 1;
    }
    return (u8)active;
}

void TNpcPlayer::AiParams::copy_entry_by_index(s32 index) {
    npc_player_ai_templates[index].copy(this);
}

// Indexed by TLobby::get_instance().
static const Vec npc_lobby_entry_positions[2] = {{214.0f, 0.0f, -236.0f}, {214.0f, 0.0f, -236.0f}};
static const s32 npc_lobby_entry_yaws[2] = {0x8000, 0x8000};
static const Vec party_position_table[2] = {{200.0f, 0.0f, 320.0f}, {30.0f, 0.0f, 212.0f}};
static const s32 party_yaw_table[2] = {0xE400, 0xC000};

const Vec *get_npc_lobby_entry_position() {
    return &npc_lobby_entry_positions[TLobby::get_instance()];
}

s32 get_npc_lobby_entry_yaw() {
    return npc_lobby_entry_yaws[TLobby::get_instance()];
}

const Vec *get_party_position() {
    return &party_position_table[TLobby::get_instance()];
}

s32 get_party_yaw() {
    return party_yaw_table[TLobby::get_instance()];
}

TNpcPartnerSpawner::TNpcPartnerSpawner(TObject *parent) : TObject(parent) {
    s32 slot;
    TObjPlayer *player;
    partner_count = 0;
    for (slot = 0; slot < 4; slot++) {
        player = get_player_by_client_id(slot);
        if (player == NULL || player->obj_isState3_324() == 0 || player->get_npc_controller() == 0xFFFF) {
            continue;
        }
        new TNpcPlayer(player->get_npc_controller(), (u16)slot, player->get_npc_control_state(), tl_00);
        partner_count++;
    }
}

TNpcPartnerSpawner::~TNpcPartnerSpawner() {
    s32 i;
    TObjPlayer *player;
    i = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            if (player->is_script_controlled() != 0) {
                delete player;
            } else if (player->obj_isState3_324() != 0 && player->get_npc_controller() == 0xFFFF) {
                delete player;
            }
        }
        i += 1;
    } while (i < 4);
}

void TNpcPartnerSpawner::run_task() {  }

void apply_player_slot_status(s32 client, u32 status) {
    TObjPlayer *player;
    player = get_player_by_client_id(client);
    if (player == NULL) {
        return;
    }
    switch (status) {
    case 0:
        player->set_actor_flags(1);
        break;
    case 1:
        player->set_actor_flags(2);
        break;
    case 2:
        player->set_actor_flags(4);
        break;
    case 3:
        player->set_actor_flags(0x20);
        break;
    case 4:
        player->set_actor_flags(8);
        break;
    case 5:
        player->set_actor_flags(0x10);
        break;
    case 6: {
        StatStatusReceipt shifta = {9, 20.0f};
        player->apply_attack_stat_status(&shifta);
        break;
    }
    case 7: {
        StatStatusReceipt deband = {10, 20.0f};
        player->apply_defense_stat_status(&deband);
        break;
    }
    case 8: {
        StatStatusReceipt jellen = {11, 20.0f};
        player->apply_attack_stat_status(&jellen);
        break;
    }
    case 9: {
        StatStatusReceipt zalure = {12, 20.0f};
        player->apply_defense_stat_status(&zalure);
        break;
    }
    case 10:
        player->set_hp_clamped(player->get_hpmax());
        break;
    case 11:
        player->set_tp(obj_getS16_2BA((u8 *)player));
        break;
    }
}
void set_partner_dialogue_override(const char *text, s32 kind, u16 player) {
    s32 i;
    if (player >= 4) {
        return;
    }
    for (i = 0; i < 6; i++) {
        if (partner_dialogue_table[player].kind[i] == 25 || kind == partner_dialogue_table[player].kind[i]) {
            partner_dialogue_table[player].kind[i] = kind;
            partner_dialogue_table[player].text[i] = text;
            return;
        }
    }
}
const char *get_partner_custom_text(s32 kind, u16 player) {
    s32 i;
    if (player >= 4) {
        return NULL;
    }
    for (i = 0; i < 6; i++) {
        if (kind == partner_dialogue_table[player].kind[i]) {
            return partner_dialogue_table[player].text[i];
        }
    }
    return NULL;
}
