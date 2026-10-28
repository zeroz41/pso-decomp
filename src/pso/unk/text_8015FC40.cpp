#include "types.h"
#include "pso/misc/TLobby_80160804.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TODoorAncient08.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOBarrierEnergy01.h"
struct State_8015FC40 { s16 a; s16 b; };

struct Pkt_8015FC40 { s16 hdr; u16 id; s32 state; s32 kind; };

struct Obj_8015FC40 { u8 pad[4]; s16 kind; };

struct Self_8015FC40 { u8 pad[0x1C]; u16 id; u8 pad1e[0x80 - 0x1E]; Obj_8015FC40 *obj; };

void TODoorAncient08::door_ancient08_sync_state(void *src_arg) {
    Self_8015FC40 *self = (Self_8015FC40 *)this;
    State_8015FC40 *src = (State_8015FC40 *)src_arg;
    State_8015FC40 st;
    Obj_8015FC40 *obj;
    if (src != 0) {
        ((TLobby *)(&st))->copy_short_fields(src);
    } else {
        ((TUnk_804AF8A0 *)self)->access_object_saved_state((void *)((s32)&st), (s16)1);
    }
    obj = *(Obj_8015FC40 * *)&this->m_80;
    if (obj != 0) {
        Pkt_8015FC40 pkt;
        ((TOBarrierEnergy01 *)(&pkt))->init();
        pkt.id = this->entity_id;
        pkt.state = st.a;
        pkt.kind = obj->kind;
        update_and_send_60__6TLobbyFPv(&pkt);
    }
}
