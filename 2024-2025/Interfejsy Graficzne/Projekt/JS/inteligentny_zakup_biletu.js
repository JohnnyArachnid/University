function renderContentPolish() {
    const contentContainer = document.querySelector('.div_content_container');

    if (contentContainer) {
        contentContainer.innerHTML = `
        <form id="travel-form">
          <div class="station-input">
            <label for="start-station">Przystanek Początkowy:</label>
            <input type="text" id="start-station" name="start-station" autocomplete="off" placeholder="Wprowadź przystanek" />
            <button type="button" id="swap-stations">⟲</button>
            <ul class="suggestions" id="start-suggestions"></ul>
          </div>

          <div id="intermediate-stations-container">
            <!-- Intermediate stations will be added dynamically here -->
          </div>
      
          <div class="station-input">
            <label for="end-station">Przystanek Końcowy:</label>
            <input type="text" id="end-station" name="end-station" autocomplete="off" placeholder="Wprowadź przystanek" />
            <ul class="suggestions" id="end-suggestions"></ul>
          </div>
          <div id="buttons">
            <button type="button" class="icon" id="add-intermediate-station">+</button>
            <p>Dodaj<br>przystanek<br>pośredni</p>
            <button type="button" id="set-date">Wybierz Datę</button>
            <button type="button" id="set-time">Wybierz Godzinę</button>
          </div>
          <div class="selected-values">
            <p id="selected-date">Wybrana Data: Brak Wybranej Daty</p>
            <p id="selected-time">Wybrana Godzina: Brak Wybranej Godziny</p>
          </div>
      
          <button type="submit" id="search_ticket_button">Wyszukaj Bilet</button>
        </form>
        `;   

        document.getElementById('date-modal-description').textContent = `Wybierz Datę`;
        document.getElementById('close-date-modal').textContent = `Zamknij`;
        document.getElementById('time-modal-description').textContent = `Wybierz Godzinę`;
        document.getElementById('close-time-modal').textContent = `Zamknij`;
    }
}

function renderContentEnglish() {
    const contentContainer = document.querySelector('.div_content_container');

    if (contentContainer) {
        contentContainer.innerHTML = `
        <form id="travel-form">
          <div class="station-input">
            <label for="start-station">Starting Stop:</label>
            <input type="text" id="start-station" name="start-station" autocomplete="off" placeholder="Enter stop" />
            <button type="button" id="swap-stations">⟲</button>
            <ul class="suggestions" id="start-suggestions"></ul>
          </div>

          <div id="intermediate-stations-container">
            <!-- Intermediate stations will be added dynamically here -->
          </div>
      
          <div class="station-input">
            <label for="end-station">Ending Stop:</label>
            <input type="text" id="end-station" name="end-station" autocomplete="off" placeholder="Enter stop" />
            <ul class="suggestions" id="end-suggestions"></ul>
          </div>
          <div id="buttons">
            <button type="button" class="icon" id="add-intermediate-station">+</button>
            <p>Add<br>intermediate<br>stop</p>
            <button type="button" id="set-date">Select Date</button>
            <button type="button" id="set-time">Select Hour</button>
          </div>
          <div class="selected-values">
            <p id="selected-date">Selected Date: No Selected Date</p>
            <p id="selected-time">Selected Hour: No Selected Hour</p>
          </div>
      
          <button type="submit" id="search_ticket_button">Search Ticket</button>
        </form>
        `;
        
        document.getElementById('date-modal-description').textContent = `Pick Date`;
        document.getElementById('close-date-modal').textContent = `Close`;
        document.getElementById('time-modal-description').textContent = `Pick Hour`;
        document.getElementById('close-time-modal').textContent = `Close`;
    }
}

function setupAutoComplete(input, suggestionsBox) {
    input.addEventListener('input', () => {
      const query = input.value.toLowerCase();
      const matches = shortPublicTransportLines
        .filter(line => line.toLowerCase().includes(query))
        .slice(0, 3);
  
      suggestionsBox.innerHTML = '';
      suggestionsBox.style.display = matches.length ? 'block' : 'none';
  
      matches.forEach(match => {
        const li = document.createElement('li');
        li.textContent = match;
        li.addEventListener('click', () => {
          input.value = match;
          suggestionsBox.style.display = 'none';
        });
        suggestionsBox.appendChild(li);
      });
    });
  }
  
  function setupModal(triggerButton, modal, closeButton, onSelect) {
    triggerButton.addEventListener('click', () => {
      modal.style.display = 'flex';
    });
  
    closeButton.addEventListener('click', () => {
      modal.style.display = 'none';
      if (onSelect) onSelect();
    });
  }
  
  function addIntermediateStation(container) {
    if (container.childElementCount >= 1) {
      alert('Można dodać maksymalnie jeden przystanek pośredni.');
      return;
    }
  
    const div = document.createElement('div');
    div.className = 'station-input intermediate-station';
    const isPolish = get_language();
    if (isPolish) {
        div.innerHTML = `
        <label for="between-station">Przystanek Pośredni:</label>
        <input type="text" id="between-station" name="between-station" placeholder="Wprowadź przystanek" autocomplete="off" />
        <ul class="suggestions"></ul>
        <button type="button" class="remove-station">X</button>
        `;
        container.appendChild(div);
    } else {
        div.innerHTML = `
        <label for="between-station">Intermediate Stop:</label>
        <input type="text" id="between-station" name="between-station" placeholder="Enter stop" autocomplete="off" />
        <ul class="suggestions"></ul>
        <button type="button" class="remove-station">X</button>
        `;
        container.appendChild(div);
    }
  
    const input = div.querySelector('input');
    const suggestionsBox = div.querySelector('.suggestions');
    setupAutoComplete(input, suggestionsBox);
  
    div.querySelector('.remove-station').addEventListener('click', () => {
      div.remove();
    });
  }
  
  function swapStations() {
    const startInput = document.getElementById('start-station');
    const endInput = document.getElementById('end-station');
    const temp = startInput.value;
    startInput.value = endInput.value;
    endInput.value = temp;
  }
  
  document.addEventListener('DOMContentLoaded', () => {

    updateContent();

    let finalTime;
    let finalDate;

    const setDefaultDateTime = () => {
        const now = new Date();
        const formattedDate = now.toISOString().split('T')[0];
        const formattedTime = now.toTimeString().slice(0, 8);

        const isPolish = get_language();

        finalDate = formattedDate;
        finalTime = formattedTime;

        if (isPolish) {
            document.getElementById('selected-date').textContent = `Wybrana Data: ${formattedDate}`;
            document.getElementById('selected-time').textContent = `Wybrana Godzina: ${formattedTime}`;
        } else {
            document.getElementById('selected-date').textContent = `Selected Date: ${formattedDate}`;
            document.getElementById('selected-time').textContent = `Selected Hour: ${formattedTime}`;
        }
    };

    setDefaultDateTime();

    setupAutoComplete(document.getElementById('start-station'), document.getElementById('start-suggestions'));
    setupAutoComplete(document.getElementById('end-station'), document.getElementById('end-suggestions'));
    
    document.getElementById('add-intermediate-station').addEventListener('click', () => {
        addIntermediateStation(document.getElementById('intermediate-stations-container'));
    });
    
    document.getElementById('swap-stations').addEventListener('click', swapStations);
    
    setupModal(
        document.getElementById('set-date'),
        document.getElementById('date-modal'),
        document.getElementById('close-date-modal'),
        () => {
            const date = document.getElementById('date-picker').value;
            const isPolish = get_language();
            if (isPolish) {
                if (date) {
                    finalDate = date;
                    document.getElementById('selected-date').textContent = `Wybrana Data: ${date}`;
                }
            } else {
                if (date) {
                    finalDate = date;
                    document.getElementById('selected-date').textContent = `Selected Date: ${date}`;
                }
            }
        }
    );
    
    setupModal(
        document.getElementById('set-time'),
        document.getElementById('time-modal'),
        document.getElementById('close-time-modal'),
        () => {
            const time = document.getElementById('time-picker').value;
            const isPolish = get_language();
            if (isPolish) {
                if (time) {
                    finalTime = time;
                    document.getElementById('selected-time').textContent = `Wybrana Godzina: ${time}`;
                }
            } else {
                if (time) {
                    finalTime = time;
                    document.getElementById('selected-time').textContent = `Selected Hour: ${time}`;
                }
            }
        }
    );

    const searchButton = document.querySelector('#search_ticket_button');
    const container = document.querySelector('.div_content_container');
    const isPolish = get_language();

    const saveToLocalStorage = (data) => {
        localStorage.setItem('ticketData', JSON.stringify(data));
    };

    searchButton.addEventListener('click', (event) => {
        event.preventDefault();
        const startPoint = document.querySelector('#start-station').value || '';
        const endPoint = document.querySelector('#end-station').value || '';
        const travelDate = finalDate;
        const travelTime = finalTime;
        
        const intermediateStops = Array.from(document.querySelectorAll('.intermediate-station input'))
            .map(input => input.value)
            .filter(value => value);

        if (!startPoint || !endPoint || !travelDate || !travelTime) {
            if (isPolish) {
                alert("Proszę podać przystanek początkowy, przystanek końcowy, datę oraz godzinę.");
                return;
            } else {
                alert("Please provide the starting stop, ending stop, date and time.");
                return;
            }
        }

        const initialData = {
            startPoint,
            endPoint,
            travelDate,
            travelTime,
            intermediateStops
        };

        saveToLocalStorage(initialData);
        
        if (isPolish) {
            container.innerHTML = `
            <div class="ticket_selection">
                <div class="ticket_left">
                    <h2>Wybierz rodzaj oraz ilość biletów</h2>
                </div>
                <div class="ticket_right">
                    <div class="ticket_type">
                        <span>Bilet normalny</span>
                        <div class="ticket_counter">
                            <button class="decrement" data-type="normal">-</button>
                            <input type="number" class="ticket_input" data-type="normal" value="0" min="0" readonly />
                            <button class="increment" data-type="normal">+</button>
                        </div>
                    </div>
                    <div class="ticket_type">
                        <span>Bilet ulgowy</span>
                        <div class="ticket_counter">
                            <button class="decrement" data-type="discount">-</button>
                            <input type="number" class="ticket_input" data-type="discount" value="0" min="0" readonly />
                            <button class="increment" data-type="discount">+</button>
                        </div>
                    </div>
                    <button class="next_button">Dalej</button>
                </div>
            </div>
            `;
        } else {
            container.innerHTML = `
            <div class="ticket_selection">
                <div class="ticket_left">
                    <h2>Select the type and number of tickets</h2>
                </div>
                <div class="ticket_right">
                    <div class="ticket_type">
                        <span>Standard ticket</span>
                        <div class="ticket_counter">
                            <button class="decrement" data-type="normal">-</button>
                            <input type="number" class="ticket_input" data-type="normal" value="0" min="0" readonly />
                            <button class="increment" data-type="normal">+</button>
                        </div>
                    </div>
                    <div class="ticket_type">
                        <span>Reduced Ticket</span>
                        <div class="ticket_counter">
                            <button class="decrement" data-type="discount">-</button>
                            <input type="number" class="ticket_input" data-type="discount" value="0" min="0" readonly />
                            <button class="increment" data-type="discount">+</button>
                        </div>
                    </div>
                    <button class="next_button">Next</button>
                </div>
            </div>
            `;
        }

        const counters = container.querySelectorAll('.ticket_counter');
        counters.forEach(counter => {
            const decrement = counter.querySelector('.decrement');
            const increment = counter.querySelector('.increment');
            const input = counter.querySelector('.ticket_input');

            decrement.addEventListener('click', () => {
                let value = parseInt(input.value);
                if (value > 0) input.value = value - 1;
            });

            increment.addEventListener('click', () => {
                let value = parseInt(input.value);
                input.value = value + 1;
            });
        });

        const nextButton = container.querySelector('.next_button');
        nextButton.addEventListener('click', () => {
            const normalTickets = parseInt(container.querySelector('input[data-type="normal"]').value) || 0;
            const discountTickets = parseInt(container.querySelector('input[data-type="discount"]').value) || 0;

            if (normalTickets === 0 && discountTickets === 0) {
                if (isPolish) {
                    alert('Musisz wybrać przynajmniej jeden bilet!');
                    return;
                } else {
                    alert('You must select at least one ticket!');
                    return;
                }
            }

            const updatedData = {
                ...JSON.parse(localStorage.getItem('ticketData')),
                normalTickets,
                discountTickets
            };

            saveToLocalStorage(updatedData);

            const ticketData = JSON.parse(localStorage.getItem('ticketData'));
            let selectedDate;
            if (isPolish) {
                selectedDate = ticketData ? ticketData.travelDate : 'Brak wybranej daty';
            } else {
                selectedDate = ticketData ? ticketData.travelDate : 'No date selected';

            }
            const travelDate = new Date(ticketData.travelDate);
            const dayOfWeek = travelDate.getDay();
            let dayType = 'normal_days';
            if (dayOfWeek === 6) dayType = 'saturdays';
            if (dayOfWeek === 0) dayType = 'sundays';

            const availableConnections = [];

            publicTransportLines.forEach(line => {
                line.directions.forEach(direction => {
                    const routeStops = direction.route.split(', ');
                    const startIndex = routeStops.indexOf(ticketData.startPoint);
                    const endIndex = routeStops.indexOf(ticketData.endPoint);

                    if (startIndex !== -1 && endIndex !== -1 && startIndex < endIndex) {
                        const intermediateStops = ticketData.intermediateStops;
                        let validRoute = true;

                        if (intermediateStops.length > 0) {
                            const intermediateStopIndex = routeStops.indexOf(intermediateStops[0]);
                            if (intermediateStopIndex === -1 || intermediateStopIndex <= startIndex || intermediateStopIndex >= endIndex) {
                                validRoute = false;
                            }
                        }

                        if (validRoute) {
                                const stationBegining = direction.lines[startIndex].time_table[0][dayType];
                                stationBegining.forEach((schedule, index1) => {
                                    const hour = parseInt(schedule.hour);
                                    schedule.minutes.forEach((minute, index2) => {
                                        const departureTime = `${hour}:${minute}`;
                                        const arrivalTime = `${hour}:${direction.lines[endIndex].time_table[0][dayType][index1].minutes[index2]}`;
                                        const userTime = ticketData.travelTime.split(':').slice(0, 2).join(':');
                                        const departureTimeInMinutes = convertToMinutes(departureTime);
                                        const arrivalTimeInMinutes = convertToMinutes(arrivalTime);
                                        const userTimeInMinutes = convertToMinutes(userTime);
                                        let travelDuration;
                                        if (arrivalTimeInMinutes > departureTimeInMinutes) {
                                            travelDuration = arrivalTimeInMinutes - departureTimeInMinutes;
                                        } else {
                                            travelDuration = departureTimeInMinutes - arrivalTimeInMinutes;
                                        }
                                        const bestTicket = findBestTicketCombination(base_tickets, ticketData, travelDuration);

                                        if (departureTimeInMinutes >= userTimeInMinutes && departureTimeInMinutes <= arrivalTimeInMinutes) {
                                            availableConnections.push({
                                                departure: departureTime,
                                                departureTimeInMinutes: departureTimeInMinutes,
                                                arrival: arrivalTime,
                                                lineNumber: line.number_of_line,
                                                vehicleType: line.vehicle_type,
                                                route: direction.route,
                                                bestTicket
                                            });
                                        } else if  (departureTimeInMinutes >= userTimeInMinutes && departureTimeInMinutes > arrivalTimeInMinutes) {
                                            availableConnections.push({
                                                departure: arrivalTime,
                                                departureTimeInMinutes: arrivalTimeInMinutes,
                                                arrival: departureTime,
                                                lineNumber: line.number_of_line,
                                                vehicleType: line.vehicle_type,
                                                route: direction.route,
                                                bestTicket
                                            });
                                        }
                                    });
                                });
                            availableConnections.sort((a, b) => a.departureTimeInMinutes - b.departureTimeInMinutes);
                        }
                    }
                });
            });

            let currentFilter = 'quickest-filter';

            function showResult(filteredConnections = availableConnections) {
                const isPolish = get_language();
                if (filteredConnections.length > 0) {
                    if (isPolish) {
                        container.innerHTML = `
                        <div class="connections-list">
                            <h2>Lista połączeń</h2>
                            <p>Data podróży: ${selectedDate}</p>
                            <div class="filters">
                                <label class="radio"><input type="radio" name="filter" id="quickest-filter" ${currentFilter === 'quickest-filter' ? 'checked' : ''}> <span class="name">Najszybszy</span></label>
                                <label class="radio"><input type="radio" name="filter" id="shortest-filter" ${currentFilter === 'shortest-filter' ? 'checked' : ''}> <span class="name">Najkrótszy</span></label>
                                <label class="radio"><input type="radio" name="filter" id="cheapest-filter" ${currentFilter === 'cheapest-filter' ? 'checked' : ''}> <span class="name">Najtańszy</span></label>
                            </div>
                            
                            <div id="connections">${generateConnectionsHTML(filteredConnections)}</div>
                        </div>
                        `;
                    } else {
                        container.innerHTML = `
                        <div class="connections-list">
                            <h2>List of public transport connections</h2>
                            <p>Travel date: ${selectedDate}</p>
                            <div class="filters">
                                <label class="radio"><input type="radio" name="filter" id="quickest-filter" ${currentFilter === 'quickest-filter' ? 'checked' : ''}> <span class="name">The quickest</span></label>
                                <label class="radio"><input type="radio" name="filter" id="shortest-filter" ${currentFilter === 'shortest-filter' ? 'checked' : ''}> <span class="name">The shortest</span></label>
                                <label class="radio"><input type="radio" name="filter" id="cheapest-filter" ${currentFilter === 'cheapest-filter' ? 'checked' : ''}> <span class="name">The cheapest</span></label>
                            </div>
                            
                            <div id="connections">${generateConnectionsHTML(filteredConnections)}</div>
                        </div>
                        `;
                    }
                } else {
                    if (isPolish) {
                        container.innerHTML = `
                        <div class="connections-list">
                            <h2>Lista połączeń</h2>
                            <p>Data podróży: ${selectedDate}</p>
                            <p id="no-connections">Brak dostępnych połączeń dla wybranych przystanków.</p>
                            <button id="reset-webpage">Wyszukaj Ponownie</button>
                        </div>
                        `;
                    } else {
                        container.innerHTML = `
                        <div class="connections-list">
                            <h2>List of public transport connections</h2>
                            <p>Travel date: ${selectedDate}</p>
                            <p id="no-connections">No connections available for the selected stops.</p>
                            <button id="reset-webpage">Search Again</button>
                        </div>
                        `;
                    }

                    const resetButton = document.getElementById('reset-webpage');

                    if (resetButton) {
                        resetButton.addEventListener('click', () => {
                            location.reload();
                        });
                    }
                }

                document.querySelectorAll('input[name="filter"]').forEach(button => {
                    button.addEventListener('change', () => applyFilter(button.id));
                });

                const connectionElements = document.querySelectorAll('.connection');
                connectionElements.forEach((connectionElement, index) => {
                    connectionElement.addEventListener('click', () => {
                        const selectedConnection = filteredConnections[index];
                        showSummary(selectedConnection);
                    });
                });
            }

            function applyFilter(selectedFilter) {
                currentFilter = selectedFilter;

                let filteredConnections = [...availableConnections];
                switch (selectedFilter) {
                    case 'quickest-filter':
                        filteredConnections.sort((a, b) => a.departureTimeInMinutes - b.departureTimeInMinutes);
                        break;
                    case 'shortest-filter':
                        filteredConnections.sort((a, b) => {
                            const durationA = convertToMinutes(a.arrival) - convertToMinutes(a.departure);
                            const durationB = convertToMinutes(b.arrival) - convertToMinutes(b.departure);
                            return durationA - durationB;
                        });
                        break;
                    case 'cheapest-filter':
                        filteredConnections.sort((a, b) => a.bestTicket.totalCost - b.bestTicket.totalCost);
                        break;
                }

                showResult(filteredConnections);
            }

            showResult();

        });

        function capitalize(string) {
            if (!string || typeof string !== 'string') return string;
            return string.charAt(0).toUpperCase() + string.slice(1).toLowerCase();
        }

        function generateConnectionsHTML(connections) {
            return connections.map(connection => {
                const vehicleImage = connection.vehicleType === 'bus' ? '../IMAGES/bus_image.png' : '../IMAGES/tram_image.png';
                const isPolish = get_language();
                let result = ``;
                if (isPolish) {
                    const ticketDetails = connection.bestTicket.tickets.map(ticket => 
                        `${ticket.count} x ${capitalize(ticket.ticket.client_type)} (${capitalize(ticket.ticket.quantity_type)}) - ${ticket.ticket.price * ticket.count} zł`
                    ).join('<br>');
                    result = `
                    <div class="connection">
                        <p>Odjazd: ${connection.departure}</p>
                        <p>Przyjazd: ${connection.arrival}</p>
                        <p>Linia: ${connection.lineNumber} <img src="${vehicleImage}" alt="${connection.vehicleType}" class="vehicle-image" /></p>
                        <p>Trasa: ${connection.route}</p>
                        <p>Najlepszy bilet/ty:<br>${ticketDetails}</p>
                        <p>Łączny koszt: ${connection.bestTicket.totalCost} zł</p>
                    </div>
                    `;
                } else {
                    const ticketDetails = connection.bestTicket.tickets.map(ticket => 
                        `${ticket.count} x ${capitalize(ticket.ticket.client_type_ang)} (${capitalize(ticket.ticket.quantity_type_ang)}) - ${ticket.ticket.price * ticket.count} PLN`
                    ).join('<br>');
                    result = `
                    <div class="connection">
                        <p>Departure: ${connection.departure}</p>
                        <p>Arrival: ${connection.arrival}</p>
                        <p>Line: ${connection.lineNumber} <img src="${vehicleImage}" alt="${connection.vehicleType}" class="vehicle-image" /></p>
                        <p>Route: ${connection.route}</p>
                        <p>The best ticket/s:<br>${ticketDetails}</p>
                        <p>Total cost: ${connection.bestTicket.totalCost} PLN</p>
                    </div>
                    `;
                }
                return result;
            }).join('');
        }

        function convertToMinutes(time) {
            const [hours, minutes] = time.split(':').map(Number);
            return hours * 60 + minutes;
        }

        function findBestTicketCombination(baseTickets, ticketData, travelDuration) {
            const { normalTickets, discountTickets } = ticketData;
        
            function findCheapestTickets(tickets, travelDuration, ticketType) {
                const availableSingleTickets = tickets
                    .filter(ticket => ticket.travel_time >= travelDuration && ticket.quantity_type === 'pojedynczy' && ticket.client_type == ticketType)
                    .sort((a, b) => a.price - b.price);
        
                const availableGroupTickets = tickets
                    .filter(ticket => ticket.travel_time >= travelDuration && ticket.quantity_type === 'grupowy' && ticket.client_type == ticketType)
                    .sort((a, b) => a.price - b.price);
        
                const cheapestSingleTicket = availableSingleTickets[0] || null;
                const cheapestGroupTicket = availableGroupTickets[0] || null;
        
                return { cheapestSingleTicket, cheapestGroupTicket };
            }
        
            function generateBestCombination(ticketCount, cheapestSingleTicket, cheapestGroupTicket) {
                const combination = [];
                let remainingTickets = ticketCount;
            
                const maxGroupSize = 20;
            
                while (remainingTickets > 0) {
                    if (cheapestGroupTicket && remainingTickets >= 2) {
                        const groupPrice = cheapestGroupTicket.price;
                        const groupSize = Math.min(maxGroupSize, remainingTickets);
                        const singlePriceForGroupSize = cheapestSingleTicket.price * groupSize;
            
                        if (groupPrice < singlePriceForGroupSize) {
                            const ticketsNeeded = Math.floor(remainingTickets / maxGroupSize);
                            const groupTicketsCount = ticketsNeeded > 0 ? ticketsNeeded : 1;
                            const actualGroupSize = Math.min(maxGroupSize, remainingTickets);
            
                            const existingGroupTicket = combination.find(
                                (item) => item.ticket === cheapestGroupTicket
                            );
            
                            if (existingGroupTicket) {
                                existingGroupTicket.count += groupTicketsCount;
                            } else {
                                combination.push({
                                    ticket: cheapestGroupTicket,
                                    count: groupTicketsCount,
                                });
                            }
            
                            remainingTickets -= groupTicketsCount * actualGroupSize;
                            continue;
                        }
                    }
            
                    if (cheapestSingleTicket && remainingTickets > 0) {
                        const existingSingleTicket = combination.find(
                            (item) => item.ticket === cheapestSingleTicket
                        );
            
                        if (existingSingleTicket) {
                            existingSingleTicket.count += remainingTickets;
                        } else {
                            combination.push({
                                ticket: cheapestSingleTicket,
                                count: remainingTickets,
                            });
                        }
            
                        remainingTickets = 0;
                    }
                }
            
                return combination;
            }                                
        
            const normalTicketsList = findCheapestTickets(baseTickets, travelDuration, 'normalny');
            const discountTicketsList = findCheapestTickets(baseTickets, travelDuration, 'ulgowy');
        
            const normalCombination = generateBestCombination(normalTickets, normalTicketsList.cheapestSingleTicket, normalTicketsList.cheapestGroupTicket);
            const discountCombination = generateBestCombination(discountTickets, discountTicketsList.cheapestSingleTicket, discountTicketsList.cheapestGroupTicket);
        
            const allTickets = [...normalCombination, ...discountCombination];
        
            let totalCost = 0;
            allTickets.forEach(ticket => {
                totalCost += ticket.ticket.price * ticket.count;
            });
        
            return {
                tickets: allTickets,
                totalCost: totalCost
            };
        }        
    });
});

function showSummary(connection) {
    const container = document.querySelector('.div_content_container');
    const selectedTickets = connection.bestTicket.tickets;
    const isPolish = get_language();
    const ticketSummary = selectedTickets.map(ticketInfo => {
        const ticket = ticketInfo.ticket;
        const count = ticketInfo.count;
        let clientType;
        let ticketType;
        let ticketTimeLabel;
        let ticketZone;
        if (isPolish) {
            clientType = ticket.client_type.charAt(0).toUpperCase() + ticket.client_type.slice(1);
            ticketType = ticket.quantity_type.charAt(0).toUpperCase() + ticket.quantity_type.slice(1);
            ticketTimeLabel = ticket.travel_time === 1440
                ? '24 h'
                : ticket.travel_time === 2880
                ? '48 h'
                : ticket.travel_time === 4320
                ? '72 h'
                : ticket.travel_time === 10080
                ? '7 dni'
                : `${ticket.travel_time} minut`;

            ticketZone = ticket.zone === 'all' ? 'Strefa I + II + III' : 'Strefa I';
        } else {
            clientType = ticket.client_type_ang.charAt(0).toUpperCase() + ticket.client_type_ang.slice(1);
            ticketType = ticket.quantity_type_ang.charAt(0).toUpperCase() + ticket.quantity_type_ang.slice(1);
            ticketTimeLabel = ticket.travel_time === 1440
                ? '24 h'
                : ticket.travel_time === 2880
                ? '48 h'
                : ticket.travel_time === 4320
                ? '72 h'
                : ticket.travel_time === 10080
                ? '7 days'
                : `${ticket.travel_time} minutes`;

            ticketZone = ticket.zone === 'all' ? 'Zone I + II + III' : 'Zone I';
        }
        return `
            <div class="ticket-row">
                <span>${ticketType} - ${clientType}</span>
                <span>${ticketTimeLabel}</span>
                <span>${ticketZone}</span>
                <span>${ticket.price} PLN</span>
                <span>${count}</span>
                <span>${ticket.price * count} PLN</span>
            </div>
        `;
    }).join('');

    const totalPrice = selectedTickets.reduce((sum, ticketInfo) => {
        return sum + (ticketInfo.ticket.price * ticketInfo.count);
    }, 0);

    if (isPolish) {
        container.innerHTML = `
            <div class="summary-container">
                <div class="summary-left">
                    <h3>Twoje wybrane bilety</h3>
                </div>
                <div class="summary-right">
                    <div class="summary_opis">
                        <div class="summary_opis_title">Opis</div>
                        <div class="summary_opis_title">Czas</div>
                        <div class="summary_opis_title">Strefa</div>
                        <div class="summary_opis_title">Cena</div>
                        <div class="summary_opis_title">Ilość</div>
                        <div class="summary_opis_title">Suma</div>
                    </div>
                    ${ticketSummary}
                    <div class="total-price">Łączna cena: ${totalPrice} zł</div>
                    <div class="buttons_summary">
                        <div class="top_buttons">
                            <button id="reselect-button">Ponowne Inteligentne Wybranie Biletu</button>
                            <button id="add-to-cart-button">Dodaj do Koszyka</button>
                        </div>
                        <button id="proceed-to-payment-button">Przejdź do Płatności</button>
                    </div>
                </div>
            </div>
        `;
    } else {
        container.innerHTML = `
            <div class="summary-container">
                <div class="summary-left">
                    <h3>Your selected tickets</h3>
                </div>
                <div class="summary-right">
                    <div class="summary_opis">
                        <div class="summary_opis_title">Description</div>
                        <div class="summary_opis_title">Time</div>
                        <div class="summary_opis_title">Zone</div>
                        <div class="summary_opis_title">Price</div>
                        <div class="summary_opis_title">Amount</div>
                        <div class="summary_opis_title">Sum</div>
                    </div>
                    ${ticketSummary}
                    <div class="total-price">Total price: ${totalPrice} PLN</div>
                    <button id="reselect-button">Smart Ticket Reselection</button>
                    <button id="add-to-cart-button">Add to Cart</button>
                    <button id="proceed-to-payment-button">Go to Payments</button>
                </div>
            </div>
        `;
    }

    document.getElementById('reselect-button').addEventListener('click', () => {
        location.reload();
    });

    document.getElementById('add-to-cart-button').addEventListener('click', () => {
        const currentBasket = getCurrentBasket();
        const updatedBasket = selectedTickets
        .reduce((basket, ticketInfo) => {
            const ticket = ticketInfo.ticket;
            const count = ticketInfo.count;
            const existingTicket = basket.find(t => t.id === ticket.id);
            if (existingTicket) {
                existingTicket.quantity += count;
                existingTicket.sum_price = existingTicket.quantity * ticket.price;
            } else {
                basket.push({
                    ...ticket,
                    quantity: count,
                    sum_price: ticket.price * count
                });
            }
            return basket;
        }, [...currentBasket]);
        const basketSummary = connection.bestTicket.tickets.map(ticket => {
            const isPolish = get_language();
            let clientType;
            let ticketType;
            let ticketTimeLabel;
            if (isPolish) {
                clientType = ticket.ticket.client_type.charAt(0).toUpperCase() + ticket.ticket.client_type.slice(1);
                ticketType = ticket.ticket.quantity_type.charAt(0).toUpperCase() + ticket.ticket.quantity_type.slice(1);
                ticketTimeLabel = ticket.ticket.travel_time === 1440
                    ? '24 h'
                    : ticket.ticket.travel_time === 2880
                    ? '48 h'
                    : ticket.ticket.travel_time === 4320
                    ? '72 h'
                    : ticket.ticket.travel_time === 10080
                    ? '7 dni'
                    : `${ticket.ticket.travel_time} minut`;

                return `${ticketType} - ${clientType} - ${ticketTimeLabel} - ${ticket.ticket.price} zł - ${ticket.count} szt. - ${ticket.count * ticket.ticket.price} zł`;
            } else {
                clientType = ticket.ticket.client_type_ang.charAt(0).toUpperCase() + ticket.ticket.client_type_ang.slice(1);
                ticketType = ticket.ticket.quantity_type_ang.charAt(0).toUpperCase() + ticket.ticket.quantity_type_ang.slice(1);
                ticketTimeLabel = ticket.ticket.travel_time === 1440
                    ? '24 h'
                    : ticket.ticket.travel_time === 2880
                    ? '48 h'
                    : ticket.ticket.travel_time === 4320
                    ? '72 h'
                    : ticket.ticket.travel_time === 10080
                    ? '7 days'
                    : `${ticket.ticket.travel_time} minutes`;

                return `${ticketType} - ${clientType} - ${ticketTimeLabel} - ${ticket.ticket.price} PLN - ${ticket.count} pcs. - ${ticket.count * ticket.ticket.price} PLN`;
            }
        }).join('\n');
        saveCurrentBasket(updatedBasket);
        if (isPolish) {
            alert(`Przechodzimy do koszyka z wybranymi biletami:\n${basketSummary}`);
        } else {
            alert(`We go to the basket with selected tickets:\n${basketSummary}`);
        }
        window.location.href = './koszyk.html';
    });

    document.getElementById('proceed-to-payment-button').addEventListener('click', () => {
        const currentBasket = getCurrentBasket();
        const updatedBasket = selectedTickets
        .reduce((basket, ticketInfo) => {
            const ticket = ticketInfo.ticket;
            const count = ticketInfo.count;
            const existingTicket = basket.find(t => t.id === ticket.id);
            if (existingTicket) {
                existingTicket.quantity += count;
                existingTicket.sum_price = existingTicket.quantity * ticket.price;
            } else {
                basket.push({
                    ...ticket,
                    quantity: count,
                    sum_price: ticket.price * count
                });
            }
            return basket;
        }, [...currentBasket]);
        const basketSummary = updatedBasket.map(ticket => {
            const isPolish = get_language();
            let clientType;
            let ticketType;
            let ticketTimeLabel;
            if (isPolish) {
                clientType = ticket.client_type.charAt(0).toUpperCase() + ticket.client_type.slice(1);
                ticketType = ticket.quantity_type.charAt(0).toUpperCase() + ticket.quantity_type.slice(1);
                ticketTimeLabel = ticket.travel_time === 1440
                    ? '24 h'
                    : ticket.travel_time === 2880
                    ? '48 h'
                    : ticket.travel_time === 4320
                    ? '72 h'
                    : ticket.travel_time === 10080
                    ? '7 dni'
                    : `${ticket.travel_time} minut`;

                return `${ticketType} - ${clientType} - ${ticketTimeLabel} - ${ticket.price} zł - ${ticket.quantity} szt. - ${ticket.quantity * ticket.price} zł`;
            } else {
                clientType = ticket.client_type_ang.charAt(0).toUpperCase() + ticket.client_type_ang.slice(1);
                ticketType = ticket.quantity_type_ang.charAt(0).toUpperCase() + ticket.quantity_type_ang.slice(1);
                ticketTimeLabel = ticket.travel_time === 1440
                    ? '24 h'
                    : ticket.travel_time === 2880
                    ? '48 h'
                    : ticket.travel_time === 4320
                    ? '72 h'
                    : ticket.travel_time === 10080
                    ? '7 days'
                    : `${ticket.travel_time} minutes`;

                return `${ticketType} - ${clientType} - ${ticketTimeLabel} - ${ticket.price} PLN - ${ticket.quantity} pcs. - ${ticket.quantity * ticket.price} PLN`;
            }
        }).join('\n');
        const totalPrice = updatedBasket.reduce((sum, t) => sum + t.sum_price, 0);
        const totalNumber = updatedBasket.reduce((sum, t) => sum + t.quantity, 0);
        saveCurrentBasket(updatedBasket);
        if (isPolish) {
            alert(`Przechodzimy do płatności z wybranymi biletami:\n${basketSummary}\nŁączna cena: ${totalPrice} zł\nIlość wybranych biletów: ${totalNumber}`);
        } else {
            alert(`We proceed to payment with selected tickets:\n${basketSummary}\nTotal price: ${totalPrice} PLN\nNumber of selected tickets: ${totalNumber}`);
        }
        window.location.href = './platnosci.html';
    });
}

  