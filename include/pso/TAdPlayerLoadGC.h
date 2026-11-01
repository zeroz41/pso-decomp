#ifndef PSO_TADPLAYERLOADGC_H
#define PSO_TADPLAYERLOADGC_H
#include "pso/TObject.h"
#include "types.h"

class TAdPlayerLoadGC : public TObject {
public:
    virtual ~TAdPlayerLoadGC();
    virtual void render();
    virtual void run_task();
public:
    static s32 get_instance();
    static void set_state(int a0);
    static void reset_load_state(void *arg0, void *arg1);
    static void poll_card_load(s32 arg0);
    s32 check_card_result_code();
    static s32 probe_and_check_card(s32 chan);
    static void unmount_card_and_clear_flags(s32 n);
    static void load_banner_files();
    static s32 get_load_result(void * _w0);
    static s32 probe_card_slot(s32 chan);
    static s32 find_card_file(s32 chan, const char *name);
    static s32 check_memcard_status(s32 arg0);
    static s32 query_memcard_capacity(s32 arg0);
    static s32 poll_load_status(s32 arg0);
    void play_load_sound();
    u8 *create_instance();
    static s32 get_or_set_channel_flag(s32 arg0, s32 arg1);
    static s32 get_load_state();
    static void step_set_attributes(s32 arg0);
    static void update_card_delete(s32 arg0);
    static void update_card_rename(s32 arg0);
    static void reset_slot_entry(s32 arg0);
    static s32 close_card_slot(s32 arg0);
    static s32 finish_load_slot_state4(s32 arg0, s32 *arg1);
    static s32 queue_network_request(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static s32 finish_load_slot_state3(s32 arg0, s32 *arg1);
    static s32 begin_card_file_request(s32 chan, const char *name);
    static void unmount_card(s32 chan);
    static s32 take_network_info_load_result(s32 arg0, s32 *arg1);
    static s32 take_network_info_poll_result(s32 arg0, s32 *arg1);
public:
    static s32 request_card_open(s32 arg0, const char *arg1);
};

#endif
