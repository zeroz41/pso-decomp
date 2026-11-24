#include "types.h"
#include "pso/ui/window/TWindowDD_80346F48.h"
#include "pso/ui/window/TWindowDD.h"
#include <string.h>
#include "pso/player/PlayerSlots.h"

struct DD_80346FE4 {
    u8 pad[0x10];
    s16 *list0;
    s32 n0;
    s16 *list1;
    s32 n1;
    s16 *list2;
    s32 n2;
    s16 *list3;
    s32 n3;
};

extern "C" {
extern s32 local_client_id;
extern char **TWindowDD__player_name_buffers;
extern DD_80346FE4 *TWindowDD__word_select_lists;

    extern short lbl_805D6E24;
void TWindowDD::reset_selection() {
    menu_index = -1;
    lbl_805D6E24 = -1;
    build_item_list__9TWindowDDFPv(this);
}

void TWindowDD::update_selected_id() {
    s16 *msg = (s16 *)this;
    if ((msg[1] == 1) && (TWindowDD__sub_80346FC0(msg[2]) != 0)) {
        lbl_805D6E24 = msg[2];
    }
}
s32 TWindowDD__sub_80346FC0(s16 arg0) {
    u8 var_r3;
    var_r3 = 0;
    if ((arg0 >= 0x7F) && (arg0 <= 0x138)) {
        var_r3 = 1;
    }
    return var_r3;
}
void TWindowDD::build_player_word_lists() {
    s32 i;
    s32 n;
    s16 *list;
    s32 j;
    s32 j2;
    s32 k;
    s16 *l1;
    s16 *l2;
    s16 *l3;
    uaddr p;
    s16 v;
    n = 0;
    list = TWindowDD__word_select_lists->list0;
    list[n++] = 0x2c7;
    for (i = 0; i < 12; i++) {
        p = (uaddr)get_player_by_client_id(i);
        if (p != 0) {
            strncpy(TWindowDD__player_name_buffers[i], (char *)(p + 0x85c), 0x18);
            if (i != local_client_id) {
                list[n++] = i + 0x68c;
                if (n >= 16) {
                    break;
                }
            }
        } else {
            TWindowDD__player_name_buffers[i][0] = 0;
        }
    }
    TWindowDD__word_select_lists->n0 = n;
    j = 0;
    l1 = TWindowDD__word_select_lists->list1;
    l1[j++] = 0x2c4;
    for (k = 0; k < n - 1; k++) {
        l1[j++] = list[k + 1];
    }
    l1[j++] = 0x2c5;
    l1[j++] = 0x2c6;
    l1[j++] = 0x2c7;
    TWindowDD__word_select_lists->n1 = j;
    j2 = 0;
    l2 = TWindowDD__word_select_lists->list2;
    l3 = TWindowDD__word_select_lists->list3;
    l2[j2++] = 0x2c4;
    *l3++ = 0x2c4;
    for (k = 0; k < n - 1; k++) {
        v = list[k + 1];
        l2[j2++] = v;
        *l3++ = v;
    }
    l2[j2++] = 0x2c7;
    *l3 = 0x2c7;
    l2[j2++] = 0x2c8;
    TWindowDD__word_select_lists->n2 = j2;
    TWindowDD__word_select_lists->n3 = j2 - 1;
}

}
