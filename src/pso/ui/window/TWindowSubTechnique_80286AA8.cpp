#include "types.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

s32 TWindowSubTechnique::category_changed() {
    if (category_menu == NULL) {
        return 0;
    }
    if (current_category == category_menu->get_selected_value()) {
        return 0;
    }
    current_category = category_menu->get_selected_value();
    return 1;
}

struct Base_80286B0C { char pad[0x18]; };
struct VObj_80286B0C : Base_80286B0C {
    virtual void v0();
#define VV(n) virtual void v##n();
VV(1)VV(2)VV(3)VV(4)VV(5)VV(6)VV(7)VV(8)VV(9)VV(10)
VV(11)VV(12)VV(13)VV(14)VV(15)VV(16)VV(17)VV(18)VV(19)VV(20)
VV(21)VV(22)VV(23)VV(24)VV(25)VV(26)VV(27)VV(28)VV(29)VV(30)
VV(31)VV(32)VV(33)
#undef VV
    virtual s32 v36();
};



void TWindowSubTechnique::get_selection(s16 *arg0, s32 *arg1, s32 client) {
    void *player;

    player = get_player_by_client_id(client);
    if (player != NULL) {
        *arg0 = *(s16 *)((s8 *)player + 0x32E);
        *arg1 = ((VObj_80286B0C *)player)->v36();
    }
}

s32 TWindowSubTechnique::update_selection(s16 *arg0, s32 *arg1, s32 client) {
    s32 spC;
    s16 sp8;

    TWindowSubTechnique::get_selection(&sp8, &spC, client);
    if ((sp8 == (s16) *arg0) && (spC == (s32) *arg1)) {
        return 0;
    }
    *arg0 = sp8;
    *arg1 = spC;
    return 1;
}
