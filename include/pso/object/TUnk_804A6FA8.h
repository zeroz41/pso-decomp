#ifndef PSO_OBJECT_TUNK_804A6FA8_H
#define PSO_OBJECT_TUNK_804A6FA8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804A6FA8 : public TObject {
public:
    virtual ~TUnk_804A6FA8();
    virtual void run_task();
};
typedef char TUnk_804A6FA8_size[sizeof(TUnk_804A6FA8) == 0x1C ? 1 : -1];

#endif
