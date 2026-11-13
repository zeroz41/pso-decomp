#include "types.h"
#include "pso/object/fence/TOVS2Wall01_8017BCC8.h"
#include "pso/object/fence/TOVS2Wall01_8017C7A4.h"
#include "pso/unk/text_8017B8A0.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"
#include "pso/object/fence/TOVS2Wall01.h"
#include "pso/object/fence/WallHitPacket.h"

struct WallSetEntry { u8 unk_0[4]; s16 m_4; };

struct Ent_8017B9B0 { s16 a; s16 b; };

extern "C" {
s32 check_value_equals__13TUnk_804B6C24Fl(void *, int);
void *find_entity_by_id(u16 id);
extern s32 TOVS2Wall01__class_name;
extern Ent_8017B9B0 *quest_object_entries;
void handle_6x86_hit_destructible_object(WallHitPacket *arg0);

void TOVS2Wall01__sub_8017B9AC(void) {  }

void handle_6x86_hit_destructible_object(WallHitPacket *arg0) {
    Ent_8017B9B0 spC;
    Ent_8017B9B0 sp8;
    TOVS2Wall01 *o;
    u16 id;
    if (arg0 == NULL) {
        return;
    }
    ((TOVS2Wall01 *)arg0)->byteswap_hit_packet();
    id = arg0->entity_id;
    if (id == 0xFFFF) {
        return;
    }
    if (id < 0x4000) {
        return;
    }
    o = (TOVS2Wall01 *)find_entity_by_id(id);
    if (o != NULL) {
        if (check_value_equals__13TUnk_804B6C24Fl(o, TOVS2Wall01__class_name) == 0) {
            return;
        }
        switch (arg0->m_c) {
        case 0:
            switch (o->mode) {
            case 1:
                break;
            default:
                o->mode = 0;
            case 0:
                if (arg0->m_e < TOVS2Wall01__sub_8017CA50(o)) {
                    TOVS2Wall01__sub_8017CA48(o, arg0->m_e);
                }
                break;
            }
            break;
        case 1:
            o->mode = 1;
            init__11TOVS2Wall01Fi((s32)o);
            break;
        }
        o->access_object_saved_state(&spC, 1);
        spC.a = o->mode;
        o->access_object_saved_state(&spC, 0);
        o->vfunc_6(&spC.a, 0);
    } else {
        *(s32 *)&sp8 = *(s32 *)&quest_object_entries[arg0->m_8];
        if (sp8.a != 1) {
            sp8.a = arg0->state;
            TLobby::apply_table_entry(arg0->m_8, &sp8);
        }
    }
}

void TOVS2Wall01::save_and_send_state(u16 arg1) {
    s16 sp8;
    WallHitPacket pkt;
    s16 v = mode;
    WallSetEntry *entry;
    if (arg1 == 1) {
        v = 1;
    }
    if (set_entry != NULL && access_object_saved_state(&sp8, 1) != 0) {
        sp8 = v;
        access_object_saved_state(&sp8, 0);
        entry = (WallSetEntry *)set_entry;
        ((TOVS2Wall01 *)&pkt)->init();
        pkt.entity_id = entity_id;
        pkt.state = sp8;
        pkt.m_8 = entry->m_4;
        pkt.m_c = arg1;
        pkt.m_e = m_33c;
        ((TOVS2Wall01 *)&pkt)->update_and_send();
    }
}
}
