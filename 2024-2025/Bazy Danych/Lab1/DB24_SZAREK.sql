-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Czas generowania: 18 Paź 2024, 11:10
-- Wersja serwera: 8.0.39-0ubuntu0.22.04.1
-- Wersja PHP: 8.1.2-1ubuntu2.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `DB24_SZAREK`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Account`
--

CREATE TABLE `Account` (
  `account_id` int NOT NULL,
  `currency_name` enum('PLN','USD','EUR','GBP','CHF') DEFAULT 'PLN',
  `account_type` enum('Personal','Savings','Currency','Company','Eldery','Youth') DEFAULT 'Personal',
  `balance` decimal(15,2) DEFAULT '0.00',
  `creation_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Zrzut danych tabeli `Account`
--

INSERT INTO `Account` (`account_id`, `currency_name`, `account_type`, `balance`, `creation_date`) VALUES
(1, 'PLN', 'Personal', '1000.00', '2021-01-01'),
(2, 'EUR', 'Savings', '2000.00', '2021-02-01'),
(3, 'USD', 'Currency', '3000.00', '2021-03-01'),
(4, 'GBP', 'Company', '4000.00', '2021-04-01'),
(5, 'CHF', 'Personal', '5000.00', '2021-05-01'),
(6, 'PLN', 'Eldery', '6000.00', '2021-06-01'),
(7, 'PLN', 'Youth', '7000.00', '2021-07-01'),
(8, 'EUR', 'Savings', '8000.00', '2021-08-01'),
(9, 'USD', 'Currency', '9000.00', '2021-09-01'),
(10, 'GBP', 'Company', '10000.00', '2021-10-01'),
(11, 'CHF', 'Personal', '11000.00', '2021-11-01'),
(12, 'PLN', 'Eldery', '12000.00', '2021-12-01'),
(13, 'PLN', 'Youth', '13000.00', '2022-01-01'),
(14, 'EUR', 'Savings', '14000.00', '2022-02-01'),
(15, 'USD', 'Currency', '15000.00', '2022-03-01'),
(16, 'GBP', 'Company', '16000.00', '2022-04-01'),
(17, 'CHF', 'Personal', '17000.00', '2022-05-01'),
(18, 'PLN', 'Eldery', '18000.00', '2022-06-01'),
(19, 'PLN', 'Youth', '19000.00', '2022-07-01'),
(20, 'EUR', 'Savings', '20000.00', '2022-08-01');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Bank_instance`
--

CREATE TABLE `Bank_instance` (
  `bank_instance_id` int NOT NULL,
  `number_of_workers` int NOT NULL,
  `online_support` tinyint(1) DEFAULT '1',
  `is_open_on_weekend` tinyint(1) DEFAULT '1',
  `localization_id` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Zrzut danych tabeli `Bank_instance`
--

INSERT INTO `Bank_instance` (`bank_instance_id`, `number_of_workers`, `online_support`, `is_open_on_weekend`, `localization_id`) VALUES
(1, 50, 1, 1, 1),
(2, 35, 1, 0, 2),
(3, 45, 1, 1, 3),
(4, 80, 0, 1, 4),
(5, 60, 1, 0, 5),
(6, 75, 1, 1, 6),
(7, 55, 1, 0, 7),
(8, 40, 0, 1, 8),
(9, 90, 1, 0, 9),
(10, 30, 1, 1, 10),
(11, 65, 1, 0, 11),
(12, 50, 1, 1, 12),
(13, 70, 0, 1, 13),
(14, 85, 1, 0, 14),
(15, 55, 1, 1, 15),
(16, 40, 0, 1, 16),
(17, 60, 1, 0, 17),
(18, 35, 1, 1, 18),
(19, 75, 0, 1, 19),
(20, 50, 1, 0, 20);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Card`
--

CREATE TABLE `Card` (
  `card_id` int NOT NULL,
  `style` enum('Basic','Striped','Dotted','Personalized') DEFAULT 'Basic',
  `card_number` char(16) NOT NULL,
  `svd` char(3) NOT NULL,
  `expire_date` date NOT NULL,
  `account_id` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Zrzut danych tabeli `Card`
--

INSERT INTO `Card` (`card_id`, `style`, `card_number`, `svd`, `expire_date`, `account_id`) VALUES
(1, 'Basic', '1234567812345672', '123', '2026-01-01', 1),
(2, 'Striped', '2345678923456789', '234', '2026-02-01', 2),
(3, 'Dotted', '3456789034567890', '345', '2026-03-01', 3),
(4, 'Personalized', '4567890145678901', '456', '2026-04-01', 4),
(5, 'Basic', '5678901256789012', '567', '2026-05-01', 5),
(6, 'Striped', '6789012367890123', '678', '2026-06-01', 6),
(7, 'Dotted', '7890123478901234', '789', '2026-07-01', 7),
(8, 'Personalized', '8901234589012345', '890', '2026-08-01', 8),
(9, 'Basic', '9012345690123456', '901', '2026-09-01', 9),
(10, 'Striped', '0123456701234567', '012', '2026-10-01', 10),
(11, 'Dotted', '1234567812345678', '123', '2026-11-01', 11),
(12, 'Personalized', '2345678923456781', '234', '2026-12-01', 12),
(13, 'Basic', '3456789034567891', '345', '2027-01-01', 13),
(14, 'Striped', '4567890145678902', '456', '2027-02-01', 14),
(15, 'Dotted', '5678901256789011', '567', '2027-03-01', 15),
(16, 'Personalized', '6789012367890122', '678', '2027-04-01', 16),
(17, 'Basic', '7890123478901231', '789', '2027-05-01', 17),
(18, 'Striped', '8901234589012342', '890', '2027-06-01', 18),
(19, 'Dotted', '9012345690123451', '901', '2027-07-01', 19),
(20, 'Personalized', '0123456701234561', '012', '2027-08-01', 20);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Client`
--

CREATE TABLE `Client` (
  `client_id` int NOT NULL,
  `first_name` varchar(50) NOT NULL,
  `last_name` varchar(50) NOT NULL,
  `pesel` char(11) NOT NULL,
  `phone_number` char(9) NOT NULL,
  `email_address` varchar(100) NOT NULL,
  `nationality` varchar(50) NOT NULL,
  `primary_bank_instance_id` int DEFAULT NULL,
  `residential_address_id` int DEFAULT NULL,
  `correspondance_address_id` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Zrzut danych tabeli `Client`
--

INSERT INTO `Client` (`client_id`, `first_name`, `last_name`, `pesel`, `phone_number`, `email_address`, `nationality`, `primary_bank_instance_id`, `residential_address_id`, `correspondance_address_id`) VALUES
(1, 'Jan', 'Kowalski', '90010112345', '600123123', 'jan.kowalski@gmail.com', 'Polish', 1, 1, 1),
(2, 'Anna', 'Nowak', '80010254321', '600987651', 'anna.nowak@yahoo.com', 'Polish', 2, 2, 2),
(3, 'John', 'Smith', '79020165432', '500321321', 'john.smith@hotmail.com', 'British', 6, 6, 6),
(4, 'Maria', 'Garcia', '81030376543', '700456789', 'maria.garcia@outlook.com', 'Spanish', 7, 7, 7),
(5, 'Jean', 'Dupont', '70040487654', '800654987', 'jean.dupont@orange.fr', 'French', 5, 5, 5),
(6, 'Hans', 'Muller', '69050598765', '900789123', 'hans.muller@gmail.de', 'German', 4, 4, 4),
(7, 'Emma', 'Brown', '89060619876', '700123456', 'emma.brown@bt.co.uk', 'British', 6, 6, 6),
(8, 'Luca', 'Rossi', '85070720987', '600321654', 'luca.rossi@libero.it', 'Italian', 8, 8, 8),
(9, 'Olga', 'Petrova', '92080832098', '500456789', 'olga.petrova@yandex.ru', 'Russian', 13, 13, 13),
(10, 'David', 'Lee', '81090943109', '700654321', 'david.lee@gmail.com', 'American', 9, 9, 9),
(11, 'Anna', 'Johnson', '99010112312', '500321654', 'anna.johnson@outlook.com', 'Canadian', 10, 10, 10),
(12, 'Erik', 'Larsson', '90020223423', '800987321', 'erik.larsson@telia.se', 'Swedish', 17, 17, 17),
(13, 'Nina', 'Mikhailova', '91030354321', '600654987', 'nina.mikhailova@mail.ru', 'Russian', 13, 13, 13),
(14, 'Tom', 'Wright', '80040487654', '700321987', 'tom.wright@bt.co.uk', 'British', 6, 6, 6),
(15, 'Sophia', 'Williams', '75050598765', '900789456', 'sophia.williams@outlook.com', 'American', 9, 9, 9),
(16, 'Isabelle', 'Martin', '89060619875', '800123789', 'isabelle.martin@orange.fr', 'French', 5, 5, 5),
(17, 'Pablo', 'Rodriguez', '85070720981', '600321456', 'pablo.rodriguez@gmail.com', 'Spanish', 7, 7, 7),
(18, 'Nils', 'Olsen', '94080832098', '500654123', 'nils.olsen@telenor.no', 'Norwegian', 18, 18, 18),
(19, 'Martina', 'Kovacs', '81090943102', '600987654', 'martina.kovacs@freemail.hu', 'Hungarian', 12, 12, 12),
(20, 'Victor', 'Dumont', '87010198765', '500789321', 'victor.dumont@gmail.com', 'Belgian', 16, 16, 16);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Client_account`
--

CREATE TABLE `Client_account` (
  `client_id` int NOT NULL,
  `account_id` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Zrzut danych tabeli `Client_account`
--

INSERT INTO `Client_account` (`client_id`, `account_id`) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5),
(6, 6),
(7, 7),
(8, 8),
(9, 9),
(10, 10),
(11, 11),
(12, 12),
(13, 13),
(14, 14),
(15, 15),
(16, 16),
(17, 17),
(18, 18),
(19, 19),
(20, 20);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Localization`
--

CREATE TABLE `Localization` (
  `localization_id` int NOT NULL,
  `country` varchar(50) NOT NULL,
  `city` varchar(50) DEFAULT NULL,
  `street` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Zrzut danych tabeli `Localization`
--

INSERT INTO `Localization` (`localization_id`, `country`, `city`, `street`) VALUES
(1, 'Poland', 'Warsaw', 'Main St 1'),
(2, 'Poland', 'Krakow', 'River St 5'),
(3, 'Poland', 'Gdansk', 'Ocean St 3'),
(4, 'Germany', 'Berlin', 'Alexanderplatz 10'),
(5, 'France', 'Paris', 'Rue de Rivoli 15'),
(6, 'UK', 'London', 'Baker St 221B'),
(7, 'Spain', 'Madrid', 'Gran Via 8'),
(8, 'Italy', 'Rome', 'Via Condotti 12'),
(9, 'USA', 'New York', '5th Avenue 102'),
(10, 'Canada', 'Toronto', 'Queen St 200'),
(11, 'Poland', 'Wroclaw', 'Market Square 2'),
(12, 'Poland', 'Poznan', 'King St 7'),
(13, 'Russia', 'Moscow', 'Red Square 1'),
(14, 'Ukraine', 'Kyiv', 'Independence Sq 14'),
(15, 'Netherlands', 'Amsterdam', 'Dam Square 3'),
(16, 'Belgium', 'Brussels', 'Rue Neuve 9'),
(17, 'Sweden', 'Stockholm', 'Vasagatan 2'),
(18, 'Norway', 'Oslo', 'Karl Johans Gate 17'),
(19, 'Denmark', 'Copenhagen', 'Strøget 11'),
(20, 'Finland', 'Helsinki', 'Mannerheimintie 18');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Transaction`
--

CREATE TABLE `Transaction` (
  `transaction_id` int NOT NULL,
  `from_account` int DEFAULT NULL,
  `to_account` varchar(50) NOT NULL,
  `transaction_type` enum('Standard','Payments','Standard ELIXIR','Quick ELIXIR','Phone','Foreign') DEFAULT 'Standard',
  `amount` decimal(15,2) DEFAULT '0.00',
  `transaction_date` date NOT NULL,
  `posting_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Zrzut danych tabeli `Transaction`
--

INSERT INTO `Transaction` (`transaction_id`, `from_account`, `to_account`, `transaction_type`, `amount`, `transaction_date`, `posting_date`) VALUES
(1, 1, '2', 'Standard', '100.00', '2023-01-01', '2023-01-02'),
(2, 2, '3', 'Payments', '200.00', '2023-02-01', '2023-02-02'),
(3, 3, '4', 'Standard ELIXIR', '300.00', '2023-03-01', '2023-03-02'),
(4, 4, '5', 'Quick ELIXIR', '400.00', '2023-04-01', '2023-04-02'),
(5, 5, '6', 'Phone', '500.00', '2023-05-01', '2023-05-02'),
(6, 6, '7', 'Foreign', '600.00', '2023-06-01', '2023-06-02'),
(7, 7, '8', 'Standard', '700.00', '2023-07-01', '2023-07-02'),
(8, 8, '9', 'Payments', '800.00', '2023-08-01', '2023-08-02'),
(9, 9, '10', 'Standard ELIXIR', '900.00', '2023-09-01', '2023-09-02'),
(10, 10, '11', 'Quick ELIXIR', '1000.00', '2023-10-01', '2023-10-02'),
(11, 11, '12', 'Phone', '1100.00', '2023-11-01', '2023-11-02'),
(12, 12, '13', 'Foreign', '1200.00', '2023-12-01', '2023-12-02'),
(13, 13, '14', 'Standard', '1300.00', '2024-01-01', '2024-01-02'),
(14, 14, '15', 'Payments', '1400.00', '2024-02-01', '2024-02-02'),
(15, 15, '16', 'Standard ELIXIR', '1500.00', '2024-03-01', '2024-03-02'),
(16, 16, '17', 'Quick ELIXIR', '1600.00', '2024-04-01', '2024-04-02'),
(17, 17, '18', 'Phone', '1700.00', '2024-05-01', '2024-05-02'),
(18, 18, '19', 'Foreign', '1800.00', '2024-06-01', '2024-06-02'),
(19, 19, '20', 'Standard', '1900.00', '2024-07-01', '2024-07-02'),
(20, 20, '1', 'Payments', '2000.00', '2024-08-01', '2024-08-02');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `Account`
--
ALTER TABLE `Account`
  ADD PRIMARY KEY (`account_id`);

--
-- Indeksy dla tabeli `Bank_instance`
--
ALTER TABLE `Bank_instance`
  ADD PRIMARY KEY (`bank_instance_id`),
  ADD KEY `localization_id` (`localization_id`);

--
-- Indeksy dla tabeli `Card`
--
ALTER TABLE `Card`
  ADD PRIMARY KEY (`card_id`),
  ADD UNIQUE KEY `card_number` (`card_number`),
  ADD KEY `account_id` (`account_id`);

--
-- Indeksy dla tabeli `Client`
--
ALTER TABLE `Client`
  ADD PRIMARY KEY (`client_id`),
  ADD UNIQUE KEY `pesel` (`pesel`),
  ADD UNIQUE KEY `phone_number` (`phone_number`),
  ADD UNIQUE KEY `email_address` (`email_address`),
  ADD KEY `primary_bank_instance_id` (`primary_bank_instance_id`),
  ADD KEY `residential_address_id` (`residential_address_id`),
  ADD KEY `correspondance_address_id` (`correspondance_address_id`);

--
-- Indeksy dla tabeli `Client_account`
--
ALTER TABLE `Client_account`
  ADD PRIMARY KEY (`client_id`,`account_id`),
  ADD KEY `account_id` (`account_id`);

--
-- Indeksy dla tabeli `Localization`
--
ALTER TABLE `Localization`
  ADD PRIMARY KEY (`localization_id`);

--
-- Indeksy dla tabeli `Transaction`
--
ALTER TABLE `Transaction`
  ADD PRIMARY KEY (`transaction_id`),
  ADD KEY `from_account` (`from_account`);

--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `Bank_instance`
--
ALTER TABLE `Bank_instance`
  ADD CONSTRAINT `Bank_instance_ibfk_1` FOREIGN KEY (`localization_id`) REFERENCES `Localization` (`localization_id`);

--
-- Ograniczenia dla tabeli `Card`
--
ALTER TABLE `Card`
  ADD CONSTRAINT `Card_ibfk_1` FOREIGN KEY (`account_id`) REFERENCES `Account` (`account_id`);

--
-- Ograniczenia dla tabeli `Client`
--
ALTER TABLE `Client`
  ADD CONSTRAINT `Client_ibfk_1` FOREIGN KEY (`primary_bank_instance_id`) REFERENCES `Bank_instance` (`bank_instance_id`),
  ADD CONSTRAINT `Client_ibfk_2` FOREIGN KEY (`residential_address_id`) REFERENCES `Localization` (`localization_id`),
  ADD CONSTRAINT `Client_ibfk_3` FOREIGN KEY (`correspondance_address_id`) REFERENCES `Localization` (`localization_id`);

--
-- Ograniczenia dla tabeli `Client_account`
--
ALTER TABLE `Client_account`
  ADD CONSTRAINT `Client_account_ibfk_1` FOREIGN KEY (`client_id`) REFERENCES `Client` (`client_id`),
  ADD CONSTRAINT `Client_account_ibfk_2` FOREIGN KEY (`account_id`) REFERENCES `Account` (`account_id`);

--
-- Ograniczenia dla tabeli `Transaction`
--
ALTER TABLE `Transaction`
  ADD CONSTRAINT `Transaction_ibfk_1` FOREIGN KEY (`from_account`) REFERENCES `Account` (`account_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
