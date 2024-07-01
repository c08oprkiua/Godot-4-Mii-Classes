#include "miidata.hpp"

void MiiDataResource::LoadFromBuffer(PackedByteArray buffer){
	uint8_t check_version = buffer.get(0);

	switch (check_version){
		case DEVICE_WII:
			_from_wii_data(buffer);
			break;
		case DEVICE_DS:
			_from_ds_data(buffer);
			break;
		case DEVICE_THREEDS:
			_from_3ds_data(buffer);
			break;
		case DEVICE_WII_U_SWITCH:
			_from_wiiu_data(buffer);
			break;
	}
}

PackedByteArray MiiDataResource::WriteToBuffer(Devices target_output){
    switch (target_output){
		case DEVICE_WII:
			return _to_wii_data();
		case DEVICE_DS:
			return _to_ds_data();
		case DEVICE_THREEDS:
			return _to_3ds_data();
		case DEVICE_WII_U_SWITCH:
			return _to_wiiu_data();
	}
}

Color MiiDataResource::get_favorite_color(){
	switch (get_favorite_color_value()){
		case COLOR_RED:
			return Color(0.824f, 0.118f, 0.078f);
		case COLOR_ORANGE:
			return Color(1.000f, 0.431f, 0.098f);
		case COLOR_YELLOW:
			return Color(1.000f, 0.847f, 0.125f);
		case COLOR_LIGHT_GREEN:
			return Color(0.471f, 0.824f, 0.125f);
        case COLOR_DARK_GREEN:
			return Color(0.000f, 0.471f, 0.188f);
        case COLOR_BLUE:
			return Color(0.039f, 0.282f, 0.706f);
        case COLOR_LIGHT_BLUE:
			return Color(0.235f, 0.667f, 0.871f);
        case COLOR_PINK:
			return Color(0.961f, 0.353f, 0.490f);
        case COLOR_PURPLE:
			return Color(0.451f, 0.157f, 0.678f);
        case COLOR_BROWN:
			return Color(0.282f, 0.220f, 0.094f);
        case COLOR_WHITE:
			return Color(0.878f, 0.878f, 0.878f);
        case COLOR_BLACK:
			return Color(0.094f, 0.094f, 0.078f);
	}
}
