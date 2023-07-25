def dec_to_bin(decimal):
    if(decimal == 0):
        return '0'
    remainder_array = []
    string = ''
    while(decimal != 1):
        current_remainder = decimal % 2
        decimal = decimal // 2

        remainder_array.append(current_remainder)

    
    remainder_array.append(decimal)

    remainder_array.reverse()
    # print(remainder_array)

    for elmt in remainder_array:
        string = string + str(elmt)


   


    return string


print(dec_to_bin(45))
print(dec_to_bin(64))
print(dec_to_bin(264))
print(dec_to_bin(63))
print(dec_to_bin(0))