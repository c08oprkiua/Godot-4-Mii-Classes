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
    //origin_device = BinaryToInt(binary.slice(4,6,1,true));

}

void MiiDataResource::WriteToBuffer(){
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
