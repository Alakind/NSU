import React from "react";
import { useState } from "react";
import { WeatherDescription } from "./components";
import { InputTextContainer } from "./containers/InputTextContainer";
import { CardsListContainer } from "./containers/CardsListContainer";

function App() {

  const [weather, setWeather] = useState(undefined);
  const [places, setPlaces] = useState(undefined);

  return (
    <>
      {console.log("HEHE")}
      <h1>
        lab3
      </h1>
      <InputTextContainer setWeather={setWeather} setPlaces={setPlaces} />
      <div>
        {// WEATHER
        (weather !== undefined)
          ?
        <WeatherDescription weather={weather} />
          :
        <div>Make a request</div>
        }
        {// PLACES
        (places !== undefined)
          ?
        <CardsListContainer places={places.features} maxShown={10} />
          :
        <div>Here will be places shown</div>
        }
      </div>
    </>
  );
}

export default App;
