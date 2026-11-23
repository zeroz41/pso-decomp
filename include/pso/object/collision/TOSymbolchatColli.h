#ifndef PSO_OBJECT_COLLISION_TOSYMBOLCHATCOLLI_H
#define PSO_OBJECT_COLLISION_TOSYMBOLCHATCOLLI_H

#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/PlayerStats.h"

struct TOSymbolchatColli : public TObjChara {
    TOSymbolchatColli(TObject *parent, s32 arg2);
    virtual ~TOSymbolchatColli();
    virtual void run_task();
    s32 get_state();
    void init_collision_params();
    virtual void render();
    static void *create(void *arg0);
    static void free_rock();
    static void load_symbol_chat_data();
    u8 unk_334[0x14];
    player_stats collision_stats;
    u8 unk_36C[0xC];
    u16 m_378;
    u8 unk_37A[0x2];
    u16 m_37c;
    u8 unk_37E[0x6];
};

LAYOUT_ASSERT(TOSymbolchatColliStatsOffset, offsetof(TOSymbolchatColli, collision_stats) == 0x348);
LAYOUT_ASSERT(TOSymbolchatColli_size, sizeof(TOSymbolchatColli) == 0x384);
#endif
