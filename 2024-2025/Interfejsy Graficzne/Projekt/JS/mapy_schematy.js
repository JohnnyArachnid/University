function createModal() {
    const modal = document.createElement('div');
    modal.className = 'image_modal';

    const img = document.createElement('img');
    img.className = 'modal_image';

    const closeButton = document.createElement('div');
    closeButton.className = 'close_button';
    closeButton.textContent = 'X';

    closeButton.addEventListener('click', () => modal.remove());
    modal.addEventListener('click', (e) => {
        if (e.target === modal) modal.remove();
    });

    modal.appendChild(img);
    modal.appendChild(closeButton);
    document.body.appendChild(modal);
    return img;
}

function addModal(event) {
    event.preventDefault();
    const imgSrc = event.currentTarget.closest('.image_item').querySelector('img').src;
    const modalImage = document.querySelector('.modal_image') || createModal();
    modalImage.src = imgSrc;
}

function renderContentPolish() {
    const contentContainer = document.querySelector('.div_content_container');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <div class="image_item">
                <p>STREFY BILETOWE KRAKOWA</p>
                <img src="../IMAGES/zdjecie1.png" alt="Strefy Biletowe Krakowa" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>LINIE NOCNE</p>
                <img src="../IMAGES/zdjecie2.png" alt="Linie nocne" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>LINIE AGLOMERACYJNE</p>
                <img src="../IMAGES/zdjecie3.png" alt="Linie aglomeracyjne" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>TRANSPORT PUBLICZNY</p>
                <img src="../IMAGES/zdjecie4.png" alt="Transport publiczny" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>LINIE TRAMWAJOWE</p>
                <img src="../IMAGES/zdjecie5.png" alt="Linie tramwajowe" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>LINIE TRAMWAJOWE - ZMIANY CZASOWE</p>
                <img src="../IMAGES/zdjecie6.png" alt="Linie tramwajowe - zmiany czasowe" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
        `;   
    }
}

function renderContentEnglish() {
    const contentContainer = document.querySelector('.div_content_container');

    if (contentContainer) {
        contentContainer.innerHTML = `
            <div class="image_item">
                <p>CRACOW TICKET ZONES</p>
                <img src="../IMAGES/zdjecie1.png" alt="Krakow Ticket Zones" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>NIGHT LINES</p>
                <img src="../IMAGES/zdjecie2.png" alt="Night lines" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>AGGLOMERATION LINES</p>
                <img src="../IMAGES/zdjecie3.png" alt="Agglomeration lines" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>PUBLIC TRANSPORT</p>
                <img src="../IMAGES/zdjecie4.png" alt="Public transport" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>TRAM LINES</p>
                <img src="../IMAGES/zdjecie5.png" alt="Tram lines" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
            <div class="image_item">
                <p>TRAM LINES - TIME CHANGES</p>
                <img src="../IMAGES/zdjecie6.png" alt="Tram lines - time changes" />
                <div class="zoom_icon">
                    <img src="../IMAGES/zoom_icon.png" class="icon" alt="Zoom Icon">
                </div>
            </div>
        `;   
    }
}

document.addEventListener('DOMContentLoaded', () => {

    updateContent();

    // Adding functionality to zoom
    document.querySelectorAll('.zoom_icon .icon').forEach((icon) => {
        icon.addEventListener('click', addModal);
    });
});
