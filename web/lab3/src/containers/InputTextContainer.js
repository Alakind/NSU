import { useState } from "react";
import { InputText } from "../components";

function InputTextContainer() {
    const [input, setInput] = useState("");

    const onSubmit = (event) => {
        console.log(input);
        event.preventDefault();
    }

    const handleChange = (event) => {
        setInput(event.target.value);
    }

    
    return (
        <InputText onSubmit={onSubmit} handleChange={handleChange}/>
    );
};

export { InputTextContainer };