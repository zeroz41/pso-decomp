#ifndef PSO_ITEM_TUNK_8049FEB8_H
#define PSO_ITEM_TUNK_8049FEB8_H
#include "types.h"
#include "pso/TObject.h"

struct TObjPlayer;

// Keeps a player's item timer event running for three frames
// (TItemTimerEvent::start_event_by_index), started by TUnk_8049FED0.
class TUnk_8049FEB8 : public TObject {
public:
    TUnk_8049FEB8(TObject *parent, TObjPlayer *player);
    virtual ~TUnk_8049FEB8();
    virtual void run_task();
    static void create(TObject *parent, TObjPlayer *player);
    u16 client_id;
    s16 frames_left;
};
typedef char TUnk_8049FEB8_size[sizeof(TUnk_8049FEB8) == 0x20 ? 1 : -1];

#endif
