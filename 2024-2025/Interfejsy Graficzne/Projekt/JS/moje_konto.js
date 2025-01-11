// Function to validate form inputs
function validateInput(field, value) {
    const validationRules = {
        email: /^[^\s@]+@[^\s@]+\.[^\s@]+$/,
        card_number: /^\d{4} ?\d{4} ?\d{4} ?\d{4}$/,
        expiry_date: /^(0[1-9]|1[0-2])\/\d{2}$/,
        csv: /^\d{3}$/
    };

    if (field === 'expiry_date') {
        const [month, year] = value.split('/').map(Number);
        const currentDate = new Date();
        const currentYear = currentDate.getFullYear() % 100;
        const currentMonth = currentDate.getMonth() + 1;
        if (year < currentYear || (year === currentYear && month < currentMonth)) {
            return false;
        }
    }

    return validationRules[field] ? validationRules[field].test(value) : true;
}

// Adding functionality to buttons
function addEventListeners(user) {
    const editButton = document.querySelector('.edit_button');
    const saveButton = document.querySelector('.save_button');
    const cancelButton = document.querySelector('.cancel_button');
    const fields = ['email', 'card_number', 'expiry_date', 'csv'];

    const isPolish = get_language();

    editButton.addEventListener('click', () => {
        fields.forEach(field => {
            const element = document.querySelector(`.${field}`);
            const input = document.createElement('input');
            input.type = 'text';
            input.value = element.textContent;
            input.className = `${field}_input`;
            element.replaceWith(input);
        });
        editButton.style.display = 'none';
        saveButton.style.display = 'inline';
        cancelButton.style.display = 'inline';
    });

    saveButton.addEventListener('click', () => {
        let isValid = true;

        fields.forEach(field => {
            const input = document.querySelector(`.${field}_input`);
            const value = input.value;
            if (!validateInput(field, value)) {
                if (isPolish) {
                    alert(`Nieprawidłowe dane dla ${field.replace('_', ' ')}`);
                } else {
                    alert(`Incorrect data for ${field.replace('_', ' ')}`);
                }
                isValid = false;
                return;
            }
        });

        if (isValid) {
            fields.forEach(field => {
                const input = document.querySelector(`.${field}_input`);
                const span = document.createElement('span');
                span.className = field;
                span.textContent = input.value;
                input.replaceWith(span);
                user[field] = input.value;
            });
            localStorage.setItem('users', JSON.stringify(users));
            if (isPolish) {
                alert('Dane zapisany w sposób prawidłowy.');
            } else {
                alert('Data recorded correctly.');
            }
            editButton.style.display = 'inline';
            saveButton.style.display = 'none';
            cancelButton.style.display = 'none';
            location.reload();
        }
    });

    cancelButton.addEventListener('click', () => {
        fields.forEach(field => {
            const input = document.querySelector(`.${field}_input`);
            const span = document.createElement('span');
            span.className = field;
            span.textContent = user[field];
            input.replaceWith(span);
        });
        if (isPolish) {
            alert('Brak zapisu danych.');
        } else {
            alert('No data saved.');
        }
        editButton.style.display = 'inline';
        saveButton.style.display = 'none';
        cancelButton.style.display = 'none';
    });
};

// Dynamicly rendering logged user
function renderAuthorized(user) {
    const contentContainer = document.querySelector('.div_content_container');
    const isPolish = get_language();

    if (isPolish) {
        if (contentContainer) {
            contentContainer.innerHTML = `
                <div class="user_section">
                    <h2><span>Moje konto</span></h2>
                    <div class="form">
                        <div class="left_side">
                            <p id="firstName">Imię: </p>
                            <p id="lastName">Nazwisko: </p>
                            <p id="email">Email: </p>
                            <p id="cardNumber">Numer karty: </p>
                            <p class="short" id="expiryDate">Data ważności: </p>
                            <p class="short" id="csv">CSV: </p>
                        </div>
                        <div class="right">
                            <span class="first_name">${user.first_name}</span>
                            <span class="last_name">${user.last_name}</span>
                            <span class="email">${user.email}</span>
                            <span class="card_number">${user.card_number}</span>
                            <span class="expiry_date">${user.expiry_date}</span>
                            <span class="csv">${user.csv}</span>
                        </div>
                    </div>
                    <div class="buttons">
                    <button class="edit_button">Edytuj</button>
                    <button class="cancel_button" style="display: none;">Cofnij</button>
                    <button class="save_button" style="display: none; margin-left: 10px;" >Zapisz</button>
                    </div>
                </div>
            `;
        }
    } else {
        if (contentContainer) {
            contentContainer.innerHTML = `
                <div class="user_section">
                    <h2><span>My account</span></h2>
                    <div class="form">
                        <div class="left_side">
                            <p id="firstName">Name: </p>
                            <p id="lastName">Last name: </p>
                            <p id="email">Email: </p>
                            <p id="cardNumber">Card number: </p>
                            <p class="short" id="expiryDate">Expiration date: </p>
                            <p class="short" id="csv">CSV: </p>
                        </div>
                        <div class="right">
                            <span class="first_name">${user.first_name}</span>
                            <span class="last_name">${user.last_name}</span>
                            <span class="email">${user.email}</span>
                            <span class="card_number">${user.card_number}</span>
                            <span class="expiry_date">${user.expiry_date}</span>
                            <span class="csv">${user.csv}</span>
                        </div>
                    </div>
                    <div class="buttons">
                    <button class="edit_button">Edit</button>
                    <button class="cancel_button" style="display: none;">Undo</button>
                    <button class="save_button" style="display: none; margin-left: 10px;" >Save</button>
                    </div>
                </div>
            `;
        }
    }

    addEventListeners(user);
};

// Add dynamicly loading content od the page
document.addEventListener('DOMContentLoaded', updateContentLogin);