// Dynamicly rendering logged user
function renderAuthorized(user) {
    const contentContainer = document.querySelector('.div_content_container');
    const isPolish = get_language();

    if (contentContainer) {
        if (isPolish) {
            contentContainer.innerHTML = `
                <div class="ticket-file-container">
                    <div class="not-active-section">
                        <h3>Nieaktywne</h3>
                        <div class="tickets-display">
                            <div id="tickets-container1" class="tickets-container"></div>
                        </div>
                    </div>
                    <div class="active-section">
                        <h3>Aktywne</h3>
                        <div class="tickets-display">
                            <div id="tickets-container2" class="tickets-container"></div>
                        </div>
                    </div>
                </div>
            `;   
        } else {
            contentContainer.innerHTML = `
                <div class="ticket-file-container">
                    <div class="not-active-section">
                        <h3>Inactive</h3>
                        <div class="tickets-display">
                            <div id="tickets-container1" class="tickets-container"></div>
                        </div>
                    </div>
                    <div class="active-section">
                        <h3>Active</h3>
                        <div class="tickets-display">
                            <div id="tickets-container2" class="tickets-container"></div>
                        </div>
                    </div>
                </div>
            `;   
        }
    }

    let notActiveTickets = user.not_active_file || [];
    let activeTickets = user.active_file || [];
    renderTickets(notActiveTickets, false, user);
    renderTickets(activeTickets, true, user);    
}

function renderTickets(my_file_tickets, isActive, user) {
    let ticketsContainer = document.getElementById(isActive ? 'tickets-container2' : 'tickets-container1');
    ticketsContainer.innerHTML = '';

    const isPolish = get_language();

    if (my_file_tickets.length > 0) {
        my_file_tickets.forEach((ticket, index) => {
            const ticketElement = document.createElement('div');
            let first_letter1;
            let rest_of_text1;
            let first_letter2;
            let rest_of_text2;

            if (isPolish) {
                first_letter1 = ticket.client_type[0].toUpperCase();
                rest_of_text1 = ticket.client_type.slice(1);
                first_letter2 = ticket.quantity_type[0].toUpperCase();
                rest_of_text2 = ticket.quantity_type.slice(1);
            } else {
                first_letter1 = ticket.client_type_ang[0].toUpperCase();
                rest_of_text1 = ticket.client_type_ang.slice(1);
                first_letter2 = ticket.quantity_type_ang[0].toUpperCase();
                rest_of_text2 = ticket.quantity_type_ang.slice(1);
            }
            
            const clientType = first_letter1 + rest_of_text1;
            const quantityType = first_letter2 + rest_of_text2;
            const currentCount = ticket.quantity || 0;

            let ticketTimeLabel;
            if (ticket.travel_time == 1440) {
                ticketTimeLabel = '24 h';
            } else if (ticket.travel_time == 2440) {
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

            ticketElement.classList.add('ticket');

            if (isPolish) {
                ticketElement.innerHTML = `
                    <div class="ticket-info">
                        <p><strong>Bilet ${clientType}</strong></p>
                        ${ticket.family ? '<p>Bilet Rodzinny</p>' : ''}
                        <p>Typ: ${quantityType}</p>
                        <p>Czas: ${ticketTimeLabel}</p>
                        <p>Strefa: ${ticket.zone === 'first' ? '1' : '1 + 2 + 3'}</p>
                        <p>Cena: ${ticket.price} zł</p>
                        <p>Ilość: ${currentCount}</p>
                        ${isActive ? `<div class="timer" id="timer-${index}"></div>` : ''}
                    </div>
                    <div class="ticket-buttons">
                        ${!isActive ? `<button class="active-button" data-index="${index}">Aktywuj</button>` : ''}
                        ${isActive ? `<button class="view-button" data-index="${index}">Podgląd</button>` : ''}
                        ${isActive ? `<button class="download-button" data-index="${index}">Pobierz</button>` : ''}
                    </div>
                `;
            } else {
                ticketElement.innerHTML = `
                    <div class="ticket-info">
                        <p><strong>Ticket ${clientType}</strong></p>
                        ${ticket.family ? '<p>Family Ticket</p>' : ''}
                        <p>Type: ${quantityType}</p>
                        <p>Time: ${ticketTimeLabel}</p>
                        <p>Zone: ${ticket.zone === 'first' ? '1' : '1 + 2 + 3'}</p>
                        <p>Price: ${ticket.price} PLN</p>
                        <p>Amount: ${currentCount}</p>
                        ${isActive ? `<div class="timer" id="timer-${index}"></div>` : ''}
                    </div>
                    <div class="ticket-buttons">
                        ${!isActive ? `<button class="active-button" data-index="${index}">Activate</button>` : ''}
                        ${isActive ? `<button class="view-button" data-index="${index}">Preview</button>` : ''}
                        ${isActive ? `<button class="download-button" data-index="${index}">Download</button>` : ''}
                    </div>
                `;
            }

            ticketsContainer.appendChild(ticketElement);

            if (!isActive) {
                ticketElement.querySelector('.active-button').addEventListener('click', () => {
                    showActivationModal(index, ticket, user);
                });
            } else {
                ticketElement.querySelector('.view-button').addEventListener('click', () => {
                    viewTicket(index, ticket, user);
                });

                ticketElement.querySelector('.download-button').addEventListener('click', () => {
                    downloadTicket(index, ticket, user);
                });

                startTimer(ticket, index, user);
            }
        });
    } else {
        const element = document.createElement('div');
        if (isPolish) {
            element.innerHTML = `  
                <div class="ticket-info ticket-info-empty" >
                    <p><strong>Brak Biletów.</strong></p>
                </div>
            `;
        } else {
            element.innerHTML = `  
                <div class="ticket-info ticket-info-empty">
                    <p><strong>No Tickets.</strong></p>
                </div>
            `;
        }
        ticketsContainer.appendChild(element);
    }
}

function showActivationModal(index, ticket, user) {
    const contentContainer = document.querySelector('.div_content_container');
    const modal = document.createElement('div');
    modal.className = 'modal-overlay';
    modal.innerHTML = ``;

    const isPolish = get_language();

    if (isPolish) {
        modal.innerHTML = `
            <div class="modal">
                <h2>Ile biletów aktywować?</h2>
                <div class="quantity-selector">
                    <button id="decrement">-</button>
                    <input type="number" id="quantity" value="1" min="1" max="${ticket.quantity}" readonly>
                    <button id="increment">+</button>
                </div>
                <div class="modal-buttons">
                    <button id="confirm">Potwierdź</button>
                    <button id="cancel">Anuluj</button>
                </div>
            </div>
        `;
    } else {
        modal.innerHTML = `
            <div class="modal">
                <h2>How many tickets to activate?</h2>
                <div class="quantity-selector">
                    <button id="decrement">-</button>
                    <input type="number" id="quantity" value="1" min="1" max="${ticket.quantity}" readonly>
                    <button id="increment">+</button>
                </div>
                <div class="modal-buttons">
                    <button id="confirm">Confirm</button>
                    <button id="cancel">Cancel</button>
                </div>
            </div>
        `;
    }

    contentContainer.appendChild(modal);
    modal.style.backgroundColor = 'rgba(0, 0, 0, 0.8)';
    const quantityInput = modal.querySelector('#quantity');
    modal.querySelector('#decrement').addEventListener('click', () => {
        quantityInput.value = Math.max(1, parseInt(quantityInput.value) - 1);
    });
    modal.querySelector('#increment').addEventListener('click', () => {
        quantityInput.value = Math.min(ticket.quantity, parseInt(quantityInput.value) + 1);
    });
    modal.querySelector('#cancel').addEventListener('click', () => {
        contentContainer.removeChild(modal);
    });
    modal.querySelector('#confirm').addEventListener('click', () => {
        const quantityToActivate = parseInt(quantityInput.value);
        activateTickets(index, ticket, user, quantityToActivate);
    });
    
}

function activateTickets(index, ticket, user, quantity) {
    const now = new Date();
    const activationDate = now.toLocaleDateString('pl-PL');
    const activationTime = now.toLocaleTimeString('pl-PL');
    
    const activeTickets = user.active_file || [];
    
    activeTickets.push({
        ...ticket,
        activation_date: activationDate,
        activation_time: activationTime,
        quantity: quantity
    });
    
    saveCurrentActiveFile(activeTickets);

    ticket.quantity -= quantity;
    
    if (ticket.quantity > 0) {
        const notActiveTickets = user.not_active_file || [];
        notActiveTickets[index] = ticket;
        saveCurrentNotActiveFileMyFile(notActiveTickets);
    } else {
        const notActiveTickets = user.not_active_file || [];
        notActiveTickets.splice(index, 1);
        saveCurrentNotActiveFileMyFile(notActiveTickets);
    }    
    renderAuthorized(user);
}


function startTimer(ticket, index, user) {
    const timerElement = document.getElementById(`timer-${index}`);
    const [day, month, year] = ticket.activation_date.split('.');
    const [hours, minutes, seconds] = ticket.activation_time.split(':');
    const activationDate = new Date(year, month - 1, day, hours, minutes, seconds);
    const travelTimeMs = ticket.travel_time * 60 * 1000;
    const expirationTime = activationDate.getTime() + travelTimeMs;

    const isPolish = get_language();

    let timerInterval;
    let expired = false;

    function updateTimer() {
        const now = Date.now();
        const remainingTime = expirationTime - now;

        if (remainingTime <= 0 && !expired) {
            expired = true;

            if (isPolish) {
                alert(`Bilet nr. ${index} wygasł.`);
            } else {
                alert(`Ticket nr. ${index} has just expired.`);
            }

            const activeTickets = user.active_file || [];
            const activeTicketsFilter = activeTickets.filter(t => t !== ticket);
            saveCurrentActiveFileMyFile(activeTicketsFilter);
            renderAuthorized(user);
            clearInterval(timerInterval);
            timerInterval = null;
            return;
        }

        const hours = Math.floor((remainingTime / (1000 * 60 * 60)) % 24);
        const minutes = Math.floor((remainingTime / (1000 * 60)) % 60);
        const seconds = Math.floor((remainingTime / 1000) % 60);
        timerElement.textContent = `${hours.toString().padStart(2, '0')}:${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
    }

    updateTimer();
    timerInterval = setInterval(updateTimer, 1000);
}

function viewTicket(index, ticket, user) {
    const contentContainer = document.querySelector('.div_content_container');
    const modal = document.createElement('div');
    modal.className = 'modal-overlay';
    modal.innerHTML = `  
        <div class="modal">
            <div id="qr-code"></div>
            <button class="close-modal">X</button>
        </div>
    `;

    const isPolish = get_language();

    contentContainer.appendChild(modal);

    let qrContent = `Bilet`;

    if (isPolish) {
        qrContent = `Bilet: ${ticket.client_type}, Czas: ${ticket.travel_time} minut, Strefa: ${ticket.zone}, Data: ${ticket.activation_date}, Godzina: ${ticket.activation_time}`;
    } else {
        qrContent = `Ticket: ${ticket.client_type_ang}, Time: ${ticket.travel_time} minutes, Zone: ${ticket.zone}, Date: ${ticket.activation_date}, Hour: ${ticket.activation_time}`;
    }

    QRCode.toDataURL(qrContent, { width: 200, height: 200 }, (err, url) => {
        if (err) {
            if (isPolish) {
                console.error('Błąd generowania kodu QR:', err);
            } else {
                console.error('QR code generation error:', err);
            }
            return;
        }
        const qrImage = new Image();
        qrImage.src = url;
        modal.querySelector('#qr-code').appendChild(qrImage);
    });

    modal.querySelector('.close-modal').addEventListener('click', () => {
        contentContainer.removeChild(modal);
    });
}

function downloadTicket(index, ticket, user) {
    const isPolish = get_language();

    let qrContent = `Bilet`;

    if (isPolish) {
        qrContent = `Bilet: ${ticket.client_type}, Czas: ${ticket.travel_time} minut, Strefa: ${ticket.zone}, Data: ${ticket.activation_date}, Godzina: ${ticket.activation_time}`;
    } else {
        qrContent = `Ticket: ${ticket.client_type_ang}, Time: ${ticket.travel_time} minutes, Zone: ${ticket.zone}, Date: ${ticket.activation_date}, Hour: ${ticket.activation_time}`;
    }

    QRCode.toDataURL(qrContent, { width: 200, height: 200 }, (err, url) => {
        if (err) {
            if (isPolish) {
                console.error('Błąd generowania kodu QR:', err);
            } else {
                console.error('QR code generation error:', err);
            }
            return;
        }
        const link = document.createElement('a');
        link.href = url;
        if (isPolish) {
            link.download = `bilet_${index + 1}.png`;
        } else {
            link.download = `ticket_${index + 1}.png`;
        }
        link.click();
    });
}

// Add dynamicly loading content of the page
document.addEventListener('DOMContentLoaded', updateContentLogin);
