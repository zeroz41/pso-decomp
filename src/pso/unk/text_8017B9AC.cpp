#include "types.h"
#include "pso/object/fence/TOVS2Wall01_8017BCC8.h"
#include "pso/object/fence/TOVS2Wall01_8017C7A4.h"
#include "pso/unk/text_8017B8A0.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"
#include "pso/object/fence/TOVS2Wall01.h"

struct Sub_8017BAFC { u8 pad[4]; s16 f4; };

struct Obj_8017BAFC { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; Sub_8017BAFC *sub; u8 pad2[0x2A2]; s16 state; u8 pad3[0x14]; s32 f33C; };

struct Pkt_8017BAFC { u16 a; u16 b; s32 c; s32 d; u16 e; s16 f; };

struct Pkt_8017B9B0 { u16 a; u16 b; s32 c; s32 d; u16 e; u16 f; };

struct Ent_8017B9B0 { s16 a; s16 b; };

struct VBase_8017B9B0 { u8 pad[0x18]; };

struct VObj_8017B9B0 : VBase_8017B9B0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(void *, s32);
    u8 pad2[0x326 - 0x1C];
    s16 state;
};

extern "C" {
s32 check_value_equals__13TUnk_804B6C24Fl(void *, int);
void *find_entity_by_id(u16 id);
extern s32 TOVS2Wall01__class_name;
extern Ent_8017B9B0 *quest_object_entries;
void handle_6x86_hit_destructible_object(Pkt_8017B9B0 *arg0);

void TOVS2Wall01__sub_8017B9AC(void) {  }

void handle_6x86_hit_destructible_object(Pkt_8017B9B0 *arg0) {
    Ent_8017B9B0 spC;
    Ent_8017B9B0 sp8;
    VObj_8017B9B0 *o;
    u16 id;
    if (arg0 == NULL) {
        return;
    }
    ((TOVS2Wall01 *)arg0)->byteswap_hit_packet();
    id = arg0->b;
    if (id == 0xFFFF) {
        return;
    }
    if (id < 0x4000) {
        return;
    }
    o = (VObj_8017B9B0 *)find_entity_by_id(id);
    if (o != NULL) {
        if (check_value_equals__13TUnk_804B6C24Fl(o, TOVS2Wall01__class_name) == 0) {
            return;
        }
        switch (arg0->e) {
        case 0:
            switch (o->state) {
            case 1:
                break;
            default:
                o->state = 0;
            case 0:
                if (arg0->f < TOVS2Wall01__sub_8017CA50(o)) {
                    TOVS2Wall01__sub_8017CA48(o, arg0->f);
                }
                break;
            }
            break;
        case 1:
            o->state = 1;
            init__11TOVS2Wall01Fi((s32)o);
            break;
        }
        ((TObjCollidable *)o)->access_object_saved_state(&spC, 1);
        spC.a = o->state;
        ((TObjCollidable *)o)->access_object_saved_state(&spC, 0);
        o->m4(&spC, 0);
    } else {
        *(s32 *)&sp8 = *(s32 *)&quest_object_entries[arg0->d];
        if (sp8.a != 1) {
            sp8.a = arg0->c;
            TLobby::apply_table_entry(arg0->d, &sp8);
        }
    }
}

void TOVS2Wall01::save_and_send_state(u16 arg1) {
    s16 sp8;
    Pkt_8017BAFC pkt;
    s16 v = ((Obj_8017BAFC *)this)->state;
    Sub_8017BAFC *sub;
    if (arg1 == 1) {
        v = 1;
    }
    if ((((Obj_8017BAFC *)this)->sub != NULL) && (((TObjCollidable *)((Obj_8017BAFC *)this))->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = v;
        this->access_object_saved_state(&sp8, 0);
        sub = ((Obj_8017BAFC *)this)->sub;
        ((TOVS2Wall01 *)(&pkt))->init();
        pkt.b = ((Obj_8017BAFC *)this)->f1C;
        pkt.c = sp8;
        pkt.d = sub->f4;
        pkt.e = arg1;
        pkt.f = ((Obj_8017BAFC *)this)->f33C;
        ((TOVS2Wall01 *)(&pkt))->update_and_send();
    }
}

}
