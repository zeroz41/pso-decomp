#ifndef PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_80213788_H
#define PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_80213788_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

// The hunter's guild counter in an online lobby: the client side (vtable 0x804C9740) and the
// server side (vtable 0x804C97F0). Both derive straight from TShopSequence (their ctors call it).
struct THunterGuildSeqOnline_Client : public TShopSequence {
    THunterGuildSeqOnline_Client(TObject *parent, TObjPlayer *player);
    virtual ~THunterGuildSeqOnline_Client();
    s32 pad_2c;     // 0x2C: an object the dtor queues for destruction
    s32 pad_30;
    s32 pad_34;
    s32 pad_38;
    s32 pad_3c;     // 0x3C: a window the dtor closes
};

typedef char THunterGuildSeqOnline_Client_size[sizeof(THunterGuildSeqOnline_Client) == 0x40 ? 1 : -1];

struct THunterGuildSeqOnline_Server : public TShopSequence {
    THunterGuildSeqOnline_Server(TObject *parent, TObjPlayer *player);
    virtual ~THunterGuildSeqOnline_Server();
    s32 pad_2c;     // 0x2C: an object the dtor queues for destruction
    s32 pad_30;
    s32 pad_34;
    s32 pad_38;     // 0x38: a window the dtor closes
    s32 pad_3c;
    s32 pad_40;
};

typedef char THunterGuildSeqOnline_Server_size[sizeof(THunterGuildSeqOnline_Server) == 0x44 ? 1 : -1];

// The live counter of each side; set by its ctor, cleared by its dtor.
extern THunterGuildSeqOnline_Server *hunter_guild_seq_online_server_instance;
extern THunterGuildSeqOnline_Client *hunter_guild_seq_online_client_instance;

void set_random_enemies_mode(void);

// --- C functions defined in THunterGuildSeqOffline_80213788.cpp ---
extern "C" {
void THunterGuildSeqOffline__sub_80213B18(u8 *shop_sequence);
void THunterGuildSeqOffline__sub_80213CA4(void);
void THunterGuildSeqOffline__sub_80213E64(void);
void THunterGuildSeqOffline__sub_80213EBC(void);
void THunterGuildSeqOffline__sub_80213F78(void);
void THunterGuildSeqOffline__sub_802145F8(u8 *shop_sequence);
u8 *__dt__28THunterGuildSeqOnline_ClientFv(u8 *arg0, s16 arg1);
u8 *__dt__28THunterGuildSeqOnline_ServerFv(u8 *arg0, s16 arg1);
void fn_80214254(u8 *shop_window_base);
void reset_random_enemies_mode(void);
void restore_shop_and_init_quest_state(void *shop_window_base);
void update__15TShopWindowBaseFPv(void *shop_sequence);
}
// --- end of C functions

#endif
