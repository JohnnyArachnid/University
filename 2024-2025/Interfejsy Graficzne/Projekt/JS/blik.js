// Dynamicly rendering logged user with tickets
function renderAuthorized(user) {
    const contentContainer = document.querySelector('.div_content_container');
    const isPolish = get_language();
    if (contentContainer) {
        if (isPolish) {
            renderPolish();
            contentContainer.innerHTML = `
            <h2>Płatność Blik</h2>
            <form id="payment-form">
                <div class="payment_form_input">
                    <label for="blik-number">Numer blik</label>
                    <input type="text" id="blik-number" value="" />
                </div>
                <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" disabled>Zapłać: ${calculateTotalPrice()} zł</button>
                <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Anuluj</button>
            </form>
            `;
        } else {
            renderEnglish();
            contentContainer.innerHTML = `
            <h2>Blik payment</h2>
            <form id="payment-form">
                <div class="payment_form_input">
                    <label for="blik-number">Blik number</label>
                    <input type="text" id="blik-number" value="" />
                </div>
                <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" disabled>Pay: ${calculateTotalPrice()} zł</button>
                <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Cancel</button>
            </form>
            `;
        }
        

        const form = document.getElementById('payment-form');

        form.addEventListener('input', function() {
            validateForm();
        });

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
            contentContainer.innerHTML = `
            <h2>Płatność Blik</h2>
            <form id="payment-form">
                <div class="payment_form_input">
                    <label for="blik-number">Numer blik</label>
                    <input type="text" id="blik-number" value="" />
                </div>
                <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" disabled>Zapłać: ${calculateTotalPrice()} zł</button>
                <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Anuluj</button>
            </form>
            `;
        } else {
            contentContainer.innerHTML = `
            <h2>Blik payment</h2>
            <form id="payment-form">
                <div class="payment_form_input">
                    <label for="blik-number">Blik number</label>
                    <input type="text" id="blik-number" value="" />
                </div>
                <button data-target="../HTML/dokonanie_platnosci.html" id="pay-button" disabled>Pay: ${calculateTotalPrice()} zł</button>
                <button data-target="../HTML/koszyk.html" type="button" id="cancel-button">Cancel</button>
            </form>
            `;
        }

        const form = document.getElementById('payment-form');

        form.addEventListener('input', function() {
            validateForm();
        });

        const navigationButtons = document.querySelectorAll('[data-target]');

        if (navigationButtons) {
            navigationButtons.forEach(button => {
                button.addEventListener('click', handleNavigation);
            });
        }
    }
}

function validateForm() {
    const blikNumber = document.getElementById('blik-number').value.trim();
    const payButton = document.getElementById('pay-button');

    const isBlikNumberValid = validateBlikNumber(blikNumber);

    if (isBlikNumberValid) {
        payButton.disabled = false;
        payButton.classList.add('enabled');
        payButton.classList.remove('disabled');
    } else {
        payButton.disabled = true;
        payButton.classList.add('disabled');
        payButton.classList.remove('enabled');
    }
}

function validateBlikNumber(blikNumber) {
    const cardPattern = /^\d{3} ?\d{3}$/;
    return cardPattern.test(blikNumber);
}

function calculateTotalPrice() {
    const currentBasket = getCurrentBasket();
    return currentBasket.reduce((total, ticket) => total + ticket.sum_price, 0);
}

// Add dynamicly loading content od the page
document.addEventListener('DOMContentLoaded', updateContentBacket);
document.addEventListener('DOMContentLoaded', validateForm);