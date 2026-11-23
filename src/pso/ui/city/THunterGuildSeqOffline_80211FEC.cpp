#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline_80211FEC.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TMemberCheck.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"


struct Seq_80212304 {
    u8 pad0[0x1C];
    void *win;
    char names[4][0x18];
};

extern "C" {
f32 xz_distance_squared(void *, void *);
void *get_window_layout_position(s32);
__declspec(section ".data") f32 member_name_window_pos[2] = {219.0f, 100.0f};

    extern int THunterGuildSeqOnline_Client__instance_table[];
int THunterGuildSeqOffline__sub_80211FEC(int a0) {  return THunterGuildSeqOnline_Client__instance_table[a0]; }

    extern int THunterGuildSeqOnline_Server__instance_table[];
int THunterGuildSeqOffline__sub_80212000(int a0) {  return THunterGuildSeqOnline_Server__instance_table[a0]; }

void *THunterGuildSeqOffline::create(void *player) {
    return new THunterGuildSeqOffline(tl_05, (TObjPlayer *)player);
}

    extern int THunterGuildSeqOffline__instance_table[];
int THunterGuildSeqOffline__sub_80212060(int a0) {  return THunterGuildSeqOffline__instance_table[a0]; }

s32 THunterGuildSeqOffline__sub_80212074(void) {
    saddr player;
    saddr temp_r3_2;
    s32 area;
    if ((s32) designated_client_id == (s32) local_client_id) {
        return 0;
    }
    player = (saddr)get_player_by_client_id(local_client_id);
    if (player == 0) {
        return 0;
    }
    area = ((TObjPlayer *)player)->get_area();
    if ((area != 0x12) && ((area >= 0x12) || (area != 0))) {
        return 0;
    }
    temp_r3_2 = (saddr)get_player_by_client_id(designated_client_id);
    if (temp_r3_2 == 0) {
        return 0;
    }
    return (u32)__cntlzw((u32)((xz_distance_squared((void *)(player + 0x38), (void *)(temp_r3_2 + 0x38)) > 625.0f))) >> 5;
}

s32 THunterGuildSeqOffline::check_party_gathered() {
    s32 i;
    s32 result;
    s32 j;
    saddr me;
    f32 lim;
    saddr p;
    if (TObjPlayer::get_player_count() != 0 && TLobby::count_members() == 1) {
        return 2;
    }
    if (TLobby::is_flag_set() != 0 && TLobby::count_members() == 1) {
        return 2;
    }
    for (i = 0; i < 4; i++) {
        uaddr q = (uaddr)get_player_by_client_id(i);
        if (q != 0) {
            switch (((TObjPlayer *)q)->get_area()) {
            case 0:
            case 0x12:
                break;
            default:
                return 0;
            }
        }
    }
    result = 1;
    me = (saddr)get_player_by_client_id(designated_client_id);
    lim = 625.0f;
    for (j = 0; j < 4; j++) {
        if (j != designated_client_id) {
            p = (saddr)get_player_by_client_id(j);
            if (p != 0 && xz_distance_squared((void *)(me + 0x38), (void *)(p + 0x38)) > lim) {
                result = 0;
            }
        }
    }
    return result;
}

void TMemberCheck::update_member_proximity() {
    saddr temp_r31;
    saddr player;
    s32 i;
    if (this->m_1C != 0U) {
        temp_r31 = (saddr)get_player_by_client_id(designated_client_id);
        i = 0;
        do {
            if (i != (s32) designated_client_id) {
                player = (saddr)get_player_by_client_id(i);
                if (player != 0) {
                    if (xz_distance_squared((void *)(temp_r31 + 0x38), (void *)(player + 0x38)) <= 625.0f) {
                        ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(1, i);
                    } else {
                        ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(0, i);
                    }
                } else {
                    ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(0, i);
                }
            } else {
                ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(1, i);
            }
            i += 1;
        } while (i < 4);
    }
}
void TMemberCheck::open_member_name_window() {
    Seq_80212304 *self = (Seq_80212304 *)this;
    s32 i;
    if (self->win != 0) {
        ((TWindowBase *)self->win)->close();
        self->win = 0;
    }
    self->win = create_check_box_window_for_local_client((const NJS_POINT2 *)get_window_layout_position(0xBD), (const void *)member_name_window_pos);
    if (self->win != 0) {
        ((TWindowSubTradeMain *)(self->win))->set_visible();
        ((TWindowSubTradeMain *)(self->win))->set_close_flag();
        for (i = 0; i < 4; i++) {
            uaddr p = (uaddr)get_player_by_client_id(i);
            if (p != 0) {
                strcpy(self->names[i], (char *)(p + 0x85C));
                TWindowSubStatusDisp::dispatch_without_flags((saddr)self->win, (saddr)self->names[i], (s32)i);
            } else {
                self->names[i][0] = 0;
                TWindowSubStatusDisp::dispatch_without_flags((saddr)self->win, (saddr)self->names[i], (s32)i);
            }
        }
    }
}

}
