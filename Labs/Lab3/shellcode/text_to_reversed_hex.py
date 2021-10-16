TEXT = b"manelele ie vtm!\n"

for i in range(0, len(TEXT), 4):
	print('0x' + TEXT[i:i+4][::-1].hex())

