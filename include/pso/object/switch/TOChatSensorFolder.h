#ifndef PSO_OBJECT_SWITCH_TOCHATSENSORFOLDER_H
#define PSO_OBJECT_SWITCH_TOCHATSENSORFOLDER_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TOChatSensorFolder : public TObject {
public:
    virtual ~TOChatSensorFolder();
};

extern "C" {
void *TOChatSensorFolder__ct(void *chat_sensor_folder);
}

#endif
