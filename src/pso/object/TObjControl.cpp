#include "types.h"
#include "pso/system/vector.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/TObjControl.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby.h"

struct Ply_800F7118 {
    u8 pad0[0x28];
    s16 f28;
    u8 pad2A[0x30 - 0x2A];
    s32 f30;
    u8 pad34[0x334 - 0x34];
    s32 f334;
    u8 pad338[0x340 - 0x338];
    Ply_800F7118 *f340;
    Ply_800F7118 *f344;
    Ply_800F7118 *next;
    Ply_800F7118 *prev;
    u8 pad350[0x36C - 0x350];
    s32 f36C;
};

extern "C" {
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern u32 TObjPlayer__data_8050D460[];
u8 *get_enemy_entity(u16 arg0);
struct EnemyControlDispatchBase { char pad[0x18]; };

struct EnemyControlDispatch : EnemyControlDispatchBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual s32 m26();
    virtual s32 m27();
    virtual s32 m28();
    virtual s32 m29();
    virtual s32 m30();
    virtual s32 m31();
    virtual s32 m32();
    virtual void m33();
    virtual s32 m34();
    virtual void m35();
    virtual s32 m36();
    virtual s32 m37();
    virtual s32 m38();
    virtual s32 m39();
    virtual s32 m40();
    virtual s32 m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual s32 m56();
    virtual s32 m57();
    virtual s32 m58();
    virtual s32 m59();
    virtual s32 m60();
    virtual s32 m61();
};

struct Msg_800F641C { u8 code; u8 size; u16 id; s32 arg; };

struct Obj_800F641C { u8 pad[0x1c]; u16 id; };

struct Hdr_800F6464 { u32 w; u16 x; s16 y; u32 z; };

struct Base_800F6464 { u8 pad[0x18]; };

struct Ene_800F6464 : Base_800F6464 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void m78(void *);
};

struct Msg_800F6464 { u8 pad0[2]; u16 f2; u16 f4; s16 f6; u32 f8; };

struct Msg_800F62E0 { u8 pad0[2]; u16 id; s32 flags; };

struct VBase_800F62E0 { char pad[0x18]; };

struct Ene_800F62E0 : VBase_800F62E0 {
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
    virtual void m40(); virtual void m41(); virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46(s32);
    virtual void m47();
};

struct Pkt_800F65D0 {
    s32 id;
    s16 pad4;
    s16 diff;
    s8 a;
    s8 av;
    s8 b;
    s8 bv;
};

struct Pair_800F673C { s32 a; f32 b; };

struct VBase_800F673C { char pad[0x18]; };

struct VObj_800F673C : VBase_800F673C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46(s32);
    virtual void m47();
    virtual void m48();
    virtual void m49(Pair_800F673C);
    virtual void m50(Pair_800F673C);
    u8 pad1c[0x2B8 - 0x1C];
    s16 f2B8;
    u8 pad2ba[0x32C - 0x2BA];
    s16 f32C;
};

struct Msg_800F673C { u32 flags; u8 pad4[2]; s16 f6; u8 b8; u8 b9; u8 bA; u8 bB; };

struct Base_800F6960 { char pad[0x18]; };

struct VObj_800F6960 : Base_800F6960 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
};

typedef struct TObjPlayer_800F6B68 {
    u8 pad[0x2D6];
    u16 attacker_id;
} TObjPlayer_800F6B68;

struct Vec_800F698C { f32 x, y, z; };

struct A_800F698C {
    u8 pad0[0x1C]; u16 f1C; u8 pad1E[0x28 - 0x1E]; s16 f28; s16 f2A; s16 f2C;
    u8 pad2E[0x38 - 0x2E]; Vec_800F698C v38; u8 pad44[0x50 - 0x44]; Vec_800F698C v50; Vec_800F698C v5C;
    u8 pad68[0x160 - 0x68]; u8 f160[0x354 - 0x160]; f32 f354[5]; s32 f368; s32 f36C;
};

struct B_800F698C {
    s16 f0; u8 pad2[4]; u16 f6; s16 f8; s16 fA; u8 padC[4]; Vec_800F698C v10; Vec_800F698C v1C; f32 f28[5]; s16 f3C; s16 f3E;
};

struct Node_800F6E2C {
    u8 pad0[0x340];
    Node_800F6E2C *f340;
    Node_800F6E2C *f344;
    Node_800F6E2C *f348;
    Node_800F6E2C *f34C;
};

struct VBase_800F6BF0 { u8 pad[0x18]; };

struct Plr_800F6BF0 : VBase_800F6BF0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12(s32);
};

f32 TObjPlayer__sub_800192C4(s32, s32);
u16 obj_getArrU16_FC(void *, int);
s32 obj_testFlag_2E4__9TObjCharaFUl(void *, u32);
s16 get_attack_params_atp_min(void *);
s32 TObjPlayer__sub_8001943C(void *, int);
s16 TObjPlayer__sub_800194E8(void *);
s16 get_attack_params_atp_max(void *);
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
void obj_setFlags30(void *, s32);
s32 is_split_screen();
s32 get_current_floor();
void queue_destruction__7TObjectFv(void *arg0);
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
void pause_update__7TObjectFv(void *arg0);
s32 is_quest_active();
s32 is_flag_set__6TLobbyFv();
void subtractive_rng_seed(void *, s32);
Ene_800F62E0 * find_active_entity_by_id(u16);
void * __ct__11TObjControlFP7TObject(void *arg0);
void handle_6x9C_set_enemy_low_game_flags_ultimate(Msg_800F62E0 *arg0);
void handle_6x0A_update_enemy_state(Msg_800F6464 *arg0);
void distribute_experience__9TObjEnemyFv(TObjPlayer_800F6B68 *self);
void award_enemy_experience__9TObjEnemyFl(u8 *arg0, s32 arg1);
void link_chain_nodes__10TObjPlayerFPvPvPv(void *arg0, Node_800F6E2C *arg1, Node_800F6E2C *arg2);
void apply_by_index__9TObjEnemyFs(s16, void *);
void resume_update__7TObjectFv(void *arg0);
s32 get_attack_credit_slot_count(void *);
f32 TLobby__sub_800F7A6C();
f32 TLobby__sub_800F7A7C();
s32 create_font_small_task(void *, s32, s32, s32, s32 *, s32, u16);
int send_6x60_standard_drop_item_request(void*);
s32 fn_801B0480(void *, void *, s32);
s32 draw_player_status(void *, void *, s32 *);
s32 submit_cursor_candidate(int, int);
Plr_800F6BF0 * get_player_by_client_id(u16);
s32 minimap_render_dot(void *, int, int, int);
void __ct__7TObjectFP7TObject(void *);
s32 is_challenge_mode_active();
}
void init_6x9C_enemy_low_game_flags_packet(u8 *arg0);
extern Hdr_800F6464 *TLobby__data_805D6144;
extern s32 __vt__11TObjControl[];
extern u8 lobby_rule_settings[];
extern void *lbl_805D2B04;
extern s32 area_random_seed;
extern s32 game_difficulty_selection;
extern const f32 lbl_805DA8C0;
extern const f32 lbl_805DA8C4;
extern const f32 lbl_805DA8C8;
extern s32 lbl_805DA8CC;
extern s32 lbl_805DA8D0;
extern const f32 lbl_805DA8D4;
extern s32 lbl_805DA8D8;
extern const f32 lbl_805DA8DC;
void TObjControl::run_task() {
    s16 mode;
    u8 *enemy;
    u8 *control_record;

    enemy = (u8 *)m_down;
    if (enemy == NULL) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (TObjPlayer::check_demo_mode() == 0) {
        if (((EnemyControlDispatch *)(enemy))->m31() != 0) {
            resume_update__7TObjectFv((enemy));
            ((EnemyControlDispatch *)(enemy))->m61();
            return;
        }
        ((EnemyControlDispatch *)(enemy))->m39();
        ((EnemyControlDispatch *)(enemy))->m40();
        if (((EnemyControlDispatch *)(enemy))->m41() == 0) {
            ((EnemyControlDispatch *)(enemy))->m36();
            if ((((EnemyControlDispatch *)(enemy))->m34() != 0) || (((EnemyControlDispatch *)(enemy))->m38() != 0) || (((EnemyControlDispatch *)(enemy))->m37() != 0)) {
                submit_cursor_candidate((int)enemy, -1);
                minimap_render_dot(enemy + 0x38, -0x5DB4, 1, 0);
                ((EnemyControlDispatch *)(enemy))->m26();
                pause_update__7TObjectFv((enemy));
                return;
            }
            resume_update__7TObjectFv((enemy));
        }
        if (((EnemyControlDispatch *)(enemy))->m30() != 0) {
            ((EnemyControlDispatch *)(enemy))->m60();
            return;
        }
        if (((EnemyControlDispatch *)(enemy))->m29() != 0) {
            ((EnemyControlDispatch *)(enemy))->m59();
            return;
        }
        if (!(*(s32 *)((s8 *)enemy + 0x30) & 0x600000)) {
            if ((void *) *(u8 **)((s8 *)enemy + 0x314) != NULL) {
                m_decision_mode = 0;
            } else {
                m_decision_mode = 2;
            }
            mode = m_decision_mode;
            switch (mode) {
            case 0:
                control_record = (u8 *)(*(u8 **)((s8 *)enemy + 0x314));
                if (*(s32 *)((s8 *)control_record + 8) & 4) {
                    ((EnemyControlDispatch *)(enemy))->m58();
                    return;
                }
                if (*(f32 *)((s8 *)control_record + 0x24) > lbl_805DA8C0) {
                    ((EnemyControlDispatch *)(enemy))->m57();
                    return;
                }
                ((EnemyControlDispatch *)(enemy))->m56();
                break;
            case 1:
            case 2:
                ((EnemyControlDispatch *)(enemy))->m26();
                if (((EnemyControlDispatch *)(enemy))->m27() != 0) {
                    ((EnemyControlDispatch *)(enemy))->m56();
                    return;
                }
                if (((EnemyControlDispatch *)(enemy))->m32() != 0) {
                    ((EnemyControlDispatch *)(enemy))->m57();
                    return;
                }
                if (((EnemyControlDispatch *)(enemy))->m28() != 0) {
                    ((EnemyControlDispatch *)(enemy))->m58();
                    return;
                }
                ((EnemyControlDispatch *)(enemy))->m57();
                break;

            }
        }
    }
}

TObjControl::~TObjControl() {}

void *__ct__11TObjControlFP7TObject(void *control) {
    __ct__7TObjectFP7TObject(control);
    *(s32 **)((s8 *)control + 0x18) = __vt__11TObjControl;
    *(void * *)&((TObjControl *)control)->m_name = lbl_805D2B04;
    ((TObjControl *)control)->m_decision_mode = 2;
    ((TObjControl *)control)->m_reserved = 0;
    return control;
}

void handle_6x9C_set_enemy_low_game_flags_ultimate(Msg_800F62E0 *arg0) {
    Ene_800F62E0 *e;
    s32 flags;
    if (arg0 == NULL) {
        return;
    }
    if (game_difficulty_selection != 3) {
        return;
    }
    ((TLobby *)arg0)->bswap_field();
    if (arg0->id < 0x1000) {
        return;
    }
    if (arg0->id >= 0x4000) {
        return;
    }
    e = find_active_entity_by_id(arg0->id);
    if (e == NULL) {
        return;
    }
    if (((TObject *)e)->all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    if (obj_testFlags30__14TObjCollidableFUl(e, 0x800) != 0) {
        return;
    }
    flags = arg0->flags;
    if (obj_testFlags30__14TObjCollidableFUl(e, flags) != 0) {
        return;
    }
    obj_setFlags30(e, flags);
    switch (flags) {
    case 2:
        e->m43();
        break;
    case 3:
        break;
    case 4:
        e->m47();
        break;
    case 16:
        e->m45();
        break;
    case 32:
        e->m46(0);
        break;
    }
}

void TObjEnemy::send_6x9C_enemy_low_game_flags(s32 arg) {
    Msg_800F641C msg;
    init_6x9C_enemy_low_game_flags_packet((u8 *)&msg);
    msg.id = ((Obj_800F641C *)this)->id;
    msg.arg = arg;
    ((TLobby *)(&msg))->broadcast_state();
}

void handle_6x0A_update_enemy_state(Msg_800F6464 *arg0) {
    Hdr_800F6464 sp;
    u16 idx;
    Ene_800F6464 *e;
    ((TLobby *)arg0)->bswap_enemy_state();
    idx = arg0->f4;
    ((TLobby *)(&sp))->copy_header(&TLobby__data_805D6144[idx]);
    sp.y = arg0->f6;
    if (game_difficulty_selection == 3) {
        sp.w &= 0x3F;
        sp.w = (arg0->f8 & ~0x3F) | sp.w;
    } else {
        sp.w = arg0->f8;
    }
    apply_by_index__9TObjEnemyFs(idx, &sp);
    e = ((Ene_800F6464 *)get_enemy_entity(arg0->f2));
    if (e != NULL) {
        e->m78(&sp);
    }
}

struct Ene_800F6510 { u8 pad[0x2C]; s16 f2C; u8 pad2E[0x302]; u32 low_game_flags; };

void init_6x0A_enemy_state_packet(void *);
void send_6x0A_enemy_state_packet(void *);

void TObjEnemy::send_6x0A_enemy_state(void *state_in) {
    Pkt_800F65D0 state;
    Msg_800F6464 msg;
    u32 new_flags;
    if (((Pkt_800F65D0 *)state_in) != NULL) {
        ((TLobby *)(&state))->copy_header(((Pkt_800F65D0 *)state_in));
    } else if (this->exchange_object_state((s32)&state, 1) == 0) {
        return;
    }
    init_6x0A_enemy_state_packet(&msg);
    msg.f2 = this->entity_id;
    msg.f4 = ((Ene_800F6510 *)this)->f2C;
    msg.f6 = state.diff;
    if (game_difficulty_selection == 3) {
        msg.f8 = state.id & ~0x3F;
        new_flags = state.id & 0x3F;
        new_flags &= ~((Ene_800F6510 *)this)->low_game_flags;
        if (new_flags != 0) {
            this->send_6x9C_enemy_low_game_flags(new_flags);
            ((Ene_800F6510 *)this)->low_game_flags = state.id & 0x3F;
        }
    } else {
        msg.f8 = state.id;
    }
    send_6x0A_enemy_state_packet(&msg);
}

s32 TObjEnemy::vfunc_74(s32 kind) {
    Pkt_800F65D0 pkt;
    s32 ret;
    ret = 0;
    if (this->entity_id >= 0x1000 && this->entity_id < 0x4000) {
        exchange_object_state__9TObjEnemyFls(this, &pkt, 1);
        pkt.diff = this->hpmax - this->hp;
        pkt.id = this->actorFlags;
        switch (kind) {
        case 9:
        case 11:
            pkt.a = kind;
            pkt.av = lbl_805DA8C0 * ((f32)TObjPlayer__sub_8001943C(this, 2) / lbl_805DA8C4 - lbl_805DA8C8);
            break;
        case 10:
        case 12:
            pkt.b = kind;
            pkt.bv = lbl_805DA8C0 * ((f32)TObjPlayer__sub_8001943C(this, 3) / lbl_805DA8C4 - lbl_805DA8C8);
            break;
        }
        ret = exchange_object_state__9TObjEnemyFls(this, &pkt, 0);
        if (ret != 0) {
            send_6x0A_enemy_state(&pkt);
        }
    }
    return ret;
}

void TObjEnemy::apply_hit_message_flags(void *arg1_arg) {
    Msg_800F673C *arg1 = (Msg_800F673C *)arg1_arg;
    s32 flags;
    Pair_800F673C p;
    ((VObj_800F673C *)this)->f32C = ((VObj_800F673C *)this)->f2B8 - arg1->f6;
    if (game_difficulty_selection == 3) {
        flags = arg1->flags & ~0x3F;
    } else {
        flags = arg1->flags;
        if ((flags & 2) && obj_testFlags30__14TObjCollidableFUl(this, 2) == 0) {
            this->apply_paralysis();
        }
        if ((flags & 4) && obj_testFlags30__14TObjCollidableFUl(this, 4) == 0) {
            this->apply_shock_status();
        }
        if ((flags & 0x10) && obj_testFlags30__14TObjCollidableFUl(this, 0x10) == 0) {
            this->apply_confusion_status();
        }
        if ((flags & 0x20) && obj_testFlags30__14TObjCollidableFUl(this, 0x20) == 0) {
            this->apply_movement_ailment(0);
        }
    }
    obj_setFlags30(this, flags);
    p.a = arg1->b8;
    p.b = arg1->b9;
    arg1->b8 = 0;
    arg1->b9 = 0;
    switch (p.a) {
    case 9:
    case 11:
        ((VObj_800F673C *)this)->m49(p);
        break;
    }
    p.a = arg1->bA;
    p.b = arg1->bB;
    arg1->bA = 0;
    arg1->bB = 0;
    switch (p.a) {
    case 10:
    case 12:
        ((VObj_800F673C *)this)->m50(p);
        break;
    }
}

void TObjEnemy::vfunc_79(s32 *state) {
    struct VObj_800F6960 *o = (struct VObj_800F6960 *)this;
    o->m78();
}

void TObjEnemy::apply_set_data(void *arg1_arg) {
    A_800F698C *arg0 = (A_800F698C *)this;
    B_800F698C *arg1 = (B_800F698C *)arg1_arg;
    s32 i;
    arg0->f1C = arg1->f6;
    VecCopy((Vec *)&arg0->v50, (const Vec *)&arg1->v10);
    VecCopy((Vec *)&arg0->v38, (const Vec *)&arg0->v50);
    copy_xyz(&arg0->v5C, &arg1->v1C);
    for (i = 0; i < 5; i++) {
        arg0->f354[i] = arg1->f28[i];
    }
    arg0->f368 = arg1->f3C;
    arg0->f36C = arg1->f3E;
    arg0->f28 = arg1->f8;
    arg0->f2A = arg1->fA;
    arg0->f2C = arg1->f0;
    subtractive_rng_seed(arg0->f160, arg0->f1C + area_random_seed);
}

u8 *get_enemy_entity(u16 arg0) {
    s32 low;
    s32 mid;
    s32 high;
    if (arg0 >= 0x1000 && arg0 < 0x4000) {
        high = (registered_player_count + lbl_805D5870) - 1;
        low = registered_player_count;
        while (low < high) {
            mid = (low + high) / 2;
            if (get_entity_id((void *)TObjPlayer__data_8050D460[mid]) < arg0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        u32 e = TObjPlayer__data_8050D460[low];
        if (e != 0 && arg0 == get_entity_id((void *)e)) {
            return (u8 *)e;
        }
    }
    return 0;
}

void TObjPlayer::refresh_lobby_state() { distribute_experience__9TObjEnemyFv((TObjPlayer_800F6B68 *)(this)); query_lobby_state(); }

int TObjPlayer::query_lobby_state() { return send_6x60_standard_drop_item_request(this); }

void TObjEnemy::distribute_experience() {
    s32 count;
    s32 i;
    u16 id;
    if (is_split_screen() == 0) {
        ((void (*)(void *, u16))award_enemy_experience__9TObjEnemyFl)(((TObjPlayer_800F6B68 *)this), ((TObjPlayer_800F6B68 *)this)->attacker_id);
    } else {
        count = get_attack_credit_slot_count(this);
        for (i = 0; i < count; i++) {
            id = obj_getArrU16_FC(this, i);
            if (id == 0xFFFF) {
                break;
            }
            ((void (*)(void *, u16))award_enemy_experience__9TObjEnemyFl)(this, id);
        }
    }
}

void TObjEnemy::award_enemy_experience(s32 arg1) {
    s32 val;
    Plr_800F6BF0 *p;

    if ((u16)arg1 >= 0x1000 || (p = get_player_by_client_id(arg1)) == NULL ||
        ((s32 (*)(void *, int))obj_testFlags30__14TObjCollidableFUl)(p, 0x800) != 0 || ((TObjPlayer *)p)->get_floor() != get_current_floor()) {
        return;
    }
    val = *(s32 *)(this->m_2b0 + 0x1C);
    if ((u16)arg1 == this->m_2d4) {
        if (((TLobby *)lobby_rule_settings)->get_rule_field_0() == 1) {
            fn_801B0480(p, this, 1);
            draw_player_status(p, p, &lbl_805DA8CC);
            draw_player_status(p, this, &lbl_805DA8D0);
        }
        ((TObjPlayer *)p)->add_capped_counter_999(1);
    } else {
        val = (s32)((f32)val * lbl_805DA8D4);
    }
    if (is_quest_active() == 1) {
        if (is_flag_set__6TLobbyFv() != 0) {
            val = (s32)((f32)val * TLobby__sub_800F7A7C());
        } else if (is_challenge_mode_active() != 0) {
            val = (s32)((f32)val * TLobby__sub_800F7A6C());
        }
    }
    p->m12(val);
    create_font_small_task(((u8 *)this) + 0x2FC, 0xFFFF00FF, 0x14, 0x14, &lbl_805DA8D8, val, get_entity_id(p));
}

#pragma push
#pragma fp_contract on
void TObjEnemy::update_prev_position() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    temp_r3 = (unsigned char *) (this->m_2b0);
    if (temp_r3 != NULL) {
        this->m_300 = (f32) ((lbl_805DA8DC * *(f32 *)((s8 *)temp_r3 + 0x10)) + this->m_300);
    }
}
#pragma pop

void link_chain_nodes__10TObjPlayerFPvPvPv(void *arg0, Node_800F6E2C *arg1, Node_800F6E2C *arg2) {
    Node_800F6E2C *p = arg1->f34C;
    Node_800F6E2C *q = arg2->f34C;
    if (p != NULL) {
        while (p->f348 != NULL) {
            p = p->f348;
        }
        if (q == NULL) {
            if (p->f344 != NULL) {
                p->f344->f348 = NULL;
                p->f344 = NULL;
            }
            p->f340 = arg2;
            arg2->f34C = p;
            return;
        }
        while (q->f348 != NULL) {
            q = q->f348;
        }
        if (p->f344 != NULL) {
            p->f344->f348 = NULL;
        }
        p->f344 = q;
        q->f348 = p;
    }
}

void TUnk_80493450::unlink_enemy_group_relations() {
    u8 *temp_r0;
    u8 *temp_r0_2;
    u8 *temp_r0_3;
    u8 *temp_r0_4;
    u8 *temp_r0_5;
    u8 *temp_r0_6;
    u8 *temp_r0_7;
    u8 *temp_r0_8;
    u8 *temp_r0_9;
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    u8 *temp_r4_4;
    u8 *temp_r4_5;
    u8 *temp_r5;
    u8 *temp_r5_2;
    u8 *temp_r5_3;
    u8 *temp_r5_4;
    u8 *temp_r5_5;
    u8 *var_r5;
    u8 *var_r6;
    u8 *var_r6_2;
    u8 *var_r6_3;
    temp_r5 = (u8 *)this->group;
    if (temp_r5 != NULL) {
        temp_r4 = (u8 *)this->next;
        if (temp_r4 != NULL) {
            temp_r5_2 = (u8 *)this->children;
            if (temp_r5_2 != NULL) {
                temp_r0 = (u8 *)(*(u8 **)((s8 *)temp_r4 + 0x34C));
                if (temp_r0 != NULL) {
                    var_r6 = temp_r0;
while (*(u8 **)((s8 *)var_r6 + 0x348) != NULL) {
    var_r6 = *(u8 **)((s8 *)var_r6 + 0x348);
}
                    *(u8 **)((s8 *)var_r6 + 0x348) = temp_r5_2;
                    *(void **)((s8 *)this->children + 0x340) = NULL;
                    *(void **)((s8 *)this->children + 0x344) = var_r6;
                } else {
                    *(u8 **)((s8 *)temp_r4 + 0x34C) = temp_r5_2;
                    *(void **)((s8 *)this->children + 0x340) = (void *) this->next;
                }
            }
            *(void **)((s8 *)this->group + 0x34C) = (void *) this->next;
            *(void **)((s8 *)this->next + 0x340) = (void *) this->group;
            *(void **)((s8 *)this->next + 0x344) = NULL;
        } else {
            temp_r0_3 = (u8 *)this->children;
            if (temp_r0_3 != NULL) {
                *(u8 **)((s8 *)temp_r5 + 0x34C) = temp_r0_3;
                *(void **)((s8 *)this->children + 0x340) = (void *) this->group;
            } else {
                *(u8 **)((s8 *)temp_r5 + 0x34C) = NULL;
            }
        }
    } else {
        temp_r5_3 = (u8 *)this->previous;
        if (temp_r5_3 != NULL) {
            temp_r4_2 = (u8 *)this->next;
            if (temp_r4_2 != NULL) {
                temp_r5_4 = (u8 *)this->children;
                if (temp_r5_4 != NULL) {
                    temp_r0_4 = (u8 *)(*(u8 **)((s8 *)temp_r4_2 + 0x34C));
                    if (temp_r0_4 != NULL) {
                        var_r6_2 = temp_r0_4;
while (*(u8 **)((s8 *)var_r6_2 + 0x348) != NULL) {
    var_r6_2 = *(u8 **)((s8 *)var_r6_2 + 0x348);
}
                        *(u8 **)((s8 *)var_r6_2 + 0x348) = temp_r5_4;
                        *(void **)((s8 *)this->children + 0x340) = NULL;
                        *(void **)((s8 *)this->children + 0x344) = var_r6_2;
                    } else {
                        *(u8 **)((s8 *)temp_r4_2 + 0x34C) = temp_r5_4;
                        *(void **)((s8 *)this->children + 0x340) = (void *) this->next;
                    }
                }
                *(void **)((s8 *)this->previous + 0x348) = (void *) this->next;
                *(void **)((s8 *)this->next + 0x344) = (void *) this->previous;
            } else {
                temp_r4_3 = (u8 *)this->children;
                if (temp_r4_3 != NULL) {
                    temp_r0_6 = (u8 *)(*(u8 **)((s8 *)temp_r5_3 + 0x34C));
                    if (temp_r0_6 != NULL) {
                        var_r5 = temp_r0_6;
while (*(u8 **)((s8 *)var_r5 + 0x348) != NULL) {
    var_r5 = *(u8 **)((s8 *)var_r5 + 0x348);
}
                        *(u8 **)((s8 *)var_r5 + 0x348) = temp_r4_3;
                        *(void **)((s8 *)this->children + 0x340) = NULL;
                        *(void **)((s8 *)this->children + 0x344) = var_r5;
                    } else {
                        *(u8 **)((s8 *)temp_r5_3 + 0x34C) = temp_r4_3;
                        *(void **)((s8 *)this->children + 0x340) = (void *) this->previous;
                    }
                }
                *(void **)((s8 *)this->previous + 0x348) = NULL;
            }
        } else {
            temp_r4_4 = (u8 *)this->next;
            if (temp_r4_4 != NULL) {
                temp_r5_5 = (u8 *)this->children;
                if (temp_r5_5 != NULL) {
                    temp_r0_8 = (u8 *)(*(u8 **)((s8 *)temp_r4_4 + 0x34C));
                    if (temp_r0_8 != NULL) {
                        var_r6_3 = temp_r0_8;
while (*(u8 **)((s8 *)var_r6_3 + 0x348) != NULL) {
    var_r6_3 = *(u8 **)((s8 *)var_r6_3 + 0x348);
}
                        *(u8 **)((s8 *)var_r6_3 + 0x348) = temp_r5_5;
                        *(void **)((s8 *)this->children + 0x340) = NULL;
                        *(void **)((s8 *)this->children + 0x344) = var_r6_3;
                    } else {
                        *(u8 **)((s8 *)temp_r4_4 + 0x34C) = temp_r5_5;
                        *(void **)((s8 *)this->children + 0x340) = (void *) this->next;
                    }
                }
                *(void **)((s8 *)this->next + 0x344) = NULL;
            } else {
                temp_r4_5 = (u8 *)this->children;
                if (temp_r4_5 != NULL) {
                    *(u8 **)((s8 *)temp_r4_5 + 0x340) = NULL;
                }
            }
        }
    }
    this->group = NULL;
    this->previous = NULL;
    this->next = NULL;
    this->children = NULL;
}

#define FIND_TAIL_800F7118(q) \
    if (self->next == NULL && tail == NULL) { \
        while (q->next != NULL) { \
            q = q->next; \
        } \
        tail = q; \
    }
void TUnk_80493450::link_into_group_chain() {
    Ply_800F7118 *self = (Ply_800F7118 *)this;
    Ply_800F7118 *p;
    Ply_800F7118 *head;
    Ply_800F7118 *tail;
    s32 i;
    Ply_800F7118 *q;
    Ply_800F7118 *r;
    u16 id;
    if (*(s32 *)&this->state36C > 0 && *(Ply_800F7118 * *)&this->group == NULL && *(Ply_800F7118 * *)&this->previous == NULL) {
        head = NULL;
        tail = NULL;
        for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
            p = (Ply_800F7118 *)get_player_data__10TObjPlayerFi(i);
            if (p == NULL || p == self) {
                continue;
            }
            id = get_entity_id(p);
            if (id < 0x1000 || id >= 0x4000) {
                continue;
            }
            if (p->f30 & 0x800) {
                continue;
            }
            if (p->f36C != *(s32 *)&this->state36C || p->f28 != self->f28) {
                continue;
            }
            switch (*(s32 *)&this->subtype) {
            case 2:
                switch (p->f334) {
                case 2:
                    FIND_TAIL_800F7118(p);
                    break;
                }
                break;
            case 1:
                switch (p->f334) {
                case 2:
                    if (head == NULL) {
                        q = p->prev;
                        if (q == NULL) {
                            head = p;
                        } else FIND_TAIL_800F7118(q);
                    }
                    break;
                case 1:
                    FIND_TAIL_800F7118(p);
                    break;
                }
                break;
            case 0:
                switch (p->f334) {
                case 2:
                    if (head == NULL) {
                        q = p->prev;
                        if (q == NULL) {
                            head = p;
                        } else {
                            r = q->prev;
                            if (r == NULL) {
                                head = q;
                            } else FIND_TAIL_800F7118(r);
                        }
                    }
                    break;
                case 1:
                    q = p->prev;
                    if (q == NULL) {
                        head = p;
                    } else FIND_TAIL_800F7118(q);
                    break;
                default:
                    FIND_TAIL_800F7118(p);
                    break;
                }
                break;
            }
        }
        if (head != NULL) {
            *(Ply_800F7118 * *)&this->group = head;
            head->prev = self;
        } else if (tail != NULL) {
            *(Ply_800F7118 * *)&this->previous = tail;
            tail->next = self;
        }
    }
}

s32 TUnk_80493450::countChildren() {
    TObjEnemy* child = children;
    s32 count = 0;
    if (child) {
        TObjEnemy* cur = child;
        while ((child = cur->next) != NULL) {
            cur = child;
            ++count;
        }
        ++count;
    }
    return count;
}

s32 TObjPlayer::is_action_available() {
    TObjEnemy*_w0 = (TObjEnemy*)this;
    return ((s32)_w0->groupRoot()) ? 1 : 0;
}

TObjEnemy* TObjEnemy::groupRoot() {
    TObjEnemy* current=this;
    while(current->previous) current=current->previous;
    TObjEnemy* group=current->group;
    if(group) return group;
    return 0;
}

s32 TObjEnemy::bind_enemy_combat_stats(u8 *arg1, u8 *arg2, u8 *arg3) {
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    s16 temp_r0;
    s16 temp_r0_2;
    s16 temp_r0_3;
    s16 temp_r0_4;
    s16 attack_params_atp_max;
    u8 *temp_r4;
    u8 *temp_r6;

    if (arg1 != NULL) {
        this->m_2b0 = arg1;
        temp_r6 = this->m_2b0;
        this->hpmax = (s16) (*(s16 *)((s8 *)temp_r6 + 6) + *(s32 *)((s8 *)temp_r6 + 0x18));
        this->hp = (s16) this->hpmax;
        if (obj_testFlag_2E4__9TObjCharaFUl(this, 4U) != 0) {
            this->tpmax = 0;
            this->tp = 0;
        } else {
            temp_r4 = this->m_2b0;
            this->tpmax = (s16) (*(s16 *)((s8 *)temp_r4 + 2) + *(s32 *)((s8 *)temp_r4 + 0x18));
            this->tp = (s16) this->tpmax;
        }
        goto block_6;
    }
    if ((void *) this->m_2b0 == NULL) {
        return 0;
    }
block_6:
    if (arg2 != NULL) {
        *(u8 **)((s8 *)((u8 *)this) + 0x318) = arg2;
        goto block_10;
    }
    if ((void *) *(u8 **)((s8 *)((u8 *)this) + 0x318) == NULL) {
        return 0;
    }
block_10:
    if (arg3 != NULL) {
        *(u8 **)((s8 *)((u8 *)this) + 0x31C) = arg3;
        goto block_14;
    }
    if ((void *) *(u8 **)((s8 *)((u8 *)this) + 0x31C) == NULL) {
        return 0;
    }
block_14:
    temp_r0 = *(s16 *)(this->m_2b0 + 0);
    this->m_2c8 = temp_r0;
    this->m_2c0 = temp_r0;
    attack_params_atp_max = get_attack_params_atp_max(*(u8 **)((s8 *)((u8 *)this) + 0x318));
    temp_r0_2 = attack_params_atp_max - get_attack_params_atp_min(*(u8 **)((s8 *)((u8 *)this) + 0x318));
    *(s16 *)((s8 *)((u8 *)this) + 0x2CA) = temp_r0_2;
    *(s16 *)((s8 *)((u8 *)this) + 0x2C2) = temp_r0_2;
    temp_r0_3 = *(s16 *)(this->m_2b0 + 4) + *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 0);
    this->m_2cc = temp_r0_3;
    this->m_2c4 = temp_r0_3;
    temp_r0_4 = *(s16 *)(this->m_2b0 + 8) + *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 0x1C);
    *(s16 *)((s8 *)((u8 *)this) + 0x2CE) = temp_r0_4;
    *(s16 *)((s8 *)((u8 *)this) + 0x2C6) = temp_r0_4;
    this->m_2d0 = (s16) (*(s16 *)(this->m_2b0 + 0xA) + TObjPlayer__sub_800194E8(*(u8 **)((s8 *)((u8 *)this) + 0x318)));
    *(s16 *)((s8 *)((u8 *)this) + 0x2D2) = (s16) *(s16 *)(this->m_2b0 + 0xC);
    this->m_2f2 = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 2);
    this->m_2f4 = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 6);
    *(s16 *)((s8 *)((u8 *)this) + 0x2F6) = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 4);
    this->m_2f8 = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 0xA);
    *(s16 *)((s8 *)((u8 *)this) + 0x2FA) = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 8);
    this->add_to_field_2c8((s32)((f32)this->get_field_2c0() * TObjPlayer__sub_800192C4((s32)this, 2)));
    this->add_to_field_2ca((s32)((f32)this->get_field_2c2() * TObjPlayer__sub_800192C4((s32)this, 2)));
    this->add_to_field_2ce((s32)((f32)this->get_atp() * TObjPlayer__sub_800192C4((s32)this, 3)));
    return 1;
}
