function renderContentPolish() {
    const contentContainer = document.querySelector('.register_box');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <p class="title">Utwórz swoje konto</p>
            <!-- Tu ten prostokat na srodku -->
            <div class="div_content_container_register">
                <form class="registration_form">
                    <label for="firstName">Imię:</label>
                    <input id="firstName" type="text" class="first_name" name="firstName" autocomplete="given-name"><br>
                
                    <label for="lastName">Nazwisko:</label>
                    <input id="lastName" type="text" class="last_name" name="lastName" autocomplete="family-name"><br>
                
                    <label for="email">Email:</label>
                    <input id="email" type="email" class="email" name="email" autocomplete="email"><br>
                
                    <label for="password">Hasło:</label>
                    <input id="password" type="password" class="password" name="password" autocomplete="new-password"><br>

                    <label for="repeatPassword">Powtórzone Hasło:</label>
                    <input id="repeatPassword" type="password" class="repeatPassword" name="repeatPassword" autocomplete="repeat-password"><br>
                
                    <label for="cardNumber">Numer Karty:</label>
                    <input id="cardNumber" type="text" class="card_number" name="cardNumber" autocomplete="cc-number"><br>
                
                    <label for="expiryDate">Data Ważności (MM/YY):</label>
                    <input id="expiryDate" type="text" class="expiry_date" name="expiryDate" autocomplete="cc-exp"><br>
                
                    <label for="csv">CSV:</label>
                    <input id="csv" type="text" class="csv" name="csv" autocomplete="cc-csc"><br>
                
                    <button type="submit">Zarejestruj</button>
                </form>          
            </div>
        `;   
    }
}

function renderContentEnglish() {
    const contentContainer = document.querySelector('.register_box');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <p class="title">Create your account</p>
            <!-- Tu ten prostokat na srodku -->
            <div class="div_content_container_register">
                <form class="registration_form">
                    <label for="firstName">Name:</label>
                    <input id="firstName" type="text" class="first_name" name="firstName" autocomplete="given-name"><br>
                
                    <label for="lastName">Last name:</label>
                    <input id="lastName" type="text" class="last_name" name="lastName" autocomplete="family-name"><br>
                
                    <label for="email">Email:</label>
                    <input id="email" type="email" class="email" name="email" autocomplete="email"><br>
                
                    <label for="password">Password:</label>
                    <input id="password" type="password" class="password" name="password" autocomplete="new-password"><br>

                    <label for="repeatPassword">Powtórzone Hasło:</label>
                    <input id="repeatPassword" type="password" class="repeatPassword" name="repeatPassword" autocomplete="repeat-password"><br>
                
                    <label for="cardNumber">Card Number:</label>
                    <input id="cardNumber" type="text" class="card_number" name="cardNumber" autocomplete="cc-number"><br>
                
                    <label for="expiryDate">Expiration Date (MM/YY):</label>
                    <input id="expiryDate" type="text" class="expiry_date" name="expiryDate" autocomplete="cc-exp"><br>
                
                    <label for="csv">CSV:</label>
                    <input id="csv" type="text" class="csv" name="csv" autocomplete="cc-csc"><br>
                
                    <button type="submit">Register</button>
                </form>          
            </div>
        `;   
    }
}

// Function to validate form inputs
function validateForm() {
    const fields = [
        { class: 'first_name', regex: /^[a-zA-Ząćęłńóśżź]{1,50}$/, error: 'Imię może zawierać tylko litery i maksymalnie 50 znaków.', errorANG: 'The name can contain only letters and a maximum of 50 characters.' },
        { class: 'last_name', regex: /^[a-zA-Ząćęłńóśżź]{1,50}$/, error: 'Nazwisko może zawierać tylko litery i maksymalnie 50 znaków.', errorANG: 'The last name can contain only letters and a maximum of 50 characters.' },
        { class: 'email', regex: /^[^\s@]+@[^\s@]+\.[^\s@]+$/, error: 'Wprowadź poprawny adres email.', errorANG: 'Please enter a valid email address.' },
        { class: 'password', regex: /^(?=.*[A-Z])(?=.*\d)(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,100}$/, error: 'Hasło musi mieć co najmniej 8 znaków, jedną dużą literę, jedną cyfrę i jeden znak specjalny.', errorANG: 'Password must be at least 8 characters long, one uppercase letter, one number, and one special character.' },
        { class: 'repeatPassword', regex: /^(?=.*[A-Z])(?=.*\d)(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,100}$/, error: 'Powtórzone hasło musi mieć co najmniej 8 znaków, jedną dużą literę, jedną cyfrę i jeden znak specjalny.', errorANG: 'Repeated password must be at least 8 characters long, one uppercase letter, one number, and one special character.' },
        { class: 'card_number', regex: /^\d{4} ?\d{4} ?\d{4} ?\d{4}$/, error: 'Numer karty musi składać się z 16 cyfr, może zawierać spacje co 4 cyfry.', errorANG: 'The card number must consist of 16 digits, it can contain spaces every 4 digits.' },
        { class: 'expiry_date', regex: /^(0[1-9]|1[0-2])\/\d{2}$/, error: 'Data ważności w formacie MM/YY.', errorANG: 'Expiration date in format MM/YY.' },
        { class: 'csv', regex: /^\d{3}$/, error: 'CSV musi zawierać 3 cyfry.', errorANG: 'CSV must contain 3 digits.' }
    ];

    const isPolish = get_language();

    let isValid = true;

    fields.forEach(field => {
        const input = document.querySelector(`.${field.class}`);
        const errorElement = document.querySelector(`.${field.class}_error`);

        input.style.border = '';
        if (errorElement) errorElement.remove();

        if (!field.regex.test(input.value.trim())) {
            isValid = false;
            input.style.border = '2px solid red';
            const errorMessage = document.createElement('div');
            errorMessage.className = `${field.class}_error`;
            errorMessage.style.color = 'red';

            if (isPolish) {
                errorMessage.textContent = field.error;
            } else {
                errorMessage.textContent = field.errorANG;
            }
            input.insertAdjacentElement('afterend', errorMessage);
        }

        // Additional validation for expiry date
        if (field.class === 'expiry_date' && field.regex.test(input.value.trim())) {
            const [month, year] = input.value.trim().split('/').map(Number);
            const currentDate = new Date();
            const currentYear = currentDate.getFullYear() % 100;
            const currentMonth = currentDate.getMonth() + 1;

            const expiryError = document.querySelector('.expiry_date_error');
            if (expiryError) expiryError.remove();

            if (year < currentYear || (year === currentYear && month < currentMonth)) {
                isValid = false;
                input.style.border = '2px solid red';
                const errorMessage = document.createElement('div');
                errorMessage.className = `expiry_date_error`;
                errorMessage.style.color = 'red';
                errorMessage.textContent = isPolish 
                    ? 'Karta nieaktualna. Podaj poprawną datę ważności.' 
                    : 'Card expired. Please provide correct expiration date.';

                input.insertAdjacentElement('afterend', errorMessage);
            }
        }

        if (field.class === 'repeatPassword' && field.regex.test(input.value.trim())) {
            const passwordInput = document.querySelector('.password');
            const repeatPasswordError = document.querySelector('.repeatPassword_error');

            if (repeatPasswordError) repeatPasswordError.remove();

            if (passwordInput.value.trim() !== input.value.trim()) {
                isValid = false;
                input.style.border = '2px solid red';
                const errorMessage = document.createElement('div');
                errorMessage.className = 'repeatPassword_error';
                errorMessage.style.color = 'red';
                errorMessage.textContent = isPolish
                    ? 'Hasła muszą być identyczne.'
                    : 'Passwords must match.';
                    input.insertAdjacentElement('afterend', errorMessage);
            }
        }
    });

    return isValid;
}

// Function to save user data to localStorage
function saveUser(user) {
    const lastId = users.length > 0 ? Math.max(...users.map(u => u.id || 1)) : 1;
    user.id = lastId + 1;
    users.push(user);
    localStorage.setItem('users', JSON.stringify(users));
}

// Function to check if the email is already taken
function isEmailTaken(email) {
    const users = JSON.parse(localStorage.getItem('users')) || [];
    return users.some(user => user.email === email);
}

// Function to reper proper card adress formula
function formatCardNumber(cardNumber) {
    const cleanedCardNumber = cardNumber.replace(/\D/g, '');
    return cleanedCardNumber.replace(/(\d{4})(?=\d)/g, '$1 ').trim();
}

// Function for registration
function registration(event) {
    event.preventDefault();

    const emailInput = document.querySelector('.email').value.trim();

    const isPolish = get_language();

    if (isEmailTaken(emailInput)) {
        if (isPolish) {
            alert('Konto z tym adresem email już istnieje. Wybierz inny adres.');
        } else {
            alert('An account with this email address already exists. Please select a different address.');
        }
        this.reset();
        return;
    }
    
    if (validateForm()) {
        const firstNameInput = document.querySelector('.first_name').value.trim();
        const lastNameInput = document.querySelector('.last_name').value.trim();
        const emailInput = document.querySelector('.email').value.trim();

        const user = {
            first_name: firstNameInput.charAt(0).toUpperCase() + firstNameInput.slice(1).toLowerCase(),
            last_name: lastNameInput.charAt(0).toUpperCase() + lastNameInput.slice(1).toLowerCase(),
            email: emailInput.toLowerCase(),
            password: document.querySelector('.password').value.trim(),
            card_number: formatCardNumber(document.querySelector('.card_number').value.trim()),
            expiry_date: document.querySelector('.expiry_date').value.trim(),
            csv: document.querySelector('.csv').value.trim(),
            is_logged_in: false,
            basket: [],
            favourites: [],
            not_active_file: [],
            active_file: [],
            history: []
        };
        saveUser(user);

        if(isPolish) {
            alert('Rejestracja zakończona pomyślnie!');
        } else {
            alert('Registration completed successfully!');
        }
        this.reset();
        window.location.href = '../HTML/logowanie.html';
    }
}

document.addEventListener('DOMContentLoaded', () => {

    updateContent();

    // Attach event listener to the form
    document.querySelector('.registration_form').addEventListener('submit', registration);

});