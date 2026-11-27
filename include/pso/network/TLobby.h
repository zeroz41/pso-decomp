#ifndef PSO_NETWORK_TLOBBY_H
#define PSO_NETWORK_TLOBBY_H

#include "types.h"
#include "pso/network/LobbyRuleSettings.h"

struct NJS_SPRITE;
struct BmlResource;
struct AsyncFileReadRequest;
struct EnemySetRecord;
struct TChallenge;
class TLobbyIdleTimer;
class TEnemyTaskList;
template <size_t size> struct TPlyText;
class TPlyJoinGame;
struct PlayerSyncRecord;
struct G_ClientIDHeader;
struct extended_game_command_header;
struct FloorObjectSetRow;
class GameListEntry;
class QuestListEntry;
template <typename T, int num_entries, int num_pad_entries> class TMenuList;
struct GuildCardRecord;

struct ShortMailEntry;
struct player_stats;
struct AttackParams;
struct SymbolChatPayload;
struct TAdDialingMessageWindow;
struct ActorParamBlock;
union BattleMovementParams;
#include "pso/audio/AdxCallbacks.h"
#include "pso/audio/GcrnaError.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemData.h"

struct NJS_TEXLIST;
class TObjPlayer;
class TProtocol;
class TUserAns;
class TWindowMenuIconLine;
struct TWindowMessage;
struct TPlyChallenge;
struct TRecvInfoBoard;
class TRecvDownload;
struct TRecvChoiceSearchOptions;
struct ChoiceSearchResultList;
s32 LoadBmlExec(BmlResource *bml, const char *name);

struct AdxbDecoder;
struct SjRingBuffer;
struct GcrnaStream;

struct TObjTombstone;
struct TObjTombstoneSpot;
class TPlyJoinLobbyEntry;

// A lobby server's host name and port.
struct LobbyServerAddress {
    const char *host;
    s32 port;
};

struct TLobby : public TObject {
    static int is_flag_set(void *p);
    TLobby(TObject *parent);
    virtual ~TLobby();
    virtual void run_task();
    void try_close(void *);
    static void on_game_player_add(TPlyJoinLobbyEntry *entries, int leader_id, int disable_udp);
    void close_window();
    static s32 get_filtered_event_theme();
    static s32 clear_record_flags_a();
    static s32 clear_record_flags_b();
    static void free_nodes_with_id(const void *root);
    static void dispatch_by_index(s32 index);
    static void open_scroll_text_window(saddr src);
    void render();
    static void copy_player_records(TPlyChallenge *records, s32 count);
    static s32 get_option_state();
    static void install_game_join_handlers();
    static s32 get_instance();
    static void close_result_windows();
    static s32 get_game_mode();
    void collect_active_card_ids();
    static void send_status_packet();
    // Empty free half of set_ending_callback in the scene load/free tables
    static int get_lobby_flag();
    void process_and_dispatch_packet();
    void bswap_6xa2_fields();
    void *build_6x06_guild_card_packet();
    static void clear_counters();
    static void disconnect_protocol();
    static char *init_serial_access();

    static s32 is_idle();
    static void clear_counter();
    static void clear_quest_state();
    static void reset_quest_counter();
    static void set_cleanup_flag();
    static void reset_door_state();
    static void set_flag_and_update();
    static void free_objects();
    static void reset_counter();
    static u32 clamp_min_drop(u32 min, u32 max);
    static void free_boss4rock();
    void bswap_vec3();
    static int rebuild_entry();
    static int init_sub_state();
    static void *create_tl05_object(TObjPlayer *player);
    s32 get_id();
    static void clear_flag_bit2();
    static int get_com_card_data();
    static s32 get_clamped_time_limit();
    static s32 is_value_out_of_range(s32 seed);
    static void free_chr_select_slots();
    void set_flag_and_clear_download();
    void open_keyboard();
    void request_change_game_mode();
    void enter_game_mode_change();
    void enter_chg_game_mode();
    static void init_once(TRecvInfoBoard *info_board);
    static char *get_info_board_text();  // the player's own info board text (CharacterSaveRecord)
    static TAdDialingMessageWindow *create_dialing_message_window(const char *message, u32 delay);
    static void send_game_character();
    static void open_udp_socket_for_player(s32 client);
    static void send_6x71_to_player(s32 client_id);
    static void send_6x6D_item_state(s32 client_id);
    static void make_players();
    static void drain_deferred_packets();
    void add_status_disp_entry(s32 name, s32 id);
    // Takes one 13 download chunk of the quest .dat/.bin being downloaded.
    static void handle_quest_download_chunk(TRecvDownload &download);
    static void send_challenge_records(TChallenge *challenge);
    static void set_fade_params(void (*callback)());
    void copy_record_entry(saddr src);

    void update_alloc_size();
    static void create_tasks();
    static void clear_session_buffers();
    static s32 run_lobby_load_tables();
    static s32 check_disconnect_conditions();
    static void reset_and_invoke();
    static void clear_callback_and_reset_keyboard();
    static void set_keyboard_mode(int a0);
    // Empties the com card list on floor load and unload.
    static void reset_state();
    static void reset_lobby_state(char *time);
    // Receive handlers for DA (lobby event), D8 (info boards), C4 (choice search results), C0 (choice search options).
    static void set_lobby_event_theme(int theme);
    static void handle_info_board(TRecvInfoBoard *info_board);
    static void handle_choice_search_results(ChoiceSearchResultList *results);
    static void handle_choice_search_options(TRecvChoiceSearchOptions *options);
    static void send_battle_mode_data(void * _w0);
    static void clear_quest_vm_flag();
    static void free_luker_object();
    static int is_warning_aram_load_done();
    static int get_lobby_count();
    static void set_lobby_id(int a0);
    static void set_area_total(int a0);
    void bswap_enemy_set_rows(u32 size);
    static void init_floor_encounter_sections();
    static void handle_msg_type1_for_idle_slots();
    static s32 handle_msg_type2(s32 floor);
    static s32 handle_msg_type1(s32 floor);
    static void init_id_tables();
    static s32 is_scene_ready();
    static void reset_story_select();
    static void reset_story_select(void* p);
    static s32 update_key_machine();
    static void free_global_buffers();
    static void clear_flag400();
    void build_trade_item_list();
    static void send_modify_trade_proposal(s8 what, s32 item_id, s32 amount);
    static void send_trade_proposal_result(s8 what, s8 result);
    static s32 write_zero_padded_block(void *arg0p);
    static s32 init_floor_enemy_count(s32 floor, u8 *source, s32 size);
    static s32 load_object_set_entries(s32 floor, u8 *rows, s32 byte_size);
    static void append_color_code(s32 color);
    static s32 parse_color_code(char *s);
    void destroy_matching_children();
    static void send_compressed_packet_6c(s32 client_id);
    static void send_cmd_6B(s32 client_id);
    u8 *create_new_floor_windows();
    static void append_float_value(s32 reg);
    static void append_int_param(s32 reg);
    static void send_simple_mail(s32 target_card_id, void *message);
    void*get_com_card_list();
    s32 get_lobby_id();
    static int get_short_mail_ctrl();
    static void clear_lobby_flag();
    static void send_find_user_self_tag(s32 gc_num);
    static GuildCardRecord *get_com_card_entry(int a0);
    // Empties the com card list and clears its flag.
    static void reset_com_card_list();
    static s32 assign_player_id(void *);
    static void handle_battle_result(int client, s32 local);
    static void close_and_play_effect(int client, s32 local);
    // Members other code calls by their mangled names.
    static void add_lobby_members(TPlyJoinLobbyEntry *, int, int, int);
    static void *adxf_open(unsigned int, int);
    static void bswap_and_handle_packet(void *packet, int size);
    static void bswap_header_fields(extended_game_command_header *header);
    static void bswap_player_data(PlayerSyncRecord *record);
    static void close_all_windows(void *);
    static void close_all_windows();
    static void close_and_send_text_list();
    static void close_and_set_state_12();
    static void close_and_set_state_13(int msg);
    static void close_com_card_window();
    static void close_menu_windows();
    static void construct_global_arrays();
    static void copy_all_data(int, int);
    static void *copy_member_record(void *, void *);
    static void *copy_symbol_chat_entry(void *, void *);
    static void *create_quest_col_apc_inw(void *, void *);
    static void create_warp_menu();
    static void destroy_all_objects();
    static void destroy_child_recursive(TObject *task, TObject *object);
    static void destroy_join_entries();
    static void destroy_lobby_ui();
    static void disable_window_flags(void*);
    static s32 get_progress_info(void *, void *, void *, void *);
    static const char *get_seq_phase(int);
    static void handle_com_card();
    static void handle_comcard_window();
    static void handle_create_game_window();
    static void handle_game_join(TPlyJoinGame *);
    static void handle_game_list_select();
    static void handle_lobby_enter(TPlyJoinLobbyEntry *, int, int, int, int, int, int, int);
    static void handle_login_result(unsigned int);
    static void handle_regist_check(int);
    static void handle_register_name_result(int);
    static void handle_register_result(int);
    static void handle_short_list_input();
    static void handle_state(int);
    static void handle_team_select();
    static void handle_verify_result(unsigned int);
    static void handle_warp_menu_input();
    static void init_buffers(int floor, u8 *quest);
    static void init_player_window_effect();
    static s32 load_floor_enemy_group_entries(s32 idx, FloorObjectSetRow *src, u32 size);
    static void on_lobby_player_add(TPlyJoinLobbyEntry *entries, int leader_id);
    static void open_city_warp_menu();
    static void open_download_list_window(int entry_count, TMenuList<QuestListEntry, 30, 0> &quest_list);
    static s32 open_hard_keyboard(s32 client_id);
    static void open_information_list(int entry_count, GameListEntry *entries, GameListEntry &entry_0);
    static void open_keyboard_window();
    static void open_lobby_warp_menu();
    static void open_make_team_window(int);
    static void open_menu_window();
    static void open_ship_block_select_menu(int entry_count, GameListEntry *entries, GameListEntry &entry_0);
    static void open_warp_menu();
    static void process_deferred_player_setup();
    static void queue_static_object_destruction();
    static s8 read_byte_advance();
    static void rebuild_all(u8 *quest);
    static void remove_player(unsigned int, int, int);
    static void request_game_list();
    static void reset(int);
    static void reset_random_enemies_mode(TObject *fade);
    static void reset_state(int msg);
    static void reset_state_flags();
    static void retire_lobby_player(int, int);
    static void return_to_main_menu();
    static void run_join_lobby_connect(TObject *parent);
    static void send_6x6E_sync_game_state(int);
    static void send_6x70_player_data(int);
    static void send_logout();
    static void send_packet_60(void *packet);
    static void send_position_update();
    static void send_room_change(int);
    static void send_selected_character();
    static void set_menu_mode_0();
    static void set_menu_mode_1();
    static void set_menu_mode_2();
    static void set_player_count(int);
    static void show_seq_phase_message(int);
    static void update();
    static void update_and_reset(u8 *quest);
    static void update_block_jump_list();
    static void update_card_list_window();
    static void update_com_card_window();
    static void update_game_list_menu();
    static void update_idle_timeout(TLobbyIdleTimer *);
    static void update_make_team_menu();
    static void update_menu_window();
    static void update_player_window();
    static void update_scroll_close();
    static void update_ship_select_window();
    static void update_short_list();
    static void update_state();
    static saddr get_object_count(void*);
    static u8 is_ready(void *);
    static void send_modify_trade_proposal(int);
    static void set_mode(void *, int);
    static void set_split_screen_flag();
    static void update_all(int);

    // Lobby state shared by the lobby screens.
    static TProtocol *protocol_instance;
    static TWindowMenuIconLine *list_window;
    static s32 lobby_state;  // the run_task state
    static TWindowMessage *current_dialog_window;
    static TWindowMessage *download_list_window;
    static TWindowMessage *join_entry_window_obj;
    static TWindowMessage *card_list_window;
    static s32 event_theme_id;
    static s32 lobby_number;
    static s32 deferred_player_setup_state;
    static s32 join_state_flag;
    static TLobby *join_lobby_controller;
    static s16 pending_member_count;
    static s32 idle_timeout_active;
    static s32 block_number;  // from the 0x67 lobby join packet
    static s32 join_lobby_idle_timer;
    static s32 player_setup_pending;
    static s16 pending_local_client_id;  // add_lobby_members' client id, for construct_lobby_players
    static s32 date_seconds;
    static s32 card_list_selected_index;
    static s32 room_change_pending;  // set by send_room_change, cleared when the lobby is entered
    static s32 login_pending_flag;
    static s32 connection_lost;
    static s32 lobby_entered_flag;
    static s32 lobby_block_high;  // high byte of the 0x67 lobby join packet's block number; never read
    static u32 join_entries_dtor_registration[3];
};

void call_funcs_reverse(void *table, unsigned int size);
void send_6x75_quest_flag(u16 flag, s16 action, s32 difficulty);
void send_6x75_quest_flag_cur_difficulty(u16 flag, s16 action);

void destroy_global_object();

void destroy_download_server(TObject *fade);

void queue_destruction_and_cleanup(TObject *fade);

void release_scene_resources();

void send_challenge_with_value(TChallenge *challenge, s32 window_mode);

void init_fadeout_state(void (*callback)());

LAYOUT_ASSERT(TLobby_size, sizeof(TLobby) == 0x1C);
// The object set entry new ground items take their placement from, and
// whether placing one shows the drop effect.
extern void *item_object_set_data;
extern s32 item_ground_placement_enabled;

// 1 when the local player stands on another floor than the current one (never in split screen).
s32 is_local_player_off_current_floor();

class TPlyCharData;

void set_first_inventory_item_flag(TPlyCharData *chr);

class TQuestThread;
// The AB (quest stats response) handler: starts the quest thread at `label`.
TQuestThread *create_quest_stats_thread(s32 label);

char *get_lobby_name();

struct CompressedSyncPacket;
struct PlayerSyncPacket;

// 6x6B-6x6E: the compressed game-state blocks a joining client receives; 6x70: a player's state and inventory.
void handle_6x6B_sync_game_state(CompressedSyncPacket *pkt);
void handle_6x6C_sync_game_state(CompressedSyncPacket *pkt);
void handle_6x6D_sync_game_state(CompressedSyncPacket *pkt);
void handle_6x6E_sync_game_state(CompressedSyncPacket *pkt);
void handle_6x70_sync_player_disp_and_inventory(PlayerSyncPacket *pkt);

// The battle rule settings (0x24 bytes) the TLobby rule accessors read and write.

class TObject;

const char *get_online_message_text(s32 id);
u8 *init_idle_timeout_timer(u8 *timer, TObject *parent);
void queue_join_entry_exit_on_input(TObject *task);
// A5: the quest info text, shown in the card list window.
void show_card_list_message(TPlyText<288> &info);
void show_join_entry_message(s32 id);
void handle_game_list(int entry_count, GameListEntry *entries, GameListEntry &entry_0);

// One player record of a lobby join (construct_lobby_players builds the players from them).
struct LobbyPlayerEntry {
    u8 tag[8];
    u32 ip_addr;
    saddr client_id;
    char name[16];
    u8 char_data[0x41C];
};
void construct_lobby_players(LobbyPlayerEntry *records, s32 count, int self_id, s32 unused);

class TPlyCharData;

TPlyCharData *copy_char_data(TPlyCharData *dst, TPlyCharData *src);

u8 *get_password_input_buffer(void);

extern TPlyChallenge lobby_player_status_records[];

u8 *copy_join_lobby_entry(u8 *dst, u8 *src);

saddr get_connection_message_text(s32 id);
u8 *get_access_key_input_buffer(void);
u8 *get_raw_serial_input_buffer(void);

extern TObject *lobby_player_construction_window;

#endif
