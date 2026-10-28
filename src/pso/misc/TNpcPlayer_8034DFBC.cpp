#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

struct Base_8034E440 { char pad[0x18]; };

struct VObj_8034E440 : Base_8034E440 {
    virtual void m0(int);
};

struct VBase_18_dac7f3 { char pad[0x18]; };

struct VObj_18_dac7f3 : VBase_18_dac7f3 {
    virtual s32 m0(s32);
};

struct Stack_8034EA80 {
    s32 sp8;
    s16 spC;
    u8 pad_E[0x2];
    s16 sp10;
};

struct Stack_8034EAC4 {
    s32 sp8;
    s16 spC;
    u8 pad_E[0x2];
    s16 sp10;
};

struct Stack_8034EC40 {
    s32 sp8;
    s16 spC;
    u16 spE;
    s16 sp10;
    s16 sp12;
};

struct Stack_8034EB08 {
    s32 sp8;
    s16 spC;
    u16 spE;
    s16 sp10;
    s16 sp12;
};

struct E_8034E02C { u8 flag; u8 pad[0x35]; };

struct Global_8034E5A8 { u8 pad[0x46E]; s8 f46e; u8 rest[0x600 - 0x46F]; };

typedef struct NpcCreatePacket_8034EBB0 {
    u8 header[4];
    u16 leader;
    u16 slot;
    s16 zero;
    s16 appearance;
} NpcCreatePacket_8034EBB0;

struct Slot_8034EDC4 {
    s32 a[6];
    s32 b[6];
};

struct Pkt_8034E3A0 { u16 hdr; u16 id; s16 flag; s16 arg; u32 pad; f32 x, y, z; };

struct Player_8034E24C {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
};

struct Base_8034E814 { u8 pad[0x18]; };

class Obj_8034E814 : public Base_8034E814 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Pkt_8034E814 { u8 pad0[4]; u16 client; u16 target; s16 cmd; s16 state; };

struct P_8034E054 { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Pkt_8034E64C { u16 hdr; u16 id; s16 flag; s16 arg; u32 pad; f32 x, y, z; };

struct Stack_8034ECD0 {
    s32 sp8;
    s16 spC;
    u16 spE;
    s16 sp10;
    s16 sp12;
};

struct Stack_8034ED58 {
    s32 sp8;
    s16 spC;
    u16 spE;
    s16 sp10;
    s16 sp12;
};

    extern int lbl_805D6EA0;
extern "C" {
s32 get_player_by_client_id(s32);
s32 obj_isState3_324__13TUnk_804806E8Fv();
s32 set_arrival_override_coords(s32, s32, f32, f32, f32);
void send_6x21_inter_level_warp(void *obj, s32 value);
s32 get_entity_id(s32);
s32 notify_field1c__10TObjPlayerFl();
void send_6x24_teleport_player(u16 slot, void *pos, s32 heading);
void TNpcPlayer__sub_8034EDB8(void);
s32 end_camera_pan__10TObjPlayerFv();
s32 init_photon_blast__10TObjPlayerFl(u32, s16);
void set_npc_control_flag__10TNpcPlayerFPvs(void* p, s16 v);
void build_6x69_npc_control(void* p);
extern E_8034E02C npc_partner_dialogue_state[];
void clear_partner_dialogue_flags(void);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, int);
int sprintf(char *, const char *, ...);
char *strcpy(char *, const char *);
u32 strlen(const char *);
f32 atan2_float(f32, f32);
void TNpcPlayer__ct(void *, u16, u16, s16, s32, s32);
void construct_partner__10TNpcPlayerFPviisPv(void *, u16, u16, s16, s32);
s32 load_npc_player_template(s16);
Obj_8034E814 *create_player_object(u16, s32, s32);
void *__nw__7TObjectFUl(u32);
extern s32 local_client_id;
extern s32 tl_00;
void handle_6x69_npc_control(Pkt_8034E814 *pkt);
void send_6x55_intra_map_warp(u16 id, void *pos, s32 c);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);

s32 obj_isState2_324__13TUnk_804806E8Fv();
}
void quest_remove_npc_player(u16 arg0);
void show_partner_chatter_for_key(s16 key);
extern struct Slot_8034EDC4 partner_dialogue_table[];
extern s32 TNpcPlayer__data_805D5864;
void init_partner_dialogue(void);
extern const char lbl_805DFDF0[4];
void set_partner_common_remark(s32 kind, const char *text);
extern const f64 lbl_80478CB0[];
void quest_player_look_at_partner(u16 src);
void notify_partner_room_cleared(s32 arg0);
void quest_player_face_actor(u16 src, u16 dst);

void set_partner_common_remark(s32 kind, const char *text) {
    char buf[0x40];

    if (kind < 25 && strlen(text) < 53) {
        sprintf(buf, lbl_805DFDF0, text);
        strcpy((char *)&npc_partner_dialogue_state[kind], buf);
    }
}

void clear_partner_dialogue_flags(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        npc_partner_dialogue_state[i].flag = 0;
    }
}

void TNpcPlayer::send_warp_toward_player(u16 arg0, f32 *arg1) {
    s32 npc = get_player_by_client_id(arg0);
    P_8034E054 *me = (P_8034E054 *)get_player_by_client_id(local_client_id);
    if (me == NULL || arg0 == 0) return;
    if (((TNpcPlayer *)npc)->get_action_flags() != 0xFFFF) {
        send_6x55_intra_map_warp(arg0, arg1, (lbl_80478CB0[0] * atan2_float(arg1[0] - me->x, arg1[2] - me->z)));
    }
}

void TNpcPlayer::send_code_45_to_player(int arg0) {
    s32 player;

    player = get_player_by_client_id((u16) arg0);
    if ((player != 0) && (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        TObjPlayer::send_code_45_1(player);
    }
}

void TNpcPlayer::play_effect(int arg0) {
    s32 player;

    player = get_player_by_client_id((u16) arg0);
    if ((player != 0) && (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        play_effect_default__10TObjPlayerFii(player, -1);
    }
}

void quest_player_face_actor(u16 src, u16 dst) {
    struct Pkt_8034E3A0 pkt;
    Player_8034E24C *a;
    Player_8034E24C *c;
    s32 heading;
    a = (Player_8034E24C *) get_player_by_client_id(src);
    if (a == NULL) {
        return;
    }
    c = (Player_8034E24C *) get_player_by_client_id(dst);
    if (c == NULL) {
        return;
    }
    ((TNpcPlayer *)(&pkt))->init_6x3E_packet();
    obj_testFlags30__13TUnk_804AF8A0FUl(a, 0x100000);
    heading = (s32) (lbl_80478CB0[0] * atan2_float(c->x - a->x, c->z - a->z));
    pkt.id = src;
    VecCopy((Vec *)&pkt.x, (const Vec *)&a->x);
    pkt.arg = heading;
    ((TNpcPlayer *)(&pkt))->send_6x3E();
}

void quest_player_look_at_partner(u16 src) {
    struct Pkt_8034E3A0 pkt;
    Player_8034E24C *a;
    Player_8034E24C *c;
    s32 i;
    s16 flag;
    s32 heading;
    a = (Player_8034E24C *) get_player_by_client_id(src);
    if (a == NULL) {
        return;
    }
    if (obj_isState3_324__13TUnk_804806E8Fv() != 0) {
        for (i = 0; i < 4; i++) {
            if (i != src) {
                c = (Player_8034E24C *) get_player_by_client_id(i);
                if (c != NULL && obj_isState3_324__13TUnk_804806E8Fv() == 0) {
                    break;
                }
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (i != src) {
                c = (Player_8034E24C *) get_player_by_client_id(i);
                if (c != NULL && obj_isState3_324__13TUnk_804806E8Fv() != 0) {
                    break;
                }
            }
        }
    }
    if (c == NULL) {
        return;
    }
    ((TNpcPlayer *)(&pkt))->init_6x3E_packet();
    flag = 0;
    if (obj_testFlags30__13TUnk_804AF8A0FUl(a, 0x100000) != 0) {
        flag = 1;
    }
    heading = (s32) (lbl_80478CB0[0] * atan2_float(c->x - a->x, c->z - a->z));
    pkt.id = src;
    VecCopy((Vec *)&pkt.x, (const Vec *)&a->x);
    pkt.arg = heading;
    pkt.flag = flag;
    if (flag == 1) {
        ((TNpcPlayer *)(&pkt))->send_6x3E();
    } else {
        ((TNpcPlayer *)(&pkt))->send_6x3E();
    }
}

void TNpcPlayer::send_stop_at_position(u16 id, void *pos, s16 arg) {
    struct Pkt_8034E3A0 pkt;
    s16 flag;
    u8 *p;
    ((TNpcPlayer *)(&pkt))->init_6x3E_packet();
    p = (u8 *) get_player_by_client_id(id);
    flag = 0;
    if (p != NULL) {
        if (obj_testFlags30__13TUnk_804AF8A0FUl(p, 0x100000) != 0) {
            flag = 1;
        }
        pkt.id = id;
        VecCopy((Vec *)&pkt.x, (const Vec *)pos);
        pkt.arg = arg;
        pkt.flag = flag;
        ((TNpcPlayer *)(&pkt))->send_6x3E();
    }
}

void TNpcPlayer::enable_partner_chatter() { lbl_805D6EA0 = (lbl_805D6EA0 & 0xfffffffd); }
void TNpcPlayer::disable_partner_chatter() { lbl_805D6EA0 = (lbl_805D6EA0 | 0x2); }
void TNpcPlayer::enable_all_battle_ctrl() {
    s32 var_r31;
    void *player;
    var_r31 = 0;
    do {
        player = ((void *)get_player_by_client_id(var_r31));
        if ((player != NULL) && (obj_isState3_324__13TUnk_804806E8Fv() != 0) && (player != NULL)) {
            ((VObj_8034E440*)player)->m0(1);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}
void quest_remove_npc_player(u16 arg0) {
    s32 player;
    player = ((s32)((void *)get_player_by_client_id(arg0)));
    if (player != 0) {
        TObjPlayer::send_item_pickup_request(player);
        if ((u32) player != 0U) {
            ((VObj_18_dac7f3 *)(player))->m0(1);
        }
    }
}

void notify_partner_room_cleared(s32 arg0) {
    s8 *win = (s8 *)((s32 *)&npc_partner_dialogue_state) + 0x3CC;
    s32 i;
    s32 p;
    i = 0;
    do {
        p = get_player_by_client_id(i);
        if (p != 0 && obj_isState3_324__13TUnk_804806E8Fv() != 0 && arg0 == ((TUnk_804B9870 *)p)->get_room() && !(lbl_805D6EA0 & 2) && *win != 0) {
            TWindowCtrl::open((s32)((s32)(get_entity_id(p))), (s32)((void *)((s32)win)), 0x1B);
        }
        i += 1;
    } while (i < 4);
}

void show_partner_chatter_for_key(s16 key) {
    s32 i;
    s32 player;
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player && obj_isState3_324__13TUnk_804806E8Fv() && key == ((TUnk_804B9870 *)player)->get_room()
            && !(lbl_805D6EA0 & 2) && (*(Global_8034E5A8 *)&npc_partner_dialogue_state).f46e) {
            TWindowCtrl::open((s32)(get_entity_id(player)), (s32)(&(*(Global_8034E5A8 *)&npc_partner_dialogue_state).f46e), 0x1B);
        }
    }
}

void TNpcPlayer::send_6x3e_to_all_players(void *pos, s16 arg) {
    Pkt_8034E64C pkt;
    s32 i;
    s32 p;
    s16 flag;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0 && obj_isState3_324__13TUnk_804806E8Fv() != 0 && ((TNpcPlayer *)p)->get_action_flags() != 0xFFFF) {
            flag = 0;
            if (obj_testFlags30__13TUnk_804AF8A0FUl((void *)p, 0x100000) != 0) {
                flag = 1;
            }
            ((TNpcPlayer *)(&pkt))->init_6x3E_packet();
            pkt.id = get_entity_id(p);
            VecCopy((Vec *)&pkt.x, (const Vec *)pos);
            pkt.arg = arg;
            pkt.flag = flag;
            ((TNpcPlayer *)(&pkt))->send_6x3E();
        }
    }
}

void TNpcPlayer::apply_to_players(s32 arg0, void *arg1, s32 arg2) {
    s32 var_r31;
    s32 temp_r3;
    var_r31 = 0;
    do {
        temp_r3 = get_player_by_client_id(var_r31);
        if ((temp_r3 != 0) && (obj_isState3_324__13TUnk_804806E8Fv() != 0) && ((u16) ((TNpcPlayer *)temp_r3)->get_action_flags() != 0xFFFF)) {
            set_arrival_override_coords(get_entity_id(temp_r3), arg2, *(f32 *)((s8 *)arg1 + 0), *(f32 *)((s8 *)arg1 + 4), *(f32 *)((s8 *)arg1 + 8));
            send_6x21_inter_level_warp((void *)temp_r3, arg0);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}
void TNpcPlayer::send_inter_level_warp_all(s32 arg0) {
    s32 i;
    s32 player;

    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != 0 && obj_isState3_324__13TUnk_804806E8Fv() != 0 && ((TNpcPlayer *)player)->get_action_flags() != 0xFFFF) {
            send_6x21_inter_level_warp((void *)player, arg0);
        }
    }
}

#define SETFLAG_8034E814 ((void (*)(void *, u16))set_npc_control_flag__10TNpcPlayerFPvs)
#define ISSTATE3_8034E814 ((s32 (*)(void *))obj_isState3_324__13TUnk_804806E8Fv)
#define NOTIFY_8034E814 ((void (*)(void *))notify_field1c__10TObjPlayerFl)
void handle_6x69_npc_control(Pkt_8034E814 *pkt) {
    u16 client;
    Obj_8034E814 *p;
    void *o;
    s32 i;
    ((TNpcPlayer *)pkt)->byteswap_header();
    client = pkt->client;
    if (client == 0xFFFF) {
        return;
    }
    switch (pkt->cmd) {
    case 0:
        if (pkt->target == local_client_id) {
            return;
        }
        if (pkt->target == 0xFFFF) {
            return;
        }
        if (client == local_client_id) {
            p = create_player_object(pkt->target, 5, load_npc_player_template(pkt->state));
            if (p == NULL) {
                return;
            }
            p->m6();
            SETFLAG_8034E814(p, (u16)local_client_id);
            ((TNpcPlayer *)p)->set_npc_ctrl_state(pkt->state);
            o = __nw__7TObjectFUl(0xE8);
            if (o != NULL) {
                construct_partner__10TNpcPlayerFPviisPv(o, (u16)local_client_id, pkt->target, pkt->state, tl_00);
            }
        } else {
            p = create_player_object(pkt->target, 4, load_npc_player_template(pkt->state));
            if (p != NULL) {
                p->m6();
            }
        }
        break;
    case 1:
        p = (Obj_8034E814 *)get_player_by_client_id(client);
        if (p != NULL && ISSTATE3_8034E814(p) != 0) {
            SETFLAG_8034E814(p, 0xFFFF);
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            p = (Obj_8034E814 *)get_player_by_client_id(i);
            if (p != NULL && ISSTATE3_8034E814(p) != 0) {
                SETFLAG_8034E814(p, pkt->client);
            }
        }
        break;
    case 3:
        if (pkt->target == 0xFFFF) {
            return;
        }
        if (client == local_client_id) {
            p = create_player_object(pkt->target, 5, load_npc_player_template(pkt->state));
            if (p == NULL) {
                return;
            }
            NOTIFY_8034E814(p);
            p->m6();
            SETFLAG_8034E814(p, (u16)local_client_id);
            ((TNpcPlayer *)p)->set_npc_ctrl_state(pkt->state);
            o = __nw__7TObjectFUl(0xE8);
            if (o != NULL) {
                TNpcPlayer__ct(o, (u16)local_client_id, pkt->target, pkt->state, 1, tl_00);
            }
        } else {
            p = create_player_object(pkt->target, 4, load_npc_player_template(pkt->state));
            if (p != NULL) {
                p->m6();
                NOTIFY_8034E814(p);
            }
        }
        break;
    }
}

void TNpcPlayer::send_npc_control_6x69(s16 arg0) {
    Stack_8034EA80 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spC = arg0;
    stack.sp10 = 2;
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}
void TNpcPlayer::send_npc_stop_6x69(s16 arg0) {
    Stack_8034EAC4 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spC = arg0;
    stack.sp10 = 1;
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}
void TNpcPlayer::send_npc_control_create(s16 arg0, u16 arg1, s16 arg2, u8 *arg3, s32 arg4) {
    Stack_8034EB08 stack;
    s32 var_r31;
    build_6x69_npc_control(&stack.sp8);
    stack.spC = arg0;
    var_r31 = 0;
    stack.spE = 0xFFFF;
    stack.sp10 = 3;
    stack.sp12 = arg2;
loop_1:
    if (((u32)get_player_by_client_id(var_r31)) != 0U) {
        notify_field1c__10TObjPlayerFl();
    } else {
        var_r31 += 1;
        if (var_r31 < 4) {
            goto loop_1;
        }
    }
    stack.spE = arg1;
    set_arrival_override_coords(arg1, arg4, (f32) (*(f32 *)((s8 *)arg3 + 0)), (f32) (*(f32 *)((s8 *)arg3 + 4)), (f32) (*(f32 *)((s8 *)arg3 + 8)));
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void TNpcPlayer::create_companion(u16 leader, u16 slot, s32 appearance, f32 *p, s32 heading) {
    NpcCreatePacket_8034EBB0 pkt;
    build_6x69_npc_control(&pkt);
    pkt.leader = leader;
    pkt.slot = 0xFFFF;
    pkt.zero = 0;
    pkt.appearance = appearance;
    pkt.slot = slot;
    set_arrival_override_coords(slot, heading, p[0], p[1], p[2]);
    ((TNpcPlayer *)(&pkt))->send_state_60();
    send_6x24_teleport_player(pkt.slot, p, heading);
}

void TNpcPlayer::create_default_companion(s16 arg0, s16 arg1, u8 *arg2, s32 arg3) {
    Stack_8034EC40 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spE = 0xFFFF;
    stack.spC = arg0;
    stack.sp10 = 0;
    stack.sp12 = arg1;
    stack.spE = 1;
    set_arrival_override_coords((s32)(1U), arg3, *(f32 *)((s8 *)arg2 + 0), *(f32 *)((s8 *)arg2 + 4), *(f32 *)((s8 *)arg2 + 8));
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
    send_6x24_teleport_player(stack.spE, arg2, arg3);
}

void TNpcPlayer::send_npc_control_notify_players(s16 arg0, u16 arg1, s16 arg2) {
    Stack_8034ECD0 stack;
    s32 var_r31;
    build_6x69_npc_control(&stack.sp8);
    stack.spC = arg0;
    var_r31 = 0;
    stack.spE = 0xFFFF;
    stack.sp10 = 3;
    stack.sp12 = arg2;
    stack.spE = arg1;
loop_1:
    if (((u32)get_player_by_client_id(var_r31)) != 0U) {
        notify_field1c__10TObjPlayerFl();
    } else {
        var_r31 += 1;
        if (var_r31 < 4) {
            goto loop_1;
        }
    }
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void TNpcPlayer::send_npc_create(s16 arg0, s16 arg1) {
    Stack_8034ED58 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spE = 0xFFFF;
    stack.spC = arg0;
    stack.sp10 = 0;
    stack.sp12 = arg1;
    stack.spE = 1;
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void TNpcPlayer__sub_8034EDB8(void) { lbl_805D6EA0 = 0; }

void init_partner_dialogue(void) {
    s32 i;
    s32 j;
    (*(s32 *)&lbl_805D6EA0) = 0;
    clear_partner_dialogue_flags();
    TNpcPlayer__data_805D5864 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            partner_dialogue_table[i].a[j] = 0;
            partner_dialogue_table[i].b[j] = 0x19;
        }
    }
}

void TNpcPlayer::reset_player_lobby_model(u16 arg0) {
    u32 player;
    player = ((u32)get_player_by_client_id(arg0));
    if (player != 0U) {
        ((TObjPlayer *)(player + 0x644))->reset_lobby_model();
    }
}
void TNpcPlayer::update_player_field(u16 arg0, s32 arg1) {
    u32 player;
    player = ((u32)get_player_by_client_id(arg0));
    if (player != 0U) {
        ((TObjPlayer *)(player + 0x644))->set_type(arg1);
    }
}
void TNpcPlayer::end_camera_pan_for_client(u16 arg0) {
    if (((u32)get_player_by_client_id(arg0)) != 0U) {
        end_camera_pan__10TObjPlayerFv();
    }
}
void TNpcPlayer::apply_to_battle_player_slot(u16 arg0, s16 arg1) {
    u32 temp_r3;
    if ((arg1 < 0x10) && ((temp_r3 = ((u32)get_player_by_client_id(arg0))) != 0U)) {
        init_photon_blast__10TObjPlayerFl(temp_r3, arg1);
    }
}
s32 TNpcPlayer::get_field_67c() { return *(s32*)((char*)this + 0x67c); }
void TNpcPlayer::set_npc_ctrl_state(s32 v) { *(s32*)((char*)this + 0x67c) = v; }
void set_npc_control_flag__10TNpcPlayerFPvs(void* p, s16 v) { *(s16*)((char*)p + 0x678) = v; }
void TNpcPlayer::byteswap_header() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_16((u16 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xa)); }
void TNpcPlayer::send_state_60() { byteswap_header(); send_subcommand((u8 *)this); }
void build_6x69_npc_control(void* p) { *(u8*)((char*)p + 0x0) = 105; *(u8*)((char*)p + 0x1) = 3; }
