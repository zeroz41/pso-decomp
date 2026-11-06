#ifndef PSO_OBJECT_TUNK_804F0D1C_H
#define PSO_OBJECT_TUNK_804F0D1C_H

#include "types.h"
#include "pso/system/task/TObject.h"

/* Plays one of the event tracks; only one exists at a time, and it removes
   itself once the quest takes over the music. */
class TUnk_804F0D1C : public TObject {
public:
    TUnk_804F0D1C(TObject *parent, u32 track);
    virtual ~TUnk_804F0D1C();
    virtual void run_task();
};

void create_quest_bgm_object(TObject *parent, u32 track);

#endif
