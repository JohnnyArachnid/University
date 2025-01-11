// Users
const users = JSON.parse(localStorage.getItem('users')) || [];

// Messages
const messages = JSON.parse(localStorage.getItem('messages')) || [];

// Base Tickets
const base_tickets = [
    {
        id: 1,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 60,
        price: 6,
    },
    {
        id: 2,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 60,
        price: 3,
    },
    {
        id: 3,
        client_type: 'normalny',
        quantity_type: 'grupowy',
        client_type_ang: 'regular',
        quantity_type_ang: 'group',
        family: false,
        ticket_type: 'MPK',
        zone: 'first',
        travel_time: 60,
        price: 50,
    },
    {
        id: 4,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 20,
        price: 4,
    },
    {
        id: 5,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 20,
        price: 2,
    },
    {
        id: 6,
        client_type: 'ulgowy',
        quantity_type: 'grupowy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'group',
        family: false,
        ticket_type: 'MPK',
        zone: 'first',
        travel_time: 60,
        price: 25,
    },
    {
        id: 7,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 90,
        price: 8,
    },
    {
        id: 8,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 90,
        price: 4,
    },
    {
        id: 9,
        client_type: 'normalny',
        quantity_type: 'grupowy',
        client_type_ang: 'regular',
        quantity_type_ang: 'group',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 60,
        price: 60,
    },
    {
        id: 10,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'first',
        travel_time: 1440,
        price: 17,
    },
    {
        id: 11,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'first',
        travel_time: 1440,
        price: 8.50,
    },
    {
        id: 12,
        client_type: 'ulgowy',
        quantity_type: 'grupowy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'group',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 60,
        price: 30,
    },
    {
        id: 13,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 1440,
        price: 22,
    },
    {
        id: 14,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 1440,
        price: 11,
    },
    {
        id: 15,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK_KMŁ',
        zone: 'all',
        travel_time: 70,
        price: 7,
    },
    {
        id: 16,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 2880,
        price: 35,
    },
    {
        id: 17,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 2880,
        price: 17.50,
    },
    {
        id: 18,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 4320,
        price: 50,
    },
    {
        id: 19,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 4320,
        price: 25,
    },
    {
        id: 20,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'first',
        travel_time: 10080,
        price: 56,
    },
    {
        id: 21,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'first',
        travel_time: 10080,
        price: 28,
    },
    {
        id: 22,
        client_type: 'normalny',
        quantity_type: 'pojedynczy',
        client_type_ang: 'regular',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 10080,
        price: 68,
    },
    {
        id: 23,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 10080,
        price: 34,
    },
    {
        id: 24,
        client_type: 'ulgowy',
        quantity_type: 'pojedynczy',
        client_type_ang: 'reduced',
        quantity_type_ang: 'single',
        family: false,
        ticket_type: 'MPK_KMŁ',
        zone: 'all',
        travel_time: 70,
        price: 3.50,
    },
    {
        id: 25,
        client_type: 'normalny',
        quantity_type: 'grupowy',
        client_type_ang: 'regular',
        quantity_type_ang: 'group',
        family: true,
        ticket_type: 'MPK',
        zone: 'all',
        travel_time: 4320,
        price: 100,
    },
];

// Public transport lines shorted
const shortPublicTransportLines = [ 'Wawel 01', 'Informatyczny 01', 'Salwator 01', 'Mistrzejowice 01', 'Klawiaturowa 01', 'Nowa Huta 01', 'Kurdwanów 01', 'Monitorowa 01', 'Ruczaj 01', 'Balice Lotnisko 01', 'Kablowa 01', 'Bitowa 01', 'Graficzna 01', 'Rondo Grzegórzeckie 01', 'Krowodrza Górka 01', 'Wieliczka 01', 'Tyniec 01', 'Mogilska 01' ];

function ticket_name_change(ticket_string) {
    const first_letter = ticket_string[0].toUpperCase();
    const rest_of_text = ticket_string.slice(1);
    return first_letter + rest_of_text; 
}

// Downloanding current language
function get_language() {
    if (localStorage.getItem("language") === null) {
        localStorage.setItem("language", "true");
    }
    return localStorage.getItem("language") === "true";
}

// Function to produce ticket names
function ticket_name(ticket, language) {
    let zone;
    let name;
    let quantity_type;
    const isPolish = language === 'polish'
    if (isPolish) {
        zone = ticket.zone === 'first' ? 'Strefa 1' : 'Strefa 1 + 2 + 3';
        name = ticket_name_change(ticket.client_type);
        quantity_type = ticket_name_change(ticket.quantity_type);
    } else {
        zone = ticket.zone === 'first' ? 'Zone 1' : 'Zone 1 + 2 + 3';
        name = ticket_name_change(ticket.client_type_ang);
        quantity_type = ticket_name_change(ticket.quantity_type_ang);
    }
    let time;
    if (ticket.travel_time == 1440) {
        time = '24 h';
    } else if (ticket.travel_time == 2880) {
        time = '48 h';
    } else if (ticket.travel_time == 4320) {
        time = '72 h';
    } else if (ticket.travel_time == 10080) {
        if (isPolish) {
            time = '7 dni';
        } else {
            time = '7 days';
        }
    } else {
        if (isPolish) {
            time = `${ticket.travel_time} minut`;
        } else {
            time = `${ticket.travel_time} minutes`;
        }
    }
    return `${name} ${time} ${zone} ${quantity_type}`;
}

// Update tickets with names
const tickets = base_tickets.map(ticket => ({
    ...ticket,
    name: ticket_name(ticket, 'polish'),
    name_ang: ticket_name(ticket, 'english'),
}));

// Choosen tickets to buy
const selectedTicketsToBuy = JSON.parse(localStorage.getItem('selectedTicketsToBuy')) || [];

// Public transport lines
const publicTransportLines = [
    {
        id: 1,
        number_of_line: 1,
        vehicle_type: 'tram',
        directions: [
            {
                id: 1,
                destination: 'Wawel - Salwator',
                route: 'Wawel 01, Informatyczny 01, Salwator 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Wawel 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: [ '10', '30', '50' ] },
                                    { id: 2, hour: '11', minutes: [ '10', '30', '50' ] },
                                    { id: 3, hour: '16', minutes: [ '10', '20', '30', '40', '50' ] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '4', minutes: [ '15', '35', '55' ] },
                                    { id: 2, hour: '11', minutes: [ '15', '35', '55' ] },
                                    { id: 3, hour: '16', minutes: [ '05', '25', '45' ] }
                                ],
                                sundays: [
                                    { id: 1, hour: '4', minutes: [ '20', '40' ] },
                                    { id: 2, hour: '11', minutes: [ '00', '20', '40' ] },
                                    { id: 3, hour: '16', minutes: [ '10', '30', '50' ] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Informatyczny 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: [ '13', '33', '53' ] },
                                    { id: 2, hour: '11', minutes: [ '13', '33', '53' ] },
                                    { id: 3, hour: '16', minutes: [ '13', '23', '33', '43', '53' ] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '4', minutes: [ '18', '38', '58' ] },
                                    { id: 2, hour: '11', minutes: [ '18', '38', '58' ] },
                                    { id: 3, hour: '16', minutes: [ '08', '28', '48' ] }
                                ],
                                sundays: [
                                    { id: 1, hour: '4', minutes: [ '23', '43' ] },
                                    { id: 2, hour: '11', minutes: [ '03', '23', '43' ] },
                                    { id: 3, hour: '16', minutes: [ '13', '33', '53' ] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Salwator 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: [ '17', '37', '57' ] },
                                    { id: 2, hour: '11', minutes: [ '17', '37', '57' ] },
                                    { id: 3, hour: '16', minutes: [ '17', '27', '37', '47', '57' ] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '4', minutes: [ '22', '42', '59' ] },
                                    { id: 2, hour: '11', minutes: [ '22', '42', '59' ] },
                                    { id: 3, hour: '16', minutes: [ '12', '32', '52' ] }
                                ],
                                sundays: [
                                    { id: 1, hour: '4', minutes: [ '27', '47' ] },
                                    { id: 2, hour: '11', minutes: [ '07', '27', '47' ] },
                                    { id: 3, hour: '16', minutes: [ '17', '37', '57' ] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Salwator - Wawel',
                route: 'Salwator 01, Informatyczny 01, Wawel 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Salwator 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: [ '05', '25', '45' ] },
                                    { id: 2, hour: '11', minutes: [ '05', '25', '45' ] },
                                    { id: 3, hour: '16', minutes: [ '05', '15', '25', '35', '45' ] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '4', minutes: [ '10', '30', '50' ] },
                                    { id: 2, hour: '11', minutes: [ '10', '30', '50' ] },
                                    { id: 3, hour: '16', minutes: [ '00', '20', '40' ] }
                                ],
                                sundays: [
                                    { id: 1, hour: '4', minutes: [ '15', '35' ] },
                                    { id: 2, hour: '11', minutes: [ '05', '25', '45' ] },
                                    { id: 3, hour: '16', minutes: [ '15', '35', '55' ] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Informatyczny 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: [ '08', '28', '48' ] },
                                    { id: 2, hour: '11', minutes: [ '08', '28', '48' ] },
                                    { id: 3, hour: '16', minutes: [ '08', '18', '28', '38', '48' ] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '4', minutes: [ '13', '33', '53' ] },
                                    { id: 2, hour: '11', minutes: [ '13', '33', '53' ] },
                                    { id: 3, hour: '16', minutes: [ '03', '23', '43' ] }
                                ],
                                sundays: [
                                    { id: 1, hour: '4', minutes: [ '18', '38' ] },
                                    { id: 2, hour: '11', minutes: [ '08', '28', '48' ] },
                                    { id: 3, hour: '16', minutes: [ '08', '28', '48' ] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Wawel 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: [ '12', '32', '52' ] },
                                    { id: 2, hour: '11', minutes: [ '12', '32', '52' ] },
                                    { id: 3, hour: '16', minutes: [ '12', '22', '32', '42', '52' ] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '4', minutes: [ '17', '37', '57' ] },
                                    { id: 2, hour: '11', minutes: [ '17', '37', '57' ] },
                                    { id: 3, hour: '16', minutes: [ '07', '27', '47' ] }
                                ],
                                sundays: [
                                    { id: 1, hour: '4', minutes: [ '22', '42' ] },
                                    { id: 2, hour: '11', minutes: [ '10', '30', '50' ] },
                                    { id: 3, hour: '16', minutes: [ '12', '32', '52' ] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 2,
        number_of_line: 2,
        vehicle_type: 'tram',
        directions: [
            {
                id: 1,
                destination: 'Mistrzejowice - Nowa Huta',
                route: 'Mistrzejowice 01, Klawiaturowa 01, Nowa Huta 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Mistrzejowice 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Klawiaturowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '12', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '14', minutes: ['25', '45', '45'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Nowa Huta 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['25', '45', '05'] },
                                    { id: 2, hour: '12', minutes: ['25', '45', '05'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Nowa Huta - Mistrzejowice',
                route: 'Nowa Huta 01, Klawiaturowa 01, Mistrzejowice 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Nowa Huta 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['25', '45', '05'] },
                                    { id: 2, hour: '12', minutes: ['25', '45', '05'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Klawiaturowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '12', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '15', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Mistrzejowice 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 3,
        number_of_line: 3,
        vehicle_type: 'tram',
        directions: [
            {
                id: 1,
                destination: 'Kurdwanów - Ruczaj',
                route: 'Kurdwanów 01, Monitorowa 01, Ruczaj 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Kurdwanów 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Monitorowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Ruczaj 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['40', '00', '20'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['40', '00', '20'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Ruczaj - Kurdwanów',
                route: 'Ruczaj 01, Monitorowa 01, Kurdwanów 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Ruczaj 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '23', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Monitorowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Kurdwanów 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['40', '00', '20'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['50', '10', '30'] },
                                    { id: 3, hour: '23', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 4,
        number_of_line: 4,
        vehicle_type: 'tram',
        directions: [
            {
                id: 1,
                destination: 'Balice Lotnisko - Wawel',
                route: 'Balice Lotnisko 01, Kablowa 01, Wawel 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Balice Lotnisko 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Kablowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Wawel 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Wawel - Balice Lotnisko',
                route: 'Wawel 01, Kablowa 01, Balice Lotnisko 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Wawel 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '22', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Kablowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['12', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Balice Lotnisko 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['02', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 5,
        number_of_line: 5,
        vehicle_type: 'tram',
        directions: [
            {
                id: 1,
                destination: 'Bitowa - Graficzna',
                route: 'Bitowa 01, Klawiaturowa 01, Graficzna 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Bitowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Klawiaturowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Graficzna 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Graficzna - Bitowa',
                route: 'Graficzna 01, Klawiaturowa 01, Bitowa 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Graficzna 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '21', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Klawiaturowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['01', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Bitowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['11', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 6,
        number_of_line: 101,
        vehicle_type: 'bus',
        directions: [
            {
                id: 1,
                destination: 'Rondo Grzegórzeckie - Salwator',
                route: 'Rondo Grzegórzeckie 01, Klawiaturowa 01, Salwator 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Rondo Grzegórzeckie 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '11', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '18', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Klawiaturowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: ['19', '39', '59'] },
                                    { id: 2, hour: '11', minutes: ['09', '29', '49'] },
                                    { id: 3, hour: '18', minutes: ['04', '24', '44'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '5', minutes: ['14', '34', '54'] },
                                    { id: 2, hour: '15', minutes: ['19', '39', '59'] },
                                    { id: 3, hour: '20', minutes: ['14', '34', '54'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '6', minutes: ['04', '24', '44'] },
                                    { id: 2, hour: '16', minutes: ['09', '29', '49'] },
                                    { id: 3, hour: '21', minutes: ['14', '34', '54'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Salwator 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: ['05', '25', '45'] },
                                    { id: 2, hour: '11', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '5', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Salwator - Rondo Grzegórzeckie',
                route: 'Salwator 01, Klawiaturowa 01, Rondo Grzegórzeckie 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Salwator 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: ['05', '25', '45'] },
                                    { id: 2, hour: '12', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '5', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['25', '45', '05'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Klawiaturowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: ['19', '39', '59'] },
                                    { id: 2, hour: '12', minutes: ['09', '29', '49'] },
                                    { id: 3, hour: '18', minutes: ['04', '24', '44'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '5', minutes: ['14', '34', '54'] },
                                    { id: 2, hour: '14', minutes: ['19', '39', '59'] },
                                    { id: 3, hour: '20', minutes: ['14', '34', '54'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '6', minutes: ['04', '24', '44'] },
                                    { id: 2, hour: '16', minutes: ['09', '29', '49'] },
                                    { id: 3, hour: '21', minutes: ['14', '34', '54'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Rondo Grzegórzeckie 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '4', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '12', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '18', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 7,
        number_of_line: 102,
        vehicle_type: 'bus',
        directions: [
            {
                id: 1,
                destination: 'Nowa Huta - Bitowa',
                route: 'Nowa Huta 01, Graficzna 01, Bitowa 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Nowa Huta 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['15', '35', '55'] },
                                    { id: 2, hour: '14', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['05', '25', '45'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Graficzna 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Bitowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Bitowa - Nowa Huta',
                route: 'Bitowa 01, Graficzna 01, Nowa Huta 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Bitowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['05', '25', '45'] },
                                    { id: 2, hour: '15', minutes: ['15', '35', '55'] },
                                    { id: 3, hour: '22', minutes: ['05', '25', '45'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '23', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Graficzna 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['05', '25', '45'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '16', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '23', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Nowa Huta 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40']  },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '16', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '23', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 8,
        number_of_line: 201,
        vehicle_type: 'bus',
        directions: [
            {
                id: 1,
                destination: 'Balice Lotnisko - Krowodrza Górka',
                route: 'Balice Lotnisko 01, Bitowa 01, Krowodrza Górka 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Balice Lotnisko 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Bitowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40']  },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['40', '00', '20'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40']  },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Krowodrza Górka 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Krowodrza Górka - Balice Lotnisko',
                route: 'Krowodrza Górka 01, Bitowa 01, Balice Lotnisko 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Krowodrza Górka 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '9', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Bitowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '9', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['40', '00', '20'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Balice Lotnisko 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '9', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 9,
        number_of_line: 301,
        vehicle_type: 'bus',
        directions: [
            {
                id: 1,
                destination: 'Wieliczka - Tyniec',
                route: 'Wieliczka 01, Graficzna 01, Tyniec 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Wieliczka 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['50', '10', '30'] },
                                    { id: 2, hour: '11', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '17', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Graficzna 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['40', '00', '20'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Tyniec 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Tyniec - Wieliczka',
                route: 'Tyniec 01, Graficzna 01, Wieliczka 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Tyniec 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '12', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Graficzna 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '12', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['40', '00', '20'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 1,
                        name_of_station: 'Wieliczka 01',
                        zone: 'all',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '5', minutes: ['50', '10', '30'] },
                                    { id: 2, hour: '11', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '17', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '6', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '18', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
    {
        id: 10,
        number_of_line: 302,
        vehicle_type: 'bus',
        directions: [
            {
                id: 1,
                destination: 'Mogilska - Monitorowa',
                route: 'Mogilska 01, Nowa Huta 01, Monitorowa 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Mogilska 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Nowa Huta 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['40', '00', '20'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '21', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Monitorowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '21', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    }
                ]
            },
            {
                id: 2,
                destination: 'Monitorowa - Mogilska',
                route: 'Monitorowa 01, Nowa Huta 01, Mogilska 01',
                lines: [
                    {
                        id: 1,
                        name_of_station: 'Monitorowa 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 2,
                        name_of_station: 'Nowa Huta 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '13', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '19', minutes: ['10', '30', '50'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '14', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '20', minutes: ['40', '00', '20'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '15', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '22', minutes: ['10', '30', '50'] }
                                ]
                            }
                        ]
                    },
                    {
                        id: 3,
                        name_of_station: 'Mogilska 01',
                        zone: 'first',
                        time_table: [
                            {
                                normal_days: [
                                    { id: 1, hour: '7', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '13', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '19', minutes: ['00', '20', '40'] }
                                ],
                                saturdays: [
                                    { id: 1, hour: '8', minutes: ['10', '30', '50'] },
                                    { id: 2, hour: '14', minutes: ['00', '20', '40'] },
                                    { id: 3, hour: '20', minutes: ['10', '30', '50'] }
                                ],
                                sundays: [
                                    { id: 1, hour: '9', minutes: ['00', '20', '40'] },
                                    { id: 2, hour: '15', minutes: ['10', '30', '50'] },
                                    { id: 3, hour: '22', minutes: ['00', '20', '40'] }
                                ]
                            }
                        ]
                    }
                ]
            }
        ]
    },
];
