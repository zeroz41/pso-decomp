#include "pso/ui/font/TFontSmallHelp.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/system/vector.h"

struct HelpTextPlayerState {
    u8 unresolved_00[0x84C];
    Vec position;
    u8 unresolved_858[0x558];
    u32 identity;
};
typedef char HelpTextPlayerPosition[offsetof(HelpTextPlayerState, position) == 0x84C ? 1 : -1];
typedef char HelpTextPlayerIdentity[offsetof(HelpTextPlayerState, identity) == 0xDB0 ? 1 : -1];

extern "C" {
TObject *get_instance__15TWindowCtrlMainFv();
void *get_player_by_client_id(s32 i);
extern const char *lbl_805D2B20;
}

void TFontSmallHelp::run_task() {
    HelpTextPlayerState *player = (HelpTextPlayerState *)get_player_by_client_id(player_id);
    if (player == NULL) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (owner_identity != player->identity) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    VecCopy(&position, &player->position);
    age_ticks += 1;
    s32 lifetime = lifetime_ticks;
    if (lifetime > 0 && age_ticks >= lifetime) {
        disallow_rendering__7TObjectFv(this);
        queue_destruction__7TObjectFv(this);
    }
}

TFontSmallHelp::~TFontSmallHelp() {}

TFontSmallHelp::TFontSmallHelp(u32 player, u32 text_color, s32 lifetime, u32 text_id)
    : TObject(get_instance__15TWindowCtrlMainFv()) {
    m_name = lbl_805D2B20;
    HelpTextPlayerState *owner = (HelpTextPlayerState *)get_player_by_client_id(player);
    if (owner == NULL) {
        disallow_rendering__7TObjectFv(this);
        queue_destruction__7TObjectFv(this);
        return;
    }
    player_id = player;
    VecCopy(&position, &owner->position);
    owner_identity = owner->identity;
    set_color(text_color);
    age_ticks = 0;
    lifetime_ticks = lifetime;
    set_help_text((const char *)text_id);
}
