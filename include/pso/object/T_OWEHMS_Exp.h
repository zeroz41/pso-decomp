#ifndef PSO_OBJECT_T_OWEHMS_EXP_H
#define PSO_OBJECT_T_OWEHMS_EXP_H
#include "pso/system/task/TObject.h"
struct TObjPlayer;

class T_OWEHMS_Exp : public TObject {
private:
    T_OWEHMS_Exp();
    virtual ~T_OWEHMS_Exp();
public:
    T_OWEHMS_Exp* construct(TObjPlayer* player);
    T_OWEHMS_Exp* destroy(s16 should_free);
    virtual void run_task();
    void start_bone_rotation();
    static T_OWEHMS_Exp* create(TObjPlayer* player);

    s32 descriptor_index;
    TObjPlayer* player;
};
#include <stddef.h>
typedef char T_OWEHMS_ExpSize[(sizeof(T_OWEHMS_Exp) == 0x24) ? 1 : -1];
typedef char T_OWEHMS_ExpIndex[(offsetof(T_OWEHMS_Exp, descriptor_index) == 0x1C) ? 1 : -1];
typedef char T_OWEHMS_ExpPlayer[(offsetof(T_OWEHMS_Exp, player) == 0x20) ? 1 : -1];
#endif
