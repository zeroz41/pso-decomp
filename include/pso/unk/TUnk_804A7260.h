#ifndef PSO_UNK_TUNK_804A7260_H
#define PSO_UNK_TUNK_804A7260_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804A7260 : public TObject {
public:
    virtual ~TUnk_804A7260();
    void *init(void *, void *);
    void *destroy_cursor(s16);
};

#endif
