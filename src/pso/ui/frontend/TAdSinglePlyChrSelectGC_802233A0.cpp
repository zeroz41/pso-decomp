#include "types.h"
#include "pso/ui/city/BankItemRecord.h"

void BankItemRecord::swap_item_data(BankItemRecord *other) {
    BankItemRecord tmp;

    tmp = *this;
    *this = *other;
    *other = tmp;
}
