document.addEventListener('DOMContentLoaded', () => {
    document.querySelectorAll('.resetButtonClass').forEach(button => {
        button.addEventListener('click', function() {
            window.location.href = '/';
        });
    });
});