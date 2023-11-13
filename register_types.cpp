
#include "register_types.h"

#include "core/object/class_db.h"
#include "miidata.h"

void initialize_mii_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
	ClassDB::register_class<MiiDataResource>();
}

void uninitialize_mii_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
}