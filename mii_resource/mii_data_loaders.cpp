#include "miidata.hpp"

//Because I implemented validity checks in all the set functions, 
//I just feed the values into themselves to sort of "filter" bad results

void MiiDataResource::_from_wii_data(PackedByteArray buffer){

}


void MiiDataResource::_from_ds_data(PackedByteArray buffer){

}

void MiiDataResource::_from_3ds_data(PackedByteArray buffer){

}

void MiiDataResource::_from_wiiu_data(PackedByteArray buffer){
    uint32_t add1;
    uint32_t add2;
    meta.version = buffer.get(0x00);

    meta.restrictions = buffer.get(0x01);
	set_profanity(get_profanity());
	set_region_lock(get_region_lock());
    set_char_set(get_char_set());
    
    meta.page_slot_index = buffer.get(0x02);

    meta.unk_birth_platform = buffer.get(0x03);
	set_origin_device(get_origin_device());
    //0x04

    //authorid

    //creatorid

    //two bytes of padding

    add1 = buffer.get(0x18);
    add2 = buffer.get(0x19);
    personal_info = ((add1 << 8) | add2);
	set_gender(get_gender());
	set_birthday_month(get_birthday_month());
	set_birthday_day(get_birthday_day());
	set_favorite_color_value(get_favorite_color_value());
	set_favorite_mii(get_favorite_mii());

	//mii_name = buffer.slice(26,46).get_string_from_utf16();
	
	body.height = buffer.get(0x2E);
	
	body.width = buffer.get(0x2F);
	
	face.type_line_color = buffer.get(0x30);
	set_sharable(get_sharable());
	set_face_shape(get_face_shape());
	
	//face_line_color = (face.type_line_color & 0b0110'0000) >> 5;

	face.line_makeup = buffer.get(0x31);
	//face_line = (face.line_makeup & 0b0000'1111);
	//makeup = ((face.line_makeup & 0b1111'0000) >> 4);
	
	hair.type = buffer.get(0x32);
	
	hair.color_direction = buffer.get(0x33);
	set_hair_color_value(get_hair_color_value());
	set_hair_flip(get_hair_flip());
	

    add1 = buffer.get(0x34);
    add2 = buffer.get(0x35);
	eyes.type_color_scale = ((add1 << 8) | add2);
	set_eye_style(get_eye_style());
	set_eye_color_value(get_eye_color_value());
	set_eye_x_scale(get_eye_x_scale());
	set_eye_y_scale(get_eye_y_scale());
	
    add1 = buffer.get(0x36);
    add2 = buffer.get(0x37);
    eyes.rotate_spacing_pos = ((add1 << 8) | add2);
	set_eye_rotation(get_eye_rotation());
	set_eye_x_spacing(get_eye_x_spacing());
	set_eye_y_position(get_eye_y_position());
	
	eyebrows.type_color = buffer.get(0x38);
	set_eyebrow_style(get_eyebrow_style());
	set_eyebrow_color_value(get_eyebrow_color_value());
	
	eyebrows.scale = buffer.get(0x39);
	set_eyebrow_x_scale(get_eyebrow_x_scale());
	set_eyebrow_y_scale(get_eyebrow_y_scale());

    add1 = buffer.get(0x3A);
    add2 = buffer.get(0x3B);
    eyebrows.rotation_positioning = ((add1 << 8) | add2);
	set_eyebrow_rotation(get_eyebrow_rotation());
	set_eyebrow_x_spacing(get_eyebrow_x_spacing());
	set_eyebrow_y_position(get_eyebrow_y_position());
	
    add1 = buffer.get(0x3C);
    add2 = buffer.get(0x3D);
    nose = ((add1 << 8) | add2);
	set_nose_style(get_nose_style());
	set_nose_scale(get_nose_scale());
	set_nose_y_position(get_nose_y_position());

    add1 = buffer.get(0x3E);
    add2 = buffer.get(0x3F);
    mouth = ((add1 << 8) | add2);
	set_mouth_style(get_mouth_style());
	set_mouth_color_value(get_mouth_color_value());
	set_mouth_x_scale(get_mouth_x_scale());
	set_mouth_y_scale(get_mouth_y_scale());
	
    mouth_mustache = buffer.get(0x40);
	set_mouth_y_position(get_mouth_y_position());
	set_mustache_style(get_mustache_style());
	//0x41 is unused
	
    add1 = buffer.get(0x42);
    add2 = buffer.get(0x43);
    mustache_beard = ((add1 << 8) | add2);
	set_beard_style(get_beard_style());
	set_beard_color_value(get_beard_color_value());
	set_mustache_scale(get_mustache_scale());
	set_mustache_y_position(get_mustache_y_position());
	
    add1 = buffer.get(0x44);
    add2 = buffer.get(0x45);
    glass = ((add1 << 8) | add2);
	set_glasses_style(get_glasses_style());
	set_glasses_color_value(get_glasses_color_value());
	set_glasses_scale(get_glasses_scale());
	set_glasses_y_position(get_glasses_y_position());
	
    add1 = buffer.get(0x46);
    add2 = buffer.get(0x47);
    mole = ((add1 << 8) | add2);
	set_has_mole(get_has_mole());
	set_mole_scale(get_mole_scale());
	set_mole_x_position(get_mole_x_position());
	set_mole_y_position(get_mole_y_position());
}