
function fetchOpenWeatherByName(cityName, apiKey) {
    return fetch(`http://api.openweathermap.org/data/2.5/weather` +
    `?q=${cityName}` +
    `&appid=${apiKey}`
    );
}

export const openWeatherApi = {
    fetchOpenWeatherByName,
};