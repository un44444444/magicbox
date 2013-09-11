#ifndef MAGICS_COMMON_H
#define MAGICS_COMMON_H

#define SIZEOF_ARRAY(array) sizeof(array)/sizeof(array[0])

#include <string>

typedef short int magicnum_t;
typedef struct magicobject{
    magicnum_t numarray[6];
    magicnum_t specialnum;
    //
    magicobject();
    magicnum_t* get_array() {return numarray;}
    const magicnum_t* get_array() const {return numarray;}
    size_t get_arraysize() const {return 6;}
    magicnum_t get_specialnum() const {return specialnum;}
    std::string to_string(int ac) const;
} magicobject_t;

extern int caculate_ac(const magicobject_t& mo);

#endif // MAGICS_COMMON_H
