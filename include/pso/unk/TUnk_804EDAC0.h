#ifndef PSO_UNK_TUNK_804EDAC0_H
#define PSO_UNK_TUNK_804EDAC0_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Created by TLobby::create_tasks outside split screen. TObjEneMe3Stelth, TOTrapAncient02 and TOTrapSeabed01
// queue themselves from their render() through dispatch_input_to_instance; render() then
// renders every queued object once and empties the queue (a deferred render list; role inferred).
class TUnk_804EDAC0 : public TObject {
public:
    TUnk_804EDAC0(TObject *parent);
    virtual ~TUnk_804EDAC0();
    virtual void render();
    void clear_password();                // empties the queue
    void update_children();               // renders each queued object whose parents are not being destroyed
    static s32 dispatch_input_to_instance(TObject *object);
    void sub_8032BC94(TObject *object);   // appends to the queue while it has room
    s32 get_confirm_state();              // nonzero while render() runs

    static TUnk_804EDAC0 *instance;       // set by the ctor, cleared by the dtor and the floor callbacks

    s32 rendering;
    TObject *queued[24];
    s32 queued_count;
};
LAYOUT_ASSERT(TUnk_804EDAC0_size, sizeof(TUnk_804EDAC0) == 0x84);

// Floor resource callbacks (TLobby's load/release table): both forget the instance.
extern "C" {
void TLobby__sub_8032BE30(void);
void TLobby__sub_8032BE3C(void);
}

#endif
