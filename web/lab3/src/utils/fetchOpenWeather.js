
function fetchOpenWeatherByName({ cityName, apiKey }) {
    return fetch(`api.openweathermap.org/data/2.5/weather
        ?q=${cityName}
        &appid=${apiKey}`
    );
}

export const fetchOpenWeather = {
    fetchOpenWeatherByName,
};