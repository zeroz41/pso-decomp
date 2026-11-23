#ifndef PSO_UI_FRONTEND_TADSELECTTXTGC_H
#define PSO_UI_FRONTEND_TADSELECTTXTGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSelectTxtSubGC;

// Where a select screen's text goes: its text id and screen position.
struct TAdSelectTxtLayout {
    s32 text_id;
    f32 position[2];
};

// One line of a select text: the value it shows, its line number, position and text id.
struct TAdSelectTxtEntry {
    s32 value;
    s32 index;
    f32 position[2];
    s32 text_id;
};

class TAdSelectTxtGC : public TObject {
public:
    TAdSelectTxtGC(TObject *parent, TAdSelectTxtLayout *layout, s32 value);
    virtual ~TAdSelectTxtGC();
    void init_slot_entries(TAdSelectTxtLayout *layout, s32 value);
    virtual void run_task();
    virtual void render();
public:
    void reset_state();
public:
    void reset_slots(TAdSelectTxtLayout *layout, s32 value);

    TAdSelectTxtEntry entries[8];
    s32 spawn_count;
    TAdSelectTxtSubGC *lines[8];
};

extern uaddr ad_select_text_texture_handle;

extern "C" {
void TAdSelectTxtGC__sub_802A16A8(void *p);
s32 TAdSelectTxtGC__sub_802A16C0(void *p);
void TLobby__sub_802A1918(void);
void TLobby__sub_802A194C(void);
}

#endif
