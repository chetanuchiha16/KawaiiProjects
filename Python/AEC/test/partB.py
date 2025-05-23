import random
import string

def generate_password(length=8):
    characters = string.ascii_letters + string.digits + string.punctuation
    return ''.join(random.choice(characters) for _ in range(length))

password_length = int(input("Enter password length: "))
print("Generated Password:", generate_password(password_length))
