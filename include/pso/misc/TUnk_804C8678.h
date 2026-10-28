#ifndef PSO_MISC_TUNK_804C8678_H
#define PSO_MISC_TUNK_804C8678_H
#include "types.h"
#include "pso/TObject.h"
#include "pso/quest/QuestVm.h"

class TUnk_804C8678 : public TObject {
public:
    u8 unk_1C[0x24 - 0x1C];
    QuestVmContext ctx;
    s32 script;
    u8 unk_19C[4];
    s32 kind;

    TUnk_804C8678(TObject *parent, void *script, s32 size);
    TUnk_804C8678(TObject *parent, const char *filename, s32 kind);
    TUnk_804C8678(TObject *parent, const char *filename);
    virtual ~TUnk_804C8678();
    virtual void run_task();
};
typedef char TUnk_804C8678_size[sizeof(TUnk_804C8678) == 0x1A4 ? 1 : -1];

#endif
