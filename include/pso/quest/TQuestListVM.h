#ifndef PSO_QUEST_TQUESTLISTVM_H
#define PSO_QUEST_TQUESTLISTVM_H

#include "types.h"
#include "pso/TShopWindowBase.h"

class TObjBase;
class TQuestListVM;
class TWindowMenuIconLine;
struct TWindowMenu;
struct TWindowMessage;

// A quest found on a memory card: the .bin file holding its header, the
// header's title and description, and where the file lives.
struct QuestFileEntry {
    char file_name[0xD];
    char title[0x20];
    char description[0x80];
    u8 pad_AD[0x3];
    s32 file_index;
    s32 card_slot;
    s32 episode;
};

// The header at the start of a decompressed quest .bin file.
struct QuestBinHeader {
    u32 code_offset;
    u32 function_table_offset;
    u32 size;
    u32 unused;
    s8 language;
    s8 unk_11;
    s8 quest_number;
    s8 episode;
    char name[0x20];
    char short_description[0x80];
    char long_description[0x120];
};

// A downloaded quest file once its checksum word is stripped: the big-endian
// decompressed size and cipher seed, then the encrypted PRS stream.
struct QuestDownloadFile {
    u32 decompressed_size;
    u32 seed;
    u8 data[1];
};

// Decrypts and decompresses a downloaded quest file into dst; returns the
// decompressed size, or 0 when it does not fit in capacity.
u32 decrypt_quest_data(void *src, s32 size, void *dst, u32 capacity);

// Quest files on a memory card are named quest_file_prefix plus a two-digit
// index, in pairs (.bin then .dat) from quest_file_first_index up to
// quest_file_index_limit.
extern const char quest_file_prefix[];
extern const char quest_file_99_name[];
extern const s32 quest_file_first_index;
extern const s32 quest_file_index_limit;

// The quest being loaded: the .bin is decompressed to decrypted_quest_buffer
// and the .dat after it, at quest_data_output_cursor.
extern u8 *decrypted_quest_buffer;
extern u32 decompression_capacity;
extern u8 *quest_data_output_cursor;
extern u32 quest_decrypt_result_size;
extern TQuestListVM *quest_list_vm_instance;

// Lists the downloaded quests on the memory cards and loads the chosen one.
class TQuestListVM : public TShopWindowBase {
public:
    TQuestListVM(TObject *parent, TShopWindowBase *owner, TObjBase *player);
    virtual int vfunc_10();
    virtual void display_guild_message(s32 index, s32 flags);
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_6();
    virtual void vfunc_11();
    virtual ~TQuestListVM();

    void set_state_after_message(s32 state);
    u32 get_download_seed();
    s32 update_load_status();
    void close_windows();
    static void set_enemy_mode_3();
    static void load_vm();
    void wait_for_message();
    void invoke_callback_and_queue_destruction();
    void close_and_destroy();
    void close();
    void idle();
    void update_close();
    void load_downloaded_quest();
    void load_selected_slot();
    void handle_confirm_window();
    void open_confirm_window();
    void poll_quest_download();
    void load_selected_bin();
    void quest_vm_load();
    void update_lobby_selection();
    void build_download_list();
    s32 is_downloadable_new_entry(QuestBinHeader *header);
    void process_download_entry();
    void load_selected_player_slot();
    void scan_memcard_quest_files();
    void load_quest_vm();
    void init();
    static u8 *get_quest_bin();
    static u32 get_quest_size();
    static void reset();
    static u8 *get_quest_dat();

    u8 pad_1C[0x4];
    s32 state;
    TObjBase *player;
    QuestFileEntry entries[48];
    s32 entry_count;
    s32 described_entry;
    s32 resume_state;
    TWindowMenuIconLine *list_window;
    TWindowMenu *confirm_window;
    TWindowMessage *description_window;
    TWindowMessage *detail_window;
    u8 *tmp_buffer;
    void *card_buffer;
    u8 pad_238C[0x4];
    s32 unk_2390;
    u8 pad_2394[0x4];
    s32 scan_index;
    s32 scan_card_slot;
    TShopWindowBase *owner;
    s32 card_mask;
    s32 prev_card_mask;
    s32 scan_card_error;
    s32 scan_download_error;
    s32 deferred_state;
    void (*on_close)();
    void (*on_error)();
    void (*on_finish)();
};

typedef char TQuestListVM_size[sizeof(TQuestListVM) == 0x23C4 ? 1 : -1];
#endif
