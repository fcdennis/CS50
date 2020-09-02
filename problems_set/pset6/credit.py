def main():
    while True:
        number = int(input("Number: "))
        if number <= 0:
            break
    
    is_valid = valid(number)

    if (is_valid % 10 == 0):
        card_brand = brand(number)
        print(card_brand)
    else:
        print("INVALID")


def valid(number):
    particial1 = parcial2 = result1 = result2 = remainder = 0

    while True:
        parcial2 += (number % 10)
        result1 = number / 10
        result2 = result1 / 10
        remainder = 2 * (result1 % 10)

        if (remainder < 10):
            particial1 += remainder
        else:
            particial1 += 1 + (remainder - 10)
        number = result2

        if (number > 0):
            break

        return particial1 + parcial2


def brand(number):
    first_numbers = number
    total_number = 1

    for c in range(number, 100):
        first_numbers /= 10
        total_number += 1
    
    if (51 <= first_numbers <= 55 ):
        return 'MASTERCARD'
    elif (first_numbers == 34 or first_numbers == 37):
        return 'AMEX'
    elif (first_numbers / 10 == 4 and total_number + 1 == 13 or first_numbers / 4 == 10 and total_number + 1 == 16) :
        return 'Visa'
    else:
        return 'INVALID'


main()