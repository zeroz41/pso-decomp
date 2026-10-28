#include "types.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TWindowMeseta.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 draw_visible_window_entries(s32, s32, s32);
void *get_player_by_client_id(s32 i);
s32 draw_window_tab(s32, s32, s32, f32);

s32 TWindowMeseta::get_meseta_value() {
    TObjPlayer *player = (TObjPlayer *)get_player_by_client_id(this->m_64);
    u8 *stats;

    if (player == NULL) {
        return 0;
    }
    stats = player->get_stats();
    if (stats == NULL) {
        return 0;
    }
    return *(s32 *)(stats + 0x20);
}
void TWindowMeseta::draw_value(s32 arg1) {
    draw_window_tab(arg1, arg1 + 0x10, 3, this->m_60);
}
void TWindowMeseta::render() {
    s32 ctx;
    s32 arg0 = (s32)this;

    ctx = ((TUnk_804CE018 *)arg0)->setup_window_draw_context(arg0 + 0x6C);
    ((TWindowMeseta *)arg0)->draw_value(ctx);
    draw_visible_window_entries(arg0, arg0 + 0x24, ctx);
}

}
