-- Ilośc kont na klienta

SELECT client_id , COUNT(account_id) FROM Client_account GROUP BY client_id;

-- Suma wszystkich środków na wszystkich kontach klienta

SELECT Client_account.client_id , SUM(Account.balance) FROM Account INNER JOIN Client_account ON Account.account_id = Client_account.account_id GROUP BY Client_account.client_id;

-- Suma wszystkich środków na wszystkich kontach klienta, pokazuję większe niż 100 k tylko

SELECT Client_account.client_id , SUM(Account.balance) FROM Account INNER JOIN Client_account ON Account.account_id = Client_account.account_id GROUP BY Client_account.client_id HAVING SUM(Account.balance) > 100000;

-- Pokazuje tranzakcje które są większe niż średnia kwota tranzakcji

SELECT * FROM Transaction WHERE amount > (SELECT AVG(amount) FROM Transaction);

-- Pokazuje sumę tranzakcji które są większe niż średnia kwota tranzakcji

SELECT SUM(amount) FROM Transaction WHERE amount > (SELECT AVG(amount) FROM Transaction);


