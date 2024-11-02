SELECT Account.*
FROM Account
LEFT JOIN Client_account ON Account.account_id = Client_account.account_id
WHERE Client_account.client_id IS NULL;