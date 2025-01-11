function renderContentPolish() {
    const contentContainer = document.querySelector('.login_box');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <p class="title">Zaloguj się</p>
            <!-- Tu ten prostokat na srodku -->
            <div class="div_content_container_login">
                <form class="login_form">
                    <label for="email">Adres Email:</label>
                    <input id="email" type="email" class="email" name="email" autocomplete="email" required />

                    <label for="password">Hasło:</label>
                    <input id="password" type="password" class="password" name="password" autocomplete="new-password" required />

                    <button type="submit">Zaloguj się</button>
                </form>
            </div>
        `;   
    }
}

function renderContentEnglish() {
    const contentContainer = document.querySelector('.login_box');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <p class="title">Log in</p>
            <!-- Tu ten prostokat na srodku -->
            <div class="div_content_container_login">
                <form class="login_form">
                    <label for="email">Email Address:</label>
                    <input id="email" type="email" class="email" name="email" autocomplete="email" required />

                    <label for="password">Password:</label>
                    <input id="password" type="password" class="password" name="password" autocomplete="new-password" required />

                    <button type="submit">Log in</button>
                </form>
            </div>
        `;
    }
}

// Function to handle login
function handleLogin(event) {
    event.preventDefault();
    const isPolish = get_language();

    const email = document.querySelector('.email').value;
    const password = document.querySelector('.password').value;
    const users = JSON.parse(localStorage.getItem('users')) || [];
    const user = users.find(user => user.email === email && user.password === password);

    if (user) {
        user.is_logged_in = true;
        localStorage.setItem('users', JSON.stringify(users));
        if (isPolish) {
            alert(`Zalogowano pomyślnie! Witaj, ${user.first_name} ${user.last_name}.`);
        } else {
            alert(`You have successfully logged in! Welcome, ${user.first_name} ${user.last_name}.`);
        }
        window.location.href = '../HTML/inteligentny_zakup_biletu.html';
    } else {
        if (isPolish) {
            alert('Nieprawidłowy email lub hasło.');
        } else {
            alert('Incorrect email or password.');
        }
        location.reload();
    }
}

document.addEventListener('DOMContentLoaded', () => {

    updateContent();

    // Attach event listener to the login form
    document.querySelector('.login_form').addEventListener('submit', handleLogin);

});