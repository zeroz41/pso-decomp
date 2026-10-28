#include "pso/item/ChallengeStageLoadouts.h"
#include "pso/unk/text_80071B30.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/misc/TLobby.h"

struct Vec_80071BC0 { f32 x, y, z; };

struct Hdr_80071BC0 { u32 a, b; };

struct Chr_80071BC0 {
    u8 pad0[0x31];
    u8 f31;
    u8 pad32[0x34 - 0x32];
    u32 f34;
    u8 pad38[0x50 - 0x38];
};

class TPlyCharData {
public:
    TPlyCharData();
    ~TPlyCharData();
    u8 pad[0x370];
    Chr_80071BC0 chr;
    u8 pad3c0[0x420 - 0x3c0];
};

typedef ChallengeTechniqueLevel Pair_80071BC0;

typedef ChallengeStageStart Tbl_80071BC0;

struct PBase_80071BC0 { u8 pad[0x18]; };

struct Plr_80071BC0 : PBase_80071BC0 {
    virtual void m0(s32);
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

extern "C" {
s32 get_layout_id__20TWindowSubStatusDispFv(s32);
s32 *TWindowSubStatusDisp__sub_8006F0D8(void *);
extern u8 challenge_mode_state[];
void copy_player_visual_record(Chr_80071BC0 *, void *);
Plr_80071BC0 *get_player_by_client_id(s32);
Plr_80071BC0 *create_player_object(s32, s32, TPlyCharData *);
void clamp_and_set_unit_value__10TObjPlayerFiUci(Plr_80071BC0 *, u8, s16);
void begin_action_state__10TObjPlayerFPv(TPlyCharData *);
void send_command__10TNpcPlayerFlScllPSc(u8, s32, s32, s32, TPlyCharData *);
extern s32 local_client_id;
s32 TLobby__sub_80071B30(s32 arg0, s32 arg1) {
    s32 *list;
    s32 n;
    s32 i;
    s32 *q = (s32 *)(challenge_mode_state + arg0 * 0x104 + 0x270);
    if (q[0] == 0) {
        return 0;
    }
    list = TWindowSubStatusDisp__sub_8006F0D8(q + 1);
    n = get_layout_id__20TWindowSubStatusDispFv(arg1);
    for (i = 0; i < n; i++) {
        if (list[i] == 0) {
            break;
        }
    }
    return i;
}
void TObjPlayer::rebuild_players_for_stage(s32 arg0) {
    Hdr_80071BC0 hdr;
    Vec_80071BC0 pos;
    Chr_80071BC0 chr;
    s32 i;
    Plr_80071BC0 *p;
    Tbl_80071BC0 *t;
    Pair_80071BC0 *e;
    if (arg0 < 0 || arg0 >= 0x10) {
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
            if (p != NULL) {
                p->m0(1);
            }
            switch (chr.f34 & 0xe0) {
            case 0x20:
                t = &hunter_stage_start_parameters[arg0];
                break;
            case 0x40:
                t = &ranger_stage_start_parameters[arg0];
                break;
            case 0x80:
                t = &force_stage_start_parameters[arg0];
                break;
            default:
                t = &hunter_stage_start_parameters[arg0];
                break;
            }
            {
                TPlyCharData cd;
                copy_player_visual_record(&cd.chr, &chr);
                begin_action_state__10TObjPlayerFPv(&cd);
                send_command__10TNpcPlayerFlScllPSc(chr.f31, t->item_count, (s32)t->items, t->level, &cd);
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
            ((TObjBase *)p)->set_position_from(&pos);
            ((TBoss4DarkFalz *)p)->save_position();
            p->m6();
            ((TObjPlayer *)((u8 *)p + 0x428))->set_all_technique_levels((void *)0xff);
            if (t->techniques != NULL) {
                for (e = t->techniques; e->level != 0xff; e++) {
                    clamp_and_set_unit_value__10TObjPlayerFiUci(p, e->level, e->technique);
                }
            }
            *(s32 *)((u8 *)p + 0xd58) = 0;
        }
    }
}

}
