#ifndef PSO_PLAYER_TUNK_804B1B80_H
#define PSO_PLAYER_TUNK_804B1B80_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

// The base of the fences (TOFenceAncient01-04): a map object that opens
// when a player comes near or a floor switch is set (trigger_mode 1 or 2).
class TUnk_804B1B80 : public TObjMapObject {
public:
    TUnk_804B1B80(TObject *parent);
    virtual ~TUnk_804B1B80();
    virtual void run_task();
    virtual void render();
    // trigger_mode's condition met / lost: the fences drop or raise their
    // collision and start or stop their motion.
    virtual void open();
    virtual void close();
    // The step run_task takes in demo mode.
    virtual void update_demo();
    void check_trigger();
    void update_trigger();
    s32 sub_80166EA8(int);
    s32 sub_80166E64();
    s32 trigger_mode;  // 0 never, 1 a player within 70, 2 switch_id set
    u32 switch_id;
    s32 is_open;  // 1 draws the root model posed instead of the motion
    u32 m_d4;
};

typedef char TUnk_804B1B80Size[sizeof(TUnk_804B1B80) == 0xD8 ? 1 : -1];

// The derived destructors still written out by hand call this by its symbol.
extern "C" void *__dt__13TUnk_804B1B80Fv(void *self, s16 del);

#endif
