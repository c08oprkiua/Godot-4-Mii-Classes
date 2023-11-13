#include "miidata.h"

//Oh boy, a million SetGets

//General

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

void MiiDataResource::set_origin_device(int val){
    origin_device = val;
}

int MiiDataResource::get_origin_device(){
    return origin_device;
}

void MiiDataResource::set_mii_id(int new_id){
    mii_id = new_id;
}

int MiiDataResource::get_mii_id(){
    return mii_id;
}

void MiiDataResource::set_creation_date(int date){
    creation_date = date;
}

int MiiDataResource::get_creation_date(){
    return creation_date;
}

void MiiDataResource::set_dsi(bool is_dsi){
    dsi = is_dsi;
}

bool MiiDataResource::get_dsi(){
    return dsi;
}

void MiiDataResource::set_special(bool is_special){
    special = is_special;
}

bool MiiDataResource::get_special(){
    return special;
}

void MiiDataResource::set_mac_address(String new_mac){
    mac_address = new_mac;
}

String MiiDataResource::get_mac_address(){
    return mac_address;
}

//General

void MiiDataResource::set_sex(int wtfcppsex){
    sex = wtfcppsex;
}
int MiiDataResource::get_sex(){
    return sex;
}

void MiiDataResource::set_birthday_month(int bdaymonth){
    birthday_month = bdaymonth;
}
int MiiDataResource::get_birthday_month(){
    return birthday_month;
}

void MiiDataResource::set_birthday_day(int bdayday){
    birthday_day = bdayday;
}
int MiiDataResource::get_birthday_day(){
    return birthday_day;
}

void MiiDataResource::set_favorite_color(int color){
    favorite_color = color;
}
int MiiDataResource::get_favorite_color(){
    return favorite_color;
}

void MiiDataResource::set_favorite_mii(bool val){
    favorite_mii = val;
}

bool MiiDataResource::get_favorite_mii(){
    return favorite_mii;
}

void MiiDataResource::set_mii_name(String new_name){
    mii_name = new_name;
}
String MiiDataResource::get_mii_name(){
    return mii_name;
}

void MiiDataResource::set_width(float wideness){
    width = wideness;
}

float MiiDataResource::get_width(){
    return width;
}

void MiiDataResource::set_height(float heightness){
    height = heightness;
}

float MiiDataResource::get_height(){
    return height;
}

void MiiDataResource::set_sharable(bool is_sharable){
    sharable = is_sharable;
}

bool MiiDataResource::get_sharable(){
    return sharable;
}

void MiiDataResource::set_author(String new_author){
    author = new_author;
}

String MiiDataResource::get_author(){
    return author;
}

//Face Misc.