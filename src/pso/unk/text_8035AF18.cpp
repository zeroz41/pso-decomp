#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/macros.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/PhotonChairSeat.h"

extern "C" {
int TPlyPhotonChair__sub_8035B520(void *p);
}

int PhotonChairSeat::create_chair() {
    TPlyPhotonChair *chair;

    FOREACH_NODE(TObject, tl_05->m_down, node) {
        if (node->check_value_equals(TPlyPhotonChair__class_name) != 0
            && owner_id == ((TPlyPhotonChair *)node)->sub_8035B530()
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
