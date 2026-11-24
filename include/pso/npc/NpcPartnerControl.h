#ifndef PSO_NPC_NPCPARTNERCONTROL_H
#define PSO_NPC_NPCPARTNERCONTROL_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

struct G_NPCControl_6x69;

// Spawns a TNpcPlayer partner for every client slot an NPC holds when the party
// area loads, and deletes the NPC players again when it is destroyed.
class TNpcPartnerSpawner : public TObject {
public:
    TNpcPartnerSpawner(TObject *parent);
    virtual ~TNpcPartnerSpawner();
    virtual void run_task();

    u32 partner_count;  // partners the constructor created
};
LAYOUT_ASSERT(TNpcPartnerSpawner_size, sizeof(TNpcPartnerSpawner) == 0x20);

// The common partner remarks, one per remark kind; an empty text means none is set.
struct PartnerRemark {
    char text[0x36];
};

extern PartnerRemark npc_partner_dialogue_state[25];

// Custom partner remarks per player: up to six texts, each keyed by a remark kind (25 = free slot).
struct PartnerDialogueSet {
    const char *text[6];
    s32 kind[6];
};

extern PartnerDialogueSet partner_dialogue_table[4];

const char *get_partner_custom_text(s32 kind, u16 player);
void set_partner_dialogue_override(const char *text, s32 kind, u16 player);
void set_partner_common_remark(s32 kind, const char *text);
void show_partner_chatter_for_key(s16 key);
void quest_remove_npc_player(u16 client);

// Quest slot status opcodes: 0-5 set an ailment flag, 6-9 cast shifta, deband, jellen
// and zalure on the player, 10 restores HP and 11 restores TP.
void apply_player_slot_status(s32 client, u32 status);
// Where and facing which way the NPC partners arrive in the lobby and in the party area.
const Vec *get_npc_lobby_entry_position();
s32 get_npc_lobby_entry_yaw();
const Vec *get_party_position();
s32 get_party_yaw();

// The floor load and release callbacks of the partner dialogue state.
void init_partner_dialogue();
void release_partner_dialogue();

void clear_partner_dialogue_flags();
void notify_partner_room_cleared(s32 room);
void quest_player_look_at_partner(u16 src);
void quest_player_face_actor(u16 src, u16 dst);

void handle_6x69_npc_control(G_NPCControl_6x69 *cmd);
void send_npc_create(s32 controller_id, s32 npc_type);
void send_npc_control_notify_players(s32 controller_id, s32 npc_client_id, s32 npc_type);
void create_default_companion(u16 leader, s32 appearance, Vec *pos, s32 heading);
void create_companion(u16 leader, u16 slot, s32 appearance, Vec *pos, s32 heading);
void send_npc_control_create(u16 controller_id, u16 npc_client_id, s32 npc_type, Vec *pos, s32 heading);
void send_npc_stop_6x69(s32 controller_id);
void send_npc_control_6x69(s32 controller_id);

void apply_to_battle_player_slot(u16 client, s16 photon_blast);
void end_camera_pan_for_client(u16 client);
void update_player_field(u16 client, s32 frames);
void reset_player_lobby_model(u16 client);
void send_inter_level_warp_all(s32 value);
void apply_to_players(s32 value, const Vec *pos, s32 heading);
void send_6x3e_to_all_players(const Vec *pos, s32 angle);
// Deletes every NPC player (control state 3) when the quest or the floor's
// objects are torn down.
void delete_npc_players();
// quest opcodes pl_pkon / pl_pkoff: send 6x1B / 6x1C for every player present.
void enable_pk_mode_for_all_players();
void disable_pk_mode_for_all_players();
void disable_partner_chatter();
void enable_partner_chatter();
void send_stop_at_position(u16 id, const Vec *pos, s32 angle);
void play_effect(int client);
void send_code_45_to_player(int client);
void send_warp_toward_player(u16 id, const Vec *destination);

#endif
