// Add default user if not already present
function addDefaultUser() {
    if (users.length === 0) {
        const defaultUser = {
            id: 1,
            first_name: 'Jan',
            last_name: 'Kowalski',
            email: 'jan.kowalski@gmail.com',
            password: 'janKOWALSKI123!',
            card_number: '1234 1234 1234 1234',
            expiry_date: '01/25',
            csv: '123',
            is_logged_in: false,
            basket: [],
            favourites: [],
            not_active_file: [],
            active_file: [],
            history: []
        };
        users.push(defaultUser);
        localStorage.setItem('users', JSON.stringify(users));
    }
}

// Hamburger menu
function hamburger_menu() {
    const hamburger = document.querySelector(".hamburger_menu");
    const navLinks = document.querySelector(".nav_links");

    if (hamburger) {
        hamburger.addEventListener("click", function() {
            navLinks.classList.toggle("show");
        });
    }
}

// Downloanding current basket
function getCurrentBasket() {
    const loggedInUser = users.find(user => user.is_logged_in);
    if (loggedInUser) {
        return loggedInUser.basket || [];
    }
    return JSON.parse(localStorage.getItem('selectedTicketsToBuy')) || [];
}

// Saving current basket
function saveCurrentBasket(basket) {
    const loggedInUser = users.find(user => user.is_logged_in);
    if (loggedInUser) {
        loggedInUser.basket = basket;
        localStorage.setItem('users', JSON.stringify(users));
    } else {
        localStorage.setItem('selectedTicketsToBuy', JSON.stringify(basket));
    }
}

// Saving current favourites
function saveCurrentFavourites(favourites) {
    const loggedInUser = users.find(user => user.is_logged_in);
    loggedInUser.favourites = [...new Set(favourites)];
    localStorage.setItem('users', JSON.stringify(users));
}

// Saving current history
function saveCurrentHistory(history) {
    const loggedInUser = users.find(user => user.is_logged_in);
    loggedInUser.history = [...new Set([...(loggedInUser.history || []), ...history])];
    localStorage.setItem('users', JSON.stringify(users));
}

// Downloanding current active tickets
function saveCurrentActiveFile(active_file) {
    const loggedInUser = users.find(user => user.is_logged_in);
    loggedInUser.active_file = [...new Set([...(loggedInUser.active_file || []), ...active_file])];
    localStorage.setItem('users', JSON.stringify(users));
}

// Downloanding current active tickets with My File
function saveCurrentActiveFileMyFile(active_file) {
    const loggedInUser = users.find(user => user.is_logged_in);
    loggedInUser.active_file = active_file || [];
    localStorage.setItem('users', JSON.stringify(users));
}

// Downloanding current not active tickets
function saveCurrentNotActiveFile(not_active_file) {
    const loggedInUser = users.find(user => user.is_logged_in);
    const updatedNotActiveFile = not_active_file.reduce((acc, newTicket) => {
        const existingTicketIndex = acc.findIndex(ticket => ticket.id === newTicket.id);
        
        if (existingTicketIndex !== -1) {
            acc[existingTicketIndex].quantity += newTicket.quantity;
        } else {
            acc.push(newTicket);
        }

        return acc;
    }, loggedInUser.not_active_file || []);
    loggedInUser.not_active_file = updatedNotActiveFile;
    localStorage.setItem('users', JSON.stringify(users));
}

// Downloanding current not active tickets with My File
function saveCurrentNotActiveFileMyFile(not_active_file) {
    const loggedInUser = users.find(user => user.is_logged_in);
    loggedInUser.not_active_file = [...new Set(not_active_file)];
    localStorage.setItem('users', JSON.stringify(users));
}

// Validation functionality
function validation() {
    // Validation accounts
    console.log(JSON.parse(localStorage.getItem('users')));

    // Validation messages
    console.log(JSON.parse(localStorage.getItem('messages')));

    // Validation selected tickets
    console.log(JSON.parse(localStorage.getItem('selectedTicketsToBuy')));
}

// Language validation
function language_validation(language) {
    if (language) {
        console.log('Aktualny język strony: Polski');
    } else {
        console.log('Aktualny język strony: Angielski');
    }
}

// Add default user on page load
document.addEventListener('DOMContentLoaded', addDefaultUser);

// Add default validation check
document.addEventListener('DOMContentLoaded', validation);

// Add hamburger menu on page load
document.addEventListener('DOMContentLoaded', hamburger_menu);
