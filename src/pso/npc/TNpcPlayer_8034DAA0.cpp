#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/npc/TNpcPlayer_8034DAA0.h"
#include "pso/unk/text_8034DAA0.h"
#include "pso/npc/TNpcPlayer_8034DC20.h"
#include "pso/unk/TUnk_804F07C8.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecReverser.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801BDF5C.h"


// One TU: TLobby__sub_8034DAA0 (jumptable after the TUnk_804F07C8 vtable in .data),
// the party-area task, TTecReverser::is_active, the 4-player notifiers and the
// partner dialogue code share one .data block (dialogue state, vtable, jumptable).

struct VBase_18_dac7f3 { char pad[0x18]; };

struct VObj_18_dac7f3 : VBase_18_dac7f3 {
    virtual s32 m0(s32);
};

// One entry per partner remark kind; flag is cleared by clear_partner_dialogue_flags.
struct E_8034E02C { u8 flag; u8 pad[0x35]; };

extern "C" {
saddr get_player_by_client_id(s32);
E_8034E02C npc_partner_dialogue_state[25] = { 0 };
}

struct Vec2i_8034DAA0 {
    s32 x;
    f32 y;
};

struct Base_8034DAA0 {
    u8 pad0[0x18];
};

class Player_8034DAA0 : public Base_8034DAA0 {
public:
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
    virtual void v49(Vec2i_8034DAA0 *);
    virtual void v50(Vec2i_8034DAA0 *);
};

extern "C" {
s32 obj_getS16_2BA(Player_8034DAA0 *);
void obj_setFlags30(void *, u32);

void set_tp__10TObjPlayerFs(Player_8034DAA0 *, s32);

struct TNpcPlayerTemplateTable { s32 value; u8 remaining[0x9FC]; };
extern TNpcPlayerTemplateTable TNpcPlayer__template_table;
void construct_partner__10TNpcPlayerFPviisPv(void *, u16, u16, s32, void *);

typedef struct VBase_18_dac7f3 VBase_18_dac7f3;
typedef struct VObj_18_dac7f3 VObj_18_dac7f3;
#pragma opt_pointer_analysis on
#define PSO_VCALL_VObj_18_dac7f3_m0(_self, _arg0) (((VObj_18_dac7f3 *)(_self))->m0((_arg0)))


}


struct Base_8034E440 { char pad[0x18]; };

struct VObj_8034E440 : Base_8034E440 {
    virtual void m0(int);
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

struct Pkt_8034E814 { u8 pad0[4]; u16 client; u16 target; s16 cmd; s16 state; };


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

int lbl_805D6EA0;
extern "C" {
void set_arrival_override_coords(u16, s32, f32, f32, f32);
u16 get_entity_id(s32);
void send_6x21_inter_level_warp(void *obj, s32 value);
void send_6x24_teleport_player(u16 slot, void *pos, s32 heading);
f32 atan2_float(f32, f32);
void TNpcPlayer__ct(void *, u16, u16, s16, s32, void *);
void handle_6x69_npc_control(Pkt_8034E814 *pkt);

}
void quest_remove_npc_player(u16 arg0);
extern struct Slot_8034EDC4 partner_dialogue_table[];
extern s32 TNpcPlayer__data_805D5864;
void init_partner_dialogue(void);
void quest_player_look_at_partner(u16 src);
void notify_partner_room_cleared(s32 arg0);
void quest_player_face_actor(u16 src, u16 dst);


#define NOTIFY_8034E814(x) TObjPlayer::notify_field1c((s32)(x))


// Compiled with -inline off,deferred: the functions are written in reverse of their
// address order (the .text order is the reverse of the source order).

void build_6x69_npc_control(void* p) { *(u8*)((char*)p + 0x0) = 105; *(u8*)((char*)p + 0x1) = 3; }

void TNpcPlayer::send_state_60() { byteswap_header(); send_subcommand((u8 *)this); }

void TNpcPlayer::byteswap_header() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_16((u16 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xa)); }

void TObjPlayer::set_npc_controller(u16 client) { npc_control.controller_client_id = client; }

void TObjPlayer::set_npc_control_state(s32 state) { npc_control.state = state; }

s32 TObjPlayer::get_npc_control_state() { return npc_control.state; }

void TNpcPlayer::apply_to_battle_player_slot(u16 arg0, s16 arg1) {
    uaddr temp_r3;
    if ((arg1 < 0x10) && ((temp_r3 = ((u32)get_player_by_client_id(arg0))) != 0U)) {
        ((TObjPlayer *)temp_r3)->init_photon_blast(arg1);
    }
}

void TNpcPlayer::end_camera_pan_for_client(u16 arg0) {
    saddr tmp_player;
    if ((tmp_player = (s32)get_player_by_client_id(arg0)) != 0U) {
        ((TObjPlayer *)tmp_player)->end_camera_pan();
    }
}

void TNpcPlayer::update_player_field(u16 arg0, s32 frames) {
    uaddr player;
    player = ((u32)get_player_by_client_id(arg0));
    if (player != 0U) {
        ((TObjPlayer *)player)->protection.set_frames(frames);
    }
}

void TNpcPlayer::reset_player_lobby_model(u16 arg0) {
    uaddr player;
    player = ((u32)get_player_by_client_id(arg0));
    if (player != 0U) {
        ((TObjPlayer *)player)->protection.reset_lobby_model();
    }
}

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

void TNpcPlayer__sub_8034EDB8(void) { lbl_805D6EA0 = 0; }

void TNpcPlayer::send_npc_create(s32 arg0, s32 arg1) {
    Stack_8034ED58 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spE = 0xFFFF;
    stack.spC = arg0;
    stack.sp10 = 0;
    stack.sp12 = arg1;
    stack.spE = 1;
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void TNpcPlayer::send_npc_control_notify_players(s32 arg0, s32 arg1, s32 arg2) {
    s32 tmp_player;
    Stack_8034ECD0 stack;
    s32 var_r31;
    uaddr player;
    build_6x69_npc_control(&stack.sp8);
    stack.spC = arg0;
    var_r31 = 0;
    stack.spE = 0xFFFF;
    stack.sp10 = 3;
    stack.sp12 = arg2;
    stack.spE = arg1;
loop_1:
    if ((tmp_player = (s32)get_player_by_client_id(var_r31)) != 0U) {
        TObjPlayer::notify_field1c(tmp_player);
    } else {
        var_r31 += 1;
        if (var_r31 < 4) {
            goto loop_1;
        }
    }
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void TNpcPlayer::create_default_companion(u16 leader, s32 appearance, u8 *pos, s32 heading) {
    Stack_8034EC40 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spE = 0xFFFF;
    stack.spC = leader;
    stack.sp10 = 0;
    stack.sp12 = appearance;
    stack.spE = 1;
    set_arrival_override_coords((s32)(1U), heading, *(f32 *)((s8 *)pos + 0), *(f32 *)((s8 *)pos + 4), *(f32 *)((s8 *)pos + 8));
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
    send_6x24_teleport_player(stack.spE, pos, heading);
}

void TNpcPlayer::create_companion(u16 leader, u16 slot, s32 appearance, f32 *p, s32 heading) {
    NpcCreatePacket_8034EBB0 pkt;
    build_6x69_npc_control(&pkt);
    pkt.leader = leader;
    pkt.slot = 0xFFFF;
    pkt.zero = 0;
    pkt.appearance = appearance;
    pkt.slot = slot;
    set_arrival_override_coords(pkt.slot, heading, p[0], p[1], p[2]);
    ((TNpcPlayer *)(&pkt))->send_state_60();
    send_6x24_teleport_player(pkt.slot, p, heading);
}

void TNpcPlayer::send_npc_control_create(u16 arg0, u16 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    s32 tmp_player;
    Stack_8034EB08 stack;
    s32 var_r31;
    build_6x69_npc_control(&stack.sp8);
    uaddr player;
    stack.spC = arg0;
    var_r31 = 0;
    stack.spE = 0xFFFF;
    stack.sp10 = 3;
    stack.sp12 = arg2;
loop_1:
    if ((tmp_player = (s32)get_player_by_client_id(var_r31)) != 0U) {
        TObjPlayer::notify_field1c(tmp_player);
    } else {
        var_r31 += 1;
        if (var_r31 < 4) {
            goto loop_1;
        }
    }
    stack.spE = arg1;
    set_arrival_override_coords(stack.spE, arg4, (f32) (*(f32 *)((s8 *)arg3 + 0)), (f32) (*(f32 *)((s8 *)arg3 + 4)), (f32) (*(f32 *)((s8 *)arg3 + 8)));
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void TNpcPlayer::send_npc_stop_6x69(s32 arg0) {
    Stack_8034EAC4 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spC = arg0;
    stack.sp10 = 1;
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void TNpcPlayer::send_npc_control_6x69(s32 arg0) {
    Stack_8034EA80 stack;
    build_6x69_npc_control(&stack.sp8);
    stack.spC = arg0;
    stack.sp10 = 2;
    ((TNpcPlayer *)(&stack.sp8))->send_state_60();
}

void handle_6x69_npc_control(Pkt_8034E814 *pkt) {
    u16 client;
    TObjPlayer *p;
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
            p = (TObjPlayer *)create_player_object(pkt->target, 5, load_npc_player_template(pkt->state));
            if (p == NULL) {
                return;
            }
            p->reset_motion_fields();
            p->set_npc_controller((u16)local_client_id);
            p->set_npc_control_state(pkt->state);
            o = TObject::operator new(0xE8);
            if (o != NULL) {
                construct_partner__10TNpcPlayerFPviisPv(o, (u16)local_client_id, pkt->target, pkt->state, tl_00);
            }
        } else {
            p = (TObjPlayer *)create_player_object(pkt->target, 4, load_npc_player_template(pkt->state));
            if (p != NULL) {
                p->reset_motion_fields();
            }
        }
        break;
    case 1:
        p = (TObjPlayer *)get_player_by_client_id(client);
        if (p != NULL && p->obj_isState3_324() != 0) {
            p->set_npc_controller(0xFFFF);
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            p = (TObjPlayer *)get_player_by_client_id(i);
            if (p != NULL && p->obj_isState3_324() != 0) {
                p->set_npc_controller(pkt->client);
            }
        }
        break;
    case 3:
        if (pkt->target == 0xFFFF) {
            return;
        }
        if (client == local_client_id) {
            p = (TObjPlayer *)create_player_object(pkt->target, 5, load_npc_player_template(pkt->state));
            if (p == NULL) {
                return;
            }
            TObjPlayer::notify_field1c((saddr)p);
            p->reset_motion_fields();
            p->set_npc_controller((u16)local_client_id);
            p->set_npc_control_state(pkt->state);
            o = TObject::operator new(0xE8);
            if (o != NULL) {
                TNpcPlayer__ct(o, (u16)local_client_id, pkt->target, pkt->state, 1, tl_00);
            }
        } else {
            p = (TObjPlayer *)create_player_object(pkt->target, 4, load_npc_player_template(pkt->state));
            if (p != NULL) {
                p->reset_motion_fields();
                TObjPlayer::notify_field1c((saddr)p);
            }
        }
        break;
    }
}

void TNpcPlayer::send_inter_level_warp_all(s32 value) {
    s32 i;
    saddr player;

    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != 0 && reinterpret_cast<TObjPlayer *>(player)->obj_isState3_324() != 0 && ((TObjPlayer *)player)->get_npc_controller() != 0xFFFF) {
            send_6x21_inter_level_warp((void *)player, value);
        }
    }
}

void TNpcPlayer::apply_to_players(s32 value, void *arg1, s32 heading) {
    s32 var_r31;
    saddr temp_r3;
    var_r31 = 0;
    do {
        temp_r3 = get_player_by_client_id(var_r31);
        if ((temp_r3 != 0) && (reinterpret_cast<TObjPlayer *>(temp_r3)->obj_isState3_324() != 0) && ((u16) ((TObjPlayer *)temp_r3)->get_npc_controller() != 0xFFFF)) {
            set_arrival_override_coords(get_entity_id(temp_r3), heading, *(f32 *)((s8 *)arg1 + 0), *(f32 *)((s8 *)arg1 + 4), *(f32 *)((s8 *)arg1 + 8));
            send_6x21_inter_level_warp((void *)temp_r3, value);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

void TNpcPlayer::send_6x3e_to_all_players(void *pos, s32 arg) {
    Pkt_8034E64C pkt;
    s32 i;
    saddr p;
    s16 flag;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0 && reinterpret_cast<TObjPlayer *>(p)->obj_isState3_324() != 0 && ((TObjPlayer *)p)->get_npc_controller() != 0xFFFF) {
            flag = 0;
            if (((TObjCollidable *)p)->test_actor_flags(0x100000) != 0) {
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

void show_partner_chatter_for_key(s16 key) {
    s32 i;
    saddr player;
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player && reinterpret_cast<TObjPlayer *>(player)->obj_isState3_324() && key == ((TObjBase *)player)->get_room()
            && !(lbl_805D6EA0 & 2) && (*(Global_8034E5A8 *)&npc_partner_dialogue_state).f46e) {
            TWindowCtrl::open(get_entity_id(player), (saddr)(&(*(Global_8034E5A8 *)&npc_partner_dialogue_state).f46e), 0x1B);
        }
    }
}

void notify_partner_room_cleared(s32 arg0) {
    s8 *win = (s8 *)((s32 *)&npc_partner_dialogue_state) + 0x3CC;
    s32 i;
    saddr p;
    i = 0;
    do {
        p = get_player_by_client_id(i);
        if (p != 0 && reinterpret_cast<TObjPlayer *>(p)->obj_isState3_324() != 0 && arg0 == ((TObjBase *)p)->get_room() && !(lbl_805D6EA0 & 2) && *win != 0) {
            TWindowCtrl::open(get_entity_id(p), (saddr)((void *)((saddr)win)), 0x1B);
        }
        i += 1;
    } while (i < 4);
}

void quest_remove_npc_player(u16 arg0) {
    saddr player;
    player = ((saddr)((void *)get_player_by_client_id(arg0)));
    if (player != 0) {
        TObjPlayer::send_item_pickup_request(player);
        if ((u32) player != 0U) {
            ((VObj_18_dac7f3 *)(player))->m0(1);
        }
    }
}

void TNpcPlayer::enable_all_battle_ctrl() {
    s32 var_r31;
    void *player;
    var_r31 = 0;
    do {
        player = ((void *)get_player_by_client_id(var_r31));
        if ((player != NULL) && (((TObjChara *)player)->obj_isState3_324() != 0) && (player != NULL)) {
            ((VObj_8034E440*)player)->m0(1);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

void TNpcPlayer::disable_partner_chatter() { lbl_805D6EA0 = (lbl_805D6EA0 | 0x2); }

void TNpcPlayer::enable_partner_chatter() { lbl_805D6EA0 = (lbl_805D6EA0 & 0xfffffffd); }

void TNpcPlayer::send_stop_at_position(u16 id, void *pos, s32 arg) {
    struct Pkt_8034E3A0 pkt;
    s16 flag;
    u8 *p;
    ((TNpcPlayer *)(&pkt))->init_6x3E_packet();
    p = (u8 *) get_player_by_client_id(id);
    flag = 0;
    if (p != NULL) {
        if (((TObjCollidable *)p)->test_actor_flags(0x100000) != 0) {
            flag = 1;
        }
        pkt.id = id;
        VecCopy((Vec *)&pkt.x, (const Vec *)pos);
        pkt.arg = arg;
        pkt.flag = flag;
        ((TNpcPlayer *)(&pkt))->send_6x3E();
    }
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
    if (((TObjChara *)a)->obj_isState3_324() != 0) {
        for (i = 0; i < 4; i++) {
            if (i != src) {
                c = (Player_8034E24C *) get_player_by_client_id(i);
                if (c != NULL && ((TObjChara *)c)->obj_isState3_324() == 0) {
                    break;
                }
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (i != src) {
                c = (Player_8034E24C *) get_player_by_client_id(i);
                if (c != NULL && ((TObjChara *)c)->obj_isState3_324() != 0) {
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
    if (((TObjCollidable *)a)->test_actor_flags(0x100000) != 0) {
        flag = 1;
    }
    heading = (s32) ((65536.0 / (2.0 * 3.141592f)) * atan2_float(c->x - a->x, c->z - a->z));
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
    ((TObjCollidable *)a)->test_actor_flags(0x100000);
    heading = (s32) ((65536.0 / (2.0 * 3.141592f)) * atan2_float(c->x - a->x, c->z - a->z));
    pkt.id = src;
    VecCopy((Vec *)&pkt.x, (const Vec *)&a->x);
    pkt.arg = heading;
    ((TNpcPlayer *)(&pkt))->send_6x3E();
}

void TNpcPlayer::play_effect(int arg0) {
    saddr player;

    player = get_player_by_client_id((u16) arg0);
    if ((player != 0) && (((TObjChara *)player)->obj_isState2_324() == 0)) {
        TObjPlayer::play_effect_default(player, -1);
    }
}

void TNpcPlayer::send_code_45_to_player(int arg0) {
    saddr player;

    player = get_player_by_client_id((u16) arg0);
    if ((player != 0) && (((TObjChara *)player)->obj_isState2_324() == 0)) {
        TObjPlayer::send_code_45_1(player);
    }
}

void TNpcPlayer::send_warp_toward_player(u16 id, const Vec *destination) {
    TObjPlayer *npc = reinterpret_cast<TObjPlayer *>(get_player_by_client_id(id));
    TObjPlayer *local_player = reinterpret_cast<TObjPlayer *>(get_player_by_client_id(local_client_id));
    if (local_player == NULL || id == 0) {
        return;
    }
    if (npc->get_npc_controller() != 0xFFFF) {
        send_6x55_intra_map_warp(id, destination,
            (65536.0 / (2.0 * 3.141592f)) * atan2_float(destination->x - local_player->position.x,
                                                       destination->z - local_player->position.z));
    }
}

void clear_partner_dialogue_flags(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        npc_partner_dialogue_state[i].flag = 0;
    }
}

void set_partner_common_remark(s32 kind, const char *text) {
    char buf[0x40];

    if (kind < 25 && strlen(text) < 53) {
        sprintf(buf, "%s", text);
        strcpy((char *)&npc_partner_dialogue_state[kind], buf);
    }
}


void TObjPlayer::update_4p_battle_ctrls() {
    s32 var_r31;
    uaddr player;

    var_r31 = 0;
    do {
        if ((player = get_player_by_client_id(var_r31)) != 0) {
            TObjPlayer::send_item_pickup_request(player);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

void TObjPlayer::notify_all_battle_players() {
    s32 tmp_player;
    s32 var_r31;
    uaddr player;

    var_r31 = 0;
    do {
        if ((tmp_player = (s32)get_player_by_client_id(var_r31)) != 0U) {
            TObjPlayer::notify_field1c(tmp_player);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

s32 TTecReverser::is_active() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction() != 0) && !(*(s32 *)((s8 *)this + 0x30) & 0x02040800)) {
        var_r31 = 1;
    }
    return (u8)((u8) var_r31);
}

void TNpcPlayer::AiParams::copy_entry_by_index(s32 arg1) {
    saddr arg0 = (saddr)this;
    s32 temp_r5;
    temp_r5 = arg1 * 0x28;
    ((AiParams *)((u8 *)&TNpcPlayer__template_table.value + temp_r5))->copy((AiParams *)arg0);
}

// Indexed by TLobby::get_instance(); the yaw tables' names are inferred from their accessors.
static const Vec npc_lobby_entry_positions[2] = {{214.0f, 0.0f, -236.0f}, {214.0f, 0.0f, -236.0f}};
static const s32 npc_lobby_entry_yaws[2] = {0x8000, 0x8000};
static const Vec party_position_table[2] = {{200.0f, 0.0f, 320.0f}, {30.0f, 0.0f, 212.0f}};
static const s32 party_yaw_table[2] = {0xE400, 0xC000};

u8 *TNpcPlayer::get_lobby_entry_ptr() {
    return (u8 *)&npc_lobby_entry_positions[TLobby::get_instance()];
}

s32 TNpcPlayer__get_lobby_entry_yaw(void) {
    return npc_lobby_entry_yaws[TLobby::get_instance()];
}

u8 *get_party_position(void) {
    return (u8 *)&party_position_table[TLobby::get_instance()];
}

s32 get_party_yaw(void) {
    return party_yaw_table[TLobby::get_instance()];
}

TUnk_804F07C8::TUnk_804F07C8(TObject *parent) : TObject(parent) {
    void *task;
    s32 slot;
    u8 *player;
    partner_count = 0;
    for (slot = 0; slot < 4; slot++) {
        player = (u8 *)get_player_by_client_id(slot);
        if (player == NULL || reinterpret_cast<TObjPlayer *>(player)->obj_isState3_324() == 0 || ((TObjPlayer *)player)->get_npc_controller() == 0xFFFF) {
            continue;
        }
        task = TObject::operator new(0xE8);
        if (task != NULL) {
            construct_partner__10TNpcPlayerFPviisPv(task, ((TObjPlayer *)player)->get_npc_controller(), (u16) slot, ((TObjPlayer *)player)->get_npc_control_state(), tl_00);
        }
        partner_count++;
    }
}

TUnk_804F07C8::~TUnk_804F07C8() {
  s32 var_r31;
  u8 *player;
  var_r31 = 0;
    do
    {
      player = (u8 *) get_player_by_client_id(var_r31);
      if (player != 0)
      {
        if (reinterpret_cast<TObjPlayer *>(player)->is_script_controlled() != 0)
        {
          if (player != 0)
          {
            PSO_VCALL_VObj_18_dac7f3_m0(player, 1);
          }
        }
        else
          if (((reinterpret_cast<TObjPlayer *>(player)->obj_isState3_324() != 0) && (((TObjPlayer *)player)->get_npc_controller() == ((-1U) & 0xFFFFu))) && (player != 0))
        {
          PSO_VCALL_VObj_18_dac7f3_m0(player, 1);
        }
      }
      var_r31 += 1;
    }
    while (var_r31 < 4);
}

void TUnk_804F07C8::run_task() {  }

void TLobby__sub_8034DAA0(s32 arg0, u32 arg1) {
    Player_8034DAA0 *p;
    p = (Player_8034DAA0 *)get_player_by_client_id(arg0);
    if (p == NULL) {
        return;
    }
    switch (arg1) {
    case 0:
        obj_setFlags30(p, 1);
        break;
    case 1:
        obj_setFlags30(p, 2);
        break;
    case 2:
        obj_setFlags30(p, 4);
        break;
    case 3:
        obj_setFlags30(p, 0x20);
        break;
    case 4:
        obj_setFlags30(p, 8);
        break;
    case 5:
        obj_setFlags30(p, 0x10);
        break;
    case 6: {
        Vec2i_8034DAA0 v = {9, 20.0f};
        p->v49(&v);
        break;
    }
    case 7: {
        Vec2i_8034DAA0 v = {10, 20.0f};
        p->v50(&v);
        break;
    }
    case 8: {
        Vec2i_8034DAA0 v = {11, 20.0f};
        p->v49(&v);
        break;
    }
    case 9: {
        Vec2i_8034DAA0 v = {12, 20.0f};
        p->v50(&v);
        break;
    }
    case 10:
        ((TObjPlayer *)p)->set_hp_clamped(((TObjChara *)p)->get_hpmax());
        break;
    case 11:
        set_tp__10TObjPlayerFs(p, obj_getS16_2BA(p));
        break;
    }
}

