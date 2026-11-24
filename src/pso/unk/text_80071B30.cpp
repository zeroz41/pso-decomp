#include "pso/npc/TNpcPlayer.h"
#include "pso/quest/challenge/ChallengeStageLoadouts.h"
#include "pso/unk/text_80071B30.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/player/PlayerSlots.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/unk/TLobby.h"

struct Hdr_80071BC0 { u32 a, b; };

struct Chr_80071BC0 {
    u8 pad0[0x31];
    u8 f31;
    u8 pad32[0x34 - 0x32];
    u32 f34;
    u8 pad38[0x50 - 0x38];
};

typedef ChallengeTechniqueLevel Pair_80071BC0;

typedef ChallengeStageStart Tbl_80071BC0;

extern "C" {
s32 *TWindowSubStatusDisp__sub_8006F0D8(void *);
extern u8 challenge_mode_state[];
void copy_player_visual_record(void *, void *);
void set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(TObjPlayer *, u8, s16);
extern s32 local_client_id;
s32 TLobby__sub_80071B30(s32 arg0, s32 slot) {
    s32 *list;
    s32 n;
    s32 i;
    s32 *q = (s32 *)(challenge_mode_state + arg0 * 0x104 + 0x270);
    if (q[0] == 0) {
        return 0;
    }
    list = TWindowSubStatusDisp__sub_8006F0D8(q + 1);
    n = TWindowSubStatusDisp::get_layout_id(slot);
    for (i = 0; i < n; i++) {
        if (list[i] == 0) {
            break;
        }
    }
    return i;
}
void TObjPlayer::rebuild_players_for_stage(s32 stage) {
    Hdr_80071BC0 hdr;
    Vec pos;
    Chr_80071BC0 chr;
    s32 i;
    TObjPlayer *p;
    Tbl_80071BC0 *t;
    Pair_80071BC0 *e;
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
            ((TObjPlayer *)((u8 *)p + 0x428))->set_all_technique_levels((void *)0xff);
            if (t->techniques != NULL) {
                for (e = t->techniques; e->level != 0xff; e++) {
                    set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(p, e->level, e->technique);
                }
            }
            *(s32 *)((u8 *)p + 0xd58) = 0;
        }
    }
}

}
