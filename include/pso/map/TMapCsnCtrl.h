#ifndef PSO_MAP_TMAPCSNCTRL_H
#define PSO_MAP_TMAPCSNCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

struct CsnGroup;
struct TObjMapCsn;

class TMapCsnCtrl : public TObject {
public:
    static const char *class_name;
    TMapCsnCtrl(TObject *parent);
    virtual ~TMapCsnCtrl();
    void clear_groups();
    CsnGroup **get_collision_groups();
    void remove_object(TObjMapCsn *object);
    void remove_group(CsnGroup *group);
    void add_object(TObjMapCsn *object);
    void add_group(CsnGroup *group);
    // Copies the groups up to the first one without a model.
    void set_groups(CsnGroup *source);

    CsnGroup *groups[0x200];
};
LAYOUT_ASSERT(TMapCsnCtrlExtent, sizeof(TMapCsnCtrl) == 0x81C);

LAYOUT_ASSERT(TMapCsnCtrlGroupsOffset, offsetof(TMapCsnCtrl, groups) == 0x1C);


#endif
