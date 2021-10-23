
async function fetchOpenWeatherByName(cityName, apiKey) {
    let result = {};

    await fetch(`http://api.openweathermap.org/data/2.5/weather` +
    `?q=${cityName}` +
    `&appid=${apiKey}`
    )
    .then(response => (response.json()))
    .then(res => {
        result = res;
    })
    .catch(console.log);

    return result;
}

export const openWeatherApi = {
    fetchOpenWeatherByName,
};