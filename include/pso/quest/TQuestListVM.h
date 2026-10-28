#ifndef PSO_QUEST_TQUESTLISTVM_H
#define PSO_QUEST_TQUESTLISTVM_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TQuestListVM : public TShopWindowBase {
    virtual ~TQuestListVM();
    s32 quest_vm_load();
    void sub_80219064();
    void open_confirm_window();
    void load_selected_slot();
    virtual void vfunc_11();
    virtual int vfunc_10();
    virtual void vfunc_9();
    virtual void vfunc_7();
    virtual void vfunc_6();
    u8 _pad1C[0x4];
    u32 m_20;
    u32 m_24;
    u8 unk_28[0x10];
    f32 m_38;
    u8 unk_3C[0x4];
    f32 m_40;
    u8 unk_44[0x26C];
    u8 unk_2B0[0xA50];
    s32 m_d00;
    u8 unk_D04[0x1664];
    u32 m_2368;
    u8 _pad236C[0x4];
    u32 m_2370;
    u32 m_2374;
    u32 m_2378;
    u32 m_237c;
    u32 m_2380;
    u32 m_2384;
    u32 m_2388;
    u8 _pad238C[0x4];
    u32 m_2390;
    u8 _pad2394[0x4];
    u32 m_2398;
    u32 m_239c;
    u32 m_23a0;
    u32 m_23a4;
    u32 m_23a8;
    u32 m_23ac;
    u32 m_23b0;
    u32 m_23b4;
    u32 m_23b8;
    u32 m_23bc;
    u32 m_23c0;
    s32 update_load_status();
    void close_windows();
    static void set_enemy_mode_3();
    static void load_vm();
    s32 handle_click();
    s32 invoke_callback_and_queue_destruction();
    s32 close_and_destroy();
    s32 close();
    void update_close();
    void load_downloaded_quest();
    void handle_confirm_window();
    static void poll_quest_download(void *p);
    static void update_lobby_selection(void *arg0_);
    static s32 build_download_list(void *p);
    void process_download_entry();
    void load_selected_player_slot();
    static void scan_memcard_quest_files(void *arg0);
    s32 load_quest_vm();
    s32 init();
    static int get_instance();
    static int get_quest_size();
    static void reset();
    u32 decrypt_quest_data(s32 arg1, s32 arg2, u32 arg3);
    static int get_data();
    void set_selected_entry(void* a1);
    static void poll_download();
};

typedef char TQuestListVM_size[sizeof(TQuestListVM) == 0x23C4 ? 1 : -1];
#endif
