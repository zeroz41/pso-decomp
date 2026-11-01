#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/THunterGuildSeqOffline_80211FEC.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TLobby.h"
#include "pso/TMemberCheck.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"

struct Seq_80212304 {
    u8 pad0[0x1C];
    void *win;
    char names[4][0x18];
};

extern "C" {
f32 xz_distance_squared(void *, void *);
s32 get_player_by_client_id(int);
extern s32 TLobby__designated_client_id;
extern f32 THunterGuildSeqOffline__data_805DC648;
extern s32 local_client_id;
s32 is_flag_set__6TLobbyFv();
void *refresh_with_default_list__20TWindowSubStatusDispFll(void *, void *);
void *get_window_layout_position(s32);
char *strcpy(char *, const char *);
extern u8 member_name_window_pos[];
u8 *THunterGuildSeqOffline__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__nw__7TObjectFUl(int);

    extern int lbl_80513E70[];
int THunterGuildSeqOffline__sub_80211FEC(int a0) {  return lbl_80513E70[a0]; }

    extern int lbl_80513E60[];
int THunterGuildSeqOffline__sub_80212000(int a0) {  return lbl_80513E60[a0]; }

extern void *tl_05;

void *THunterGuildSeqOffline::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x3C);
    if (o != NULL) {
        o = THunterGuildSeqOffline__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

    extern int THunterGuildSeqOffline__instance_table[];
int THunterGuildSeqOffline__sub_80212060(int a0) {  return THunterGuildSeqOffline__instance_table[a0]; }

s32 THunterGuildSeqOffline__sub_80212074(void) {
    s32 player;
    s32 temp_r3_2;
    s32 temp_r3_3;
    if ((s32) TLobby__designated_client_id == (s32) local_client_id) {
        return 0;
    }
    player = get_player_by_client_id(local_client_id);
    if (player == 0) {
        return 0;
    }
    temp_r3_3 = ((TBoss3Volopt *)player)->get_field_3e0();
    if ((temp_r3_3 != 0x12) && ((temp_r3_3 >= 0x12) || (temp_r3_3 != 0))) {
        return 0;
    }
    temp_r3_2 = get_player_by_client_id(TLobby__designated_client_id);
    if (temp_r3_2 == 0) {
        return 0;
    }
    return (u32)__cntlzw((u32)((xz_distance_squared((void *)(player + 0x38), (void *)(temp_r3_2 + 0x38)) > (*(const f32 *)&THunterGuildSeqOffline__data_805DC648)))) >> 5;
}

s32 THunterGuildSeqOffline::check_party_gathered() {
    s32 i;
    s32 result;
    s32 j;
    s32 me;
    f32 lim;
    s32 p;
    if (TObjPlayer::get_player_count() != 0 && TLobby::count_members() == 1) {
        return 2;
    }
    if (is_flag_set__6TLobbyFv() != 0 && TLobby::count_members() == 1) {
        return 2;
    }
    for (i = 0; i < 4; i++) {
        u32 q = get_player_by_client_id(i);
        if (q != 0) {
            switch (((TBoss3Volopt *)q)->get_field_3e0()) {
            case 0:
            case 0x12:
                break;
            default:
                return 0;
            }
        }
    }
    result = 1;
    me = get_player_by_client_id(TLobby__designated_client_id);
    lim = THunterGuildSeqOffline__data_805DC648;
    for (j = 0; j < 4; j++) {
        if (j != TLobby__designated_client_id) {
            p = get_player_by_client_id(j);
            if (p != 0 && xz_distance_squared((void *)(me + 0x38), (void *)(p + 0x38)) > lim) {
                result = 0;
            }
        }
    }
    return result;
}

void TMemberCheck::update_member_proximity() {
    s32 temp_r31;
    s32 player;
    s32 var_r30;
    if (this->m_1C != 0U) {
        temp_r31 = get_player_by_client_id(TLobby__designated_client_id);
        var_r30 = 0;
        do {
            if (var_r30 != (s32) TLobby__designated_client_id) {
                player = get_player_by_client_id(var_r30);
                if (player != 0) {
                    if (xz_distance_squared((void *)(temp_r31 + 0x38), (void *)(player + 0x38)) <= THunterGuildSeqOffline__data_805DC648) {
                        ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(1, var_r30);
                    } else {
                        ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(0, var_r30);
                    }
                } else {
                    ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(0, var_r30);
                }
            } else {
                ((THunterGuildSeqOffline *)(this->m_1C))->advance_matching_entries(1, var_r30);
            }
            var_r30 += 1;
        } while (var_r30 < 4);
    }
}
void TMemberCheck::open_member_name_window() {
    Seq_80212304 *self = (Seq_80212304 *)this;
    s32 i;
    if (self->win != 0) {
        ((TWindowBase *)self->win)->close();
        self->win = 0;
    }
    self->win = refresh_with_default_list__20TWindowSubStatusDispFll(get_window_layout_position(0xBD), member_name_window_pos);
    if (self->win != 0) {
        ((TWindowSubTradeMain *)(self->win))->set_visible();
        ((TWindowSubTradeMain *)(self->win))->set_close_flag();
        for (i = 0; i < 4; i++) {
            u32 p = get_player_by_client_id(i);
            if (p != 0) {
                strcpy(self->names[i], (char *)(p + 0x85C));
                TWindowSubStatusDisp::dispatch_without_flags((s32)self->win, (s32)self->names[i], (s32)i);
            } else {
                self->names[i][0] = 0;
                TWindowSubStatusDisp::dispatch_without_flags((s32)self->win, (s32)self->names[i], (s32)i);
            }
        }
    }
}

}
