#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

struct CreationTextureCacheEntry;
struct OSContext;
class TAdGuideTxtGC;
class TAdChrSelPlayerGC;
class TPlyCharData;
struct CharacterFile;
struct CharacterSaveRecord;

struct TAdChrSelASlotGC;
class TAdSelectCurGC;
class TWindowBase;
struct TWindowMenu;
struct TWindowMessageYesNo;
class TAdFadeGC;

// The blocks TAdSinglePlyChrSelectGC::init_windows constructs in a 0xE28C-byte buffer.
struct CardList_801FFDFC {
    u8 pad_0[0xC0];
    u8 entries[0xD2][0x100];
};

struct CardFile_801FFD78 {
    u32 pad_0;
    CardList_801FFDFC list;
    u8 tags[0x1C][0x90];
};

struct TAdSinglePlyChrSelectGC : public TObject {
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
    static void wake_load_thread(s32 channel, OSContext *context);
    static s32 send_at_ms_command(s32 arg0);
    static s32 send_at_error_correction_cmd(s32 arg0);
    static s32 send_at_compression_cmd(s32 arg0);
    static s32 send_atx_command(s32 arg0);
    static BOOL send_modem_hangup(BOOL final);
    static void free_singleton_805D65C0();
    static s32 check_slot_flags(s32 arg0, u32 arg1);
    void cleanup();
    virtual void run_task();
    static s32 get_chr_select_state();
    static u8 *get_global_state();
    static int get_state();
    static void free_resources();
    static void set_slot(int a0);
    static u16 get_char_select_slot();
    static void destroy();
    static s32 create_if_key_pressed();
    static int get_game_mode();
    s32 is_both_confirmed();
    static void copy_name(s32 arg0);
    static void set_card_disk_id(s32 arg0);
    s32 init_char_slot_record();
    static s32 is_ready();
    static u16 get_card_window_field(int client);
    static u16 get_card_window_status(int client);
    static u16 get_card_state(int client);
    static u16 get_card_flag(int client);
    static u16 get_card_field(int client);
    static u16 get_card_status(int client);
    static u16 get_card_value(int client);
    static u16 get_card_field_21a8(int client);
    s32 append_inventory_item(saddr arg1);
    static s32 load_player_by_slot(s32 chan);
    static s32 verify_system_file(void* _w0);
    static s32 load_save_from_card();
    s32 fields_equal(void *arg1);
    static s32 verify_card_player_data();
    s32 poll_memcard_status();
    s32 has_valid_slot();
    void clear_inventory_slot_by_index(s32 i);
    static int get_selection();
    static void set_global_flags(s32 arg0);
    static saddr get_instance();
    static void set_player_index(int a0);
    static void set_save_slot(int a0);
    static void clear_flags(s32 arg0);
    static s32 check_flag(s32 arg0);
    static void set_state(int a0);
    static void set_chr_select_state(int a0);
    void*init_guild_card_tag();
    void clear_inventory_slot();
    static s32 draw_window_bg(s32 chan, s32 arg1, s32 arg2, s32 arg3);
    static s32 load_player(s32 chan, s32 arg1, s32 arg2, s32 arg3);
    static s32 load_player_slot(s32 chan, const char *file_name, void *buffer);
    s32 try_acquire_slot();
    static void init_entry_tables(void* _w0);
    static s32 is_active();
    void reset_creation_parts();
    static s32 map_button_code(s32 arg0);
    static s32 count_remaining_slots();
    static s32 has_matching_entry(void *arg0);
    static CreationTextureCacheEntry *find_free_slot();
    static s32 evict_char_entries(s32 arg0);
    void update_char_panels();
    static void free_global();
    static void render(void *self);
    TWindowMenu *create_chr_warp(s32 pos);
    void close_and_change_scene();
    void handle_card_select();
    void handle_card_select2();
    void update_card_input();
    void update();
    void handle_menu_selection();
    void handle_slot_selection();
    void finish_character_selection_transition();
    void sub_802D4570();
    void sub_802D4664();
    void sub_802D4730();
    void sub_802D486C();
    static int get_flag_count();
    static int get_selected_count();
    static int get_data();
    static void permute_save_blocks(void* stream, const u8* source, u8* destination, u32 size);
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
    static void remove_matching_entries(s32 arg0);
    u8 *copy_character_data(u8 *arg1);
    static void reset_quest_id();
    static void set_quest_download_server(int quest_download_server);
    static void init_logo_state(s32 arg0);
    static void noop();
    static void run_frame();
    void apply_rng_cipher(u32 *data, s32 len);
    void crypt_data_be(u32 *data, s32 len);
    void append_extension_if_missing(char *name, char *ext);
    static TPlyCharData *get_char_index(unsigned int index);
    static TPlyCharData *get_char_table_entry(int index);
    static void run_save_load_sequence();
    static s32 init();
    static s32 load_character_from_card(int);
    static void copy_slot_data(void *, void *);
    static s32 is_entry_equal(void *, void *);
    static s32 count_char_diffs(void *, void *);
    static s32 save_character_to_card();
    static s32 forward_to_global_instance(int);
    static s32 increment_frame();
    static s32 get_player_count();
    static s32 save_online_character();
    static void reset_character_data();
    static s32 all_players_loaded();
    static void alloc_char_buffers();
    static s32 apply_loaded_character(int arg0);
    static void build_default_save_file();
    static void build_save_file();
    static s32 check_page_cross(CharacterFile *src_file, int src_slot, CharacterFile *dst_file, int dst_slot);
    static s32 check_system_file_status();
    static void clear_load_buffers();
    static void clear_slot_body(int i);
    static void clear_slot_entry(int i);
    static u8 *construct_card_window_array(void *arg0);
    static void *construct_guild_card_tag_array(void *array);
    static void * copy_char_slot_data(void * a0, void * a1);
    static s32 copy_character_to_slot(CharacterFile *arg0, int src_slot, CharacterFile *arg2, int dst_slot);
    static void copy_chr_slots_from_request();
    static CharacterFile *copy_save_data(CharacterFile *arg0, CharacterFile *arg1);
    static void encrypt_save_data(void *arg0);
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
    static s32 init_and_register(CharacterFile *arg0);
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
    static void save_character_file(int arg0);
    static void set_id(void* p, int v);
    static s32 setup_player_battle_ctrls();
    static s32 update_elapsed_time(CharacterSaveRecord *record);
    static void update_pair(void* p);
    static s32 update_play_time();
    static s32 verify_save_checksum(int arg0);
    static void verify_save_checksum();
    static s32 write_encrypted_save();
    static void alloc_char_records(void *arg0);
    static s32 check_ready();
    static s32 check_slot_swap_allowed(void *src_file, int src_slot, void *dst_file, int dst_slot);
    static s32 check_system_load_result();
    static void clear_entry(int i);
    static s32 compare_save_headers(void *record_a, void *record_b, void *file_a, void *file_b);
    static void decrypt_char_data(void *arg0);
    static void free_char_data_slots(void *table);
    static TPlyCharData *get_entry(int i);
    static int get_serial_seed();
    static void *init_windows(void *arg0);
    static s32 is_entry_valid(CharacterFile *self, int i);
    static s32 is_same_slot_entry(void *src_file, int src_slot, void *dst_file, int dst_slot);
    static s32 is_slot_active(unsigned int arg0);
    static s32 load_character_and_wait();
    static s32 load_player_and_wait();
    static s32 load_system_file(s32 chan, s32 *arg1);
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
extern uaddr active_character_save_record;
extern uaddr guild_card_save_payload;
extern uaddr system_save_payload;
extern uaddr secondary_card_system_save_payload;
extern s32 TAdSinglePlyChrSelectGC__selection_index;
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
#endif
