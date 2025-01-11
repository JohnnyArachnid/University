// Function to handle navigation
function handleNavigation(event) {
    event.preventDefault();

    const targetUrl = event.currentTarget.dataset.target;
    if (targetUrl) {
        window.location.href = targetUrl;
    }
}

// Update the navigation dynamically based on user login status and language
function updateNavigation() {
    const currentUser = users.find(user => user.is_logged_in);
    const loggingDiv = document.querySelector('.logging');
    const isPolish = get_language();

    const navigationLinks = document.querySelector(".nav_links");

    if (navigationLinks) {
        if (isPolish) {
            navigationLinks.innerHTML = `
                <a href="./inteligentny_zakup_biletu.html">Inteligentny zakup biletu</a>
                <a href="./szybki_zakup_biletu.html">Szybki zakup biletu</a>
                <a href="./mapy_schematy.html">Mapy i schematy Krakowa</a>
                <a href="./rozklad_jazdy.html">Rozkład jazdy</a>
            `;
        } else {
            navigationLinks.innerHTML = `
                <a href="./inteligentny_zakup_biletu.html">Smart ticket purchase</a>
                <a href="./szybki_zakup_biletu.html">Quick ticket purchase</a>
                <a href="./mapy_schematy.html">Maps of Cracow</a>
                <a href="./rozklad_jazdy.html">Schedule</a>
            `;
        }
    }

    if (currentUser && loggingDiv) {
        if (isPolish) {
            loggingDiv.innerHTML = `
            <div class="user_menu">
                <button class="toggle_menu_button">&darr;</button>
                <span class="user_name">${currentUser.first_name} ${currentUser.last_name}</span>
                <div class="menu_options" style="display: none;">
                    <button data-target="../HTML/moje_konto.html">Moje konto</button>
                    <button data-target="../HTML/ulubione.html">Ulubione</button>
                    <button data-target="../HTML/historia_zakupow.html">Historia zakupów</button>
                    <button data-target="../HTML/moja_teczka.html">Moja teczka</button>
                    <button class="logout_button">WYLOGUJ</button>
                </div>
            </div>`;
        } else {
            loggingDiv.innerHTML = `
            <div class="user_menu">
                <button class="toggle_menu_button">&darr;</button>
                <span class="user_name">${currentUser.first_name} ${currentUser.last_name}</span>
                <div class="menu_options" style="display: none;">
                    <button data-target="../HTML/moje_konto.html">My account</button>
                    <button data-target="../HTML/ulubione.html">Favorite</button>
                    <button data-target="../HTML/historia_zakupow.html">Purchase history</button>
                    <button data-target="../HTML/moja_teczka.html">My briefcase</button>
                    <button class="logout_button">LOG OUT</button>
                </div>
            </div>`;
        }

        const toggleMenuButton = document.querySelector('.toggle_menu_button');
        const menuOptions = document.querySelector('.menu_options');

        toggleMenuButton.addEventListener('click', () => {
            const isMenuVisible = menuOptions.style.display === 'block';
            menuOptions.style.display = isMenuVisible ? 'none' : 'block';
            toggleMenuButton.classList.toggle('down', isMenuVisible);
            toggleMenuButton.classList.toggle('up', !isMenuVisible);
            toggleMenuButton.innerHTML = isMenuVisible ? '&darr;' : '&uarr;';
        });

        const logoutButton = document.querySelector('.logout_button');
        logoutButton.addEventListener('click', () => {
            currentUser.is_logged_in = false;
            localStorage.setItem('users', JSON.stringify(users));
            if (isPolish) {
                alert(`Wylogowano poprawnie, Do zobaczenia ${currentUser.first_name} ${currentUser.last_name}`)
            } else {
                alert(`You have successfully logged out, See you soon ${currentUser.first_name} ${currentUser.last_name}`)
            }
            location.reload();
        });

    } else if (loggingDiv) {
        if (isPolish) {
            loggingDiv.innerHTML = `
            <button data-target="../HTML/rejestracja.html">Zarejestruj się</button>
            <button data-target="../HTML/logowanie.html">Zaloguj się</button>
            `;
        } else {
            loggingDiv.innerHTML = `
            <button data-target="../HTML/rejestracja.html">Sign up</button>
            <button data-target="../HTML/logowanie.html">Log in</button>
            `;
        }  
    }

    const navigationButtons = document.querySelectorAll('[data-target]');

    if (navigationButtons) {
        navigationButtons.forEach(button => {
            button.addEventListener('click', handleNavigation);
        });
    }

    const backButton = document.querySelector('.back_arrow');

    if (backButton) {
        backButton.addEventListener('click', (event) => {
            event.preventDefault();
            window.history.back();
        });
    }
}

// Run the navigation update on page load
document.addEventListener('DOMContentLoaded', updateNavigation);