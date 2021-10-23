import { useState } from "react";
import { WeatherDescription } from "./components";
import { InputTextContainer } from "./containers/InputTextContainer";

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
        {(weather !== undefined)
          ?
        <WeatherDescription weather={weather} />
          :
        <div>Make a request</div>
        }
        {console.log(weather)}
        {console.log(places)}
      </div>
    </>
  );
}

export default App;
