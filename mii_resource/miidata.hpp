#ifndef MIIDATA_H
#define MIIDATA_H

#include "core/io/resource.h"
#include "core/variant/typed_array.h"

class MiiDataResource : public Resource {
    GDCLASS(MiiDataResource, Resource);
public:
    //all the enum declarations

    enum RegionLockType: uint8_t {
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
        //Interestingly, according to the validity checks in FFL, the maximum valid platform
        //value is 7. What the other 3 platforms would've been circa 2013, idk. 
        //Though, that is also the numerical bit max of the 3 bits this value gets in storage.
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
    
    enum MiiGender: uint8_t {
        GENDER_MALE,
        GENDER_FEMALE
    };

	enum ValueMaximums : uint8_t {
		MAX_BODY_HEIGHT = 128,
		MAX_BODY_WIDTH = 128,

		MAX_FACE_MAKEUP,
		//FFL_FACE_TYPE_MAX = 12,
		//FFL_FACELINE_COLOR_MAX = 6,
		//FFL_FACE_LINE_MAX = 12,
		//FFL_FACE_MAKE_MAX = 12,

		MAX_HAIR_STYLE = 131,
		MAX_HAIR_COLOR = 7,

		MAX_EYE_STYLE = 59,
		MAX_EYE_COLOR = 5,
		MAX_EYE_X_SCALE = 7,
		MAX_EYE_Y_SCALE = 6,
		MAX_EYE_ROTATION = 7,
		MAX_EYE_X_SPACING = 12,
		MAX_EYE_Y_POSITION = 18,

		MAX_EYEBROW_STYLE = 23,
		MAX_EYEBROW_COLOR = 7,
		MAX_EYEBROW_X_SCALE = 7,
		MAX_EYEBROW_Y_SCALE = 6,
		MAX_EYEBROW_ROTATION = 7,
		MAX_EYEBROW_X_SPACING = 12,
        MIN_EYEBROW_Y_POSITION = 3,
		MAX_EYEBROW_Y_POSITION = 18,

		MAX_NOSE_STYLE = 17,
		MAX_NOSE_SCALE = 8,
		MAX_NOSE_Y_POSITION = 18,

		MAX_MOUTH_STYLE = 35,
		MAX_MOUTH_COLOR = 4,
		MAX_MOUTH_X_SCALE = 8,
		MAX_MOUTH_Y_SCALE = 6,
		MAX_MOUTH_Y_POSITION = 18,

		MAX_BEARD_STYLE = 5,
		MAX_BEARD_COLOR = 7,
		MAX_MUSTACHE_STYLE = 5,
		MAX_MUSTACHE_SCALE = 8,
		MAX_MUSTACHE_Y_POSITION = 16,

		MAX_GLASSES_STYLE = 8,
		MAX_GLASSES_COLOR = 5,
		MAX_GLASSES_SCALE = 7,
		MAX_GLASSES_Y_POSITION = 20,

		MAX_MOLE_SCALE = 9,
		MAX_MOLE_X_POS = 17,
		MAX_MOLE_Y_POS = 31,
	};

private:
    //New memory friendly format
    struct {
        uint8_t version = 3;
        uint8_t restrictions;
        uint8_t page_slot_index;
        uint8_t unk_birth_platform;
    } meta; //0x00-0x03

    uint8_t author_id[8]; //0x04-???
    uint8_t creation_id[10];

    uint16_t personal_info;

    uint16_t name_bits[10]; 

    struct {
        uint8_t height;
        uint8_t width;
    } body;

    struct {
        uint8_t type_line_color; //The "local only" flag bit is also here
        uint8_t line_makeup;
    } face;

    struct {
        uint8_t type;
        uint8_t color_direction;
    } hair; //0x32

    struct {
        uint16_t type_color_scale; 
        uint16_t rotate_spacing_pos; 
    } eyes; 

    struct {
        uint8_t type_color;
        uint8_t scale;
        uint16_t rotation_positioning;
    } eyebrows;

    uint16_t nose;

    uint16_t mouth;
    uint8_t mouth_mustache;

    uint16_t mustache_beard;

    uint16_t glass;

    uint16_t mole;

    //old values

    //Mii ID
    String mii_id; //Todo: Make this value read-only
    int creation_date = 0;
    bool temporary = false;
    bool dsi = false;
    bool special = false;
    String mac_address;

    String mii_name;
    String author;

    int wrinkles;
    int skin_color;


    //It'd be a neat detail if all these values were set
    // to match that one default red shirt mii

    void _from_wii_data(PackedByteArray data);
    void _from_ds_data(PackedByteArray data);
    void _from_3ds_data(PackedByteArray data);
    void _from_wiiu_data(PackedByteArray data);

    PackedByteArray _to_wii_data();
    PackedByteArray _to_ds_data();
    PackedByteArray _to_3ds_data();
    PackedByteArray _to_wiiu_data();

protected:
	static void _bind_methods();

public:

    void LoadFromBuffer(PackedByteArray buffer);

    PackedByteArray WriteToBuffer(Devices target_output = DEVICE_WII_U_SWITCH);

    Color get_favorite_color();

    int get_checksum();

    //Meta

    void set_version(int version);
    int get_version();

    void set_profanity(bool profanity);
    bool get_profanity();

    void set_region_lock(RegionLockType region_lock);
    RegionLockType get_region_lock();

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

    void set_gender(MiiGender wtfcppsex);
    MiiGender get_gender();

    void set_birthday_month(Months bdaymonth);
    Months get_birthday_month(); 

    void set_birthday_day(int bdayday);
    int get_birthday_day();

    void set_favorite_color_value(FavColor color);
    FavColor get_favorite_color_value();

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

    void set_hair_color_value(int color);
    int get_hair_color_value();

    void set_hair_flip(bool flip);
    bool get_hair_flip();

    //Eyes

    void set_eye_style(int eye);
    int get_eye_style();

    void set_eye_color_value(int eye);
    int get_eye_color_value(); 

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

	void set_eyebrow_color_value(int val); 
	int get_eyebrow_color_value();

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

	void set_mouth_color_value(int val); 
	int get_mouth_color_value();

	void set_mouth_x_scale(int val); 
	int get_mouth_x_scale();

	void set_mouth_y_scale(int val); 
	int get_mouth_y_scale();

	void set_mouth_y_position(int val); 
	int get_mouth_y_position();

    //Facial Hair
	void set_beard_style(int val); 
	int get_beard_style();

	void set_beard_color_value(int val); 
	int get_beard_color_value();

	void set_mustache_style(int val); 
	int get_mustache_style();

	void set_mustache_scale(int val); 
	int get_mustache_scale();

	void set_mustache_y_position(int val); 
	int get_mustache_y_position();

    //Glasses

	void set_glasses_style(int val); 
	int get_glasses_style();

	void set_glasses_color_value(int val); 
	int get_glasses_color_value();

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

};

VARIANT_ENUM_CAST(MiiDataResource::RegionLockType);
VARIANT_ENUM_CAST(MiiDataResource::CharSetType);
VARIANT_ENUM_CAST(MiiDataResource::Devices);
VARIANT_ENUM_CAST(MiiDataResource::FavColor);
VARIANT_ENUM_CAST(MiiDataResource::Months);
VARIANT_ENUM_CAST(MiiDataResource::MiiGender);
VARIANT_ENUM_CAST(MiiDataResource::ValueMaximums);

#endif