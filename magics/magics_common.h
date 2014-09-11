#ifndef MAGICBOX_MAGICS_COMMON_H
#define MAGICBOX_MAGICS_COMMON_H

#define SIZEOF_ARRAY(array) sizeof(array)/sizeof(array[0])

#include <string>

typedef short int magicnum_t;
typedef struct magicobject{
    magicnum_t _numarray[6];
    magicnum_t _specialnum;
    magicnum_t _ac;
    magicnum_t _score;
    //
    magicobject();
    const magicnum_t* get_array() const {return _numarray;}
    size_t get_arraysize() const {return sizeof(_numarray)/sizeof(magicnum_t);}
    magicnum_t get_specialnum() const {return _specialnum;}
    std::string to_string() const;
    //
    magicnum_t* get_array() {return _numarray;}
    void set_specialnum(int specialnum) {_specialnum = specialnum;}
    void set_ac(int ac) {_ac = ac;}
    void set_score(int score) {_score = score;}
} magicobject_t;

extern int caculate_ac(const magicobject_t& mo);
extern int caculate_score(const magicobject_t& mo);

#endif // MAGICBOX_MAGICS_COMMON_H
