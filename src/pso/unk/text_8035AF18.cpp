#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/macros.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TUnk_804B6C24.h"

struct PhotonChairSeat {
    u16 m_0;
    u16 owner_id;
};

extern "C" {
int TPlyPhotonChair__sub_8035B520(void *p);
int fn_8035AF18(PhotonChairSeat *seat);
}

int fn_8035AF18(PhotonChairSeat *seat) {
    TPlyPhotonChair *chair;

    FOREACH_NODE(TObject, tl_05->m_down, node) {
        if (((TUnk_804B6C24 *)node)->check_value_equals((s32)TPlyPhotonChair__class_name) != 0
            && seat->owner_id == ((TPlyPhotonChair *)node)->sub_8035B530()
            && TPlyPhotonChair__sub_8035B520(node) != 0) {
            return 0;
        }
    }
    chair = new TPlyPhotonChair(seat->owner_id, (TObject *)tl_05);
    if (chair == NULL) {
        return 0;
    }
    return 1;
}
