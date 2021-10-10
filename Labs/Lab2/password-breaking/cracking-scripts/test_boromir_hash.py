from hashlib import sha256

HASH = '926ddc2e7b1d09e43bda9eeec25356498e721c762356797550454c37862b212d'
PASSWORD = 'one does not simply walk into mordor'


def main():
    h = sha256(PASSWORD.encode()).hexdigest()
    print(f'"{PASSWORD}"' + ' iz ok' if h == HASH else ' iz not ok')


if __name__ == '__main__':
    exit(main())
