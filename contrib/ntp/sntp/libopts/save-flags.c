/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (save-flags.c)
 *
 *  It has been AutoGen-ed
 *  From the definitions    /tmp/.ag-ufBbQe/save-flags.def
 *  and the template file   str2enum
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name ``Bruce Korb'' nor the name of any other
 *    contributor may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * str2enum IS PROVIDED BY Bruce Korb ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Bruce Korb OR ANY OTHER CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "save-flags.h"
#include <sys/types.h>
#ifndef MISSING_INTTYPES_H
# include <inttypes.h>
#endif

typedef enum {
    SVFL_BNM_DEFAULT  = 0,
    SVFL_BNM_USAGE    = 1,
    SVFL_BNM_UPDATE   = 2,
    SVFL_COUNT_BNM
} save_flags_enum_t;

static save_flags_enum_t
find_save_flags_bnm(char const * str, size_t len);


#include <sys/types.h>
#include <string.h>
#ifndef NUL
#define NUL '\0'
#endif

/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf save-flags.gp  */
/* Computed positions: -k'' */


# if 0 /* gperf build options: */
// %struct-type
// %language=ANSI-C
// %includes
// %global-table
// %omit-struct-type
// %readonly-tables
// %compare-strncmp
//
// %define slot-name               svfl_name
// %define hash-function-name      save_flags_hash
// %define lookup-function-name    find_save_flags_name
// %define word-array-name         save_flags_table
// %define initializer-suffix      ,SVFL_COUNT_BNM
//
# endif

#include "save-flags.h"
typedef struct {
    char const *    svfl_name;
    save_flags_enum_t svfl_id;
} save_flags_map_t;
#include <string.h>

/* maximum key range = 3, duplicates = 0 */

static unsigned int
save_flags_hash (register const char *str, register size_t len)
{
  (void)str;
  (void)len;
  return len;
}

static const save_flags_map_t save_flags_table[] =
  {
    {"",SVFL_COUNT_BNM}, {"",SVFL_COUNT_BNM},
    {"",SVFL_COUNT_BNM}, {"",SVFL_COUNT_BNM},
    {"",SVFL_COUNT_BNM},
    {"usage",    SVFL_BNM_USAGE},
    {"update",   SVFL_BNM_UPDATE},
    {"default",  SVFL_BNM_DEFAULT}
  };

static inline const save_flags_map_t *
find_save_flags_name (register const char *str, register size_t len)
{
  if (len <= 7 && len >= 5)
    {
      register unsigned int key = (int)save_flags_hash (str, len);

      if (key <= 7)
        {
          register const char *s = save_flags_table[key].svfl_name;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return &save_flags_table[key];
        }
    }
  return 0;
}

/**
 * Convert a command (keyword) to a save_flags_enum_t enumeration value.
 *
 * @param[in] str   a string that should start with a known key word.
 * @param[in] len   the provided length of the keyword at \a str.
 * @returns the enumeration value.
 * If not found, that value is SVFL_COUNT_BNM.
 */
static save_flags_enum_t
find_save_flags_bnm(char const * str, size_t len)
{
    save_flags_map_t const * map;

    map = find_save_flags_name(str, (unsigned int)len);
    if (map != NULL)
        return map->svfl_id;
    /* Check for a partial match */
    {
        /*
         * Indexes of valid save_flags_table entries in sorted order:
         */
        static unsigned int const ix_map[] = {
            7, 6, 5 };
        save_flags_enum_t res = SVFL_COUNT_BNM;
        static int const HI = (sizeof(ix_map) / sizeof(ix_map[0])) - 1;
        int lo = 0;
        int hi = HI;
        int av;
        int cmp;

        for (;;) {
            av  = (hi + lo) / 2;
            map = save_flags_table + ix_map[av];
            cmp = strncmp(map->svfl_name, str, len);
            if (cmp == 0) break;
            if (cmp > 0)
                 hi = av - 1;
            else lo = av + 1;
            if (lo > hi)
                return SVFL_COUNT_BNM;
        }
        res = map->svfl_id;
        /*
         * If we have an exact match, accept it.
         */
        if (map->svfl_name[len] == NUL)
            return res;
        /*
         * Check for a duplicate partial match (a partial match
         * with a higher or lower index than "av".
         */
        if (av < HI) {
            map = save_flags_table + ix_map[av + 1];
            if (strncmp(map->svfl_name, str, len) == 0)
                return SVFL_COUNT_BNM;
        }
        if (av > 0) {
            map = save_flags_table + ix_map[av - 1];
            if (strncmp(map->svfl_name, str, len) == 0)
                return SVFL_COUNT_BNM;
        }
        return res;
    }
}

/**
 * Convert a string to a save_flags_mask_t mask.
 * Bit names prefixed with a hyphen have the bit removed from the mask.
 * If the string starts with a '-', '+' or '|' character, then
 * the old value is used as a base, otherwise the result mask
 * is initialized to zero.  Separating bit names with '+' or '|'
 * characters is optional.  By default, the bits are "or"-ed into the
 * result.
 *
 * @param[in] str string with a list of bit names
 * @param[in] old previous value, used if \a str starts with a '+' or '-'.
 *
 * @returns an unsigned integer with the bits set.
 */
save_flags_mask_t
save_flags_str2mask(char const * str, save_flags_mask_t old)
{
    static char const white[] = ", \t\f";
    static char const name_chars[] =
        "adefglpstu"
        "ADEFGLPSTU";

    save_flags_mask_t res = 0;
    int have_data = 0;

    for (;;) {
        save_flags_enum_t val;
        unsigned int val_len;
        unsigned int invert = 0;

        str += strspn(str, white);
        switch (*str) {
        case NUL: return res;
        case '-': case '~':
            invert = 1;
            /* FALLTHROUGH */

        case '+': case '|':
            if (have_data == 0)
                res = old;

            str += 1 + strspn(str + 1, white);
            if (*str == NUL)
                return 0;
        }

        val_len = strspn(str, name_chars);
        if (val_len == 0)
            return 0;
        val = find_save_flags_bnm(str, val_len);
        if (val == SVFL_COUNT_BNM)
            return 0;
        if (invert)
            res &= ~((save_flags_mask_t)1 << val);
        else
            res |= (save_flags_mask_t)1 << val;
        have_data = 1;
        str += val_len;
    }
}
/* end of save-flags.c */
