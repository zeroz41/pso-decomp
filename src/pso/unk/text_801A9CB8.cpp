#include "types.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TFogCtrl.h"
#include "pso/misc/TLobby.h"

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
