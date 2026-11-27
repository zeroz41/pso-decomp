#include "types.h"
#include "pso/item/shop/ShopSinglePurchase.h"

s32 is_single_purchase_shop_item(u8 *p) {
    if (p[0] == 3) {
        switch (p[1]) {
        case 2:
        case 9:
        case 10:
        case 11:
            return 1;
        default:
            return 0;
        }
    }
    if (p[0] == 1) {
        switch (p[1]) {
        case 3:
            return 1;
        default:
            return 0;
        }
    }
    if (p[0] == 0) {
        switch (p[1]) {
        case 9:
            if (p[2] == 5) return 1;
            break;
        case 7:
            if (p[2] == 7) return 1;
            break;
        case 2:
            if (p[2] == 6) return 1;
            break;
        case 4:
            if (p[2] == 7) return 1;
            break;
        case 8:
            if (p[2] == 6) return 1;
            break;
        case 12:
            if (p[2] == 6) return 1;
            break;
        case 3:
            if (p[2] == 6) return 1;
            break;
        case 5:
            if (p[2] == 7) return 1;
            break;
        case 20:
            if (p[2] == 0) return 1;
            break;
        case 18:
            if (p[2] == 0) return 1;
            break;
        case 33:
            if (p[2] == 0) return 1;
            break;
        case 17:
            if (p[2] == 0) return 1;
            break;
        case 21:
            if (p[2] == 0) return 1;
            break;
        case 36:
            if (p[2] == 0) return 1;
            break;
        case 13:
            if (p[2] == 1) return 1;
            break;
        case 14:
            if (p[2] == 1) return 1;
            break;
        }
    }
    return 0;
}
