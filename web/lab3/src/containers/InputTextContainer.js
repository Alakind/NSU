import { useState } from "react";
import { InputText } from "../components";
import { openTripApi, openWeatherApi } from "../utils";
import consts from "../consts";

async function InputTextContainer({setWeather, setPlaces}) {
    const [input, setInput] = useState("");

    const onSubmit = (event) => {
        event.preventDefault();

        let place = openWeatherApi.fetchOpenWeatherByName(input, consts.API_KEY_OPEN_WEATHER);

        // openTripApi.fetchOpenTripRadius(consts.API_KEY_OPEN_TRIP, place.coord.lon, place.coord.lat, consts.RADIUS)
        //     .then();
    }

    const handleChange = (event) => {
        setInput(event.target.value);
    }

    
    return (
        <InputText onSubmit={onSubmit} handleChange={handleChange}/>
    );
};

export { InputTextContainer };