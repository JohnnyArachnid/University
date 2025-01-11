function renderContentPolish() {
    const contentContainer = document.querySelector('.content-policy');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <p>Polityka prywatności</p>
            <div class="div_content_container">
                <ol>
                    <li>Administrator danych osobowych<br>
                    Administratorem Twoich danych osobowych jest [Nazwa firmy], z siedzibą w [Adres firmy], wpisana do rejestru pod numerem [Numer rejestracyjny/NIP]. W sprawach związanych z ochroną danych osobowych możesz skontaktować się z nami pod adresem e-mail: [Adres e-mail].
                    </li>
                    <li>Zakres i cel przetwarzania danych osobowych<br>
                    Przetwarzamy dane osobowe użytkowników w celu realizacji sprzedaży biletów komunikacji miejskiej za pośrednictwem naszej strony internetowej. Dane, które zbieramy, obejmują:
                    <ul>
                        <li>Imię i nazwisko w celu identyfikacji użytkownika.</li>
                        <li>Adres e-mail w celu przesłania potwierdzenia zakupu i biletu elektronicznego.</li>
                        <li>Dane płatności w celu realizacji płatności za bilety.</li>
                        <li>Dane logowania jeśli zakładasz konto na naszej stronie, przetwarzamy login i hasło.</li>
                    </ul>
                    </li>
                    <li>Przetwarzanie danych osobowych jest niezbędne do:
                    <ul>
                        <li>Wypełnienia obowiązków prawnych (art. 6 ust. 1 lit. b i RODO).</li>
                        <li>Realizacji umowy sprzedaży biletów (art. 6 ust. 1 lit. b RODO).</li>
                        <li>Realizacji uzasadnionych interesów administratora, np. analiza sprzedaży, działania marketingowe (art. 6 ust. 1 lit. f RODO).</li>
                    </ul>
                    </li>
                    <li>Nie profilujemy użytkowników, ale możemy korzystać z technologii w celu:
                    <ul>
                        <li>Analizy ruchu na stronie i optymalizacji funkcjonalności.</li>
                        <li>Personalizacji treści reklamowych i marketingowych.</li>
                        <li>Możesz zablokować lub usunąć pliki cookie w swojej przeglądarce internetowej lub zaakceptować wyświetlania spersonalizowanych reklam na naszej stronie.</li>
                    </ul>
                    </li>
                    <li>Przekazywanie danych osobowych<br>
                    Twoje dane osobowe mogą być przekazywane następującym podmiotom:
                    <ul>
                        <li>Firmom obsługującym płatności (np. zewnętrzna operatora płatności)  w celu realizacji płatności.</li>
                        <li>Firmom zajmującym się analizą ruchu na stronie i marketingu (np. Google Analytics, Facebook Pixel).</li>
                        <li>Twoje dane mogą być przekazywane do krajów spoza Europejskiego Obszaru Gospodarczego (EOG) bez stosownych zabezpieczeń.</li>
                    </ul>
                    </li>
                    <li>Okres przechowywania danych<br>
                    Twoje dane osobowe będą przechowywane przez okres niezbędny do realizacji zamówienia i spełnienia wymogów prawnych. Dane związane z kontem użytkownika przechowywane są do czasu usunięcia konta lub wycofania zgody na ich przetwarzanie, o ile nie jest to sprzeczne z przepisami prawa.
                    </li>
                    <li>Prawa użytkowników<br>
                    W związku z przetwarzaniem danych osobowych użytkownicy mają prawo do:
                    <ul>
                        <li>Dostępu do swoich danych oraz uzyskania ich kopii.</li>
                        <li>Sprostowania danych.</li>
                        <li>Usunięcia danych (prawo do bycia zapomnianym).</li>
                        <li>Ograniczenia przetwarzania danych.</li>
                        <li>Przenoszenia danych.</li>
                        <li>Wniesienia sprzeciwu wobec przetwarzania danych.</li>
                        <li>Wniesienia skargi do organu nadzorczego.</li>
                    </ul>
                    </li>
                    <li>Kontakt<br>
                    W przypadku pytań lub wątpliwości dotyczących ochrony danych osobowych prosimy o kontakt pod adresem e-mail: [Adres e-mail].
                    </li>
                    <li>Zmiany w polityce prywatności<br>
                    Zastrzegamy sobie prawo do wprowadzania zmian w niniejszej polityce prywatności. Wszelkie zmiany będą publikowane na naszej stronie.
                    </li>
                </ol>
            </div>
        `;  
    }
}

function renderContentEnglish() {
    const contentContainer = document.querySelector('.content-policy');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <p>Privacy Policy</p>
            <div class="div_content_container">
                <ol>
                    <li>Personal Data Administrator<br>
                        The administrator of your personal data is [Company Name], based in [Company Address], entered in the register under the number [Registration Number/NIP]. In matters related to the protection of personal data, you can contact us at the following e-mail address: [E-mail Address].
                    </li>
                    <li>Scope and purpose of personal data processing<br>
                    We process users' personal data in order to sell public transport tickets via our website. The data we collect includes:
                        <ul>
                            <li>Name and surname to identify the user.</li>
                            <li>E-mail address to send purchase confirmation and e-ticket.</li>
                            <li>Payment data to process payment for tickets.</li>
                            <li>Login data if you create an account on our website, we process the login and password.</li>
                        </ul>
                    </li>
                    <li>The processing of personal data is necessary for:
                        <ul>
                            <li>Fulfillment of legal obligations (Article 6 paragraph 1 letter b and GDPR).</li>
                            <li>Performance of the ticket sales contract (Article 6 paragraph 1 letter b GDPR).</li>
                            <li>Pursuit of the legitimate interests of the administrator, e.g. sales analysis, marketing activities (Article 6 paragraph 1 letter f GDPR).</li>
                        </ul>
                    </li>
                    <li>We do not profile users, but we may use technology to:
                        <ul>
                            <li>Analysis of website traffic and optimization of functionality.</li>
                            <li>Personalization of advertising and marketing content.</li>
                            <li>You can block or delete cookies in your web browser or accept the display of personalized ads on our website.</li>
                        </ul>
                    </li>
                    <li>Transfer of personal data<br>
                    Your personal data may be transferred to the following entities:
                        <ul>
                            <li>Payment service companies (e.g. external payment service provider) for the purpose of payment processing.</li>
                            <li>Companies involved in website traffic analysis and marketing (e.g. Google Analytics, Facebook Pixel).</li>
                            <li>Your data may be transferred to countries outside the European Economic Area (EEA) without appropriate safeguards.</li>
                        </ul>
                    </li>
                    <li>Data storage period<br>
                    Your personal data will be stored for the period necessary to complete the order and meet legal requirements. Data related to the user account is stored until the account is deleted or consent to its processing is withdrawn, unless this is contrary to the provisions of law.
                    </li>
                    <li>User rights<br>
                    In connection with the processing of personal data, users have the right to:
                        <ul>
                            <li>Access their data and obtain a copy of it.</li>
                            <li>Correct the data.</li>
                            <li>Delete the data (right to be forgotten).</li>
                            <li>Restrict data processing.</li>
                            <li>Transfer the data.</li>
                            <li>Object to data processing.</li>
                            <li>File a complaint with the supervisory authority.</li>
                        </ul>
                    </li>
                    <li>Contact<br>
                    In case of questions or concerns regarding the protection of personal data, please contact us at the following e-mail address: [E-mail address].
                    </li>
                    <li>Changes to the Privacy Policy<br>
                    We reserve the right to make changes to this privacy policy. Any changes will be posted on our website.
                    </li>
                </ol>
            </div>
        `;   
    }
}

document.addEventListener('DOMContentLoaded', updateContent);