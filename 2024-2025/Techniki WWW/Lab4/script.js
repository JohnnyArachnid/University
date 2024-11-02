function zmiana_tla(color){
    document.body.style.background = color;
}

class Prostokat {
    constructor(a,b) {
        this.a = a;
        this.b = b;
    }
    pole() {
        return this.a * this.b;
    }
    przekatna() {
        return Math.sqrt(this.a**2 + this.b**2);
    }
}

function wielokrotnosci_3_i_5_do_1000() {
    let suma = 0
    for(i=1; i<1000; i++) {
       if(i % 3 === 0) {
            suma += i;
       }
       else if(i % 5 === 0 && i % 3 !== 0) {
            suma += i;
       }
    }
    return suma;
}

function fibo(dane) {
    if (dane === 0) return 0;
    if (dane === 1) return 1;
    
    let a = 0, b = 1, c;
    for (let i = 2; i <= dane; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

function fibo_parzyste() {
    let suma = 0
    
    let a = 0, b = 1, c;
    for (let i = 2; i <= 10000000; i++) {
        if (i % 2 === 0) suma += i;
        c = a + b;
        a = b;
        b = c;
    }
    return suma;
}

function sprawdzenie_hasla_liczby(value, dlugosc) {
    let licznik = 0
    for(i=0;i<dlugosc;i++) {
        if (isNaN(value[i]) === true) licznik+=1
    }
    return licznik !== 0 || licznik !== dlugosc
}


function sprawdzenie_hasla() {
    let value = document.getElementById("password").value;
    let dlugosc = value.length <= 6 ? false : true;
    let liczby = dlugosc > 9 ? true : sprawdzenie_hasla_liczby(value, dlugosc);
    let password = !value.includes("password");
    let temp = new Set(value).size
    let znaki = temp <= 3 ? false : true;
    alert(dlugosc && liczby && password && znaki)
}


dane = prompt("Podaj wartosc do fibo: ");
prostokat = new Prostokat(3,4);
console.log(prostokat.pole(), prostokat.przekatna());
console.log(wielokrotnosci_3_i_5_do_1000());
console.log(fibo(dane));
console.log(fibo_parzyste())