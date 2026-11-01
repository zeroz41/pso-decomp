#ifndef PSO_MISC_TQUESTVMDOWNLOADSERVER_H
#define PSO_MISC_TQUESTVMDOWNLOADSERVER_H

#include "pso/TObject.h"
#include "pso/ui/TMessageWindowController.h"
#include "types.h"

class TQuestVmDownLoadServer : public TObject, public TMessageWindowController {
public:
    s32 m_22c;
    s32 m_230;
    s32 m_234;
    s32 m_238;
    u8 _pad23C[0x20];
    s32 m_25c;
    void *m_260;
    u8 unk_264[0x4];
    s32 m_268;
    u8 unk_26C[0x4];
    char m_270[0xD];
    char m_27d[0xD];
    void *m_28c;
    void *m_290;
    s32 m_294;
    s32 m_298;
    TObject *m_29c;
    s32 state;

    TQuestVmDownLoadServer(TObject *parent);
    virtual ~TQuestVmDownLoadServer();
    void sub_801F7FEC();
    void handle_confirm_input();
    void sub_801F770C();
    void sub_801F718C();
    void sub_801F6D24();
    void sub_801F6C74();
    void sub_801F6B00();
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
    void show_status_message(s32 arg1, s32 arg2);
    void close_message();
    void check_cancel_input();
    static void create();
    static s32 get_field230();
    static void clear_field2A0();
    static void split_time_hms(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3);
    static void *alloc(u32 size);
    static void register_global_instance_dtor();
    void clear_flag4_bit4();
    static s32 is_ready();
    static s32 get_serial_access();
    static s32 poll_serial_access();
    static void destroy_instance();
    static void reset_download();
    void init(void* a1, void* a2, void* a3, void* a4);
    void init_from_keyboard_state();
    static s32 reset_download_buffers();
    static s32 poll_download_status();
    s32 handle_list_scroll();
    s32 convert_jis_to_sjis_string();
    static void init_buffer_pointers();
    static s32 get_buffer_size();
    static s32 lookup_value_by_key(u16 arg0);
    static u16 map_key_to_code(u32 arg0);
    static s32 is_valid_item_for_slot(u8 c, u8 k);
    static void invalidate_entries_by_id(s32 id);
    static void clear_entries_by_id(s32 id);
    static s32 release_ref_slot(u32 arg0);
    static s32 set_slot_values_for_indices(s32 *arg0, s32 arg1, u32 arg2);
    s32 get_max_size_of_indices(s32 arg1);
    static u32 acquire_slot_entry(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void retry_seek_active_entries();
    static void set_active();
    static s32 match_prefix_length(const u8 *a, const u8 *b, s32 n);
    static s32 count_matching_name_prefix(s32 arg0, u8 *arg1);
    s32 has_name_mismatch(u8 *arg1);
    s32 is_char_allowed(s16 arg1);
    static s32 read_ask_header();
    static void init_page_cache();
    static s32 seek_or_reopen(int arg0);
    static s32 find_file_info_index();
    void set_file_info_name();
    u32 aram_read_thunk(u32 arg1, int _w2);
    static void unescape_copy_string(u8 *arg0, u8 *arg1, u8 *arg2);
    static s32 count_entries_until_terminator(const u8 *p, const u8 *end);
    static void copy_sjis_string(u8 *arg0, u8 *arg1);
    static s32 calc_sjis_string_width(u8 *arg0);
    s32 calc_text_length();
    s32 calc_message_length();
    static u8 *get_buffer_ptr(s32 arg0);
    static s32 is_download_cmd_allowed(u8 arg0);
    static void latch_slot_value(s32 arg0);
    static s32 count_leading_entries(s32 i, s32 end);
    static void init_entries();
    s32 count_chain_nodes();
    static void *build_text_node_chain(void *sp, void *a1, s32 a2, void *hp, void *tp);
    static u16 jis_to_sjis(u16 arg0);
    static s32 is_valid_sjis_code(u16 arg0);
    static s32 is_download_command(u16 arg0, s32 arg1);
    static s32 encode_char_with_attr(u16 *out, u16 ch, s32 attr);
    static s32 is_sjis_lead_byte(u8 arg0);
    void free_node_list();
    static void push_download_entry(s32 *arg0);
    static void init_block_free_list();
    static s32 calc_item_cost_bonus(u8 kind, u8 v, u8 w, s32 base, s32 add);
    s32 calc_item_entry_cost(u8 k, u8 v, s32 base);
    static s32 calc_pair_cost_bonus(u8 arg0, u8 arg1, s32 arg2);
    static s32 calc_item_entry_cost_extra(u8 arg0, u8 arg1, u8 arg2, s32 arg3);
    static void reset_slot_chain_timers(s32 arg0);
    static s16 select_best_slot_entry(s32 idx, s32 max, s32 want);
    static s32 sum_entry_sizes(s32 start, s32 n);
    static u8 *find_keyword_entry(u16 *start, u16 *end);
    static s32 get_download_state();
    u8 *find_insert_position(s32 key, s32 n, s32 len);
    static s32 read_quest_chunk(u32 id, u8 a1, u8 a2, u8 *buf, s32 *out);
    static u32 aram_dma_read(void *h, void *dst, int size);
public:
    void encrypt_download_data(s32 size);
    static void unshuffle_and_decrypt(void *data, s32 size);
    s32 find_name_index();
};
typedef char TQuestVmDownLoadServer_size_check[sizeof(TQuestVmDownLoadServer) == 0x2A4 ? 1 : -1];

// The two seeds of the download cipher; a quest saved to a memory card is
// encrypted with the console's serial number in both.
extern __declspec(section ".data") u32 download_rng_seed_pair[2];

void seed_download_rng(s32 seed);

#endif
