import { useEffect, useState } from "react";

function WeatherDescription({ weather }) {

    const icon = `http://openweathermap.org/img/wn/${weather.weather[0].icon}@2x.png`;

    return(
        <>
            <h3>{weather.name}</h3>
            <div>{Math.round(weather.main.temp - 273)}</div>
            {(icon !== undefined)
                ?
            <img src={icon} />
                :
            <div>here should've been icon</div>}
        </>
    );
}

export { WeatherDescription };