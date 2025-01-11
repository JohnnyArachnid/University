// Dynamicly rendering logged user with tickets
function renderAuthorized(user) {
    const contentContainer = document.querySelector('.div_content_container_platnosci');
    const isPolish = get_language();

    if (contentContainer) {
        if (isPolish) {
            contentContainer.innerHTML = `
                <h2>Wybierz metodę płatności</h2>
                <div class="div_content_container">
                    <div class="payment-button">
                        <button data-target="../HTML/blik.html"">Płatność BLIK</button>
                    </div>
                    <div class="payment-button">
                        <button data-target="../HTML/karta.html">Płatność kartą</button>
                    </div>
                </div>
            `;
        } else {
            contentContainer.innerHTML = `
                <h2>Select payment method</h2>
                <div class="div_content_container">
                    <div class="payment-button">
                        <button data-target="../HTML/blik.html"">Payment with BLIK</button>
                    </div>
                    <div class="payment-button">
                        <button data-target="../HTML/karta.html">Payment by card</button>
                    </div>
                </div>
            `;
        }

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
    const contentContainer = document.querySelector('.div_content_container_platnosci');
    const isPolish = get_language();

    if (contentContainer) {
        if (isPolish) {
            contentContainer.innerHTML = `
                <h2>Wybierz metodę płatności</h2>
                <div class="div_content_container">
                    <div class="payment-button">
                        <button data-target="../HTML/blik.html"">Płatność BLIK</button>
                    </div>
                    <div class="payment-button">
                        <button data-target="../HTML/karta.html">Płatność kartą</button>
                    </div>
                </div>
            `;
        } else {
            contentContainer.innerHTML = `
                <h2>Select payment method</h2>
                <div class="div_content_container">
                    <div class="payment-button">
                        <button data-target="../HTML/blik.html"">Payment with BLIK</button>
                    </div>
                    <div class="payment-button">
                        <button data-target="../HTML/karta.html">Payment by card</button>
                    </div>
                </div>
            `;
        }

        const navigationButtons = document.querySelectorAll('[data-target]');

        if (navigationButtons) {
            navigationButtons.forEach(button => {
                button.addEventListener('click', handleNavigation);
            });
        }
    }
}

// Add dynamicly loading content od the page
document.addEventListener('DOMContentLoaded', updateContentBacket);