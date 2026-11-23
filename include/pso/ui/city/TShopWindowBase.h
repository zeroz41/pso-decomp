#ifndef PSO_UI_CITY_TSHOPWINDOWBASE_H
#define PSO_UI_CITY_TSHOPWINDOWBASE_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjPlayer;

class TShopWindowBase : public TObject {
public:
    TShopWindowBase(TObject *parent);
    virtual ~TShopWindowBase();
    virtual void display_shop_message(s32 id, s32 flags);
    virtual void display_message(const char *text, s32 flags);
    virtual void send_message(s32 id, s32 flags);
    virtual void display_guild_message(s32 index, s32 flags);
    virtual int is_message_ready();
    virtual void update_state();
    void set_state(s32);
    s32 is_cancel_pressed();
    s32 is_decide_pressed();
    s32 get_split_screen_slot();
    u16 get_player_entity_id();
    virtual void run_task();
public:
    f32 get_scale();

    u32 pad_1C;
    s32 state;          // the derived window's update_state switch
    TObjPlayer *player; // the player at the counter
};

// The derived windows' constructors are still C functions and call these by symbol.
extern "C" {
void *__ct__15TShopWindowBaseFP7TObject(void *self, TObject *parent);
}

#endif
