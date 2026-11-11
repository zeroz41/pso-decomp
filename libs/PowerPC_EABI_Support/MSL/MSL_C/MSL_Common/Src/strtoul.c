
#include "MSL_C/scanf.h"
#include "MSL_C/ctype.h"

#define ULONG_MAX 0xFFFFFFFFul
#define LONG_MAX 2147483647l
#define LONG_MIN -2147483648l
#define ERANGE 0x22

extern int errno;

enum scan_states {
    start = 0x01,
    check_for_zero = 0x02,
    leading_zero = 0x04,
    need_digit = 0x08,
    digit_loop = 0x10,
    finished = 0x20,
    failure = 0x40
};

#define final_state(scan_state) (scan_state & (finished | failure))
#define success(scan_state) (scan_state & (leading_zero | digit_loop | finished))
#define fetch() (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, __UngetAChar)

#define final_state(scan_state) (scan_state & (finished | failure))
#define success(scan_state) (scan_state & (leading_zero | digit_loop | finished))
#define fetch() (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, __UngetAChar)

unsigned long __strtoul(int base, int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg,
                        int* chars_scanned, int* negative, int* overflow) {
    int scan_state = start;
    int count = 0;
    int c2 = 0;
    unsigned long value = 0;
    unsigned long value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1) {
        scan_state = failure;
    } else {
        c = fetch();
    }

    if (base != 0)
        value_max = ULONG_MAX / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
            case start:
                if (_isspace(c)) {
                    c = fetch();
                    count--;
                    c2++;
                    break;
                }

                if (c == '+') {
                    c = fetch();
                } else if (c == '-') {
                    c = fetch();
                    *negative = 1;
                }

                scan_state = check_for_zero;
                break;

            case check_for_zero:
                if (base == 0 || base == 16) {
                    if (c == '0') {
                        scan_state = leading_zero;
                        c = fetch();
                        break;
                    }
                }

                scan_state = need_digit;
                break;

            case 4:
                if (c == 'X' || c == 'x') {
                    base = 16;
                    scan_state = need_digit;
                    c = fetch();
                    break;
                }

                if (base == 0)
                    base = 8;

                scan_state = digit_loop;
                break;

            case need_digit:
            case digit_loop:
                if (base == 0)
                    base = 10;

                if (value_max == 0) {
                    value_max = ULONG_MAX / base;
                }

                if (_isdigit(c)) {
                    if ((c -= '0') >= base) {
                        if (scan_state == digit_loop)
                            scan_state = finished;
                        else
                            scan_state = failure;

                        c += '0';
                        break;
                    }
                } else if (!_isalpha(c) || (_toupper(c) - 'A' + 10) >= base) {
                    if (scan_state == digit_loop)
                        scan_state = finished;
                    else
                        scan_state = failure;

                    break;
                } else {
                    c = _toupper(c) - 'A' + 10;
                }

                if (value > value_max)
                    *overflow = 1;

                value *= base;

                if (c > (ULONG_MAX - value))
                    *overflow = 1;

                value += c;
                scan_state = digit_loop;
                c = fetch();
                break;
        }
    }

    if (!success(scan_state)) {
        value = 0;
        count = 0;
        *chars_scanned = count;
    } else {
        count--;
        *chars_scanned = count + c2;
    }

    unfetch(c);

    return value;
}

unsigned long long __strtoull(int base, int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg,
                              int* chars_scanned, int* negative, int* overflow) {
    int scan_state = start;
    int count = 0;
    int spaces = 0;
    unsigned long long value = 0;
    unsigned long long value_max = 0;
    unsigned long long ullmax = 0xFFFFFFFFFFFFFFFFull;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1) {
        scan_state = failure;
    } else {
        c = fetch();
    }

    if (base != 0) {
        value_max = ullmax / base;
    }

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
            case start:
                if (_isspace(c)) {
                    c = fetch();
                    count--;
                    spaces++;
                    break;
                }

                if (c == '+') {
                    c = fetch();
                } else if (c == '-') {
                    c = fetch();
                    *negative = 1;
                }

                scan_state = check_for_zero;
                break;

            case check_for_zero:
                if (base == 0 || base == 16) {
                    if (c == '0') {
                        scan_state = leading_zero;
                        c = fetch();
                        break;
                    }
                }

                scan_state = need_digit;
                break;

            case leading_zero:
                if (c == 'X' || c == 'x') {
                    base = 16;
                    scan_state = need_digit;
                    c = fetch();
                    break;
                }

                if (base == 0) {
                    base = 8;
                }

                scan_state = digit_loop;
                break;

            case need_digit:
            case digit_loop:
                if (base == 0) {
                    base = 10;
                }

                if (!value_max) {
                    value_max = ullmax / base;
                }

                if (_isdigit(c)) {
                    if ((c -= '0') >= base) {
                        if (scan_state == digit_loop) {
                            scan_state = finished;
                        } else {
                            scan_state = failure;
                        }

                        c += '0';
                        break;
                    }
                } else if (!_isalpha(c) || (_toupper(c) - 'A' + 10) >= base) {
                    if (scan_state == digit_loop) {
                        scan_state = finished;
                    } else {
                        scan_state = failure;
                    }

                    break;
                } else {
                    c = _toupper(c) - 'A' + 10;
                }

                if (value > value_max) {
                    *overflow = 1;
                }

                value = value * base;

                if (c > (ullmax - value)) {
                    *overflow = 1;
                }

                value += c;
                scan_state = digit_loop;
                c = fetch();
                break;
        }
    }

    if (!success(scan_state)) {
        value = *chars_scanned = count = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }

    unfetch(c);
    return value;
}

unsigned long strtoul(const char* str, char** end, int base) {
    unsigned long value;
    int count, negative, overflow;

    __InStrCtrl isc;
    isc.NextChar = (char*)str;
    isc.NullCharDetected = 0;

    value = __strtoul(base, 0x7FFFFFFF, &__StringRead, (void*)&isc, &count, &negative, &overflow);

    if (end) {
        *end = (char*)str + count;
    }

    if (overflow) {
        value = ULONG_MAX;
        errno = 0x22;
    } else if (negative) {
        value = -value;
    }

    return value;
}

static inline long strtol(const char* str, char** end, int base) {
    unsigned long uvalue;
    long svalue;
    int count, negative, overflow;

    __InStrCtrl isc;
    isc.NextChar = (char*)str;
    isc.NullCharDetected = 0;

    uvalue = __strtoul(base, 0x7FFFFFFF, &__StringRead, (void*)&isc, &count, &negative, &overflow);

    if (end) {
        *end = (char*)str + count;
    }

    if (overflow || (!negative && uvalue > LONG_MAX) || (negative && uvalue > -LONG_MIN)) {
        svalue = (negative ? -LONG_MIN : LONG_MAX);
        errno = ERANGE;
    } else {
        svalue = (negative ? (long)-uvalue : (long)uvalue);
    }

    return svalue;
}

int atoi(const char* str) {
    return strtol(str, NULL, 10);
}

#include "MSL_C/ansi_fp.h"
#include "MSL_C/locale.h"
extern double __dec2num(const decimal* d);
extern float __float_huge[];
extern float __float_nan[];
extern unsigned long __double_huge[];
extern unsigned long __extended_min[];
extern unsigned long __extended_max[];
#define HUGE_VALF (*__float_huge)
#define NAN (*__float_nan)
#define HUGE_VAL (*(double*)__double_huge)
#define LDBL_MIN (*(double*)__extended_min)
#define LDBL_MAX (*(double*)__extended_max)
#define LDBL_MAX_EXP 1024
#define LDBL_MANT_DIG 53
#define DBL_MAX_10_EXP 308
#define DBL_MIN_10_EXP (-307)
#define SHRT_MAX 32767
#define SHRT_MIN (-32768)
extern void* memset(void*, int, unsigned long);
#define TARGET_FLOAT_BITS 64
#define TARGET_FLOAT_BYTES (TARGET_FLOAT_BITS / 8)
#define TARGET_FLOAT_MAX_EXP LDBL_MAX_EXP
#define TARGET_FLOAT_MANT_DIG LDBL_MANT_DIG
#define TARGET_FLOAT_IMPLICIT_J_BIT 1
#define TARGET_FLOAT_MANT_BITS (TARGET_FLOAT_MANT_DIG - TARGET_FLOAT_IMPLICIT_J_BIT)
#define TARGET_FLOAT_EXP_BITS (TARGET_FLOAT_BITS - TARGET_FLOAT_MANT_BITS - 1)

enum ld_scan_states {
    ld_start = 0x0001,
    ld_sig_start = 0x0002,
    ld_leading_sig_zeroes = 0x0004,
    ld_int_digit_loop = 0x0008,
    ld_frac_start = 0x0010,
    ld_frac_digit_loop = 0x0020,
    ld_sig_end = 0x0040,
    ld_exp_start = 0x0080,
    ld_leading_exp_digit = 0x0100,
    ld_leading_exp_zeroes = 0x0200,
    ld_exp_digit_loop = 0x0400,
    ld_finished = 0x0800,
    ld_failure = 0x1000,
    ld_nan_state = 0x2000,
    ld_infin_state = 0x4000,
    ld_hex_state = 0x8000
};

enum hex_scan_states {
    not_hex = 0x0000,
    hex_start = 0x0001,
    hex_leading_sig_zeroes = 0x0002,
    hex_int_digit_loop = 0x0004,
    hex_frac_digit_loop = 0x0008,
    hex_sig_end = 0x0010,
    hex_exp_start = 0x0020,
    hex_leading_exp_digit = 0x0040,
    hex_leading_exp_zeroes = 0x0080,
    hex_exp_digit_loop = 0x0100
};

#undef final_state
#undef success
#undef fetch
#undef unfetch
#define final_state(scan_state) (scan_state & (ld_finished | ld_failure))
#define success(scan_state) \
    (scan_state &           \
     (ld_leading_sig_zeroes | ld_int_digit_loop | ld_frac_digit_loop | ld_leading_exp_zeroes | ld_exp_digit_loop | ld_finished))
#define hex_success(count, scan_state)                                                                  \
    (count - 1 > 2 && scan_state & (hex_leading_sig_zeroes | hex_int_digit_loop | hex_frac_digit_loop | \
                                    hex_leading_exp_zeroes | hex_exp_digit_loop))

#define fetch() (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, __UngetAChar)

long double __strtold(int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned,
                      int* overflow) {
    int scan_state = ld_start;
    int hex_scan_state = not_hex;
    int count = 0;
    int spaces = 0;
    int c;
    decimal d = {0, 0, 0, {0, ""}};
    int sig_negative = 0;
    int exp_negative = 0;
    long exp_value = 0;
    int exp_adjust = 0;
    long double result;
    int sign_detected = 0;
    unsigned char* chptr = (unsigned char*)&result;
    unsigned char uch, uch1;
    int ui;
    int NibbleIndex;
    int expsign = 0;
    int exp_digits = 0;
    int intdigits = 0;
    short exponent = 0;
    int radix_marker = *(unsigned char*)(__lconv).decimal_point;

    *overflow = 0;
    c = fetch();

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
            case ld_start:
                if (_isspace(c)) {
                    c = fetch();
                    count--;
                    spaces++;
                    break;
                }

                switch (_toupper(c)) {
                    case '-':
                        sig_negative = 1;

                    case '+':
                        c = fetch();
                        sign_detected = 1;
                        break;
                    case 'I':
                        c = fetch();
                        scan_state = ld_infin_state;
                        break;

                    case 'N':
                        c = fetch();
                        scan_state = ld_nan_state;
                        break;

                    default:
                        scan_state = ld_sig_start;
                        break;
                }
                break;

            case ld_infin_state: {
                int i = 1;
                char model[] = "INFINITY";

                while ((i < 8) && (_toupper(c) == model[i])) {
                    i++;
                    c = fetch();
                }

                if ((i == 3) || (i == 8)) {
                    if (sig_negative) {
                        result = (float)-HUGE_VALF;
                    } else {
                        result = HUGE_VALF;
                    }

                    *chars_scanned = spaces + i + sign_detected;
                    return result;
                } else {
                    scan_state = ld_failure;
                }

                break;
            }

            case ld_nan_state: {
                int i = 1, j = 0;
                char model[] = "NAN(";
                while ((i < 4) && (_toupper(c) == model[i])) {
                    i++;
                    c = fetch();
                }

                if ((i == 3) || (i == 4)) {
                    if (i == 4) {
                        while ((j < 32) && (_isdigit(c) || _isalpha(c))) {
                            j++;
                            c = fetch();
                        }

                        if (c != ')') {
                            scan_state = ld_failure;
                            break;
                        } else {
                            j++;
                        }
                    }

                    if (sig_negative) {
                        result = -NAN;
                    } else {
                        result = NAN;
                    }

                    *chars_scanned = spaces + i + j + sign_detected;
                    return result;
                } else {
                    scan_state = ld_failure;
                }
                break;
            }

            case ld_sig_start:
                if (c == radix_marker) {
                    scan_state = ld_frac_start;
                    c = fetch();
                    break;
                }
                if (!_isdigit(c)) {
                    scan_state = ld_failure;
                    break;
                }

                if (c == '0') {
                    c = fetch();
                    if (_toupper(c) == 'X') {
                        scan_state = ld_hex_state;
                        hex_scan_state = hex_start;
                    } else {
                        scan_state = ld_leading_sig_zeroes;
                    }
                    break;
                }

                scan_state = ld_int_digit_loop;
                break;

            case ld_leading_sig_zeroes:
                if (c == '0') {
                    c = fetch();

                    break;
                }
                scan_state = ld_int_digit_loop;
                break;

            case ld_int_digit_loop:
                if (!_isdigit(c)) {
                    if (c == radix_marker) {
                        scan_state = ld_frac_digit_loop;
                        c = fetch();
                    } else {
                        scan_state = ld_sig_end;
                    }
                    break;
                }
                if (d.sig.length < 20) {
                    d.sig.text[d.sig.length++] = (unsigned char)c;
                } else {
                    exp_adjust++;
                }

                c = fetch();
                break;

            case ld_frac_start:
                if (!_isdigit(c)) {
                    scan_state = ld_failure;
                    break;
                }

                scan_state = ld_frac_digit_loop;
                break;

            case ld_frac_digit_loop:
                if (!_isdigit(c)) {
                    scan_state = ld_sig_end;
                    break;
                }

                if (d.sig.length < 20) {
                    if (c != '0' || d.sig.length) {
                        d.sig.text[d.sig.length++] = (unsigned char)c;
                    }

                    exp_adjust--;
                }
                c = fetch();
                break;

            case ld_sig_end:
                if (_toupper(c) == 'E') {
                    scan_state = ld_exp_start;
                    c = fetch();
                    break;
                }
                scan_state = ld_finished;
                break;

            case ld_exp_start:
                if (c == '+') {
                    c = fetch();
                } else if (c == '-') {
                    c = fetch();
                    exp_negative = 1;
                }

                scan_state = ld_leading_exp_digit;
                break;

            case ld_leading_exp_digit:
                if (!_isdigit(c)) {
                    scan_state = ld_failure;
                    break;
                }

                if (c == '0') {
                    scan_state = ld_leading_exp_zeroes;
                    c = fetch();
                    break;
                }

                scan_state = ld_exp_digit_loop;
                break;

            case ld_leading_exp_zeroes:
                if (c == '0') {
                    c = fetch();
                    break;
                }

                scan_state = ld_exp_digit_loop;
                break;

            case ld_exp_digit_loop:
                if (!_isdigit(c)) {
                    scan_state = ld_finished;
                    break;
                }

                exp_value = exp_value * 10 + (c - '0');
                if (exp_value > SHRT_MAX) {
                    *overflow = 1;
                }

                c = fetch();
                break;

            case ld_hex_state: {
                switch (hex_scan_state) {
                    case hex_start: {
                        int k;
                        for (k = 0; k < 8; k++) {
                            chptr[k] = 0;
                        }
                        NibbleIndex = 2;
                        hex_scan_state = hex_leading_sig_zeroes;
                        c = fetch();
                        break;
                    }

                    case hex_leading_sig_zeroes:
                        if (c == '0') {
                            c = fetch();
                            break;
                        }

                        hex_scan_state = hex_int_digit_loop;
                        break;

                    case hex_int_digit_loop:
                        if (!_isxdigit(c)) {
                            if (c == radix_marker) {
                                hex_scan_state = hex_frac_digit_loop;
                                c = fetch();
                            } else {
                                hex_scan_state = hex_sig_end;
                            }
                            break;
                        }

                        if (NibbleIndex < 17) {
                            intdigits++;
                            uch = *(chptr + NibbleIndex / 2);

                            ui = _toupper(c);
                            if (ui >= 'A') {
                                ui = ui - 'A' + 10;
                            } else {
                                ui -= '0';
                            }

                            uch1 = (unsigned char)ui;

                            if ((NibbleIndex % 2) != 0) {
                                uch |= uch1;
                            } else {
                                uch |= uch1 << 4;
                            }

                            *(chptr + NibbleIndex++ / 2) = uch;
                            c = fetch();
                        } else {
                            c = fetch();
                        }

                        break;

                    case hex_frac_digit_loop:
                        if (!_isxdigit(c)) {
                            hex_scan_state = hex_sig_end;
                            break;
                        }

                        if (NibbleIndex < 17) {
                            uch = *(chptr + NibbleIndex / 2);
                            ui = _toupper(c);

                            if (ui >= 'A') {
                                ui = ui - 'A' + 10;
                            } else {
                                ui -= '0';
                            }

                            uch1 = (unsigned char)ui;

                            if ((NibbleIndex % 2) != 0) {
                                uch |= uch1;
                            } else {
                                uch |= uch1 << 4;
                            }

                            *(chptr + NibbleIndex++ / 2) = uch;
                            c = fetch();
                        } else {
                            c = fetch();
                        }
                        break;

                    case hex_sig_end:
                        if (_toupper(c) == 'P') {
                            hex_scan_state = hex_exp_start;
                            exp_digits++;
                            c = fetch();
                        } else {
                            scan_state = ld_finished;
                        }

                        break;

                    case hex_exp_start:
                        exp_digits++;
                        if (c == '-') {
                            expsign = 1;
                        } else if (c != '+') {
                            unfetch(c);
                            exp_digits--;
                        }

                        hex_scan_state = hex_leading_exp_digit;
                        c = fetch();
                        break;

                    case hex_leading_exp_digit:
                        if (!_isdigit(c)) {
                            scan_state = ld_failure;
                            break;
                        }

                        if (c == '0') {
                            exp_digits++;
                            hex_scan_state = hex_leading_exp_zeroes;
                            c = fetch();
                            break;
                        }

                        hex_scan_state = hex_exp_digit_loop;
                        break;

                    case hex_exp_digit_loop:
                        if (!_isdigit(c)) {
                            scan_state = ld_finished;
                            break;
                        }

                        exponent = exponent * 10 + (c - '0');

                        if (exp_value > SHRT_MAX) {
                            *overflow = 1;
                        }

                        exp_digits++;
                        c = fetch();

                        break;
                }
            } break;
        }
    }

    if (!success(scan_state)) {
        count = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }

    unfetch(c);

    if (hex_scan_state == not_hex) {
        if (exp_negative) {
            exp_value = -exp_value;
        }

        {
            int n = d.sig.length;
            unsigned char* p = &d.sig.text[n];

            while (n-- && *--p == '0') {
                exp_adjust++;
            }

            d.sig.length = (unsigned char)(n + 1);

            if (d.sig.length == 0) {
                d.sig.text[d.sig.length++] = '0';
            }
        }

        exp_value += exp_adjust;

        if (exp_value < SHRT_MIN || exp_value > SHRT_MAX) {
            *overflow = 1;
        }

        if (*overflow) {
            if (exp_negative) {
                return 0.0;
            } else {
                return sig_negative ? -HUGE_VAL : HUGE_VAL;
            }
        }

        d.exp = (short)exp_value;

        result = __dec2num(&d);

        if (0.0 != result && result < LDBL_MIN) {
            *overflow = 1;
        } else if (result > LDBL_MAX) {
            *overflow = 1;
            result = HUGE_VAL;
        }

        if (sig_negative && success(scan_state)) {
            result = -result;
        }

        return result;
    } else {
        if (result) {
            if (expsign) {
                exponent = -exponent;
            }

            while ((*(short*)chptr & 0x00F0) != 0x0010) {
                *(unsigned long long*)chptr >>= 1;
                exponent++;
            }

            exponent += (intdigits - 1) * 4;
            *(short*)chptr &= 0x000F;
            *(short*)chptr |= (exponent + 1023) << 4;
            *chars_scanned = spaces + sign_detected + NibbleIndex + 1 + exp_digits;

            if (0.0 != result && result < LDBL_MIN) {
                *overflow = 1;
                result = 0.0;
            } else if (result > LDBL_MAX) {
                *overflow = 1;
                result = HUGE_VAL;
            }

            if (sig_negative) {
                *(short*)chptr |= 0x8000;
            }
        } else {
            result = 0.0;
        }

        return result;
    }
}
