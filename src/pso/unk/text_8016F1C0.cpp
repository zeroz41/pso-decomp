#include "types.h"
#include "pso/unk/text_8016F1C0.h"
#include "pso/misc/TOMineDisp.h"
#include "pso/system/vector.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TOMineTrap.h"

struct RecoveredGlobal_8016F1C0___vt__10TOMineDisp {
    s32 value;
    u8 remaining[0x30];
};

struct VB_8016F320 { char pad[0x18]; };

struct VO_8016F320 : VB_8016F320 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual char *m10();
};

extern "C" {
s32 __ct__13TUnk_804B9870FP7TObject();
extern RecoveredGlobal_8016F1C0___vt__10TOMineDisp __vt__10TOMineDisp;
extern s32 TOMineDisp__name;
extern const f32 lbl_805DB85C;
void *get_shared_text_buffer(void);
s32 get_trap_type__10TOMineTrapFv(s32);
s32 is_technique_ready__8TTecCtrlFv(void);
VO_8016F320 *get_player_by_client_id(u16);
void text_builder_append(const char *);
}
void text_builder_reset(void);
extern const char lbl_804421F0[];
extern const char lbl_805DB860[4];
extern "C" {
u32 TOMineTrapDisp__ct(u32, s32, u16, s32);
u32 __nw__7TObjectFUl(s32);
s32 is_split_screen();

extern s32 local_client_id;

typedef char RecoveredGlobal_8016F1C0___vt__10TOMineDisp_size[sizeof(RecoveredGlobal_8016F1C0___vt__10TOMineDisp) == 0x34 ? 1 : -1];
u8 *TOMineDisp__ct(TOMineDisp *mine_disp, s32 arg1, s16 arg2) {
    __ct__13TUnk_804B9870FP7TObject();
    *(s32 **)((s8 *)mine_disp + 0x18) = &__vt__10TOMineDisp.value;
    *(s32 *)((s8 *)mine_disp + 0) = (s32) TOMineDisp__name;
    mine_disp->m_a8 = arg2;
    *(f32 *)((s8 *)mine_disp + 0x94) = (f32) lbl_805DB85C;
    mine_disp->m_98 = (f32) lbl_805DB85C;
    *(f32 *)((s8 *)mine_disp + 0x9C) = (f32) lbl_805DB85C;
    mine_disp->m_a0 = (f32) lbl_805DB85C;
    mine_disp->m_a4 = 0;
    mine_disp->m_90 = 0;
    return (u8 *)mine_disp;
}

void TOMineTrap::spawn_disp_objects() {
    u32 mine_trap_disp;
    u16 i;
    s32 arg0 = (s32)this;

    if (is_split_screen() == 0) {
        mine_trap_disp = __nw__7TObjectFUl(0xB0);
        if (mine_trap_disp != 0U) {
            mine_trap_disp = TOMineTrapDisp__ct(mine_trap_disp, arg0, (u16) local_client_id, get_trap_type__10TOMineTrapFv(arg0));
        }
        if (mine_trap_disp != 0U) {
            VecCopy((Vec *)(mine_trap_disp + 0x50), (const Vec *)(arg0 + 0x50));
            VecCopy((Vec *)(mine_trap_disp + 0x38), (const Vec *)(arg0 + 0x38));
        }
    } else {
        for (i = 0; i != 4; i++) {
            mine_trap_disp = __nw__7TObjectFUl(0xB0);
            if (mine_trap_disp != 0U) {
                mine_trap_disp = TOMineTrapDisp__ct(mine_trap_disp, arg0, i, get_trap_type__10TOMineTrapFv(arg0));
            }
            if (mine_trap_disp != 0U) {
                VecCopy((Vec *)(mine_trap_disp + 0x50), (const Vec *)(arg0 + 0x50));
                VecCopy((Vec *)(mine_trap_disp + 0x38), (const Vec *)(arg0 + 0x38));
            }
        }
    }
}
s32 TOMineTrap::show_owner_message(s32 arg0, u32 arg1) {
    char *name;
    VO_8016F320 *p;
    if ((arg1 != 0U) && (is_technique_ready__8TTecCtrlFv() != 0)) {
        p = get_player_by_client_id(get_trap_type__10TOMineTrapFv(arg0));
        if (p != NULL) {
            name = p->m10();
            if (name != NULL) {
                text_builder_reset();
                text_builder_append(lbl_805DB860);
                text_builder_append(name);
                text_builder_append(lbl_804421F0);
                TWindowCtrl::init_all((void*)(get_shared_text_buffer()), (void*)0x200);
                return 1;
            }
        }
    }
    return 0;
}
}

#include "pso/player/TObjPlayer.h"

struct Pkt_8016F558 { u8 code, words; u16 object, sub, idx; };

struct Obj_8016F5B4 { u8 pad0[0x88]; s32 cnt; u8 pad1[0x29A]; s16 state; };

struct Obj_8016F64C { u8 pad0[0x2FC]; u8 sub[0x58]; s32 state; };

struct VBase_8016F418 { u8 pad[0x18]; };

struct VObj_8016F418 : VBase_8016F418 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84();
};

struct Pkt_8016F418 { u8 pad[4]; u16 id; u16 kind; };

extern "C" {
void TOMineTrap__sub_8017141C(void *);
s32 check_value_equals__13TUnk_804B6C24Fl(u32, int);
extern s32 TOMineTrap__data_805D3080;
f32 TOMineTrap__vt20(Obj_8016F5B4 *arg0, u32 arg1);
void *spawn_particle_effect(void *pos, s32 id);
extern const f32 lbl_805DB864;
int get_player_data__10TObjPlayerFi(int a0);
s16 TOMineTrap__sub_80171340(void *);
u16 TOMineTrap__sub_80171358(void *);
extern s32 lbl_805D5868;
extern s32 lbl_805D586C;
extern s32 lbl_805D5870;
void handle_6x80_trigger_trap(Pkt_8016F418 *arg0);

const char *TOMineTrap::get_name() {
    const char *name;
    TObjPlayer *player;

    name = NULL;
    player = (TObjPlayer *)get_player_by_client_id((u16)get_trap_type__10TOMineTrapFv((s32)this));
    if (player != NULL) {
        name = player->get_name();
    }
    return name;
}

void handle_6x80_trigger_trap(Pkt_8016F418 *arg0) {
    VObj_8016F418 *p;
    s32 i;
    if (arg0 == NULL) {
        return;
    }
    ((TOMineTrap *)arg0)->bswap_6x80_trigger_trap();
    for (i = lbl_805D586C + lbl_805D5870; i < lbl_805D5868; i++) {
        p = (VObj_8016F418 *)get_player_data__10TObjPlayerFi(i);
        if (p == NULL) {
            continue;
        }
        if (check_value_equals__13TUnk_804B6C24Fl((u32)p, TOMineTrap__data_805D3080) == 0) {
            continue;
        }
        if (arg0->id != TOMineTrap__sub_80171358(p)) {
            continue;
        }
        switch (arg0->kind) {
        case 0:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
                p->m84();
                break;
            }
            break;
        case 1:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
            case 2:
                ((TOMineTrap *)p)->set_triggered();
                break;
            }
            break;
        case 2:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
            case 2:
            case 3:
                ((TOMineTrap *)p)->set_state();
                break;
            }
            break;
        }
        return;
    }
}

void TOMineTrap::send_state_packet(u16 idx) {
    TOMineTrap *self = this;
    if (idx < 3) {
        Pkt_8016F558 pkt;
        TOMineTrap__sub_8017141C(&pkt);
        pkt.object = self->m_1c;
        pkt.sub = self->m_37e;
        pkt.idx = idx;
        ((TOMineTrap *)(&pkt))->send_and_handle_60();
    }
}
f32 TOMineTrap__vt20(Obj_8016F5B4 *arg0, u32 arg1) {
    switch (arg0->state) {
    case 0:
    case 1:
    case 2:
        if ((arg1 != 0U) && (check_value_equals__13TUnk_804B6C24Fl(arg1, TOMineTrap__data_805D3080) != 0)) {
            ((TOMineTrap *)arg0)->set_triggered();
            if (arg0->cnt > 0xF) {
                arg0->cnt = 0xF;
            }
            break;
        }
    case 3:
        ((TOMineTrap *)arg0)->set_state();
        ((TOMineTrap *)arg0)->send_state_packet((u16)(2));
        break;
    }
    return lbl_805DB85C;
}
void TOMineTrap::vfunc_82() {
    Obj_8016F64C *arg0 = (Obj_8016F64C *)this;
    u32 r;
    switch (this->m_354) {
    default:
        r = (u32)spawn_particle_effect(arg0->sub, 0x45);
        if (r != 0U) {
            ((TObjPlayer *)r)->set_position_xy(lbl_805DB864, lbl_805DB864);
        }
        break;
    case 15:
    case 16:
    case 17:
    case 18:
        spawn_particle_effect(arg0->sub, 0x8E);
        spawn_particle_effect(arg0->sub, 0x8E);
        break;
    case 6:
    case 7:
        spawn_particle_effect(arg0->sub, 0x8D);
        spawn_particle_effect(arg0->sub, 0x8D);
        break;
    }
}

}
