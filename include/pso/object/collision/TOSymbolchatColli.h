#ifndef PSO_OBJECT_COLLISION_TOSYMBOLCHATCOLLI_H
#define PSO_OBJECT_COLLISION_TOSYMBOLCHATCOLLI_H

#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/PlayerStats.h"

struct TOSymbolchatColli : public TObjChara {
    TOSymbolchatColli(TObject *parent, saddr set_data);
    virtual ~TOSymbolchatColli();
    virtual void run_task();
    void open_balloon_chat(s32 state, u16 player);  // opens the state's balloon chat over the player
    s32 get_state();
    void init_collision_params();
    virtual void render();
    static void *create(void *set_data);
    static void free_rock();
    static void load_symbol_chat_data();
    f32 radius_sq;            // scale.x squared
    s32 player_inside[4];     // set while that player is inside the radius
    player_stats collision_stats;
    u8 *balloon_chats[3];     // per state: the param table entry, else the preset picked by preset_ids
    u16 switch_ids[3];        // set param high half, 0xFFFF when not a switch
    u16 preset_ids[3];        // set param low half
};

LAYOUT_ASSERT(TOSymbolchatColliStatsOffset, offsetof(TOSymbolchatColli, collision_stats) == 0x348);
LAYOUT_ASSERT(TOSymbolchatColli_size, sizeof(TOSymbolchatColli) == 0x384);
#endif
