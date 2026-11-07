#include "types.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TFogCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"

struct Rec_801AA17C {
    s32 kinds[4];
    s32 participants[4];
    s32 state;
};

struct Obj_801A9CB8 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x20];
    u16 id;
    u8 pad3e[0xe];
    s32 active;
    u8 pad50[0x10];
    u32 ids[4];
};

struct Obj_801A9E10 {
    u8 pad0[0x18];
    void *vt;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 count;
    f32 pos[3];
    void *player;
    u16 id;
    u8 pad3e[2];
    s32 charge;
    s32 f44;
    s32 f48;
    s32 flag4c;
    s32 vals50[4];
    u32 ids60[4];
    s32 vals70[4];
    u32 vals80[4];
    u16 held90[4];
};

extern struct Rec_801AA17C photon_blast_sequence_table[];
extern "C" {
s32 get_photon_blast_chain(struct Rec_801AA17C *output, s32 player);
void __dt__7TObjectFv(void *, int);
s32 restore_player_cameras(void);
}
void reset_cameras_to_actor(void *actor, s32 arg1);
extern "C" {
void *get_player_by_client_id(s32);
void release_photon_blast_player_holds(u16 *p);
void __dl__7TObjectFPv(void *);
void TLobby__sub_8024AC20(s32);
extern u8 __vt__13TUnk_804C349C[];
extern s32 local_client_id;
Obj_801A9CB8 *__dt__13TUnk_804C349CFv(Obj_801A9CB8 *self, s16 flag);

}
TUnk_804C349C::~TUnk_804C349C() {
    s32 i;
    s32 j;
    if (((Obj_801A9CB8 *)this)->active != 0) {
        TLobby::set_and_notify_default();
        release_photon_blast_player_holds((u16 *)((u8 *)this + 0x90));
        if (get_player_by_client_id(local_client_id) != NULL) {
            TLobby__sub_8024AC20(local_client_id);
            TCameraCtrl::release_photon_blast_camera();
            restore_player_cameras();
            reset_cameras_to_actor(get_player_by_client_id(local_client_id), 0);
        }
    } else {
        TFogCtrl::restore_fog_for_player(((Obj_801A9CB8 *)this)->id, 0);
    }
    if (((Obj_801A9CB8 *)this)->id != 0xFFFF && ((Obj_801A9CB8 *)this)->id < 4) {
        for (i = 0; i < 4; i++) {
            if (((Obj_801A9CB8 *)this)->ids[i] < 4) {
                for (j = 0; j < 4; j++) {
                    photon_blast_sequence_table[((Obj_801A9CB8 *)this)->ids[i]].kinds[j] = -1;
                    photon_blast_sequence_table[((Obj_801A9CB8 *)this)->ids[i]].participants[j] = 0xFFFF;
                }
                photon_blast_sequence_table[((Obj_801A9CB8 *)this)->ids[i]].state = 0;
            }
        }
    }
}
extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern void *tl_07;
void apply_photon_blast_action_hold__Flll(void *, s32, s32);
void freeze_players_for_photon_blast__FsPUs(s16, u16 *);
s16 get_room__8TObjBaseFv(void *);
s32 get_entity_id(void *);

#pragma push
#pragma opt_common_subs off
Obj_801A9E10 *TObjPlayer__sub_801A9E10(Obj_801A9E10 *self, s32 client_id,
                                       u8 *targets, s32 *arr, s32 flag,
                                       s32 val) {
    s32 i;
    s32 j;
    s32 n;
    void *pl;
    u8 *e;

    __ct__7TObjectFP7TObject(self, tl_07);
    self->vt = __vt__13TUnk_804C349C;
    self->id = client_id;
    self->f48 = val;
    self->f44 = 0;
    self->flag4c = flag;
    {
        volatile s32 *w = (volatile s32 *)(void *)self;
        volatile u16 *h = (volatile u16 *)(void *)self;
        for (i = 0; i < 4; i++) {
            w[i + 0x1C] = arr[i] + 1;
            w[i + 0x14] = -1;
            h[i + 0x48] = 0xFFFF;
        }
    }
    self->charge = 0;
    pl = get_player_by_client_id(client_id);
    if (pl != NULL) {
        self->charge = ((TObjPlayer *)pl)->get_photon_blast_charge();
    }
    for (i = 0; i < 4; i++) {
        self->ids60[i] = 0xFFFF;
    }
    self->count = 4;
    for (n = 0; n < 4; n++) {
        if (TObjPlayer__sub_80313114(targets) == -1) {
            self->count = n;
            break;
        }
        *(s32 *)((u8 *)self + (0x50 + n * 4)) =
            TObjPlayer__sub_80313114(targets);
        *(u32 *)((u8 *)self + (0x60 + n * 4)) =
            (u16)((TObjPlayer *)targets)->get_section_id();
        targets += 0x18;
    }
    self->player = get_player_by_client_id(client_id);
    apply_photon_blast_action_hold__Flll(self, self->count * 150 + 100,
                                         client_id);
    if (self->flag4c != 0) {
        TLobby::send_neg30();
        TObjPlayer__sub_8024ABDC(local_client_id);
        if (self->player != NULL) {
            VecCopy((Vec *)self->pos,
                    (const Vec *)((u8 *)self->player + 0x38));
            play_sound_effect(0x40021927, self->pos, 0, 0);
        }
        clear_photon_blast_hits();
    } else {
        clear_deferred_photon_blast_hits();
        TFogCtrl::select_fog_for_viewport(self->id, 0x3e, 0);
    }
    for (i = 0; i < 4; i++) {
        s32 *p60 = (s32 *)((u8 *)self + (0x60 + i * 4));
        if (*p60 < 4) {
            if (photon_blast_sequence_table[*p60].state != 2) {
                for (j = 0; j < 4; j++) {
                    s32 *pj = (s32 *)((u8 *)self + j * 4);
                    photon_blast_sequence_table[*p60].kinds[j] = pj[0x14];
                    photon_blast_sequence_table[*p60].participants[j] = pj[0x18];
                }
            }
            photon_blast_sequence_table[*p60].state = 2;
        }
    }
    self->f24 = 0;
    self->f1c = 0;
    self->f20 = 0;
    for (i = 0; i < 4; i++) {
        self->vals80[i] = 0xFFFF;
    }
    if (self->player != NULL) {
        pl = get_player_by_client_id(local_client_id);
        if (pl != NULL) {
            e = TObjPlayer::find_photon_blast_by_section_id(
                get_entity_id(self->player));
            if (e != NULL) {
                for (i = 0; i < 4; i++) {
                    if ((u16)((TObjPlayer *)e)->get_entity_type() !=
                            0xFFFF &&
                        (u16)((TObjPlayer *)e)->get_entity_type() !=
                            self->id) {
                        self->vals80[i] =
                            (u16)((TObjPlayer *)e)->get_entity_type();
                    }
                    e += 4;
                }
            }
        }
    }
    if (self->flag4c != 0) {
        pl = get_player_by_client_id(self->id);
        if (pl != NULL) {
            freeze_players_for_photon_blast__FsPUs(get_room__8TObjBaseFv(pl),
                                                   self->held90);
        }
    }
    return self;
}

#pragma pop
}
extern "C" {

s32 get_photon_blast_chain(struct Rec_801AA17C *output, s32 player) {
    s32 i;
    if (photon_blast_sequence_table[player].state == 0) {
        return 0;
    }
    if (photon_blast_sequence_table[player].state == 2) {
        for (i = 0; i < 4; i++) {
            output->kinds[i] = photon_blast_sequence_table[player].kinds[i];
            output->participants[i] = photon_blast_sequence_table[player].participants[i];
        }
        return 2;
    }
    if (photon_blast_sequence_table[player].state == 1) {
        for (i = 0; i < 4; i++) {
            output->kinds[i] = photon_blast_sequence_table[player].kinds[i];
            output->participants[i] = photon_blast_sequence_table[player].participants[i];
        }
        return 1;
    }
    return 0;
}
}
