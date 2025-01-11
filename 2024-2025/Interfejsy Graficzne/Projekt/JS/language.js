// Website language support
document.addEventListener("DOMContentLoaded", () => {
    const languageChangeButton = document.querySelector(".language_change");

    if (localStorage.getItem("language") === null) {
        localStorage.setItem("language", "true");
    }

    const updateLanguageIcon = () => {
        const isPolish = localStorage.getItem("language") === "true";
        const imagePath = isPolish ? "../IMAGES/flaga_UK.png" : "../IMAGES/flaga_PL.png";
        languageChangeButton.innerHTML = `<img src="${imagePath}" alt="Flag Icon" class="flag_uk"/>`;
    };

    languageChangeButton.addEventListener("click", () => {
        const isPolish = localStorage.getItem("language") === "true";
        localStorage.setItem("language", (!isPolish).toString());
        location.reload();
    });

    updateLanguageIcon();
});