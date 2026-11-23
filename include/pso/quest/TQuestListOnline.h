#ifndef PSO_QUEST_TQUESTLISTONLINE_H
#define PSO_QUEST_TQUESTLISTONLINE_H
#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/network/protocol/packet_classes.h"

class TWindowMenuIconLine;
struct TWindowMenu;
struct TWindowMessage;
class TRecvDownloadHead;
template <size_t size> struct TPlyText;
typedef TPlyText<288> OnlineQuestInfo;
class QuestListEntry;
template <typename T, int entries, int pad_entries> class TMenuList;
typedef TMenuList<QuestListEntry, 30, 0> OnlineQuestMenu;

struct TQuestListOnline : public TShopWindowBase {
    virtual ~TQuestListOnline();
    void update_state();
    void (*callback28)();
    void (*callback2c)();
    void (*callback30)();
    void (*callback34)();
    TWindowMenuIconLine *list_window;
    TWindowMessage *description_window;
    TWindowMessage *info_window;
    TWindowMenu *confirm_window;
    s32 selected_index;
    GameListEntry selected_entry;
    s32 selection_stage;
    TShopWindowBase *sequence;
    void close_windows();
    void invoke_callback_28_and_queue_destruction();
    void invoke_callback_2c_and_queue_destruction();
    void invoke_callback_30_and_queue_destruction();
    void invoke_callback_34_and_queue_destruction();
    void handle_quest_confirm();
    void decompress_quest_list_buffers();
    void request_download_buffer();
    void begin_buffer_request();
    void handle_list_selection();
    void show_info_window();
    void build_list_window();
    void request_menu();
    s32 get_selection_stage();
    static int get_quest_size();
    static u8 *get_quest_data();
    static void begin_file_download(TRecvDownloadHead &file);
    static void receive_quest_info(OnlineQuestInfo &info);
    static void release_resources();
    static void init_download_buffers();
    static s32 get_list_state();
    static const char *get_selected_entry();
    static int get_selected_quest_id();
    u8 get_unlocked_tier();
    static void decompress_quest_buffer(const u8 *data, s32 size);
    static s32 init();
    static void ensure_online_quests_loaded();
    static u8 *get_quest_list_flag();
    static void close_windows_and_reset();
    static void handle_quest_ready();
};
LAYOUT_ASSERT(QuestListOnlineSize, (sizeof(TQuestListOnline)==0x70));
LAYOUT_ASSERT(QuestListOnline_state, (offsetof(TQuestListOnline,state)==0x20));
LAYOUT_ASSERT(QuestListOnline_player, (offsetof(TQuestListOnline,player)==0x24));
LAYOUT_ASSERT(QuestListOnline_callback28, (offsetof(TQuestListOnline,callback28)==0x28));
LAYOUT_ASSERT(QuestListOnline_callback2c, (offsetof(TQuestListOnline,callback2c)==0x2C));
LAYOUT_ASSERT(QuestListOnline_callback30, (offsetof(TQuestListOnline,callback30)==0x30));
LAYOUT_ASSERT(QuestListOnline_callback34, (offsetof(TQuestListOnline,callback34)==0x34));
LAYOUT_ASSERT(QuestListOnline_list_window, (offsetof(TQuestListOnline,list_window)==0x38));
LAYOUT_ASSERT(QuestListOnline_description_window, (offsetof(TQuestListOnline,description_window)==0x3C));
LAYOUT_ASSERT(QuestListOnline_info_window, (offsetof(TQuestListOnline,info_window)==0x40));
LAYOUT_ASSERT(QuestListOnline_confirm_window, (offsetof(TQuestListOnline,confirm_window)==0x44));
LAYOUT_ASSERT(QuestListOnline_selected_index, (offsetof(TQuestListOnline,selected_index)==0x48));
LAYOUT_ASSERT(QuestListOnline_selected_entry, (offsetof(TQuestListOnline,selected_entry)==0x4C));
LAYOUT_ASSERT(QuestListOnline_selection_stage, (offsetof(TQuestListOnline,selection_stage)==0x68));
LAYOUT_ASSERT(QuestListOnline_sequence, (offsetof(TQuestListOnline,sequence)==0x6C));
extern TQuestListOnline *TQuestListOnline__instance;

extern "C" {
void copy_quest_list_data__16TQuestListOnlineFv(OnlineQuestMenu &menu);
TQuestListOnline *TQuestListOnline__ct(TQuestListOnline *list, TObject *parent,
                                     TShopWindowBase *sequence, TObjPlayer *player);
}

#endif
