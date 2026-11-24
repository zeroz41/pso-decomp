#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/npc/TNpcPlayer_8034DAA0.h"
#include "pso/unk/text_8034DAA0.h"
#include "pso/npc/TNpcPlayer_8034DC20.h"
#include "pso/unk/TUnk_804F07C8.h"
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
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_80011014.h"

// One TU: TLobby__sub_8034DAA0 (jumptable after the TUnk_804F07C8 vtable in .data),
// the party-area task, TTecReverser::is_active, the 4-player notifiers and the
// partner dialogue code share one .data block (dialogue state, vtable, jumptable).

// One entry per partner remark kind; flag is cleared by clear_partner_dialogue_flags.
struct E_8034E02C { u8 flag; u8 pad[0x35]; };

extern "C" {
E_8034E02C npc_partner_dialogue_state[25] = { 0 };
}

extern "C" {
struct TNpcPlayerTemplateTable { s32 value; u8 remaining[0x9FC]; };
extern TNpcPlayerTemplateTable TNpcPlayer__template_table;

#pragma opt_pointer_analysis on

}

struct Global_8034E5A8 { u8 pad[0x46E]; s8 f46e; u8 rest[0x600 - 0x46F]; };

struct Slot_8034EDC4 {
    s32 a[6];
    s32 b[6];
};

int lbl_805D6EA0;
extern "C" {
void set_arrival_override_coords(u16, s32, f32, f32, f32);
void send_6x24_teleport_player(u16 slot, void *pos, s32 heading);
f32 atan2_float(f32, f32);
void handle_6x69_npc_control(G_NPCControl_6x69 *cmd);

}
void quest_remove_npc_player(u16 client);
extern struct Slot_8034EDC4 partner_dialogue_table[];
extern s32 TNpcPlayer__data_805D5864;
void init_partner_dialogue(void);
void quest_player_look_at_partner(u16 src);
void notify_partner_room_cleared(s32 arg0);
void quest_player_face_actor(u16 src, u16 dst);

// Compiled with -inline off,deferred: the functions are written in reverse of their
// address order (the .text order is the reverse of the source order).

void G_NPCControl_6x69::init() {
    header.subcommand = 0x69;
    header.size = 3;
}

void G_NPCControl_6x69::send() {
    bswap();
    send_subcommand((u8 *)this);
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

void TNpcPlayer::apply_to_battle_player_slot(u16 client, s16 arg1) {
    uaddr player;
    if ((arg1 < 0x10) && ((player = ((uaddr)get_player_by_client_id(client))) != 0U)) {
        ((TObjPlayer *)player)->init_photon_blast(arg1);
    }
}

void TNpcPlayer::end_camera_pan_for_client(u16 client) {
    saddr tmp_player;
    if ((tmp_player = (saddr)get_player_by_client_id(client)) != 0U) {
        ((TObjPlayer *)tmp_player)->end_camera_pan();
    }
}

void TNpcPlayer::update_player_field(u16 client, s32 frames) {
    uaddr player;
    player = (uaddr)get_player_by_client_id(client);
    if (player != 0U) {
        ((TObjPlayer *)player)->protection.set_frames(frames);
    }
}

void TNpcPlayer::reset_player_lobby_model(u16 client) {
    uaddr player;
    player = (uaddr)get_player_by_client_id(client);
    if (player != 0U) {
        ((TObjPlayer *)player)->protection.reset_lobby_model();
    }
}

void init_partner_dialogue(void) {
    s32 i;
    s32 j;
    (*(s32 *)&lbl_805D6EA0) = 0;
    clear_partner_dialogue_flags();
    TNpcPlayer__data_805D5864 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            partner_dialogue_table[i].a[j] = 0;
            partner_dialogue_table[i].b[j] = 0x19;
        }
    }
}

void TNpcPlayer__sub_8034EDB8(void) { lbl_805D6EA0 = 0; }

void TNpcPlayer::send_npc_create(s32 controller_id, s32 npc_type) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.npc_client_id = 0xFFFF;
    cmd.controller_id = controller_id;
    cmd.command = 0;
    cmd.npc_type = npc_type;
    cmd.npc_client_id = 1;
    cmd.send();
}

void TNpcPlayer::send_npc_control_notify_players(s32 controller_id, s32 npc_client_id, s32 npc_type) {
    s32 client;
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
        if ((client = (saddr)get_player_by_client_id(i)) != 0U) {
            TObjPlayer::notify_field1c(client);
            break;
        }
    }
    cmd.send();
}

void TNpcPlayer::create_default_companion(u16 leader, s32 appearance, u8 *pos, s32 heading) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.npc_client_id = 0xFFFF;
    cmd.controller_id = leader;
    cmd.command = 0;
    cmd.npc_type = appearance;
    cmd.npc_client_id = 1;
    set_arrival_override_coords((s32)(1U), heading, *(f32 *)((s8 *)pos + 0), *(f32 *)((s8 *)pos + 4), *(f32 *)((s8 *)pos + 8));
    cmd.send();
    send_6x24_teleport_player(cmd.npc_client_id, pos, heading);
}

void TNpcPlayer::create_companion(u16 leader, u16 slot, s32 appearance, f32 *p, s32 heading) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.controller_id = leader;
    cmd.npc_client_id = 0xFFFF;
    cmd.command = 0;
    cmd.npc_type = appearance;
    cmd.npc_client_id = slot;
    set_arrival_override_coords(cmd.npc_client_id, heading, p[0], p[1], p[2]);
    cmd.send();
    send_6x24_teleport_player(cmd.npc_client_id, p, heading);
}

void TNpcPlayer::send_npc_control_create(u16 controller_id, u16 npc_client_id, s32 npc_type, u8 *pos, s32 heading) {
    s32 client;
    G_NPCControl_6x69 cmd;
    s32 i;
    const Vec *at;
    cmd.init();
    cmd.controller_id = controller_id;
    i = 0;
    cmd.npc_client_id = 0xFFFF;
    cmd.command = 3;
    cmd.npc_type = npc_type;
    for (; i < 4; i++) {
        if ((client = (saddr)get_player_by_client_id(i)) != 0U) {
            TObjPlayer::notify_field1c(client);
            break;
        }
    }
    cmd.npc_client_id = npc_client_id;
    at = (const Vec *)pos;
    set_arrival_override_coords(cmd.npc_client_id, heading, at->x, at->y, at->z);
    cmd.send();
}

void TNpcPlayer::send_npc_stop_6x69(s32 controller_id) {
    G_NPCControl_6x69 cmd;
    cmd.init();
    cmd.controller_id = controller_id;
    cmd.command = 1;
    cmd.send();
}

void TNpcPlayer::send_npc_control_6x69(s32 controller_id) {
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
            TObjPlayer::notify_field1c((saddr)p);
            p->reset_motion_fields();
            p->set_npc_controller((u16)local_client_id);
            p->set_npc_control_state(cmd->npc_type);
            new TNpcPlayer((u16)local_client_id, cmd->npc_client_id, cmd->npc_type, 1, tl_00);
        } else {
            p = create_player_object(cmd->npc_client_id, 4, load_npc_player_template(cmd->npc_type));
            if (p != NULL) {
                p->reset_motion_fields();
                TObjPlayer::notify_field1c((saddr)p);
            }
        }
        break;
    }
}

void TNpcPlayer::send_inter_level_warp_all(s32 value) {
    s32 i;
    TObjPlayer *player;

    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != NULL && player->obj_isState3_324() != 0 && player->get_npc_controller() != 0xFFFF) {
            send_6x21_inter_level_warp(player, value);
        }
    }
}

void TNpcPlayer::apply_to_players(s32 value, void *arg1, s32 heading) {
    s32 client;
    TObjPlayer *player;
    client = 0;
    do {
        player = get_player_by_client_id(client);
        if ((player != NULL) && (player->obj_isState3_324() != 0) && (player->get_npc_controller() != 0xFFFF)) {
            set_arrival_override_coords(player->get_entity_id(), heading, *(f32 *)((s8 *)arg1 + 0), *(f32 *)((s8 *)arg1 + 4), *(f32 *)((s8 *)arg1 + 8));
            send_6x21_inter_level_warp(player, value);
        }
        client += 1;
    } while (client < 4);
}

void TNpcPlayer::send_6x3e_to_all_players(void *pos, s32 angle) {
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
            ((TNpcPlayer *)&cmd)->init_6x3E_packet();
            cmd.header.client_id = player->get_entity_id();
            VecCopy((Vec *)&cmd.pos, (const Vec *)pos);
            cmd.angle = angle;
            cmd.is_near_enemy = near_enemy;
            ((TNpcPlayer *)&cmd)->send_6x3E();
        }
    }
}

void show_partner_chatter_for_key(s16 key) {
    s32 i;
    saddr player;
    for (i = 0; i < 4; i++) {
        player = (saddr)get_player_by_client_id(i);
        if (player && reinterpret_cast<TObjPlayer *>(player)->obj_isState3_324() && key == ((TObjBase *)player)->get_room()
            && !(lbl_805D6EA0 & 2) && (*(Global_8034E5A8 *)&npc_partner_dialogue_state).f46e) {
            TWindowCtrl::open(((TObjBase *)(player))->get_entity_id(), (saddr)(&(*(Global_8034E5A8 *)&npc_partner_dialogue_state).f46e), 0x1B);
        }
    }
}

void notify_partner_room_cleared(s32 arg0) {
    s8 *win = (s8 *)((s32 *)&npc_partner_dialogue_state) + 0x3CC;
    s32 i;
    saddr p;
    i = 0;
    do {
        p = (saddr)get_player_by_client_id(i);
        if (p != 0 && reinterpret_cast<TObjPlayer *>(p)->obj_isState3_324() != 0 && arg0 == ((TObjBase *)p)->get_room() && !(lbl_805D6EA0 & 2) && *win != 0) {
            TWindowCtrl::open(((TObjBase *)(p))->get_entity_id(), (saddr)((void *)((saddr)win)), 0x1B);
        }
        i += 1;
    } while (i < 4);
}

void quest_remove_npc_player(u16 client) {
    TObjPlayer *player;
    player = get_player_by_client_id(client);
    if (player != NULL) {
        TObjPlayer::send_item_pickup_request((saddr)player);
        delete player;
    }
}

void TNpcPlayer::enable_all_battle_ctrl() {
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

void TNpcPlayer::disable_partner_chatter() { lbl_805D6EA0 = (lbl_805D6EA0 | 0x2); }

void TNpcPlayer::enable_partner_chatter() { lbl_805D6EA0 = (lbl_805D6EA0 & 0xfffffffd); }

void TNpcPlayer::send_stop_at_position(u16 id, void *pos, s32 angle) {
    G_StopAtPosition_6x3E cmd;
    s16 near_enemy;
    TObjPlayer *player;
    ((TNpcPlayer *)&cmd)->init_6x3E_packet();
    player = get_player_by_client_id(id);
    near_enemy = 0;
    if (player != NULL) {
        if (player->test_actor_flags(0x100000) != 0) {
            near_enemy = 1;
        }
        cmd.header.client_id = id;
        VecCopy((Vec *)&cmd.pos, (const Vec *)pos);
        cmd.angle = angle;
        cmd.is_near_enemy = near_enemy;
        ((TNpcPlayer *)&cmd)->send_6x3E();
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
    ((TNpcPlayer *)&cmd)->init_6x3E_packet();
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
        ((TNpcPlayer *)&cmd)->send_6x3E();
    } else {
        ((TNpcPlayer *)&cmd)->send_6x3E();
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
    ((TNpcPlayer *)&cmd)->init_6x3E_packet();
    player->test_actor_flags(0x100000);
    angle = (s32)((65536.0 / (2.0 * 3.141592f)) *
                  atan2_float(target->position.x - player->position.x, target->position.z - player->position.z));
    cmd.header.client_id = src;
    VecCopy((Vec *)&cmd.pos, &player->position);
    cmd.angle = angle;
    ((TNpcPlayer *)&cmd)->send_6x3E();
}

void TNpcPlayer::play_effect(int client) {
    saddr player;

    player = (saddr)get_player_by_client_id((u16) client);
    if ((player != 0) && (((TObjChara *)player)->obj_isState2_324() == 0)) {
        TObjPlayer::play_effect_default(player, -1);
    }
}

void TNpcPlayer::send_code_45_to_player(int client) {
    saddr player;

    player = (saddr)get_player_by_client_id((u16) client);
    if ((player != 0) && (((TObjChara *)player)->obj_isState2_324() == 0)) {
        TObjPlayer::send_code_45_1(player);
    }
}

void TNpcPlayer::send_warp_toward_player(u16 id, const Vec *destination) {
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

void clear_partner_dialogue_flags(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        npc_partner_dialogue_state[i].flag = 0;
    }
}

void set_partner_common_remark(s32 kind, const char *text) {
    char buf[0x40];

    if (kind < 25 && strlen(text) < 53) {
        sprintf(buf, "%s", text);
        strcpy((char *)&npc_partner_dialogue_state[kind], buf);
    }
}

void TObjPlayer::update_4p_battle_ctrls() {
    s32 i;
    uaddr player;

    i = 0;
    do {
        if ((player = ((saddr)get_player_by_client_id(i))) != 0) {
            TObjPlayer::send_item_pickup_request(player);
        }
        i += 1;
    } while (i < 4);
}

void TObjPlayer::notify_all_battle_players() {
    s32 tmp_player;
    s32 i;
    uaddr player;

    i = 0;
    do {
        if ((tmp_player = (saddr)get_player_by_client_id(i)) != 0U) {
            TObjPlayer::notify_field1c(tmp_player);
        }
        i += 1;
    } while (i < 4);
}

s32 TTecReverser::is_active() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction() != 0) && !(*(s32 *)((s8 *)this + 0x30) & 0x02040800)) {
        var_r31 = 1;
    }
    return (u8)((u8) var_r31);
}

void TNpcPlayer::AiParams::copy_entry_by_index(s32 arg1) {
    saddr arg0 = (saddr)this;
    s32 temp_r5;
    temp_r5 = arg1 * 0x28;
    ((AiParams *)((u8 *)&TNpcPlayer__template_table.value + temp_r5))->copy((AiParams *)arg0);
}

// Indexed by TLobby::get_instance(); the yaw tables' names are inferred from their accessors.
static const Vec npc_lobby_entry_positions[2] = {{214.0f, 0.0f, -236.0f}, {214.0f, 0.0f, -236.0f}};
static const s32 npc_lobby_entry_yaws[2] = {0x8000, 0x8000};
static const Vec party_position_table[2] = {{200.0f, 0.0f, 320.0f}, {30.0f, 0.0f, 212.0f}};
static const s32 party_yaw_table[2] = {0xE400, 0xC000};

u8 *TNpcPlayer::get_lobby_entry_ptr() {
    return (u8 *)&npc_lobby_entry_positions[TLobby::get_instance()];
}

s32 TNpcPlayer__get_lobby_entry_yaw(void) {
    return npc_lobby_entry_yaws[TLobby::get_instance()];
}

u8 *get_party_position(void) {
    return (u8 *)&party_position_table[TLobby::get_instance()];
}

s32 get_party_yaw(void) {
    return party_yaw_table[TLobby::get_instance()];
}

TUnk_804F07C8::TUnk_804F07C8(TObject *parent) : TObject(parent) {
    s32 slot;
    u8 *player;
    partner_count = 0;
    for (slot = 0; slot < 4; slot++) {
        player = (u8 *)get_player_by_client_id(slot);
        if (player == NULL || reinterpret_cast<TObjPlayer *>(player)->obj_isState3_324() == 0 || ((TObjPlayer *)player)->get_npc_controller() == 0xFFFF) {
            continue;
        }
        new TNpcPlayer(((TObjPlayer *)player)->get_npc_controller(), (u16)slot, ((TObjPlayer *)player)->get_npc_control_state(), tl_00);
        partner_count++;
    }
}

TUnk_804F07C8::~TUnk_804F07C8() {
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

void TUnk_804F07C8::run_task() {  }

void TLobby__sub_8034DAA0(s32 client, u32 status) {
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
