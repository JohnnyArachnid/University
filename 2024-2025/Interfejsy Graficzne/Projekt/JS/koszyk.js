function renderContentPolish() {
    const contentContainer = document.querySelector('.div_content_container');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <div class="ticket-purchase-container">
                <div class="tickets-display">
                    <h2>Bilety w Koszyku</h2>
                    <div id="tickets-container" class="tickets-container"></div>
                </div>
                <div class="summary">
                    <h3>Podsumowanie</h3>
                    <div class="summary-section"></div>
                    <div class="action-buttons">
                    <button id="reset-filters">Wyczyść Bilety</button>
                    <button id="proceed-to-payment" disabled>Przejdź do Płatności</button>
                    <button id="go-to-buy" data-target="../HTML/inteligentny_zakup_biletu.html">Kontynuuj zakupy</button>
                    </div>
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

function renderContentEnglish() {
    const contentContainer = document.querySelector('.div_content_container');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <div class="ticket-purchase-container">
                <div class="tickets-display">
                    <h2>Tickets in Cart</h2>
                    <div id="tickets-container" class="tickets-container"></div>
                </div>
                <div class="summary">
                    <h3>Summary</h3>
                    <div class="summary-section"></div>
                    <div class="action-buttons">
                    <button id="reset-filters">Clear Tickets</button>
                    <button id="proceed-to-payment" disabled>Go to Payments</button>
                    <button id="go-to-buy" data-target="../HTML/inteligentny_zakup_biletu.html">Continue shopping</button>
                    </div>
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

function renderTickets() {
    const ticketsContainer = document.getElementById('tickets-container');
    const currentBasket = getCurrentBasket();
    const isPolish = get_language();
    ticketsContainer.innerHTML = '';
    let totalPrice = 0;
    let totalCount = 0;
    if (currentBasket.length > 0) {
        currentBasket.forEach(ticket => {
            const ticketElement = document.createElement('div');
            ticketElement.classList.add('ticket');
            let ticketTimeLabel;
            if (ticket.travel_time == 1440) {
                ticketTimeLabel = '24 h';
            } else if (ticket.travel_time == 2880) {
                ticketTimeLabel = '48 h';
            } else if (ticket.travel_time == 4320) {
                ticketTimeLabel = '72 h';
            } else if (ticket.travel_time == 10080) {
                if (isPolish) {
                    ticketTimeLabel = '7 dni';
                } else {
                    ticketTimeLabel = '7 days';
                }
            } else {
                if (isPolish) {
                    ticketTimeLabel = `${ticket.travel_time} minut`;
                } else {
                    ticketTimeLabel = `${ticket.travel_time} minutes`;
                }
            }

            if (isPolish) {
                ticketElement.innerHTML = `
                    <div class="ticket-info">
                        <p><strong>Bilet ${ticket.client_type.toUpperCase()}</strong></p>
                        ${ticket.family ? '<p>Bilet Rodzinny</p>' : ''}
                        <p>Czas: ${ticketTimeLabel}</p>
                        <p>Strefa: ${ticket.zone === 'first' ? '1 Strefa' : '1 + 2 + 3 Strefa'}</p>
                        <p>Cena: ${ticket.price} zł</p>
                    </div>
                    <div class="ticket-actions">
                        <button onclick="updateTicketCount(${ticket.id}, -1)">-</button>
                        <span id="ticket-count-${ticket.id}">${ticket.quantity || 0}</span>
                        <button onclick="updateTicketCount(${ticket.id}, 1)">+</button>
                    </div>
                `;
            } else {
                ticketElement.innerHTML = `
                    <div class="ticket-info">
                        <p><strong>Ticket ${ticket.client_type_ang.toUpperCase()}</strong></p>
                        ${ticket.family ? '<p>Family Ticket</p>' : ''}
                        <p>Time: ${ticketTimeLabel}</p>
                        <p>Zone: ${ticket.zone === 'first' ? '1 Zone' : '1 + 2 + 3 Zone'}</p>
                        <p>Price: ${ticket.price} PLN</p>
                    </div>
                    <div class="ticket-actions">
                        <button onclick="updateTicketCount(${ticket.id}, -1)">-</button>
                        <span id="ticket-count-${ticket.id}">${ticket.quantity || 0}</span>
                        <button onclick="updateTicketCount(${ticket.id}, 1)">+</button>
                    </div>
                `;
            }
            
            ticketsContainer.appendChild(ticketElement);

            totalPrice += ticket.sum_price || 0;
            totalCount += ticket.quantity || 0;
        });
    } else {
        const element = document.createElement('div');
        if (isPolish) {
            element.innerHTML = `
                <div class="ticket-info">
                    <p><strong>Brak biletów w koszyku</strong></p>
                </div>
            `;
        } else {
            element.innerHTML = `
                <div class="ticket-info">
                    <p><strong>No tickets in cart</strong></p>
                </div>
        `   ;
        }
        ticketsContainer.appendChild(element);
    }
    updateSummary(currentBasket);
}

function updateTicketCount(ticketId, change) {
    let currentBasket = getCurrentBasket();
    const ticket = currentBasket.find(t => t.id === ticketId);

    if (ticket) {
        ticket.quantity = Math.max(0, (ticket.quantity || 0) + change);
        ticket.sum_price = ticket.quantity * ticket.price;

        if (ticket.quantity === 0) {
            currentBasket = currentBasket.filter(t => t.id !== ticketId);
        }

        document.getElementById(`ticket-count-${ticket.id}`).innerText = ticket.quantity;

        saveCurrentBasket(currentBasket);
        updateSummary(currentBasket);
        renderTickets();
    }
}

function updateSummary(currentBasket) {
    const summarySection = document.querySelector('.summary-section');
    const resetFiltersButton = document.getElementById("reset-filters");
    const proceedToPaymentButton = document.getElementById('proceed-to-payment');
    const isPolish = get_language();

    let totalPrice = 0;
    let totalCount = 0;

    currentBasket = currentBasket.filter(ticket => ticket.quantity > 0);
    for (let i = 0; i < currentBasket.length; i++) {
        const ticket = currentBasket[i];
        totalPrice += ticket.sum_price || 0;
        totalCount += ticket.quantity || 0;
    }

    if (isPolish) {
        summarySection.innerHTML = `
            <p>Wartość biletów: ${totalPrice} zł</p>
            <p>Liczba biletów: ${totalCount}</p>
        `;
    } else {
        summarySection.innerHTML = `
            <p>Ticket Value: ${totalPrice} PLN</p>
            <p>Number of tickets: ${totalCount}</p>
        `;
    }

    resetFiltersButton.disabled = totalCount === 0;
    proceedToPaymentButton.disabled = totalCount === 0;
}

function summary_for_buying() {
    const currentBasket = getCurrentBasket();
    return currentBasket.filter(ticket => ticket.quantity > 0).map(ticket => ({ ...ticket }));
}

document.addEventListener('DOMContentLoaded', () => {

    updateContent();

    const resetFiltersButton = document.getElementById("reset-filters");
    const proceedToPaymentButton = document.getElementById('proceed-to-payment');

    resetFiltersButton.addEventListener("click", () => {
        const isPolish = get_language();
        let currentBasket = getCurrentBasket();
        if (currentBasket.length > 0) {
            currentBasket.forEach(ticket => {
                ticket.quantity = 0;
                ticket.sum_price = 0;
            });
    
            currentBasket = currentBasket.filter(ticket => ticket.quantity > 0);
    
            saveCurrentBasket(currentBasket);
            renderTickets();
            resetFiltersButton.disabled = true;
            proceedToPaymentButton.disabled = true;
            if (isPolish) {
                alert("Bilety z koszyka zostały usunięte.");
            } else {
                alert("Tickets have been removed from your cart.");
            }
            location.reload();
        }
    });
    
    proceedToPaymentButton.addEventListener('click', () => {
        const selectedTicketsForBuy = summary_for_buying();
        const isPolish = get_language();
        saveCurrentBasket(selectedTicketsForBuy);
        let basketSummary;
        if (isPolish) {
            basketSummary = selectedTicketsForBuy.map(ticket => {
                let firstLetter = ticket.client_type[0].toUpperCase();
                let restOfText = ticket.client_type.slice(1);
                const name = firstLetter + restOfText;
                firstLetter = ticket.quantity_type[0].toUpperCase();
                restOfText = ticket.quantity_type.slice(1);
                const type = firstLetter + restOfText;
                let ticketTimeLabel;
                if (ticket.travel_time == 1440) {
                    ticketTimeLabel = '24 h';
                } else if (ticket.travel_time == 2880) {
                    ticketTimeLabel = '48 h';
                } else if (ticket.travel_time == 4320) {
                    ticketTimeLabel = '72 h';
                } else if (ticket.travel_time == 10080) {
                    ticketTimeLabel = '7 dni';
                } else {
                    ticketTimeLabel = `${ticket.travel_time} minut`;
                }
                return `${type} - ${name} - ${ticketTimeLabel} - ${ticket.price} zł - ${ticket.quantity} szt. - ${ticket.sum_price} zł`;
            }).join("\n");
        } else {
            basketSummary = selectedTicketsForBuy.map(ticket => {
                let firstLetter = ticket.client_type_ang[0].toUpperCase();
                let restOfText = ticket.client_type_ang.slice(1);
                const name = firstLetter + restOfText;
                firstLetter = ticket.quantity_type_ang[0].toUpperCase();
                restOfText = ticket.quantity_type_ang.slice(1);
                const type = firstLetter + restOfText;
                let ticketTimeLabel;
                if (ticket.travel_time == 1440) {
                    ticketTimeLabel = '24 h';
                } else if (ticket.travel_time == 2880) {
                    ticketTimeLabel = '48 h';
                } else if (ticket.travel_time == 4320) {
                    ticketTimeLabel = '72 h';
                } else if (ticket.travel_time == 10080) {
                    ticketTimeLabel = '7 days';
                } else {
                    ticketTimeLabel = `${ticket.travel_time} minutes`;
                }
                return `${type} - ${name} - ${ticketTimeLabel} - ${ticket.price} PLN - ${ticket.quantity} pcs. - ${ticket.sum_price} PLN`;
            }).join("\n");
        }
        const totalPrice = selectedTicketsForBuy.reduce((sum, t) => sum + t.sum_price, 0);
        const totalNumber = selectedTicketsForBuy.reduce((sum, t) => sum + t.quantity, 0);
        if (isPolish) {
            alert(`Przechodzimy do płatności z wybranymi biletami:\n${basketSummary}\nŁączna cena: ${totalPrice} zł\nIlość wybranych biletów: ${totalNumber}`);
        } else {
            alert(`We proceed to payment with selected tickets:\n${basketSummary}\nTotal price: ${totalPrice} PLN\nNumber of selected tickets: ${totalNumber}`);
        }
        window.location.href = './platnosci.html';
    });
    
    // Initial render of tickets and summary
    renderTickets();
});