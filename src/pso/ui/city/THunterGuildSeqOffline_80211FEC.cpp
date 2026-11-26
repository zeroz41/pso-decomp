#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline_80211FEC.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/system/TMemberCheck.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"


extern "C" {
f32 xz_distance_squared(void *, void *);
__declspec(section ".data") f32 member_name_window_pos[2] = {219.0f, 100.0f};

    extern int hunter_guild_online_client_instance_table[];
int get_online_client_instance(int a0) {  return hunter_guild_online_client_instance_table[a0]; }

    extern int hunter_guild_online_server_instance_table[];
int get_online_server_instance(int a0) {  return hunter_guild_online_server_instance_table[a0]; }

void *THunterGuildSeqOffline::create(void *player) {
    return new THunterGuildSeqOffline(tl_05, (TObjPlayer *)player);
}

int get_offline_instance(int a0) {  return THunterGuildSeqOffline::instance_table[a0]; }

s32 is_near_designated_player(void) {
    TObjPlayer *player;
    TObjPlayer *designated_player;
    s32 area;
    if ((s32) designated_client_id == (s32) local_client_id) {
        return 0;
    }
    player = get_player_by_client_id(local_client_id);
    if (player == NULL) {
        return 0;
    }
    area = player->get_area();
    if ((area != 0x12) && ((area >= 0x12) || (area != 0))) {
        return 0;
    }
    designated_player = get_player_by_client_id(designated_client_id);
    if (designated_player == NULL) {
        return 0;
    }
    return (u32)__cntlzw((u32)((xz_distance_squared(&player->position, &designated_player->position) > 625.0f))) >> 5;
}

s32 THunterGuildSeqOffline::check_party_gathered() {
    s32 i;
    s32 result;
    s32 j;
    TObjPlayer *me;
    f32 lim;
    TObjPlayer *p;
    if (TObjPlayer::get_player_count() != 0 && TLobby::count_members() == 1) {
        return 2;
    }
    if (is_challenge_mode() != 0 && TLobby::count_members() == 1) {
        return 2;
    }
    for (i = 0; i < 4; i++) {
        TObjPlayer *q = get_player_by_client_id(i);
        if (q != 0) {
            switch (q->get_area()) {
            case 0:
            case 0x12:
                break;
            default:
                return 0;
            }
        }
    }
    result = 1;
    me = get_player_by_client_id(designated_client_id);
    lim = 625.0f;
    for (j = 0; j < 4; j++) {
        if (j != designated_client_id) {
            p = get_player_by_client_id(j);
            if (p != 0 && xz_distance_squared(&me->position, &p->position) > lim) {
                result = 0;
            }
        }
    }
    return result;
}

void TMemberCheck::update_member_proximity() {
    TObjPlayer *designated_player;
    TObjPlayer *player;
    s32 i;
    if (this->member_window != 0U) {
        designated_player = get_player_by_client_id(designated_client_id);
        i = 0;
        do {
            if (i != (s32) designated_client_id) {
                player = get_player_by_client_id(i);
                if (player != 0) {
                    if (xz_distance_squared(&designated_player->position, &player->position) <= 625.0f) {
                        this->member_window->advance_matching_entries(1, i);
                    } else {
                        this->member_window->advance_matching_entries(0, i);
                    }
                } else {
                    this->member_window->advance_matching_entries(0, i);
                }
            } else {
                this->member_window->advance_matching_entries(1, i);
            }
            i += 1;
        } while (i < 4);
    }
}
void TMemberCheck::open_member_name_window() {
    s32 i;
    if (member_window != 0) {
        ((TWindowBase *)member_window)->close();
        member_window = 0;
    }
    member_window = create_check_box_window_for_local_client((const NJS_POINT2 *)get_window_layout_position(0xBD), member_name_window_pos);
    if (member_window != 0) {
        member_window->set_flag_40();
        member_window->set_close_flag();
        for (i = 0; i < 4; i++) {
            TObjPlayer *p = get_player_by_client_id(i);
            if (p != 0) {
                strcpy(names[i], p->name);
                member_window->dispatch_without_flags((saddr)names[i], (s32)i);
            } else {
                names[i][0] = 0;
                member_window->dispatch_without_flags((saddr)names[i], (s32)i);
            }
        }
    }
}

}
