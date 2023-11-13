#ifndef MIIDATA_H
#define MIIDATA_H

#include "core/io/resource.h"
#include "core/variant/typed_array.h"

class MiiDataResource : 
public Resource {
    GDCLASS(MiiDataResource, Resource);

private:

    bool BoolCheck(int check);
    int BinaryToInt(TypedArray<int> binary);
    TypedArray<int> ByteToBinary(int byte);
    // Meta
    int version;
    bool profanity;
    int region_lock;
    //enum region_lock {none, JPN, USA, EUR};
    int char_set;
    //enum char_set {JPN_USA_EUR, CHN, KOR, TWN};
    //enum origin_device {Wii = 1, DS, ThreeDS, WiiUSwitch};
    int origin_device;
    int mii_id;
    int creation_date;
    //bool unknown;
    bool temporary;
    bool dsi;
    bool special;
    String mac_address;

    //General
    enum sex {Male, Female};
    int birthday_month;
    int birthday_day;
    int favorite_color;
    bool favorite_mii;
    String mii_name;
    float width;
    float height;
    bool sharable;
    String author;

    //Face misc.
    int face_shape;
    int skin_color;
    int wrinkles;
    int makeup;

    //Hair 
    int hair_style;
    int hair_color; 
    bool hair_flip;

    //Eyebrows

protected:
	static void _bind_methods();

public:
    MiiDataResource();
    void LoadFromBuffer(PackedByteArray buffer);

    void WriteToBuffer();

    void set_version(int version);
    int get_version();

    void set_profanity(int profanity);
    bool get_profanity();

    void set_region_lock(int region_lock);
    int get_region_lock();

    void set_char_set(int char_set);
    int get_char_set();

    void set_origin_device(int origin_dev);
    int get_origin_device();



    void set_favorite_mii(bool favorite);
    bool get_favorite_mii();

    ~MiiDataResource();
};



#endif