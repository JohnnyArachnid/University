// Dynamicly rendering logged user with tickets
function renderAuthorized(user) {
    const contentContainer = document.querySelector('.div_content_container');
    const isPolish = get_language();
    if (contentContainer) {
        if (isPolish) {
            renderPolish();
            contentContainer.innerHTML = `
                <h2>Płatność kartą</h2>
                <form id="payment-form">
                    <div class="payment_form_input">
                        <label for="card-number">Numer karty</label>
                        <input type="text" id="card-number" value="${user.card_number}" readonly />
                    </div>
                    <div class="payment_form_input">
                        <label for="expiry-date">Data ważności</label>
                        <input type="text" id="expiry-date" value="${user.expiry_date}" readonly />
                    </div>
                    <div class="payment_form_input">
                        <label for="csv">CSV</label>
                        <input type="text" id="csv" value="${user.csv}" readonly />
                    </div>
                    <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" class="disabled" disabled>Zapłać: ${calculateTotalPrice()} zł</button>
                    <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Anuluj</button>
                </form>
            `;
        } else {
            renderEnglish();
            contentContainer.innerHTML = `
                <h2>Card payment</h2>
                <form id="payment-form">
                    <div class="payment_form_input">
                        <label for="card-number">Card number</label>
                        <input type="text" id="card-number" value="${user.card_number}" readonly />
                    </div>
                    <div class="payment_form_input">
                        <label for="expiry-date">Expiration date</label>
                        <input type="text" id="expiry-date" value="${user.expiry_date}" readonly />
                    </div>
                    <div class="payment_form_input">
                        <label for="csv">CSV</label>
                        <input type="text" id="csv" value="${user.csv}" readonly />
                    </div>
                    <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" class="disabled" disabled>Pay: ${calculateTotalPrice()} PLN</button>
                    <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Cancel</button>
                </form>
            `;
        }
        
        validateForm();

        const navigationButtons = document.querySelectorAll('[data-target]');

        if (navigationButtons) {
            navigationButtons.forEach(button => {
                button.addEventListener('click', handleNavigation);
            });
        }
    }
}

// Dynamicly rendering unlogged user with tickets
function renderUnauthorizedWithTickets() {
    const contentContainer = document.querySelector('.div_content_container');
    const isPolish = get_language();
    if (contentContainer) {
        if (isPolish) {
            renderPolish();
            contentContainer.innerHTML = `
                <h2>Płatność kartą</h2>
                <form id="payment-form">
                    <div class="payment_form_input">
                        <label for="card-number">Numer karty</label>
                        <input type="text" id="card-number" placeholder="Wpisz numer karty" />
                    </div>
                    <div class="payment_form_input">
                        <label for="expiry-date">Data ważności</label>
                        <input type="text" id="expiry-date" placeholder="MM/YY" />
                    </div>
                    <div class="payment_form_input">
                        <label for="csv">CSV</label>
                        <input type="text" id="csv" placeholder="Wpisz kod CSV" />
                    </div>
                    <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" class="disabled" disabled>Zapłać: ${calculateTotalPrice()} zł</button>
                    <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Anuluj</button>
                </form>
            `;    
        } else {
            renderEnglish();
            contentContainer.innerHTML = `
                <h2>Card payment</h2>
                <form id="payment-form">
                    <div class="payment_form_input">
                        <label for="card-number">Card number</label>
                        <input type="text" id="card-number" placeholder="Enter your card number" />
                    </div>
                    <div class="payment_form_input">
                        <label for="expiry-date">Expiration date</label>
                        <input type="text" id="expiry-date" placeholder="MM/YY" />
                    </div>
                    <div class="payment_form_input">
                        <label for="csv">CSV</label>
                        <input type="text" id="csv" placeholder="Enter CSV code" />
                    </div>
                    <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" class="disabled" disabled>Pay: ${calculateTotalPrice()} PLN</button>
                    <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Cancel</button>
                </form>
            `;        
        }

        const form = document.getElementById('payment-form');

        form.addEventListener('input', validateForm);

        const navigationButtons = document.querySelectorAll('[data-target]');

        if (navigationButtons) {
            navigationButtons.forEach(button => {
                button.addEventListener('click', handleNavigation);
            });
        }
    }
}

function validateForm() {
    const cardNumber = document.getElementById('card-number').value.trim();
    const expiryDate = document.getElementById('expiry-date').value.trim();
    const csv = document.getElementById('csv').value.trim();
    const payButton = document.getElementById('pay-button');

    const isCardValid = validateCardNumber(cardNumber);
    const isExpiryDateValid = validateExpiryDate(expiryDate);
    const isCsvValid = validateCsv(csv);
    
    if (isCardValid && isExpiryDateValid && isCsvValid) {
        payButton.disabled = false;
        payButton.classList.add('enabled');
        payButton.classList.remove('disabled');
    } else {
        payButton.disabled = true;
        payButton.classList.add('disabled');
        payButton.classList.remove('enabled');
    }
}

function validateCardNumber(cardNumber) {
    const digitsOnly = cardNumber.replace(/\s+/g, '');
    const cardPattern = /^\d{16}$/;
    return cardPattern.test(digitsOnly);
}

function validateExpiryDate(expiryDate) {
    const expiryPattern = /^(0[1-9]|1[0-2])\/\d{2}$/;
    if(expiryPattern.test(expiryDate)) {
        const [month, year] = expiryDate.split('/').map(value => parseInt(value, 10));
        const currentDate = new Date();
        const currentYear = currentDate.getFullYear() % 100;
        const currentMonth = currentDate.getMonth() + 1;

        if (year < currentYear || (year === currentYear && month < currentMonth)) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

function validateCsv(csv) {
    const csvPattern = /^\d{3}$/;
    return csvPattern.test(csv);
}

function calculateTotalPrice() {
    const currentBasket = getCurrentBasket();
    return currentBasket.reduce((total, ticket) => total + ticket.sum_price, 0);
}

// Add dynamicly loading content od the page
document.addEventListener('DOMContentLoaded', updateContentBacket);