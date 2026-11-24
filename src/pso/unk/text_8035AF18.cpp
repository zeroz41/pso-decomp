#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/macros.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/player/PhotonChairSeat.h"

extern "C" {
int TPlyPhotonChair__sub_8035B520(void *p);
}

int PhotonChairSeat::create_chair() {
    TPlyPhotonChair *chair;

    FOREACH_NODE(TObject, tl_05->m_down, node) {
        if (((TUnk_804B6C24 *)node)->check_value_equals((saddr)TPlyPhotonChair__class_name) != 0
            && owner_id == ((TPlyPhotonChair *)node)->get_owner_id()
            && TPlyPhotonChair__sub_8035B520(node) != 0) {
            return 0;
        }
    }
    chair = new TPlyPhotonChair(owner_id, (TObject *)tl_05);
    if (chair == NULL) {
        return 0;
    }
    return 1;
}
