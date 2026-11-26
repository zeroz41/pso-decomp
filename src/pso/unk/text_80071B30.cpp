#include "pso/npc/TNpcPlayer.h"
#include "pso/quest/challenge/ChallengeStageLoadouts.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/PlayerSlots.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeModeState.h"

struct RebuildPlayersForStageHdr { u32 a, b; };

struct RebuildPlayersForStageChr {
    u8 pad0[0x31];
    u8 f31;
    u8 pad32[0x34 - 0x32];
    u32 f34;
    u8 pad38[0x50 - 0x38];
};


s32 client_cleared_stages(s32 client, s32 slot) {
    s32 *list;
    s32 n;
    s32 i;
    ChallengeClientRecords *r;

    r = &challenge_mode_state.client_records[client];
    if (r->present == 0) {
        return 0;
    }
    list = challenge_set_stage_times(&r->records, slot);
    n = challenge_set_stage_count(slot);
    for (i = 0; i < n; i++) {
        if (list[i] == 0) {
            break;
        }
    }
    return i;
}

extern "C" {
void copy_player_visual_record(void *, void *);
extern s32 local_client_id;
void TObjPlayer::rebuild_players_for_stage(s32 stage) {
    RebuildPlayersForStageHdr hdr;
    Vec pos;
    RebuildPlayersForStageChr chr;
    s32 i;
    TObjPlayer *p;
    ChallengeStageStart *t;
    ChallengeTechniqueLevel *e;
    if (stage < 0 || stage >= 0x10) {
        return;
    }
    {
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            ((TObjPlayer *)(&hdr))->clear_header_struct();
            if (p == NULL) {
                continue;
            }
            VecCopy((Vec *)&pos, (const Vec *)((u8 *)p + 0x38));
            copy_player_visual_record(&chr, (u8 *)p + 0x85c);
            ((TLobby *)(&hdr))->copy_header_struct((u8 *)p + 0xdac);
            delete p;
            switch (chr.f34 & 0xe0) {
            case 0x20:
                t = &hunter_stage_start_parameters[stage];
                break;
            case 0x40:
                t = &ranger_stage_start_parameters[stage];
                break;
            case 0x80:
                t = &force_stage_start_parameters[stage];
                break;
            default:
                t = &hunter_stage_start_parameters[stage];
                break;
            }
            {
                TPlyCharData cd;
                copy_player_visual_record(&cd.m_disp_part2, &chr);
                TObjPlayer::begin_action_state(&cd);
                TNpcPlayer::send_command(chr.f31, t->item_count, (const TPlyInventoryItem *)t->items, t->level, &cd);
                if (i == local_client_id) {
                    p = create_player_object(i, 0, &cd);
                } else {
                    p = create_player_object(i, 4, &cd);
                }
                if (p == NULL) {
                    return;
                }
            }
            ((TLobby *)((u8 *)p + 0xdac))->copy_header_struct(&hdr);
            p->set_position_from(&pos);
            p->save_previous_position();
            p->reset_motion_fields();
            p->technique_state.set_all_technique_levels(0xff);
            if (t->techniques != NULL) {
                for (e = t->techniques; e->level != 0xff; e++) {
                    TObjPlayer::set_technique_level_clamped(p, e->level, e->technique);
                }
            }
            *(s32 *)((u8 *)p + 0xd58) = 0;
        }
    }
}

}
