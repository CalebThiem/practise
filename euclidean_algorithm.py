user_input = input("GCD(")

numerator = int(user_input.split(",")[0])
denomenator = int(user_input.split(",")[1][1:-1])

remainder = numerator % denomenator

while remainder != 0:

    numerator = denomenator

    denomenator = remainder 

    remainder = numerator % denomenator

print(denomenator)
