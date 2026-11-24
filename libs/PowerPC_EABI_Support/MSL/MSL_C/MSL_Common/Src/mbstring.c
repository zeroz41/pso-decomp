#include "MSL_C/mbstring.h"
#include "MSL_C/string.h"

#pragma dont_inline on
static int is_utf8_complete(const char* s, size_t n) {
    if (n == 0)
        return -1;

    if (*s == 0x00)
        return 0;

    if ((*s & 0x80) == 0x00)
        return 1;
    else if ((*s & 0xE0) == 0xC0) {
        if (n >= 2) {
            if ((*(s + 1) & 0x80) == 0x80)
                return 2;
            return -1;
        }
        return -2;
    } else if ((*s & 0xF0) == 0xE0) {
        if (n >= 3) {
            if (((*(s + 1) & 0x80) == 0x80) && ((*(s + 2) & 0x80) == 0x80))
                return 3;
            return -1;
        } else if (((n == 2) && ((*(s + 1) & 0x80) == 0x80)) || (n == 1))
            return -2;
        return -1;
    } else
        return -1;
}

static int utf8_to_unicode(wchar_t* pwc, const char* s, size_t n) {
    int number_of_bytes;
    int check_byte_count;
    const char* source;
    wchar_t result_chr = 0;

    if (!s)
        return 0;

    if (n <= 0)
        return -1;

    number_of_bytes = is_utf8_complete(s, n);
    if (number_of_bytes < 0)
        return -1;

    source = s;
    switch (number_of_bytes) {
        case 3:
            result_chr |= (*source++ & 0x0F);
            result_chr <<= 6;
        case 2:
            result_chr |= (*source++ & 0x3F);
            result_chr <<= 6;
        case 1:
            result_chr |= (*source++ & 0x7F);
    }

    if (result_chr == 0x0000)
        check_byte_count = 0;
    else if (result_chr < 0x0080)
        check_byte_count = 1;
    else if (result_chr < 0x0800)
        check_byte_count = 2;
    else
        check_byte_count = 3;

    if (check_byte_count != number_of_bytes)
        return -1;

    if (pwc != 0)
        *pwc = result_chr;

    return number_of_bytes;
}

int mbtowc(wchar_t* pwc, const char* s, size_t n) {
    return utf8_to_unicode(pwc, s, n);
}

size_t unicode_to_UTF8(char* s, wchar_t wchar) {
    const char first_byte_mark[] = { 0, 0, 0xC0, 0xE0 };
    int number_of_bytes;
    char* target_ptr;

    if (!s)
        return 0;

    if (wchar < 0x80)
        number_of_bytes = 1;
    else if (wchar < 0x800)
        number_of_bytes = 2;
    else
        number_of_bytes = 3;

    target_ptr = s + number_of_bytes;
    switch (number_of_bytes) {
        case 3:
            *--target_ptr = (wchar & 0x3F) | 0x80;
            wchar >>= 6;
        case 2:
            *--target_ptr = (wchar & 0x3F) | 0x80;
            wchar >>= 6;
        case 1:
            *--target_ptr = wchar | first_byte_mark[number_of_bytes];
    }
    return number_of_bytes;
}
#pragma dont_inline off

size_t wctomb(char* s, wchar_t wchar) {
    return unicode_to_UTF8(s, wchar);
}

size_t wcstombs(char* s, const wchar_t* pwcs, size_t n) {
    char decoded[4];
    wchar_t w;
    size_t num;
    int i = 0;
    const wchar_t* p;

    if (!s || !pwcs)
        return 0;

    p = pwcs;
    while (i <= n) {
        w = *p;

        if (!w) {
            s[i] = 0;
            break;
        }
        ++p;
        num = wctomb(decoded, w);

        if (i + num > n)
            break;

        strncpy(s + i, decoded, num);
        i += num;
    }
    return i;
}
