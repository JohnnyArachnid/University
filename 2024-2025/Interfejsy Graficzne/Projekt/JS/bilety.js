function renderAuthorized(user) {
    const contentContainer = document.querySelector('.div_content_container');
    const availableTickets = tickets.filter(ticket => !user.favourites.some(fav => fav.id === ticket.id));
    const isPolish = get_language();
    const ticketsHTML = availableTickets.map(ticket => `
        <button class="ticket-button" data-id="${ticket.id}">
            <img src="../IMAGES/TICKETS/ticket${ticket.id}.jpg" alt="${ticket.name}" />
        </button>
    `).join('');
    if (contentContainer) {
        if (isPolish) {
            renderPolish();
            contentContainer.innerHTML = `
            <div class="tickets-container">
                ${ticketsHTML}
            </div>
            <button id="add-to-favourites" class="favourites-button" disabled>
                Dodaj Do Ulubionych
            </button>
            `;
        } else {
            renderEnglish();
            contentContainer.innerHTML = `
            <div class="tickets-container">
                ${ticketsHTML}
            </div>
            <button id="add-to-favourites" class="favourites-button" disabled>
                Add to favorites
            </button>
            `;
        }
        setupEventListeners(user);
    }
}

function setupEventListeners(user) {
    const ticketButtons = document.querySelectorAll('.ticket-button');
    const favouritesButton = document.getElementById('add-to-favourites');
    const isPolish = get_language();
    let selectedTickets = [];

    ticketButtons.forEach(button => {
        button.addEventListener('click', () => {
            const ticketId = parseInt(button.dataset.id, 10);
            if (selectedTickets.includes(ticketId)) {
                selectedTickets = selectedTickets.filter(id => id !== ticketId);
                button.classList.remove('selected');
            } else {
                selectedTickets.push(ticketId);
                button.classList.add('selected');
            }
            favouritesButton.disabled = selectedTickets.length === 0;
        });
    });

    favouritesButton.addEventListener('click', () => {
        const addedTickets = tickets.filter(ticket => selectedTickets.includes(ticket.id));

        addedTickets.forEach(ticket => {
            if (!user.favourites.some(fav => fav.id === ticket.id)) {
                user.favourites.push(ticket);
            }
        });
        if (isPolish) {
            const ticketNames = addedTickets.map(ticket => ticket.name).join(', ');
            alert(`Dodano do ulubionych następujące bilety: ${ticketNames}`);
        } else {
            const ticketNames = addedTickets.map(ticket => ticket.name_ang).join(', ');
            alert(`The following tickets have been added to your favorites: ${ticketNames}`);
        }
        saveCurrentFavourites(user.favourites);
        window.location.href = './ulubione.html';
    });
}

document.addEventListener('DOMContentLoaded', updateContentLogin);