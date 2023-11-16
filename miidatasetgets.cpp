#include "miidata.h"

//Oh boy, a million SetGets

//Meta
void MiiDataResource::set_version(int val){
    version = val;
}
int MiiDataResource::get_version(){
    return version;
}
void MiiDataResource::set_profanity(int val){
    profanity = val;
}
bool MiiDataResource::get_profanity(){
    return profanity;
}
void MiiDataResource::set_region_lock(int val){
    region_lock = val;
}
int MiiDataResource::get_region_lock(){
    return region_lock;
}
void MiiDataResource::set_char_set(int val){
    char_set = val;
}
int MiiDataResource::get_char_set(){
    return char_set;
}
void MiiDataResource::set_origin_device(Devices val){
    if ((int)val < 1 || (int)val > 4){
        origin_device = DEVICE_WII_U_SWITCH;
    }
    else {
        origin_device = val;
    }
}
MiiDataResource::Devices MiiDataResource::get_origin_device(){
    return origin_device;
}
void MiiDataResource::set_mii_id(String val){
    mii_id = val;
}
String MiiDataResource::get_mii_id(){
    return mii_id;
}
void MiiDataResource::set_creation_date(int val){
    creation_date = val;
}
int MiiDataResource::get_creation_date(){
    return creation_date;
}
void MiiDataResource::set_dsi(bool val){
    dsi = val;
}
bool MiiDataResource::get_dsi(){
    return dsi;
}
void MiiDataResource::set_special(bool val){
    special = val;
}
bool MiiDataResource::get_special(){
    return special;
}
void MiiDataResource::set_mac_address(String val){
    mac_address = val;
}
String MiiDataResource::get_mac_address(){
    return mac_address;
}

//General
void MiiDataResource::set_sex(MiiSex wtfcppsex){
    if ((int)wtfcppsex > 1 || (int)wtfcppsex < 0){
    sex = SEX_MALE;
    }
    else {
        sex = wtfcppsex;
    }
}
MiiDataResource::MiiSex MiiDataResource::get_sex(){
    return sex;
}
void MiiDataResource::set_birthday_month(Months val){
    if ((int)val > 11 || (int)val < 0) {
        birthday_day = MONTH_NOVEMBER;
    }
    else{
    birthday_month = val;
    }
}
MiiDataResource::Months MiiDataResource::get_birthday_month(){
    return birthday_month;
}
void MiiDataResource::set_birthday_day(int val){
    if (val < 1){
        val = 1;
        birthday_day = val;
        return;
    };
    if (val >= 32){
        val = 31;
    };
    uint8_t maxday;
    switch(val){
        case MONTH_JANUARY:
            maxday = 31;
        case MONTH_FEBRUARY:
            maxday = 28;
        case MONTH_MARCH:
            maxday = 31;
        case MONTH_APRIL:
            maxday = 30;
        case MONTH_MAY:
            maxday = 31;
        case MONTH_JUNE:
            maxday = 30;
        case MONTH_JULY:
            maxday = 31;
        case MONTH_AUGUST:
            maxday = 31;
        case MONTH_SEPTEMBER:
            maxday = 30;
        case MONTH_OCTOBER:
            maxday = 31;
        case MONTH_NOVEMBER:
            maxday = 30;
        case MONTH_DECEMBER:
            maxday = 31;
    };
    if (val > maxday){
        val = maxday;
    };
    birthday_day = val;
}
int MiiDataResource::get_birthday_day(){
    return birthday_day;
}
void MiiDataResource::set_favorite_color(FavColor val){
    if ((int)val < 0 || (int)val > 11){
        favorite_color = COLOR_RED;
    }
    else {
        favorite_color = val;
    }
}
MiiDataResource::FavColor MiiDataResource::get_favorite_color(){
    return favorite_color;
}
void MiiDataResource::set_favorite_mii(bool val){
    favorite_mii = val;
}
bool MiiDataResource::get_favorite_mii(){
    return favorite_mii;
}
void MiiDataResource::set_mii_name(String val){
    mii_name = val;
}
String MiiDataResource::get_mii_name(){
    return mii_name;
}
void MiiDataResource::set_body_width(int val){
    body_width = val;
}
int MiiDataResource::get_body_width(){
    return body_width;
}
void MiiDataResource::set_body_height(int val){
    body_height = val;
}
int MiiDataResource::get_body_height(){
    return body_height;
}
void MiiDataResource::set_sharable(bool val){
    sharable = val;
}
bool MiiDataResource::get_sharable(){
    return sharable;
}
void MiiDataResource::set_author(String val){
    author = val;
}
String MiiDataResource::get_author(){
    return author;
}

//Face Misc.
void MiiDataResource::set_face_shape(int val){
    face_shape = val;
}
int MiiDataResource::get_face_shape(){
    return face_shape;
}
void MiiDataResource::set_skin_color(int val){
    skin_color = val;
}
int MiiDataResource::get_skin_color(){
    return skin_color;
}
void MiiDataResource::set_wrinkles(int val){
    wrinkles = val;
}
int MiiDataResource::get_wrinkles(){
    return wrinkles;
}
void MiiDataResource::set_makeup(int val){
    makeup = val;
}
int MiiDataResource::get_makeup(){
    return makeup;
}

//Hair
void MiiDataResource::set_hair_style(int val){
    hair_style = val;
}
int MiiDataResource::get_hair_style(){
    return hair_style;
}
void MiiDataResource::set_hair_color(int val){
    hair_color = val;
}
int MiiDataResource::get_hair_color(){
    return hair_color;
}
void MiiDataResource::set_hair_flip(bool val){
    hair_flip = val;
}
bool MiiDataResource::get_hair_flip(){
    return hair_flip;
}

//Eyes
void MiiDataResource::set_eye_style(int val){
    eye_style = val;
}
int MiiDataResource::get_eye_style(){
    return eye_style;
}
void MiiDataResource::set_eye_color(int val){
    eye_color = val;
}
int MiiDataResource::get_eye_color(){
    return eye_color;
}
void MiiDataResource::set_eye_x_scale(int val){
    eye_x_scale = val;
}
int MiiDataResource::get_eye_x_scale(){
    return eye_x_scale;
}
void MiiDataResource::set_eye_y_scale(int val){
    eye_y_scale = val;
}
int MiiDataResource::get_eye_y_scale(){
    return eye_y_scale;
}
void MiiDataResource::set_eye_rotation(int val){
    eye_rotation = val;
}
int MiiDataResource::get_eye_rotation(){
    return eye_rotation;
}
void MiiDataResource::set_eye_x_spacing(int val){
    eye_x_spacing = val;
}
int MiiDataResource::get_eye_x_spacing(){
    return eye_x_spacing;
}
void MiiDataResource::set_eye_y_position(int val){
    eye_y_position = val;
}
int MiiDataResource::get_eye_y_position(){
    return eye_y_position;
}

//Eyebrows
void MiiDataResource::set_eyebrow_style(int val){
    eyebrow_style = val;
}
int MiiDataResource::get_eyebrow_style(){
    return eyebrow_style;
}
void MiiDataResource::set_eyebrow_color(int val){
    eyebrow_color = val;
}
int MiiDataResource::get_eyebrow_color(){
    return eyebrow_color;
}
void MiiDataResource::set_eyebrow_x_scale(int val){
    eyebrow_x_scale = val;
}
int MiiDataResource::get_eyebrow_x_scale(){
    return eyebrow_x_scale;
}
void MiiDataResource::set_eyebrow_y_scale(int val){
    eyebrow_y_scale = val;
}
int MiiDataResource::get_eyebrow_y_scale(){
    return eyebrow_y_scale;
}
void MiiDataResource::set_eyebrow_rotation(int val){
    eyebrow_rotation = val;
}
int MiiDataResource::get_eyebrow_rotation(){
    return eyebrow_rotation;
}
void MiiDataResource::set_eyebrow_x_spacing(int val){
    eyebrow_x_spacing = val;
}
int MiiDataResource::get_eyebrow_x_spacing(){
    return eyebrow_x_spacing;
}
void MiiDataResource::set_eyebrow_y_position(int val){
    eyebrow_y_position = val;
}
int MiiDataResource::get_eyebrow_y_position(){
    return eyebrow_y_position;
}

//Nose
void MiiDataResource::set_nose_style(int val){
    nose_style = val;
}
int MiiDataResource::get_nose_style(){
    return nose_style;
}
void MiiDataResource::set_nose_scale(int val){
    nose_scale = val;
}
int MiiDataResource::get_nose_scale(){
    return nose_scale;
}
void MiiDataResource::set_nose_y_position(int val){
    nose_y_position = val;
}
int MiiDataResource::get_nose_y_position(){
    return nose_y_position;
}

//Mouth
void MiiDataResource::set_mouth_style(int val){
    mouth_style = val;
}
int MiiDataResource::get_mouth_style(){
    return mouth_style;
}
void MiiDataResource::set_mouth_color(int val){
    mouth_color = val;
}
int MiiDataResource::get_mouth_color(){
    return mouth_color;
}
void MiiDataResource::set_mouth_x_scale(int val){
    mouth_x_scale = val;
}
int MiiDataResource::get_mouth_x_scale(){
    return mouth_x_scale;
}
void MiiDataResource::set_mouth_y_scale(int val){
    mouth_y_scale = val;
}
int MiiDataResource::get_mouth_y_scale(){
    return mouth_y_scale;
}
void MiiDataResource::set_mouth_y_position(int val){
    mouth_y_position = val;
}
int MiiDataResource::get_mouth_y_position(){
    return mouth_y_position;
}

//Facial hair
void MiiDataResource::set_beard_style(int val){
    beard_style = val;
}
int MiiDataResource::get_beard_style(){
    return beard_style;
}
void MiiDataResource::set_beard_color(int val){
    beard_color = val;
}
int MiiDataResource::get_beard_color(){
    return beard_color;
}
void MiiDataResource::set_mustache_style(int val){
    mustache_style = val;
}
int MiiDataResource::get_mustache_style(){
    return mustache_style;
}
void MiiDataResource::set_mustache_scale(int val){
    mustache_scale = val;
}
int MiiDataResource::get_mustache_scale(){
    return mustache_scale;
}
void MiiDataResource::set_mustache_y_position(int val){
    mustache_y_position = val;
}
int MiiDataResource::get_mustache_y_position(){
    return mustache_y_position;
}

//Glasses
void MiiDataResource::set_glasses_style(int val){
    glasses_style = val;
}
int MiiDataResource::get_glasses_style(){
    return glasses_style;
}
void MiiDataResource::set_glasses_color(int val){
    glasses_color = val;
}
int MiiDataResource::get_glasses_color(){
    return glasses_color;
}
void MiiDataResource::set_glasses_scale(int val){
    glasses_scale = val;
}
int MiiDataResource::get_glasses_scale(){
    return glasses_scale;
}
void MiiDataResource::set_glasses_y_position(int val){
    glasses_y_position = val;
}
int MiiDataResource::get_glasses_y_position(){
    return glasses_y_position;
}

//Mole
void MiiDataResource::set_has_mole(bool val){
    has_mole = val;
}
bool MiiDataResource::get_has_mole(){
    return has_mole;
}
void MiiDataResource::set_mole_scale(int val){
    mole_scale = val;
}
int MiiDataResource::get_mole_scale(){
    return mole_scale;
}
void MiiDataResource::set_mole_x_position(int val){
    mole_x_position = val;
}
int MiiDataResource::get_mole_x_position(){
    return mole_x_position;
}
void MiiDataResource::set_mole_y_position(int val){
    mole_y_position = val;
}
int MiiDataResource::get_mole_y_position(){
    return mole_y_position;
}