
function renderContentPolish() {
  const contentContainer = document.querySelector('.div_content_container');

  if (contentContainer) {
      contentContainer.innerHTML = `
        <!-- Filter Section -->
        <div class="filter-container">
          <div class="filter-container-left">
            <label for="line-filter">Numer linii:</label>
            <input type="text" id="line-filter" placeholder="Wpisz numer linii" />
          </div>
          <div class="filter-container-right">
            <div class="vehicle-type">
              <label>
                <input type="radio" name="vehicle-type" value="tram" checked />
                <span>Tramwaj</span>
              </label>
              <label>
                <input type="radio" name="vehicle-type" value="bus" />
                <span>Autobus</span>
              </label>
              <span class="selection"></span>
            </div>
            <button id="reset-filters">Resetuj filtry</button>
          </div>
        </div>
      
        <!-- Stops Display Section -->
        <div id="stops-container" class="stops-container"></div>
      
        <!-- Modal -->
        <div id="modal" class="modal hidden">
          <div class="modal-content">
            <button id="close-modal" class="close-modal">X</button>
            <div class="modal-body">
              <h2 id="line-number"></h2>
              <img id="vehicle-icon" src="" alt="Vehicle Icon" />
              <div>
                <button id="direction1" class="direction-btn"></button>
                <button id="direction2" class="direction-btn"></button>
              </div>
              <div id="route-container">
                <h3>Trasa:</h3>
                <p id="route"></p>
              </div>
              <div id="timetable-container">
                <h3>Rozkład jazdy:</h3>
                <div id="timetable"></div>
              </div>
              <div id="stations-container">
                <h3>Przystanki:</h3>
                <div id="stations-list"></div>
              </div>
            </div>
          </div>
        </div>    
      `;   
  }
}

function renderContentEnglish() {
  const contentContainer = document.querySelector('.div_content_container');

  if (contentContainer) {
    contentContainer.innerHTML = `
      <!-- Filter Section -->
      <div class="filter-container">
        <div class="filter-container-left">
          <label for="line-filter">Line number:</label>
          <input type="text" id="line-filter" placeholder="Enter line number" />
        </div>
        <div class="filter-container-right">
          <div class="vehicle-type">
            <label>
              <input type="radio" name="vehicle-type" value="tram" checked />
              <span>Tram</span>
            </label>
            <label>
              <input type="radio" name="vehicle-type" value="bus" />
              <span>Bus</span>
            </label>
            <span class="selection"></span>
          </div>
          <button id="reset-filters">Reset filters</button>
        </div>
      </div>
    
      <!-- Stops Display Section -->
      <div id="stops-container" class="stops-container"></div>
    
      <!-- Modal -->
      <div id="modal" class="modal hidden">
        <div class="modal-content">
          <button id="close-modal" class="close-modal">X</button>
          <div class="modal-body">
            <h2 id="line-number"></h2>
            <img id="vehicle-icon" src="" alt="Vehicle Icon" />
            <div>
              <button id="direction1" class="direction-btn"></button>
              <button id="direction2" class="direction-btn"></button>
            </div>
            <div id="route-container">
              <h3>Route:</h3>
              <p id="route"></p>
            </div>
            <div id="timetable-container">
              <h3>Schedule:</h3>
              <div id="timetable"></div>
            </div>
            <div id="stations-container">
              <h3>Stops:</h3>
              <div id="stations-list"></div>
            </div>
          </div>
        </div>
      </div>    
    `;   
  }
}

function renderStops(filter = "", vehicleType = "tram") {
  const stopsContainer = document.getElementById("stops-container");
  const noResultsMessage = document.createElement("p");
  noResultsMessage.classList.add("no-results");
  const isPolish = get_language();

  if (isPolish) {
    noResultsMessage.innerText = "Brak lini o wskazanych kryteriach!";
  } else {
    noResultsMessage.innerText = "There are no lines with the specified criteria!";
  }

  stopsContainer.innerHTML = "";
  const filteredLines = publicTransportLines.filter(
    (line) =>
      (!filter || line.number_of_line.toString().includes(filter)) &&
      line.vehicle_type === vehicleType
  );

  if (filteredLines.length === 0) {
    noResultsMessage.style.display = "block";
  } else {
    noResultsMessage.style.display = "none";
  }

  filteredLines.forEach((line) => {
    const button = document.createElement("button");

    if (isPolish) {
      button.textContent = `Linia ${line.number_of_line}`;
    } else {
      button.textContent = `Line ${line.number_of_line}`;
    }

    button.addEventListener("click", () => showModal(line));
    stopsContainer.appendChild(button);
  });
  stopsContainer.appendChild(noResultsMessage);
}

function showModal(line) {
    const isPolish = get_language();
    const lineNumberElement = modal.querySelector("#line-number");

    if (isPolish) {
      lineNumberElement.textContent = `Linia ${line.number_of_line}`;
    } else {
      lineNumberElement.textContent = `Line ${line.number_of_line}`;
    }
  
    const vehicleIconElement = modal.querySelector("#vehicle-icon");
    vehicleIconElement.src = `../IMAGES/${line.vehicle_type}_image.png`;
  
    const direction1Button = modal.querySelector("#direction1");
    const direction2Button = modal.querySelector("#direction2");
  
    const directions = line.directions;
    direction1Button.textContent = directions[0].destination;

    if (isPolish) {
      direction2Button.textContent = directions[1] ? directions[1].destination : 'Brak';
    } else {
      direction2Button.textContent = directions[1] ? directions[1].destination : 'Lack';
    }

    let selectedDirection = directions[0];

    const changeDirection = (direction) => {
        selectedDirection = direction;
        updateModalForDirection(selectedDirection);
    };

    direction1Button.addEventListener("click", () => changeDirection(directions[0]));
    direction2Button.addEventListener("click", () => directions[1] && changeDirection(directions[1]));

    const updateModalForDirection = (direction) => {
        const routeContainer = modal.querySelector("#route");
        routeContainer.textContent = direction.route;
        const stationsList = modal.querySelector("#stations-list");
        stationsList.innerHTML = '';
        direction.lines.forEach((station) => {
            const stationElement = document.createElement("button");
            stationElement.textContent = station.name_of_station;
            stationElement.addEventListener("click", () => displayTimetableForStation(station, direction.lines));
            stationsList.appendChild(stationElement);
        });
        displayTimetableForStation(direction.lines[0], direction.lines);
    };

    const displayTimetableForStation = (station, lines) => {
        const timetableContainer = modal.querySelector("#timetable");
        timetableContainer.innerHTML = '';

        const stationHeader = document.createElement("h3");

        if (isPolish) {
          stationHeader.textContent = `Rozkład dla przystanku: ${station.name_of_station}`;
        } else {
          stationHeader.textContent = `Timetable for the stop: ${station.name_of_station}`;
        }

        timetableContainer.appendChild(stationHeader);

        const timetableTable = document.createElement("table");
        timetableTable.classList.add("timetable-table");

        if (isPolish) {
          timetableTable.innerHTML = `
            <thead>
                <tr>
                    <th>Dzień</th>
                    <th>Godzina</th>
                    <th>Minuta</th>
                </tr>
            </thead>
            <tbody>
                <tr class="${station === lines[0] ? 'selected' : ''}">
                    <td>Dni powszednie</td>
                    <td>${formatTimeForSchedule(station.time_table, 'normal_days').hour}</td>
                    <td>${formatTimeForSchedule(station.time_table, 'normal_days').minutes}</td>
                </tr>
                <tr class="${station === lines[1] ? 'selected' : ''}">
                    <td>Sobota</td>
                    <td>${formatTimeForSchedule(station.time_table, 'saturdays').hour}</td>
                    <td>${formatTimeForSchedule(station.time_table, 'saturdays').minutes}</td>
                </tr>
                <tr class="${station === lines[2] ? 'selected' : ''}">
                    <td>Święta</td>
                    <td>${formatTimeForSchedule(station.time_table, 'sundays').hour}</td>
                    <td>${formatTimeForSchedule(station.time_table, 'sundays').minutes}</td>
                </tr>
            </tbody>
          `;
        } else {
          timetableTable.innerHTML = `
            <thead>
                <tr>
                    <th>Day</th>
                    <th>Hour</th>
                    <th>Minute</th>
                </tr>
            </thead>
            <tbody>
                <tr class="${station === lines[0] ? 'selected' : ''}">
                    <td>Normal Days</td>
                    <td>${formatTimeForSchedule(station.time_table, 'normal_days').hour}</td>
                    <td>${formatTimeForSchedule(station.time_table, 'normal_days').minutes}</td>
                </tr>
                <tr class="${station === lines[1] ? 'selected' : ''}">
                    <td>Saturdays</td>
                    <td>${formatTimeForSchedule(station.time_table, 'saturdays').hour}</td>
                    <td>${formatTimeForSchedule(station.time_table, 'saturdays').minutes}</td>
                </tr>
                <tr class="${station === lines[2] ? 'selected' : ''}">
                    <td>Holidays</td>
                    <td>${formatTimeForSchedule(station.time_table, 'sundays').hour}</td>
                    <td>${formatTimeForSchedule(station.time_table, 'sundays').minutes}</td>
                </tr>
            </tbody>
          `;
        }
        // Zamiana dwukropka na trzy spacje oraz przecinka na <br>
        timetableContainer.appendChild(timetableTable);
        const tableCells = document.querySelectorAll('td');
        tableCells.forEach(cell => {
          let text = cell.textContent;
          text = text.split(',').map(item => item.trim()).join('<br>');
          text = text.replace(/:/g, '&nbsp;&nbsp;&nbsp;');
          cell.innerHTML = text;
        });
            
    };

    const formatTimeForSchedule = (timeTable, dayType) => {
        const daySchedule = timeTable.find(schedule => schedule[dayType]);
        if (daySchedule) {
            return {
                hour: daySchedule[dayType].map(t => t.hour).join(', '),
                minutes: daySchedule[dayType]
                .map(t => t.minutes.sort((a, b) => a - b).join(':'))
                .join(', ')
            };
        }

        if (isPolish) {
          return { hour: 'Brak', minutes: 'Brak' };
        } else {
          return { hour: 'Lack', minutes: 'Lack' };
        }
    };

    updateModalForDirection(selectedDirection);  
    modal.classList.remove("hidden");
}

function resetFilters() {
  const lineFilter = document.getElementById("line-filter");
  lineFilter.value = "";
  document.querySelector("input[name='vehicle-type'][value='tram']").checked = true;
  renderStops();
}

document.addEventListener('DOMContentLoaded', () => {

  updateContent();

  const stopsContainer = document.getElementById("stops-container");
  const lineFilter = document.getElementById("line-filter");
  const vehicleTypeInputs = document.querySelectorAll("input[name='vehicle-type']");
  const modal = document.getElementById("modal");
  const closeModal = document.getElementById("close-modal");
  const noResultsMessage = document.createElement("p");
  const resetButton = document.getElementById("reset-filters");

  const isPolish = get_language();
  
  if (isPolish) {
    noResultsMessage.textContent = "Brak linii o wskazanych kryteriach.";
  } else {
    noResultsMessage.textContent = "No lines with the specified criteria.";
  }

  
  noResultsMessage.style.color = "red";
  noResultsMessage.style.display = "none";
  stopsContainer.parentNode.appendChild(noResultsMessage);

  closeModal.addEventListener("click", () => {
    modal.classList.add("hidden");
  });
  

  lineFilter.addEventListener("input", () => {
    const filterValue = lineFilter.value;
    const selectedType = [...vehicleTypeInputs].find((input) => input.checked).value;
    renderStops(filterValue, selectedType);
  });
  
  vehicleTypeInputs.forEach((input) => {
    input.addEventListener("change", () => {
      const filterValue = lineFilter.value;
      renderStops(filterValue, input.value);
    });
  });

  resetFilters();

  // Event listener dla przycisku resetowania
  resetButton.addEventListener("click", resetFilters);
});