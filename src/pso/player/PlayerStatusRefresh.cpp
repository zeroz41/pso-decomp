#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/player/PlayerStatusRefresh.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/player/PlayerSlots.h"

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
    virtual const char *m10();
};


void refresh_player_status(s32 client_id) {
    struct VObj_80228C84 *o = (struct VObj_80228C84 *)get_player_by_client_id(client_id);
    if (o != NULL) {
        text_builder_append(o->m10());
    }
}
