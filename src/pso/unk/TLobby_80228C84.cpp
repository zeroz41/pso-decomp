#include "types.h"
#include "pso/unk/TLobby.h"

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

void *get_player_by_client_id();
s32 text_builder_append();

void TLobby::refresh_player_status() {
    struct VObj_80228C84 *o = (struct VObj_80228C84 *)get_player_by_client_id();
    if (o != NULL) {
        o->m10();
        text_builder_append();
    }
}

}
