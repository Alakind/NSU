import { useState } from "react";
import { InputText } from "../components";
import { openTripApi, openWeatherApi } from "../utils";
import consts from "../consts";

function InputTextContainer({setWeather, setPlaces}) {
    const [input, setInput] = useState("");

    const onSubmit = (event) => {
        event.preventDefault();

        console.log(input);

        openWeatherApi.fetchOpenWeatherByName(input, consts.API_KEY_OPEN_WEATHER)
            .then(response => response.json())
            .then(console.log)
            .catch(console.log);
    }

    const handleChange = (event) => {
        setInput(event.target.value);
    }

    
    return (
        <InputText onSubmit={onSubmit} handleChange={handleChange}/>
    );
};

export { InputTextContainer };