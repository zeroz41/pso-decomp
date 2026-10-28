#ifndef PSO_MISC_TQUESTLISTONLINE_H
#define PSO_MISC_TQUESTLISTONLINE_H
#include "types.h"
#include "pso/TShopWindowBase.h"

struct TQuestListOnline : public TShopWindowBase {
    virtual ~TQuestListOnline();
    void vfunc_11();
    u32 unknown1c;
    u32 state;
    s32 window_owner;
    s32 (*callback28)();
    s32 (*callback2c)();
    s32 (*callback30)();
    s32 (*callback34)();
    u32 list_window;
    u32 description_window;
    u32 info_window;
    u32 confirm_window;
    s32 selected_index;
    u8 selected_entry[0x1C];
    s32 selection_stage;
    void* sequence;
    void close_windows();
    void invoke_callback_28_and_queue_destruction();
    void invoke_callback_2c_and_queue_destruction();
    void invoke_callback_30_and_queue_destruction();
    void invoke_callback_34_and_queue_destruction();
    void handle_quest_confirm();
    void decompress_quest_list_buffers();
    void request_download_buffer();
    int begin_buffer_request();
    void handle_list_selection();
    void show_info_window();
    void build_list_window();
    void request_menu();
    s32 get_selection_stage();
    static int get_quest_size();
    static int get_quest_data();
    void begin_file_download();
    static void receive_quest_info(void *arg0);
    void copy_quest_list_data();
    static void release_resources();
    static void init_download_buffers();
    static s32 get_list_state();
    static s32 get_selected_entry();
    static int get_selected_quest_id();
    static u8 get_unlocked_tier();
    static void decompress_quest_buffer(s32 arg0);
    static s32 init();
    static void ensure_online_quests_loaded();
    static int get_quest_list_flag();
    static void close_windows_and_reset();
    static void handle_quest_ready();
};
#include <stddef.h>
typedef char QuestListOnlineSize[(sizeof(TQuestListOnline)==0x70)?1:-1];
typedef char QuestListOnline_state[(offsetof(TQuestListOnline,state)==0x20)?1:-1];
typedef char QuestListOnline_window_owner[(offsetof(TQuestListOnline,window_owner)==0x24)?1:-1];
typedef char QuestListOnline_callback28[(offsetof(TQuestListOnline,callback28)==0x28)?1:-1];
typedef char QuestListOnline_callback2c[(offsetof(TQuestListOnline,callback2c)==0x2C)?1:-1];
typedef char QuestListOnline_callback30[(offsetof(TQuestListOnline,callback30)==0x30)?1:-1];
typedef char QuestListOnline_callback34[(offsetof(TQuestListOnline,callback34)==0x34)?1:-1];
typedef char QuestListOnline_list_window[(offsetof(TQuestListOnline,list_window)==0x38)?1:-1];
typedef char QuestListOnline_description_window[(offsetof(TQuestListOnline,description_window)==0x3C)?1:-1];
typedef char QuestListOnline_info_window[(offsetof(TQuestListOnline,info_window)==0x40)?1:-1];
typedef char QuestListOnline_confirm_window[(offsetof(TQuestListOnline,confirm_window)==0x44)?1:-1];
typedef char QuestListOnline_selected_index[(offsetof(TQuestListOnline,selected_index)==0x48)?1:-1];
typedef char QuestListOnline_selected_entry[(offsetof(TQuestListOnline,selected_entry)==0x4C)?1:-1];
typedef char QuestListOnline_selection_stage[(offsetof(TQuestListOnline,selection_stage)==0x68)?1:-1];
typedef char QuestListOnline_sequence[(offsetof(TQuestListOnline,sequence)==0x6C)?1:-1];
#endif
