#ifndef PSO_QUEST_TQUESTVMDOWNLOADSERVER_H
#define PSO_QUEST_TQUESTVMDOWNLOADSERVER_H

#include "pso/system/task/TObject.h"
#include "pso/ui/window/TMessageWindowController.h"
#include "types.h"

class TMCFormatSequence;
struct Hdr_803EA384;
struct QuestSymbolLookupResult;
struct QuestDownloadItemNode;
struct QuestDownloadMatchToken;
struct QuestDownloadTextNode;
struct QuestDownloadTextRecord;
struct QuestNameLookupResult;
struct QuestDownloadRequest;

class TQuestVmDownLoadServer : public TObject, public TMessageWindowController {
public:
    // Field names are inferred from their uses in TQuestVmDownLoadServer.cpp.
    s32 pad_22c;
    s32 total_blocks;          // sum of the files' memory card block counts, checked against the free blocks
    s32 card_mask;             // bit per channel that probe_card_slot reports present
    s32 prev_card_mask;
    u8 _pad23C[0x20];
    s32 memcard_slot;          // the card picked to save to (poll_memcard_result, get_memcard_free_files)
    void *save_image;          // alloc(blocks << 13) image built by build_save_file_image
    s32 slot_file_blocks;      // blocks of quest_download_file_slot
    s32 state_file_blocks;     // blocks of TQuestVmDownLoadServer__download_file_state
    s32 info_file_blocks;      // blocks of quest_download_file_info
    char slot_file_name[0xD];  // written with slot_file_blocks
    char state_file_name[0xD]; // written with state_file_blocks
    void *icon_menu;           // TWindowMenuIconLine (clear_decided)
    void *status_window;       // init_shop_judgment_window
    TWindowMessagePage *message_window; // create_window's window, closed by close_message
    s32 file_count;            // files to save, checked against get_memcard_free_files
    TObject *mc_select;        // TAdMcSelectGC::create
    s32 state;
    s32 pad_2a4; // picks update_mc_select's status message; nothing in this TU writes it

    TQuestVmDownLoadServer(TObject *parent);
    virtual ~TQuestVmDownLoadServer();
    void count_download_file_blocks();
    void handle_confirm_input();
    void build_file_slot_image();
    void build_file_info_image();
    void sub_801F6D24();
    void handle_download_done_input();
    void check_dismiss_to_close_input();
    virtual void run_task();
public:
    static void reset_download_state();
    static void free_download_buffers();
    static void free_buffers();
    void begin_file_download();
    void receive_file_chunk();
    static s32 verify_checksum(const void *data, s32 size);
    void close_window();
    void update_mc_select();
    void open();
    void check_memcard_slot();
    void handle_confirm_window();
    void find_free_file_names();
    void load_quest_data();
    void abort_download();
    void write_memcard_file();
    void write_quest_data_named();
    void finish_download();
    void write_quest_data();
    void close_download();
    void destroy();
    void close();
    void check_client_connections();
    void show_status_message(saddr text, s32 flags);
    void close_message();
    void check_cancel_input();
    static void create();
    static s32 get_field230();
    static void clear_field2A0(TMCFormatSequence *sequence);
    static void split_time_hms(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3);
    static void *alloc(u32 size);
    static s32 is_ready();
    static s32 get_serial_access();
    static s32 poll_serial_access();
    static void destroy_instance();
    static void reset_download();
    static s32 reset_download_buffers(saddr *);
    static s32 poll_download_status(saddr *);
    static s32 handle_list_scroll(saddr *args);
    static s32 convert_jis_to_sjis_string(saddr *args);
    static void init_buffer_pointers();
    static s32 get_buffer_size();
    static u8 lookup_value_by_key(u16 key);
    static u16 map_key_to_code(u32 ch);
    static s32 is_valid_item_for_slot(u8 c, u8 k);
    static void invalidate_entries_by_id(s32 id);
    static void clear_entries_by_id(s32 id);
    static s32 release_ref_slot(u32 index);
    static s32 set_slot_values_for_indices(s32 *ids, s32 count, u32 value);
    s32 get_max_size_of_indices(s32 count);
    static u32 acquire_slot_entry(s32 page_index, s32 file_offset, s32 cached_id, s32 value);
    static void retry_seek_active_entries();
    static void set_active();
    static s32 match_prefix_length(const u8 *a, const u8 *b, s32 n);
    static s32 count_matching_name_prefix(s32 idx, u8 *name);
    static s32 is_char_allowed(const u8 *text, s16 len);
    static s32 has_name_mismatch(s32 row, u8 *key);
    static s32 find_name_index(const char *key);
    static void set_file_info_name(const char *filename);
    static s32 read_ask_header();
    static void init_page_cache();
    static s32 seek_or_reopen(int pos);
    static s32 find_file_info_index();
    static s32 aram_read_thunk(s32 handle, void *dst, s32 size);
    static void unescape_copy_string(u8 *dst, u8 *src, u8 *end);
    static s32 count_entries_until_terminator(const u8 *p, const u8 *end);
    static void copy_sjis_string(u8 *src, u8 *dst);
    static s32 calc_sjis_string_width(u8 *text);
    static u8 *get_buffer_ptr(s32 id);
    static s32 is_download_cmd_allowed(u8 cmd);
    static void latch_slot_value(s32 index);
    static s32 count_leading_entries(s32 i, s32 end);
    static void init_entries();
    static QuestDownloadTextNode *build_text_node_chain(QuestDownloadTextRecord *record, const QuestDownloadItemNode *source, s32 length,
                                                         QuestDownloadTextNode **head, QuestDownloadTextNode **tail);
    static u16 jis_to_sjis(u16 jis);
    static s32 is_valid_sjis_code(u16 ch);
    static s32 is_download_command(u16 ch, s32 arg1);
    static s32 encode_char_with_attr(u16 *out, u16 ch, s32 attr);
    static s32 is_sjis_lead_byte(u8 c);
    static void push_download_entry(void *storage);
    static void init_block_free_list();
    static s32 calc_item_cost_bonus(u8 kind, u8 v, u8 w, s32 base, s32 add);
    static s32 calc_pair_cost_bonus(u8 arg0, u8 bk, s32 extra);
    static s32 calc_item_entry_cost_extra(u8 arg0, u8 arg1, u8 bk, s32 extra);
    static void reset_slot_chain_timers(s32 pos);
    static s32 select_best_slot_entry(s32 idx, s32 max, s32 want);
    static s32 sum_entry_sizes(s32 start, s32 n);
    static const u8 *find_keyword_entry(u16 *start, u16 *end);
    static s32 get_download_state();
    static QuestDownloadTextRecord *find_insert_position(u8 *buffer, s32 key, s32 n, s32 len);
    static u8 *format_number_text(const u8 *input, s32 length, QuestDownloadTextRecord *out, s32 mode);
    static s32 read_quest_chunk(u32 id, u8 key, u8 sub_key, u8 *buf, s32 *out);
    static s32 aram_dma_read(s32 handle, void *dst, s32 size);
public:
    void encrypt_download_data(s32 size);
    static void unshuffle_and_decrypt(void *data, s32 size);
public:
    static u8 *get_cached_page(s32 page);
    static s32 lookup_name_entry(char *name, s16 name_len, QuestNameLookupResult *out);
    static void append_message_text(u8 *record, s32 size, QuestDownloadRequest *msg, u8 attr);
    static void build_message_packet(u8 *record, s32 size, QuestDownloadRequest *msg, u8 attr);
    static const QuestDownloadMatchToken *find_longest_match_entry(u8 *text, s32 remaining, s32 *length);
    static QuestDownloadItemNode *build_item_list(s32 start, Hdr_803EA384 *arg1);
    static s32 count_fitting_entries(QuestDownloadTextNode *arg0);
    static s32 find_symbol_entry(const char *name, s16 len, QuestSymbolLookupResult *out);
};
LAYOUT_ASSERT(TQuestVmDownLoadServer_size_check, sizeof(TQuestVmDownLoadServer) == 0x2A8);

extern TQuestVmDownLoadServer *TQuestVmDownLoadServer__instance;

// The two seeds of the download cipher; a quest saved to a memory card is
// encrypted with the console's serial number in both.
extern __declspec(section ".data") u32 download_rng_seed_pair[2];

void seed_download_rng(s32 seed);

// One downloaded quest file (begin_file_download fills one per extension: .dat, .bin, .pvr, .gba);
// the type name is inferred. size is the packet's file size, +8 for .dat/.bin whose buffer starts with a
// QuestDownloadFile header (receive_file_chunk writes their chunks at data + 8); data is alloc(size).
struct QuestDownloadRecord {
    char name[0x10];
    char title[0x24];
    s32 size;
    u8 *data;
};

extern QuestDownloadRecord TQuestVmDownLoadServer__download_file_state; // .dat
extern QuestDownloadRecord quest_download_file_slot;                    // .bin
extern QuestDownloadRecord quest_download_file_info;                    // .pvr
extern QuestDownloadRecord quest_download_file_header;                  // .gba

QuestDownloadRecord *get_quest_download_file_header(void);

// Set while a quest file is being downloaded (TQuestVmDownLoadServer::load_quest_data sets it).
extern s32 quest_download_in_progress;

// Defined with the memory-card file constants (TAdSinglePlyChrSelectGC_801FBF54.cpp, next to
// TQuestVmDownLoadServer__memcard_key). Names inferred: the quest file requests store them in their
// banner (+0x44) and icon (+0x48) fields, which set_card_banner_and_icon then replaces with the
// loaded banner/icon buffers; build_save_file_image copies 0x1800 (banner) / 0x800 (icon) bytes from them.
extern "C" const char memcard_default_banner[];
extern "C" const char memcard_default_icon[];

#endif
