//C++ port of Mii.gd

#include "miidata.h"
#include "core/variant/typed_array.h"

MiiDataResource::MiiDataResource(){}
MiiDataResource::~MiiDataResource(){}

void MiiDataResource::LoadFromBuffer(PackedByteArray buffer){
    TypedArray<int> binary;
    //0x0
    version = buffer.operator[](0);
    //0x1
    binary = ByteToBinary(buffer.operator[](1));
    profanity = BoolCheck(binary.operator[](0));
    region_lock = BinaryToInt(binary.slice(2,3,1,true));
    char_set = BinaryToInt(binary.slice(4,5,1,true));
    //0x3
    binary = ByteToBinary(buffer.operator[](3));
    origin_device = BinaryToInt(binary.slice(4,6,1,true));
}

void MiiDataResource::WriteToBuffer(){
}

TypedArray<int> MiiDataResource::ByteToBinary(int byte){
    TypedArray<int> bytevalues;
    int bytesize;
    bytesize = 1;
    while (bytesize < byte)
    {
        bytevalues.append(bytesize);
        bytesize = bytesize << 1;
    };
    TypedArray<int> binarr;
    bytevalues.reverse();
    int vals = 0;
    for (vals = 0; vals <= bytevalues.size(); vals++){
        if (byte >= vals){
            binarr.append(1);
            byte = byte-vals;
        }
        else {
            binarr.append(0);
        };
    };
    return binarr;
}

int MiiDataResource::BinaryToInt(TypedArray<int> binary){
    binary.reverse();
    int bytesize = 1;
    int intval = 0;
    int vals = 0;
    for(vals = 0; vals <= binary.size(); vals++){
        if (BoolCheck(vals)){
            intval = intval + bytesize;
        }
        bytesize = bytesize << 1;
    }
    return intval;
}

bool MiiDataResource::BoolCheck(int check){
    if (check > 0){
        return true;
    }
    else {
        return false;
    }

}


//Oh boy, a million SetGets

void MiiDataResource::set_version(int ver){
    version = ver;
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

void MiiDataResource::set_favorite_mii(bool val){
    favorite_mii = val;
}

bool MiiDataResource::get_favorite_mii(){
    return favorite_mii;
}


void MiiDataResource::_bind_methods(){
    ClassDB::bind_method(D_METHOD("LoadFromBuffer", "buffer"), &MiiDataResource::LoadFromBuffer);
    ClassDB::bind_method(D_METHOD("WriteToBuffer"), &MiiDataResource::WriteToBuffer);
    
    ADD_GROUP("Meta", "");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "version"), "set_version", "get_version");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "profanity"), "set_profanity", "get_profanity");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "region_lock", PROPERTY_HINT_ENUM, "None, Japan, USA, Europe"), "set_region_lock", "get_region_lock");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "char_set", PROPERTY_HINT_ENUM, "Japan/USA/Europe, China, Korea, Taiwan"), "set_char_set", "get_char_set");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "origin_device", PROPERTY_HINT_ENUM, "Wii, DS, 3DS, Wii U/Switch"), "set_origin_device", "get_origin_device");
    
    ADD_GROUP("General", "");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "favorite_mii"), "set_favorite_mii", "get_favorite_mii");
}

