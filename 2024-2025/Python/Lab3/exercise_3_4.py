print("Witaj w programie wypisującym podaną przez użytkownika liczbę x oraz jej trzecią potęgę!")
print("W celu przerwania działania programu podaj jako wartość input: 'stop', wówczas program się zakończy.")
while True:
    try:
        x = input("Podaj wartość x: ")
        if x.lower() == 'stop':
            break
        else:
            x = float(x)
            print("Podana wartość x: {:.3f}".format(x))
            print("Trzecia potęga podanej wartości x: {:.3f}".format(pow(x, 3)))
    except ValueError as e:
        print("Podano zły format danych, komunikat o błędzie: {}".format(e))
    except Exception as e:
        print("Wystąpił błąd: {}".format(e))
