#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"

struct P_802A5628 { u8 pad[0x30]; f32 x; f32 y; };

struct O_802A5628 { u8 pad[0x28]; P_802A5628 *a; P_802A5628 *b; };

struct V_802A5628 { f32 x, y; };

extern "C" {
void TWindowSubTradeMain__sub_802448E4(void *, void *);
void update_label_positions__17TWindowSubComCardFPvPv(O_802A5628 *arg0, V_802A5628 *arg1);
void TWindowSubComCard::free_windows() {
    if ((u32) this->m_28 != 0U) {
        ((TWindowSubComCard *)(this->m_28))->reparent_to_main_ctrl();
    }
    if ((u32) this->m_2c != 0U) {
        ((TWindowSubComCard *)(this->m_2c))->reparent_to_main_ctrl();
    }
}

void update_label_positions__17TWindowSubComCardFPvPv(O_802A5628 *arg0, V_802A5628 *arg1) {
    V_802A5628 v;
    P_802A5628 *p = arg0->a;
    if (p != NULL && (p->x != arg1->x || p->y != arg1->y)) {
        TWindowSubTradeMain__sub_802448E4(p, arg1);
    }
    if (arg0->b != NULL) {
        ((TChCrTagPlBack *)arg0)->get_position_offset(&v);
        p = arg0->b;
        if (p->x != v.x || p->y != v.y) {
            TWindowSubTradeMain__sub_802448E4(p, &v);
        }
    }
}

void TWindowSubComCard::update_card_slot() { void* m = *(void* *)&this->m_2c; if (m) ((TAdChrSelASlotGC *)m)->set_flag_40(); }
void TWindowSubComCard::notify_trade_main() { void* m = *(void* *)&this->m_2c; if (m) ((TWindowSubTradeMain *)m)->clear_trade_flag(); }

}
