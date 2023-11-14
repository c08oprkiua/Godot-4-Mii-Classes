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
    int char_set = 0;
    int origin_device = 3;
    String mii_id;
    int creation_date;
    //bool unknown;
    bool temporary = false;
    bool dsi = false;
    bool special = false;
    String mac_address;

    //General
    int sex = 0;
    int birthday_month = 10;
    int birthday_day = 19;
    int favorite_color = 5;
    bool favorite_mii = false;
    String mii_name;
    int body_width = 1;
    int body_height = 1;
    bool sharable = true;
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

    //Eyes
    int eye_style;
    int eye_color;
    int eye_x_scale = 1;
    int eye_y_scale = 1;
    int eye_rotation;
    int eye_x_spacing;
    int eye_y_position;

    //Eyebrows
    int eyebrow_style;
    int eyebrow_color;
    int eyebrow_x_scale = 1;
    int eyebrow_y_scale = 1;
    int eyebrow_rotation;
    int eyebrow_x_spacing;
    int eyebrow_y_position;

    //Nose
    int nose_style;
    int nose_scale = 1;
    int nose_y_position;

    //Mouth
    int mouth_style;
    int mouth_color;
    int mouth_x_scale = 1;
    int mouth_y_scale = 1;
    int mouth_y_position;

    //Facial hair
    int beard_style;
    int beard_color;
    int mustache_style;
    int mustache_scale = 1;
    int mustache_y_position;

    //Glasses
    int glasses_style;
    int glasses_color;
    int glasses_scale = 1;
    int glasses_y_position;

    //Mole
    bool has_mole = false;
    int mole_scale = 1;
    int mole_x_position;
    int mole_y_position;

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



#endif