extends Resource
class_name MiiDataResource

@export_group("Meta")
@export var version: int
@export var profanity: bool
@export_enum("No lock", "JPN", "USA", "EUR") var region_lock: int
@export_enum("JPN+USA+EUR", "CHN", "KOR", "TWN") var character_set: int

@export_enum("null", "Wii", "DS", "3DS", "Wii U/Switch") var origin_device: int
@export var mii_id: int #U32
@export var creation_date: int
@export var unknown: bool
@export var temporary: bool
@export var dsi: bool
@export var special: bool
@export var mac_address: String
@export var creator_id: String #From FFLiCharInfo
@export var author_id: String #From FFLiCharInfo

@export_group("General")
@export_enum("Male", "Female") var sex: int
@export var birthday_month: int
@export var birthday_day: int
@export_range(0, 12) var favorite_color: int
@export var favorite_mii: bool
@export var mii_name: String 
@export var author_name: String
@export var body_width: int
@export var body_height: int
@export var sharable: bool

@export_group("Face Misc.")
@export_range(0, 12) var face_shape: int
@export var skin_color: int
@export_range(0, 12) var face_line: int #from FFLiCharInfo
@export_range(0, 6) var face_line_color: int #from FFLiCharInfo
@export var wrinkles: int
@export var makeup: int

@export_group("Hair")
@export_range(0, 132) var hair_style: int
@export_range(0, 8) var hair_color: int
@export var hair_flip: int #bool?

@export_group("Eyes")
@export_range(0, 60) var eye_style: int
@export_range(0, 6) var eye_color: int
@export_range(0, 8) var eye_scale: int
@export_range(0, 7) var eye_y_scale: int
@export_range(0, 8) var eye_rotation: int
@export_range(0, 13) var eye_x_spacing: int
@export_range(0, 19) var eye_y_position: int

@export_group("Eyebrows")
@export_range(0, 31) var eyebrow_style: int
@export_range(0, 8) var eyebrow_color: int
@export_range(0, 9) var eyebrow_scale: int
@export_range(0, 7) var eyebrow_y_scale: int
@export_range(0, 12) var eyebrow_rotation: int
@export_range(0, 13) var eyebrow_x_spacing: int
@export_range(3,19) var eyebrow_y_position: int

@export_group("Nose")
@export_range(0, 18) var nose_style: int
@export_range(0, 9) var nose_scale: int
@export_range(0, 19) var nose_y_position: int

@export_group("Mouth")
@export_range(0, 36) var mouth_style: int
@export_range(0, 5) var mouth_color: int
@export_range(0, 9) var mouth_x_scale:int
@export_range(0, 7) var mouth_y_scale: int
@export_range(0, 7) var mouth_y_position: int

@export_group("Facial Hair")
@export_range(0, 6) var beard_style: int
@export_range(0, 8) var beard_color: int
@export_range(0, 6) var mustache_style: int
@export_range(0, 9) var mustache_scale: int
@export_range(0, 17) var mustache_y_position: int

@export_group("Glasses")
@export_range(0, 9) var glasses_style: int
@export_range(0, 6) var glasses_color: int
@export_range(0, 8) var glasses_scale: int
@export_range(0, 21) var glasses_y_position: int

@export_group("Mole")
@export var mole_enabled: bool
@export_range(0, 9) var mole_scale: int
@export_range(0, 17) var mole_x_position: int
@export_range(0, 31) var mole_y_position: int

#Essentially a full code implementation of https://www.3dbrew.org/wiki/Mii#Mii_format
func LoadFromBuffer(buffer:PackedByteArray):
	var tempint: int
	#0x00
	version = buffer.decode_u8(0)
	#0x01
	tempint = buffer.decode_u8(1)
	var copyable:bool = tempint & 1
	profanity = tempint & 2
	region_lock = (tempint & 12) >> 2
	character_set = (tempint & 48) >> 4
	#0x03
	tempint = buffer.decode_u8(2)
	var pageindex: int = (tempint & 15)
	var slotindex: int = (tempint & 240) >> 4
	#0x04
	tempint = buffer.decode_u8(3)
	var _0_24_27: int = (tempint & 15)
	origin_device = (tempint & 112) >> 4
	#0x05
	mii_id = buffer.decode_u32(4)
	
	
	#0x18
	tempint = buffer.decode_u16(24)
	sex = (tempint & 1)
	birthday_month = (tempint & 30) >> 1
	birthday_day = (tempint & 480) >> 5
	favorite_color = (tempint & 15360) >> 10
	favorite_mii = (tempint & 16384) >> 14
	var empty: int = (tempint & 32768) >> 15
	
	#0x18
	tempint = buffer.decode_u16(26)
	mii_name = buffer.slice(26,46).get_string_from_utf16()
	#0x2E
	body_height = buffer.decode_u8(46)
	#0x2F
	body_width = buffer.decode_u8(47)
	#0x30
	tempint = buffer.decode_u8(48)
	sharable = (tempint & 1)
	face_shape = (tempint & 14) >> 1
	face_line_color = (tempint & 96) >> 5
	#0x31
	tempint = buffer.decode_u8(31)
	face_line = (tempint & 15)
	makeup = (tempint & 240) >> 4
	#0x32
	hair_style = buffer.decode_u8(50)
	#0x33
	tempint = buffer.decode_u8(51)
	hair_color = (tempint & 3)
	hair_flip = (tempint & 4)
	#0x34
	tempint = buffer.decode_u8(52)
	eye_style = (tempint & 63)
	eye_color = (tempint & 448) >> 6
	eye_scale = (tempint & 7860) >> 9
	eye_y_scale = (tempint & 57344) >> 13
	#0x36
	tempint = buffer.decode_u8(54)
	eye_rotation = (tempint & 31)
	eye_x_spacing = (tempint & 480) >> 5
	eye_y_position = (tempint & 15872) >> 9
	#0x38
	tempint = buffer.decode_u8(56)
	eyebrow_style = (tempint & 31)
	eyebrow_color = (tempint & 224) >> 5
	#0x39
	tempint = buffer.decode_u8(57)
	eyebrow_scale = (tempint & 15)
	eyebrow_y_scale = (tempint & 112) >> 4
	#0x3A
	tempint = buffer.decode_u16(58)
	eyebrow_rotation = (tempint & 31)
	eyebrow_x_spacing = (tempint & 480) >> 5
	eyebrow_y_position = (tempint & 15872) >> 9
	#0x3C
	tempint = buffer.decode_u16(60)
	nose_style = (tempint & 31)
	nose_scale = (tempint & 480) >> 5
	nose_y_position = (tempint & 15872) >> 9
	#0x3E
	tempint = buffer.decode_u16(62)
	mouth_style = (tempint & 63)
	mouth_color = (tempint & 448) >> 6
	mouth_x_scale = (tempint & 7680) >> 9
	mouth_y_scale = (tempint & 57344) >> 13
	#0x40
	tempint = buffer.decode_u8(64)
	mouth_y_position = (tempint & 31)
	mustache_style = (tempint & 224) >> 5
	#0x41 is unused
	#0x42
	tempint = buffer.decode_u16(66)
	beard_style = (tempint & 3)
	beard_color = (tempint & 56) >> 3
	mustache_scale = (tempint & 960) >> 6
	mustache_y_position = (tempint & 31744) >> 10
	#0x44
	tempint = buffer.decode_u16(68)
	glasses_style = (tempint & 15)
	glasses_color = (tempint & 120) >> 4
	glasses_scale = (tempint & 1920) >> 7
	glasses_y_position = (tempint & 63488) >>11
	#0x46
	tempint = buffer.decode_u16(70)
	mole_enabled = (tempint & 1)
	mole_scale = (tempint & 30) >> 1
	mole_x_position = (tempint & 992) >> 5
	mole_y_position = (tempint &31744) >> 10

func WriteToBuffer(filepath: String):
	var exportbytes: PackedByteArray
	var tempint: int
	exportbytes.encode_u8(0, version)
