#ifndef PSO_UI_TADSELECTTXTGC_H
#define PSO_UI_TADSELECTTXTGC_H

#include "pso/TObject.h"
#include "types.h"

class TAdSelectTxtGC : public TObject {
public:
    TAdSelectTxtGC(TObject *arg1, void *arg1_arg, void *arg3);
    virtual ~TAdSelectTxtGC();
    void init_slot_entries(void *, void *);
    virtual void run_task();
    virtual void render();
public:
    void reset_state();
    static void render();
public:
    void reset_slots(void *arg1, void *arg2);
};

extern "C" {
void TAdSelectTxtGC__sub_802A16A8(void *p);
s32 TAdSelectTxtGC__sub_802A16C0(void *p);
void TLobby__sub_802A1918(void);
void TLobby__sub_802A194C(void);
}

#endif
