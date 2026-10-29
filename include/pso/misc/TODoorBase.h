#ifndef PSO_MISC_TODOORBASE_H
#define PSO_MISC_TODOORBASE_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

// The base of the switch-locked doors (TODoorAncient*, TODoorCave*,
// TODoorMachine*, TODoorFourLight*, TODoorJungleMain, TObjDoorJung,
// TOBarrierEnergy01...). run_task steps the door through its open states
// (m_ac) while its lock follows a floor switch; the open amount is the motion
// frame m_b0, which moves by m_b8 per update between 0 and m_b4.
class TODoorBase : public TObjMapObject {
public:
    // Door states, kept in m_ac.
    enum {
        DOOR_CLOSED = 0,
        DOOR_OPENING = 1,
        DOOR_OPEN = 2,
        DOOR_CLOSING = 3
    };
    // How lock_mode ties the lock to switch_id.
    enum {
        LOCK_LOCKED = 0,     // never unlocks
        LOCK_UNLOCKED = 1,   // never locks
        LOCK_SWITCH = 2,     // unlocked while the switch is set
        LOCK_SWITCH_LATCH = 3 // unlocks for good once the switch is set
    };
    enum { DOOR_FLAG_UNLOCKED = 1 };

    TODoorBase(TObject *parent);
    virtual ~TODoorBase();
    virtual void run_task();
    virtual void update_door_switch_state();
    virtual void update_closed();
    virtual void update_opening();
    virtual void update_open();
    virtual void update_closing();
    virtual s32 init_door_switch_binding();
    // run_task's demo-mode step, empty in this build.
    virtual void update_demo();
    void play_door_sound();

    s32 switch_id;  // the floor switch, set_params[0]
    s32 lock_mode;
    s32 door_flags; // DOOR_FLAG_UNLOCKED; subclasses keep more bits here
};

typedef char TODoorBaseSize[sizeof(TODoorBase) == 0xD4 ? 1 : -1];

// Set while the room's switch doors are held shut (TObjDoor raises it,
// TLobby::reset_door_state clears it).
extern s32 switch_doors_force_closed;

// The derived constructors and destructors still written out by hand call
// these by their symbols.
extern "C" void *__dt__10TODoorBaseFv(void *self, s16 del);

extern "C" void *__vt__10TODoorBase[];

#endif
