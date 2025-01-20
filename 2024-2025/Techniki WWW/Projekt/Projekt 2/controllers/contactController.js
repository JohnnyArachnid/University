const Contact_message = require('../models/Contact_message');

exports.getContactSite = (req, res, next) => {
    try {
        const lang = req.currentLang;
        res.render('subpages/contact', { 
            currentLang: lang, 
            errors: {}, 
            values: {}, 
            success: false
        });
    } catch (error) {
        console.error('Error rendering contact page:', error);
        next(error);
    }
};

exports.submitContactSite = async (req, res, next) => {
    try {
        const { first_name, last_name, email, phone, message } = req.body;
        const errors = {};
        const values = { first_name, last_name, email, phone, message };
        const lang = req.currentLang;

        if (!/^[a-zA-Ząćęłńóśżź]{1,50}$/.test(first_name)) {
            errors.first_name = 'Imię może zawierać tylko litery i maksymalnie 50 znaków.';
            errors.first_name_ang = 'First name can contain only letters and a maximum of 50 characters.';
        }
        if (!/^[a-zA-Ząćęłńóśżź]{1,50}$/.test(last_name)) {
            errors.last_name = 'Nazwisko może zawierać tylko litery i maksymalnie 50 znaków.';
            errors.last_name_ang = 'Last name can contain only letters and a maximum of 50 characters.';
        }
        if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email)) {
            errors.email = 'Wprowadź poprawny adres email.';
            errors.email_ang = 'Please enter a valid email address.';
        }
        if (!/^\d{3} ?\d{3} ?\d{3}$/.test(phone)) {
            errors.phone = 'Numer telefonu musi zawierać tylko 9 cyfr.';
            errors.phone_ang = 'The telephone number must contain only 9 digits.';
        }
        if (!message || message.length > 1000) {
            errors.message = 'Treść wiadomości nie może być pusta i musi zawierać maksymalnie 1000 znaków.';
            errors.message_ang = 'The message body cannot be empty and must contain a maximum of 1000 characters.';
        }

        if (Object.keys(errors).length > 0) {
            return res.render('subpages/contact', {
                currentLang: lang,
                errors,
                values,
                success: false
            });
        }

        await Contact_message.create({
            first_name,
            last_name,
            email,
            phone,
            message,
        });

        res.render('subpages/contact', {
            currentLang: lang,
            errors: {},
            values: {},
            success: true
        });
    } catch (error) {
        console.error('Error submitting contact form:', error);
        next(error);
    }
};