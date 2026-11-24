#include "pso/system/task/TObject.h"
#include "pso/player/PlayerState.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/player/TObjPlayer_80309D80.h"
#include "pso/ui/font/TFontSmallLobby_801C013C.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/player/TUnk_804C4540.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TPlyCharData.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayerCreate.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/network/TLobby.h"
#include "pso/player/PlayerCharDataEntry.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/object/TObjWaitEntryHairMoveSim.h"

extern "C" {
// TObjPlayer.h declares the slot as s32; the call passes the u16 entity id unextended.
s32 sub_801AF454__10TObjPlayerFl(void *, u16);
int copy_player_visual_record(void *dst, void *src);
}

extern u8 *TObjPlayer__shared_model_buffer;

void TObjPlayer::init_model_and_idle_pose() {
    joint_matrices = TObjPlayer__shared_model_buffer + get_entity_id() * 0xC00;
    select_class_action_provider();
    sub_801AF454__10TObjPlayerFl(this, get_entity_id());
    init_idle_animation();
    draw();
}

void TObjPlayer::init_body_parts(void *visual) { update_body_parts(visual); }
void TObjPlayer::reset_body_parts() {  }
void TObjPlayer::free_chara_making() { restore_boss6_player_snapshot(this); ((TCharaMaking *)this)->free_loaded_buffers(); }
void TObjPlayer::update_body_parts(void *visual) { copy_player_visual_record((char*)this + 0x85c, visual); this->model_load_flags = 255; ((TCharaMaking *)this)->update_body_parts(); create_hair_move_sim(this); }

TObjPlayer::~TObjPlayer() {
    release_child_object();
    free_chara_making();
    destroy_child();
    release_pad_binding();
    release_char_data();
    release_area_sync();
    release_technique_caps();
    destroy_owned_object();
    release_motion();
    release_area_placement();
    release_lock_on_cursor();
    release_action_palettes();
    release_pending_action();
    unregister();
    TObjPlayer::free_owned_buffer_b((saddr)&this->attack_state, (s16)(-1));
    destroy__10TObjPlayerFis((saddr)((s8 *)this + 0x754), -1);
    TObjPlayer__sub_801BFAD4(&this->protection, -1);
}

extern "C" {
void TObjPlayer__sub_801BB85C(TObjPlayer *player, u8 *record);
void TObjPlayer__sub_801BBB70(void *, void *);
extern const char *lbl_805D3530;
}

TObjPlayer::TObjPlayer(TObject *parent, TUnk_801D8A4C *src) : TObjChara(parent) {
    ((TObjPlayer *)((char *)this + 1544))->set_vec4_const_wrapper();
    ((TObjPlayer *)((char *)this + 1588))->wrap_update();
    battle_music.reset_and_clear();
    ((TObjPlayer *)((char *)this + 1604))->construct_hurt_timer();
    stick_escape_detector.reset_fields();
    ((TObjPlayer *)((char *)this + 1624))->reset_scale_vector();
    ((TObjPlayer *)((char *)this + 1644))->set_vec3_const_wrapper();
    npc_control.reset();
    ((TObjPlayer *)((char *)this + 1708))->forward_release();
    movement_hold.init();
    ((TObjPlayer *)((char *)this + 1860))->init_vec_record();
    ((TObjPlayer *)((char *)this + 1876))->init_sub_objects();
    TObjPlayer::init_partial((saddr)(((char *)this + 1988)));
    ((TObjPlayer *)((char *)this + 1992))->clear_base();
    attack_state.init();
    TObjPlayer__sub_801C1A00(((char *)this + 2088));
    init_player_telepipe_record(&telepipe);
    TObjPlayer__sub_801BFB4C(&marker_position);
    __ct__8FlagWordFv(((char *)this + 2136));
    TObjPlayer::reset_and_return((saddr)(((char *)this + 3332)));
    ((TObjPlayer *)((char *)this + 3500))->clear_header_struct();
    this->m_name = lbl_805D3530;
    this->init_action_provider();
    this->entity_id = 0;
    this->setup_control_role(7);
    this->update_body_parts(src);
    this->init_player_data(src->stats);
    this->init_data_table_ptr();
}

TObjPlayer::TObjPlayer(TObject *parent, PlayerSyncRecord *record) : TObjChara(parent) {
    ((TObjPlayer *)((char *)this + 1544))->set_vec4_const_wrapper();
    ((TObjPlayer *)((char *)this + 1588))->wrap_update();
    battle_music.reset_and_clear();
    ((TObjPlayer *)((char *)this + 1604))->construct_hurt_timer();
    stick_escape_detector.reset_fields();
    ((TObjPlayer *)((char *)this + 1624))->reset_scale_vector();
    ((TObjPlayer *)((char *)this + 1644))->set_vec3_const_wrapper();
    npc_control.reset();
    ((TObjPlayer *)((char *)this + 1708))->forward_release();
    movement_hold.init();
    ((TObjPlayer *)((char *)this + 1860))->init_vec_record();
    ((TObjPlayer *)((char *)this + 1876))->init_sub_objects();
    TObjPlayer::init_partial((saddr)(((char *)this + 1988)));
    ((TObjPlayer *)((char *)this + 1992))->clear_base();
    attack_state.init();
    TObjPlayer__sub_801C1A00(((char *)this + 2088));
    init_player_telepipe_record(&telepipe);
    TObjPlayer__sub_801BFB4C(&marker_position);
    __ct__8FlagWordFv(((char *)this + 2136));
    TObjPlayer::reset_and_return((saddr)(((char *)this + 3332)));
    ((TObjPlayer *)((char *)this + 3500))->clear_header_struct();
    this->m_name = lbl_805D3530;
    this->init_from_data(record);
    this->setup_control_role(4);
    init_body_parts(&record->visual);
    this->load_char_data(record);
    this->update_position(record);
    clear_lock_on_cursor(record);
    init_model_buffer_and_actions(record);
    init_remote_pad_binding(record);
    init_session_technique_caps(record);
    this->init_from_source(record);
    init_session_area_sync(record);
    init_battle(record);
    TObjPlayer__sub_801BBB70(this, record);
    this->init_class_flags((saddr)record);
    TObjPlayer__sub_801BB85C(this, (u8 *)record);
    this->hp = record->current_hp;
}

TObjPlayer::TObjPlayer(TObject *parent, s32 slot, s32 role, TPlyCharData *record) : TObjChara(parent) {
    ((TObjPlayer *)(((u8 *)this) + 0x608))->set_vec4_const_wrapper();
    ((TObjPlayer *)(((u8 *)this) + 0x634))->wrap_update();
    battle_music.reset_and_clear();
    ((TObjPlayer *)(((u8 *)this) + 0x644))->construct_hurt_timer();
    stick_escape_detector.reset_fields();
    ((TObjPlayer *)(((u8 *)this) + 0x658))->reset_scale_vector();
    ((TObjPlayer *)(((u8 *)this) + 0x66C))->set_vec3_const_wrapper();
    npc_control.reset();
    ((TObjPlayer *)(((u8 *)this) + 0x6AC))->forward_release();
    movement_hold.init();
    ((TObjPlayer *)(((u8 *)this) + 0x744))->init_vec_record();
    ((TObjPlayer *)(((u8 *)this) + 0x754))->init_sub_objects();
    TObjPlayer::init_partial((saddr)((((u8 *)this) + 0x7C4)));
    ((TObjPlayer *)(((u8 *)this) + 0x7C8))->clear_base();
    attack_state.init();
    TObjPlayer__sub_801C1A00((void *) (((u8 *)this) + 0x828));
    init_player_telepipe_record(&telepipe);
    TObjPlayer__sub_801BFB4C(&marker_position);
    __ct__8FlagWordFv((((u8 *)this) + 0x858));
    TObjPlayer::reset_and_return((saddr)((((u8 *)this) + 0xD04)));
    ((TObjPlayer *)(((u8 *)this) + 0xDAC))->clear_header_struct();
    m_name = lbl_805D3530;
    this->init_action_provider();
    this->entity_id = slot;
    this->setup_control_role(role);
    update_body_parts(&record->m_disp_part2);
    sub_801BEE2C(record->m_inventory.m_hp_materials_used);
    sub_801BEE24(record->m_inventory.m_tp_materials_used);
    this->set_power_materials_used(record->get_power_materials_used());
    this->set_mind_materials_used(record->get_mind_materials_used());
    this->set_evade_materials_used(record->get_evade_materials_used());
    this->set_def_materials_used(record->get_def_materials_used());
    this->set_luck_materials_used(record->get_luck_materials_used());
    this->init_player_data(&record->m_stats);
    this->create_lockon_cursor();
    this->init_model_and_idle_pose();
    this->init_control_mode(role);
    init_saved_technique_caps(record);
    init_player_substructs(reinterpret_cast<u8 *>(&record->m_config));
    this->load_character_state(record);
    this->update_if_active();
    assign_owner_ids();
    this->setup_fresh_player_state((u8 *)record);
    this->sub_801BB8B0((u8 *)record);
    TObjPlayer::set_com_card_window((saddr)((this->get_entity_id())));
}


extern const char *TObjPlayer__player_set_class_name;

// C linkage: TObjPlayer_801BC194.cpp declares it unmangled.
extern "C" TObjPlayerSet *find_player_arrival_set(TObjPlayer *player, s32 slot) {
    TObjPlayerSet *set;
    s32 side;

    side = player->get_entrance_id();
    if (side != -1) {
        player->reset_entrance_id();
    } else {
        switch (select_area_entrance(&floor_transition_state)) {
        case 0:
            side = 1;
            break;
        case 1:
        case 2:
            side = 0;
            break;
        case 4:
        default:
            side = 1;
            break;
        }
    }
    for (set = (TObjPlayerSet *)tl_06->m_down; set != NULL; set = (TObjPlayerSet *)set->m_next) {
        if (set->check_value_equals(TObjPlayer__player_set_class_name) != 0 &&
            slot == (s32)set->scale.x && set->set_params[0] == side) {
            return set;
        }
    }
    return NULL;
}

void TObjPlayer::create_active_players() {
    s32 slot;
    PlayerCharDataEntry *entry;
    slot = 0;
    entry = TObjPlayer__char_data_array;
    do {
        if (entry->has_character() != 0) {
            create(slot & 0xFFFF, entry);
        }
        slot++;
        entry++;
    } while (slot < 12);
}

void TObjPlayer::refresh_player_lobby_headers() {
    s32 client;
    TObjPlayer *player;
    PlayerCharDataEntry *entry;
    client = 0;
    entry = TObjPlayer__char_data_array;
    do {
        ((TObjPlayer *)entry)->init_select_txt();
        player = get_player_by_client_id(client);
        if (player != NULL) {
            if (TObjPlayer::is_locally_controlled(player) != 0) {
                ((TObjPlayer *)entry)->copy_lobby_header((saddr)player);
            }
            delete player;
        }
        client++;
        entry++;
    } while (client < 12);
}

TObjPlayer *create_remote_player_object(void *record) {
    decode_remote_player_inventory(record);
    return new TObjPlayer(tl_03, (PlayerSyncRecord *)record);
}

s32 TObjPlayer::create(u32 slot, PlayerCharDataEntry *entry) {
    TObjPlayer *created;

    created = new TObjPlayer(tl_03, slot & 0xFFFF, entry->get_role(), entry->get_char_data());
    ((TLobby *)&created->guild_card_tag)->copy_header_struct(entry->get_lobby_header());
    return (s32)created;
}
