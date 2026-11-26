#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_H

#include <stddef.h>
#include "types.h"
struct NJS_POINT2;
#include "pso/system/task/TObject.h"

struct CreationTextureCacheEntry;
struct OSContext;
class TAdGuideTxtGC;
class TAdChrSelPlayerGC;
class TPlyCharData;
struct CharacterFile;
struct CharacterSaveRecord;
struct TItemData;

struct TAdChrSelASlotGC;
class TAdSelectCurGC;
class TWindowBase;
struct TWindowMenu;
struct TWindowMessageYesNo;
class TAdFadeGC;

struct GuildCardSaveData;

// The split-screen players' buffers: a TPlyCharData and a save record for each of players 0-3.
struct CharacterBufferTable {
    TPlyCharData *char_data[4];
    CharacterSaveRecord *records[4];
};

// The 0x11C bytes of the system card file (the part after the card header).
struct SystemSaveData {
    s32 fields_equal(SystemSaveData *other);
    u32 checksum;
    s16 music_stream_gain;
    s8 cue_stream_gain;
    s8 language;
    s32 clock_offset_frames;
    s16 field_c;
    s16 field_e;
    u8 data_10[0x110 - 0x10];
    u8 serial_number[8];
    s32 serial_seed;
};

LAYOUT_ASSERT(SystemSaveData_size, sizeof(SystemSaveData) == 0x11C);

struct TAdSinglePlyChrSelectGC : public TObject {
    static const char *class_name;
    static s32 selection_index;
    explicit TAdSinglePlyChrSelectGC(TObject *parent);
    virtual ~TAdSinglePlyChrSelectGC();
    void sub_802D4E08();
    static s32 can_pay_fee();
    virtual void render();
    s32 state_timer;                       // 0x1C  frames spent in the current state
    s32 state;                             // 0x20  index into the run_task handler table
    s32 prev_state;                        // 0x24
    TAdChrSelASlotGC *slot_window;         // 0x28
    TAdSelectCurGC *cursor;                // 0x2C
    TAdChrSelPlayerGC *player;             // 0x30
    TAdGuideTxtGC *guide;                  // 0x34
    static void try_load_system_file();
    static s32 wait_for_card_load(s32 chan);
    static void format_challenge_stage_times(s32 lobby, s32 challenge_id);
    static void free_singleton_805D65C0();
    static s32 check_slot_flags(s32 slot, u32 mask);
    void cleanup();
    virtual void run_task();
    static s32 get_chr_select_state();
    static u8 *get_global_state();
    static int get_state();
    static void free_resources();
    static void set_active_disconnect_count(int a0);
    static u16 get_active_disconnect_count();
    static void destroy();
    static s32 create_if_key_pressed();
    static int get_game_mode();
    s32 is_both_confirmed();
    static void copy_name(s32 chan);
    static void set_card_disk_id(s32 chan);
    s32 init_char_slot_record();
    static s32 is_ready();
    static u16 get_split_fourth_place_count(int client);
    static u16 get_split_third_place_count(int client);
    static u16 get_split_first_place_count(int client);
    static u16 get_online_disconnect_count(int client);
    static u16 get_online_fourth_place_count(int client);
    static u16 get_online_third_place_count(int client);
    static u16 get_online_second_place_count(int client);
    static u16 get_online_first_place_count(int client);
    static s32 load_player_by_slot(s32 chan);
    static s32 verify_system_file();
    static s32 load_save_from_card();
    static s32 verify_card_player_data();
    static s32 poll_memcard_status();
    s32 has_valid_slot();
    static int get_selection();
    static void set_global_flags(s32 flags);
    static saddr get_instance();
    static void set_player_index(int a0);
    static void set_save_slot(int a0);
    static void clear_flags(s32 flags);
    static s32 check_flag(s32 flags);
    static void set_state(int a0);
    static void set_chr_select_state(int a0);
    void*init_guild_card_tag();
    void clear_inventory_slot();
    static s32 draw_window_bg(s32 chan, s32 filename, s32 buf, s32 blocks);
    static s32 load_player(s32 chan, s32 filename, s32 buf, s32 blocks);
    static s32 load_player_slot(s32 chan, const char *file_name, void *buffer);
    s32 try_acquire_slot();
    static void init_entry_tables(void* _w0);
    static s32 is_active();
    void reset_creation_parts();
    static s32 map_button_code(s32 code);
    static s32 count_remaining_slots();
    static s32 has_matching_entry(void *character);
    static CreationTextureCacheEntry *find_free_slot();
    static s32 evict_char_entries(s32 limit);
    static void free_global();
    static void render(void *self);
    TWindowMenu *create_chr_warp(NJS_POINT2 *pos);
    void close_and_change_scene();
    void handle_card_select();
    void handle_card_select2();
    void update_card_input();
    void update();
    void handle_menu_selection();
    void handle_slot_selection();
    void finish_character_selection_transition();
    void run_state_4();
    void run_state_3();
    void run_state_2();
    void run_state_1();
    static int get_flag_count();
    static int get_selected_count();
    static int get_data();
    TWindowMenu *chr_menu;                 // 0x38  play / meseta / delete / back menu of an occupied slot
    TWindowBase *card_check_message;       // 0x3C  shown while the card is polled for the guild card file
    TWindowBase *card_load_message;        // 0x40  shown while the guild card file is read
    TWindowMessageYesNo *create_character_prompt; // 0x44  empty slot: create a character?
    TWindowMessageYesNo *yes_no_prompt;    // 0x48  transferred character confirmation
    TWindowMessageYesNo *meseta_prompt;    // 0x4C  menu entry 1, costs 10000 meseta
    TWindowMessageYesNo *replace_prompt;   // 0x50  menu entry 3
    TAdFadeGC *fade_task;                  // 0x54
    s32 last_cursor_index;                 // 0x58
    s32 menu_choice;                       // 0x5C  chr_menu entry that decides where the scene goes next
    static void free_all_resources();
    s32 load_and_verify_character_save(char *desc);
    u8 *copy_character_data(u8 *source);
    static void reset_quest_id();
    static void set_quest_download_server(int quest_download_server);
    static void init_logo_state(s32 state);
    static void noop();
    static void run_frame();
    static TPlyCharData *get_char_index(unsigned int index);
    static TPlyCharData *get_char_table_entry(int index);
    static void run_save_load_sequence();
    static s32 init();
    static s32 load_character_from_card(int);
    static void copy_slot_data(void *, void *);
    static s32 is_entry_equal(void *, void *);
    static s32 count_char_diffs(void *, void *);
    static s32 save_character_to_card();
    static s32 forward_to_global_instance(TItemData *item);
    static s32 increment_frame();
    static s32 get_player_count();
    static s32 save_online_character();
    static void reset_character_data();
    static s32 all_players_loaded();
    static void alloc_char_buffers();
    static s32 apply_loaded_character(int verify_only);
    static void build_default_save_file();
    static void build_save_file();
    static s32 check_page_cross(CharacterFile *src_file, int src_slot, CharacterFile *dst_file, int dst_slot);
    static s32 check_system_file_status();
    static void clear_load_buffers();
    static void clear_slot_body(int i);
    static void clear_slot_entry(int i);
    static void * copy_char_slot_data(void * a0, void * a1);
    static s32 copy_character_to_slot(CharacterFile *src_file, int src_slot, CharacterFile *dst_file, int dst_slot);
    static void copy_chr_slots_from_request();
    static CharacterFile *copy_save_data(CharacterFile *to, CharacterFile *from);
    static void encrypt_save_data(CharacterFile *file);
    static void create_instance();
    static s32 encrypt_and_save();
    static s32 encrypt_save_and_write();
    static s32 free();
    static s32 free_buffer();
    static void free_callbacks();
    static s32 free_data();
    static s32 get_type(void* p);
    static void increment_counter();
    static void increment_counters();
    static s32 init_and_register(CharacterFile *source);
    static void init_char_select_globals();
    static s32 load_character_from_card();
    static s32 load_chr_select_slot();
    static s32 load_player_data();
    static s32 load_pso_system(int chan);
    static s32 load_pso_system_slot();
    static s32 load_selected_char();
    static s32 load_selected_character();
    static void open_confirm_window();
    static void prepare_save_data();
    static void refresh_char_slots();
    static void release_all();
    static void render_frame();
    static void reset_save_header();
    static void save_character_file(int use_primary);
    static void set_id(void* p, int v);
    static s32 setup_player_battle_ctrls();
    static s32 update_elapsed_time(CharacterSaveRecord *record);
    static void update_pair(void* p);
    static s32 update_play_time();
    static s32 verify_save_checksum(int keep_on_mismatch);
    static void verify_save_checksum();
    static s32 write_encrypted_save();
    static void alloc_char_records(CharacterBufferTable *table);
    static s32 check_ready();
    static s32 check_slot_swap_allowed(CharacterFile *src_file, int src_slot, CharacterFile *dst_file, int dst_slot);
    static s32 check_system_load_result();
    static void clear_entry(int i);
    static s32 compare_save_headers(CharacterSaveRecord *record_a, CharacterSaveRecord *record_b, CharacterFile *file_a, CharacterFile *file_b);
    static void decrypt_char_data(CharacterFile *file);
    static void free_char_data_slots(CharacterBufferTable *table);
    static TPlyCharData *get_entry(int i);
    static int get_serial_seed();
    static s32 is_entry_valid(CharacterFile *self, int i);
    static s32 is_same_slot_entry(CharacterFile *src_file, int src_slot, CharacterFile *dst_file, int dst_slot);
    static s32 is_slot_active(unsigned int slot);
    static s32 load_character_and_wait();
    static s32 load_player_and_wait();
    static s32 load_system_file(s32 chan, s32 *out_value);
    static s32 load_system_file_blocking();
    static s32 load_system_file_flag();
    static s32 setup(int quest_download_server);
    static s32 start_load();
    static s32 swap_characters(s32 src_slot, s32 i);
    static s32 try_confirm_selection();
    static s32 try_move_char(int src_slot, int dst_slot);
};

LAYOUT_ASSERT(TAdSinglePlyChrSelectGC_size, sizeof(TAdSinglePlyChrSelectGC) == 0x60);
LAYOUT_ASSERT(TAdSinglePlyChrSelectGC_slot_window_offset, offsetof(TAdSinglePlyChrSelectGC, slot_window) == 0x28);
LAYOUT_ASSERT(TAdSinglePlyChrSelectGC_cursor_offset, offsetof(TAdSinglePlyChrSelectGC, cursor) == 0x2C);
LAYOUT_ASSERT(TAdSinglePlyChrSelectGC_player_offset, offsetof(TAdSinglePlyChrSelectGC, player) == 0x30);
LAYOUT_ASSERT(TAdSinglePlyChrSelectGC_guide_offset, offsetof(TAdSinglePlyChrSelectGC, guide) == 0x34);
LAYOUT_ASSERT(TAdSinglePlyChrSelectGC_menu_choice_offset, offsetof(TAdSinglePlyChrSelectGC, menu_choice) == 0x5C);

// Memory-card save state of the character select scene (.sbss of TAdSinglePlyChrSelectGC_801FBF54.cpp,
// in definition order). The buffers hold heap addresses as words: every test of them against 0 is a cmplwi.
extern CharacterFile *card_character_save_buffer;
extern CharacterFile *secondary_card_character_save_buffer;
extern TPlyCharData *selected_character_data;
extern CharacterSaveRecord *active_character_save_record;
extern GuildCardSaveData *guild_card_save_payload;
extern SystemSaveData *system_save_payload;
extern SystemSaveData *secondary_card_system_save_payload;
extern s32 card_load_sequence_state;
extern saddr character_save_card_slot;
extern saddr card_load_channel;
extern saddr character_save_file_block_count;
extern saddr guild_card_save_file_block_count;
extern saddr system_save_card_channel;
extern saddr system_save_file_block_count;
extern u8 *character_save_file_buffer;
extern u8 *guild_card_save_file_buffer;
extern u8 *system_save_file_buffer;
extern s32 chr_select_scene_state;

// Checks the character file loaded from card slot A / B against the system file's card serial.
s32 check_slot_a_card_save(void);
s32 check_slot_b_card_save(void);
extern s32 chr_select_game_mode;
extern s32 chr_select_save_slot;

class TAdTitleTexGC;
struct NJS_POINT2;
extern "C" void fn_802D50B8(TAdTitleTexGC *title, const NJS_POINT2 *first, const NJS_POINT2 *second, const NJS_POINT2 *third);
#endif
