pizza = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12    
}

for pie, price in  pizza.items():
    print(f"A whole {pie} pizza costs ${price}")
