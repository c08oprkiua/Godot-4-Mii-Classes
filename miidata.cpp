//C++ port of Mii.gd

#include "miidata.h"
#include "core/variant/typed_array.h"

MiiDataResource::MiiDataResource(){}
MiiDataResource::~MiiDataResource(){}

void MiiDataResource::LoadFromBuffer(PackedByteArray buffer){
    uint32_t tempint;
    u_int8_t add1;
    u_int8_t add2;
    //0x0
    version = buffer.get(0);
    //0x1
    tempint = buffer.get(1);
    profanity = (tempint & 2);
    region_lock = (RegLockType)((tempint >> 2) & 3);
    char_set = (CharSetType)((tempint  >> 4) & 3);
    //0x2

    //0x3
    tempint = buffer.get(3);
    origin_device = (Devices)((tempint >> 4) & 7);

	//0x18
    add1 = buffer.get(26);
    add2 = buffer.get(27);
    tempint = ((add1 << 8) | add2);
	//mii_name = buffer.slice(26,46).get_string_from_utf16();
	//0x2E
	body_height = buffer.get(46);
	//0x2F
	body_width = buffer.get(47);
	//0x30
	tempint = buffer.get(48);
	sharable = (tempint & 1);
	face_shape = ((tempint >> 1) & 15);
	//face_line_color = (tempint & 96) >> 5;
	//0x31
	tempint = buffer.get(31);
	//face_line = (tempint & 15);
	makeup = ((tempint >> 4) & 15);
	//0x32
	hair_style = buffer.get(50);
	//0x33
	tempint = buffer.get(51);
	hair_color = (tempint & 3);
	hair_flip = (tempint & 4);
	//0x34
	tempint = buffer.get(52);
	eye_style = (tempint & 63);
	eye_color = ((tempint >> 6) & 7);
	eye_x_scale = ((tempint >> 9) & 15);
	eye_y_scale = ((tempint >> 13) & 7);
	//0x36
	tempint = buffer.get(54);
	eye_rotation = (tempint & 31);
	eye_x_spacing = ((tempint >> 5) & 15);
	eye_y_position = ((tempint >> 9) & 31);
	//0x38
	tempint = buffer.get(56);
	eyebrow_style = (tempint & 31);
	eyebrow_color = ((tempint >> 5) & 7);
	//0x39
	tempint = buffer.get(57);
	eyebrow_x_scale = (tempint & 15);
	eyebrow_y_scale = ((tempint >> 4) & 7);
	//0x3A
    add1 = buffer.get(58);
    add2 = buffer.get(59);
    tempint = ((add1 << 8) | add2);
	eyebrow_rotation = (tempint & 31);
	eyebrow_x_spacing = ((tempint >> 5) & 15);
	eyebrow_y_position = ((tempint >> 9) & 31);
	//0x3C
    add1 = buffer.get(60);
    add2 = buffer.get(61);
    tempint = ((add1 << 8) | add2);
	nose_style = (tempint & 31);
	nose_scale = ((tempint >> 5) & 15);
	nose_y_position = ((tempint >> 9) & 31);
	//0x3E
    add1 = buffer.get(62);
    add2 = buffer.get(63);
    tempint = ((add1 << 8) | add2);
	mouth_style = (tempint & 63);
	mouth_color = ((tempint >> 6) & 7);
	mouth_x_scale = ((tempint >> 9) & 15);
	mouth_y_scale = ((tempint >> 13) & 7);
	//0x40
    tempint = buffer.get(64);
	mouth_y_position = (tempint & 31);
	mustache_style = ((tempint >> 5) & 7);
	//0x41 is unused
	//0x42
    add1 = buffer.get(66);
    add2 = buffer.get(67);
    tempint = ((add1 << 8) | add2);
	beard_style = (tempint & 3);
	beard_color = ((tempint >> 3) & 7);
	mustache_scale = ((tempint >> 6) & 15);
	mustache_y_position = ((tempint >> 10) & 31);
	//0x44
    add1 = buffer.get(68);
    add2 = buffer.get(69);
    tempint = ((add1 << 8) | add2);
	glasses_style = (tempint & 15);
	glasses_color = ((tempint >> 4) & 7);
	glasses_scale = ((tempint >> 7) & 15);
	glasses_y_position = ((tempint >> 11) & 31);
	//0x46
    add1 = buffer.get(70);
    add2 = buffer.get(71);
    tempint = ((add1 << 8) | add2);
    has_mole = (tempint & 1);
	mole_scale = ((tempint & 30) >> 1);
	mole_x_position = ((tempint >> 5) & 31);
	mole_y_position = ((tempint >> 10) & 31);

}

void MiiDataResource::WriteToBuffer(){
    PackedByteArray expbin;
    expbin.append(version);
    //uint8_t tempbyte;



}

TypedArray<int> MiiDataResource::ByteToBinary(int byte){
    TypedArray<int> bytevalues;
    int bytesize;
    bytesize = 1;
    while (bytesize < byte){
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
