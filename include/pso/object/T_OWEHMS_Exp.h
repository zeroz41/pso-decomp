#ifndef PSO_OBJECT_T_OWEHMS_EXP_H
#define PSO_OBJECT_T_OWEHMS_EXP_H
#include "pso/system/task/TObject.h"
class TObjPlayer;

class T_OWEHMS_Exp : public TObject {
public:
    T_OWEHMS_Exp(TObjPlayer *player);
    virtual ~T_OWEHMS_Exp();
    virtual void run_task();
    void start_bone_rotation();
    static T_OWEHMS_Exp* create(TObjPlayer* player);

    s32 descriptor_index;
    TObjPlayer* player;
};
#include <stddef.h>
LAYOUT_ASSERT(T_OWEHMS_ExpSize, sizeof(T_OWEHMS_Exp) == 0x24);
LAYOUT_ASSERT(T_OWEHMS_ExpIndex, offsetof(T_OWEHMS_Exp, descriptor_index) == 0x1C);
LAYOUT_ASSERT(T_OWEHMS_ExpPlayer, offsetof(T_OWEHMS_Exp, player) == 0x20);
#endif
