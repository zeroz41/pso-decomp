#ifndef PSO_MISC_TOSYMBOLCHATCOLLI_H
#define PSO_MISC_TOSYMBOLCHATCOLLI_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TOSymbolchatColli : public TObjChara {
    virtual ~TOSymbolchatColli();
    virtual void run_task();
    s32 get_state();
    void init_collision_params();
    virtual void render();
    static void *create(void *arg0);
    static void free_rock();
    static void load_symbol_chat_data();
    u8 unk_334[0x24];
    f32 m_358;
    u8 unk_35C[0x1C];
    u16 m_378;
    u8 unk_37A[0x2];
    u16 m_37c;
    u8 unk_37E[0x6];
};

typedef char TOSymbolchatColli_size[sizeof(TOSymbolchatColli) == 0x384 ? 1 : -1];
#endif
