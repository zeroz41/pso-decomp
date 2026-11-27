#ifndef PSO_QUEST_TQUESTVMDOWNLOADSERVER_H
#define PSO_QUEST_TQUESTVMDOWNLOADSERVER_H

#include "pso/system/task/TObject.h"
#include "pso/ui/window/TMessageWindowController.h"
#include "types.h"

class TMCFormatSequence;
class TRecvDownload;
class TRecvDownloadHead;
struct QuestDownloadQueryResult;
struct QuestSymbolLookupResult;
struct QuestDownloadItemNode;
struct QuestDownloadMatchToken;
struct QuestDownloadTextNode;
struct QuestDownloadTextRecord;
struct QuestNameLookupResult;
struct QuestDownloadRequest;

class TWindowBase;
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
    s32 state_file_blocks;     // blocks of quest_download_file_state
    s32 info_file_blocks;      // blocks of quest_download_file_info
    char slot_file_name[0xD];  // written with slot_file_blocks
    char state_file_name[0xD]; // written with state_file_blocks
    TWindowBase *icon_menu;    // TWindowMenuIconLine (clear_decided)
    TWindowBase *status_window; // init_shop_judgment_window
    TWindowMessagePage *message_window; // create_window's window, closed by close_message
    s32 file_count;            // files to save, checked against get_memcard_free_files
    TObject *mc_select;        // TAdMcSelectGC::create
    s32 state;
    s32 status_message_index; // picks the status message update_mc_select shows (0-5)

    TQuestVmDownLoadServer(TObject *parent);
    virtual ~TQuestVmDownLoadServer();
    void count_download_file_blocks();
    void handle_confirm_input();
    void build_file_slot_image();
    void build_file_info_image();
    void handle_status_message_input();
    void handle_download_done_input();
    void check_dismiss_to_close_input();
    virtual void run_task();
public:
    static void reset_download_state();
    static void free_download_buffers();
    static void free_buffers();
    static void begin_file_download(TRecvDownloadHead &download_head);
    static void receive_file_chunk(TRecvDownload &download);
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
    void show_status_message(const char *text, s32 flags);
    void close_message();
    void check_cancel_input();
    static void create();
    static s32 get_total_blocks();
    static void reset_state_on_format_error(TMCFormatSequence *sequence);
    static s32 get_serial_access();
    static s32 poll_serial_access();
    static void reset_download();
public:
    static void encrypt_download_data(u32 *data, s32 size);
    static void unshuffle_and_decrypt(void *data, s32 size);
public:
};
LAYOUT_ASSERT(TQuestVmDownLoadServer_size_check, sizeof(TQuestVmDownLoadServer) == 0x2A8);

extern TQuestVmDownLoadServer *quest_vm_download_server_instance;

void *alloc(u32 size);

// The two seeds of the download cipher; a quest saved to a memory card is
// encrypted with the console's serial number in both.
extern __declspec(section ".data") u32 download_rng_seed_pair[2];

void seed_download_rng(s32 seed);

void reset_download_graph(void);

// One downloaded quest file (begin_file_download fills one per extension: .dat, .bin, .pvr, .gba);
// the type name is inferred. size is the packet's file size, +8 for .dat/.bin whose buffer starts with a
// QuestDownloadFile header (receive_file_chunk writes their chunks at data + 8); data is alloc(size).
struct QuestDownloadRecord {
    char name[0x10];
    char title[0x24];
    s32 size;
    u8 *data;
};

extern QuestDownloadRecord quest_download_file_state; // .dat
extern QuestDownloadRecord quest_download_file_slot;                    // .bin
extern QuestDownloadRecord quest_download_file_info;                    // .pvr
extern QuestDownloadRecord quest_download_file_header;                  // .gba

QuestDownloadRecord *get_quest_download_file_header(void);

// Set while a quest file is being downloaded (TQuestVmDownLoadServer::load_quest_data sets it).
extern s32 quest_download_in_progress;

// Defined with the memory-card file constants (TAdSinglePlyChrSelectGC_801FBF54.cpp, next to
// quest_memcard_key). Names inferred: the quest file requests store them in their
// banner (+0x44) and icon (+0x48) fields, which set_card_banner_and_icon then replaces with the
// loaded banner/icon buffers; build_save_file_image copies 0x1800 (banner) / 0x800 (icon) bytes from them.
extern "C" const char memcard_default_banner[];
extern "C" const char memcard_default_icon[];

struct StatusWindowPos { f32 a; f32 b; };

struct DownloadWindowPos { f32 a, b; };

// TMCFormatSequence: its class name and window position sit in this TU's
// .sdata/.rodata, so it is the tail of this file (deferred: the source runs backwards from the text).
struct FormatWindowPos { f32 a; f32 b; };

#endif
