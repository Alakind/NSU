import consts from "../consts";
import { openTripApi, openWeatherApi } from ".";

const getFullInfo = async function(city, setWeather, setPlaces) {
    const promiseWeather = openWeatherApi.fetchOpenWeatherByName(city, consts.API_KEY_OPEN_WEATHER);
    
    const responseW = await promiseWeather;
    const weather = await responseW.json();

    const promisePlaces = openTripApi.fetchOpenTripRadius(weather.coord.lon, weather.coord.lat, consts.RADIUS);

    const responseP = await promisePlaces;
    const places = await responseP.json();

    setWeather(weather);
    setPlaces(places);
}

const fetchPlace = async function(id, setPlace) {
    const promise = openTripApi.fetchOpenTripPlace(id);

    const response = await promise;
    const place = await response.json();

    setPlace(place);
}

export {
    getFullInfo,
    fetchPlace,
};
