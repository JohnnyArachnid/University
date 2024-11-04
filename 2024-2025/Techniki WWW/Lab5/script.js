let input = document.getElementById("input-text");
let submit = document.getElementById("submit");
let result = document.getElementById("result");

let listaObrazow = ['obraz1.jpg', 'obraz2.jpg', 'obraz3.jpg'];

const img1 = document.createElement('img');
img1.src = listaObrazow[0];
img1.alt = 'obraz1';
img1.style.width = '200px';
img1.style.height = '200px';

const img2 = document.createElement('img');
img2.src = listaObrazow[1];
img2.alt = 'obraz2';
img2.style.width = '200px';
img2.style.height = '200px';

const img3 = document.createElement('img');
img3.src = listaObrazow[2];
img3.alt = 'obraz3';
img3.style.width = '200px';
img3.style.height = '200px';

let id = 0;
const listaObrazowImg = [img1, img2, img3];

document.getElementById('zdjecie').appendChild(listaObrazowImg[id]);

function addTekst() {
    if (!input.value) {
        alert("Wartość input nie może być pusta");
        return;
    }

    let tekst = document.createElement("p");
    let button = document.createElement("button");
    button.textContent = "Usuń";
    button.addEventListener("click", function() {
        removeTekst(tekst);
    });

    let text = document.createTextNode(input.value);
    tekst.appendChild(text);
    tekst.appendChild(button);
    result.appendChild(tekst);
    input.value = "";
}

function removeTekst(element) {
    element.remove();
}

function changePhotoRight() {
    let newId = (id + 1) % listaObrazowImg.length;
    document.getElementById('zdjecie').replaceChild(listaObrazowImg[newId], listaObrazowImg[id]);
    id = newId;
}

function changePhotoLeft() {
    let newId = (id - 1 + listaObrazowImg.length) % listaObrazowImg.length;
    document.getElementById('zdjecie').replaceChild(listaObrazowImg[newId], listaObrazowImg[id]);
    id = newId;
}
