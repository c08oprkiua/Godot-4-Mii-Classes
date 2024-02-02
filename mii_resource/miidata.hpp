#ifndef MIIDATA_H
#define MIIDATA_H

#include "core/io/resource.h"
#include "core/variant/typed_array.h"

class MiiDataResource : 
public Resource {
    GDCLASS(MiiDataResource, Resource);
public:
    //all the enum declarations

    enum RegLockType: uint8_t {
        REGLOCK_NONE,
        REGLOCK_JP_ONLY,
        REGLOCK_US_ONLY,
        REGLOCK_EU_ONLY,
    };

    enum CharSetType: uint8_t {
        CHAR_JAPAN_USA_EUROPE, 
        CHAR_CHINA, 
        CHAR_KOREA, 
        CHAR_TAIWAN
    };

    enum Devices: uint8_t {
        DEVICE_WII = 1,
        DEVICE_DS,
        DEVICE_THREEDS,
        DEVICE_WII_U_SWITCH,
    };
    enum FavColor: uint8_t {
        COLOR_RED,
        COLOR_ORANGE,
        COLOR_YELLOW,
        COLOR_LIGHT_GREEN, 
        COLOR_DARK_GREEN, 
        COLOR_BLUE, 
        COLOR_LIGHT_BLUE, 
        COLOR_PINK, 
        COLOR_PURPLE, 
        COLOR_BROWN, 
        COLOR_WHITE, 
        COLOR_BLACK
    };
    enum Months: uint8_t {
        MONTH_JANUARY,
        MONTH_FEBRUARY,
        MONTH_MARCH,
        MONTH_APRIL,
        MONTH_MAY,
        MONTH_JUNE,
        MONTH_JULY,
        MONTH_AUGUST,
        MONTH_SEPTEMBER,
        MONTH_OCTOBER,
        MONTH_NOVEMBER,
        MONTH_DECEMBER
    };
    
    //Haha, Mii sex, very funny//
    enum MiiSex: uint8_t {
        SEX_MALE,
        SEX_FEMALE
    };


private:

    bool BoolCheck(int check);

public:

    // Meta
    int version = 3;
    bool profanity = false;
    RegLockType region_lock = REGLOCK_NONE;
    CharSetType char_set = CHAR_JAPAN_USA_EUROPE;
    Devices origin_device = DEVICE_WII_U_SWITCH;

    //Mii ID
    String mii_id; //Todo: Make this value read-only
    int creation_date = 0;
    //bool unknown;
    bool temporary = false;
    bool dsi = false;
    bool special = false;
    String mac_address;

    //General
    MiiSex sex = SEX_MALE;
    Months birthday_month = MONTH_NOVEMBER;
    int birthday_day = 19;
    FavColor favorite_color = COLOR_RED;
    bool favorite_mii = false;
    String mii_name;
    int body_width = 1;
    int body_height = 1;
    bool sharable = true;
    String author;

    //It'd be a neat detail if all these values were set
    // to match that one default red shirt mii

    //Face misc.
    int face_shape = 1;
    int skin_color = 1;
    int wrinkles = 1;
    int makeup = 1;

    //Hair 
    int hair_style = 1;
    int hair_color = 1;
    bool hair_flip = 1;

    //Eyes
    int eye_style = 1;
    int eye_color = 1;
    int eye_x_scale = 1;
    int eye_y_scale = 1;
    int eye_rotation = 1;
    int eye_x_spacing = 1;
    int eye_y_position = 1;

    //Eyebrows
    int eyebrow_style = 1;
    int eyebrow_color = 1;
    int eyebrow_x_scale = 1;
    int eyebrow_y_scale = 1;
    int eyebrow_rotation = 1;
    int eyebrow_x_spacing = 1;
    int eyebrow_y_position = 1;

    //Nose
    int nose_style = 1;
    int nose_scale = 1;
    int nose_y_position = 1;

    //Mouth
    int mouth_style = 1;
    int mouth_color = 1;
    int mouth_x_scale = 1;
    int mouth_y_scale = 1;
    int mouth_y_position = 1;

    //Facial hair
    int beard_style = 1;
    int beard_color = 1;
    int mustache_style = 1;
    int mustache_scale = 1;
    int mustache_y_position = 1;

    //Glasses
    int glasses_style = 1;
    int glasses_color = 1;
    int glasses_scale = 1;
    int glasses_y_position = 1;

    //Mole
    bool has_mole = false;
    int mole_scale = 1;
    int mole_x_position = 1;
    int mole_y_position = 1;

protected:
	static void _bind_methods();

public:
    MiiDataResource();
    void LoadFromBuffer(PackedByteArray buffer);

    PackedByteArray WriteToBuffer();
    //Meta
    void set_version(int version);
    int get_version();
    void set_profanity(int profanity);
    bool get_profanity();
    void set_region_lock(RegLockType region_lock);
    RegLockType get_region_lock();
    void set_char_set(CharSetType char_set);
    CharSetType get_char_set();
    void set_origin_device(Devices origin_dev);
    Devices get_origin_device();
    void set_mii_id(String new_id);
    String get_mii_id();
    void set_creation_date(int date);
    int get_creation_date();
    void set_dsi(bool is_from_dsi);
    bool get_dsi();
    void set_special(bool is_special);
    bool get_special();
    void set_mac_address(String new_address);
    String get_mac_address();
    //General
    void set_sex(MiiSex wtfcppsex);
    MiiSex get_sex();
    void set_birthday_month(Months bdaymonth);
    Months get_birthday_month(); 
    void set_birthday_day(int bdayday);
    int get_birthday_day();
    void set_favorite_color(FavColor color);
    FavColor get_favorite_color();
    void set_favorite_mii(bool favorite);
    bool get_favorite_mii();
    void set_mii_name(String new_name);
    String get_mii_name();
    void set_body_width(int wideness);
    int get_body_width();
    void set_body_height(int heightness);
    int get_body_height();
    void set_sharable(bool is_sharable);
    bool get_sharable();
    void set_author(String new_author);
    String get_author();
    //Face Misc.
    void set_face_shape(int shape);
    int get_face_shape();
    void set_skin_color(int color);
    int get_skin_color();
    void set_wrinkles(int new_wrinkles);
    int get_wrinkles();
    void set_makeup(int new_makeup);
    int get_makeup();
    //Hair
    void set_hair_style(int style);
    int get_hair_style();
    void set_hair_color(int color);
    int get_hair_color();
    void set_hair_flip(bool flip);
    bool get_hair_flip();
    //Eyes
    void set_eye_style(int eye);
    int get_eye_style();
    void set_eye_color(int eye);
    int get_eye_color(); 
    void set_eye_x_scale(int eye);
    int get_eye_x_scale();
    void set_eye_y_scale(int eye);
    int get_eye_y_scale();
    void set_eye_rotation(int eye);
    int get_eye_rotation();
    void set_eye_x_spacing(int eye);
    int get_eye_x_spacing();
    void set_eye_y_position(int eye);
    int get_eye_y_position();
    //Eyebrows
	void set_eyebrow_style(int val); 
	int get_eyebrow_style();
	void set_eyebrow_color(int val); 
	int get_eyebrow_color();
	void set_eyebrow_x_scale(int val); 
	int get_eyebrow_x_scale();
	void set_eyebrow_y_scale(int val); 
	int get_eyebrow_y_scale();
	void set_eyebrow_rotation(int val); 
	int get_eyebrow_rotation();
	void set_eyebrow_x_spacing(int val); 
	int get_eyebrow_x_spacing();
	void set_eyebrow_y_position(int val); 
	int get_eyebrow_y_position();
    //Nose
	void set_nose_style(int val); 
	int get_nose_style();
	void set_nose_scale(int val); 
	int get_nose_scale();
	void set_nose_y_position(int val); 
	int get_nose_y_position();
    //Mouth
	void set_mouth_style(int val); 
	int get_mouth_style();
	void set_mouth_color(int val); 
	int get_mouth_color();
	void set_mouth_x_scale(int val); 
	int get_mouth_x_scale();
	void set_mouth_y_scale(int val); 
	int get_mouth_y_scale();
	void set_mouth_y_position(int val); 
	int get_mouth_y_position();
    //Facial Hair
	void set_beard_style(int val); 
	int get_beard_style();
	void set_beard_color(int val); 
	int get_beard_color();
	void set_mustache_style(int val); 
	int get_mustache_style();
	void set_mustache_scale(int val); 
	int get_mustache_scale();
	void set_mustache_y_position(int val); 
	int get_mustache_y_position();
    //Glasses
	void set_glasses_style(int val); 
	int get_glasses_style();
	void set_glasses_color(int val); 
	int get_glasses_color();
	void set_glasses_scale(int val); 
	int get_glasses_scale();
	void set_glasses_y_position(int val); 
	int get_glasses_y_position();
    //Mole
    void set_has_mole(bool val); 
	bool get_has_mole();
	void set_mole_scale(int val); 
	int get_mole_scale();
	void set_mole_x_position(int val); 
	int get_mole_x_position();
	void set_mole_y_position(int val); 
	int get_mole_y_position();

    ~MiiDataResource();
};

VARIANT_ENUM_CAST(MiiDataResource::RegLockType);
VARIANT_ENUM_CAST(MiiDataResource::CharSetType);
VARIANT_ENUM_CAST(MiiDataResource::Devices);
VARIANT_ENUM_CAST(MiiDataResource::FavColor);
VARIANT_ENUM_CAST(MiiDataResource::Months);
VARIANT_ENUM_CAST(MiiDataResource::MiiSex);

#endif