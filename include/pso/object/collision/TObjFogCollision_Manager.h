#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_MANAGER_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_MANAGER_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjFogCollision_Manager : public TObject {
public:
    virtual ~TObjFogCollision_Manager();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    s32 m_28;
    u8 unk_2C[0x4];
};
typedef char TObjFogCollision_Manager_size[sizeof(TObjFogCollision_Manager) == 0x30 ? 1 : -1];

#endif
