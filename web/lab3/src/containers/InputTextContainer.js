import { useState } from "react";
import { InputText } from "../components";
import { openTripApi, openWeatherApi } from "../utils";
import consts from "../consts";
import { getFullInfo } from "../utils";

function InputTextContainer({setWeather, setPlaces}) {
    const [input, setInput] = useState("");

    const onSubmit = (event) => {
        event.preventDefault();

        const { weather, places } = getFullInfo(input);
    }

    const handleChange = (event) => {
        setInput(event.target.value);
    }

    
    return (
        <InputText onSubmit={onSubmit} handleChange={handleChange}/>
    );
};

export { InputTextContainer };