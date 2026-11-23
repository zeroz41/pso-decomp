#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80228C84.h"
#include "pso/player/PlayerSlots.h"

struct Base_80228C84 { char pad[0x18]; };
struct VObj_80228C84 : Base_80228C84 {
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
};

extern "C" {

s32 text_builder_append();

void refresh_player_status(s32 client_id) {
    struct VObj_80228C84 *o = (struct VObj_80228C84 *)get_player_by_client_id(client_id);
    if (o != NULL) {
        o->m10();
        text_builder_append();
    }
}

}
