import consts from "../consts";
import { openTripApi, openWeatherApi } from ".";

const getFullInfo = async function(city, setWeather, setPlaces) {
    const promiseWeather = openWeatherApi.fetchOpenWeatherByName(city, consts.API_KEY_OPEN_WEATHER);

    let weather;
    let places;

    try {
    const responseW = await promiseWeather;
    weather = await responseW.json();

    const promisePlaces = openTripApi.fetchOpenTripRadius(weather.coord.lon, weather.coord.lat, consts.RADIUS);

    const responseP = await promisePlaces;
    places = await responseP.json();
    } catch(error) {
        console.log(error);

        return;
    }

    setWeather(weather);
    setPlaces(places);
}

const fetchPlace = async function(id, setPlace) {
    const promise = openTripApi.fetchOpenTripPlace(id);
    
    let place;

    try {
        const response = await promise;
        place = await response.json();
    } catch(error) {
        console.log(error);

        return;
    }

    setPlace(place);
}

export {
    getFullInfo,
    fetchPlace,
};
