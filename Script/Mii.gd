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
@export var body_width: int
@export var body_height: int
@export var sharable: bool
@export var author: String

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
	version = buffer.decode_u8(0)
	#0x1
	var binary: Array[int]
	binary = ByteToBinary(buffer[1])
	profanity = bool(binary[0])
	region_lock = BinaryToInt(binary.slice(2,3,1,true))
	character_set = BinaryToInt(binary.slice(4,5,1,true))
	#0x3
	binary = ByteToBinary(buffer[3])
	origin_device = BinaryToInt(binary.slice(4,6,1,true))
	#0x4
	
	#0xC
	mii_id = buffer.decode_u32(13)
	binary = ByteToBinary(mii_id)
	creation_date = BinaryToInt(binary.slice(0,27,1,true))
	temporary = bool(binary[29])
	dsi = bool(binary[30])
	special = bool(binary[31])
	#0x10
	
	#0x18
	binary = ByteToBinary(buffer.decode_u16(24))
	sex = bool(binary[0])
	birthday_month = BinaryToInt(binary.slice(1,4,1,true))
	birthday_day = BinaryToInt(binary.slice(5,9,1,true))
	favorite_color = BinaryToInt(binary.slice(10,13,1,true))
	favorite_mii = bool(binary[14])
	#0x1A
	mii_name = buffer.slice(26, 45).get_string_from_utf16()
	#0x2E
	#insert height/width here
	#0x30
	binary = ByteToBinary(buffer[48])
	sharable = bool(binary[0])
	face_shape = BinaryToInt(binary.slice(1,4,1,true))
	skin_color = BinaryToInt(binary.slice(5,7,1,true))
	#0x31
	binary = ByteToBinary(buffer[49])
	wrinkles = BinaryToInt(binary.slice(0,3,1,true))
	makeup = BinaryToInt(binary.slice(4,7,1,true))
	#0x32
	hair_style = buffer.decode_u8(50)
	#0x33
	binary = ByteToBinary(buffer[51])
	hair_color = BinaryToInt(binary.slice(0,2,1,true))
	hair_flip = bool(binary[3])
	#0x34
	binary = ByteToBinary(buffer.decode_u32(52))
	eye_style = BinaryToInt(binary.slice(0,5,1,true))
	eye_color = BinaryToInt(binary.slice(6,8,1,true))
	eye_scale = BinaryToInt(binary.slice(9,12,1,true))
	eye_y_scale = BinaryToInt(binary.slice(13,15,1,true))
	eye_rotation = BinaryToInt(binary.slice(16,20,1,true))
	eye_x_spacing = BinaryToInt(binary.slice(21,24,1,true))
	eye_y_position = BinaryToInt(binary.slice(25,29,1,true))
	#0x38
	binary = ByteToBinary(buffer.decode_u32(56))
	eyebrow_style = BinaryToInt(binary.slice(0,4,1,true))
	eyebrow_color = BinaryToInt(binary.slice(5,7,1,true))
	eyebrow_scale = BinaryToInt(binary.slice(8,11,1,true))
	eyebrow_y_scale = BinaryToInt(binary.slice(12,14,1,true))
	eyebrow_rotation = BinaryToInt(binary.slice(16,19,1,true)) #So what, we just skip 15??
	eyebrow_x_spacing = BinaryToInt(binary.slice(21,24,1,true))
	eyebrow_y_position = BinaryToInt(binary.slice(25,29,1,true))
	#0x3C
	binary = ByteToBinary(buffer.decode_u16(60))
	nose_style = BinaryToInt(binary.slice(0,4,1,true))
	nose_scale = BinaryToInt(binary.slice(5,8,1,true))
	nose_y_position = BinaryToInt(binary.slice(9,13,1,true))
	#0x3E
	binary = ByteToBinary(buffer.decode_u16(62))
	mouth_style = BinaryToInt(binary.slice(0,5,1,true))
	mouth_color = BinaryToInt(binary.slice(6,8,1,true))
	

func WriteToBuffer(filepath: String):
	pass

func ByteToBinary(byte: int):
	var bytevalues: Array[int]
	var bytesize: int = 1
	while bytesize < byte:
		bytevalues.append(bytesize)
		bytesize = bytesize + bytesize
	var binarr: Array[int]
	bytevalues.reverse()
	for vals in bytevalues:
		if byte >= vals:
			binarr.append(1)
			byte = byte-vals
		else:
			binarr.append(0)
	return binarr

func BinaryToInt(binary: Array):
	var returnedint: int
	binary.reverse()
	var bytesize: int = 1
	var intval: int
	for vals in binary:
		if bool(vals):
			intval = intval + bytesize
		bytesize = bytesize+bytesize
	return intval
