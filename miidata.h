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
    int version = 3;
    bool profanity = false;
    int region_lock = 0;
    int char_set;
    //enum origin_device {Wii = 1, DS, ThreeDS, WiiUSwitch};
    int origin_device = 3;
    int mii_id;
    int creation_date;
    //bool unknown;
    bool temporary;
    bool dsi;
    bool special;
    String mac_address;

    //General
    //enum sex {Male, Female};
    int sex = 0;
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
    //Meta
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
    void set_mii_id(int new_id);
    int get_mii_id();
    void set_creation_date(int date);
    int get_creation_date();
    void set_dsi(bool is_from_dsi);
    bool get_dsi();
    void set_special(bool is_special);
    bool get_special();
    void set_mac_address(String new_address);
    String get_mac_address();

    //General
    void set_sex(int wtfcppsex);
    int get_sex();
    void set_birthday_month(int bdaymonth);
    int get_birthday_month();
    void set_birthday_day(int bdayday);
    int get_birthday_day();
    void set_favorite_color(int color);
    int get_favorite_color();
    void set_favorite_mii(bool favorite);
    bool get_favorite_mii();
    void set_mii_name(String new_name);
    String get_mii_name();
    void set_width(float wideness);
    float get_width();
    void set_height(float heightness);
    float get_height();
    void set_sharable(bool is_sharable);
    bool get_sharable();
    void set_author(String new_author);
    String get_author();

    ~MiiDataResource();
};



#endif