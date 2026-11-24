#include "MSL_C/string.h"
#include "MSL_C/printf.h"

size_t strlen(const char* str) {
    size_t len = -1;
    unsigned char* p = (unsigned char*)str - 1;

    do {
        len++;
    } while (*++p);

    return len;
}

char* strcpy(char* dst, const char* src) {
    register unsigned char *destb, *fromb;
    register unsigned long w, t, align;
    register unsigned int k1;
    register unsigned int k2;

    fromb = (unsigned char*)src;
    destb = (unsigned char*)dst;

    if ((align = ((int)fromb & 3)) != ((int)destb & 3)) {
        goto bytecopy;
    }

    if (align) {
        if ((*destb = *fromb) == 0) {
            return dst;
        }

        for (align = 3 - align; align; align--) {
            if ((*(++destb) = *(++fromb)) == 0) {
                return dst;
            }
        }
        ++destb;
        ++fromb;
    }

    k1 = 0x80808080;
    k2 = 0xFEFEFEFF;

    w = *((int*)(fromb));

    t = w + k2;

    t &= k1;
    if (t) {
        goto bytecopy;
    }
    --((int*)(destb));

    do {
        *(++((int*)(destb))) = w;
        w = *(++((int*)(fromb)));

        t = w + k2;
        t &= k1;
        if (t) {
            goto adjust;
        }
    } while (1);

adjust:
    ++((int*)(destb));

bytecopy:
    if ((*destb = *fromb) == 0) {
        return dst;
    }

    do {
        if ((*(++destb) = *(++fromb)) == 0) {
            return dst;
        }
    } while (1);

    return dst;
}

char* strncpy(char* dst, const char* src, size_t n) {
    const unsigned char* p = (const unsigned char*)src - 1;
    unsigned char* q = (unsigned char*)dst - 1;

    n++;
    while (--n) {
        if (!(*++q = *++p)) {
            while (--n) {
                *++q = 0;
            }
            break;
        }
    }

    return dst;
}

char* strcat(char* dst, const char* src) {
    const unsigned char* p = (unsigned char*)src - 1;
    unsigned char* q = (unsigned char*)dst - 1;

    while (*++q) {}

    q--;

    while (*++q = *++p) {}

    return dst;
}

char* strncat(char* dst, const char* src, size_t n) {
    const unsigned char* p = (const unsigned char*)src - 1;
    unsigned char* q = (unsigned char*)dst - 1;

    while (*++q) {
    }

    q--;
    n++;

    while (--n) {
        if (!(*++q = *++p)) {
            q--;
            break;
        }
    }

    *++q = 0;

    return dst;
}

int strcmp(const char* str1, const char* str2) {
    register unsigned char* left = (unsigned char*)str1;
    register unsigned char* right = (unsigned char*)str2;
    unsigned long align, l1, r1, x;

    l1 = *left;
    r1 = *right;
    if (l1 - r1) {
        return l1 - r1;
    }

    if ((align = ((int)left & 3)) != ((int)right & 3)) {
        goto bytecopy;
    }

    if (align) {
        if (l1 == 0) {
            return 0;
        }
        for (align = 3 - align; align; align--) {
            l1 = *(++left);
            r1 = *(++right);
            if (l1 - r1) {
                return l1 - r1;
            }
            if (l1 == 0) {
                return 0;
            }
        }
        left++;
        right++;
    }

    l1 = *(int*)left;
    r1 = *(int*)right;
    x = l1 + 0xFEFEFEFF;
    if (x & 0x80808080) {
        goto adjust;
    }

    while (l1 == r1) {
        l1 = *(++((int*)(left)));
        r1 = *(++((int*)(right)));
        x = l1 + 0xFEFEFEFF;
        if (x & 0x80808080) {
            goto adjust;
        }
    }

    if (l1 > r1) {
        return 1;
    }
    return -1;

adjust:
    l1 = *left;
    r1 = *right;
    if (l1 - r1) {
        return l1 - r1;
    }

bytecopy:
    if (l1 == 0) {
        return 0;
    }

    do {
        l1 = *(++left);
        r1 = *(++right);
        if (l1 - r1) {
            return l1 - r1;
        }
        if (l1 == 0) {
            return 0;
        }
    } while (1);
}

int strncmp(const char* str1, const char* str2, size_t n)
{
	const unsigned char* p1 = (unsigned char*)str1 - 1;
	const unsigned char* p2 = (unsigned char*)str2 - 1;
	unsigned long c1, c2;

	n++;

	while (--n)
		if ((c1 = *++p1) != (c2 = *++p2))
			return (c1 - c2);
		else if (!c1)
			break;
	return 0;
}

char* strchr(const char* str, int c) {
    const unsigned char* p = (unsigned char*)str - 1;
    unsigned long chr = (c & 0xFF);

    unsigned long ch;
    while (ch = *++p) {
        if (ch == chr) {
            return (char*)p;
        }
    }

    return chr ? NULL : (char*)p;
}

typedef unsigned char char_map[32];

#define set_char_map(map, ch) map[(unsigned char)ch >> 3] |= (1 << (ch & 7))
#define tst_char_map(map, ch) (map[(unsigned char)ch >> 3] & (1 << (ch & 7)))

char* strtok(char* str, const char* set) {
    unsigned char *p, *q;
    int c;
    char_map map = {0};
    static unsigned char* empty = (unsigned char*)"";
    static unsigned char* s = (unsigned char*)"";

    if (str) {
        s = (unsigned char*)str;
    }

    p = (unsigned char*)set - 1;

    while (c = *++p) {
        set_char_map(map, c);
    }

    p = s - 1;

    while (c = *++p) {
        if (!tst_char_map(map, c)) {
            break;
        }
    }

    if (!c) {
        s = empty;
        return NULL;
    }

    q = p;

    while (c = *++p) {
        if (tst_char_map(map, c)) {
            break;
        }
    }

    if (!c) {
        s = empty;
    } else {
        s = p + 1;
        *p = 0;
    }

    return (char*)q;
}

char* strstr(const char* str, const char* pat) {
    const unsigned char* s1 = (const unsigned char*)str - 1;
    const unsigned char* p1 = (const unsigned char*)pat - 1;
    unsigned long firstc, c1, c2;

    if ((pat == 0) || (!(firstc = *++p1))) {
        return (char*)str;
    }

    while (c1 = *++s1) {
        if (c1 == firstc) {
            const unsigned char* s2 = s1 - 1;
            const unsigned char* p2 = p1 - 1;

            while ((c1 = *++s2) == (c2 = *++p2) && c1)
                ;

            if (!c2)
                return (char*)s1;
        }
    }

    return NULL;
}

char* __strerror(int errnum, char* str) {
    if (errnum == 1) strcpy(str, "Argument list too long");
    else if (errnum == 2) strcpy(str, "Permission denied");
    else if (errnum == 3) strcpy(str, "Resource temporarily unavailable");
    else if (errnum == 4) strcpy(str, "Bad file descriptor");
    else if (errnum == 5) strcpy(str, "Device busy");
    else if (errnum == 6) strcpy(str, "No child processes");
    else if (errnum == 7) strcpy(str, "Resource deadlock avoided");
    else if (errnum == 8) strcpy(str, "Numerical argument out of domain");
    else if (errnum == 9) strcpy(str, "File exists");
    else if (errnum == 10) strcpy(str, "Bad address");
    else if (errnum == 11) strcpy(str, "File too large");
    else if (errnum == 12) strcpy(str, "File Position Error");
    else if (errnum == 13) strcpy(str, "Wide character encoding error");
    else if (errnum == 14) strcpy(str, "Interrupted system call");
    else if (errnum == 15) strcpy(str, "Invalid argument");
    else if (errnum == 16) strcpy(str, "Input/output error");
    else if (errnum == 17) strcpy(str, "Is a directory");
    else if (errnum == 18) strcpy(str, "Too many open files");
    else if (errnum == 19) strcpy(str, "Too many links");
    else if (errnum == 20) strcpy(str, "File name too long");
    else if (errnum == 21) strcpy(str, "Too many open files in system");
    else if (errnum == 22) strcpy(str, "Operation not supported by device");
    else if (errnum == 23) strcpy(str, "No such file or directory");
    else if (errnum == 24) strcpy(str, "No error detected");
    else if (errnum == 25) strcpy(str, "Exec format error");
    else if (errnum == 26) strcpy(str, "No locks available");
    else if (errnum == 27) strcpy(str, "Cannot allocate memory");
    else if (errnum == 28) strcpy(str, "No space left on device");
    else if (errnum == 29) strcpy(str, "Function not implemented");
    else if (errnum == 30) strcpy(str, "Not a directory");
    else if (errnum == 31) strcpy(str, "Directory not empty");
    else if (errnum == 32) strcpy(str, "Inappropriate ioctl for device");
    else if (errnum == 33) strcpy(str, "Device not configured");
    else if (errnum == 34) strcpy(str, "Operation not permitted");
    else if (errnum == 35) strcpy(str, "Broken pipe");
    else if (errnum == 36) strcpy(str, "Result too large");
    else if (errnum == 37) strcpy(str, "Read-only file system");
    else if (errnum == 38) strcpy(str, "Signal error");
    else if (errnum == 39) strcpy(str, "Illegal seek");
    else if (errnum == 40) strcpy(str, "No such process");
    else if (errnum == 41) strcpy(str, "Unknown error");
    else if (errnum == 42) strcpy(str, "Cross-device link");
    else sprintf(str, "Unknown Error (%d)", errnum);
    return str;
}
