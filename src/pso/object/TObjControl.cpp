#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"

#include "pso/system/vector.h"

#include "pso/object/base/TObjChara.h"

#include "pso/enemy/TUnk_80493450.h"

#include "pso/object/TObjControl.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/player/TObjPlayer.h"

#include "pso/system/task/TObject.h"

#include "pso/unk/TLobby.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

#include "pso/unk/TLobby_800F7744.h"

#include "pso/system/ControllerInputState.h"

#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"

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


extern uaddr TObjPlayer__data_8050D460[];

struct Msg_800F641C { u8 code; u8 size; u16 id; s32 arg; };

struct Obj_800F641C { u8 pad[0x1c]; u16 id; };

struct Msg_800F6464 { u8 pad0[2]; u16 f2; u16 f4; s16 f6; u32 f8; };

struct Msg_800F62E0 { u8 pad0[2]; u16 id; s32 flags; };

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
};

typedef struct TObjPlayer_800F6B68 {
    u8 pad[0x2D6];
    u16 attacker_id;
} TObjPlayer_800F6B68;

struct A_800F698C {
    u8 pad0[0x1C]; u16 f1C; u8 pad1E[0x28 - 0x1E]; s16 f28; s16 f2A; s16 f2C;
    u8 pad2E[0x38 - 0x2E]; Vec v38; u8 pad44[0x50 - 0x44]; Vec v50; Vec v5C;
    u8 pad68[0x160 - 0x68]; SubtractiveRng rng; u8 pad248[0x354 - 0x248]; f32 f354[5]; s32 f368; s32 f36C;
};

struct B_800F698C {
    s16 f0; u8 pad2[4]; u16 f6; s16 f8; s16 fA; u8 padC[4]; Vec v10; Vec v1C; f32 f28[5]; s16 f3C; s16 f3E;
};

struct Node_800F6E2C {
    u8 pad0[0x340];
    Node_800F6E2C *f340;
    Node_800F6E2C *f344;
    Node_800F6E2C *f348;
    Node_800F6E2C *f34C;
};


u16 obj_getArrU16_FC(void *, int);


s16 get_attack_params_atp_min(void *);



s16 get_attack_params_atp_max(void *);


s32 is_split_screen();

s32 get_current_floor();



void handle_6x9C_set_enemy_low_game_flags_ultimate(Msg_800F62E0 *arg0);

void handle_6x0A_update_enemy_state(Msg_800F6464 *arg0);

void award_enemy_experience__9TObjEnemyFl(u8 *arg0, s32 arg1);

void link_chain_nodes__10TObjPlayerFPvPvPv(void *arg0, Node_800F6E2C *arg1, Node_800F6E2C *arg2);

void apply_by_index__9TObjEnemyFs(s16, void *);

s32 get_attack_credit_slot_count(void *);

f32 TLobby__sub_800F7A6C();

f32 TLobby__sub_800F7A7C();

s32 create_font_small_task(void *, s32, s32, s32, const char *, s32, u16);

int send_6x60_standard_drop_item_request(void*);

s32 fn_801B0480(void *, void *, s32);

s32 draw_player_status(void *, void *, const char *);

s32 submit_cursor_candidate(void *, int);

TObjPlayer *get_player_by_client_id(u16);

s32 minimap_render_dot(void *, int, int, int);

}

void init_6x9C_enemy_low_game_flags_packet(u8 *arg0);

extern EnemyStateRecord *TLobby__data_805D6144;

extern u8 lobby_rule_settings[];

s32 area_random_seed;

extern s32 game_difficulty_selection;

struct Ene_800F6510 { u8 pad[0x2C]; s16 f2C; u8 pad2E[0x302]; u32 low_game_flags; };

void init_6x0A_enemy_state_packet(void *);

void send_6x0A_enemy_state_packet(void *);

#define FIND_TAIL_800F7118(q) \
    if (self->next == NULL && tail == NULL) { \
        while (q->next != NULL) { \
            q = q->next; \
        } \
        tail = q; \
    }

extern "C" {

s32 copy_header__6TLobbyFPv(s32);
}


#pragma push
#pragma readonly_strings on
const char *TObjEnemy_class_name = "TObjEnemy";
const char *TObjControl__name = "TObjControl";
#pragma pop

void TObject::resume_update() { m_flags &= ~PAUSE_UPDATE; }

void TObjCollidable::set_shadow_flag() { this->m_flags |= 0x400; }

void TObjCollidable::clear_shadow_flag() { this->m_flags &= 0xfffffbff; }

int TObjEnemy::apply_player_54a00() { return unregister_object_by_id(); }

s32 TObjEnemy::apply_by_index(s16 index) {
    if (index > 0xB4F) {
        return 0;
    }
    copy_header__6TLobbyFPv((saddr)TLobby__data_805D6144 + (index * 0xC));
    return 1;
}

TObjEnemy::TObjEnemy(TObject *parent) : TObjChara(parent) {
    m_name = TObjEnemy_class_name;
    targetId = 0xFFFF;
    variant = 0;
    state36C = 0;
    control = 0;
    subtype = 0;
    group = 0;
    previous = 0;
    next = 0;
    children = 0;
    movementParameters = 0;
    resetTimer = 0;
    timer = 0;
    referenceHp = hp;
    for (int i = 0; i < 5; ++i) {
        parameters[i] = 0.0f;
    }
    actorFlags |= 0x20000000;
    this->motion_flags |= 1;
}

TObjEnemy::~TObjEnemy() {
    u16 temp_r0;
    this->apply_player_54a00();
    if ((u32) *(u32 *)((s8 *)this + 0x80) != 0U) {
        temp_r0 = this->entity_id;
        if ((temp_r0 >= 0x1000U) && (temp_r0 < 0x4000U)) {
            this->mask_sub_flags(-3);
            *(u32 *)((s8 *)this + 0x80) = 0U;
        }
    }
}

void TLobby::clear_flag_on_phase_e() {
    if (get_main_phase() == 0xE) {
        area_random_seed = 0;
    }
}

void TLobby__sub_800F7744(void) {  }

s32 TObjEnemy::bind_enemy_combat_stats(u8 *arg1, u8 *arg2, u8 *arg3) {
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    s16 temp_r0;
    s16 temp_r0_2;
    s16 temp_r0_3;
    s16 temp_r0_4;
    s16 attack_params_atp_max;
    player_stats *temp_r4;
    player_stats *temp_r6;

    if (arg1 != NULL) {
        this->stat_block = (player_stats *)arg1;
        temp_r6 = this->stat_block;
        this->hpmax = (s16) (temp_r6->stats.hp + temp_r6->level);
        this->hp = (s16) this->hpmax;
        if (obj_testFlag_2E4(4U) != 0) {
            this->tpmax = 0;
            this->tp = 0;
        } else {
            temp_r4 = this->stat_block;
            this->tpmax = (s16) (temp_r4->stats.mst + temp_r4->level);
            this->tp = (s16) this->tpmax;
        }
        goto block_6;
    }
    if ((void *) this->stat_block == NULL) {
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
    temp_r0 = this->stat_block->stats.atp;
    this->atp = temp_r0;
    this->base_atp = temp_r0;
    attack_params_atp_max = get_attack_params_atp_max(*(u8 **)((s8 *)((u8 *)this) + 0x318));
    temp_r0_2 = attack_params_atp_max - get_attack_params_atp_min(*(u8 **)((s8 *)((u8 *)this) + 0x318));
    this->atp_range = temp_r0_2;
    this->base_atp_range = temp_r0_2;
    temp_r0_3 = this->stat_block->stats.evp + *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 0);
    this->evp = temp_r0_3;
    this->base_evp = temp_r0_3;
    temp_r0_4 = this->stat_block->stats.dfp + *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 0x1C);
    this->dfp = temp_r0_4;
    this->base_dfp = temp_r0_4;
    this->ata = (s16) (this->stat_block->stats.ata + this->attack_params->get_ata());
    this->lck = (s16) this->stat_block->stats.lck;
    this->m_2f2 = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 2);
    this->m_2f4 = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 6);
    *(s16 *)((s8 *)((u8 *)this) + 0x2F6) = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 4);
    this->m_2f8 = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 0xA);
    *(s16 *)((s8 *)((u8 *)this) + 0x2FA) = (s16) *(s16 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x31C)) + 8);
    this->adjust_atp((s32)((f32)this->get_base_atp() * this->get_status_effect_amount(2)));
    this->adjust_atp_range((s32)((f32)this->get_base_atp_range() * this->get_status_effect_amount(2)));
    this->adjust_dfp((s32)((f32)this->get_base_dfp() * this->get_status_effect_amount(3)));
    return 1;
}

TObjEnemy* TObjEnemy::groupRoot() {
    TObjEnemy* current=this;
    while(current->previous) current=current->previous;
    TObjEnemy* group=current->group;
    if(group) return group;
    return 0;
}

s32 TObjPlayer::is_action_available() {
    TObjEnemy*_w0 = (TObjEnemy*)this;
    return ((saddr)_w0->groupRoot()) ? 1 : 0;
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
        for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
            p = (Ply_800F7118 *)TObjPlayer::get_player_data(i);
            if (p == NULL || p == self) {
                continue;
            }
            id = ((TObjBase *)(p))->get_entity_id();
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

#undef FIND_TAIL_800F7118
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

#pragma push
#pragma fp_contract on
void TObjEnemy::update_prev_position() {
    u8 *arg0 = (u8 *)this;
    player_stats *temp_r3;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    temp_r3 = this->stat_block;
    if (temp_r3 != NULL) {
        this->body_center.y = (f32) ((0.5f * temp_r3->proportions) + this->body_center.y);
    }
}

#pragma pop
void TObjEnemy::award_enemy_experience(s32 arg1) {
    s32 val;
    TObjPlayer *p;

    if ((u16)arg1 >= 0x1000 || (p = get_player_by_client_id(arg1)) == NULL ||
        p->test_actor_flags(0x800) != 0 || p->get_floor() != get_current_floor()) {
        return;
    }
    val = this->stat_block->exp;
    if ((u16)arg1 == this->attacker_id) {
        if (((TLobby *)lobby_rule_settings)->get_rule_field_0() == 1) {
            fn_801B0480(p, this, 1);
            draw_player_status(p, p, "\tC1");
            draw_player_status(p, this, "\tC4");
        }
        p->add_capped_counter_999(1);
    } else {
        val *= 0.8f;
    }
    if (is_quest_active() == 1) {
        if (TLobby::is_flag_set() != 0) {
            val = (s32)((f32)val * TLobby__sub_800F7A7C());
        } else if (is_challenge_mode_active() != 0) {
            val = (s32)((f32)val * TLobby__sub_800F7A6C());
        }
    }
    p->add_actor_exp(val);
    create_font_small_task(((u8 *)this) + 0x2FC, 0xFFFF00FF, 0x14, 0x14, "EXP", val, p->get_entity_id());
}

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

int TObjEnemy::query_lobby_state() { return send_6x60_standard_drop_item_request(this); }

void TObjEnemy::refresh_lobby_state() { distribute_experience(); query_lobby_state(); }

u8 *get_enemy_entity(u16 arg0) {
    s32 low;
    s32 mid;
    s32 high;
    if (arg0 >= 0x1000 && arg0 < 0x4000) {
        high = (registered_player_count + registered_enemy_count) - 1;
        low = registered_player_count;
        while (low < high) {
            mid = (low + high) / 2;
            if (((TObjBase *)TObjPlayer__data_8050D460[mid])->get_entity_id() < arg0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        uaddr e = TObjPlayer__data_8050D460[low];
        if (e != 0 && arg0 == ((TObjBase *)e)->get_entity_id()) {
            return (u8 *)e;
        }
    }
    return 0;
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
    subtractive_rng_seed(&arg0->rng, arg0->f1C + area_random_seed);
}

void TObjEnemy::apply_enemy_state(s32 *state) {
    apply_hit_message_flags(state);
}

void TObjEnemy::apply_hit_message_flags(void *arg1_arg) {
    EnemyStateRecord *arg1 = (EnemyStateRecord *)arg1_arg;
    s32 flags;
    Pair_800F673C p;
    this->hp = this->hpmax - arg1->damage;
    if (game_difficulty_selection == 3) {
        flags = arg1->flags & ~0x3F;
    } else {
        flags = arg1->flags;
        if ((flags & 2) && test_actor_flags(2) == 0) {
            this->apply_paralysis();
        }
        if ((flags & 4) && test_actor_flags(4) == 0) {
            this->apply_shock_status();
        }
        if ((flags & 0x10) && test_actor_flags(0x10) == 0) {
            this->apply_confusion_status();
        }
        if ((flags & 0x20) && test_actor_flags(0x20) == 0) {
            this->apply_movement_ailment(0);
        }
    }
    set_actor_flags(flags);
    p.a = arg1->attack_status;
    p.b = arg1->attack_status_level;
    arg1->attack_status = 0;
    arg1->attack_status_level = 0;
    switch (p.a) {
    case 9:
    case 11:
        ((VObj_800F673C *)this)->m49(p);
        break;
    }
    p.a = arg1->defense_status;
    p.b = arg1->defense_status_level;
    arg1->defense_status = 0;
    arg1->defense_status_level = 0;
    switch (p.a) {
    case 10:
    case 12:
        ((VObj_800F673C *)this)->m50(p);
        break;
    }
}

s32 TObjEnemy::sync_enemy_state(s32 status) {
    EnemyStateRecord pkt;
    s32 ret;
    ret = 0;
    if (this->entity_id >= 0x1000 && this->entity_id < 0x4000) {
        this->exchange_object_state(&pkt, 1);
        pkt.damage = this->hpmax - this->hp;
        pkt.flags = this->actorFlags;
        switch (status) {
        case 9:
        case 11:
            pkt.attack_status = status;
            pkt.attack_status_level = 0.1f * ((f32)this->get_status_effect_timer(2) / 30.0f - 40.0f);
            break;
        case 10:
        case 12:
            pkt.defense_status = status;
            pkt.defense_status_level = 0.1f * ((f32)this->get_status_effect_timer(3) / 30.0f - 40.0f);
            break;
        }
        ret = this->exchange_object_state(&pkt, 0);
        if (ret != 0) {
            send_6x0A_enemy_state(&pkt);
        }
    }
    return ret;
}

void TObjEnemy::send_6x0A_enemy_state(void *state_in) {
    EnemyStateRecord state;
    Msg_800F6464 msg;
    u32 new_flags;
    if (((EnemyStateRecord *)state_in) != NULL) {
        ((TLobby *)(&state))->copy_header(((EnemyStateRecord *)state_in));
    } else if (this->exchange_object_state(&state, 1) == 0) {
        return;
    }
    init_6x0A_enemy_state_packet(&msg);
    msg.f2 = this->entity_id;
    msg.f4 = ((Ene_800F6510 *)this)->f2C;
    msg.f6 = state.damage;
    if (game_difficulty_selection == 3) {
        msg.f8 = state.flags & ~0x3F;
        new_flags = state.flags & 0x3F;
        new_flags &= ~((Ene_800F6510 *)this)->low_game_flags;
        if (new_flags != 0) {
            this->send_6x9C_enemy_low_game_flags(new_flags);
            ((Ene_800F6510 *)this)->low_game_flags = state.flags & 0x3F;
        }
    } else {
        msg.f8 = state.flags;
    }
    send_6x0A_enemy_state_packet(&msg);
}

void handle_6x0A_update_enemy_state(Msg_800F6464 *arg0) {
    EnemyStateRecord sp;
    u16 idx;
    TObjEnemy *e;
    ((TLobby *)arg0)->bswap_enemy_state();
    idx = arg0->f4;
    ((TLobby *)(&sp))->copy_header(&TLobby__data_805D6144[idx]);
    sp.damage = arg0->f6;
    if (game_difficulty_selection == 3) {
        sp.flags &= 0x3F;
        sp.flags = (arg0->f8 & ~0x3F) | sp.flags;
    } else {
        sp.flags = arg0->f8;
    }
    apply_by_index__9TObjEnemyFs(idx, &sp);
    e = (TObjEnemy *)get_enemy_entity(arg0->f2);
    if (e != NULL) {
        e->apply_hit_message_flags(&sp);
    }
}

void TObjEnemy::send_6x9C_enemy_low_game_flags(s32 arg) {
    Msg_800F641C msg;
    init_6x9C_enemy_low_game_flags_packet((u8 *)&msg);
    msg.id = ((Obj_800F641C *)this)->id;
    msg.arg = arg;
    ((TLobby *)(&msg))->broadcast_state();
}

void handle_6x9C_set_enemy_low_game_flags_ultimate(Msg_800F62E0 *arg0) {
    TObjChara *e;
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
    e = (TObjChara *)find_active_entity_by_id(arg0->id);
    if (e == NULL) {
        return;
    }
    if (e->all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    if (e->test_actor_flags(0x800) != 0) {
        return;
    }
    flags = arg0->flags;
    if (e->test_actor_flags(flags) != 0) {
        return;
    }
    e->set_actor_flags(flags);
    switch (flags) {
    case 2:
        e->apply_paralysis();
        break;
    case 3:
        break;
    case 4:
        e->apply_shock_status();
        break;
    case 16:
        e->apply_confusion_status();
        break;
    case 32:
        e->apply_movement_ailment(0);
        break;
    }
}

TObjControl::TObjControl(TObject *parent) : TObject(parent) {
    m_name = TObjControl__name;
    m_decision_mode = 2;
    m_reserved = 0;
}

TObjControl::~TObjControl() {}

void TObjControl::run_task() {
    s16 mode;
    TObjChara *enemy;
    ControllerInputContext *input;

    enemy = (TObjChara *)m_down;
    if (enemy == NULL) {
        queue_destruction();
        return;
    }
    if (TObjPlayer::check_demo_mode() == 0) {
        if (enemy->has_flag_0x800() != 0) {
            enemy->resume_update();
            enemy->run_death_reaction();
            return;
        }
        enemy->update_attack_stat_status();
        enemy->update_defense_stat_status();
        if (enemy->vfunc_43() == 0) {
            enemy->update_flag30_timer();
            if ((enemy->update_action_hold_status() != 0) || (enemy->update_shock_clock() != 0) || (enemy->update_movement_status() != 0)) {
                submit_cursor_candidate(enemy, -1);
                minimap_render_dot(&enemy->position, -0x5DB4, 1, 0);
                enemy->refresh_target();
                enemy->pause_update();
                return;
            }
            enemy->resume_update();
        }
        if (enemy->test_flag30_512() != 0) {
            enemy->run_hit_reaction();
            return;
        }
        if (enemy->test_flag_256() != 0) {
            enemy->run_miss_reaction();
            return;
        }
        if (!(enemy->actorFlags & 0x600000)) {
            if (enemy->controller_input != NULL) {
                m_decision_mode = 0;
            } else {
                m_decision_mode = 2;
            }
            mode = m_decision_mode;
            switch (mode) {
            case 0:
                input = enemy->controller_input;
                if (input->pressed_buttons & 4) {
                    enemy->run_attack_action();
                    return;
                }
                if (input->stick_magnitude > 0.1f) {
                    enemy->run_move_action();
                    return;
                }
                enemy->run_idle_action();
                break;
            case 1:
            case 2:
                enemy->refresh_target();
                if (enemy->has_no_target() != 0) {
                    enemy->run_idle_action();
                    return;
                }
                if (enemy->test_flag_1000() != 0) {
                    enemy->run_move_action();
                    return;
                }
                if (enemy->is_target_in_attack_range() != 0) {
                    enemy->run_attack_action();
                    return;
                }
                enemy->run_move_action();
                break;

            }
        }
    }
}
