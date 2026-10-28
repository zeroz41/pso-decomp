#ifndef PSO_MISC_TOCHATSENSOR_H
#define PSO_MISC_TOCHATSENSOR_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOChatSensor : public TObjBase {
    virtual ~TOChatSensor();
    u32 m_90;
    u16 m_94;
    u8 unk_96[0x2];
    u32 m_98;
    u8 unk_9C[0x4];
    u32 m_a0;
    u8 unk_A4[0x4];
    u16 m_a8;
    u8 unk_AA[0xA];
    s32 m_b4;
    u8 unk_B8[0xC];
    u32 m_c4;
    u32 m_c8;
    u32 m_cc;
    static void dispatch_chat_message_to_children(s32 arg0);
    static void destroy_global();
    void check_player_proximity();
    void set_trigger_text(void *arg1);
    void handle_chat_message(void *arg1);
    void init_params();
    virtual void render();
    virtual void run_task();
    void send_state();
    void swap_state_endian();
    void init_packet_type();
};

typedef char TOChatSensor_size[sizeof(TOChatSensor) == 0xD0 ? 1 : -1];
#endif
