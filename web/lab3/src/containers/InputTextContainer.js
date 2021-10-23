import { useState } from "react";
import { InputText } from "../components";
import { getFullInfo } from "../utils";

function InputTextContainer({setWeather, setPlaces}) {
    const [input, setInput] = useState("");

    const onSubmit = (event) => {
        event.preventDefault();

        getFullInfo(input, setWeather, setPlaces);
    }

    const handleChange = (event) => {
        setInput(event.target.value);
    }

    return (
        <InputText onSubmit={onSubmit} handleChange={handleChange}/>
    );
};

export { InputTextContainer };