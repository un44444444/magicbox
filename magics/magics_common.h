#ifndef MAGICS_COMMON_H
#define MAGICS_COMMON_H

#include <string>

typedef short int magicnum_t;
typedef struct magicobject{
    magicnum_t numarray[6];
    magicnum_t specialnum;
    //
    magicobject();
    magicnum_t* get_array() {return numarray;}
    size_t get_arraysize() const {return 6;}
    magicnum_t get_specialnum() const {return specialnum;}
    std::string to_string() const;
} magicobject_t;

extern int caculate_ac(const magicobject_t& mo);

#endif // MAGICS_COMMON_H
