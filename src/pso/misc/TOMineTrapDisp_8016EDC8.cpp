#include "types.h"
#include "pso/system/vector.h"
#include "pso/misc/TOMineTrap.h"

extern "C" {

s32 is_locally_controlled__10TObjPlayerFPv(void);
s32 get_entity_id(void *);
f32 horizontal_distance_squared(void *, void *);
void get_player_state__6TOMineFv(void *, u16);
s32 fn_80171314(void *);
s32 TOMineTrap__sub_80171350(void);
s32 get_room__13TUnk_804B9870Fv(void *);
s32 is_technique_ready__8TTecCtrlFv(void);
u8 *get_player_by_client_id(s32);
extern const f32 lbl_805DB850;

}

class TOMineTrapDisp {
public:
    u8 pad0[0x10];
    void *data;
    u8 pad14[0x38 - 0x14];
    f32 pos[3];
    u8 pad44[0xA4 - 0x44];
    s32 state;
    u16 fA8;
    u8 padAA[2];
    u16 fAC;

    void run_task();
};

void TOMineTrapDisp::run_task() {
    void *d;
    s32 hit;
    s32 i;
    u8 *pl;

    d = data;
    switch (state) {
    case 0:
        hit = 0;
        if (TOMineTrap__sub_80171350() == 1) {
            for (i = 0; i < 4; i++) {
                pl = get_player_by_client_id(i);
                if (pl != 0 && is_locally_controlled__10TObjPlayerFPv() != 0) {
                    if (fn_80171314(pl) != 0 ||
                        (is_technique_ready__8TTecCtrlFv() != 0 && fAC == (u16)get_entity_id(pl))) {
                        if (!(horizontal_distance_squared(pos, pl + 0x38) <= lbl_805DB850)) {
                            if ((s16)get_room__13TUnk_804B9870Fv(pl) != (s16)get_room__13TUnk_804B9870Fv(this)) {
                                continue;
                            }
                        }
                        if (fA8 == (u16)get_entity_id(pl)) {
                            hit = 1;
                        }
                    }
                }
            }
        }
        if (hit != 0) {
            state = 2;
        }
        return;
    case 1:
        break;
    case 2:
        get_player_state__6TOMineFv(d, fA8);
        VecCopy((Vec *)pos, (const Vec *)(((TOMineTrap *)d)->get_mine_data_ptr()));
        break;
    case 3:
        break;
    }
}
