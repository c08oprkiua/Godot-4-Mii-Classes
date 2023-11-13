#include "miidata.h"


void MiiDataResource::_bind_methods(){
    ClassDB::bind_method(D_METHOD("LoadFromBuffer", "buffer"), &MiiDataResource::LoadFromBuffer);
    ClassDB::bind_method(D_METHOD("WriteToBuffer"), &MiiDataResource::WriteToBuffer);
    //Meta
    ClassDB::bind_method(D_METHOD("set_version", "new_version"), &MiiDataResource::set_version);
    ClassDB::bind_method(D_METHOD("get_version"), &MiiDataResource::get_version);
    ClassDB::bind_method(D_METHOD("set_profanity", "is_profane"), &MiiDataResource::set_profanity);
    ClassDB::bind_method(D_METHOD("get_profanity"), &MiiDataResource::get_profanity);
    ClassDB::bind_method(D_METHOD("set_region_lock", "locked_region"), &MiiDataResource::set_region_lock);
    ClassDB::bind_method(D_METHOD("get_region_lock"), &MiiDataResource::get_region_lock);
    ClassDB::bind_method(D_METHOD("set_char_set", "character_set_used"), &MiiDataResource::set_char_set);
    ClassDB::bind_method(D_METHOD("get_char_set"), &MiiDataResource::get_char_set);
    ClassDB::bind_method(D_METHOD("set_origin_device", "origin_device"), &MiiDataResource::set_origin_device);
    ClassDB::bind_method(D_METHOD("get_origin_device"), &MiiDataResource::get_origin_device);
    ClassDB::bind_method(D_METHOD("set_mii_id", "new_id"), &MiiDataResource::set_mii_id);
    ClassDB::bind_method(D_METHOD("get_mii_id"), &MiiDataResource::get_mii_id);
    ClassDB::bind_method(D_METHOD("set_creation_date", "creation_date"), &MiiDataResource::set_creation_date);
    ClassDB::bind_method(D_METHOD("get_creation_date"), &MiiDataResource::get_creation_date);
    ClassDB::bind_method(D_METHOD("set_dsi", "dsi"), &MiiDataResource::set_dsi);
    ClassDB::bind_method(D_METHOD("get_dsi"), &MiiDataResource::get_dsi);
    ClassDB::bind_method(D_METHOD("set_special", "special"), &MiiDataResource::set_special);
    ClassDB::bind_method(D_METHOD("get_special"), &MiiDataResource::get_special);
    ClassDB::bind_method(D_METHOD("set_mac_address", "mac_address"), &MiiDataResource::set_mac_address);
    ClassDB::bind_method(D_METHOD("get_mac_address"), &MiiDataResource::get_mac_address);
    //General
    ClassDB::bind_method(D_METHOD("set_sex", "sex"), &MiiDataResource::set_sex);
    ClassDB::bind_method(D_METHOD("get_sex"), &MiiDataResource::get_sex);
    ClassDB::bind_method(D_METHOD("set_birthday_month", "birthday_month"), &MiiDataResource::set_birthday_month);
    ClassDB::bind_method(D_METHOD("get_birthday_month"), &MiiDataResource::get_birthday_month);
    ClassDB::bind_method(D_METHOD("set_birthday_day", "birthday_day"), &MiiDataResource::set_birthday_day);
    ClassDB::bind_method(D_METHOD("get_birthday_day"), &MiiDataResource::get_birthday_day);
    ClassDB::bind_method(D_METHOD("set_favorite_color", "color"), &MiiDataResource::set_favorite_color);
    ClassDB::bind_method(D_METHOD("get_favorite_color"), &MiiDataResource::get_favorite_color);
    ClassDB::bind_method(D_METHOD("set_favorite_mii", "is__a_favorite"), &MiiDataResource::set_favorite_mii);
    ClassDB::bind_method(D_METHOD("get_favorite_mii"), &MiiDataResource::get_favorite_mii);
    ClassDB::bind_method(D_METHOD("set_mii_name", "new_name"), &MiiDataResource::set_mii_name);
    ClassDB::bind_method(D_METHOD("get_mii_name"), &MiiDataResource::get_mii_name);
    ClassDB::bind_method(D_METHOD("set_width", "width"), &MiiDataResource::set_width);
    ClassDB::bind_method(D_METHOD("get_width"), &MiiDataResource::get_width);
    ClassDB::bind_method(D_METHOD("set_height", "height"), &MiiDataResource::set_height);
    ClassDB::bind_method(D_METHOD("get_height"), &MiiDataResource::get_height);
    ClassDB::bind_method(D_METHOD("set_sharable", "is_sharable"), &MiiDataResource::set_sharable);
    ClassDB::bind_method(D_METHOD("get_sharable"), &MiiDataResource::get_sharable);
    ClassDB::bind_method(D_METHOD("set_author", "author"), &MiiDataResource::set_author);
    ClassDB::bind_method(D_METHOD("get_author"), &MiiDataResource::get_author);




    ADD_GROUP("Meta", "");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "version", PROPERTY_HINT_RANGE, "0,3"), "set_version", "get_version");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "profanity"), "set_profanity", "get_profanity");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "region_lock", PROPERTY_HINT_ENUM, "None, Japan, USA, Europe"), "set_region_lock", "get_region_lock");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "char_set", PROPERTY_HINT_ENUM, "Japan/USA/Europe, China, Korea, Taiwan"), "set_char_set", "get_char_set");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "origin_device", PROPERTY_HINT_ENUM, "Wii, DS, 3DS, Wii U/Switch"), "set_origin_device", "get_origin_device");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mii_id"), "get_mii_id", "get_mii_id");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "creation_date"), "set_creation_date", "get_creation_date");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "dsi"), "set_dsi", "get_dsi");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "special"), "set_special", "get_special");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "mac_address"), "set_mac_address", "get_mac_address");

    ADD_GROUP("General", "");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sex", PROPERTY_HINT_ENUM, "Male, Female"), "set_sex", "get_sex");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "birthday_month"), "set_birthday_month", "get_birthday_month");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "birthday_day"), "set_birthday_day", "get_birthday_day");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "favorite_color"), "set_favorite_color", "get_favorite_color");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "favorite_mii"), "set_favorite_mii", "get_favorite_mii");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "mii_name"), "set_mii_name", "get_mii_name");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "width"), "set_width", "get_width");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "sharable"), "set_sharable", "get_sharable");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "author"), "set_author", "get_author");


}

