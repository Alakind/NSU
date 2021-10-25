import { useState } from "react";
import { WeatherDescription } from "./components";
import { InputTextContainer } from "./containers/InputTextContainer";
import { PlaceCardContainer } from "./containers/PlaceCardContainer";

function App() {

  const [weather, setWeather] = useState(undefined);
  const [places, setPlaces] = useState(undefined);

  return (
    <>
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
        <PlaceCardContainer id={places.features[0].properties.xid} />
          :
        <div>Here will be places shown</div>
        }
      </div>
    </>
  );
}

export default App;
