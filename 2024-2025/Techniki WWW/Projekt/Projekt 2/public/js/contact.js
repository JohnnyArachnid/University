document.getElementById('message').addEventListener('input', () => {
    const messageInput = document.getElementById('message');
    const charCounter = document.querySelector('.charCounter');
    const maxMessageLength = 1000;
    const currentLength = messageInput.value.length;
    charCounter.textContent = `${currentLength}/${maxMessageLength}`;
    if (currentLength > maxMessageLength || currentLength < 0) {
        charCounter.classList.add('text-danger');
    } else {
        charCounter.classList.remove('text-danger');
    }
});

document.getElementById('resetButton').addEventListener('click', function() {
    window.location.href = '/subpages/contact';
});