while True:
    cents = float(input("Change owed: "))
    if cents > 0:
        break

cents = round(cents * 100)
quarters = cents // 25
rest_quarters = cents % 25
dimes = rest_quarters // 10
rest_dimes = rest_quarters % 10
nickels = rest_dimes // 5
pennies = rest_dimes % 5

coins = quarters + dimes + nickels + pennies

print(f'{coins}')