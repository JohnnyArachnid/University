function renderContentPolish() {
  const contentContainer = document.querySelector('.div_content_container');

  if (contentContainer) {
      contentContainer.innerHTML = `
        <div class="left_form">
          <h3>Masz jakieś pytania?</h3>
          <h1>Skontaktuj się z nami</h1>
          <p class="to_left">+32 XXX XXX XXX</p>
          <p class="to_left">xxxxxx@gmail.com</p>
          <p class="to_left">Kraków</p>
        </div>
        <div class="right">
          <form class="contact_form">
            <div class="form_inputs">
              <label for="firstName">Imię:</label>
              <input id="firstName" type="text" class="first_name" autocomplete="given-name">
            </div>
            <div class="form_inputs">
              <label for="lastName">Nazwisko:</label>
              <input id="lastName" type="text" class="last_name" autocomplete="family-name">
            </div>
            <div class="form_inputs">
              <label for="email">Email:</label>
              <input id="email" type="email" class="email" autocomplete="email">
            </div>
            <div class="form_inputs">
              <label for="phone">Numer telefonu:</label>
              <input id="phone" type="tel" class="phone" autocomplete="tel">
            </div>
            <div class="form_inputs form_message">
              <label for="message">Treść wiadomości:</label>
              <textarea id="message" class="message" maxlength="1000" autocomplete="off"></textarea>
              <div class="char_counter">0/1000</div>
            </div>
            <div class="button_container">
              <button type="submit">Wyślij</button>
            </div>
          </form>          
        </div>
      `;   
  }
}

function renderContentEnglish() {
  const contentContainer = document.querySelector('.div_content_container');

  if (contentContainer) {
    contentContainer.innerHTML = `
      <div class="left_form">
        <h3>Do you have any questions?</h3>
        <h1>Contact us</h1>
        <p class="to_left">+32 XXX XXX XXX</p>
        <p class="to_left">xxxxxx@gmail.com</p>
        <p class="to_left">Cracow</p>
      </div>
      <div class="right">
        <form class="contact_form">
          <div class="form_inputs">
            <label for="firstName">Name:</label>
            <input id="firstName" type="text" class="first_name" autocomplete="given-name">
          </div>
          <div class="form_inputs">
            <label for="lastName">Last name:</label>
            <input id="lastName" type="text" class="last_name" autocomplete="family-name">
          </div>
          <div class="form_inputs">
            <label for="email">Email:</label>
            <input id="email" type="email" class="email" autocomplete="email">
          </div>
          <div class="form_inputs">
            <label for="phone">Phone number:</label>
            <input id="phone" type="tel" class="phone" autocomplete="tel">
          </div>
          <div class="form_inputs form_message">
            <label for="message">Message content:</label>
            <textarea id="message" class="message" maxlength="1000" autocomplete="off"></textarea>
            <div class="char_counter">0/1000</div>
          </div>
          <div class="button_container">
            <button type="submit">Send</button>
          </div>
        </form>          
      </div>
    `;   
  }
}

// Function for validate message form
function validateForm() {
  const fields = [
    { class: 'first_name', regex: /^[a-zA-Ząćęłńóśżź]{1,50}$/, error: 'Imię może zawierać tylko litery i maksymalnie 50 znaków.', errorANG: 'The name can contain only letters and a maximum of 50 characters.' },
    { class: 'last_name', regex: /^[a-zA-Ząćęłńóśżź]{1,50}$/, error: 'Nazwisko może zawierać tylko litery i maksymalnie 50 znaków.', errorANG: 'The last name can contain only letters and a maximum of 50 characters.' },
    { class: 'email', regex: /^[^\s@]+@[^\s@]+\.[^\s@]+$/, error: 'Wprowadź poprawny adres email.', errorANG: 'Please enter a valid email address.' },
    { class: 'phone', regex: /^\d{3} ?\d{3} ?\d{3}$/, error: 'Numer telefonu musi zawierać 9 cyfr.', errorANG: 'The phone number must contain 9 digits.' },
    { class: 'message', regex: /^.{1,1000}$/, error: 'Treść wiadomości nie może być pusta i musi zawierać maksymalnie 1000 znaków.', errorANG: 'The message body cannot be empty and must contain a maximum of 1000 characters.' }
  ];

  const isPolish = get_language();

  let isValid = true;

  fields.forEach(field => {
    const input = document.querySelector(`.${field.class}`);
    const errorElement = document.querySelector(`.${field.class}_error`);

    input.style.border = '';
    if (errorElement) {
      errorElement.remove();
    }

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
  });

  return isValid;
}

// Function to save form data to localStorage
function saveMessage(message) {
  messages.push(message);
  localStorage.setItem('messages', JSON.stringify(messages));
}

// Function for messaging

function message(event) {
  const charCounter = document.querySelector('.char_counter');

  event.preventDefault();

  const isPolish = get_language();

  if (validateForm()) {
    const message = {
      first_name: document.querySelector('.first_name').value.trim(),
      last_name: document.querySelector('.last_name').value.trim(),
      email: document.querySelector('.email').value.trim(),
      phone: document.querySelector('.phone').value.trim(),
      message: document.querySelector('.message').value.trim()
    };

    saveMessage(message);

    if (isPolish) {
      alert('Twoja wiadomość została wysłana pomyślnie!');
    } else {
      alert('Your message was sent successfully!');
    }

    this.reset();
    charCounter.textContent = '0/1000';
    window.location.href = '../HTML/inteligentny_zakup_biletu.html';
  }
}

document.addEventListener('DOMContentLoaded', () => {

  updateContent();

  // Counter for message
  const messageField = document.querySelector('.message');
  const charCounter = document.querySelector('.char_counter');

  messageField.addEventListener('input', () => {
    const currentLength = messageField.value.length;
    charCounter.textContent = `${currentLength}/1000`;
  });

    // Attach event listener to the form
  document.querySelector('.contact_form').addEventListener('submit', message);
});