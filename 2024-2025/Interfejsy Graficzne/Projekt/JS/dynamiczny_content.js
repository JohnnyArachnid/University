// Dynamicly rendering whether user isn't logged 
function renderUnauthorized() {
    const contentContainer = document.querySelector('.div_content_container');
    const contentContainerPlatnosci = document.querySelector('.div_content_container_platnosci');
    const isPolish = get_language();
    language_validation(isPolish);


    if (contentContainer && isPolish) {
        contentContainer.innerHTML = `
        <div id="unauthorized-section">
            <h2>Brak dostępu!</h2>
        </div>
    `;
    } else if (contentContainerPlatnosci && isPolish) {
        contentContainerPlatnosci.innerHTML = `
        <div id="unauthorized-section">
            <h2>Brak dostępu!</h2>
        </div>`
        ;
    } else if (contentContainer && !isPolish) {
        contentContainer.innerHTML = `
        <div id="unauthorized-section">
            <h2>No access!</h2>
        </div>
    `;
    } else if (contentContainerPlatnosci && !isPolish) {
        contentContainerPlatnosci.innerHTML = `
        <div id="unauthorized-section">
            <h2>No access!</h2>
        </div>`
        ;
    }
};

// Dynamicly rendering whether user is logged 
function updateContentLogin() {
    const loggedInUser = users.find(user => user.is_logged_in);
    const isPolish = get_language();
    language_validation(isPolish);
    if (loggedInUser) {
        renderAuthorized(loggedInUser);
    } else {
        renderUnauthorized();
    }
}

// Dynamicly rendering whether there are tickets in backet
function updateContentBacket() {
    const loggedInUser = users.find(user => user.is_logged_in);
    const currentBasket = getCurrentBasket();
    const isPolish = get_language();
    language_validation(isPolish);
    if (currentBasket.length > 0) {
        if (loggedInUser) {
            renderAuthorized(loggedInUser);
        }
        else {
            renderUnauthorizedWithTickets();
        }
    } else {
        renderUnauthorized();
    }
}

function updateContent() {
    const isPolish = get_language();
    language_validation(isPolish);
    if (isPolish) {
        renderContentPolish();
        renderPolish();
    } else {
        renderContentEnglish();
        renderEnglish();
    }
}

function renderPolish() {
    const footerSocial = document.querySelector(".social");

    if (footerSocial) {
        footerSocial.innerHTML = `
            <a href="./polityka_prywatnosci.html">Polityka prywatności</a>
            <a href="./skontaktuj_sie_z_nami.html">Skontaktuj się z nami</a>
            <a href="https://x.com/?lang=pl&mx=2" class="icons" target="_blank"><img src="../IMAGES/twitter.png" alt="X" class="flag_uk" /></a>
            <a href="https://www.instagram.com/" class="icons" target="_blank"><img src="../IMAGES/instagram.png" alt="Instagram" class="flag_uk" /></a>
            <a href="https://www.facebook.com/" class="icons" target="_blank" target="_blank"><img src="../IMAGES/facebook.png" alt="Facebook" class="flag_uk" /></a>
        `;
    }
}

function renderEnglish() {
    const footerSocial = document.querySelector(".social");

    if (footerSocial) {
        footerSocial.innerHTML = `
            <a href="./polityka_prywatnosci.html">Privacy Policy</a>
            <a href="./skontaktuj_sie_z_nami.html">Contact us</a>
            <a href="https://x.com/?lang=pl&mx=2" class="icons" target="_blank"><img src="../IMAGES/twitter.png" alt="X" class="flag_uk" /></a>
            <a href="https://www.instagram.com/" class="icons" target="_blank"><img src="../IMAGES/instagram.png" alt="Instagram" class="flag_uk" /></a>
            <a href="https://www.facebook.com/" class="icons" target="_blank" target="_blank"><img src="../IMAGES/facebook.png" alt="Facebook" class="flag_uk" /></a>
        `;
    }
}