extends RefCounted
class_name BinConv

static func ByteToBinary(byte: int):
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
	print(binarr)
	return binarr as Array[int]

static func BinaryToInt(binary: Array):
	var returnedint: int
	binary.reverse()
	var bytesize: int = 1
	var intval: int
	for vals in binary:
		if bool(vals):
			intval = intval + bytesize
		bytesize = bytesize+bytesize
	return intval
