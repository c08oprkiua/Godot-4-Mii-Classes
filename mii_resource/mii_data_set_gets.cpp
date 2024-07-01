#include "miidata.hpp"

//Oh boy, a million SetGets

//Meta
#define PROFANITY_FIELD 0b0000'0010
#define REGION_LOCK_FIELD 0b0000'1100
#define CHAR_SET_FIELD 0b0011'0000

#define ORIGIN_DEVICE_FIELD 0b0111'0000

void MiiDataResource::set_version(int val){
    meta.version = CLAMP(val, 0, 3);
}

int MiiDataResource::get_version(){
    return meta.version;
}

void MiiDataResource::set_profanity(bool new_profanity){
    new_profanity ? meta.restrictions |= PROFANITY_FIELD : meta.restrictions &= ~PROFANITY_FIELD;
}

bool MiiDataResource::get_profanity(){
    return ((meta.restrictions & PROFANITY_FIELD) >> 1);
}

void MiiDataResource::set_region_lock(RegionLockType new_region_lock){
    uint16_t val = (CLAMP(new_region_lock, REGLOCK_NONE, REGLOCK_EU_ONLY)) << 2; //make new aligned value
    meta.restrictions &= ~REGION_LOCK_FIELD; //clear field
    meta.restrictions |= val; //write new number to field
}

MiiDataResource::RegionLockType MiiDataResource::get_region_lock(){
    return (RegionLockType)((meta.restrictions & REGION_LOCK_FIELD) >> 2);
}

void MiiDataResource::set_char_set(CharSetType new_char_set){
    uint16_t val = (CLAMP(new_char_set, CHAR_JAPAN_USA_EUROPE, CHAR_TAIWAN)) << 4;
    meta.restrictions &= ~CHAR_SET_FIELD;
    meta.restrictions |= val;
}

MiiDataResource::CharSetType MiiDataResource::get_char_set(){
    return (CharSetType)((meta.restrictions & CHAR_SET_FIELD) >> 4);
}

void MiiDataResource::set_origin_device(Devices new_origin_device){
    uint16_t val = ((CLAMP(new_origin_device, DEVICE_WII, DEVICE_WII_U_SWITCH)) << 4);
    meta.unk_birth_platform &= ~ORIGIN_DEVICE_FIELD;
    meta.unk_birth_platform |= val;
}

MiiDataResource::Devices MiiDataResource::get_origin_device(){
    return (Devices)((meta.unk_birth_platform & ORIGIN_DEVICE_FIELD) >> 4);
}

//Mii ID stuff

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


//Personal Info (ie. stuff that doesn't pertain to facial features)
#define MII_GENDER_FIELD 0b0000'0000'0000'0001
#define BDAY_MONTH_FIELD 0b0000'0000'0001'1110
#define BDAY_DAY_FIELD 0b0000'0011'1110'0000
#define FAV_COLOR_FIELD 0b0011'1100'0000'0000
#define FAV_MII_FIELD 0b0100'0000'0000'0000

void MiiDataResource::set_gender(MiiGender new_gender){
    uint16_t val = (CLAMP(new_gender, GENDER_MALE, GENDER_FEMALE));
    personal_info &= ~MII_GENDER_FIELD; //clear field
    personal_info |= val; //write new number to field
}

MiiDataResource::MiiGender MiiDataResource::get_gender(){
    return (MiiGender)(personal_info & MII_GENDER_FIELD);
}

void MiiDataResource::set_birthday_month(Months new_month){
    uint16_t val = ((CLAMP(new_month, MONTH_JANUARY, MONTH_DECEMBER)) << 1);
    personal_info &= ~BDAY_MONTH_FIELD; //clear field
    personal_info |= val; //write new number to field
}

MiiDataResource::Months MiiDataResource::get_birthday_month(){
    return (Months)((personal_info & BDAY_MONTH_FIELD) >> 1);
}

void MiiDataResource::set_birthday_day(int new_day){
    uint8_t maxday;
    switch(get_birthday_month()){
        case MONTH_JANUARY:
            maxday = 31;
            break;
        case MONTH_FEBRUARY:
            maxday = 28;
            break;
        case MONTH_MARCH:
            maxday = 31;
            break;
        case MONTH_APRIL:
            maxday = 30;
            break;
        case MONTH_MAY:
            maxday = 31;
            break;
        case MONTH_JUNE:
            maxday = 30;
            break;
        case MONTH_JULY:
            maxday = 31;
            break;
        case MONTH_AUGUST:
            maxday = 31;
            break;
        case MONTH_SEPTEMBER:
            maxday = 30;
            break;
        case MONTH_OCTOBER:
            maxday = 31;
            break;
        case MONTH_NOVEMBER:
            maxday = 30;
            break;
        case MONTH_DECEMBER:
            maxday = 31;
            break;
    };
    uint16_t val = (CLAMP(new_day, 0, maxday)) << 5;
    personal_info &= ~BDAY_DAY_FIELD; //clear field
    personal_info |= val; //write new number to field
}

int MiiDataResource::get_birthday_day(){
    return ((personal_info & BDAY_DAY_FIELD) >> 5);
}

void MiiDataResource::set_favorite_color_value(FavColor new_fav_color){
    uint16_t val = ((CLAMP(new_fav_color, COLOR_RED, COLOR_BLACK)) << 10);
    personal_info &= ~FAV_COLOR_FIELD; //clear field
    personal_info |= val; //write new number to field
}

MiiDataResource::FavColor MiiDataResource::get_favorite_color_value(){
    return (FavColor)((personal_info & FAV_COLOR_FIELD) >> 10);
}

void MiiDataResource::set_favorite_mii(bool new_fav_mii){
    new_fav_mii ? personal_info |= FAV_MII_FIELD : personal_info &= ~FAV_MII_FIELD;
}

bool MiiDataResource::get_favorite_mii(){
    return ((personal_info & FAV_MII_FIELD) >> 14);
}

void MiiDataResource::set_mii_name(String val){
    
    mii_name = val;
}

String MiiDataResource::get_mii_name(){
    return mii_name;
}

void MiiDataResource::set_body_width(int val){
    body.width = CLAMP(val, 0, MAX_BODY_WIDTH);
}

int MiiDataResource::get_body_width(){
    return body.width;
}

void MiiDataResource::set_body_height(int val){
    body.height = CLAMP(val, 0, MAX_BODY_HEIGHT);
}

int MiiDataResource::get_body_height(){
    return body.height;
}

void MiiDataResource::set_author(String val){
    author = val;
}

String MiiDataResource::get_author(){
    return author;
}


//Face Misc.
#define SHARABLE_FIELD 0b0000'0001
#define FACE_SHAPE_FIELD 0b0001'1110
#define FACE_LINE_COLOR_FIELD 0b0110'0000

void MiiDataResource::set_sharable(bool new_sharable){
    new_sharable ? face.type_line_color |= SHARABLE_FIELD : face.type_line_color &= ~SHARABLE_FIELD;
}

bool MiiDataResource::get_sharable(){
    return (face.type_line_color & SHARABLE_FIELD);
}

void MiiDataResource::set_face_shape(int new_face_shape){
    uint16_t val = (new_face_shape << 1) & FACE_SHAPE_FIELD;
    face.type_line_color &= ~FACE_SHAPE_FIELD; //clear field
    face.type_line_color |= val; //write new number to field
}

int MiiDataResource::get_face_shape(){
    return (face.type_line_color & FACE_SHAPE_FIELD) >> 1;
}

void MiiDataResource::set_skin_color(int val){
    skin_color = val;
}

int MiiDataResource::get_skin_color(){
    return skin_color;
}

#define FACE_LINE_FIELD 0b0000'1111
#define MAKEUP_FIELD 0b1111'0000

void MiiDataResource::set_wrinkles(int val){
    wrinkles = val;
}

int MiiDataResource::get_wrinkles(){
    return wrinkles;
}

void MiiDataResource::set_makeup(int new_makeup){
    uint16_t val = (CLAMP(new_makeup, 0, MAX_FACE_MAKEUP)) << 4;
    face.line_makeup &= ~MAKEUP_FIELD;
    face.line_makeup |= val;
}

int MiiDataResource::get_makeup(){
    return ((face.line_makeup & MAKEUP_FIELD) >> 4);
}

//Hair
void MiiDataResource::set_hair_style(int val){
    hair.type = CLAMP(val, 0, MAX_HAIR_STYLE);
}

int MiiDataResource::get_hair_style(){
    return hair.type;
}

#define HAIR_COLOR_FIELD 0b0000'0011
#define HAIR_FLIP_FIELD 0b0000'0100

void MiiDataResource::set_hair_color_value(int new_hair_color){
    uint16_t val = CLAMP(new_hair_color, 0, MAX_HAIR_COLOR);
    hair.color_direction &= ~HAIR_COLOR_FIELD;
    hair.color_direction |= val;
}

int MiiDataResource::get_hair_color_value(){
    return (hair.color_direction & HAIR_COLOR_FIELD);
}

void MiiDataResource::set_hair_flip(bool new_hair_flip){
    new_hair_flip ? hair.color_direction |= HAIR_FLIP_FIELD : hair.color_direction &= ~HAIR_FLIP_FIELD;
}

bool MiiDataResource::get_hair_flip(){
    return ((hair.color_direction & HAIR_FLIP_FIELD) >> 2);
}


//Eyes
#define EYE_STYLE_FIELD 0b0000'0000'0011'1111
#define EYE_COLOR_FIELD 0b0000'0001'1100'0000
#define EYE_X_SCALE_FIELD 0b0001'1110'0000'0000
#define EYE_Y_SCALE_FIELD 0b1110'0000'0000'0000

void MiiDataResource::set_eye_style(int new_eye_style){
    uint16_t val = CLAMP(new_eye_style, 0, MAX_EYE_STYLE);
    eyes.rotate_spacing_pos &= ~EYE_STYLE_FIELD;
    eyes.rotate_spacing_pos |= val;
}

int MiiDataResource::get_eye_style(){
    return (eyes.type_color_scale & EYE_STYLE_FIELD);
}

void MiiDataResource::set_eye_color_value(int new_eye_color){
    uint16_t val = (CLAMP(new_eye_color, 0, MAX_EYE_COLOR)) << 6;
    eyes.type_color_scale &= ~EYE_COLOR_FIELD;
    eyes.type_color_scale |= val;
}

int MiiDataResource::get_eye_color_value(){
    return ((eyes.type_color_scale & EYE_COLOR_FIELD) >> 6);
}

void MiiDataResource::set_eye_x_scale(int new_eye_x_scale){
    uint16_t val = (CLAMP(new_eye_x_scale, 0, MAX_EYE_X_SCALE)) << 9;
    eyes.type_color_scale &= ~EYE_Y_SCALE_FIELD;
    eyes.type_color_scale |= val;
}

int MiiDataResource::get_eye_x_scale(){
    return ((eyes.type_color_scale & EYE_X_SCALE_FIELD) >> 9);
}

void MiiDataResource::set_eye_y_scale(int new_eye_y_scale){
    uint16_t val = (CLAMP(new_eye_y_scale, 0, MAX_EYE_Y_SCALE)) << 13;
    eyes.type_color_scale &= ~EYE_Y_SCALE_FIELD;
    eyes.type_color_scale |= val;
}

int MiiDataResource::get_eye_y_scale(){
    return ((eyes.type_color_scale & EYE_Y_SCALE_FIELD) >> 13);
}

#define EYE_ROTATION_FIELD 0b0000'0000'0001'1111
#define EYE_X_SPACING_FIELD 0b0000'0001'1110'0000
#define EYE_Y_POSITION_FIELD 0b0011'1110'0000'0000

void MiiDataResource::set_eye_rotation(int new_eye_rotation){
    uint16_t val = CLAMP(new_eye_rotation, 0, MAX_EYE_ROTATION);
    eyes.rotate_spacing_pos &= ~EYE_ROTATION_FIELD;
    eyes.rotate_spacing_pos |= val;
}

int MiiDataResource::get_eye_rotation(){
    return (eyes.rotate_spacing_pos & EYE_ROTATION_FIELD);
}

void MiiDataResource::set_eye_x_spacing(int new_eye_x_spacing){
    uint16_t val = (CLAMP(new_eye_x_spacing, 0, MAX_EYE_X_SPACING)) << 5;
    eyes.rotate_spacing_pos &= ~EYE_X_SPACING_FIELD;
    eyes.rotate_spacing_pos |= val;
}

int MiiDataResource::get_eye_x_spacing(){
    return ((eyes.rotate_spacing_pos & EYE_X_SPACING_FIELD) >> 5);
}

void MiiDataResource::set_eye_y_position(int new_eye_y_position){
    uint16_t val = (CLAMP(new_eye_y_position, 0, MAX_EYE_Y_POSITION)) << 9;
    eyes.rotate_spacing_pos &= ~EYE_Y_POSITION_FIELD;
    eyes.rotate_spacing_pos |= val;
}

int MiiDataResource::get_eye_y_position(){
    return ((eyes.rotate_spacing_pos & EYE_Y_POSITION_FIELD) >> 9);
}


//Eyebrows
#define EYEBROW_STYLE_FIELD 0b0001'1111
#define EYEBROW_COLOR_FIELD 0b1110'0000

void MiiDataResource::set_eyebrow_style(int new_eyebrow_style){
    uint8_t val = CLAMP(new_eyebrow_style, 0, MAX_EYEBROW_STYLE);
    eyebrows.type_color &= ~ EYEBROW_STYLE_FIELD;
    eyebrows.type_color |= val;
}

int MiiDataResource::get_eyebrow_style(){
    return (eyebrows.type_color & EYEBROW_STYLE_FIELD);
}

void MiiDataResource::set_eyebrow_color_value(int new_eyebrow_color){
    uint8_t val = (CLAMP(new_eyebrow_color, 0, MAX_EYEBROW_COLOR)) << 5;
    eyebrows.type_color &= ~EYEBROW_COLOR_FIELD;
    eyebrows.type_color |= val;
}

int MiiDataResource::get_eyebrow_color_value(){
    return ((eyebrows.type_color & EYEBROW_COLOR_FIELD) >> 5);
}

#define EYEBROW_X_SCALE_FIELD 0b0000'1111
#define EYEBROW_Y_SCALE_FIELD 0b0111'0000

void MiiDataResource::set_eyebrow_x_scale(int new_eyebrow_x_scale){
    uint8_t val = CLAMP(new_eyebrow_x_scale, 0, MAX_EYEBROW_X_SCALE);
    eyebrows.scale &= ~EYEBROW_X_SCALE_FIELD;
    eyebrows.scale |= val;
}

int MiiDataResource::get_eyebrow_x_scale(){
    return (eyebrows.scale & EYEBROW_X_SCALE_FIELD);
}

void MiiDataResource::set_eyebrow_y_scale(int new_eyebrow_y_scale){
    uint8_t val = (CLAMP(new_eyebrow_y_scale, 0, MAX_EYEBROW_Y_SCALE)) << 4;
    eyebrows.scale &= ~EYEBROW_Y_SCALE_FIELD;
    eyebrows.scale |= val;
}

int MiiDataResource::get_eyebrow_y_scale(){
    return ((eyebrows.scale & EYEBROW_Y_SCALE_FIELD) >> 4);
}

#define EYEBROW_ROTATION_FIELD 0b0000'0000'0001'1111
#define EYEBROW_X_SPACING_FIELD 0b0000'0001'1110'0000
#define EYEBROW_Y_POSITION_FIELD 0b0011'1110'0000'0000

void MiiDataResource::set_eyebrow_rotation(int new_eyebrow_rotation){
    uint16_t val = CLAMP(new_eyebrow_rotation, 0, MAX_EYEBROW_ROTATION);
    eyebrows.rotation_positioning &= ~EYEBROW_ROTATION_FIELD;
    eyebrows.rotation_positioning |= val;
}

int MiiDataResource::get_eyebrow_rotation(){
    return (eyebrows.rotation_positioning & EYEBROW_ROTATION_FIELD);
}

void MiiDataResource::set_eyebrow_x_spacing(int new_eyebrow_x_spacing){
    uint16_t val = (CLAMP(new_eyebrow_x_spacing, 0, MAX_EYEBROW_X_SPACING)) << 5;
    eyebrows.rotation_positioning &= ~EYEBROW_X_SPACING_FIELD;
    eyebrows.rotation_positioning |= val;
}

int MiiDataResource::get_eyebrow_x_spacing(){
    return ((eyebrows.rotation_positioning & EYEBROW_X_SCALE_FIELD) >> 5);
}

void MiiDataResource::set_eyebrow_y_position(int new_eyebrow_y_position){
    uint16_t val = (CLAMP(new_eyebrow_y_position, MIN_EYEBROW_Y_POSITION, MAX_EYEBROW_Y_POSITION)) << 9;
    eyebrows.rotation_positioning &= EYEBROW_Y_POSITION_FIELD;
    eyebrows.rotation_positioning |= val;
}

int MiiDataResource::get_eyebrow_y_position(){
    return ((eyebrows.rotation_positioning & EYEBROW_Y_POSITION_FIELD) >> 9);
}


//Nose
#define NOSE_STYLE_FIELD 0b0000'0000'0001'1111
#define NOSE_SCALE_FIELD 0b0000'0001'1110'0000
#define NOSE_Y_POS_FIELD 0b0011'1110'0000'0000

void MiiDataResource::set_nose_style(int new_nose_style){
    uint16_t val = CLAMP(new_nose_style, 0, MAX_NOSE_STYLE);
    nose &= ~NOSE_STYLE_FIELD;
    nose |= val;
}

int MiiDataResource::get_nose_style(){
    return (nose & NOSE_STYLE_FIELD);
}

void MiiDataResource::set_nose_scale(int new_nose_scale){
    uint16_t val = (CLAMP(new_nose_scale, 0, MAX_NOSE_SCALE)) << 5;
    nose &= ~NOSE_SCALE_FIELD;
    nose |= val;
}

int MiiDataResource::get_nose_scale(){
    return ((nose & NOSE_SCALE_FIELD) >> 5);
}

void MiiDataResource::set_nose_y_position(int new_nose_y_position){
    uint16_t val = (CLAMP(new_nose_y_position, 0, MAX_NOSE_Y_POSITION)) << 9;
    nose &= ~NOSE_Y_POS_FIELD;
    nose |= val;
}

int MiiDataResource::get_nose_y_position(){
    return ((nose & NOSE_Y_POS_FIELD) >> 9);
}


//Mouth
#define MOUTH_STYLE_FIELD 0b0000'0000'0011'1111
#define MOUTH_COLOR_FIELD 0b0000'0001'1100'0000
#define MOUTH_X_SCALE_FIELD 0b0001'1110'0000'0000
#define MOUTH_Y_SCALE_FIELD 0b1110'0000'0000'0000


void MiiDataResource::set_mouth_style(int new_mouth_style){
    uint16_t val = CLAMP(new_mouth_style, 0, MAX_MOUTH_STYLE);
    mouth &= ~MOUTH_STYLE_FIELD;
    mouth |= val;
}

int MiiDataResource::get_mouth_style(){
    return (mouth & MOUTH_STYLE_FIELD);
}

void MiiDataResource::set_mouth_color_value(int new_mouth_color){
    uint16_t val = (CLAMP(new_mouth_color, 0, MAX_MOUTH_COLOR)) << 6;
    mouth &= ~MOUTH_COLOR_FIELD;
    mouth |= val;
}

int MiiDataResource::get_mouth_color_value(){
    return ((mouth & MOUTH_COLOR_FIELD) >> 6);
}

void MiiDataResource::set_mouth_x_scale(int new_mouth_x_scale){
    uint16_t val = (CLAMP(new_mouth_x_scale, 0, MAX_MOUTH_X_SCALE)) << 9;
    mouth &= ~MOUTH_X_SCALE_FIELD;
    mouth |= val;
}

int MiiDataResource::get_mouth_x_scale(){
    return ((mouth & MOUTH_X_SCALE_FIELD) >> 9);
}

void MiiDataResource::set_mouth_y_scale(int new_mouth_y_scale){
    uint16_t val = (CLAMP(new_mouth_y_scale, 0, MAX_MOUTH_Y_SCALE)) << 13;
    mouth &= ~MOUTH_Y_SCALE_FIELD;
    mouth |= val;
}

int MiiDataResource::get_mouth_y_scale(){
    return ((mouth & MOUTH_Y_SCALE_FIELD) >> 13);
}

#define MOUTH_Y_POSITION_FIELD 0b0001'1111
#define MUSTACHE_STYLE_FIELD 0b1110'0000

void MiiDataResource::set_mouth_y_position(int new_mouth_y_position){
    uint8_t val = CLAMP(new_mouth_y_position, 0, MAX_MOUTH_Y_POSITION);
    mouth_mustache &= ~MOUTH_Y_POSITION_FIELD;
    mouth_mustache |= val;
}

int MiiDataResource::get_mouth_y_position(){
    return (mouth_mustache & MOUTH_Y_POSITION_FIELD);
}

void MiiDataResource::set_mustache_style(int new_mustache_style){
    uint8_t val = (CLAMP(new_mustache_style, 0, MAX_MUSTACHE_STYLE)) << 5;
    mouth_mustache &= ~MUSTACHE_STYLE_FIELD;
    mouth_mustache |= val;
}

int MiiDataResource::get_mustache_style(){
    return ((mouth_mustache & MUSTACHE_STYLE_FIELD) >> 5);
}

//Facial hair
#define BEARD_STYLE_FIELD 0b0000'0000'0000'0111
#define BEARD_COLOR_FIELD 0b0000'0000'0011'1000
#define MUSTACHE_SCALE_FIELD 0b0000'0011'1100'0000
#define MUSTACHE_Y_POS_FIELD 0b0111'1100'0000'0000

void MiiDataResource::set_beard_style(int new_beard_style){
    uint16_t val = CLAMP(new_beard_style, 0, MAX_BEARD_STYLE);
    mustache_beard &= ~BEARD_STYLE_FIELD;
    mustache_beard |= val;
}

int MiiDataResource::get_beard_style(){
    return (mustache_beard & BEARD_STYLE_FIELD);
}

void MiiDataResource::set_beard_color_value(int new_beard_color){
    uint16_t val = (CLAMP(new_beard_color, 0, MAX_BEARD_COLOR)) << 3;
    mustache_beard &= ~BEARD_COLOR_FIELD;
    mustache_beard |= val;
}

int MiiDataResource::get_beard_color_value(){
    return ((mustache_beard & BEARD_COLOR_FIELD) >> 3);
}

void MiiDataResource::set_mustache_scale(int new_mustache_scale){
    uint16_t val = (CLAMP(new_mustache_scale, 0, MAX_MUSTACHE_SCALE)) << 6;
    mustache_beard &= ~MUSTACHE_SCALE_FIELD;
    mustache_beard |= val;
}

int MiiDataResource::get_mustache_scale(){
    return ((mustache_beard & MUSTACHE_SCALE_FIELD) >> 6);
}

void MiiDataResource::set_mustache_y_position(int new_mustache_y_position){
    uint16_t val = (CLAMP(new_mustache_y_position, 0, MAX_MUSTACHE_Y_POSITION)) << 10;
    mustache_beard &= ~MUSTACHE_Y_POS_FIELD;
    mustache_beard |= val;
}

int MiiDataResource::get_mustache_y_position(){
    return ((mustache_beard & MUSTACHE_Y_POS_FIELD) >> 10);
}


//Glasses
#define GLASSES_STYLE_FIELD 0b0000'0000'0000'1111
#define GLASSES_COLOR_FIELD 0b0000'0000'0111'0000
#define GLASSES_SCALE_FIELD 0b0000'0111'1000'0000
#define GLASSES_Y_POS_FIELD 0b1111'1000'0000'0000

void MiiDataResource::set_glasses_style(int new_glasses_style){
    uint16_t val = CLAMP(new_glasses_style, 0, MAX_GLASSES_STYLE);
    glass &= ~GLASSES_STYLE_FIELD;
    glass |= val;
}

int MiiDataResource::get_glasses_style(){
    return (glass & GLASSES_STYLE_FIELD);
}

void MiiDataResource::set_glasses_color_value(int new_glasses_color){
    uint16_t val = (CLAMP(new_glasses_color, 0, MAX_GLASSES_COLOR)) << 4;
    glass &= ~GLASSES_COLOR_FIELD;
    glass |= val;
}

int MiiDataResource::get_glasses_color_value(){
    return ((glass & GLASSES_COLOR_FIELD) >> 4);
}

void MiiDataResource::set_glasses_scale(int new_glasses_scale){
    uint16_t val = (CLAMP(new_glasses_scale, 0, MAX_GLASSES_SCALE)) << 7;
    glass &= ~GLASSES_SCALE_FIELD;
    glass |= val;
}

int MiiDataResource::get_glasses_scale(){
    return ((glass & GLASSES_SCALE_FIELD) >> 7);
}

void MiiDataResource::set_glasses_y_position(int new_glasses_y_position){
    uint16_t val = (CLAMP(new_glasses_y_position, 0, MAX_GLASSES_Y_POSITION)) << 11;
    glass &= ~GLASSES_Y_POS_FIELD;
    glass |= val;
}

int MiiDataResource::get_glasses_y_position(){
    return ((glass & GLASSES_Y_POS_FIELD) >> 11);
}


//Mole
#define HAS_MOLE_FIELD 0b0000'0000'0000'0001
#define MOLE_SCALE_FIELD 0b0000'0000'0001'1110
#define MOLE_X_POS_FIELD 0b0000'0011'1110'0000
#define MOLE_Y_POS_FIELD 0b0111'1100'0000'0000

void MiiDataResource::set_has_mole(bool has_mole){
    has_mole ? mole |= HAS_MOLE_FIELD : mole &= ~HAS_MOLE_FIELD;
}

bool MiiDataResource::get_has_mole(){
    return (mole & HAS_MOLE_FIELD);
}

void MiiDataResource::set_mole_scale(int new_mole_scale){
    uint16_t val = (CLAMP(new_mole_scale, 0, 8)) << 1;
    mole &= ~MOLE_SCALE_FIELD;
    mole |= val;
}

int MiiDataResource::get_mole_scale(){
    return ((mole & MOLE_SCALE_FIELD) >> 1);
}

void MiiDataResource::set_mole_x_position(int new_mole_x_pos){
    uint16_t val = (CLAMP(new_mole_x_pos, 0, 16)) << 5;
    mole &= ~MOLE_X_POS_FIELD;
    mole |= val;
}

int MiiDataResource::get_mole_x_position(){
    return ((mole & MOLE_X_POS_FIELD) >> 5);
}

void MiiDataResource::set_mole_y_position(int new_mole_y_pos){
    uint16_t val = (CLAMP(new_mole_y_pos, 0, 30)) << 10;
    mole &= ~MOLE_Y_POS_FIELD;
    mole |= val;
}

int MiiDataResource::get_mole_y_position(){
    return ((mole & MOLE_Y_POS_FIELD) >> 10);
}
